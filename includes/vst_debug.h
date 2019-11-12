#ifndef _VST_DEBUG_H
#define _VST_DEBUG_H

void
WriteDebugInfo(void)
{
  char szBuffer[1024];

  sprintf_s(szBuffer, _countof(szBuffer), "processBaseAddress: 0x%016llx\n",
      processBaseAddress);
  WriteDebugLog(szBuffer);

  // Maximum window dimensions
  sprintf_s(szBuffer, _countof(szBuffer), "conMaxSizeX: %i, conMaxSizeY: %i\n",
      conMaxSizeX, conMaxSizeY);
  WriteDebugLog(szBuffer);

  // Pointer to the back-buffer memory
  sprintf_s(
      szBuffer, _countof(szBuffer), "chiBuffer address: 0x%08p\n", chiBuffer);
  WriteDebugLog(szBuffer);
}

#endif