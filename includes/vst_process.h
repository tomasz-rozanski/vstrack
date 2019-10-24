#ifndef _VST_PROCESS_H
#define _VST_PROCESS_H

#define LDR_IS_DATAFILE(handle) (((ULONG_PTR)(handle)) & (ULONG_PTR) 1)
#define LDR_IS_IMAGEMAPPING(handle) (((ULONG_PTR)(handle)) & (ULONG_PTR) 2)
#define LDR_IS_RESOURCE(handle)                                                \
  (LDR_IS_IMAGEMAPPING(handle) || LDR_IS_DATAFILE(handle))

SIZE_T moduleDllBase;
SIZE_T PSX_TO_EMU;

DWORD dwPriorityClassValue[6] = { ABOVE_NORMAL_PRIORITY_CLASS,
  BELOW_NORMAL_PRIORITY_CLASS, HIGH_PRIORITY_CLASS, IDLE_PRIORITY_CLASS,
  NORMAL_PRIORITY_CLASS, REALTIME_PRIORITY_CLASS };

TCHAR *szPriorityClassName[6] = { TEXT("ABOVE_NORMAL_PRIORITY_CLASS"),
  TEXT("BELOW_NORMAL_PRIORITY_CLASS"), TEXT("HIGH_PRIORITY_CLASS"),
  TEXT("IDLE_PRIORITY_CLASS"), TEXT("NORMAL_PRIORITY_CLASS"),
  TEXT("REALTIME_PRIORITY_CLASS") };

TCHAR szModuleName[MAX_PATH] = TEXT("");
TCHAR szExeName[MAX_PATH] = TEXT("");

SIZE_T
GetModuleDllBase(DWORD processID, TCHAR *szModuleName)
{
  DWORD dwDesiredAccess = PROCESS_QUERY_INFORMATION | PROCESS_VM_READ;
  HANDLE hProcess;
  HMODULE hModule;
  MODULEINFO modinfo = { 0 };
  DWORD cbNeeded;

  SIZE_T lpBaseOfDll;

  hProcess = OpenProcess(dwDesiredAccess, FALSE, processID);

  if (NULL != hProcess)
  {
    if (EnumProcessModules(hProcess, &hModule, sizeof(hModule), &cbNeeded))
    {
      if (GetModuleInformation(hProcess, hModule, &modinfo, sizeof(modinfo)))
      {
        lpBaseOfDll = (SIZE_T) modinfo.lpBaseOfDll;
      }
      else
      {
        printf("ERROR: Couldn't read module info structure.\n");
      }
    }
    CloseHandle(hProcess);
  }
  else
  {
    printf("ERROR: Couldn't open the process.\n");
  }
  return lpBaseOfDll;
}

DWORD
FindProcessIdByName(
    DWORD *dwProcessesList, DWORD dwProcessesNumber, TCHAR *szModuleName)
{
  TCHAR szProcessName[MAX_PATH] = TEXT("");
  TCHAR lpFilename[MAX_PATH] = TEXT("");
  HMODULE hMods[1024];
  HANDLE hProcess;
  TCHAR szBuffer[64];
  DWORD cModules;
  DWORD processID = -1;
  DWORD dwDesiredAcces = PROCESS_QUERY_INFORMATION | PROCESS_VM_READ;

  for (int i = 0; i < dwProcessesNumber; i++)
  {

    processID = *dwProcessesList++;

    hProcess = OpenProcess(dwDesiredAcces, FALSE, processID);

    // Get the process name.
    if (NULL != hProcess)
    {
      HMODULE hMod;
      DWORD cbNeeded;

      if (EnumProcessModules(hProcess, hMods, sizeof(hMods), &cbNeeded))
      {
        for (int i = 0; i < (cbNeeded / sizeof(HMODULE)); ++i)
        {
          /* code */
          GetModuleBaseName(hProcess, hMods[i], szProcessName,
              sizeof(szProcessName) / sizeof(TCHAR));
          // GetModuleFileNameEx(hProcess, hMods[i], lpFilename, MAX_PATH);

          // _tprintf(TEXT("%d %s\n"), processID, szProcessName);
          // _tprintf(TEXT("%d %s\n"), processID, lpFilename);

          if (strcmp(szProcessName, szModuleName) == 0)
          {
            break;
          }
        }
      }
    }
  }

  if (hProcess)
  {
    CloseHandle(hProcess);
  }

  return processID;
}

void
PrintProcessNameAndID(DWORD processID)
{
  TCHAR szProcessName[MAX_PATH] = TEXT("<unknown>");

  // Get a handle to the process.
  HANDLE hProcess = OpenProcess(
      PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processID);

  // Get the process name.
  if (NULL != hProcess)
  {
    HMODULE hMod;
    DWORD cbNeeded;

    if (EnumProcessModules(hProcess, &hMod, sizeof(hMod), &cbNeeded))
    {
      GetModuleBaseName(
          hProcess, hMod, szProcessName, sizeof(szProcessName) / sizeof(TCHAR));
    }
  }

  // Print the process name and ID.
  _tprintf(TEXT("%s (PID: %u)\n"), szProcessName, processID);

  // Release the handle to the process.
  CloseHandle(hProcess);
}

DWORD
ReadMemoryValue(DWORD processID, SIZE_T offset, SIZE_T BytesToRead)
{
  DWORD Value = -1;
  // Get a handle to the process.
  HANDLE hProcess = OpenProcess(
      PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processID);

  // Get the process name.
  if (NULL != hProcess)
  {
    SIZE_T NumberOfBytesActuallyRead = -1;

    if (ReadProcessMemory(hProcess, (LPCVOID) offset, &Value, BytesToRead,
            &NumberOfBytesActuallyRead))
    {
      if (BytesToRead > NumberOfBytesActuallyRead)
      {
        _tprintf(TEXT("ERROR: Not all bytes read from memory.\n"));
      }
      CloseHandle(hProcess);
    }
    else
    {
      _tprintf(TEXT(
          "ERROR (ReadMemoryValue): Couldn't read from the process memory\n"));
    }
  }

  // CloseHandle(hProcess);
  return Value;
}

DWORD
_GetProcessMemory(
    DWORD processID, SIZE_T Offset, SIZE_T BytesToRead, void *Value)
{
  SIZE_T BytesActuallyRead = -1;
  SIZE_T FinalOffset = Offset - PSX_TO_EMU;

  // fprintf(stdout, "FinalOffset: 0x%02x - 0x%02x = 0x%02x\n", Offset,
  // PSX_TO_EMU,
  //     FinalOffset);
  // Get a handle to the process.
  HANDLE hProcess = OpenProcess(
      PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processID);

  // fprintf(stdout, "hProcess: %i\n", hProcess);

  // Get the process name.
  if (NULL != hProcess)
  {
    if (ReadProcessMemory(hProcess, (LPCVOID) FinalOffset, Value, BytesToRead,
            &BytesActuallyRead))
    {
      if (BytesToRead > BytesActuallyRead)
      {
        _tprintf(TEXT(
            "ERROR (GetProcessMemory): Not all bytes read from memory.\n"));
      }
      CloseHandle(hProcess);
    }
    else
    {
      _tprintf(TEXT(
          "ERROR (GetProcessMemory): Couldn't read from the process memory\n"));
      exit(1);
    }
  }
  // CloseHandle(hProcess);
  return BytesActuallyRead;
}

void
PrintMemoryValue(
    DWORD processID, SIZE_T offset, SIZE_T BytesToRead, TCHAR *szDescription)
{
  TCHAR szBuffer[1024] = TEXT("");

  // Make sure to change Value size depending from the BytesToRead
  short Value = -1;

  if (_GetProcessMemory(processID, offset, BytesToRead, &Value))
  {
    _tprintf(TEXT("Value of %s: %d\n"), szDescription, Value);
  }
  else
  {
    _tprintf("ERROR (PrintMemoryValue): Couldn't read the Value\n");
  }
}

void
PrintProcessInfo(DWORD processID)
{
  DWORD dwDesiredAccess = PROCESS_QUERY_INFORMATION | PROCESS_VM_READ;
  HANDLE hProcess;
  HMODULE hModule;
  MODULEINFO modinfo;
  DWORD cbNeeded;

  hProcess = OpenProcess(dwDesiredAccess, FALSE, processID);

  if (NULL != hProcess)
  {
    if (EnumProcessModules(hProcess, &hModule, sizeof(hModule), &cbNeeded))
    {
      if (GetModuleInformation(hProcess, hModule, &modinfo, sizeof(modinfo)))
      {
        LPVOID lpBaseOfDll = modinfo.lpBaseOfDll;
        DWORD SizeOfImage = modinfo.SizeOfImage;
        LPVOID EntryPoint = modinfo.EntryPoint;

        printf("Base of DLL: %p\n", lpBaseOfDll);
        printf("Size of Image: %d\n", SizeOfImage);
        printf("Entry Point: %p\n", EntryPoint);
      }
      else
      {
        printf(
            "ERROR (PrintProcessInfo): Couldn't read module info structure.\n");
      }
    }
    CloseHandle(hProcess);
  }
  else
  {
    printf("ERROR (PrintProcessInfo): Couldn't open the process.\n");
  }
}

void
PrintPriorityClass(DWORD processID)
{
  DWORD dwDesiredAccess = PROCESS_QUERY_INFORMATION | PROCESS_VM_READ;
  DWORD dwPriorityClass;
  HANDLE hProcess;

  hProcess = OpenProcess(dwDesiredAccess, FALSE, processID);

  dwPriorityClass = GetPriorityClass(hProcess);

  for (int i = 0; i < 6; i++)
  {
    if (dwPriorityClass == dwPriorityClassValue[i])
    {
      printf("Process priority class is: %s\n", szPriorityClassName[i]);
      break;
    }
  }

  CloseHandle(hProcess);
}

void
PrintModuleFileName(DWORD processID)
{
  printf("Process ID: %d\n", processID);

  HANDLE hProcess;
  HMODULE hModules[32];
  HMODULE hModule;
  TCHAR lpFilename[MAX_PATH] = TEXT("");
  TCHAR szBaseName[MAX_PATH] = TEXT("");
  DWORD cbNeeded;
  DWORD dwDesiredAccess = PROCESS_VM_READ | PROCESS_QUERY_INFORMATION;

  hProcess = OpenProcess(dwDesiredAccess, FALSE, processID);

  if (NULL != hProcess)
  {
    if (EnumProcessModules(hProcess, hModules, sizeof(hModules), &cbNeeded))
    {
      GetModuleBaseName(hProcess, hModules[0], szBaseName,
          sizeof(szBaseName) / sizeof(TCHAR));

      GetModuleFileNameEx(hProcess, hModules[0], lpFilename, MAX_PATH);
      _tprintf("Base name: %s File name: %s\n", szBaseName, lpFilename);
    }
    CloseHandle(hProcess);
  }
}

void
PrintProcessVersion(DWORD processID)
{
  DWORD dwVersion = GetProcessVersion(processID);

  short unsigned major, minor;

  major = (dwVersion & 0xFFFF0000) >> 16;
  minor = dwVersion & 0x0000FFFF;

  printf("Version: %i.%i\n", major, minor);
}

BOOL
GetProcessIdFromName(DWORD *processID, TCHAR *szModuleName)
{
  HANDLE hProcess = CreateToolhelp32Snapshot(
      TH32CS_SNAPPROCESS | TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, 0);
  if (hProcess)
  {
    PROCESSENTRY32 pe32 = { sizeof(PROCESSENTRY32) };
    Process32First(hProcess, &pe32);

    do
    {
      if ((strcmp(pe32.szExeFile, szModuleName) == 0))
      {
        fprintf(stdout, "Found it!!! The PID you're looking for is %i\n",
            pe32.th32ProcessID);
        *processID = pe32.th32ProcessID;

        MODULEENTRY32 me32 = { sizeof(MODULEENTRY32) };
        Module32First(hProcess, &me32);

        fprintf(stdout, "Module base: %p\n", me32.modBaseAddr);

        return TRUE;
      }

      MODULEENTRY32 me32 = { sizeof(MODULEENTRY32) };
      HANDLE hModuleSnap = CreateToolhelp32Snapshot(
          TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, pe32.th32ProcessID);

      do
      {
        // fprintf(stdout, "Module name: %s\n", me32.szModule);
        if ((strcmp(me32.szModule, szModuleName) == 0))
        {
          fprintf(stdout, "Found it!!! The PID you're looking for is %i\n",
              pe32.th32ProcessID);

          fprintf(stdout, "Module base: %p\n", me32.modBaseAddr);

          *processID = pe32.th32ProcessID;
          return TRUE;
        }
      } while (Module32Next(hModuleSnap, &me32));
    } while (Process32Next(hProcess, &pe32));

    CloseHandle(hProcess);
  }
  return FALSE;
}

BOOL
GetProcessIdFromName2(DWORD *processID, TCHAR *szModuleName)
{
  HANDLE hProcess = CreateToolhelp32Snapshot(
      TH32CS_SNAPPROCESS | TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, 0);
  if (hProcess)
  {
    PROCESSENTRY32 pe32 = { sizeof(PROCESSENTRY32) };
    Process32First(hProcess, &pe32);

    do
    {
      if ((strcmp(pe32.szExeFile, szModuleName) == 0))
      {
        fprintf(stdout, "Found it!!! The PID you're looking for is %i\n",
            pe32.th32ProcessID);
        *processID = pe32.th32ProcessID;

        MODULEENTRY32 me32 = { sizeof(MODULEENTRY32) };
        Module32First(hProcess, &me32);

        fprintf(stdout, "Module base: %p\n", me32.modBaseAddr);

        HANDLE hModuleSnap = CreateToolhelp32Snapshot(
            TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, pe32.th32ProcessID);
        do
        {
          // fprintf(stdout, "Module name: %s\n", me32.szModule);
          if ((strcmp(me32.szModule, szModuleName) == 0))
          {
            fprintf(stdout, "Found it!!! The PID you're looking for is %i\n",
                pe32.th32ProcessID);

            fprintf(stdout, "Module base: %p\n", me32.modBaseAddr);
          }
        } while (Module32Next(hModuleSnap, &me32));
      }

    } while (Process32Next(hProcess, &pe32));

    CloseHandle(hProcess);
  }
  return FALSE;
}

DWORD
ReadGameMemory(DWORD processID, SIZE_T Offset, SIZE_T BytesToRead, void *Value)
{
  SIZE_T BytesActuallyRead = -1;
  SIZE_T FinalOffset = Offset - PSX_TO_EMU;

  // fprintf(stdout, "FinalOffset: 0x%02x - 0x%02x = 0x%02x\n", Offset,
  // PSX_TO_EMU, FinalOffset);

  Toolhelp32ReadProcessMemory(processID, (LPCVOID) FinalOffset, (LPVOID) Value,
      BytesToRead, &BytesActuallyRead);

  //   if (BytesToRead > BytesActuallyRead)
  //   {
  //     _tprintf(
  //         TEXT("ERROR (ReadGameMemory): Not all bytes read from
  //         memory.\n"));
  //   }
  // }
  // else
  // {
  //   _tprintf(TEXT(
  //       "ERROR (ReadGameMemory): Couldn't read from the process
  //       memory\n"));
  // }
  return BytesActuallyRead;
}

void PrintHeapList(processID)
{
  fprintf(stdout, "Looking for a heap list...\n");

  HEAPLIST32 hl32 = { sizeof(HEAPLIST32) };

  HANDLE hHeapSnap = CreateToolhelp32Snapshot(TH32CS_SNAPHEAPLIST, processID);

  if (Heap32ListFirst(hHeapSnap, &hl32))
  {
    fprintf(stdout, "Heap list found!!!\n");
    do
    {
      HEAPENTRY32 he32 = { sizeof(HEAPENTRY32) };

      if (Heap32First(&he32, processID, hl32.th32HeapID))
      {

        do
        {
          fprintf(stdout, "Block size: %i\n", he32.dwBlockSize);

          he32.dwSize = sizeof(HEAPENTRY32);
        } while (Heap32Next(&he32));
      }
      hl32.dwSize = sizeof(HEAPLIST32);

    } while (Heap32ListNext(hHeapSnap, &hl32));
  }

  CloseHandle(hHeapSnap);
}

BOOL
ListProcessModules(DWORD dwPID)
{
  HANDLE hModuleSnap = INVALID_HANDLE_VALUE;
  MODULEENTRY32 me32;

  //  Take a snapshot of all modules in the specified process.
  hModuleSnap =
      CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, dwPID);
  if (hModuleSnap == INVALID_HANDLE_VALUE)
  {
    // printError(TEXT("CreateToolhelp32Snapshot (of modules)"));
    return (FALSE);
  }
  me32.dwSize = sizeof(MODULEENTRY32);

  //  Retrieve information about the first module,
  //  and exit if unsuccessful
  if (!Module32First(hModuleSnap, &me32))
  {
    // printError(TEXT("Module32First"));  // Show cause of failure
    CloseHandle(hModuleSnap); // Must clean up the snapshot object!
    return (FALSE);
  }

  //  Now walk the module list of the process,
  //  and display information about each module
  do
  {
    _tprintf(TEXT("\n\n     MODULE NAME:     %s"), me32.szModule);
    _tprintf(TEXT("\n     executable     = %s"), me32.szExePath);
    _tprintf(TEXT("\n     process ID     = 0x%08X"), me32.th32ProcessID);
    _tprintf(TEXT("\n     ref count (g)  =     0x%04X"), me32.GlblcntUsage);
    _tprintf(TEXT("\n     ref count (p)  =     0x%04X"), me32.ProccntUsage);
    _tprintf(TEXT("\n     base address   = 0x%08X"), (DWORD) me32.modBaseAddr);
    _tprintf(TEXT("\n     base size      = %d"), me32.modBaseSize);

  } while (Module32Next(hModuleSnap, &me32));

  _tprintf(TEXT("\n"));

  //  Do not forget to clean up the snapshot object.
  CloseHandle(hModuleSnap);
  return (TRUE);
}

BOOL
ListProcessThreads(DWORD dwPID)
{
  HANDLE hThreadSnap = INVALID_HANDLE_VALUE;
  THREADENTRY32 te32 = { sizeof(THREADENTRY32) };

  //  Take a snapshot of all modules in the specified process.
  hThreadSnap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
  if (hThreadSnap == INVALID_HANDLE_VALUE)
  {
    // printError(TEXT("CreateToolhelp32Snapshot (of modules)"));
    return (FALSE);
  }

  //  Retrieve information about the first module,
  //  and exit if unsuccessful
  if (!Thread32First(hThreadSnap, &te32))
  {
    // printError(TEXT("Module32First"));  // Show cause of failure
    CloseHandle(hThreadSnap); // Must clean up the snapshot object!
    return (FALSE);
  }

  //  Now walk the module list of the process,
  //  and display information about each module
  do
  {
    if (te32.th32OwnerProcessID == dwPID)
    {

      _tprintf(TEXT("\n\n     THREAD ID:     %i"), te32.th32ThreadID);
      _tprintf(TEXT("\n     dwSize:     %i"), te32.dwSize);
      _tprintf(TEXT("\n     Base Priority     = %i"), te32.tpBasePri);
      _tprintf(TEXT("\n     Delta Priority    = %i"), te32.tpDeltaPri);
    }

  } while (Thread32Next(hThreadSnap, &te32));

  _tprintf(TEXT("\n"));

  //  Do not forget to clean up the snapshot object.
  CloseHandle(hThreadSnap);
  return (TRUE);
}

HANDLE
GetProcessHandle(TCHAR *ProcessName, DWORD *ReturnedProcessId)
{
  PROCESSENTRY32 pe32 = { sizeof(PROCESSENTRY32) };
  HANDLE hSnap;

  // pe->dwSize = sizeof(PROCESSENTRY32W);
  hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

  if (hSnap == INVALID_HANDLE_VALUE)
  {
    return 0;
  }

  BOOL bProcess = Process32First(hSnap, &pe32);
  while (bProcess)
  {
    if (strcmp(pe32.szExeFile, ProcessName) == 0)
    {
      HANDLE ProcessHandle =
          OpenProcess(PROCESS_ALL_ACCESS, 0, pe32.th32ProcessID);

      if (ReturnedProcessId)
        *ReturnedProcessId = pe32.th32ProcessID;

      CloseHandle(hSnap);

      return ProcessHandle;
    }

    bProcess = Process32Next(hSnap, &pe32);
  }

  CloseHandle(hSnap);

  return 0;
}

ULONG
GetModuleBase(TCHAR *ModuleName, DWORD ProcessId)
{
  _tprintf(_T("Searching for %s\n"), ModuleName);

  MODULEENTRY32 me32 = { sizeof(MODULEENTRY32) };

  HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE32, ProcessId);

  if (hSnap == INVALID_HANDLE_VALUE)
  {
    return 0;
  }

  BOOL bModule = Module32First(hSnap, &me32);
  while (bModule)
  {
    if (!ModuleName || strcmp(me32.szModule, ModuleName) == 0)
    {
      _tprintf("I found the DLL!!!\n");
      CloseHandle(hSnap);
      return (ULONG) me32.modBaseAddr;
    }

    bModule = Module32Next(hSnap, &me32);
  }

  CloseHandle(hSnap);

  return 0;
}

HRSRC
GetModuleResource(HANDLE RemoteProcessHandle, TCHAR *szResourceName)
{
  HRSRC hResource =
      FindResource(RemoteProcessHandle, szResourceName, RT_RCDATA);

  return hResource;
}

void
EnumProcessModules2(DWORD processID)
{
  HANDLE hProcess;
  DWORD dwDesiredAccess = PROCESS_QUERY_INFORMATION | PROCESS_VM_READ;

  hProcess = OpenProcess(dwDesiredAccess, FALSE, processID);

  HMODULE hmArray[256];
  DWORD cb = sizeof(hmArray);
  DWORD cbNeeded;
  DWORD dwFilterFlag = LIST_MODULES_32BIT | LIST_MODULES_64BIT;
  TCHAR szModulName[MAX_PATH];

  EnumProcessModulesEx(hProcess, hmArray, cb, &cbNeeded, dwFilterFlag);

  _tprintf("cb: %i, cbNeeded: %i", cb, cbNeeded);

  int cbSize = cbNeeded / sizeof(HMODULE);

  for (int i = 0; i < cbSize; ++i)
  {
    GetModuleFileNameEx(hProcess, hmArray[i], szModulName, MAX_PATH);
    _tprintf(_T("Module name: %s"), szModuleName);
  }
}

#endif