#ifndef _VST_UTILS_H
#define _VST_UTILS_H

SYSTEMTIME stLocalTime;
wchar_t szTimeStampDebug[64];
wchar_t szTimeStampFile[64];

BOOL
DataChanged(void *Struct1, void *Struct2, usize StructSize) {
    u8 *pStruct1 = Struct1;
    u8 *pStruct2 = Struct2;

    for (int i = 0; i < StructSize; ++i) {
        if (*pStruct1++ != *pStruct2++) {
            return TRUE;
        }
    }
    return FALSE;
}

void
WriteTimeStampDebugString() {
    GetLocalTime(&stLocalTime);

    swprintf_s(szTimeStampDebug, _countof(szTimeStampDebug), //
            L"%04d-%02d-%02d %02d:%02d:%02d: ", //
            stLocalTime.wYear, //
            stLocalTime.wMonth, //
            stLocalTime.wDay, //
            stLocalTime.wHour, //
            stLocalTime.wMinute, //
            stLocalTime.wSecond);
}

void
WriteTimeStampFileString() {
    GetLocalTime(&stLocalTime);

    swprintf_s(szTimeStampFile, _countof(szTimeStampFile), //
            L"%04d%02d%02dT%02d%02d%02d", //
            stLocalTime.wYear, //
            stLocalTime.wMonth, //
            stLocalTime.wDay, //
            stLocalTime.wHour, //
            stLocalTime.wMinute, //
            stLocalTime.wSecond);
}

u16
ErrorExit(wchar_t *Message) {
    u32 ErrorCode = GetLastError();

    fwprintf(stderr, L"\n\n%ls failed with the error code %d", Message, ErrorCode);

    exit(ErrorCode);
}

#endif

