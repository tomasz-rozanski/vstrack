#ifndef _VST_DEBUG_H
#define _VST_DEBUG_H

void
WriteDebugInfo(void)
{
  TCHAR szBuffer[1024];

  processBaseAddress = GetModuleDllBase(processID, szModuleName);
  sprintf(szBuffer, "processBaseAddress: 0x%08x\n", processBaseAddress);
  WriteDebugLog(szBuffer);

  // Maximum window dimensions
  sprintf(
      szBuffer, "conMaxSizeX: %i, conMaxSizeY: %i\n", conMaxSizeX, conMaxSizeY);
  WriteDebugLog(szBuffer);

  // Pointer to the back-buffer memory
  sprintf(szBuffer, "chiBuffer address: 0x%08p\n", chiBuffer);
  WriteDebugLog(szBuffer);
}

#endif