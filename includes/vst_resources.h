#ifndef _VS_RESOURCES
#define _VS_RESOURCES

BOOL CALLBACK EnumResNameProc(
    HMODULE hModule, LPCTSTR lpszType, LPTSTR lpszName, LONG_PTR lParam);

void
ListModuleResources(HANDLE hModule, ENUMRESNAMEPROC EnumResNameProc)
{
  _tprintf(_T("Inside ListModuleResources()"));
  EnumResourceNames(hModule, NULL, EnumResNameProc, NULL);
}

BOOL CALLBACK
EnumResNameProc(
    HMODULE hModule, LPCTSTR lpszType, LPTSTR lpszName, LONG_PTR lParam)
{
  _tprintf(_T("Resource name: %s, type: %s"), lpszName, lpszType);

  return TRUE;
}

#endif
