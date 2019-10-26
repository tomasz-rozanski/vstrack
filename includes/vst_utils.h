#ifndef _VST_UTILS_H
#define _VST_UTILS_H

SYSTEMTIME stLocalTime;
TCHAR szTimeStampDebug[64];
TCHAR szTimeStampFile[64];

void
WriteTimeStampDebugString()
{
  GetLocalTime(&stLocalTime);

  sprintf(szTimeStampDebug, //
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

  sprintf(szTimeStampFile, //
      "%04d%02d%02dT%02d%02d%02d", //
      stLocalTime.wYear, //
      stLocalTime.wMonth, //
      stLocalTime.wDay, //
      stLocalTime.wHour, //
      stLocalTime.wMinute, //
      stLocalTime.wSecond);
}

#endif