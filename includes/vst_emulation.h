#ifndef _VST_EMULATION_H
#define _VST_EMULATION_H

// The formula:
// PSX_TO_EMU = PSX_OFFSET - EMU_OFFSET + EMU_BASE_ADDRESS
// EMU_OFFSET = PSX_OFFSET + EMU_BASE_ADDRESS - PSX_TO_EMU
// PSX_OFFSET = PSX_TO_EMU + EMU_OFFSET - EMU_BASE_ADDRESS

#define PSX_TO_EPSXE_1925 0x7f974960
#define PSX_TO_EPSXE_2050 0x7f57dfe0

#define PSX_TO_BIZHAWK_2320 0x7fee2780
#define PSX_TO_BIZHAWK_2410 0x7fcf2070
#define PSX_TO_BIZHAWK_2420 0x7fcf2070
#define PSX_TO_BIZHAWK_2520 0x7fcef080
#define PSX_TO_BIZHAWK_2610 0x7fcef080

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

#define OFFSET_GAME_STATUS 0x800f196c

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

char *GameStatusNameList[17] = {
  "Normal", // 1
  "Battle", // 2
  "Cut-scene", // 3
  "???", // 4
  "Menu Screen", // 5
  "Quick Menu", // 6
  "First Person View", // 7
  "Activate Panel", // 8
  "Open Container", // 9
  "Draw Weapon", // 10
  "Use Locked Door", // 11
  "End of Turn", // 12
  "???", // 13
  "???", // 14
  "???", // 15
  "???", // 16
  "???" // 17
};

void
ReadGameStatus(u16 *GameStatus)
{

  usize BytesToRead = sizeof(u16);

  ReadGameMemory(processID, OFFSET_GAME_STATUS, BytesToRead, GameStatus);
}

void
PrintGameStatus(u16 *GameStatus)
{
  sprintf(szBuffer, "\nGAME STATUS:\n");
  WriteToBackBuffer();

  sprintf(szBuffer, "#%d -- %s\n", *GameStatus,
      GameStatusNameList[*GameStatus - 1]);
  WriteToBackBuffer();
}

#endif
