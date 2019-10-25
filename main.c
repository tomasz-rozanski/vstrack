#include <windows.h>
#include <psapi.h>
#include <stdio.h>
#include <tchar.h>
#include <tlhelp32.h>

#define NELEMS(x) (sizeof(x) / sizeof(x[0]))

UINT16 LastBossHP = 0xff;
BOOL GameOver = FALSE; // set to TRUE when the last boss is dead
char GlobalWeaponName[18] = "";
DWORD processID;
DWORD processVersion;
BOOL DEBUG;

#include "includes/vst_console.h"
#include "includes/vst_process.h"
#include "includes/vst_emulation.h"
#include "includes/vst_equipment.h"
#include "includes/vst_translate.h"
#include "includes/vst_time.h"
#include "includes/vst_player.h"
#include "includes/vst_location.h"

// Main
int
wmain(int argc, wchar_t *argv[])
{
  WCHAR ver_s[3];
  UINT8 ver_d = 0;

  do // repeat until the user enters the right option
  {
    switch (argc)
    {
      case 1:
      {
        system("cls");
        printf("1. ePSXe 1.9.00\n");
        printf("2. ePSXe 1.9.25\n");
        printf("3. ePSXe 2.0.50\n");
        printf("0. Exit\n");

        wscanf_s(L"%2s", ver_s, (unsigned) _countof(ver_s));

        break;
      }
      case 2:
      {
        wsprintfW(ver_s, argv[1]);
        break;
      }
    }
    ver_d = _wtoi(ver_s);

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
        wsprintf(szModuleName, TEXT("%s"), TEXT("ePSXe.exe"));
        break;
      }
      case 2:
      {
        PSX_TO_EMU = PSX_TO_EPSXE_1925;
        wsprintf(szModuleName, TEXT("%s"), TEXT("ePSXe.exe"));
        break;
      }
      case 3:
      {
        PSX_TO_EMU = PSX_TO_EPSXE_2050;
        wsprintf(szModuleName, TEXT("%s"), TEXT("ePSXe.exe"));
        break;
      }
      default:
      {
        fprintf(stderr, "Wrong argument\n");
        Sleep(1000);
      }
    }
  } while (!PSX_TO_EMU);

  while (!(GetProcessIdFromName(&processID, szModuleName)))
  {

    system("cls");
    fprintf(stderr, "Error: Couldn't obtain process ID number.\n");
    fprintf(stderr, "Check if the emulator is running.\n");

    Sleep(1000);
  };

  // Display this info when DEBUG is ON.
  // Create separate function for this.

  // moduleDllBase = GetModuleDllBase(processID, szModuleName);
  // fprintf(stdout, "moduleDllBase: 0x%08x\n", moduleDllBase);

  // PrintProcessInfo(processID);
  // PrintProcessNameAndID(processID);
  // PrintProcessVersion(processID);

  // PrintModuleFileName(processID);

  mkdir("game_stats");

  SetConsoleHandles();
  cls(hStdout);

  GetConsoleWindowSize(hStdout, &conSizeX, &conSizeY);

  do
  {
    cls(hBackBuffer);

    SetCursorPosition(hStdout, 0, 0);
    SetCursorPosition(hBackBuffer, 0, 0);

    sprintf(szBuffer, "============================\n"
                      "== VSTracker v0.1.1-alpha ==\n"
                      "============================\n");
    WriteToBackBuffer();

    ReadPlayTime(&PlayTimeCurrent);
    PrintPlayTimeShort2(&PlayTimeCurrent);
    WritePlayTimeToFile(&PlayTimeCurrent, _T("game_stats//play-time.txt"));

    // Check player's location
    ReadLocation(&Location);
    GetAreaAndRoomName(&Location, szAreaName, szRoomName);
    PrintLocation2(&Location, szAreaName, szRoomName);
    WriteLocationIntoFile(&Location, szAreaName, szRoomName);

    // Write player stats into the file
    WritePlayerStats();
    PrintPlayerStats2();

    GetWeaponName(processID, GlobalWeaponName);

    // Write equipment stats into files
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

    // Handle last boss
    if (IsThisTheLastBossRoom(&Location))
    {
      LastBossHandleIt2();
    }

    // SHORT keyState = GetAsyncKeyState(0x44); // 'D' for Debug Mode

    // if (keyState & 0x8000) // 0x8000 is 'D' key code
    // {
    //   DEBUG = !DEBUG;
    //   FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
    // }

    CopyFromBackBuffer();
    Sleep(100);
  } while (!GameOver);

  cls(hStdout);

  PrintRecordTime(&RecordTime);

  printf("\nPress any key to exit the program...\n");
  getchar();

  return 0;
}
