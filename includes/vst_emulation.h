#ifndef _VST_EMULATION_H
#define _VST_EMULATION_H

// GameStatus flag:
// 1=Normal,
// 2=TargetSphere
// 3=CutScene
// 4=?
// 5=MenuScreen
// 6=QuickMenu
// 7=FirstPersonView
// 8=TrapPanel/HealPanel
// 9=TreasureChest/Container
// A=DrawingWeapon
// B=OperateLockedDoor
// C=?

#define OFFSET_GAME_STATUS 0xf196c

#define GAME_STATUS_NORMAL 0x0001
#define GAME_STATUS_BATTLE 0x0002
#define GAME_STATUS_CUTSCENE 0x0003
#define GAME_STATUS_MENU_SCREEN 0x0005
#define GAME_STATUS_QUICK_MENU 0x0006
#define GAME_STATUS_FP_VIEW 0x0007
#define GAME_STATUS_ACTIVATE_PANEL 0x0008
#define GAME_STATUS_OPEN_CONTAINER 0x0009
#define GAME_STATUS_DRAW_WEAPON 0x000a
#define GAME_STATUS_USE_OPEN_DOOR 0x000b
#define GAME_STATUS_END_OF_TURN 0x000c

wchar_t *GameStatusNameList[18] = {
    L"???",
    L"Normal", // 1
    L"Battle", // 2
    L"Cut-scene", // 3
    L"???", // 4
    L"Menu Screen", // 5
    L"Quick Menu", // 6
    L"First Person View", // 7
    L"Activate Panel", // 8
    L"Open Container", // 9
    L"Draw Weapon", // 10
    L"Use Locked Door", // 11
    L"End of Turn", // 12
    L"???", // 13
    L"???", // 14
    L"???", // 15
    L"???", // 16
    L"???" // 17
};

void
ReadGameStatus(u16 *GameStatus) {
  usize BytesToRead = sizeof(u16);

  ReadGameMemory(processID, OFFSET_GAME_STATUS, BytesToRead, GameStatus);
}

void
PrintGameStatus(u16 *GameStatus) {
    //if (*GameStatus == 0) return;

    swprintf_s(szBuffer, _countof(szBuffer), L"\nGAME STATUS:\n");
    WriteToBackBuffer();

    swprintf_s(szBuffer, _countof(szBuffer), L"#%d -- %s\n", *GameStatus,
            GameStatusNameList[*GameStatus]);
    WriteToBackBuffer();
}

#endif

