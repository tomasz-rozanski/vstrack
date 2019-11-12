#ifndef _VST_UTILS_H
#define _VST_UTILS_H

SYSTEMTIME stLocalTime;
char szTimeStampDebug[64];
char szTimeStampFile[64];

void
WriteTimeStampDebugString()
{
  GetLocalTime(&stLocalTime);

  sprintf_s(szTimeStampDebug, _countof(szTimeStampDebug), //
      "%04d-%02d-%02d %02d:%02d:%02d: ", //
      stLocalTime.wYear, //
      stLocalTime.wMonth, //
      stLocalTime.wDay, //
      stLocalTime.wHour, //
      stLocalTime.wMinute, //
      stLocalTime.wSecond);
}

void
WriteTimeStampFileString()
{
  GetLocalTime(&stLocalTime);

  sprintf_s(szTimeStampFile, _countof(szTimeStampFile), //
      "%04d%02d%02dT%02d%02d%02d", //
      stLocalTime.wYear, //
      stLocalTime.wMonth, //
      stLocalTime.wDay, //
      stLocalTime.wHour, //
      stLocalTime.wMinute, //
      stLocalTime.wSecond);
}

u16
ErrorExit(char *Message)
{
  u32 ErrorCode = GetLastError();

  fprintf(stderr, "\n\n%s failed with the error code %d", Message, ErrorCode);

  exit(ErrorCode);
}

#endif