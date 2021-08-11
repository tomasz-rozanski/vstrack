#include <windows.h>
#include <psapi.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <tchar.h>
#include <tlhelp32.h>

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

// Main
int main(int argc, char *argv[]) {
    char ver_s[3];
    u8 ver_d = 0;

    do // repeat until the user enters a valid option
    {
        switch (argc) {
            case 1: {
                system("cls");

                fprintf(stdout, "1. ePSXe\n");
                fprintf(stdout, "2. BizHawk\n");
                fprintf(stdout, "3. DuckStation (SDL)\n");
                fprintf(stdout, "4. DuckStation (QT)\n");
                fprintf(stdout, "5. pSX\n");
                fprintf(stdout, "6. no$psx\n\n");

                fprintf(stdout, "0. Exit\n\n");

                fprintf(stdout, ">>> ");

                scanf_s("%2s", ver_s, (unsigned) _countof(ver_s));

                break;
            }
            case 2: {
                sprintf_s(ver_s, _countof(ver_s), argv[1]);
                break;
            }
        }
        ver_d = atoi(ver_s);

        switch (ver_d) {
            case 0: {
                exit(1);
                break;
            }
            case 1: {
                emuBaseMaxAttempts = 1;
                sprintf_s(szExeName, MAX_PATH, "ePSXe.exe");
                sprintf_s(szModuleName, MAX_PATH, "");
                break;
            }
            case 2: {
                emuBaseMaxAttempts = 1;
                sprintf_s(szExeName, MAX_PATH, "EmuHawk.exe");
                sprintf_s(szModuleName, MAX_PATH, "octoshock.dll");
                break;
            }
            case 3: {
                emuBaseMaxAttempts = 1;
                sprintf_s(szExeName, MAX_PATH, "duckstation-sdl-x64-ReleaseLTCG.exe");
                sprintf_s(szModuleName, MAX_PATH, "");

                break;
            }
            case 4: {
                emuBaseMaxAttempts = 1;
                sprintf_s(szExeName, MAX_PATH, "duckstation-qt-x64-ReleaseLTCG.exe");
                sprintf_s(szModuleName, MAX_PATH, "");

                break;
            }
            case 5: {
                emuBaseMaxAttempts = 1;
                sprintf_s(szExeName, MAX_PATH, "psxfin.exe");
                sprintf_s(szModuleName, MAX_PATH, "");

                break;
            }
            case 6: {
                emuBaseMaxAttempts = 1;
                sprintf_s(szExeName, MAX_PATH, "NO$PSX.EXE");
                sprintf_s(szModuleName, MAX_PATH, "");

                break;
            }
            default: {
                fprintf(stderr, "Wrong argument\n");
                Sleep(1000);
            }
        }

        emuBaseAddress = GetEmuBaseAddress(szExeName, emuBaseMaxAttempts);

    } while (!emuBaseAddress);

    /*
    while (!(GetProcessIdFromName(&processID, szExeName)))
    {

      system("cls");
      fprintf(stderr, "Error: Couldn't obtain process ID number.\n");
      fprintf(stderr, "Check if the emulator is running.\n");
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
    // fprintf(stdout, "processID: %i\n", processID);
    // fprintf(stdout, "processBaseAddress: 0x%llx\n", processBaseAddress);

    // processBaseAddress = GetModuleDllBase(processID, "octoshock.dll");
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

        // WriteBladeInfo(processID);
        // ReadPlayerStats(&statsPlayerCur);

        if (1)
        // if (CheckPlayerStats(&statsPlayerCur))
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
            strncpy(nameWeaponPrev, nameWeaponCur, WEAPON_NAME_LENGTH);

#ifdef DEBUG
            sprintf_s(szBuffer, _countof(szBuffer), "WEAPON NUMBER: %zi\n", WeaponNumber);
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
            sprintf_s(szBuffer, _countof(szBuffer),
                "============================\n"
                "== VSTracker v0.5.0-alpha ==\n"
                "============================\n");
            WriteToBackBuffer();

            sprintf_s(szBuffer, _countof(szBuffer), "\nWaiting for the game to load ...\n");
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

    fprintf(stdout, "\nPress any key to exit the program...\n");
    getchar();

    return 0;
}
