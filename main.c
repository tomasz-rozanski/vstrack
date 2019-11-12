#include <windows.h>
#include <psapi.h>
#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <tlhelp32.h>

#include "includes/vst_types.h"
#include "includes/vst_init.h"
#include "includes/vst_utils.h"
#include "includes/vst_console.h"
#include "includes/vst_process.h"
#include "includes/vst_emulation.h"
#include "includes/vst_equipment.h"
#include "includes/vst_translate.h"
#include "includes/vst_time.h"
#include "includes/vst_player.h"
#include "includes/vst_location.h"
#include "includes/vst_debug.h"

// Main
int
main(int argc, char *argv[])
{
  char ver_s[3];
  u8 ver_d = 0;

  do // repeat until the user enters a valid option
  {
    switch (argc)
    {
      case 1:
      {
        system("cls");

        fprintf(stdout, "1. ePSXe 1.9.00\n");
        fprintf(stdout, "2. ePSXe 1.9.25\n");
        fprintf(stdout, "3. ePSXe 2.0.50\n");
        fprintf(stdout, "4. BizHawk 2.3.0\n");
        fprintf(stdout, "4. BizHawk 2.3.2\n\n");
        fprintf(stdout, "0. Exit\n\n");

        scanf_s("%2s", ver_s, (unsigned) _countof(ver_s));

        break;
      }
      case 2:
      {
        sprintf_s(ver_s, _countof(ver_s), argv[1]);
        break;
      }
    }
    ver_d = atoi(ver_s);

    switch (ver_d)
    {
      case 0:
      {
        exit(1);
        break;
      }
      case 1:
      {
        PSX_TO_EMU = PSX_TO_EPSXE_1900;
        sprintf_s(szExeName, MAX_PATH, "ePSXe.exe");
        sprintf_s(szModuleName, MAX_PATH, "");
        break;
      }
      case 2:
      {
        PSX_TO_EMU = PSX_TO_EPSXE_1925;
        sprintf_s(szExeName, MAX_PATH, "ePSXe.exe");
        sprintf_s(szModuleName, MAX_PATH, "");
        break;
      }
      case 3:
      {
        PSX_TO_EMU = PSX_TO_EPSXE_2050;
        sprintf_s(szExeName, MAX_PATH, "ePSXe.exe");
        sprintf_s(szModuleName, MAX_PATH, "");
        break;
      }
      case 4:
      {
        PSX_TO_EMU = PSX_TO_BIZHAWK_2300;
        sprintf_s(szModuleName, MAX_PATH, "octoshock.dll");
        sprintf_s(szExeName, MAX_PATH, "EmuHawk.exe");
        break;
      }
      case 5:
      {
        PSX_TO_EMU = PSX_TO_BIZHAWK_2320;
        sprintf_s(szModuleName, MAX_PATH, "octoshock.dll");
        sprintf_s(szExeName, MAX_PATH, "EmuHawk.exe");
        break;
      }
      default:
      {
        fprintf(stderr, "Wrong argument\n");
        Sleep(1000);
      }
    }
  } while (!PSX_TO_EMU);

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

  // Setup the folders
  mkdir("debug");
  mkdir("game_stats");
  mkdir("game_stats/records");

  // PrintProcessInfo(processID);
  // PrintProcessNameAndID(processID);
  // PrintProcessVersion(processID);
  // PrintModuleFileName(processID);
  // EnumProcessModules2(processID);
  fprintf(stdout, "processID: %i\n", processID);
  fprintf(stdout, "processBaseAddress: 0x%llx\n", processBaseAddress);

  // processBaseAddress = GetModuleDllBase(processID, "octoshock.dll");
  // ListProcessThreads(processID);
  ListProcessModules(processID);

  // getc(stdin);

  SetConsoleHandles();
  cls(hStdout);

  GetConsoleWindowSize(
      hStdout, &conSizeX, &conSizeY, &conMaxSizeX, &conMaxSizeY);

  chiBuffer = AllocateBackBuffer(conMaxSizeX, conMaxSizeY);

  WriteDebugInfo();

  do
  {
    GetConsoleWindowSize(
        hStdout, &conSizeX, &conSizeY, &conMaxSizeX, &conMaxSizeY);
    cls(hBackBuffer);

    SetCursorPosition(hStdout, 0, 0);
    SetCursorPosition(hBackBuffer, 0, 0);

    WriteBladeInfo(processID);
    ReadPlayerStats(&PlayerStats);

    if (CheckPlayerStats(&PlayerStats))
    {
      // TIME
      PlayTimeTemp = PlayTimeCurrent;
      ReadPlayTime(&PlayTimeCurrent);

      // Check if the time progressed
      if (IsItLater(&PlayTimeTemp, &PlayTimeCurrent))
      {
        WritePlayTimeToFile(&PlayTimeCurrent, "game_stats/play-time.txt");
      }
      PrintPlayTimeShort(&PlayTimeCurrent);

      // LOCATION
      ReadLocation(&Location);
      GetAreaAndRoomName(&Location, szAreaName, szRoomName);
      PrintLocation(&Location, szAreaName, szRoomName);
      WriteLocationIntoFile(&Location, szAreaName, szRoomName);

      // STATS
      ReadPlayerStats(&PlayerStats);
      ReadPlayerStatus(&PlayerEffects);
      PrintPlayerStats(&PlayerStats, &PlayerEffects);
      WritePlayerStats();

      GetWeaponName(processID, GlobalWeaponName);

      // EQUIPMENT
      WriteWeaponInfo(processID);

      WriteBladeInfo(processID);
      WriteBladeInfoShort(processID);

      WriteShieldInfo(processID);
      WriteShieldInfoShort(processID);

      WriteGloveInfo(processID, RIGHT_GLOVE);
      WriteGloveInfoShort(processID, RIGHT_GLOVE);

      WriteGloveInfo(processID, LEFT_GLOVE);
      WriteGloveInfoShort(processID, LEFT_GLOVE);

      WriteHeadArmorInfo(processID);
      WriteHeadArmorInfoShort(processID);

      WriteBodyArmorInfo(processID);
      WriteBodyArmorInfoShort(processID);

      WriteLegsArmorInfo(processID);
      WriteLegsArmorInfoShort(processID);

      WriteNecklaceInfo(processID);
    }
    else
    {

      sprintf_s(szBuffer, _countof(szBuffer),
          "============================\n"
          "== VSTracker v0.2.0-alpha ==\n"
          "============================\n");
      WriteToBackBuffer();

      sprintf_s(
          szBuffer, _countof(szBuffer), "\nWaiting for the game to load ...\n");
      WriteToBackBuffer();

      // sprintf_s(szBuffer, _countof(szBuffer), "\nprocessBaseAddress: 0x%p\n",
      //     (void *) processBaseAddress);
      // WriteToBackBuffer();
    }

    // Handle last boss
    if (IsThisTheLastBossRoom(&Location))
    {
      LastBossHandleIt2();
    }

    CopyFromBackBuffer();
    Sleep(10);
  } while (!GameOver);

  cls(hStdout);

  PrintRecordTime(&PlayTimeRecord);

  fprintf(stdout, "\nPress any key to exit the program...\n");
  getchar();

  return 0;
}
