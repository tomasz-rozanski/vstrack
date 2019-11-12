#ifndef _VST_TYPES_H
#define _VST_TYPES_H

// Basic Types
#include <stdint.h>
#include <stddef.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

typedef size_t usize;

typedef float f32;
typedef double f64;

//
// In-game structs
//

// Play Time
#pragma pack(push, 1)
typedef struct
{
  u8 Centiseconds; // 1/100th of a second
  u8 Seconds;
  u8 Minutes;
  u8 Hours;
} playtime;
#pragma pack(pop)

// Player/Weapon Range
typedef struct
{
  // Area shape (bits 0-2):
  // 1  spheroid
  // 2  upward cylinder
  // 3  up-downward cylinder
  // 4  downward cone (base is at casting position)
  // 5  upward cone (point is at casting position)
  // 6  cuboid
  // 7  rhombohedron

  // Shape angle (bits 3-7):
  // increment by 360°/32,
  // center is casting position,
  // direction is upward, incrementing backward
  u8 x;
  u8 y;
  u8 z;

  union {
    u8 ShapeAngleCompound;
    struct
    {
      u8 Shape : 3;
      u8 Angle : 5;
    };
  } ShapeAngle;
} range;

// Item Extended Info
#pragma pack(push, 1)
typedef struct
{
  u16 NamesListPosition;
  u8 ListPosition;
  u8 WepFileNumber;
  u8 Category;

  i8 STR;
  i8 INT;
  i8 AGL;

  u16 DPCur;
  u16 DPMax;
  u16 PPCur;
  u16 PPMax;

  // Blades only
  // (1=MP 2=RISK 3=HP 4=PP 5=nothing)
  u8 DamageType;
  u8 StatsCostType;
  u8 StatsCostValue;

  u8 Material;

  i8 _padding0;

  u8 GemSlots; // grips and shields only
  u8 GemsSpecialEffects; // gems only

  u8 EqiupmentListIndex; // RAM only

  range Range; // blades only

  i8 _padding1;

  // Type (grips only)
  u8 TypeBlunt;
  u8 TypeEdged;
  u8 TypePiercing;

  // Class
  i8 ClassHuman;
  i8 ClassBeast;
  i8 ClassUndead;
  i8 ClassPhantom;
  i8 ClassDragon;
  i8 ClassEvil;

  i16 _padding2;

  // Affinity
  i8 AffinityPhysical;
  i8 AffinityAir;
  i8 AffinityFire;
  i8 AffinityEarth;
  i8 AffinityWater;
  i8 AffinityLight;
  i8 AffinityDark;

  i8 _padding3;
} item_info;
#pragma pack(pop)

// Player Stats
#pragma pack(push, 1)
typedef struct
{
  u16 HPCur;
  u16 HPMax;
  u16 MPCur;
  u16 MPMax;
  u16 Risk;
  u16 STRCur;
  u16 STRBase;
  u16 INTCur;
  u16 INTBase;
  u16 AGLCur;
  u16 AGLBase;

  u8 _padding0[3];

  u8 WalkingSpeedWithBox;

  u8 _padding1;

  u8 RunningSpeed;

  u32 _padding2;

  range Range;
} player_stats;
#pragma pack(pop)

// Player status effects (buffs / debuffs)
#pragma pack(push, 1)
typedef struct
{
  u32 EffectID; // bit mask

  u8 _padding0;

  u8 DurationOrFrequency;

  u8 _padding1;

  u32 CanceledBy; // bit mask
  u32 ImmunizedBy; // bit mask
} status_effects;
#pragma pack(pop)

// Player Location
#pragma pack(push, 1)
typedef struct
{
  u8 AreaNumber;
  u8 RoomNumber;
} location;
#pragma pack(pop)

#endif
