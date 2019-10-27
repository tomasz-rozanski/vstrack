#ifndef _VST_PLAYER_H
#define _VST_PLAYER_H

//
// Player data
//

// Misc
#define OFFSET_PLAYER_CURRENT_MODE 0x8011FA10 // NormalMode=0, BattleMode=1
#define OFFSET_PLAYER_EQIPPED_WEAPON_CATEGORY_ID 0x8011FA15
#define OFFSET_PLAYER_PTR_NAME 0x8011FA2C // ptrName
#define OFFSET_PLAYER_PTR_00_SHP_HDR 0x8011FA34 // ptr00ShpHdr
#define OFFSET_PLAYER_PTR_WEAPON_WEP_HDR 0x8011FA38 // ptrWeaponWEPHdr
#define OFFSET_PLAYER_PTR_00_SHP_DATA 0x8011FA3C // ptr00ShpData
#define OFFSET_PLAYER_CHARACTER_NAME                                           \
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
#define OFFSET_PLAYER_WALKING_SPEED_WITH_BOX                                   \
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

#pragma pack(push, 1)
typedef struct
{
  UINT16 HP_Current;
  UINT16 HP_Maximum;
  UINT16 MP_Current;
  UINT16 MP_Maximum;
  UINT16 Risk;
  UINT16 STR_Equipped;
  UINT16 STR_Original;
  UINT16 INT_Equipped;
  UINT16 INT_Original;
  UINT16 AGL_Equipped;
  UINT16 AGL_Original;

  UINT8 Padding0[3];

  UINT8 WalkingSpeedWithBox;

  UINT8 Padding1;

  UINT8 RunningSpeed;

  UINT32 Padding2;

  range Range;
  // UINT8 Range;
} player_stats;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct
{
  UINT32 EffectID; // bit mask

  UINT8 Padding0;

  UINT8 DurationOrFrequency;

  UINT8 Padding1;

  UINT32 CanceledBy; // bit mask
  UINT32 ImmunizedBy; // bit mask
} status_effect;
#pragma pack(pop)

char *StatusEffectNames[32] = { "DYING Head (silent)",
  "DYING Right Arm (damage 50%)", "DYING Left Arm (enemy hit% x2)",
  "DYING Body (RISK decay in Normal Mode as in Battle Mode)",
  "DYING Legs (move 50%)", "STR-down", "STR-up", "INT-down", "INT-up",
  "AGI-down", "AGI-up", "Quicken", "Silence", "Paralysis", "Poison", "Numbness",
  "Curse", "Regen", "Magic Ward ", "Equip-down", "Equip-up", "+Air", "+Fire",
  "+Earth", "+Water", "Resist Air", "Resist Fire", "Resist Earth",
  "Resist Water", "Analyze", "Exorcism/Banish/Drain mind", "Magic Immmunity?" };

UINT32 StatusEffectMasks[32] = { MASK_STATUS_EFFECT_DYING_HEAD,
  MASK_STATUS_EFFECT_DYING_RIGHT_ARM, MASK_STATUS_EFFECT_DYING_LEFT_ARM,
  MASK_STATUS_EFFECT_DYING_BODY, MASK_STATUS_EFFECT_DYING_LEGS,
  MASK_STATUS_EFFECT_STR_DOWN, MASK_STATUS_EFFECT_STR_UP,
  MASK_STATUS_EFFECT_INT_DOWN, MASK_STATUS_EFFECT_INT_UP,
  MASK_STATUS_EFFECT_AGI_DOWN, MASK_STATUS_EFFECT_AGI_UP,
  MASK_STATUS_EFFECT_QUICKEN, MASK_STATUS_EFFECT_SILENCE,
  MASK_STATUS_EFFECT_PARALYSIS, MASK_STATUS_EFFECT_POISON,
  MASK_STATUS_EFFECT_NUMBNESS, MASK_STATUS_EFFECT_CURSE,
  MASK_STATUS_EFFECT_REGEN, MASK_STATUS_EFFECT_MAGIC_WARD,
  MASK_STATUS_EFFECT_EQUIP_DOWN, MASK_STATUS_EFFECT_EQUIP_UP,
  MASK_STATUS_EFFECT_AIR_UP, MASK_STATUS_EFFECT_FIRE_UP,
  MASK_STATUS_EFFECT_EARTH_UP, MASK_STATUS_EFFECT_WATER_UP,
  MASK_STATUS_EFFECT_AIR_RESIST, MASK_STATUS_EFFECT_FIRE_RESIST,
  MASK_STATUS_EFFECT_EARTH_RESIST, MASK_STATUS_EFFECT_WATER_RESIST,
  MASK_STATUS_EFFECT_ANALYZE, MASK_STATUS_EFFECT_EXORCISM,
  MASK_STATUS_EFFECT_MAGIC_IMMMUNITY };

void
WritePlayerStats(void)
{
  player_stats PlayerStats;

  SIZE_T BytesToRead = sizeof(player_stats);
  DWORD BytesRead;

  BytesRead = ReadGameMemory(
      processID, OFFSET_PLAYER_HP_CURRENT, BytesToRead, &PlayerStats);

  FILE *fpPlayerStats = fopen("game_stats/player-stats.txt", "w");

  fprintf(fpPlayerStats, "Player Stats\n\n");

  fprintf(fpPlayerStats, "HP:   %3i/%3i\n", PlayerStats.HP_Current,
      PlayerStats.HP_Maximum);

  fprintf(fpPlayerStats, "MP:   %3i/%3i\n", PlayerStats.MP_Current,
      PlayerStats.MP_Maximum);

  fprintf(fpPlayerStats, "STR:  %3i/%3i\n", PlayerStats.STR_Original,
      PlayerStats.STR_Equipped);
  fprintf(fpPlayerStats, "INT:  %3i/%3i\n", PlayerStats.INT_Original,
      PlayerStats.INT_Equipped);
  fprintf(fpPlayerStats, "AGL:  %3i/%3i\n", PlayerStats.AGL_Original,
      PlayerStats.AGL_Equipped);

  fprintf(fpPlayerStats, "RISK:     %3i\n\n", PlayerStats.Risk);

  fprintf(fpPlayerStats, "SPEED\n");
  fprintf(fpPlayerStats, "Running:  %2i\n", PlayerStats.RunningSpeed);
  fprintf(fpPlayerStats, "With box: %2i\n\n", PlayerStats.WalkingSpeedWithBox);

  fprintf(fpPlayerStats, "Range (x/y/z): %2i/%2i/%2i\n", PlayerStats.Range.x,
      PlayerStats.Range.y, PlayerStats.Range.z);
  // fprintf(fpPlayerStats, "Range: %i\n", PlayerStats.Range);

  fclose(fpPlayerStats);
}

void
PrintPlayerStats(void)
{
  player_stats PlayerStats;

  SIZE_T BytesToRead = sizeof(player_stats);
  DWORD BytesRead;

  BytesRead = ReadGameMemory(
      processID, OFFSET_PLAYER_HP_CURRENT, BytesToRead, &PlayerStats);

  fprintf(stdout, "\n= PLAYER STATS =\n");

  fprintf(stdout, "|HP Cur|HP Max|MP Cur|MP Max|RISK|"
                  "STR Org|STR Equ|INT Org|INT Equ|AGL Org|AGL Equ|\n");

  fprintf(stdout, "|------|------|------|------|----|"
                  "-------|-------|-------|-------|-------|-------|\n");
  fprintf(stdout, "|%6i|%6i|%6i|%6i|%4i|%7i|%7i|%7i|%7i|%7i|%7i|\n", //
      PlayerStats.HP_Current, PlayerStats.HP_Maximum, //
      PlayerStats.MP_Current, PlayerStats.MP_Maximum, //
      PlayerStats.Risk, //
      PlayerStats.STR_Original, PlayerStats.STR_Equipped, //
      PlayerStats.INT_Original, PlayerStats.INT_Equipped, //
      PlayerStats.AGL_Original, PlayerStats.AGL_Equipped);

  if (DEBUG)
  {
    fprintf(stdout, "\n|Range|       |With Box|Running|\n");

    fprintf(stdout, "|-----| Speed |--------|-------|\n");
    fprintf(stdout, "|%5i|       |%8i|%7i|\n", //
        PlayerStats.Range.x, //
        PlayerStats.WalkingSpeedWithBox, //
        PlayerStats.RunningSpeed);
  }
}

void
PrintPlayerStats2(void)
{
  player_stats PlayerStats;
  status_effect StatusEffects;

  DWORD BytesRead;

  BytesRead = ReadGameMemory(
      processID, OFFSET_PLAYER_HP_CURRENT, sizeof(player_stats), &PlayerStats);
  BytesRead = ReadGameMemory(processID, OFFSET_PLAYER_STATUS_EFFECTS,
      sizeof(status_effect), &StatusEffects);

  UINT16 STR_Original = PlayerStats.STR_Original;
  UINT16 STR_Equipped = PlayerStats.STR_Equipped;
  UINT16 INT_Original = PlayerStats.INT_Original;
  UINT16 INT_Equipped = PlayerStats.INT_Equipped;
  UINT16 AGL_Original = PlayerStats.AGL_Original;
  UINT16 AGL_Equipped = PlayerStats.AGL_Equipped;

  char STR_Buff = ' ';
  char INT_Buff = ' ';
  char AGL_Buff = ' ';

  if (STR_Equipped > STR_Original)
  {
    STR_Buff = '+';
  }
  else if (STR_Equipped < STR_Original)
  {
    STR_Buff = '-';
  }

  if (INT_Equipped > INT_Original)
  {
    INT_Buff = '+';
  }
  else if (INT_Equipped < INT_Original)
  {
    INT_Buff = '-';
  }

  if (AGL_Equipped > AGL_Original)
  {
    AGL_Buff = '+';
  }
  else if (AGL_Equipped < AGL_Original)
  {
    AGL_Buff = '-';
  }

  sprintf(szBuffer, "\n\n== PLAYER STATS ==\n\n");
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
      PlayerStats.HP_Current, PlayerStats.HP_Maximum, //
      PlayerStats.MP_Current, PlayerStats.MP_Maximum, //
      PlayerStats.Risk, //
      STR_Equipped, STR_Original, //
      INT_Equipped, INT_Original, //
      AGL_Equipped, AGL_Original,
      PlayerStats.Range.x, //
      PlayerStats.WalkingSpeedWithBox, //
      PlayerStats.RunningSpeed);
  WriteToBackBuffer();

  // Status effects
  sprintf(szBuffer, "\n-- Status Effects --\n\n");
  WriteToBackBuffer();

  UINT32 StatusEffectMask = StatusEffects.EffectID;

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

BOOL
CheckPlayerStats(void)
{
  player_stats PlayerStats;

  DWORD BytesRead;

  BytesRead = ReadGameMemory(
      processID, OFFSET_PLAYER_HP_CURRENT, sizeof(player_stats), &PlayerStats);

  UINT16 HP_Current = PlayerStats.HP_Current;
  UINT16 HP_Maximum = PlayerStats.HP_Maximum;
  UINT16 MP_Current = PlayerStats.MP_Current;
  UINT16 MP_Maximum = PlayerStats.MP_Maximum;
  UINT16 Risk = PlayerStats.Risk;
  UINT16 STR_Original = PlayerStats.STR_Original;
  UINT16 INT_Original = PlayerStats.INT_Original;
  UINT16 AGL_Original = PlayerStats.AGL_Original;

  // Check for invalid data
  if (HP_Current == 0 || HP_Current > 999 || HP_Maximum > 999 ||
      MP_Current == 0 || MP_Current > 999 || MP_Maximum > 999 ||
      STR_Original > 999 || INT_Original > 999 || AGL_Original > 999 ||
      Risk > 100)
  {
    return FALSE;
  }

  return TRUE;
}

DWORD
ReadLastBossHealth(UINT16 *BossHP)
{
  DWORD BytesRead =
      ReadGameMemory(processID, OFFSET_LAST_BOSS_HP_CUR, 2, BossHP);

  return BytesRead;
}

void
LastBossHandleIt2()
{
  sprintf(szBuffer, "\n= LAST BOSS FIGHT IS ON =\n");
  WriteToBackBuffer();

  ReadLastBossHealth(&LastBossHP);

  if (LastBossHP > 0)
  {
    sprintf(szBuffer, "Guildenstern's HP: %3i\n", LastBossHP);
    WriteToBackBuffer();
  }
  else
  {
    sprintf(szBuffer, "Guildenstern is dead. Good Job!!!\n");
    WriteToBackBuffer();

    ReadPlayTime(&RecordTime);
    WriteRecordTimeToFile(
        &RecordTime, _T("game_stats/records"), _T("record-time.txt"));

    CopyFromBackBuffer();

    Sleep(5000);

    GameOver = TRUE;
  }
}

#endif
