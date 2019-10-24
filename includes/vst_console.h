#ifndef _VST_CONSOLE_H
#define _VST_CONSOLE_H

COORD coordScreen, coord;
CONSOLE_SCREEN_BUFFER_INFO csbi;
HANDLE hStdout, hStdin, hStderr, hBackBuffer;
SHORT conSizeX, conSizeY;
CONSOLE_CURSOR_INFO cciOldCursor, cciNewCursor;
TCHAR szBuffer[1024];
DWORD dwBytesWritten;

// Double-buffering structs
SMALL_RECT srctReadRect;
SMALL_RECT srctWriteRect;
CHAR_INFO chiBuffer[4800]; // 120 x 40
COORD coordBufSize;
COORD coordBufCoord;
BOOL fSuccess;

void
SetConsoleHandles()
{
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
SetCursorPosition(HANDLE hConsole, DWORD PositionX, DWORD PositionY)
{
  COORD coordPosition;

  coordPosition.X = (SHORT) PositionX;
  coordPosition.Y = (SHORT) PositionY;

  SetConsoleCursorPosition(hConsole, coordPosition);
}

void
GetConsoleWindowSize(HANDLE hConsole, SHORT *conSizeX, SHORT *conSizeY)
{
  GetConsoleScreenBufferInfo(hConsole, &csbi);

  *conSizeX = csbi.srWindow.Right - csbi.srWindow.Left;
  *conSizeY = csbi.srWindow.Bottom - csbi.srWindow.Top;
}

void
HideConsoleCursor(HANDLE hConsole, CONSOLE_CURSOR_INFO *cciOldCursor,
    CONSOLE_CURSOR_INFO *cciNewCursor)
{
  // Store the original cursor setting
  GetConsoleCursorInfo(hConsole, cciOldCursor);

  // Set cursor to hidden
  cciNewCursor->bVisible = FALSE;

  SetConsoleCursorInfo(hConsole, cciNewCursor);
}

void
WriteToBackBuffer(void)
{
  WriteConsole(hBackBuffer, szBuffer, lstrlen(szBuffer), &dwBytesWritten, NULL);
}

void
CopyFromBackBuffer()
{
  // Set the source rectangle.
  srctReadRect.Top = 0;
  srctReadRect.Left = 0;
  srctReadRect.Bottom = conSizeY - 1;
  srctReadRect.Right = conSizeX - 1;

  // The temporary buffer size
  coordBufSize.Y = conSizeY;
  coordBufSize.X = conSizeX;

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

  if (!fSuccess)
  {
    printf("ReadConsoleOutput failed - (%d)\n", GetLastError());
    return;
  }

  // Set the destination rectangle.
  srctWriteRect.Top = 0;
  srctWriteRect.Left = 1;
  srctWriteRect.Bottom = conSizeY - 1;
  srctWriteRect.Right = conSizeX;

  // Copy the temporary buffer to the new screen buffer.
  fSuccess = WriteConsoleOutput(hStdout, // screen buffer to write to
      chiBuffer, // buffer to copy from
      coordBufSize, // col-row size of chiBuffer
      coordBufCoord, // top left source coll in chiBuffer
      &srctWriteRect); // destination screen buffer rectangle

  if (!fSuccess)
  {
    printf("WriteConsoleOutput failed - (%d)\n", GetLastError());
    return;
  }
}

void
cls(HANDLE hConsole)
{
  COORD coordScreen = { 0, 0 }; // home for the cursor
  DWORD cCharsWritten;
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  DWORD dwConSize;

  // Get the number of character cells in the current buffer.
  if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
  {
    return;
  }

  dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

  // Fill the entire screen with blanks
  if (!FillConsoleOutputCharacter( //
          hConsole, // Handle to the console screen buffer
          (TCHAR) ' ', // character to write to the buffer
          dwConSize, // number of cells to write
          coordScreen, // coordinates of the first cell
          &cCharsWritten)) // receive the number of characters written
  {
    return;
  }

  // Get the current text attribute.
  if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
  {
    return;
  }

  // Set the buffer's attributes accordingly.
  if (!FillConsoleOutputAttribute( //
          hConsole, // Handle to console screen buffer
          csbi.wAttributes, // Character attributes to use
          dwConSize, // Number of cells to set attribute
          coordScreen, // Coordinates of first cell
          &cCharsWritten)) // Receive number of characters written
  {
    return;
  }

  // Put the cursor at its home coordinates.
  SetConsoleCursorPosition(hConsole, coordScreen);
}

void
ClearLine()
{
  sprintf(szBuffer, "%*s\r", conSizeX - 1, "");
  WriteToBackBuffer();
}

void
WriteDebugMessage(HANDLE hConsole)
{
  SetCursorPosition(hConsole, 0, conSizeY - 1);
  sprintf(szBuffer, "Debug mode is %s. Press \"D\" to toggle.\n",
      DEBUG ? "ON" : "OFF");
  WriteToBackBuffer();
}

#endif
