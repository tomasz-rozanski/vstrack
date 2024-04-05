#ifndef _VST_CONSOLE_H
#define _VST_CONSOLE_H

COORD coordScreen, coord;
CONSOLE_SCREEN_BUFFER_INFO csbi;
HANDLE hStdout, hStdin, hStderr, hBackBuffer;
i16 conSizeX, conSizeY;
i16 conSizeXtemp, conSizeYtemp;
i16 conMinSizeX, conMinSizeY;
i16 conMaxSizeX, conMaxSizeY;
CONSOLE_CURSOR_INFO cciOldCursor, cciNewCursor;
wchar_t szBuffer[4096];
u32 BytesWritten;

// Double-buffering structs
SMALL_RECT srctReadRect;
SMALL_RECT srctWriteRect;
CHAR_INFO *chiBuffer = NULL;
COORD coordBufSize;
COORD coordBufCoord;

COORD coordLargestWindowSize;

BOOL fSuccess;

void *
AllocateBackBuffer() {
    if (chiBuffer != NULL) {
        free(chiBuffer);
    }
    void *chiBuffer =
        (void *) malloc(sizeof(CHAR_INFO) * conMaxSizeX * conMaxSizeY * 2);

    return chiBuffer;
}

void
SetConsoleHandles() {
    hStdin = GetStdHandle(STD_INPUT_HANDLE);
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    hStderr = GetStdHandle(STD_ERROR_HANDLE);
    hBackBuffer = CreateConsoleScreenBuffer( //
            GENERIC_READ | GENERIC_WRITE, // read/write access
            FILE_SHARE_READ | FILE_SHARE_WRITE, // shared
            NULL, // default security attributes
            CONSOLE_TEXTMODE_BUFFER, // must be TEXTMODE
            NULL); // reserved; must be NULL
}

void
ScrollBuffer(HANDLE hConsole) {
    SMALL_RECT ScrollRectangle, ClipRectangle;
    COORD DestinationOrigin = { 0, 15 };
    CHAR_INFO Fill = { ' ' };

    ScrollRectangle.Top = 0;
    ScrollRectangle.Left = 0;
    ScrollRectangle.Bottom = conMaxSizeY * 2 - 1;
    ScrollRectangle.Right = conMaxSizeX - 1;

    ClipRectangle.Top = 0;
    ClipRectangle.Left = 0;
    ClipRectangle.Bottom = conMaxSizeY * 2 - 1;
    ClipRectangle.Right = conMaxSizeX - 1;

    ScrollConsoleScreenBuffer(
            hConsole, &ScrollRectangle, &ClipRectangle, DestinationOrigin, &Fill);
}

void
SetCursorPosition(HANDLE hConsole, u32 PositionX, u32 PositionY) {
    COORD coordPosition;

    coordPosition.X = (i16) PositionX;
    coordPosition.Y = (i16) PositionY;

    SetConsoleCursorPosition(hConsole, coordPosition);
}

void
ResizeConsoleWindow(HANDLE hConsole, i16 Width, i16 Height) {
    BOOL AbsolutePosition = FALSE;
    SMALL_RECT NewSize;

    i16 ShiftX = 0;
    i16 ShiftY = 0;

    NewSize.Top = 0 + ShiftY;
    NewSize.Left = 0 + ShiftX;
    NewSize.Bottom = Height - 1 + ShiftY;
    NewSize.Right = Width - 1 + ShiftX;

    SetConsoleWindowInfo(hConsole, AbsolutePosition, &NewSize);
}

void
GetConsoleWindowSize(HANDLE hConsole, i16 *conSizeX, i16 *conSizeY,
        i16 *conMaxSizeX, i16 *conMaxSizeY) {
    GetConsoleScreenBufferInfo(hConsole, &csbi);

    *conSizeX = csbi.srWindow.Right - csbi.srWindow.Left;
    *conSizeY = csbi.srWindow.Bottom - csbi.srWindow.Top;

    coordLargestWindowSize = GetLargestConsoleWindowSize(hConsole);

    *conMaxSizeX = coordLargestWindowSize.X;
    *conMaxSizeY = coordLargestWindowSize.Y;
}

void
HideConsoleCursor(HANDLE hConsole, CONSOLE_CURSOR_INFO *cciOldCursor,
        CONSOLE_CURSOR_INFO *cciNewCursor) {
    // Store the original cursor setting
    GetConsoleCursorInfo(hConsole, cciOldCursor);

    // Set cursor to hidden
    cciNewCursor->bVisible = FALSE;

    SetConsoleCursorInfo(hConsole, cciNewCursor);
}

void
WriteToBackBuffer(void) {
    WriteConsole(hBackBuffer, szBuffer, wcslen(szBuffer), &BytesWritten, NULL);
}

void
CopyFromBackBuffer() {
    // Set the source rectangle.
    srctReadRect.Top = 0;
    srctReadRect.Left = 0;
    srctReadRect.Bottom = conMaxSizeY * 2 - 1;
    srctReadRect.Right = conMaxSizeX - 1;

    // The temporary buffer size
    coordBufSize.X = conMaxSizeX;
    coordBufSize.Y = conMaxSizeY * 2;

    // The top left destination cell of the temporary buffer
    // is row 0, col 0.
    coordBufCoord.X = 0;
    coordBufCoord.Y = 0;

    // Copy the block from the screen buffer to the temporary buffer.
    fSuccess = ReadConsoleOutput(hBackBuffer, // screen buffer to read from
            chiBuffer, // buffer to copy into
            coordBufSize, // col-row size of chiBuffer
            coordBufCoord, // top left destination cell in chiBuffer
            &srctReadRect); // screen buffer source rectangle

    if (!fSuccess) {
        fwprintf(stderr, L"ReadConsoleOutput failed - (%d)\n", GetLastError());
        return;
    }

    // Set the destination rectangle.
    srctWriteRect.Top = 0;
    srctWriteRect.Left = 0;
    srctWriteRect.Bottom = conMaxSizeY * 2 - 1;
    srctWriteRect.Right = conMaxSizeX - 1;

    // Copy the temporary buffer to the new screen buffer.
    fSuccess = WriteConsoleOutput(hStdout, // screen buffer to write to
            chiBuffer, // buffer to copy from
            coordBufSize, // col-row size of chiBuffer
            coordBufCoord, // top left source coll in chiBuffer
            &srctWriteRect); // destination screen buffer rectangle

    if (!fSuccess) {
        fwprintf(stderr, L"WriteConsoleOutput failed - (%d)\n", GetLastError());
        return;
    }
}

void
cls(HANDLE hConsole) {
    COORD coordScreen = { 0, 0 }; // home for the cursor
    u32 cCharsWritten;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    u32 dwConSize;

    // Get the number of character cells in the current buffer.
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        return;
    }

    dwConSize = csbi.dwMaximumWindowSize.X * csbi.dwMaximumWindowSize.Y;
    // dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

    // Fill the entire screen with blanks
    if (!FillConsoleOutputCharacter( //
                hConsole, // Handle to the console screen buffer
                (TCHAR) ' ', // character to write to the buffer
                dwConSize, // number of cells to write
                coordScreen, // coordinates of the first cell
                &cCharsWritten)) { // receive the number of characters written
        return;
    }

    // Get the current text attribute.
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        return;
    }

    // Set the buffer's attributes accordingly.
    if (!FillConsoleOutputAttribute( //
                hConsole, // Handle to console screen buffer
                csbi.wAttributes, // Character attributes to use
                dwConSize, // Number of cells to set attribute
                coordScreen, // Coordinates of first cell
                &cCharsWritten)) { // Receive number of characters written
        return;
    }

    // Put the cursor at its home coordinates.
    SetConsoleCursorPosition(hConsole, coordScreen);
}

void
ChangeMode(HANDLE hConsole) {

    u32 conMode = 0x0;
    SetConsoleMode(hConsole, conMode);
}

void
ClearLine() {
    swprintf_s(szBuffer, _countof(szBuffer), L"%*s\r", conSizeX - 1, L"");
    WriteToBackBuffer();
}

void
WriteDebugMessage(HANDLE hConsole) {
    static struct {
        u32 ConModeFlag;
        char *ConModeName;
    } ConModes[] = { { ENABLE_ECHO_INPUT, "ENABLE_ECHO_INPUT" },
        { ENABLE_INSERT_MODE, "ENABLE_INSERT_MODE" },
        { ENABLE_LINE_INPUT, "ENABLE_LINE_INPUT" },
        { ENABLE_MOUSE_INPUT, "ENABLE_MOUSE_INPUT" },
        { ENABLE_PROCESSED_INPUT, "ENABLE_PROCESSED_INPUT" },
        { ENABLE_QUICK_EDIT_MODE, "ENABLE_QUICK_EDIT_MODE" },
        { ENABLE_WINDOW_INPUT, "ENABLE_WINDOW_INPUT" },
        { ENABLE_VIRTUAL_TERMINAL_INPUT, "ENABLE_VIRTUAL_TERMINAL_INPUT" },
        { ENABLE_PROCESSED_OUTPUT, "ENABLE_PROCESSED_OUTPUT" },
        { ENABLE_WRAP_AT_EOL_OUTPUT, "ENABLE_WRAP_AT_EOL_OUTPUT" },
        { ENABLE_VIRTUAL_TERMINAL_PROCESSING,
            "ENABLE_VIRTUAL_TERMINAL_PROCESSING" },
        { DISABLE_NEWLINE_AUTO_RETURN, "DISABLE_NEWLINE_AUTO_RETURN" },
        { ENABLE_LVB_GRID_WORLDWIDE, "ENABLE_LVB_GRID_WORLDWIDE" } };

    u32 conMode;
    //char *szBuffer[1024]; not used???

    GetConsoleMode(hConsole, &conMode);

    FILE *fpConModeInfo = fopen("debug/conmode.txt", "w");

    fprintf(fpConModeInfo, "conMode: 0x%08lu\n", conMode);
    for (int i = 0; i < _countof(ConModes); ++i) {
        if (ConModes[i].ConModeFlag & conMode) {
            fprintf(fpConModeInfo, "%s\n", ConModes[i].ConModeName);
        }
    }

#ifdef DEBUG
    fwprintf(fpConModeInfo, L"Debug mode ON\n");
#endif

    fclose(fpConModeInfo);
}

void
WriteDebugLog(TCHAR *message) {
    WriteTimeStampDebugString();

    FILE *fpDebugInfo = fopen("debug/debug.log", "a");

    fwprintf(fpDebugInfo, szTimeStampDebug);
    fwprintf(fpDebugInfo, message);

    fclose(fpDebugInfo);
}

#endif
