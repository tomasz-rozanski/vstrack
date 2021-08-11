#ifndef _VST_PROCESS_H
#define _VST_PROCESS_H

u32 PriorityClassValue[6] = { ABOVE_NORMAL_PRIORITY_CLASS,
  BELOW_NORMAL_PRIORITY_CLASS, HIGH_PRIORITY_CLASS, IDLE_PRIORITY_CLASS,
  NORMAL_PRIORITY_CLASS, REALTIME_PRIORITY_CLASS };

char *szPriorityClassName[6] = { "ABOVE_NORMAL_PRIORITY_CLASS",
  "BELOW_NORMAL_PRIORITY_CLASS", "HIGH_PRIORITY_CLASS", "IDLE_PRIORITY_CLASS",
  "NORMAL_PRIORITY_CLASS", "REALTIME_PRIORITY_CLASS" };

void
ChangePageProtection(u32 processID, void *lpAddress, usize Size)
{
  u32 flNewProtect = PAGE_READWRITE;
  u32 flOldProtect;

  HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processID);

  VirtualProtectEx(hProcess, lpAddress, Size, flNewProtect, &flOldProtect);
}

usize
GetRegionSize(u32 processID, const void *lpAddress)
{
  u32 DesiredAccess = PROCESS_QUERY_INFORMATION;
  HANDLE hProcess = OpenProcess(DesiredAccess, FALSE, processID);

  if (hProcess)
  {
    MEMORY_BASIC_INFORMATION mbiBuffer = { 0 };
    if (VirtualQueryEx(hProcess, lpAddress, &mbiBuffer, sizeof(mbiBuffer)))
    {
      u32 Protect = mbiBuffer.Protect;
      return mbiBuffer.RegionSize;
    }
  }
  return -1;
}

u64
GetModuleDllBase(u32 processID, char *szModuleName)
{
  u32 DesiredAccess = PROCESS_QUERY_INFORMATION | PROCESS_VM_READ;
  HANDLE hProcess;
  HMODULE hModule;
  MODULEINFO modinfo = { 0 };
  u32 cbNeeded;

  u64 lpBaseOfDll;

  hProcess = OpenProcess(DesiredAccess, FALSE, processID);

  if (NULL != hProcess)
  {
    if (EnumProcessModules(hProcess, &hModule, sizeof(hModule), &cbNeeded))
    {
      if (GetModuleInformation(hProcess, hModule, &modinfo, sizeof(modinfo)))
      {
        lpBaseOfDll = (u64) modinfo.lpBaseOfDll;
      }
      else
      {
        fprintf(stderr, "ERROR: Couldn't read module info structure.\n");
      }
    }
    CloseHandle(hProcess);
  }
  else
  {
    fprintf(stderr, "ERROR: Couldn't open the process.\n");
  }
  return lpBaseOfDll;
}

u32
FindProcessIdByName(u32 *ProcessesList, u32 ProcessesNumber, char *szModuleName)
{
  char szProcessName[MAX_PATH] = "";
  char lpFilename[MAX_PATH] = "";
  HMODULE hMods[1024];
  HANDLE hProcess;
  char szBuffer[64];
  u32 cModules;
  u32 processID = -1;
  u32 DesiredAcces = PROCESS_QUERY_INFORMATION | PROCESS_VM_READ;

  for (int i = 0; i < ProcessesNumber; i++)
  {

    processID = *ProcessesList++;

    hProcess = OpenProcess(DesiredAcces, FALSE, processID);

    // Get the process name.
    if (NULL != hProcess)
    {
      HMODULE hMod;
      u32 cbNeeded;

      if (EnumProcessModules(hProcess, hMods, sizeof(hMods), &cbNeeded))
      {
        for (int i = 0; i < (cbNeeded / sizeof(HMODULE)); ++i)
        {
          GetModuleBaseName(hProcess, hMods[i], szProcessName,
              sizeof(szProcessName) / sizeof(char));
          // GetModuleFileNameEx(hProcess, hMods[i], lpFilename, MAX_PATH);

          // _tprintf("%d %s\n", processID, szProcessName);
          // _tprintf("%d %s\n", processID, lpFilename);

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
PrintProcessNameAndID(u32 processID)
{
  char szProcessName[MAX_PATH] = "<unknown>";

  // Get a handle to the process.
  HANDLE hProcess = OpenProcess(
      PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processID);

  // Get the process name.
  if (NULL != hProcess)
  {
    HMODULE hMod;
    u32 cbNeeded;

    if (EnumProcessModules(hProcess, &hMod, sizeof(hMod), &cbNeeded))
    {
      GetModuleBaseName(
          hProcess, hMod, szProcessName, sizeof(szProcessName) / sizeof(char));
    }
  }

  // Print the process name and ID.
  fprintf(stderr, "%s (PID: %u)\n", szProcessName, processID);

  // Release the handle to the process.
  CloseHandle(hProcess);
}

u32
ReadMemoryValue(u32 processID, usize offset, usize BytesToRead)
{
  u32 Value = -1;
  // Get a handle to the process.
  HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processID);

  // Get the process name.
  if (NULL != hProcess)
  {
    usize NumberOfBytesActuallyRead = -1;

    if (ReadProcessMemory(hProcess, (const void *) offset, &Value, BytesToRead,
            &NumberOfBytesActuallyRead))
    {
      if (BytesToRead > NumberOfBytesActuallyRead)
      {
        fprintf(stderr, "ERROR: Not all bytes read from memory.\n");
      }
      CloseHandle(hProcess);
    }
    else
    {
      fprintf(stderr,
          "ERROR (ReadMemoryValue): Couldn't read from the process memory\n");
    }
  }

  // CloseHandle(hProcess);
  return Value;
}

u8
ReadByteFromProcessMemory(u32 processID, usize offset)
{
  u8 Value = 0;
  // Get a handle to the process.
  HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processID);

  // Get the process name.
  if (NULL != hProcess)
  {
    usize NumberOfBytesActuallyRead = -1;

    if (ReadProcessMemory(hProcess, (const void *) offset, &Value, 1,
            &NumberOfBytesActuallyRead))
    {
    }
    else
    {
      fprintf(stderr,
          "ERROR (ReadMemoryValue): Couldn't read from the process memory\n");
    }
  }

  CloseHandle(hProcess);
  return Value;
}

u32
ReadMemoryValue2(u32 processID, usize offset, usize BytesToRead, void *Value)
{
  usize BytesActuallyRead = -1;
  // Get a handle to the process.
  HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processID);

  // Get the process name.
  if (NULL != hProcess)
  {

    u8 *pvalue = Value;
    for (int i = 0; i < BytesToRead; ++i)
    {
      ReadProcessMemory(hProcess, (const void *) offset++, (void *) pvalue++, 1,
          &BytesActuallyRead);
    }
  }

  // CloseHandle(hProcess);
  return BytesActuallyRead;
}

u32
_GetProcessMemory(u32 processID, usize Offset, usize BytesToRead, void *Value)
{
  usize BytesActuallyRead = -1;
  usize FinalOffset = (usize) emuBaseAddress + (usize) Offset;

  // Get a handle to the process.
  fprintf(stderr, "GetProcessMemory - Offset: 0x%llx\n", FinalOffset);

  HANDLE hProcess = OpenProcess(
      PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processID);

  // fprintf(stdout, "hProcess: %i\n", hProcess);

  // Get the process name.
  if (NULL != hProcess)
  {
    if (ReadProcessMemory(hProcess, (const void *) FinalOffset, Value,
            BytesToRead, &BytesActuallyRead))
    {
      if (BytesToRead > BytesActuallyRead)
      {
        fprintf(stderr,
            "ERROR (GetProcessMemory): Not all bytes read from memory.\n");
      }
      CloseHandle(hProcess);
    }
    else
    {
      fprintf(stderr,
          "ERROR (GetProcessMemory): Couldn't read from the process memory\n");
      exit(1);
    }
  }
  // CloseHandle(hProcess);
  return BytesActuallyRead;
}

void *
GetProcessMemory2(u32 processID, usize Offset, usize BytesToRead)
{
  usize BytesActuallyRead = -1;
  usize FinalOffset = (usize) emuBaseAddress + (usize) Offset;

  // Get a handle to the process.

  u8 *buffer = (u8 *) malloc(BytesToRead);
  fprintf(stderr, "GetProcessMemory - Offset: 0x%llx\n", FinalOffset);

  HANDLE hProcess = OpenProcess(
      PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processID);

  // fprintf(stdout, "hProcess: %i\n", hProcess);

  // Get the process name.
  if (NULL != hProcess)
  {
    if (ReadProcessMemory(hProcess, (const void *) FinalOffset, buffer,
            BytesToRead, &BytesActuallyRead))
    {
      if (BytesToRead > BytesActuallyRead)
      {
        fprintf(stderr,
            "ERROR (GetProcessMemory): Not all bytes read from memory.\n");
      }
      CloseHandle(hProcess);
    }
    else
    {
      fprintf(stderr,
          "ERROR (GetProcessMemory): Couldn't read from the process memory\n");
      exit(1);
    }
  }
  // CloseHandle(hProcess);
  return buffer;
}

void
PrintMemoryValue(
    u32 processID, usize offset, usize BytesToRead, char *szDescription)
{
  char szBuffer[1024] = "";

  // Make sure to change Value size depending from the BytesToRead
  i16 Value = -1;

  if (_GetProcessMemory(processID, offset, BytesToRead, &Value))
  {
    fprintf(stdout, "Value of %s: %d\n", szDescription, Value);
  }
  else
  {
    fprintf(stderr, "ERROR (PrintMemoryValue): Couldn't read the Value\n");
  }
}

void
PrintProcessInfo(u32 processID)
{
  u32 DesiredAccess = PROCESS_QUERY_INFORMATION | PROCESS_VM_READ;
  HANDLE hProcess;
  HMODULE hModule;
  MODULEINFO modinfo;
  u32 cbNeeded;

  hProcess = OpenProcess(DesiredAccess, FALSE, processID);

  if (NULL != hProcess)
  {
    if (EnumProcessModules(hProcess, &hModule, sizeof(hModule), &cbNeeded))
    {
      if (GetModuleInformation(hProcess, hModule, &modinfo, sizeof(modinfo)))
      {
        void *lpBaseOfDll = modinfo.lpBaseOfDll;
        u32 SizeOfImage = modinfo.SizeOfImage;
        void *EntryPoint = modinfo.EntryPoint;

        fprintf(stdout, "Base of DLL: %p\n", lpBaseOfDll);
        fprintf(stdout, "Size of Image: %d\n", SizeOfImage);
        fprintf(stdout, "Entry Point: %p\n", EntryPoint);
      }
      else
      {
        fprintf(stderr,
            "ERROR (PrintProcessInfo): Couldn't read module info structure.\n");
      }
    }
    CloseHandle(hProcess);
  }
  else
  {
    fprintf(stderr, "ERROR (PrintProcessInfo): Couldn't open the process.\n");
  }
}

void
PrintPriorityClass(u32 processID)
{
  u32 DesiredAccess = PROCESS_QUERY_INFORMATION | PROCESS_VM_READ;
  u32 PriorityClass;
  HANDLE hProcess;

  hProcess = OpenProcess(DesiredAccess, FALSE, processID);

  PriorityClass = GetPriorityClass(hProcess);

  for (int i = 0; i < 6; i++)
  {
    if (PriorityClass == PriorityClassValue[i])
    {
      fprintf(
          stdout, "Process priority class is: %s\n", szPriorityClassName[i]);
      break;
    }
  }

  CloseHandle(hProcess);
}

void
PrintModuleFileName(u32 processID)
{
  fprintf(stdout, "Process ID: %d\n", processID);

  HANDLE hProcess;
  HMODULE hModules[32];
  HMODULE hModule;
  char lpFilename[MAX_PATH] = "";
  char szBaseName[MAX_PATH] = "";
  u32 cbNeeded;
  u32 DesiredAccess = PROCESS_VM_READ | PROCESS_QUERY_INFORMATION;

  hProcess = OpenProcess(DesiredAccess, FALSE, processID);

  if (NULL != hProcess)
  {
    if (EnumProcessModules(hProcess, hModules, sizeof(hModules), &cbNeeded))
    {
      GetModuleBaseName(
          hProcess, hModules[0], szBaseName, sizeof(szBaseName) / sizeof(char));

      GetModuleFileNameEx(hProcess, hModules[0], lpFilename, MAX_PATH);
      fprintf(stdout, "Base name: %s File name: %s\n", szBaseName, lpFilename);
    }
    CloseHandle(hProcess);
  }
}

void
PrintProcessVersion(u32 processID)
{
  u32 Version = GetProcessVersion(processID);

  u16 major, minor;

  major = (Version & 0xFFFF0000) >> 16;
  minor = Version & 0x0000FFFF;

  fprintf(stdout, "Version: %i.%i\n", major, minor);
}

BOOL
GetProcessIdFromName(u32 *processID, char *szModuleName)
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
#ifdef DEBUG
        fprintf(stdout, "Found it!!! The PID you're looking for is %i\n",
            pe32.th32ProcessID);
#endif
        *processID = pe32.th32ProcessID;

        MODULEENTRY32 me32 = { sizeof(MODULEENTRY32) };
        Module32First(hProcess, &me32);

#ifdef DEBUG
        fprintf(stdout, "Module base: %p\n", me32.modBaseAddr);
#endif
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
GetProcessIdFromName2(u32 *processID, char *szModuleName)
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

u32
ReadGameMemory(u32 processID, usize Offset, usize BytesToRead, void *Value)
{
  usize BytesActuallyRead = -1;
  usize FinalOffset =
      (usize)((usize) emuBaseAddress + (usize)(Offset & 0x01fffff));

  Toolhelp32ReadProcessMemory(
      processID, (usize *) FinalOffset, Value, BytesToRead, &BytesActuallyRead);

  return BytesActuallyRead;
}

void *
ReadGameMemory2(u32 processID, usize Offset, usize BytesToRead)
{

  usize FinalOffset = (usize) emuBaseAddress + (usize) Offset;

  void *pValue = (void *) malloc(BytesToRead);

  HANDLE hProcess = OpenProcess(
      PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processID);

  if (NULL != hProcess)
  {
    ReadProcessMemory(
        hProcess, (const void *) FinalOffset, pValue, BytesToRead, NULL);
  }

  // CloseHandle(hProcess);

  return pValue;
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
          fprintf(stdout, "Block size: %I64i\n", he32.dwBlockSize);

          he32.dwSize = sizeof(HEAPENTRY32);
        } while (Heap32Next(&he32));
      }
      hl32.dwSize = sizeof(HEAPLIST32);

    } while (Heap32ListNext(hHeapSnap, &hl32));
  }

  CloseHandle(hHeapSnap);
}

BOOL
ListProcessModules(u32 dwPID)
{
  HANDLE hModuleSnap = INVALID_HANDLE_VALUE;
  MODULEENTRY32 me32;

  //  Take a snapshot of all modules in the specified process.
  hModuleSnap =
      CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, dwPID);
  if (hModuleSnap == INVALID_HANDLE_VALUE)
  {
    // printError("CreateToolhelp32Snapshot (of modules)");
    return (FALSE);
  }
  me32.dwSize = sizeof(MODULEENTRY32);

  //  Retrieve information about the first module,
  //  and exit if unsuccessful
  if (!Module32First(hModuleSnap, &me32))
  {
    // printError("Module32First");  // Show cause of failure
    CloseHandle(hModuleSnap); // Must clean up the snapshot object!
    return (FALSE);
  }

  //  Now walk the module list of the process,
  //  and display information about each module
  do
  {
    if (strcmp(me32.szModule, szModuleName) == 0)
    {

      fprintf(stdout, "\n\n     MODULE NAME:     %s\n", me32.szModule);
      fprintf(stdout, "     executable     = %s\n", me32.szExePath);
      fprintf(stdout, "     process ID     = 0x%08X\n", me32.th32ProcessID);
      fprintf(stdout, "     ref count (g)  =     0x%04X\n", me32.GlblcntUsage);
      fprintf(stdout, "     ref count (p)  =     0x%04X\n", me32.ProccntUsage);
      fprintf(stdout, "     base address   = 0x%p\n", me32.modBaseAddr);
      fprintf(stdout, "     base size      = %d\n", me32.modBaseSize);
    }

  } while (Module32Next(hModuleSnap, &me32));

  fprintf(stdout, "\n");

  //  Do not forget to clean up the snapshot object.
  CloseHandle(hModuleSnap);
  return (TRUE);
}

u64
FindDllAddress(u32 dwPID, char *szModulName)
{
  HANDLE hModuleSnap = INVALID_HANDLE_VALUE;
  MODULEENTRY32 me32;

  //  Take a snapshot of all modules in the specified process.
  hModuleSnap =
      CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, dwPID);
  if (hModuleSnap == INVALID_HANDLE_VALUE)
  {
    // printError("CreateToolhelp32Snapshot (of modules)");
    return (FALSE);
  }
  me32.dwSize = sizeof(MODULEENTRY32);

  //  Retrieve information about the first module,
  //  and exit if unsuccessful
  if (!Module32First(hModuleSnap, &me32))
  {
    // printError("Module32First");  // Show cause of failure
    CloseHandle(hModuleSnap); // Must clean up the snapshot object!
    return (FALSE);
  }

  //  Now walk the module list of the process,
  //  and display information about each module
  do
  {
    if (strcmp(szModuleName, me32.szModule) == 0)
    {
      return (u64) me32.modBaseAddr;
    }
    // _tprintf("\n\n     MODULE NAME:     %s\n", me32.szModule);
    // _tprintf("     executable     = %s\n", me32.szExePath);
    // _tprintf("     process ID     = 0x%08X\n", me32.th32ProcessID);
    // _tprintf("     ref count (g)  =     0x%04X\n", me32.GlblcntUsage);
    // _tprintf("     ref count (p)  =     0x%04X\n", me32.ProccntUsage);
    // _tprintf("     base address   = 0x%p\n", me32.modBaseAddr);
    // _tprintf("     base size      = %d\n", me32.modBaseSize);

  } while (Module32Next(hModuleSnap, &me32));

  //  Do not forget to clean up the snapshot object.
  CloseHandle(hModuleSnap);
  return (0);
}

BOOL
ListProcessThreads(u32 dwPID)
{
  HANDLE hThreadSnap = INVALID_HANDLE_VALUE;
  THREADENTRY32 te32 = { sizeof(THREADENTRY32) };

  //  Take a snapshot of all modules in the specified process.
  hThreadSnap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
  if (hThreadSnap == INVALID_HANDLE_VALUE)
  {
    // printError("CreateToolhelp32Snapshot (of modules)");
    return (FALSE);
  }

  //  Retrieve information about the first module,
  //  and exit if unsuccessful
  if (!Thread32First(hThreadSnap, &te32))
  {
    // printError("Module32First");  // Show cause of failure
    CloseHandle(hThreadSnap); // Must clean up the snapshot object!
    return (FALSE);
  }

  //  Now walk the module list of the process,
  //  and display information about each module
  do
  {
    if (te32.th32OwnerProcessID == dwPID)
    {

      fprintf(stdout, "\n\n     THREAD ID:     %i", te32.th32ThreadID);
      fprintf(stdout, "\n     dwSize:     %i", te32.dwSize);
      fprintf(stdout, "\n     Base Priority     = %i", te32.tpBasePri);
      fprintf(stdout, "\n     Delta Priority    = %i", te32.tpDeltaPri);
    }

  } while (Thread32Next(hThreadSnap, &te32));

  fprintf(stdout, "\n");

  //  Do not forget to clean up the snapshot object.
  CloseHandle(hThreadSnap);
  return (TRUE);
}

HANDLE
GetProcessHandle(char *ProcessName, u32 *ReturnedProcessId)
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

usize
GetModuleBase(char *ModuleName, u32 ProcessId)
{
  fprintf(stdout, "Searching for %s\n", ModuleName);

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
      fprintf(stdout, "I found the DLL!!!\n");
      CloseHandle(hSnap);
      return (usize) me32.modBaseAddr;
    }

    bModule = Module32Next(hSnap, &me32);
  }

  CloseHandle(hSnap);

  return 0;
}

HRSRC
GetModuleResource(HANDLE RemoteProcessHandle, char *szResourceName)
{
  HRSRC hResource =
      FindResource(RemoteProcessHandle, szResourceName, RT_RCDATA);

  return hResource;
}

void
EnumProcessModules2(u32 processID)
{
  HANDLE hProcess;
  u32 DesiredAccess = PROCESS_QUERY_INFORMATION | PROCESS_VM_READ;

  hProcess = OpenProcess(DesiredAccess, FALSE, processID);

  HMODULE hmArray[256];
  u32 cb = sizeof(hmArray);
  u32 cbNeeded;
  u32 dwFilterFlag = LIST_MODULES_32BIT | LIST_MODULES_64BIT;
  char szModulName[MAX_PATH];

  EnumProcessModulesEx(hProcess, hmArray, cb, &cbNeeded, dwFilterFlag);

  fprintf(stdout, "cb: %i, cbNeeded: %i", cb, cbNeeded);

  int cbSize = cbNeeded / sizeof(HMODULE);

  for (int i = 0; i < cbSize; ++i)
  {
    GetModuleFileNameEx(hProcess, hmArray[i], szModulName, MAX_PATH);
    fprintf(stdout, "Module name: %s\n", szModuleName);
  }
}

BOOL
EnableDebugPrivilege(void)
{
  // Get the privilege value for `SeDebugPrivilege`
  LUID luidDebugPrivilege;
  LUID luidProfilePrivilege;

  if (!LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &luidDebugPrivilege))
  {
    ErrorExit("LookupPrivilegeValue");
  }

  // Fill up the TOKEN_PRIVILEGES structure
  TOKEN_PRIVILEGES tkPrivs;

  tkPrivs.PrivilegeCount = 1; // Modify 2 privileges
  tkPrivs.Privileges[0].Luid =
      luidDebugPrivilege; // we want to modify `SeDebugPrivilege`
  tkPrivs.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED; // enable it

  HANDLE hCurrentProcess = GetCurrentProcess();
  HANDLE hProcessToken;

  if (!OpenProcessToken(
          hCurrentProcess, TOKEN_ADJUST_PRIVILEGES, &hProcessToken))
  {
    ErrorExit("OpenProcessToken");
  }

  // Let's enable Debug privileges in the token
  if (!AdjustTokenPrivileges(hProcessToken, FALSE, &tkPrivs, 0, NULL, NULL))
  {
    ErrorExit("AdjustTokenPrivileges");
  }

  return TRUE;
}

u8 *
GetAddressOfData(DWORD pid, const u8 *data, usize len, u8 maxAttempts)
{
  HANDLE process =
      OpenProcess(PROCESS_VM_READ | PROCESS_QUERY_INFORMATION, FALSE, pid);
  if (process)
  {
    SYSTEM_INFO si;
    GetSystemInfo(&si);

    MEMORY_BASIC_INFORMATION info;
    u8 *chunk;
    u8 *p = 0;
    usize curAttempt = 1;
    while (p < si.lpMaximumApplicationAddress)
    {
      if (VirtualQueryEx(process, p, &info, sizeof(info)) == sizeof(info))
      {
        p = (u8 *) info.BaseAddress;
        chunk = (u8 *) malloc(info.RegionSize);
        usize bytesRead;
        if (ReadProcessMemory(
                process, p, (u8 *) chunk + 0, info.RegionSize, &bytesRead))
        {
          for (usize i = 0; i < (bytesRead - len); ++i)
          {
            if (memcmp(data, (u8 *) chunk + i, len) == 0)
            {
              free(chunk);
              if (curAttempt >= maxAttempts)
              {
                return (u8 *) p + i;
              }
              else
              {
                curAttempt += 1;
              }
            }
          }
        }
        free(chunk);
        p += info.RegionSize;
      }
    }
  }
  return 0;
}

usize
GetEmuBaseAddress(char *szExeName, u8 maxAttempts)
{
  GetProcessIdFromName(&processID, szExeName);
  u8 *ret = GetAddressOfData(processID, EMU_BASE_MAGIC_STRING,
      sizeof(EMU_BASE_MAGIC_STRING), maxAttempts);

  return (usize) ret;
}

#endif
