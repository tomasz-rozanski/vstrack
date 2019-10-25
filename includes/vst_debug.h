#ifndef _VST_DEBUG_H
#define _VST_DEBUG_H

void
WriteDebugInfo(void)
{
  TCHAR szBuffer[1024];

  // Maximum window dimensions
  sprintf(
      szBuffer, "conMaxSizeX: %i, conMaxSizeY: %i\n", conMaxSizeX, conMaxSizeY);
  WriteDebugLog(szBuffer);

  // Pointer to the back-buffer memory
  sprintf(szBuffer, "chiBuffer address: 0x%08p\n", chiBuffer);
  WriteDebugLog(szBuffer);
}

#endif