#ifndef _VST_PLAYER_H
#define _VST_PLAYER_H

//
// Player data
//

// Offsets

// Misc
#define OFFSET_PLAYER_CURRENT_MODE 0x11fa10 // NormalMode=0, BattleMode=1
#define OFFSET_PLAYER_EQIPPED_WEAPON_CATEGORY_ID 0x11fa15
#define OFFSET_PLAYER_PTR_NAME 0x11fa2c // ptrName
#define OFFSET_PLAYER_PTR_00_SHP_HDR 0x11fa34 // ptr00ShpHdr
#define OFFSET_PLAYER_PTR_WEAPON_WEP_HDR 0x11fa38 // ptrWeaponWEPHdr
#define OFFSET_PLAYER_PTR_00_SHP_DATA 0x11fa3c // ptr00ShpData
#define OFFSET_PLAYER_CHARACTER_NAME \
    0x11fa40 // CharacterName $18str "Ashley Riot"

// Main stats
#define OFFSET_PLAYER_HP_CURRENT 0x11fa58 // CurrentHP
#define OFFSET_PLAYER_HP_MAX 0x11fa5a // MaxHP
#define OFFSET_PLAYER_MP_CURRENT 0x11fa5c // CurrentMP
#define OFFSET_PLAYER_MP_MAX 0x11fa5e // MaxMP
#define OFFSET_PLAYER_RISK 0x11fa60 // RISK
#define OFFSET_PLAYER_STR_EQUIPPED 0x11fa62 // EquippedSTR
#define OFFSET_PLAYER_STR_ORIGINAL 0x11fa64 // OriginalSTR
#define OFFSET_PLAYER_INT_EQUIPPED 0x11fa66 // EquippedINT
#define OFFSET_PLAYER_INT_ORIGINAL 0x11fa68 // OriginalINT
#define OFFSET_PLAYER_AGL_EQUIPPED 0x11fa6a // EquippedAGL
#define OFFSET_PLAYER_AGL_ORIGINAL 0x11fa6c // OriginalAGL
#define OFFSET_PLAYER_WALKING_SPEED_WITH_BOX \
    0x11fa71 // WalkingSpeedWhenCarryingBoxes
#define OFFSET_PLAYER_RUNNING_SPEED 0x11fa73 // RunningSpeed
#define OFFSET_PLAYER_RANGE 0x11fa78 // range

// Status Effects
#define OFFSET_PLAYER_STATUS_EFFECTS 0x120388

#define MASK_STATUS_EFFECT_DYING_HEAD 0x00000001
#define MASK_STATUS_EFFECT_DYING_RIGHT_ARM 0x00000002
#define MASK_STATUS_EFFECT_DYING_LEFT_ARM 0x00000004
#define MASK_STATUS_EFFECT_DYING_BODY 0x00000008
#define MASK_STATUS_EFFECT_DYING_LEGS 0x00000010
#define MASK_STATUS_EFFECT_STR_DOWN 0x00000020
#define MASK_STATUS_EFFECT_STR_UP 0x00000040
#define MASK_STATUS_EFFECT_INT_DOWN 0x00000080
#define MASK_STATUS_EFFECT_INT_UP 0x00000100
#define MASK_STATUS_EFFECT_AGI_DOWN 0x00000200
#define MASK_STATUS_EFFECT_AGI_UP 0x00000400
#define MASK_STATUS_EFFECT_QUICKEN 0x00000800
#define MASK_STATUS_EFFECT_SILENCE 0x00001000
#define MASK_STATUS_EFFECT_PARALYSIS 0x00002000
#define MASK_STATUS_EFFECT_POISON 0x00004000
#define MASK_STATUS_EFFECT_NUMBNESS 0x00008000
#define MASK_STATUS_EFFECT_CURSE 0x00010000
#define MASK_STATUS_EFFECT_REGEN 0x00020000
#define MASK_STATUS_EFFECT_MAGIC_WARD 0x00040000
#define MASK_STATUS_EFFECT_EQUIP_DOWN 0x00080000
#define MASK_STATUS_EFFECT_EQUIP_UP 0x00100000
#define MASK_STATUS_EFFECT_AIR_UP 0x00200000
#define MASK_STATUS_EFFECT_FIRE_UP 0x00400000
#define MASK_STATUS_EFFECT_EARTH_UP 0x00800000
#define MASK_STATUS_EFFECT_WATER_UP 0x01000000
#define MASK_STATUS_EFFECT_AIR_RESIST 0x02000000
#define MASK_STATUS_EFFECT_FIRE_RESIST 0x04000000
#define MASK_STATUS_EFFECT_EARTH_RESIST 0x08000000
#define MASK_STATUS_EFFECT_WATER_RESIST 0x10000000
#define MASK_STATUS_EFFECT_ANALYZE 0x20000000
#define MASK_STATUS_EFFECT_EXORCISM 0x40000000
#define MASK_STATUS_EFFECT_MAGIC_IMMMUNITY 0x80000000

// Last boss data
#define OFFSET_LAST_BOSS_HP_CUR 0x17cd08
#define OFFSET_LAST_BOSS_HP_MAX 0x17cd0a
#define OFFSET_LAST_BOSS_MP_CUR 0x17cd0c
#define OFFSET_LAST_BOSS_MP_MAX 0x17cd0e
#define OFFSET_LAST_BOSS_SHD_CUR 0x17d088
#define OFFSET_LAST_BOSS_SHD_MAX 0x17d08a

wchar_t *StatusEffectNames[32] = { //
    L"DYING Head (silent)", L"DYING Right Arm (damage 50%%)",
    L"DYING Left Arm (enemy hit%% x2)",
    L"DYING Body (RISK decay in Normal Mode as in Battle Mode)",
    L"DYING Legs (move 50%%)", L"STR-down", L"STR-up", L"INT-down", L"INT-up",
    L"AGI-down", L"AGI-up", L"Quicken", L"Silence", L"Paralysis", L"Poison", L"Numbness",
    L"Curse", L"Regen", L"Magic Ward ", L"Equip-down", L"Equip-up", L"+Air", L"+Fire",
    L"+Earth", L"+Water", L"Resist Air", L"Resist Fire", L"Resist Earth",
    L"Resist Water", L"Analyze", L"Exorcism/Banish/Drain mind", L"Magic Immmunity?"
};

u32 StatusEffectMasks[32] = { //
    MASK_STATUS_EFFECT_DYING_HEAD, MASK_STATUS_EFFECT_DYING_RIGHT_ARM,
    MASK_STATUS_EFFECT_DYING_LEFT_ARM, MASK_STATUS_EFFECT_DYING_BODY,
    MASK_STATUS_EFFECT_DYING_LEGS, MASK_STATUS_EFFECT_STR_DOWN,
    MASK_STATUS_EFFECT_STR_UP, MASK_STATUS_EFFECT_INT_DOWN,
    MASK_STATUS_EFFECT_INT_UP, MASK_STATUS_EFFECT_AGI_DOWN,
    MASK_STATUS_EFFECT_AGI_UP, MASK_STATUS_EFFECT_QUICKEN,
    MASK_STATUS_EFFECT_SILENCE, MASK_STATUS_EFFECT_PARALYSIS,
    MASK_STATUS_EFFECT_POISON, MASK_STATUS_EFFECT_NUMBNESS,
    MASK_STATUS_EFFECT_CURSE, MASK_STATUS_EFFECT_REGEN,
    MASK_STATUS_EFFECT_MAGIC_WARD, MASK_STATUS_EFFECT_EQUIP_DOWN,
    MASK_STATUS_EFFECT_EQUIP_UP, MASK_STATUS_EFFECT_AIR_UP,
    MASK_STATUS_EFFECT_FIRE_UP, MASK_STATUS_EFFECT_EARTH_UP,
    MASK_STATUS_EFFECT_WATER_UP, MASK_STATUS_EFFECT_AIR_RESIST,
    MASK_STATUS_EFFECT_FIRE_RESIST, MASK_STATUS_EFFECT_EARTH_RESIST,
    MASK_STATUS_EFFECT_WATER_RESIST, MASK_STATUS_EFFECT_ANALYZE,
    MASK_STATUS_EFFECT_EXORCISM, MASK_STATUS_EFFECT_MAGIC_IMMMUNITY
};

void
ReadPlayerStats(player_stats *PlayerStats) {
    //  usize Offset =
    //    (usize)(OFFSET_PLAYER_HP_CURRENT - PSX_TO_EMU + processBaseAddress);

    usize BytesToRead = sizeof(player_stats);

    ReadGameMemory(processID, OFFSET_PLAYER_HP_CURRENT, BytesToRead, PlayerStats);
}

void
ReadPlayerEffects(status_effects *PlayerEffects) {

    usize BytesToRead = sizeof(status_effects);

    ReadGameMemory(
            processID, OFFSET_PLAYER_STATUS_EFFECTS, BytesToRead, PlayerEffects);
}

void
WritePlayerStats(player_stats *PlayerStats) {
    FILE *fpPlayerStats = _wfopen(L"game_data/player/player_stats.txt", L"w");

    fwprintf(fpPlayerStats, L"Player Stats\n\n");

    fwprintf(
            fpPlayerStats, L"HP:   %3i/%3i\n", PlayerStats->HPCur, PlayerStats->HPMax);

    fwprintf(
            fpPlayerStats, L"MP:   %3i/%3i\n", PlayerStats->MPCur, PlayerStats->MPMax);

    fwprintf(fpPlayerStats, L"STR:  %3i/%3i\n", PlayerStats->STRBase,
            PlayerStats->STRCur);
    fwprintf(fpPlayerStats, L"INT:  %3i/%3i\n", PlayerStats->INTBase,
            PlayerStats->INTCur);
    fwprintf(fpPlayerStats, L"AGL:  %3i/%3i\n", PlayerStats->AGLBase,
            PlayerStats->AGLCur);

    fwprintf(fpPlayerStats, L"RISK:     %3i\n\n", PlayerStats->Risk);

    fwprintf(fpPlayerStats, L"SPEED\n");
    fwprintf(fpPlayerStats, L"Running:  %2i\n", PlayerStats->RunningSpeed);
    fwprintf(fpPlayerStats, L"With box: %2i\n\n", PlayerStats->WalkingSpeedWithBox);

    fwprintf(fpPlayerStats, L"Range (x/y/z): %2i/%2i/%2i\n", PlayerStats->Range.x,
            PlayerStats->Range.y, PlayerStats->Range.z);

    fclose(fpPlayerStats);
}

void
PrintPlayerStats(player_stats *PlayerStats) {
    player_stats Stats = *PlayerStats;

    u16 STRBase = Stats.STRBase;
    u16 STRCur = Stats.STRCur;
    u16 INTBase = Stats.INTBase;
    u16 INTCur = Stats.INTCur;
    u16 AGLBase = Stats.AGLBase;
    u16 AGLCur = Stats.AGLCur;

    char STR_Buff = ' ';
    char INT_Buff = ' ';
    char AGL_Buff = ' ';

    if (STRCur > STRBase)
    {
        STR_Buff = '+';
    }
    else if (STRCur < STRBase)
    {
        STR_Buff = '-';
    }

    if (INTCur > INTBase)
    {
        INT_Buff = '+';
    }
    else if (INTCur < INTBase)
    {
        INT_Buff = '-';
    }

    if (AGLCur > AGLBase)
    {
        AGL_Buff = '+';
    }
    else if (AGLCur < AGLBase)
    {
        AGL_Buff = '-';
    }

    swprintf_s(szBuffer, _countof(szBuffer), L"\n\nPLAYER STATS:\n");
    WriteToBackBuffer();

    swprintf_s(szBuffer, _countof(szBuffer),
            L"|    HP    |    MP    | RISK |  %1cSTR   |  %1cINT   |  %1cAGL   |"
            L" Range |       | With Box | Running |\n",
            STR_Buff, INT_Buff, AGL_Buff);
    WriteToBackBuffer();

    swprintf_s(szBuffer, _countof(szBuffer),
            L"|----------|----------|------|---------|---------|---------|"
            L"-------| Speed |----------|---------|\n");
    WriteToBackBuffer();

    swprintf_s(szBuffer, _countof(szBuffer),
            L"|  %3i/%3i |  %3i/%3i | %4i | %3i/%3i | %3i/%3i | %3i/%3i |"
            L" %5i |       | %8i | %7i |\n", //
            Stats.HPCur, Stats.HPMax, //
            Stats.MPCur, Stats.MPMax, //
            Stats.Risk, //
            STRCur, STRBase, //
            INTCur, INTBase, //
            AGLCur, AGLBase,
            Stats.Range.x, //
            Stats.WalkingSpeedWithBox, //
            Stats.RunningSpeed);
    WriteToBackBuffer();
}

void
PrintPlayerEffects(status_effects *PlayerEffects) {
    status_effects Effects = *PlayerEffects;

    swprintf_s(szBuffer, _countof(szBuffer), L"\nSTATUS EFFECTS:\n");
    WriteToBackBuffer();

    u32 StatusEffectMask = Effects.EffectID;

    if (!StatusEffectMask) { // if no Status Effects active, skip it
        swprintf_s(szBuffer, _countof(szBuffer), L"None\n");
        WriteToBackBuffer();
    } else {
        int buff_counter = 0;
        for (int i = 0; i < 32; ++i) {
            if (StatusEffectMasks[i] & StatusEffectMask) {
                swprintf_s(szBuffer, _countof(szBuffer), L"%s%s%s", buff_counter ? L"," : L"",
                        buff_counter ? L" " : L"", StatusEffectNames[i]);
                WriteToBackBuffer();
                buff_counter++;
            }
        }
        swprintf_s(szBuffer, _countof(szBuffer), L"\n");
        WriteToBackBuffer();
    }
}

void
WritePlayerEffects(status_effects *PlayerEffects) {
    status_effects Effects = *PlayerEffects;

    FILE *fpPlayerEffects = _wfopen(L"game_data/player/player_effects.txt", L"w");

    fwprintf(fpPlayerEffects, L"Status Effects\n\n");

    u32 StatusEffectMask = Effects.EffectID;

    if (!StatusEffectMask) { // if no Status Effects active, skip it
        fwprintf(fpPlayerEffects, L"No effects active\n");
    } else {
        int buff_counter = 0;
        for (int i = 0; i < 32; ++i) {
            if (StatusEffectMasks[i] & StatusEffectMask) {
                fwprintf(fpPlayerEffects, L"%s%s%s", buff_counter ? L"," : L"",
                        buff_counter ? L" " : L"", StatusEffectNames[i]);
                buff_counter++;
            }
        }
        fwprintf(fpPlayerEffects, L"\n");
    }
    fclose(fpPlayerEffects);
}

BOOL
CheckPlayerStats(player_stats *PlayerStats) {

    u16 HPCur = PlayerStats->HPCur;
    u16 HPMax = PlayerStats->HPMax;
    u16 MPCur = PlayerStats->MPCur;
    u16 MPMax = PlayerStats->MPMax;
    u16 Risk = PlayerStats->Risk;
    u16 STRBase = PlayerStats->STRBase;
    u16 INTBase = PlayerStats->INTBase;
    u16 AGLBase = PlayerStats->AGLBase;

    // Check for invalid data
    if (HPCur == 0 || HPCur > 999 || HPMax == 0 || HPMax > 999 || MPCur > 999 ||
            MPMax == 0 || MPMax > 999 || STRBase == 0 || STRBase > 999 ||
            INTBase == 0 || INTBase > 999 || AGLBase == 0 || AGLBase > 999 ||
            Risk > 100)
    {
        return FALSE;
    }

    return TRUE;
}

BOOL
PlayerStatsChanged() {
    usize DataSize = sizeof(player_stats);

    BOOL Result = DataChanged(
            (void *) &statsPlayerPrev, (void *) &statsPlayerCur, DataSize);

    return Result;
}

BOOL
PlayerEffectsChanged() {
    usize DataSize = sizeof(status_effects);

    BOOL Result = DataChanged(
            (void *) &effectsPlayerPrev, (void *) &effectsPlayerCur, DataSize);

    return Result;
}

u32
ReadLastBossHealth(u16 *BossHP) {
    u32 BytesRead = ReadGameMemory(processID, OFFSET_LAST_BOSS_HP_CUR, 2, BossHP);

    return BytesRead;
}

void
LastBossHandleIt() {
#ifdef DEBUG
    swprintf_s(szBuffer, _countof(szBuffer), L"\n= LAST BOSS FIGHT IS ON =\n");
    WriteToBackBuffer();
#endif

    ReadLastBossHealth(&LastBossHP);

    if (LastBossHP > 0) {
#ifdef DEBUG
        swprintf_s(szBuffer, _countof(szBuffer), L"Guildenstern's HP: %3i\n", LastBossHP);
        WriteToBackBuffer();
#endif
    } else {
        ReadGameTime(&GameTimeRecord);
        WriteGameTimeRecordToFile(&GameTimeRecord);

#ifdef DEBUG
        swprintf_s(szBuffer, _countof(szBuffer), L"Guildenstern is dead. Good Job!!!\n");
        WriteToBackBuffer();
        CopyFromBackBuffer();
#endif

        GameOver = TRUE;
    }
}

#endif

