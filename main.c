#ifndef UNICODE
#define UNICODE
#endif

#ifndef _UNICODE
#define _UNICODE
#endif

#include <windows.h>
#include <psapi.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <tchar.h>
#include <tlhelp32.h>
#include <locale.h>

#include "includes/vst_types.h"
#include "includes/vst_init.h"
#include "includes/vst_utils.h"
#include "includes/vst_console.h"
#include "includes/vst_process.h"
#include "includes/vst_emulation.h"
#include "includes/vst_translate.h"
#include "includes/vst_equipment.h"
#include "includes/vst_time.h"
#include "includes/vst_player.h"
#include "includes/vst_input.h"
#include "includes/vst_actors.h"
#include "includes/vst_location.h"
#include "includes/vst_gazette.h"
#include "includes/vst_debug.h"

int wmain(int argc, wchar_t *argv[]) {
    _wsetlocale(LC_ALL, L".UTF8");

    wchar_t ver_s[3];
    u8 ver_d = 0;

    do { // repeat until the user enters a valid option
        switch (argc) {
            case 1: {
                        system("cls");

                        fwprintf(stdout, L"1. ePSXe\n");
                        fwprintf(stdout, L"2. BizHawk\n");
                        fwprintf(stdout, L"3. DuckStation\n");
                        fwprintf(stdout, L"4. pSX\n");
                        fwprintf(stdout, L"5. no$psx\n\n");

                        fwprintf(stdout, L"0. Exit\n\n");

                        fwprintf(stdout, L">>> ");

                        wscanf_s(L"%2s", ver_s, (unsigned) _countof(ver_s));

                        break;
                    }
            case 2: {
                        swprintf_s(ver_s, _countof(ver_s), argv[1]);
                        break;
                    }
        }
        ver_d = _wtoi(ver_s);

        switch (ver_d) {
            case 0: {
                        exit(1);
                        break;
                    }
            case 1: {
                        emuBaseMaxAttempts = 1;
                        swprintf_s(szExeName, MAX_PATH, L"ePSXe.exe");
                        swprintf_s(szModuleName, MAX_PATH, L"");
                        break;
                    }
            case 2: {
                        emuBaseMaxAttempts = 1;
                        swprintf_s(szExeName, MAX_PATH, L"EmuHawk.exe");
                        swprintf_s(szModuleName, MAX_PATH, L"octoshock.dll");
                        break;
                    }
            case 3: {
                        emuBaseMaxAttempts = 1;
                        swprintf_s(szExeName, MAX_PATH, L"duckstation-qt-x64-ReleaseLTCG.exe");
                        swprintf_s(szModuleName, MAX_PATH, L"");
                        break;
                    }
            case 4: {
                        emuBaseMaxAttempts = 1;
                        swprintf_s(szExeName, MAX_PATH, L"psxfin.exe");
                        swprintf_s(szModuleName, MAX_PATH, L"");
                        break;
                    }
            case 5: {
                        emuBaseMaxAttempts = 1;
                        swprintf_s(szExeName, MAX_PATH, L"NO$PSX.EXE");
                        swprintf_s(szModuleName, MAX_PATH, L"");
                        break;
                    }
            default: {
                         fwprintf(stderr, L"Wrong argument\n");
                         Sleep(1000);
                     }
        }

        emuBaseAddress = GetEmuBaseAddress(szExeName, emuBaseMaxAttempts);

    } while (!emuBaseAddress);

    /*
       while (!(GetProcessIdFromName(&processID, szExeName)))
       {

       system("cls");
       fwprintf(stderr, L"Error: Couldn't obtain process ID number.\n");
       fwprintf(stderr, L"Check if the emulator is running.\n");
       Sleep(1000);
       };
       system("cls");

       if (!strlen(szModuleName))
       {
       processBaseAddress = GetModuleDllBase(processID, szExeName);
       }
       else
       {
       processBaseAddress = FindDllAddress(processID, szModuleName);
       }
       */

    // Setup the folders
    mkdir("debug");
    mkdir("debug/map");
    mkdir("game_data");
    mkdir("game_data/time");
    mkdir("game_data/time/records");
    mkdir("game_data/map");
    mkdir("game_data/weapon");
    mkdir("game_data/armor");
    mkdir("game_data/player");
    mkdir("game_data/score");

    // PrintProcessInfo(processID);
    // PrintProcessNameAndID(processID);
    // PrintProcessVersion(processID);
    // PrintModuleFileName(processID);
    // EnumProcessModules2(processID);
    // fwprintf(stdout, L"processID: %i\n", processID);
    // fwprintf(stdout, L"processBaseAddress: 0x%llx\n", processBaseAddress);

    // processBaseAddress = GetModuleDllBase(processID, L"octoshock.dll");
    // ListProcessThreads(processID);
    // ListProcessModules(processID);

    // getc(stdin);

    SetConsoleHandles();
    cls(hStdout);

    GetConsoleWindowSize(hStdout, &conSizeX, &conSizeY, &conMaxSizeX, &conMaxSizeY);

    chiBuffer = AllocateBackBuffer();

    WriteDebugInfo();
    WriteDebugMessage(hStdout);

    do {
        GetConsoleWindowSize(hStdout, &conSizeX, &conSizeY, &conMaxSizeX, &conMaxSizeY);

        chiBuffer = AllocateBackBuffer();

        cls(hBackBuffer);

        SetCursorPosition(hStdout, 0, 0);
        SetCursorPosition(hBackBuffer, 0, 0);


        ReadPlayerStats(&statsPlayerCur);

        if (CheckPlayerStats(&statsPlayerCur))
        {
            // TIME
            GameTimePrev = GameTimeCur;
            ReadGameTime(&GameTimeCur);

            // GAME STATUS
            ReadGameStatus(&GameStatus);
#ifdef DEBUG
            PrintGameStatus(&GameStatus);
#endif
            // Check if the time progressed
            if (GameTimeChanged(&GameTimePrev, &GameTimeCur)) {
                WriteGameTimeToFile(&GameTimeCur);
            }
            PrintGameTimeShort(&GameTimeCur);

            if (ProgramStarted) {
                ReadLocation();
                ReadZoneAndMapName(&LocationCur, nameZone, nameMap);
                WriteLocation();

                ReadMapFlags(&MapFlagMemCur); // Initialize Map Flags
                ReadMapCheckFlags(&MapCheckFlagMem); // Initialize Map Check Flags
                ReadChestFlags(&ChestFlagMemCur); // Initialize Chest Flags

#ifdef DEBUG
                GenerateMapCheckFlagList();
#endif
                ReadBladeData();
                ReadWeaponData();
                ReadShieldData();
                ReadArmorData();

                ReadWeaponName();

                WriteBladeData();
                WriteWeaponData();
                WriteShieldData();
                WriteArmorData();

                ReadWeaponNumber();
                WriteBladeLeveling(WeaponNumber);

                CalculateChestCount(&ChestCount, &ChestFlagMemCur);
                CalculateMapCount(&MapCount);

                WriteMapCount(&MapCount);
                WriteChestCount(&ChestCount);

                WriteMissingChestList(&ChestFlagMemCur, ChestFlagChecklist);
                WriteMissingMapList(&MapFlagMemCur, MapFlagChecklist);

                ReadKillList();
                WriteKillList();

                ReadWeaponUsage();
                WriteWeaponUsage();

                ProgramStarted = FALSE;
            }

            // Some debug

            // LOCATION
            LocationPrev = LocationCur;
            ReadLocation();
            ReadZoneAndMapName(&LocationCur, nameZone, nameMap);
            if (LocationChanged()) {
                WriteLocation();
            }
#ifdef DEBUG
            // PrintLocation();
            PrintActorsData();
#endif
            // ACTORS IN THE ROOM
            WriteActorsData();

            // STATS
            statsPlayerPrev = statsPlayerCur;
            ReadPlayerStats(&statsPlayerCur);
            if (PlayerStatsChanged()) {
                WritePlayerStats(&statsPlayerCur);
            }
#ifdef DEBUG
            // PrintPlayerStats(&statsPlayerCur);
#endif

            effectsPlayerPrev = effectsPlayerCur;
            ReadPlayerEffects(&effectsPlayerCur);
            if (PlayerEffectsChanged()) {
                WritePlayerEffects(&effectsPlayerCur);
            }

#ifdef DEBUG
            PrintPlayerEffects(&effectsPlayerCur);
#endif
            ReadButtonsTimers(&ButtonsTimers);
            ControllerInputPrev = ControllerInputCur;
            ReadControllerInput(&ControllerInputCur);
            // if (ControllerInputChanged())
            // {
            // WriteControllerInput(&ControllerInputCur);
            // }
#ifdef DEBUG
            PrintControllerInput(&ControllerInputCur);
#endif
            // GAZETTE
            KillListPrev = KillListCur;
            ReadKillList();
            if (KillListChanged()) {
                WriteKillList();
            }

            WeaponUsagePrev = WeaponUsageCur;
            ReadWeaponUsage();
            if (WeaponUsageChanged()) {
                WriteWeaponUsage();
            }

            // Opened Trausure Chests
            ChestFlagMemPrev = ChestFlagMemCur;
            ReadChestFlags(&ChestFlagMemCur);
            CalculateChestCount(&ChestCount, &ChestFlagMemCur);
            if (ChestFlagsChanged()) {
#ifdef DEBUG
                WriteChestFlagsDiffs();
#endif
                WriteChestCount(&ChestCount);
                WriteMissingChestList(&ChestFlagMemCur, ChestFlagChecklist);
            }
#ifdef DEBUG
            PrintChestCount(&ChestCount);
#endif
            // Visited Maps
            MapFlagMemPrev = MapFlagMemCur;
            ReadMapFlags(&MapFlagMemCur);

            CalculateMapCount(&MapCount);
            if (MapFlagsChanged()) {
#ifdef DEBUG
                WriteMapFlagsDiffs();
#endif
                WriteMapCount(&MapCount);
                WriteMissingMapList(&MapFlagMemCur, MapFlagChecklist);
            }
#ifdef DEBUG
            PrintMapCount(&MapCount);
#endif
            // EQUIPMENT
#ifdef DEBUG
            PrintBladeLeveling(WeaponNumber);
#endif
            // Check if weapon leveling name changed
            wcsncpy(nameWeaponPrev, nameWeaponCur, WEAPON_NAME_UNICODE_LENGTH);

#ifdef DEBUG
            swprintf_s(szBuffer, _countof(szBuffer), L"WEAPON NUMBER: %zi\n", WeaponNumber);
            WriteToBackBuffer();
#endif

            // Weapon
            itemBladePrev = itemBladeCur;
            ReadBladeData();
            if (BladeDataChanged()) {
                WriteBladeData();
                WriteWeaponData();

                UpdateLevelingFlags();
                ReadWeaponUsage();

                ReadWeaponNumber();
                WriteBladeLeveling(WeaponNumber);
            }

            ReadWeaponName();
            if (WeaponNameChanged()) {
                ClearLevelingFlags();

                ReadWeaponNumber();

                WriteBladeLeveling(WeaponNumber);
            }

            itemGripPrev = itemGripCur;
            itemGem1WeaponPrev = itemGem1WeaponCur;
            itemGem2WeaponPrev = itemGem2WeaponCur;
            itemGem3WeaponPrev = itemGem3WeaponCur;
            ReadWeaponData();
            if (WeaponDataChanged()) {
                WriteWeaponData();
            }

            // Shield
            itemShieldPrev = itemShieldCur;
            itemGem1ShieldPrev = itemGem1ShieldCur;
            itemGem2ShieldPrev = itemGem2ShieldCur;
            itemGem3ShieldPrev = itemGem3ShieldCur;

            ReadShieldData();
            if (ShieldDataChanged()) {
                WriteShieldData();
            }

            // Armor
            itemGloveLeftPrev = itemGloveLeftCur;
            itemGloveRightPrev = itemGloveRightCur;
            itemHeadPrev = itemHeadCur;
            itemBodyPrev = itemBodyCur;
            itemLegsPrev = itemLegsCur;
            itemNeckPrev = itemNeckCur;
            ReadArmorData();
            if (ArmorDataChanged()) {
                WriteArmorData();
            }

#ifdef DEBUG
            PrintWeaponName();
#endif
        } else {
            swprintf_s(szBuffer, _countof(szBuffer),
                    L"============================\n"
                    L"== VSTracker v0.6.0-alpha ==\n"
                    L"============================\n");
            WriteToBackBuffer();

            swprintf_s(szBuffer, _countof(szBuffer), L"\nWaiting for the game to load ...\n");
            WriteToBackBuffer();
        }

        // Handle last boss
        if (IsThisTheLastBossMap() && !GameOver) {
            LastBossHandleIt();
        }

        SetCursorPosition(hStdout, 0, 0);
        SetCursorPosition(hBackBuffer, 0, 0);

        CopyFromBackBuffer();
        // ScrollBuffer(hBackBuffer);

        Sleep(10);
    } while (ProgramRunning);

    cls(hStdout);

    PrintGameTimeRecord(&GameTimeRecord);

    fwprintf(stdout, L"\nPress any key to exit the program...\n");
    getchar();

    return 0;
}

