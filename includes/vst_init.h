#ifndef _VST_INIT_H
#define _VST_INIT_H

// Global Variables

// Diagnostics
BOOL DEBUG = FALSE;

// Process
u32 processID;
u32 processVersion;
u64 processBaseAddress;
u64 PSX_TO_EMU;

char szModuleName[MAX_PATH];
char szExeName[MAX_PATH];

// In-game data

// Time
playtime PlayTimeCurrent = { -1 };
playtime PlayTimeTemp = { -1 };
playtime PlayTimeRecord = { -1 };

// Equipment
item_info BladeInfo;
item_info BladeInfoTemp;

item_info GripInfo;
item_info GripInfoTemp;

item_info Gem1Info;
item_info Gem1InfoTemp;

item_info Gem2Info;
item_info Gem2InfoTemp;

item_info Gem3Info;
item_info Gem3InfoTemp;

item_info ShieldInfo;
item_info ShieldInfoTemp;

item_info GloveLeftInfo;
item_info GloveLeftInfoTemp;

item_info GloveRightInfo;
item_info GloveRightInfoTemp;

item_info HeadInfo;
item_info HeadInfoTemp;

item_info BodyInfo;
item_info BodyInfoTemp;

item_info LegsInfo;
item_info LegsInfoTemp;

item_info NeckInfo;
item_info NeckInfoTemp;

// Player Data
player_stats PlayerStats;
player_stats PlayerStatsTemp;

status_effects PlayerEffects;
status_effects PlayerEffectsTemp;

// Location
location Location;
char szAreaName[MAX_PATH];
char szRoomName[MAX_PATH];

// Misc
u16 LastBossHP = 0xff;
BOOL GameOver = FALSE; // set to TRUE when the last boss is dead
char GlobalWeaponName[18] = "";

#endif
