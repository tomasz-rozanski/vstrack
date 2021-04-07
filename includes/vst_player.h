#ifndef _VST_PLAYER_H
#define _VST_PLAYER_H

//
// Player data
//

// Offsets

// Misc
#define OFFSET_PLAYER_CURRENT_MODE 0x8011FA10 // NormalMode=0, BattleMode=1
#define OFFSET_PLAYER_EQIPPED_WEAPON_CATEGORY_ID 0x8011FA15
#define OFFSET_PLAYER_PTR_NAME 0x8011FA2C // ptrName
#define OFFSET_PLAYER_PTR_00_SHP_HDR 0x8011FA34 // ptr00ShpHdr
#define OFFSET_PLAYER_PTR_WEAPON_WEP_HDR 0x8011FA38 // ptrWeaponWEPHdr
#define OFFSET_PLAYER_PTR_00_SHP_DATA 0x8011FA3C // ptr00ShpData
#define OFFSET_PLAYER_CHARACTER_NAME \
  0x8011FA40 // CharacterName $18str "Ashley Riot"

// Main stats
#define OFFSET_PLAYER_HP_CURRENT 0x8011FA58 // CurrentHP
#define OFFSET_PLAYER_HP_MAX 0x8011FA5A // MaxHP
#define OFFSET_PLAYER_MP_CURRENT 0x8011FA5C // CurrentMP
#define OFFSET_PLAYER_MP_MAX 0x8011FA5E // MaxMP
#define OFFSET_PLAYER_RISK 0x8011FA60 // RISK
#define OFFSET_PLAYER_STR_EQUIPPED 0x8011FA62 // EquippedSTR
#define OFFSET_PLAYER_STR_ORIGINAL 0x8011FA64 // OriginalSTR
#define OFFSET_PLAYER_INT_EQUIPPED 0x8011FA66 // EquippedINT
#define OFFSET_PLAYER_INT_ORIGINAL 0x8011FA68 // OriginalINT
#define OFFSET_PLAYER_AGL_EQUIPPED 0x8011FA6A // EquippedAGL
#define OFFSET_PLAYER_AGL_ORIGINAL 0x8011FA6C // OriginalAGL
#define OFFSET_PLAYER_WALKING_SPEED_WITH_BOX \
  0x8011FA71 // WalkingSpeedWhenCarryingBoxes
#define OFFSET_PLAYER_RUNNING_SPEED 0x8011FA73 // RunningSpeed
#define OFFSET_PLAYER_RANGE 0x8011FA78 // range

// Status Effects
#define OFFSET_PLAYER_STATUS_EFFECTS 0x80120388

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
#define OFFSET_LAST_BOSS_HP_CUR 0x8017CD08
#define OFFSET_LAST_BOSS_HP_MAX 0x8017CD0A
#define OFFSET_LAST_BOSS_MP_CUR 0x8017CD0C
#define OFFSET_LAST_BOSS_MP_MAX 0x8017CD0E
#define OFFSET_LAST_BOSS_SHD_CUR 0x8017D088
#define OFFSET_LAST_BOSS_SHD_MAX 0x8017D08A

char *StatusEffectNames[32] = { //
  "DYING Head (silent)", "DYING Right Arm (damage 50%%)",
  "DYING Left Arm (enemy hit%% x2)",
  "DYING Body (RISK decay in Normal Mode as in Battle Mode)",
  "DYING Legs (move 50%%)", "STR-down", "STR-up", "INT-down", "INT-up",
  "AGI-down", "AGI-up", "Quicken", "Silence", "Paralysis", "Poison", "Numbness",
  "Curse", "Regen", "Magic Ward ", "Equip-down", "Equip-up", "+Air", "+Fire",
  "+Earth", "+Water", "Resist Air", "Resist Fire", "Resist Earth",
  "Resist Water", "Analyze", "Exorcism/Banish/Drain mind", "Magic Immmunity?"
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
ReadPlayerStats(player_stats *PlayerStats)
{
  //  usize Offset =
  //    (usize)(OFFSET_PLAYER_HP_CURRENT - PSX_TO_EMU + processBaseAddress);

  usize BytesToRead = sizeof(player_stats);

  ReadGameMemory(processID, OFFSET_PLAYER_HP_CURRENT, BytesToRead, PlayerStats);
}

void
ReadPlayerEffects(status_effects *PlayerEffects)
{

  usize BytesToRead = sizeof(status_effects);

  ReadGameMemory(
      processID, OFFSET_PLAYER_STATUS_EFFECTS, BytesToRead, PlayerEffects);
}

void
WritePlayerStats(player_stats *PlayerStats)
{
  FILE *fpPlayerStats = fopen("game_data/player/player_stats.txt", "w");

  fprintf(fpPlayerStats, "Player Stats\n\n");

  fprintf(
      fpPlayerStats, "HP:   %3i/%3i\n", PlayerStats->HPCur, PlayerStats->HPMax);

  fprintf(
      fpPlayerStats, "MP:   %3i/%3i\n", PlayerStats->MPCur, PlayerStats->MPMax);

  fprintf(fpPlayerStats, "STR:  %3i/%3i\n", PlayerStats->STRBase,
      PlayerStats->STRCur);
  fprintf(fpPlayerStats, "INT:  %3i/%3i\n", PlayerStats->INTBase,
      PlayerStats->INTCur);
  fprintf(fpPlayerStats, "AGL:  %3i/%3i\n", PlayerStats->AGLBase,
      PlayerStats->AGLCur);

  fprintf(fpPlayerStats, "RISK:     %3i\n\n", PlayerStats->Risk);

  fprintf(fpPlayerStats, "SPEED\n");
  fprintf(fpPlayerStats, "Running:  %2i\n", PlayerStats->RunningSpeed);
  fprintf(fpPlayerStats, "With box: %2i\n\n", PlayerStats->WalkingSpeedWithBox);

  fprintf(fpPlayerStats, "Range (x/y/z): %2i/%2i/%2i\n", PlayerStats->Range.x,
      PlayerStats->Range.y, PlayerStats->Range.z);

  fclose(fpPlayerStats);
}

void
PrintPlayerStats(player_stats *PlayerStats)
{
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

  sprintf(szBuffer, "\n\nPLAYER STATS:\n");
  WriteToBackBuffer();

  sprintf(szBuffer,
      "|    HP    |    MP    | RISK |  %1cSTR   |  %1cINT   |  %1cAGL   |"
      " Range |       | With Box | Running |\n",
      STR_Buff, INT_Buff, AGL_Buff);
  WriteToBackBuffer();

  sprintf(szBuffer,
      "|----------|----------|------|---------|---------|---------|"
      "-------| Speed |----------|---------|\n");
  WriteToBackBuffer();

  sprintf(szBuffer,
      "|  %3i/%3i |  %3i/%3i | %4i | %3i/%3i | %3i/%3i | %3i/%3i |"
      " %5i |       | %8i | %7i |\n", //
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
PrintPlayerEffects(status_effects *PlayerEffects)
{
  status_effects Effects = *PlayerEffects;

  sprintf(szBuffer, "\nSTATUS EFFECTS:\n");
  WriteToBackBuffer();

  u32 StatusEffectMask = Effects.EffectID;

  if (!StatusEffectMask) // if no Status Effects active, skip it
  {
    sprintf(szBuffer, "None\n");
    WriteToBackBuffer();
  }
  else
  {
    int buff_counter = 0;
    for (int i = 0; i < 32; ++i)
    {
      if (StatusEffectMasks[i] & StatusEffectMask)
      {
        sprintf(szBuffer, "%s%s%s", buff_counter ? "," : "",
            buff_counter ? " " : "", StatusEffectNames[i]);
        WriteToBackBuffer();
        buff_counter++;
      }
    }
    sprintf(szBuffer, "\n");
    WriteToBackBuffer();
  }
}

void
WritePlayerEffects(status_effects *PlayerEffects)
{
  status_effects Effects = *PlayerEffects;

  FILE *fpPlayerEffects = fopen("game_data/player/player_effects.txt", "w");

  fprintf(fpPlayerEffects, "Status Effects\n\n");

  u32 StatusEffectMask = Effects.EffectID;

  if (!StatusEffectMask) // if no Status Effects active, skip it
  {
    fprintf(fpPlayerEffects, "No effects active\n");
  }
  else
  {
    int buff_counter = 0;
    for (int i = 0; i < 32; ++i)
    {
      if (StatusEffectMasks[i] & StatusEffectMask)
      {
        fprintf(fpPlayerEffects, "%s%s%s", buff_counter ? "," : "",
            buff_counter ? " " : "", StatusEffectNames[i]);
        buff_counter++;
      }
    }
    fprintf(fpPlayerEffects, "\n");
  }
  fclose(fpPlayerEffects);
}

BOOL
CheckPlayerStats(player_stats *PlayerStats)
{

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
PlayerStatsChanged()
{
  usize DataSize = sizeof(player_stats);

  BOOL Result = DataChanged(
      (void *) &statsPlayerPrev, (void *) &statsPlayerCur, DataSize);

  return Result;
}

BOOL
PlayerEffectsChanged()
{
  usize DataSize = sizeof(status_effects);

  BOOL Result = DataChanged(
      (void *) &effectsPlayerPrev, (void *) &effectsPlayerCur, DataSize);

  return Result;
}

u32
ReadLastBossHealth(u16 *BossHP)
{
  u32 BytesRead = ReadGameMemory(processID, OFFSET_LAST_BOSS_HP_CUR, 2, BossHP);

  return BytesRead;
}

void
LastBossHandleIt()
{
#ifdef DEBUG
  sprintf(szBuffer, "\n= LAST BOSS FIGHT IS ON =\n");
  WriteToBackBuffer();
#endif

  ReadLastBossHealth(&LastBossHP);

  if (LastBossHP > 0)
  {
#ifdef DEBUG
    sprintf(szBuffer, "Guildenstern's HP: %3i\n", LastBossHP);
    WriteToBackBuffer();
#endif
  }
  else
  {
    ReadGameTime(&GameTimeRecord);
    WriteGameTimeRecordToFile(&GameTimeRecord);

#ifdef DEBUG
    sprintf(szBuffer, "Guildenstern is dead. Good Job!!!\n");
    WriteToBackBuffer();
    CopyFromBackBuffer();
#endif

    GameOver = TRUE;
  }
}

#endif
