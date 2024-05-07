#ifndef _VST_DEBUG_H
#define _VST_DEBUG_H

void
WriteDebugInfo(void) {
    wchar_t szBuffer[1024];

    swprintf_s(szBuffer, _countof(szBuffer), L"processBaseAddress: 0x%016llx\n",
            processBaseAddress);
    WriteDebugLog(szBuffer);

    // Maximum window dimensions
    swprintf_s(szBuffer, _countof(szBuffer), L"conMaxSizeX: %i, conMaxSizeY: %i\n",
            conMaxSizeX, conMaxSizeY);
    WriteDebugLog(szBuffer);

    // Pointer to the back-buffer memory
    swprintf_s(
            szBuffer, _countof(szBuffer), L"chiBuffer address: 0x%08p\n", chiBuffer);
    WriteDebugLog(szBuffer);

    // Emulator memory base offset
    swprintf_s(
       szBuffer, _countof(szBuffer), L"EmuBase address: 0x%08p\n", (void *)emuBaseAddress);
    WriteDebugLog(szBuffer);
}

#endif

