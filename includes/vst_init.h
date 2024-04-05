#ifndef _VST_INIT_H
#define _VST_INIT_H

// Global Variables

// Process
u32 processID;
u32 processVersion;
u64 processBaseAddress;
u64 emuBaseAddress;
u8 emuBaseMaxAttempts;

// 16-bytes hex: 0x03000000800c5a270800400300000000
const u8 EMU_BASE_MAGIC_STRING[] = "\x03\x00\x00\x00\x80\x0c\x5a\x27\x08\x00\x40\x03\x00\x00\x00\x00";

wchar_t szModuleName[MAX_PATH];
wchar_t szExeName[MAX_PATH];

// In-game data
u16 GameStatus;

// Time
game_time GameTimeCur = { -1 };
game_time GameTimePrev = { -1 };
game_time GameTimeRecord = { -1 };

// Equipment
#define WEAPON_NAME_HEX_LENGTH 24
#define WEAPON_NAME_UNICODE_LENGTH 50

wchar_t NameBuffer[MAX_PATH];

wchar_t nameWeaponCur[WEAPON_NAME_UNICODE_LENGTH];
wchar_t nameWeaponPrev[WEAPON_NAME_UNICODE_LENGTH];

usize WeaponNumber = 0;

item_data itemBladeCur;
item_data itemBladePrev;

item_data itemGripCur;
item_data itemGripPrev;

item_data itemGem1WeaponCur;
item_data itemGem1WeaponPrev;

item_data itemGem2WeaponCur;
item_data itemGem2WeaponPrev;

item_data itemGem3WeaponCur;
item_data itemGem3WeaponPrev;

item_data itemGem1ShieldCur;
item_data itemGem1ShieldPrev;

item_data itemGem2ShieldCur;
item_data itemGem2ShieldPrev;

item_data itemGem3ShieldCur;
item_data itemGem3ShieldPrev;

item_data itemShieldCur;
item_data itemShieldPrev;

item_data itemGloveLeftCur;
item_data itemGloveLeftPrev;

item_data itemGloveRightCur;
item_data itemGloveRightPrev;

item_data itemHeadCur;
item_data itemHeadPrev;

item_data itemBodyCur;
item_data itemBodyPrev;

item_data itemLegsCur;
item_data itemLegsPrev;

item_data itemNeckCur;
item_data itemNeckPrev;

leveling_flags LevelingFlags;

// Player Data
player_stats statsPlayerCur;
player_stats statsPlayerPrev;

status_effects effectsPlayerCur;
status_effects effectsPlayerPrev;

// Location
location LocationCur;
location LocationPrev;

#define LOCATION_MAX_NAME_LENGTH 64 
wchar_t nameZone[LOCATION_MAX_NAME_LENGTH];
wchar_t nameMap[LOCATION_MAX_NAME_LENGTH];

// Gazette
map_flag_mem MapFlagMemCur;
map_flag_mem MapFlagMemPrev;

map_flag_mem MapCheckFlagMem;

chest_flag_mem ChestFlagMemCur;
chest_flag_mem ChestFlagMemPrev;

u8 ChestCount;
u16 MapCount;

kill_list KillListCur;
kill_list KillListPrev;

weapon_usage WeaponUsageCur;
weapon_usage WeaponUsagePrev;

// Misc
u16 LastBossHP = 0xff;
BOOL ProgramStarted = TRUE;
BOOL ProgramRunning = TRUE;

BOOL GameOver = FALSE; // set to TRUE when the last boss is dead

// Input
u16 ControllerInputCur;
u16 ControllerInputPrev;

buttons_timers ButtonsTimers;

// Actors in the room
#define ACTOR_NAME_HEX_LENGTH 24
#define ACTOR_NAME_UNICODE_LENGTH 50
wchar_t ActorName[ACTOR_NAME_UNICODE_LENGTH];

#endif
