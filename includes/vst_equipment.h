#ifndef _VST_EQUIPMENT_H
#define _VST_EQUIPMENT_H

//
// Equipped Item Extended Info
//

/*
 * Area shape (bits 0-2):
 * 1  spheroid
 * 2  upward cylinder
 * 3  up-downward cylinder
 * 4  downward cone (base is at casting position)
 * 5  upward cone (point is at casting position)
 * 6  cuboid
 * 7  rhombohedron
 * Shape angle (bits 3-7):
 * ncrement by 360°/32,
 * center is casting position,
 * direction is upward, incrementing backward
 */

typedef struct
{
  UINT8 x;
  UINT8 y;
  UINT8 z;

  union {
    UINT8 ShapeAngleCompound;
    struct
    {
      UINT8 Shape : 3;
      UINT8 Angle : 5;
    };
  } ShapeAngle;
} range;

#pragma pack(push, 1)
typedef struct
{
  UINT16 NamesListPosition;
  UINT8 ListPosition;
  UINT8 WepFileNumber;
  UINT8 Category;

  INT8 STR_Bonus;
  INT8 INT_Bonus;
  INT8 AGL_Bonus;

  UINT16 DamagePoints;
  UINT16 DamagePointsMax;
  UINT16 PhantomPoints;
  UINT16 PhantomPointsMax;

  // Blades only
  // (1=MP 2=RISK 3=HP 4=PP 5=nothing)
  UINT8 DamageType;
  UINT8 StatsCostType;
  UINT8 StatsCostValue;

  UINT8 Material;

  INT8 Padding0;

  UINT8 GemSlots; // grips and shields only
  UINT8 GemsSpecialEffects;

  UINT8 EqiupmentListIndex; // RAM only

  range Range; // blades only?

  INT8 Padding1;

  // Type (grips only)
  UINT8 TypeBlunt;
  UINT8 TypeEdged;
  UINT8 TypePiercing;

  // Class
  INT8 ClassHuman;
  INT8 ClassBeast;
  INT8 ClassUndead;
  INT8 ClassPhantom;
  INT8 ClassDragon;
  INT8 ClassEvil;

  INT16 Padding2;

  // Affinity
  INT8 AffinityPhysical;
  INT8 AffinityAir;
  INT8 AffinityFire;
  INT8 AffinityEarth;
  INT8 AffinityWater;
  INT8 AffinityLight;
  INT8 AffinityDark;

  INT8 Padding3;
} equip_item_info;

#pragma pack(pop)

enum which_glove
{
  RIGHT_GLOVE,
  LEFT_GLOVE
};

//
// Entry Points
//

// Weapon
#define OFFSET_EQUIPPED_WEAPON_BLADE 0x8011FA94
#define OFFSET_EQUIPPED_WEAPON_GRIP 0x8011FAC4
#define OFFSET_EQUIPPED_WEAPON_GEM_SLOT1 0x8011FAF4
#define OFFSET_EQUIPPED_WEAPON_GEM_SLOT2 0x8011FB24
#define OFFSET_EQUIPPED_WEAPON_GEM_SLOT3 0x8011FB54

// Shield
#define OFFSET_EQUIPPED_SHIELD 0x8011FC2C
#define OFFSET_EQUIPPED_SHIELD_GEM_SLOT1 0x8011FC5C
#define OFFSET_EQUIPPED_SHIELD_GEM_SLOT2 0x8011FC8C
#define OFFSET_EQUIPPED_SHIELD_GEM_SLOT3 0x8011FCBC

// Armor
#define OFFSET_EQUIPPED_RIGHT_ARM 0x8011FDF8
#define OFFSET_EQUIPPED_LEFT_ARM 0x8011FED4
#define OFFSET_EQUIPPED_BODY 0x8012008C
#define OFFSET_EQUIPPED_LEGS 0x80120168
#define OFFSET_EQUIPPED_HEAD 0x8011FFB0
#define OFFSET_EQUIPPED_NECK 0x8011FD78

//
// Weapon Class (Equipped)
//
#define OFFSET_WEAPON_CLASS_HUMAN 0x8011FAB4
#define OFFSET_WEAPON_CLASS_BEAST 0x8011FAB5
#define OFFSET_WEAPON_CLASS_UNDEAD 0x8011FAB6
#define OFFSET_WEAPON_CLASS_PHANTOM 0x8011FAB7
#define OFFSET_WEAPON_CLASS_DRAGON 0x8011FAB8
#define OFFSET_WEAPON_CLASS_EVIL 0x8011FAB9

//
// Weapon Affinity (Equipped)
//
#define OFFSET_WEAPON_AFFINITY_PHYSICAL 0x8011FABC
#define OFFSET_WEAPON_AFFINITY_AIR 0x8011FABD
#define OFFSET_WEAPON_AFFINITY_FIRE 0x8011FABE
#define OFFSET_WEAPON_AFFINITY_EARTH 0x8011FABF
#define OFFSET_WEAPON_AFFINITY_WATER 0x8011FAC0
#define OFFSET_WEAPON_AFFINITY_LIGHT 0x8011FAC1
#define OFFSET_WEAPON_AFFINITY_DARK 0x8011FAC2

char *ItemNamesList[512] = { "", "Battle Knife", "Scramasax", "Dirk",
  "Throwing Knife", "Kudi", "Cinquedea", "Kris", "Hatchet", "Khukuri",
  "Baselard", "Stiletto", "Jamadhar", "Spatha", "Scimitar", "Rapier",
  "Short Sword", "Firangi", "Shamshir", "Falchion", "Shotel", "Khora",
  "Khopesh", "Wakizashi", "Rhomphaia", "Broad Sword", "Norse Sword", "Katana",
  "Executioner", "Claymore", "Schiavona", "Bastard Sword", "Nodachi",
  "Rune Blade", "Holy Win", "Hand Axe", "Battle Axe", "Francisca", "Tabarzin",
  "Chamkaq", "Tabar", "Bullova", "Crescent", "Goblin Club", "Spiked Club",
  "Ball Mace", "Footman\'s Mace", "Morning Star", "War Hammer", "Bec de Corbin",
  "War Maul", "Guisarme", "Large Crescent", "Sabre Halberd", "Balbriggan",
  "Double Blade", "Halberd", "Wizard Staff", "Clergy Rod", "Summoner Baton",
  "Shamanic Staff", "Bishop\'s Crosier", "Sage\'s Cane", "Langdebeve",
  "Sabre Mace", "Footman\'s Mace", "Gloomwing", "Mjolnir", "Griever",
  "Destroyer", "Hand of Light", "Spear", "Glaive", "Scorpion", "Corcesca",
  "Trident", "Awl Pike", "Boar Spear", "Fauchard", "Voulge", "Pole Axe",
  "Bardysh", "Brandestoc", "Gastraph Bow", "Light Crossbow", "Target Bow",
  "Windlass", "Cranequin", "Lug Crossbow", "Siege Bow", "Arbalest", "untitled",
  "untitled", "untitled", "untitled", "untitled", "Short Hilt", "Swept Hilt",
  "Cross Guard", "Knuckle Guard", "Counter Guard", "Side Ring", "Power Palm",
  "Murderer\'s Hilt", "Spiral Hilt", "Wooden Grip", "Sand Face", "Czekan Type",
  "Sarissa Grip", "Gendarme", "Heavy Grip", "Runkasyle", "Bhuj Type",
  "Grimoire Grip", "Elephant", "Wooden Pole", "Spiculum Pole", "Winged Pole",
  "Framea Pole", "Ahlspies", "Spiral Pole", "Simple Bolt", "Steel Bolt",
  "Javelin Bolt", "Falarica Bolt", "Stone Bullet", "Sonic Bullet", "Buckler",
  "Pelta Shield", "Targe", "Quad Shield", "Circle Shield", "Tower Shield",
  "Spiked Shield", "Round Shield", "Kite Shield", "Casserole Shield",
  "Heater Shield", "Oval Shield", "Knight Shield", "Hoplite Shield",
  "Jazeraint Shield", "Dread Shield", "Bandana", "Bear Mask", "Wizard Hat",
  "Bone Helm", "Chain Coif", "Spangenhelm", "Cabasset", "Sallet", "Barbut",
  "Basinet", "Armet", "Close Helm", "Burgonet", "Hoplite Helm",
  "Jazeraint Helm", "Dread Helm", "Jerkin", "Hauberk", "Wizard Robe", "Cuirass",
  "Banded Mail", "Ring Mail", "Chain Mail", "Breastplate", "Segmentata",
  "Scale Armor", "Brigandine", "Plate Mail", "Fluted Armor", "Hoplite Armor",
  "Jazeraint Armor", "Dread Armor", "Sandals", "Boots", "Long Boots", "Cuisse",
  "Light Greave", "Ring Leggings", "Chain Leggings", "Fusskampf", "Poleyn",
  "Jambeau", "Missaglia", "Plate Leggings", "Fluted Leggings",
  "Hoplite Leggings", "Jazeraint Leggings", "Dread Leggings", "Bandage",
  "Leather Glove", "Reinforced Glove", "Knuckles", "Ring Sleeve",
  "Chain Sleeve", "Gauntlet", "Vambrace", "Plate Glove", "Rondanche",
  "Tilt Glove", "Freiturnier", "Fluted Glove", "Hoplite Glove",
  "Jazeraint Glove", "Dread Glove", "untitled", "untitled", "untitled",
  "untitled", "untitled", "untitled", "untitled", "untitled", "untitled",
  "untitled", "untitled", "untitled", "untitled", "untitled", "untitled",
  "untitled", "Rood Necklace", "Rune Earrings", "Lionhead", "Rusted Nails",
  "Sylphid Ring", "Marduk", "Salamander Ring", "Tamulis Tongue",
  "Gnome Bracelet", "Palolo\'s Ring", "Undine Bracelet", "Talian Ring",
  "Agrias\'s Balm", "Kadesh Ring", "Agrippa\'s Choker", "Diadra\'s Earring",
  "Titan\'s Ring", "Lau Fei\'s Armlet", "Swan Song", "Pushpaka",
  "Edgar\'s Earrings", "Cross Choker", "Ghost Hound", "Beaded Anklet",
  "Dragonhead", "Faufnir\'s Tear", "Agales\'s Chain", "Balam Ring",
  "Nimje Coif", "Morgan\'s Nails", "Marlene\'s Ring", "Wood", "Leather",
  "Bronze", "Iron", "Hagane", "Silver", "Damascus", "Talos Feldspar",
  "Titan Malachite", "Sylphid Topaz", "Djinn Amber", "Salamander Ruby",
  "Ifrit Carnelian", "Gnome Emerald", "Dao Moonstone", "Undine Jasper",
  "Marid Aquamarine", "Angel Pearl", "Seraphim Diamond", "Morlock Jet",
  "Berial Blackpearl", "Haeralis", "Orlandu", "Orion", "Ogmius", "Iocus",
  "Balvus", "Trinity", "Beowulf", "Dragonite", "Sigguld", "Demonia", "Altema",
  "Polaris", "Basivalen", "Galerian", "Vedivier", "Berion", "Gervin", "Tertia",
  "Lancer", "Arturos", "Braveheart", "Hellraiser", "Nightkiller", "Manabreaker",
  "Powerfist", "Brainshield", "Speedster", "untitled", "Silent Queen",
  "Dark Queen", "Death Queen", "White Queen", "untitled", "untitled",
  "untitled", "untitled", "untitled", "untitled", "untitled", "untitled",
  "untitled", "untitled", "untitled", "untitled", "untitled", "untitled",
  "untitled", "Cure Root", "Cure Bulb", "Cure Tonic", "Cure Potion",
  "Mana Root", "Mana Bulb", "Mana Tonic", "Mana Potion", "Vera Root",
  "Vera Bulb", "Vera Tonic", "Vera Potion", "Acolyte\'s Nostrum",
  "Saint\'s Nostrum", "Alchemist\'s Reagent", "Sorcerer\'s Reagent",
  "Yggdrasil\'s Tears", "Faerie Chortle", "Spirit Orison", "Angelic Paean",
  "Panacea", "Snowfly Draught", "Faerie Wing", "Elixir of Kings",
  "Elixir of Sages", "Elixir of Dragoons", "Elixir of Queens",
  "Elixir of Mages", "Valens", "Prudens", "Volare", "Audentia", "Virtus",
  "Eye of Argon", "untitled", "untitled", "untitled", "untitled", "untitled",
  "untitled", "untitled", "untitled", "untitled", "untitled", "untitled",
  "untitled", "untitled", "untitled", "untitled", "untitled", "untitled",
  "untitled", "untitled", "untitled", "untitled", "untitled", "untitled",
  "untitled", "untitled", "untitled", "untitled", "untitled", "untitled",
  "Grimoire Zephyr", "Grimoire Teslae", "Grimoire Incendie", "Grimoire Terre",
  "Grimoire Glace", "Grimoire Lux", "Grimoire Patir", "Grimoire Exsorcer",
  "Grimoire Banish", "Grimoire Demolir", "untitled", "untitled", "untitled",
  "Grimoire Foudre", "untitled", "untitled", "untitled", "Grimoire Flamme",
  "untitled", "untitled", "untitled", "Grimoire Gaea", "untitled", "untitled",
  "untitled", "Grimoire Avalanche", "untitled", "untitled", "untitled",
  "Grimoire Radius", "untitled", "untitled", "untitled", "Grimoire Meteore",
  "untitled", "untitled", "untitled", "Grimoire Egout", "Grimoire Demance",
  "Grimoire Guerir", "Grimoire Mollesse", "Grimoire Antidote", "Grimoire Benir",
  "Grimoire Purifier", "Grimoire Vie", "Grimoire Intensite", "Grimoire Debile",
  "Grimoire Eclairer", "Grimoire Nuageux", "Grimoire Agilite",
  "Grimoire Tardif", "Grimoire Ameliorer", "Grimoire Deteriorer",
  "Grimoire Muet", "Grimoire Annuler", "Grimoire Paralysie", "Grimoire Venin",
  "Grimoire Fleau", "Grimoire Halte", "Grimoire Dissiper", "Grimoire Clef",
  "Grimoire Visible", "Grimoire Analyse", "Grimoire Sylphe",
  "Grimoire Salamandre", "Grimoire Gnome", "Grimoire Undine",
  "Grimoire Parebrise", "Grimoire Ignifuge", "Grimoire Rempart",
  "Grimoire Barrer", "untitled", "Bronze Key", "Iron Key", "Silver Key",
  "Gold Key", "Platinum Key", "Steel Key", "Crimson Key", "Chest Key",
  "Chamomile Sigil", "Lily Sigil", "Tearose Sigil", "Clematis Sigil",
  "Hyacinth Sigil", "Fern Sigil", "Aster Sigil", "Eulelia Sigil",
  "Melissa Sigil", "Calla Sigil", "Laurel Sigil", "Acacia Sigil", "Palm Sigil",
  "Kalmia Sigil", "Colombine Sigil", "Anemone Sigil", "Verbena Sigil",
  "Schirra Sigil", "Marigold Sigil", "Azalea Sigil", "Tigertail Sigil",
  "Stock Sigil", "Cattleya Sigil", "Mandrake Sigil", "untitled", "untitled",
  "untitled", "untitled", "untitled", "untitled", "untitled", "untitled",
  "untitled", "untitled", "untitled", "untitled", "untitled", "untitled",
  "untitled", "untitled", "untitled", "untitled", "untitled", "untitled",
  "untitled", "untitled" };

char *ArmoursList[81] = { "", "Buckler", "Pelta Shield", "Targe", "Quad Shield",
  "Circle Shield", "Tower Shield", "Spiked Shield", "Round Shield",
  "Kite Shield", "Casserole Shield", "Heater Shield", "Oval Shield",
  "Knight Shield", "Hoplite Shield", "Jazeraint Shield", "Dread Shield",
  "Bandana", "Bear Mask", "Wizard Hat", "Bone Helm", "Chain Coif",
  "Spangenhelm", "Cabasset", "Sallet", "Barbut", "Basinet", "Armet",
  "Close Helm", "Burgonet", "Hoplite Helm", "Jazeraint Helm", "Dread Helm",
  "Jerkin", "Hauberk", "Wizard Robe", "Cuirass", "Banded Mail", "Ring Mail",
  "Chain Mail", "Breastplate", "Segmentata", "Scale Armor", "Brigandine",
  "Plate Mail", "Fluted Armor", "Hoplite Armor", "Jazeraint Armor",
  "Dread Armor", "Sandals", "Boots", "Long Boots", "Cuisse", "Light Greave",
  "Ring Leggings", "Chain Leggings", "Fusskampf", "Poleyn", "Jambeau",
  "Missaglia", "Plate Leggings", "Fluted Leggings", "Hoplite Leggings",
  "Jazeraint Leggings", "Dread Leggings", "Bandage", "Leather Glove",
  "Reinforced Glove", "Knuckles", "Ring Sleeve", "Chain Sleeve", "Gauntlet",
  "Vambrace", "Plate Glove", "Rondanche", "Tilt Glove", "Freiturnier",
  "Fluted Glove", "Hoplite Glove", "Jazeraint Glove", "Dread Glove" };

char *WeaponsList[91] = { "", "Battle Knife", "Scramasax", "Dirk",
  "Throwing Knife", "Kudi", "Cinquedea", "Kris", "Hatchet", "Khukuri",
  "Baselard", "Stiletto", "Jamadhar", "Spatha", "Scimitar", "Rapier",
  "Short Sword", "Firangi", "Shamshir", "Falchion", "Shotel", "Khora",
  "Khopesh", "Wakizashi", "Rhomphaia", "Broad Sword", "Norse Sword", "Katana",
  "Executioner", "Claymore", "Schiavona", "Bastard Sword", "Nodachi",
  "Rune Blade", "Holy Win", "Hand Axe", "Battle Axe", "Francisca", "Tabarzin",
  "Chamkaq", "Tabar", "Bullova", "Crescent", "Goblin Club", "Spiked Club",
  "Ball Mace", "Footman\'s Mace", "Morning Star", "War Hammer", "Bec de Corbin",
  "War Maul", "Guisarme", "Large Crescent", "Sabre Halberd", "Balbriggan",
  "Double Blade", "Halberd", "Wizard Staff", "Clergy Rod", "Summoner Baton",
  "Shamanic Staff", "Bishop\'s Crosier", "Sage\'s Cane", "Langdebeve",
  "Sabre Mace", "Footman\'s Mace", "Gloomwing", "Mjolnir", "Griever",
  "Destroyer", "Hand of Light", "Spear", "Glaive", "Scorpion", "Corcesca",
  "Trident", "Awl Pike", "Boar Spear", "Fauchard", "Voulge", "Pole Axe",
  "Bardysh", "Brandestoc", "Gastraph Bow", "Light Crossbow", "Target Bow",
  "Windlass", "Cranequin", "Lug Crossbow", "Siege Bow", "Arbalest" };

char *AccessoriesList[32] = { "", "Rood Necklace", "Rune Earrings", "Lionhead",
  "Rusted Nails", "Sylphid Ring", "Marduk", "Salamander Ring", "Tamulis Tongue",
  "Gnome Bracelet", "Palolo\'s Ring", "Undine Bracelet", "Talian Ring",
  "Agrias\'s Balm", "Kadesh Ring", "Agrippa\'s Choker", "Diadra\'s Earring",
  "Titan\'s Ring", "Lau Fei\'s Armlet", "Swan Song", "Pushpaka",
  "Edgar\'s Earrings", "Cross Choker", "Ghost Hound", "Beaded Anklet",
  "Dragonhead", "Faufnir\'s Tear", "Agales\'s Chain", "Balam Ring",
  "Nimje Coif", "Morgan\'s Nails", "Marlene\'s Ring" };

char *GripsList[32] = { "", "Short Hilt", "Swept Hilt", "Cross Guard",
  "Knuckle Guard", "Counter Guard", "Side Ring", "Power Palm",
  "Murderer's Hilt", "Spiral Hilt", "Wooden Grip", "Sand Face", "Czekan Type",
  "Sarissa Grip", "Gendarme", "Heavy Grip", "Runkasyle", "Bhuj Type",
  "Grimoire Grip", "Elephant", "Wooden Pole", "Spiculum Pole", "Winged Pole",
  "Framea Pole", "Ahlspies", "Spiral Pole", "Simple Bolt", "Steel Bolt",
  "Javelin Bolt", "Falarica Bolt", "Stone Bullet", "Sonic Bullet" };

char *GemsList[63] = { "None", "Talos Feldspar", "Titan Malachite",
  "Sylphid Topaz", "Djinn Amber", "Salamander Ruby", "Ifrit Carnelian",
  "Gnome Emerald", "Dao Moonstone", "Undine Jasper", "Marid Aquamarine",
  "Angel Pearl", "Seraphim Diamond", "Morlock Jet", "Berial Blackpearl",
  "Haeralis", "Orlandu", "Orion", "Ogmius", "Iocus", "Balvus", "Trinity",
  "Beowulf", "Dragonite", "Sigguld", "Demonia", "Altema", "Polaris",
  "Basivalen", "Galerian", "Vedivier", "Berion", "Gervin", "Tertia", "Lancer",
  "Arturos", "Braveheart", "Hellraiser", "Nightkiller", "Manabreaker",
  "Powerfist", "Brainshield", "Speedster", "untitled", "Silent Queen",
  "Dark Queen", "Death Queen", "White Queen", "untitled", "untitled",
  "untitled", "untitled", "untitled", "untitled", "untitled", "untitled",
  "untitled", "untitled", "untitled", "untitled", "untitled", "untitled",
  "untitled" };

char *ArmoursCategories[8] = { "", "Shield", "Helm", "Breast Armor", "Leggings",
  "Glove", "unused", "Accessory" };

char *WeaponsCategories[11] = { "", "Daggers", "Swords", "Great Swords",
  "Axes & Maces", "Great Axes", "Staves", "Heavy Maces", "Polearms",
  "Crossbows", "Bare Hands" };

char *WeaponDamageType[4] = { "", "Blunt", "Edged", "Piercing" };

char *WeaponAttackCostType[6] = { "", "MP", "RISK", "HP", "PP", "nothing" };

char *CraftingMaterials[8] = { "", "Wood", "Leather", "Bronze", "Iron",
  "Hagane", "Silver", "Damascus" };

char *ItemClass[10] = { "", "Warrior's ", "Knightly ", "Prestigious ", "Brave ",
  "Warlord ", "Champion ", "Glorious ", "Supreme ", "Divine " };

void
WriteBladeInfo(DWORD processID)
{
  equip_item_info BladeInfo;

  SIZE_T BytesToRead = sizeof(equip_item_info);
  DWORD BytesRead;

  BytesRead = ReadGameMemory(
      processID, OFFSET_EQUIPPED_WEAPON_BLADE, BytesToRead, &BladeInfo);

  FILE *fpBladeInfoExt = fopen("game_stats/blade-full.txt", "w");

  // Check if weapon is eqipped
  if (BladeInfo.ListPosition == 0)
  {
    fprintf(
        fpBladeInfoExt, "Can't read the blade data: weapon is not equipped!\n");
    fclose(fpBladeInfoExt);

    return;
  }

  fprintf(fpBladeInfoExt, "Blade Extended Stats\n\n");

  fprintf(fpBladeInfoExt, "Name: %s\n", WeaponsList[BladeInfo.ListPosition]);
  fprintf(
      fpBladeInfoExt, "Category: %s\n", WeaponsCategories[BladeInfo.Category]);
  fprintf(
      fpBladeInfoExt, "Material: %s\n", CraftingMaterials[BladeInfo.Material]);
  fprintf(fpBladeInfoExt, "Damage type: %s\n",
      WeaponDamageType[BladeInfo.DamageType]);
  fprintf(fpBladeInfoExt, "\n");

  // Bonuses
  fprintf(fpBladeInfoExt, "BONUSES\n");
  fprintf(fpBladeInfoExt, "========\n");
  fprintf(fpBladeInfoExt, "STR: %3i\n", BladeInfo.STR_Bonus);
  fprintf(fpBladeInfoExt, "INT: %3i\n", BladeInfo.INT_Bonus);
  fprintf(fpBladeInfoExt, "AGL: %3i\n", BladeInfo.AGL_Bonus);
  fprintf(fpBladeInfoExt, "\n");

  // DP & PP
  fprintf(fpBladeInfoExt, "DURABILITY\n");
  fprintf(fpBladeInfoExt, "===========\n");
  fprintf(fpBladeInfoExt, "DP: %3i/%3i\n", (BladeInfo.DamagePoints + 99) / 100,
      (BladeInfo.DamagePointsMax + 99) / 100);
  fprintf(fpBladeInfoExt, "PP: %3i/%3i\n", BladeInfo.PhantomPoints,
      BladeInfo.PhantomPointsMax);
  fprintf(fpBladeInfoExt, "\n");

  // Misc
  fprintf(fpBladeInfoExt, "MISC\n");
  fprintf(fpBladeInfoExt, "=======================\n");

  // Range
  fprintf(fpBladeInfoExt, "Range (x/y/z): %2i/%2i/%2i\n", BladeInfo.Range.x,
      BladeInfo.Range.y, BladeInfo.Range.z);

  // Resource cost
  fprintf(fpBladeInfoExt, "Attack cost: %i %s\n", BladeInfo.StatsCostValue,
      WeaponAttackCostType[BladeInfo.StatsCostType]);
  fprintf(fpBladeInfoExt, "\n");

  // Class
  fprintf(fpBladeInfoExt, "CLASS\n");
  fprintf(fpBladeInfoExt, "=============\n");
  fprintf(fpBladeInfoExt, "Human:    %3i\n", BladeInfo.ClassHuman);
  fprintf(fpBladeInfoExt, "Beast:    %3i\n", BladeInfo.ClassBeast);
  fprintf(fpBladeInfoExt, "Undead:   %3i\n", BladeInfo.ClassUndead);
  fprintf(fpBladeInfoExt, "Phantom:  %3i\n", BladeInfo.ClassPhantom);
  fprintf(fpBladeInfoExt, "Dragon:   %3i\n", BladeInfo.ClassDragon);
  fprintf(fpBladeInfoExt, "Evil:     %3i\n", BladeInfo.ClassEvil);
  fprintf(fpBladeInfoExt, "\n");

  // Affinity
  fprintf(fpBladeInfoExt, "AFFINITY\n");
  fprintf(fpBladeInfoExt, "=============\n");
  fprintf(fpBladeInfoExt, "Physical: %3i\n", BladeInfo.AffinityPhysical);
  fprintf(fpBladeInfoExt, "Air:      %3i\n", BladeInfo.AffinityAir);
  fprintf(fpBladeInfoExt, "Fire:     %3i\n", BladeInfo.AffinityFire);
  fprintf(fpBladeInfoExt, "Earth:    %3i\n", BladeInfo.AffinityEarth);
  fprintf(fpBladeInfoExt, "Water:    %3i\n", BladeInfo.AffinityWater);
  fprintf(fpBladeInfoExt, "Light:    %3i\n", BladeInfo.AffinityLight);
  fprintf(fpBladeInfoExt, "Dark:     %3i\n", BladeInfo.AffinityDark);

  fclose(fpBladeInfoExt);
}

void
WriteBladeInfoShort(DWORD processID)
{
  equip_item_info BladeInfo;

  SIZE_T BytesToRead = sizeof(equip_item_info);
  DWORD BytesRead;

  BytesRead = ReadGameMemory(
      processID, OFFSET_EQUIPPED_WEAPON_BLADE, BytesToRead, &BladeInfo);

  FILE *fpBladeInfoShort = fopen("game_stats/blade-short.txt", "w");

  // Check if weapon is eqipped
  if (BladeInfo.ListPosition == 0)
  {
    fprintf(fpBladeInfoShort,
        "Can't read the blade data: weapon is not equipped!\n");
    fclose(fpBladeInfoShort);

    return;
  }

  fprintf(fpBladeInfoShort, "Blade Basic Stats\n\n");

  // Class
  fprintf(fpBladeInfoShort, "CLASS\n");
  fprintf(fpBladeInfoShort, "=============\n");
  fprintf(fpBladeInfoShort, "Human:    %3i\n", BladeInfo.ClassHuman);
  fprintf(fpBladeInfoShort, "Beast:    %3i\n", BladeInfo.ClassBeast);
  fprintf(fpBladeInfoShort, "Undead:   %3i\n", BladeInfo.ClassUndead);
  fprintf(fpBladeInfoShort, "Phantom:  %3i\n", BladeInfo.ClassPhantom);
  fprintf(fpBladeInfoShort, "Dragon:   %3i\n", BladeInfo.ClassDragon);
  fprintf(fpBladeInfoShort, "Evil:     %3i\n", BladeInfo.ClassEvil);
  fprintf(fpBladeInfoShort, "\n");

  // Affinity
  fprintf(fpBladeInfoShort, "AFFINITY\n");
  fprintf(fpBladeInfoShort, "=============\n");
  fprintf(fpBladeInfoShort, "Physical: %3i\n", BladeInfo.AffinityPhysical);
  fprintf(fpBladeInfoShort, "Air:      %3i\n", BladeInfo.AffinityAir);
  fprintf(fpBladeInfoShort, "Fire:     %3i\n", BladeInfo.AffinityFire);
  fprintf(fpBladeInfoShort, "Earth:    %3i\n", BladeInfo.AffinityEarth);
  fprintf(fpBladeInfoShort, "Water:    %3i\n", BladeInfo.AffinityWater);
  fprintf(fpBladeInfoShort, "Light:    %3i\n", BladeInfo.AffinityLight);
  fprintf(fpBladeInfoShort, "Dark:     %3i\n", BladeInfo.AffinityDark);

  fclose(fpBladeInfoShort);
}

void
WriteWeaponInfo(DWORD processID)
{
  equip_item_info BladeInfo;
  equip_item_info GripInfo;
  equip_item_info Gem1Info;
  equip_item_info Gem2Info;
  equip_item_info Gem3Info;

  SIZE_T BytesToRead = sizeof(equip_item_info);
  DWORD BytesRead;

  BytesRead = ReadGameMemory(
      processID, OFFSET_EQUIPPED_WEAPON_BLADE, BytesToRead, &BladeInfo);
  BytesRead = ReadGameMemory(
      processID, OFFSET_EQUIPPED_WEAPON_GRIP, BytesToRead, &GripInfo);
  BytesRead = ReadGameMemory(
      processID, OFFSET_EQUIPPED_WEAPON_GEM_SLOT1, BytesToRead, &Gem1Info);
  BytesRead = ReadGameMemory(
      processID, OFFSET_EQUIPPED_WEAPON_GEM_SLOT2, BytesToRead, &Gem2Info);
  BytesRead = ReadGameMemory(
      processID, OFFSET_EQUIPPED_WEAPON_GEM_SLOT3, BytesToRead, &Gem3Info);

  FILE *fpWeaponInfo = fopen("game_stats/weapon-full.txt", "w");

  // Check if weapon is eqipped
  if (BladeInfo.ListPosition == 0)
  {
    fprintf(fpWeaponInfo, "Weapon not equipped!\n");
    fclose(fpWeaponInfo);

    return;
  }

  fprintf(fpWeaponInfo, "Weapon Stats\n\n");

  // char WeaponName[18] = "";
  // GetWeaponName(processID, WeaponName);

  fprintf(fpWeaponInfo, "Weapon name: %s\n", GlobalWeaponName);
  fprintf(
      fpWeaponInfo, "Blade name: %s\n", WeaponsList[BladeInfo.ListPosition]);
  fprintf(
      fpWeaponInfo, "Category: %s\n", WeaponsCategories[BladeInfo.Category]);
  fprintf(
      fpWeaponInfo, "Material: %s\n", CraftingMaterials[BladeInfo.Material]);
  fprintf(fpWeaponInfo, "Grip: %s\n", GripsList[GripInfo.ListPosition]);
  fprintf(fpWeaponInfo, "Damage type: %s\n",
      WeaponDamageType[BladeInfo.DamageType]);
  fprintf(fpWeaponInfo, "\n");

  // Bonuses
  INT16 STR_BonusTotal = BladeInfo.STR_Bonus + GripInfo.STR_Bonus +
                         Gem1Info.STR_Bonus + Gem2Info.STR_Bonus +
                         Gem3Info.STR_Bonus;
  INT16 INT_BonusTotal = BladeInfo.INT_Bonus + GripInfo.INT_Bonus +
                         Gem1Info.INT_Bonus + Gem2Info.INT_Bonus +
                         Gem3Info.INT_Bonus;
  INT16 AGL_BonusTotal = BladeInfo.AGL_Bonus + GripInfo.AGL_Bonus +
                         Gem1Info.AGL_Bonus + Gem2Info.AGL_Bonus +
                         Gem3Info.AGL_Bonus;

  fprintf(fpWeaponInfo, "BONUSES\n");
  fprintf(fpWeaponInfo, "========\n");
  fprintf(fpWeaponInfo, "STR: %3i\n", STR_BonusTotal);
  fprintf(fpWeaponInfo, "INT: %3i\n", INT_BonusTotal);
  fprintf(fpWeaponInfo, "AGL: %3i\n", AGL_BonusTotal);
  fprintf(fpWeaponInfo, "\n");

  // DP & PP
  fprintf(fpWeaponInfo, "DURABILITY\n");
  fprintf(fpWeaponInfo, "===========\n");
  fprintf(fpWeaponInfo, "DP: %3i/%3i\n", (BladeInfo.DamagePoints + 99) / 100,
      (BladeInfo.DamagePointsMax + 99) / 100);
  fprintf(fpWeaponInfo, "PP: %3i/%3i\n", BladeInfo.PhantomPoints,
      BladeInfo.PhantomPointsMax);
  fprintf(fpWeaponInfo, "\n");

  // Misc
  fprintf(fpWeaponInfo, "MISC\n");
  fprintf(fpWeaponInfo, "=======================\n");

  // Range
  fprintf(fpWeaponInfo, "Range (x/y/z): %2i/%2i/%2i\n", BladeInfo.Range.x,
      BladeInfo.Range.y, BladeInfo.Range.z);

  // Resource cost
  fprintf(fpWeaponInfo, "Attack cost: %i %s\n", BladeInfo.StatsCostValue,
      WeaponAttackCostType[BladeInfo.StatsCostType]);

  fprintf(fpWeaponInfo, "\n");

  // Gems
  UINT8 GemSlots = GripInfo.GemSlots;
  if (GemSlots)
  {
    fprintf(fpWeaponInfo, "GEMS\n");
    fprintf(fpWeaponInfo, "=========================\n");

    fprintf(fpWeaponInfo, "Slot 1: %17s\n", GemsList[Gem1Info.ListPosition]);

    if (GemSlots > 1)
    {
      fprintf(fpWeaponInfo, "Slot 2: %17s\n", GemsList[Gem2Info.ListPosition]);
    }
    if (GemSlots > 2)
    {
      fprintf(fpWeaponInfo, "Slot 3: %17s\n", GemsList[Gem3Info.ListPosition]);
    }
  }

  // fprintf(fpWeaponInfo, "Gem effects 1: %i\n", Gem1Info.GemsSpecialEffects);
  // fprintf(fpWeaponInfo, "Gem effects 2: %i\n", Gem2Info.GemsSpecialEffects);
  // fprintf(fpWeaponInfo, "Gem effects 3: %i\n", Gem3Info.GemsSpecialEffects);

  fprintf(fpWeaponInfo, "\n");

  // Type
  fprintf(fpWeaponInfo, "TYPE\n");
  fprintf(fpWeaponInfo, "============\n");
  fprintf(fpWeaponInfo, "Blunt:    %2i\n", GripInfo.TypeBlunt);
  fprintf(fpWeaponInfo, "Edged:    %2i\n", GripInfo.TypeEdged);
  fprintf(fpWeaponInfo, "Piercing: %2i\n", GripInfo.TypePiercing);
  fprintf(fpWeaponInfo, "\n");

  // Class summary
  INT16 ClassHumanTotal = BladeInfo.ClassHuman + Gem1Info.ClassHuman +
                          Gem2Info.ClassHuman + Gem3Info.ClassHuman;
  INT16 ClassBeastTotal = BladeInfo.ClassBeast + Gem1Info.ClassBeast +
                          Gem2Info.ClassBeast + Gem3Info.ClassBeast;
  INT16 ClassUndeadTotal = BladeInfo.ClassUndead + Gem1Info.ClassUndead +
                           Gem2Info.ClassUndead + Gem3Info.ClassUndead;
  INT16 ClassPhantomTotal = BladeInfo.ClassPhantom + Gem1Info.ClassPhantom +
                            Gem2Info.ClassPhantom + Gem3Info.ClassPhantom;
  INT16 ClassDragonTotal = BladeInfo.ClassDragon + Gem1Info.ClassDragon +
                           Gem2Info.ClassDragon + Gem3Info.ClassDragon;
  INT16 ClassEvilTotal = BladeInfo.ClassEvil + Gem1Info.ClassEvil +
                         Gem2Info.ClassEvil + Gem3Info.ClassEvil;

  // Affinity summary
  INT16 AffinityPhysicalTotal =
      BladeInfo.AffinityPhysical + Gem1Info.AffinityPhysical +
      Gem2Info.AffinityPhysical + Gem3Info.AffinityPhysical;
  INT16 AffinityAirTotal = BladeInfo.AffinityAir + Gem1Info.AffinityAir +
                           Gem2Info.AffinityAir + Gem3Info.AffinityAir;
  INT16 AffinityFireTotal = BladeInfo.AffinityFire + Gem1Info.AffinityFire +
                            Gem2Info.AffinityFire + Gem3Info.AffinityFire;
  INT16 AffinityEarthTotal = BladeInfo.AffinityEarth + Gem1Info.AffinityEarth +
                             Gem2Info.AffinityEarth + Gem3Info.AffinityEarth;
  INT16 AffinityWaterTotal = BladeInfo.AffinityWater + Gem1Info.AffinityWater +
                             Gem2Info.AffinityWater + Gem3Info.AffinityWater;
  INT16 AffinityLightTotal = BladeInfo.AffinityLight + Gem1Info.AffinityLight +
                             Gem2Info.AffinityLight + Gem3Info.AffinityLight;
  INT16 AffinityDarkTotal = BladeInfo.AffinityDark + Gem1Info.AffinityDark +
                            Gem2Info.AffinityDark + Gem3Info.AffinityDark;

  // Class
  fprintf(fpWeaponInfo, "CLASS\n");
  fprintf(fpWeaponInfo, "=============\n");
  fprintf(fpWeaponInfo, "Human:    %3i\n", ClassHumanTotal);
  fprintf(fpWeaponInfo, "Beast:    %3i\n", ClassBeastTotal);
  fprintf(fpWeaponInfo, "Undead:   %3i\n", ClassUndeadTotal);
  fprintf(fpWeaponInfo, "Phantom:  %3i\n", ClassPhantomTotal);
  fprintf(fpWeaponInfo, "Dragon:   %3i\n", ClassDragonTotal);
  fprintf(fpWeaponInfo, "Evil:     %3i\n", ClassEvilTotal);
  fprintf(fpWeaponInfo, "\n");

  // Affinity
  fprintf(fpWeaponInfo, "AFFINITY\n");
  fprintf(fpWeaponInfo, "=============\n");
  fprintf(fpWeaponInfo, "Physical: %3i\n", AffinityPhysicalTotal);
  fprintf(fpWeaponInfo, "Air:      %3i\n", AffinityAirTotal);
  fprintf(fpWeaponInfo, "Fire:     %3i\n", AffinityFireTotal);
  fprintf(fpWeaponInfo, "Earth:    %3i\n", AffinityEarthTotal);
  fprintf(fpWeaponInfo, "Water:    %3i\n", AffinityWaterTotal);
  fprintf(fpWeaponInfo, "Light:    %3i\n", AffinityLightTotal);
  fprintf(fpWeaponInfo, "Dark:     %3i\n", AffinityDarkTotal);

  fclose(fpWeaponInfo);
}

void
WriteShieldInfo(DWORD processID)
{
  equip_item_info ShieldInfo;
  equip_item_info Gem1Info;
  equip_item_info Gem2Info;
  equip_item_info Gem3Info;

  SIZE_T BytesToRead = sizeof(equip_item_info);
  DWORD BytesRead;

  BytesRead = ReadGameMemory(
      processID, OFFSET_EQUIPPED_SHIELD, BytesToRead, &ShieldInfo);
  BytesRead = ReadGameMemory(
      processID, OFFSET_EQUIPPED_SHIELD_GEM_SLOT1, BytesToRead, &Gem1Info);
  BytesRead = ReadGameMemory(
      processID, OFFSET_EQUIPPED_SHIELD_GEM_SLOT2, BytesToRead, &Gem2Info);
  BytesRead = ReadGameMemory(
      processID, OFFSET_EQUIPPED_SHIELD_GEM_SLOT3, BytesToRead, &Gem3Info);

  FILE *fpShieldInfoExt = fopen("game_stats/shield-full.txt", "w");

  // Check if shield is eqipped. If not, write the warning and skip the rest.
  if (ShieldInfo.ListPosition == 0)
  {
    fprintf(fpShieldInfoExt, "Shield not equipped!\n");
    fclose(fpShieldInfoExt);

    return;
  }

  fprintf(fpShieldInfoExt, "Shield Stats\n\n");

  fprintf(fpShieldInfoExt, "Name: %s\n", ArmoursList[ShieldInfo.ListPosition]);
  fprintf(fpShieldInfoExt, "Material: %s\n",
      CraftingMaterials[ShieldInfo.Material]);

  fprintf(fpShieldInfoExt, "\n");

  // Bonuses
  INT16 STR_BonusTotal = ShieldInfo.STR_Bonus + Gem1Info.STR_Bonus +
                         Gem2Info.STR_Bonus + Gem3Info.STR_Bonus;
  INT16 INT_BonusTotal = ShieldInfo.INT_Bonus + Gem1Info.INT_Bonus +
                         Gem2Info.INT_Bonus + Gem3Info.INT_Bonus;
  INT16 AGL_BonusTotal = ShieldInfo.AGL_Bonus + Gem1Info.AGL_Bonus +
                         Gem2Info.AGL_Bonus + Gem3Info.AGL_Bonus;

  fprintf(fpShieldInfoExt, "BONUSES\n");
  fprintf(fpShieldInfoExt, "========\n");
  fprintf(fpShieldInfoExt, "STR: %3i\n", STR_BonusTotal);
  fprintf(fpShieldInfoExt, "INT: %3i\n", INT_BonusTotal);
  fprintf(fpShieldInfoExt, "AGL: %3i\n", AGL_BonusTotal);
  fprintf(fpShieldInfoExt, "\n");

  // DP & PP
  fprintf(fpShieldInfoExt, "DURABILITY\n");
  fprintf(fpShieldInfoExt, "===========\n");
  fprintf(fpShieldInfoExt, "DP: %3i/%3i\n",
      (ShieldInfo.DamagePoints + 99) / 100,
      (ShieldInfo.DamagePointsMax + 99) / 100);
  fprintf(fpShieldInfoExt, "PP: %3i/%3i\n", ShieldInfo.PhantomPoints,
      ShieldInfo.PhantomPointsMax);
  fprintf(fpShieldInfoExt, "\n");

  // Gems

  // Gems
  UINT8 GemSlots = ShieldInfo.GemSlots;
  if (GemSlots)
  {
    fprintf(fpShieldInfoExt, "GEMS\n");
    fprintf(fpShieldInfoExt, "=========================\n");

    fprintf(fpShieldInfoExt, "Slot 1: %17s\n", GemsList[Gem1Info.ListPosition]);

    if (GemSlots > 1)
    {
      fprintf(
          fpShieldInfoExt, "Slot 2: %17s\n", GemsList[Gem2Info.ListPosition]);
    }
    if (GemSlots > 2)
    {
      fprintf(
          fpShieldInfoExt, "Slot 3: %17s\n", GemsList[Gem3Info.ListPosition]);
    }
  }
  fprintf(fpShieldInfoExt, "\n");

  // Type
  fprintf(fpShieldInfoExt, "TYPE\n");
  fprintf(fpShieldInfoExt, "============\n");
  fprintf(fpShieldInfoExt, "Blunt:    %2i\n", ShieldInfo.TypeBlunt);
  fprintf(fpShieldInfoExt, "Edged:    %2i\n", ShieldInfo.TypeEdged);
  fprintf(fpShieldInfoExt, "Piercing: %2i\n", ShieldInfo.TypePiercing);
  fprintf(fpShieldInfoExt, "\n");

  // Class summary
  INT16 ClassHumanTotal = ShieldInfo.ClassHuman + Gem1Info.ClassHuman +
                          Gem2Info.ClassHuman + Gem3Info.ClassHuman;
  INT16 ClassBeastTotal = ShieldInfo.ClassBeast + Gem1Info.ClassBeast +
                          Gem2Info.ClassBeast + Gem3Info.ClassBeast;
  INT16 ClassUndeadTotal = ShieldInfo.ClassUndead + Gem1Info.ClassUndead +
                           Gem2Info.ClassUndead + Gem3Info.ClassUndead;
  INT16 ClassPhantomTotal = ShieldInfo.ClassPhantom + Gem1Info.ClassPhantom +
                            Gem2Info.ClassPhantom + Gem3Info.ClassPhantom;
  INT16 ClassDragonTotal = ShieldInfo.ClassDragon + Gem1Info.ClassDragon +
                           Gem2Info.ClassDragon + Gem3Info.ClassDragon;
  INT16 ClassEvilTotal = ShieldInfo.ClassEvil + Gem1Info.ClassEvil +
                         Gem2Info.ClassEvil + Gem3Info.ClassEvil;

  // Affinity summary
  INT16 AffinityPhysicalTotal =
      ShieldInfo.AffinityPhysical + Gem1Info.AffinityPhysical +
      Gem2Info.AffinityPhysical + Gem3Info.AffinityPhysical;
  INT16 AffinityAirTotal = ShieldInfo.AffinityAir + Gem1Info.AffinityAir +
                           Gem2Info.AffinityAir + Gem3Info.AffinityAir;
  INT16 AffinityFireTotal = ShieldInfo.AffinityFire + Gem1Info.AffinityFire +
                            Gem2Info.AffinityFire + Gem3Info.AffinityFire;
  INT16 AffinityEarthTotal = ShieldInfo.AffinityEarth + Gem1Info.AffinityEarth +
                             Gem2Info.AffinityEarth + Gem3Info.AffinityEarth;
  INT16 AffinityWaterTotal = ShieldInfo.AffinityWater + Gem1Info.AffinityWater +
                             Gem2Info.AffinityWater + Gem3Info.AffinityWater;
  INT16 AffinityLightTotal = ShieldInfo.AffinityLight + Gem1Info.AffinityLight +
                             Gem2Info.AffinityLight + Gem3Info.AffinityLight;
  INT16 AffinityDarkTotal = ShieldInfo.AffinityDark + Gem1Info.AffinityDark +
                            Gem2Info.AffinityDark + Gem3Info.AffinityDark;

  // Class
  fprintf(fpShieldInfoExt, "CLASS\n");
  fprintf(fpShieldInfoExt, "=============\n");
  fprintf(fpShieldInfoExt, "Human:    %3i\n", ClassHumanTotal);
  fprintf(fpShieldInfoExt, "Beast:    %3i\n", ClassBeastTotal);
  fprintf(fpShieldInfoExt, "Undead:   %3i\n", ClassUndeadTotal);
  fprintf(fpShieldInfoExt, "Phantom:  %3i\n", ClassPhantomTotal);
  fprintf(fpShieldInfoExt, "Dragon:   %3i\n", ClassDragonTotal);
  fprintf(fpShieldInfoExt, "Evil:     %3i\n", ClassEvilTotal);
  fprintf(fpShieldInfoExt, "\n");

  // Affinity
  fprintf(fpShieldInfoExt, "AFFINITY\n");
  fprintf(fpShieldInfoExt, "=============\n");
  fprintf(fpShieldInfoExt, "Physical: %3i\n", AffinityPhysicalTotal);
  fprintf(fpShieldInfoExt, "Air:      %3i\n", AffinityAirTotal);
  fprintf(fpShieldInfoExt, "Fire:     %3i\n", AffinityFireTotal);
  fprintf(fpShieldInfoExt, "Earth:    %3i\n", AffinityEarthTotal);
  fprintf(fpShieldInfoExt, "Water:    %3i\n", AffinityWaterTotal);
  fprintf(fpShieldInfoExt, "Light:    %3i\n", AffinityLightTotal);
  fprintf(fpShieldInfoExt, "Dark:     %3i\n", AffinityDarkTotal);

  fclose(fpShieldInfoExt);
}

void
WriteShieldInfoShort(DWORD processID)
{
  equip_item_info ShieldInfo;

  SIZE_T BytesToRead = sizeof(equip_item_info);
  DWORD BytesRead;

  BytesRead = ReadGameMemory(
      processID, OFFSET_EQUIPPED_SHIELD, BytesToRead, &ShieldInfo);

  FILE *fpShieldInfoShort = fopen("game_stats/shield-short.txt", "w");

  // Check if shield is eqipped. If not, write the warning and skip the rest.
  if (ShieldInfo.ListPosition == 0)
  {
    fprintf(fpShieldInfoShort, "Shield not equipped!\n");
    fclose(fpShieldInfoShort);

    return;
  }

  fprintf(fpShieldInfoShort, "Shield Basic Stats\n\n");

  // Class
  fprintf(fpShieldInfoShort, "CLASS\n");
  fprintf(fpShieldInfoShort, "=============\n");
  fprintf(fpShieldInfoShort, "Human:    %3i\n", ShieldInfo.ClassHuman);
  fprintf(fpShieldInfoShort, "Beast:    %3i\n", ShieldInfo.ClassBeast);
  fprintf(fpShieldInfoShort, "Undead:   %3i\n", ShieldInfo.ClassUndead);
  fprintf(fpShieldInfoShort, "Phantom:  %3i\n", ShieldInfo.ClassPhantom);
  fprintf(fpShieldInfoShort, "Dragon:   %3i\n", ShieldInfo.ClassDragon);
  fprintf(fpShieldInfoShort, "Evil:     %3i\n", ShieldInfo.ClassEvil);
  fprintf(fpShieldInfoShort, "\n");

  // Affinity
  fprintf(fpShieldInfoShort, "AFFINITY\n");
  fprintf(fpShieldInfoShort, "=============\n");
  fprintf(fpShieldInfoShort, "Physical: %3i\n", ShieldInfo.AffinityPhysical);
  fprintf(fpShieldInfoShort, "Air:      %3i\n", ShieldInfo.AffinityAir);
  fprintf(fpShieldInfoShort, "Fire:     %3i\n", ShieldInfo.AffinityFire);
  fprintf(fpShieldInfoShort, "Earth:    %3i\n", ShieldInfo.AffinityEarth);
  fprintf(fpShieldInfoShort, "Water:    %3i\n", ShieldInfo.AffinityWater);
  fprintf(fpShieldInfoShort, "Light:    %3i\n", ShieldInfo.AffinityLight);
  fprintf(fpShieldInfoShort, "Dark:     %3i\n", ShieldInfo.AffinityDark);

  fclose(fpShieldInfoShort);
}

void
WriteGloveInfo(DWORD processID, int which_glove)
{
  equip_item_info GloveInfo;
  SIZE_T offset;

  SIZE_T BytesToRead = sizeof(equip_item_info);
  DWORD BytesRead;

  char FileName[64] = "";

  offset = which_glove ? OFFSET_EQUIPPED_LEFT_ARM : OFFSET_EQUIPPED_RIGHT_ARM;
  sprintf(FileName, "game_stats/armor-arm-%s-full.txt",
      which_glove ? "left" : "right");

  BytesRead = ReadGameMemory(processID, offset, BytesToRead, &GloveInfo);

  FILE *fpGloveInfoExt = fopen(FileName, "w");

  // Check if a glove is eqipped. If not, write the warning and skip the rest.
  if (GloveInfo.ListPosition == 0)
  {
    fprintf(fpGloveInfoExt, "No %s glove equipped!\n",
        which_glove ? "left" : "right");
    fclose(fpGloveInfoExt);

    return;
  }

  fprintf(fpGloveInfoExt, "%s Glove Stats\n\n", which_glove ? "Left" : "Right");

  fprintf(fpGloveInfoExt, "Name: %s\n", ArmoursList[GloveInfo.ListPosition]);
  fprintf(
      fpGloveInfoExt, "Material: %s\n", CraftingMaterials[GloveInfo.Material]);
  fprintf(fpGloveInfoExt, "\n");

  // Bonuses
  fprintf(fpGloveInfoExt, "BONUSES\n");
  fprintf(fpGloveInfoExt, "========\n");
  fprintf(fpGloveInfoExt, "STR: %3i\n", GloveInfo.STR_Bonus);
  fprintf(fpGloveInfoExt, "INT: %3i\n", GloveInfo.INT_Bonus);
  fprintf(fpGloveInfoExt, "AGL: %3i\n", GloveInfo.AGL_Bonus);
  fprintf(fpGloveInfoExt, "\n");

  // DP
  fprintf(fpGloveInfoExt, "DURABILITY\n");
  fprintf(fpGloveInfoExt, "===========\n");
  fprintf(fpGloveInfoExt, "DP: %3i/%3i\n", (GloveInfo.DamagePoints + 99) / 100,
      (GloveInfo.DamagePointsMax + 99) / 100);
  fprintf(fpGloveInfoExt, "\n");

  // Type
  fprintf(fpGloveInfoExt, "TYPE\n");
  fprintf(fpGloveInfoExt, "============\n");
  fprintf(fpGloveInfoExt, "Blunt:    %2i\n", GloveInfo.TypeBlunt);
  fprintf(fpGloveInfoExt, "Edged:    %2i\n", GloveInfo.TypeEdged);
  fprintf(fpGloveInfoExt, "Piercing: %2i\n", GloveInfo.TypePiercing);
  fprintf(fpGloveInfoExt, "\n");

  // Class
  fprintf(fpGloveInfoExt, "CLASS\n");
  fprintf(fpGloveInfoExt, "=============\n");
  fprintf(fpGloveInfoExt, "Human:    %3i\n", GloveInfo.ClassHuman);
  fprintf(fpGloveInfoExt, "Beast:    %3i\n", GloveInfo.ClassBeast);
  fprintf(fpGloveInfoExt, "Undead:   %3i\n", GloveInfo.ClassUndead);
  fprintf(fpGloveInfoExt, "Phantom:  %3i\n", GloveInfo.ClassPhantom);
  fprintf(fpGloveInfoExt, "Dragon:   %3i\n", GloveInfo.ClassDragon);
  fprintf(fpGloveInfoExt, "Evil:     %3i\n", GloveInfo.ClassEvil);
  fprintf(fpGloveInfoExt, "\n");

  // Affinity
  fprintf(fpGloveInfoExt, "AFFINITY\n");
  fprintf(fpGloveInfoExt, "=============\n");
  fprintf(fpGloveInfoExt, "Physical: %3i\n", GloveInfo.AffinityPhysical);
  fprintf(fpGloveInfoExt, "Air:      %3i\n", GloveInfo.AffinityAir);
  fprintf(fpGloveInfoExt, "Fire:     %3i\n", GloveInfo.AffinityFire);
  fprintf(fpGloveInfoExt, "Earth:    %3i\n", GloveInfo.AffinityEarth);
  fprintf(fpGloveInfoExt, "Water:    %3i\n", GloveInfo.AffinityWater);
  fprintf(fpGloveInfoExt, "Light:    %3i\n", GloveInfo.AffinityLight);
  fprintf(fpGloveInfoExt, "Dark:     %3i\n", GloveInfo.AffinityDark);

  fclose(fpGloveInfoExt);
}

void
WriteGloveInfoShort(DWORD processID, int which_glove)
{
  equip_item_info GloveInfo;
  SIZE_T offset;

  SIZE_T BytesToRead = sizeof(equip_item_info);
  DWORD BytesRead;

  char FileName[64] = "";

  offset = which_glove ? OFFSET_EQUIPPED_LEFT_ARM : OFFSET_EQUIPPED_RIGHT_ARM;
  sprintf(FileName, "game_stats/armor-arm-%s-short.txt",
      which_glove ? "left" : "right");

  BytesRead = ReadGameMemory(processID, offset, BytesToRead, &GloveInfo);

  FILE *fpGloveInfoShort = fopen(FileName, "w");

  // Check if a glove is eqipped. If not, write the warning and skip the rest.
  if (GloveInfo.ListPosition == 0)
  {
    fprintf(fpGloveInfoShort, "No %s glove equipped!\n",
        which_glove ? "left" : "right");
    fclose(fpGloveInfoShort);

    return;
  }

  fprintf(fpGloveInfoShort, "%s Glove Basic Stats\n\n",
      which_glove ? "Left" : "Right");

  // Class
  fprintf(fpGloveInfoShort, "CLASS\n");
  fprintf(fpGloveInfoShort, "=============\n");
  fprintf(fpGloveInfoShort, "Human:    %3i\n", GloveInfo.ClassHuman);
  fprintf(fpGloveInfoShort, "Beast:    %3i\n", GloveInfo.ClassBeast);
  fprintf(fpGloveInfoShort, "Undead:   %3i\n", GloveInfo.ClassUndead);
  fprintf(fpGloveInfoShort, "Phantom:  %3i\n", GloveInfo.ClassPhantom);
  fprintf(fpGloveInfoShort, "Dragon:   %3i\n", GloveInfo.ClassDragon);
  fprintf(fpGloveInfoShort, "Evil:     %3i\n", GloveInfo.ClassEvil);
  fprintf(fpGloveInfoShort, "\n");

  // Affinity
  fprintf(fpGloveInfoShort, "AFFINITY\n");
  fprintf(fpGloveInfoShort, "=============\n");
  fprintf(fpGloveInfoShort, "Physical: %3i\n", GloveInfo.AffinityPhysical);
  fprintf(fpGloveInfoShort, "Air:      %3i\n", GloveInfo.AffinityAir);
  fprintf(fpGloveInfoShort, "Fire:     %3i\n", GloveInfo.AffinityFire);
  fprintf(fpGloveInfoShort, "Earth:    %3i\n", GloveInfo.AffinityEarth);
  fprintf(fpGloveInfoShort, "Water:    %3i\n", GloveInfo.AffinityWater);
  fprintf(fpGloveInfoShort, "Light:    %3i\n", GloveInfo.AffinityLight);
  fprintf(fpGloveInfoShort, "Dark:     %3i\n", GloveInfo.AffinityDark);

  fclose(fpGloveInfoShort);
}

void
WriteHeadArmorInfo(DWORD processID)
{
  equip_item_info HeadInfo;
  SIZE_T BytesToRead = sizeof(equip_item_info);
  DWORD BytesRead;

  BytesRead =
      ReadGameMemory(processID, OFFSET_EQUIPPED_HEAD, BytesToRead, &HeadInfo);

  FILE *fpHeadInfoExt = fopen("game_stats/armor-head-full.txt", "w");

  // Check if a head armor is eqipped.
  // If not, write the warning and skip the rest.
  if (HeadInfo.ListPosition == 0)
  {
    fprintf(fpHeadInfoExt, "No head armor equipped!\n");
    fclose(fpHeadInfoExt);

    return;
  }

  fprintf(fpHeadInfoExt, "Helm Stats\n\n");

  fprintf(fpHeadInfoExt, "Name: %s\n", ArmoursList[HeadInfo.ListPosition]);
  fprintf(
      fpHeadInfoExt, "Material: %s\n", CraftingMaterials[HeadInfo.Material]);
  fprintf(fpHeadInfoExt, "\n");

  // Bonuses
  fprintf(fpHeadInfoExt, "BONUSES\n");
  fprintf(fpHeadInfoExt, "========\n");
  fprintf(fpHeadInfoExt, "STR: %3i\n", HeadInfo.STR_Bonus);
  fprintf(fpHeadInfoExt, "INT: %3i\n", HeadInfo.INT_Bonus);
  fprintf(fpHeadInfoExt, "AGL: %3i\n", HeadInfo.AGL_Bonus);
  fprintf(fpHeadInfoExt, "\n");

  // DP
  fprintf(fpHeadInfoExt, "DURABILITY\n");
  fprintf(fpHeadInfoExt, "===========\n");
  fprintf(fpHeadInfoExt, "DP: %3i/%3i\n", (HeadInfo.DamagePoints + 99) / 100,
      (HeadInfo.DamagePointsMax + 99) / 100);
  fprintf(fpHeadInfoExt, "\n");

  // Type
  fprintf(fpHeadInfoExt, "TYPE\n");
  fprintf(fpHeadInfoExt, "============\n");
  fprintf(fpHeadInfoExt, "Blunt:    %2i\n", HeadInfo.TypeBlunt);
  fprintf(fpHeadInfoExt, "Edged:    %2i\n", HeadInfo.TypeEdged);
  fprintf(fpHeadInfoExt, "Piercing: %2i\n", HeadInfo.TypePiercing);
  fprintf(fpHeadInfoExt, "\n");

  // Class
  fprintf(fpHeadInfoExt, "CLASS\n");
  fprintf(fpHeadInfoExt, "=============\n");
  fprintf(fpHeadInfoExt, "Human:    %3i\n", HeadInfo.ClassHuman);
  fprintf(fpHeadInfoExt, "Beast:    %3i\n", HeadInfo.ClassBeast);
  fprintf(fpHeadInfoExt, "Undead:   %3i\n", HeadInfo.ClassUndead);
  fprintf(fpHeadInfoExt, "Phantom:  %3i\n", HeadInfo.ClassPhantom);
  fprintf(fpHeadInfoExt, "Dragon:   %3i\n", HeadInfo.ClassDragon);
  fprintf(fpHeadInfoExt, "Evil:     %3i\n", HeadInfo.ClassEvil);
  fprintf(fpHeadInfoExt, "\n");

  // Affinity
  fprintf(fpHeadInfoExt, "AFFINITY\n");
  fprintf(fpHeadInfoExt, "=============\n");
  fprintf(fpHeadInfoExt, "Physical: %3i\n", HeadInfo.AffinityPhysical);
  fprintf(fpHeadInfoExt, "Air:      %3i\n", HeadInfo.AffinityAir);
  fprintf(fpHeadInfoExt, "Fire:     %3i\n", HeadInfo.AffinityFire);
  fprintf(fpHeadInfoExt, "Earth:    %3i\n", HeadInfo.AffinityEarth);
  fprintf(fpHeadInfoExt, "Water:    %3i\n", HeadInfo.AffinityWater);
  fprintf(fpHeadInfoExt, "Light:    %3i\n", HeadInfo.AffinityLight);
  fprintf(fpHeadInfoExt, "Dark:     %3i\n", HeadInfo.AffinityDark);

  fclose(fpHeadInfoExt);
}

void
WriteHeadArmorInfoShort(DWORD processID)
{
  equip_item_info HeadInfo;
  SIZE_T BytesToRead = sizeof(equip_item_info);
  DWORD BytesRead;

  BytesRead =
      ReadGameMemory(processID, OFFSET_EQUIPPED_HEAD, BytesToRead, &HeadInfo);

  FILE *fpHeadInfoShort = fopen("game_stats/armor-head-short.txt", "w");

  // Check if a head armor is eqipped.
  // If not, write the warning and skip the rest.
  if (HeadInfo.ListPosition == 0)
  {
    fprintf(fpHeadInfoShort, "No head armor equipped!\n");
    fclose(fpHeadInfoShort);

    return;
  }

  fprintf(fpHeadInfoShort, "Helm Basic Stats\n\n");

  // Class
  fprintf(fpHeadInfoShort, "CLASS\n");
  fprintf(fpHeadInfoShort, "=============\n");
  fprintf(fpHeadInfoShort, "Human:    %3i\n", HeadInfo.ClassHuman);
  fprintf(fpHeadInfoShort, "Beast:    %3i\n", HeadInfo.ClassBeast);
  fprintf(fpHeadInfoShort, "Undead:   %3i\n", HeadInfo.ClassUndead);
  fprintf(fpHeadInfoShort, "Phantom:  %3i\n", HeadInfo.ClassPhantom);
  fprintf(fpHeadInfoShort, "Dragon:   %3i\n", HeadInfo.ClassDragon);
  fprintf(fpHeadInfoShort, "Evil:     %3i\n", HeadInfo.ClassEvil);
  fprintf(fpHeadInfoShort, "\n");

  // Affinity
  fprintf(fpHeadInfoShort, "AFFINITY\n");
  fprintf(fpHeadInfoShort, "=============\n");
  fprintf(fpHeadInfoShort, "Physical: %3i\n", HeadInfo.AffinityPhysical);
  fprintf(fpHeadInfoShort, "Air:      %3i\n", HeadInfo.AffinityAir);
  fprintf(fpHeadInfoShort, "Fire:     %3i\n", HeadInfo.AffinityFire);
  fprintf(fpHeadInfoShort, "Earth:    %3i\n", HeadInfo.AffinityEarth);
  fprintf(fpHeadInfoShort, "Water:    %3i\n", HeadInfo.AffinityWater);
  fprintf(fpHeadInfoShort, "Light:    %3i\n", HeadInfo.AffinityLight);
  fprintf(fpHeadInfoShort, "Dark:     %3i\n", HeadInfo.AffinityDark);

  fclose(fpHeadInfoShort);
}

void
WriteBodyArmorInfo(DWORD processID)
{
  equip_item_info BodyInfo;
  SIZE_T BytesToRead = sizeof(equip_item_info);
  DWORD BytesRead;

  BytesRead =
      ReadGameMemory(processID, OFFSET_EQUIPPED_BODY, BytesToRead, &BodyInfo);

  FILE *fpBodyInfoExt = fopen("game_stats/armor-body-full.txt", "w");

  // Check if a body armor is eqipped. If not, write the warning and skip the
  // rest.
  if (BodyInfo.ListPosition == 0)
  {
    // fprintf(fpBodyInfoExt, "No body armor equipped!\n");
    fprintf(fpBodyInfoExt, "No Breastplate Equipped!\n");
    fclose(fpBodyInfoExt);

    return;
  }

  fprintf(fpBodyInfoExt, "Body Armor Stats\n\n");

  fprintf(fpBodyInfoExt, "Name: %s\n", ArmoursList[BodyInfo.ListPosition]);
  fprintf(
      fpBodyInfoExt, "Material: %s\n", CraftingMaterials[BodyInfo.Material]);
  fprintf(fpBodyInfoExt, "\n");

  // Bonuses
  fprintf(fpBodyInfoExt, "BONUSES\n");
  fprintf(fpBodyInfoExt, "========\n");
  fprintf(fpBodyInfoExt, "STR: %3i\n", BodyInfo.STR_Bonus);
  fprintf(fpBodyInfoExt, "INT: %3i\n", BodyInfo.INT_Bonus);
  fprintf(fpBodyInfoExt, "AGL: %3i\n", BodyInfo.AGL_Bonus);
  fprintf(fpBodyInfoExt, "\n");

  // DP
  fprintf(fpBodyInfoExt, "DURABILITY\n");
  fprintf(fpBodyInfoExt, "===========\n");
  fprintf(fpBodyInfoExt, "DP: %3i/%3i\n", (BodyInfo.DamagePoints + 99) / 100,
      (BodyInfo.DamagePointsMax + 99) / 100);
  fprintf(fpBodyInfoExt, "\n");

  // Type
  fprintf(fpBodyInfoExt, "TYPE\n");
  fprintf(fpBodyInfoExt, "============\n");
  fprintf(fpBodyInfoExt, "Blunt:    %2i\n", BodyInfo.TypeBlunt);
  fprintf(fpBodyInfoExt, "Edged:    %2i\n", BodyInfo.TypeEdged);
  fprintf(fpBodyInfoExt, "Piercing: %2i\n", BodyInfo.TypePiercing);
  fprintf(fpBodyInfoExt, "\n");

  // Class
  fprintf(fpBodyInfoExt, "CLASS\n");
  fprintf(fpBodyInfoExt, "=============\n");
  fprintf(fpBodyInfoExt, "Human:    %3i\n", BodyInfo.ClassHuman);
  fprintf(fpBodyInfoExt, "Beast:    %3i\n", BodyInfo.ClassBeast);
  fprintf(fpBodyInfoExt, "Undead:   %3i\n", BodyInfo.ClassUndead);
  fprintf(fpBodyInfoExt, "Phantom:  %3i\n", BodyInfo.ClassPhantom);
  fprintf(fpBodyInfoExt, "Dragon:   %3i\n", BodyInfo.ClassDragon);
  fprintf(fpBodyInfoExt, "Evil:     %3i\n", BodyInfo.ClassEvil);
  fprintf(fpBodyInfoExt, "\n");

  // Affinity
  fprintf(fpBodyInfoExt, "AFFINITY\n");
  fprintf(fpBodyInfoExt, "=============\n");
  fprintf(fpBodyInfoExt, "Physical: %3i\n", BodyInfo.AffinityPhysical);
  fprintf(fpBodyInfoExt, "Air:      %3i\n", BodyInfo.AffinityAir);
  fprintf(fpBodyInfoExt, "Fire:     %3i\n", BodyInfo.AffinityFire);
  fprintf(fpBodyInfoExt, "Earth:    %3i\n", BodyInfo.AffinityEarth);
  fprintf(fpBodyInfoExt, "Water:    %3i\n", BodyInfo.AffinityWater);
  fprintf(fpBodyInfoExt, "Light:    %3i\n", BodyInfo.AffinityLight);
  fprintf(fpBodyInfoExt, "Dark:     %3i\n", BodyInfo.AffinityDark);

  fclose(fpBodyInfoExt);
}

void
WriteBodyArmorInfoShort(DWORD processID)
{
  equip_item_info BodyInfo;
  SIZE_T BytesToRead = sizeof(equip_item_info);
  DWORD BytesRead;

  BytesRead =
      ReadGameMemory(processID, OFFSET_EQUIPPED_BODY, BytesToRead, &BodyInfo);

  FILE *fpBodyInfoShort = fopen("game_stats/armor-body-short.txt", "w");

  // Check if a body armor is eqipped. If not, write the warning and skip the
  // rest.
  if (BodyInfo.ListPosition == 0)
  {
    // fprintf(fpBodyInfoShort, "No body armor equipped!\n");
    fprintf(fpBodyInfoShort, "No Breastplate Equipped!\n");
    fclose(fpBodyInfoShort);

    return;
  }

  fprintf(fpBodyInfoShort, "Body Armor Basic Stats\n\n");

  // Class
  fprintf(fpBodyInfoShort, "CLASS\n");
  fprintf(fpBodyInfoShort, "=============\n");
  fprintf(fpBodyInfoShort, "Human:    %3i\n", BodyInfo.ClassHuman);
  fprintf(fpBodyInfoShort, "Beast:    %3i\n", BodyInfo.ClassBeast);
  fprintf(fpBodyInfoShort, "Undead:   %3i\n", BodyInfo.ClassUndead);
  fprintf(fpBodyInfoShort, "Phantom:  %3i\n", BodyInfo.ClassPhantom);
  fprintf(fpBodyInfoShort, "Dragon:   %3i\n", BodyInfo.ClassDragon);
  fprintf(fpBodyInfoShort, "Evil:     %3i\n", BodyInfo.ClassEvil);
  fprintf(fpBodyInfoShort, "\n");

  // Affinity
  fprintf(fpBodyInfoShort, "AFFINITY\n");
  fprintf(fpBodyInfoShort, "=============\n");
  fprintf(fpBodyInfoShort, "Physical: %3i\n", BodyInfo.AffinityPhysical);
  fprintf(fpBodyInfoShort, "Air:      %3i\n", BodyInfo.AffinityAir);
  fprintf(fpBodyInfoShort, "Fire:     %3i\n", BodyInfo.AffinityFire);
  fprintf(fpBodyInfoShort, "Earth:    %3i\n", BodyInfo.AffinityEarth);
  fprintf(fpBodyInfoShort, "Water:    %3i\n", BodyInfo.AffinityWater);
  fprintf(fpBodyInfoShort, "Light:    %3i\n", BodyInfo.AffinityLight);
  fprintf(fpBodyInfoShort, "Dark:     %3i\n", BodyInfo.AffinityDark);

  fclose(fpBodyInfoShort);
}

void
WriteLegsArmorInfo(DWORD processID)
{
  equip_item_info LegsInfo;
  SIZE_T BytesToRead = sizeof(equip_item_info);
  DWORD BytesRead;

  BytesRead =
      ReadGameMemory(processID, OFFSET_EQUIPPED_LEGS, BytesToRead, &LegsInfo);

  FILE *fpLegsInfoExt = fopen("game_stats/armor-legs-full.txt", "w");

  // Check if a leg armor is eqipped.
  // If not, write the warning and skip the rest.
  if (LegsInfo.ListPosition == 0)
  {
    fprintf(fpLegsInfoExt, "No legs armor equipped!\n");
    fclose(fpLegsInfoExt);

    return;
  }

  fprintf(fpLegsInfoExt, "Leggings Stats\n\n");

  fprintf(fpLegsInfoExt, "Name: %s\n", ArmoursList[LegsInfo.ListPosition]);
  fprintf(
      fpLegsInfoExt, "Material: %s\n", CraftingMaterials[LegsInfo.Material]);
  fprintf(fpLegsInfoExt, "\n");

  // Bonuses
  fprintf(fpLegsInfoExt, "BONUSES\n");
  fprintf(fpLegsInfoExt, "========\n");
  fprintf(fpLegsInfoExt, "STR: %3i\n", LegsInfo.STR_Bonus);
  fprintf(fpLegsInfoExt, "INT: %3i\n", LegsInfo.INT_Bonus);
  fprintf(fpLegsInfoExt, "AGL: %3i\n", LegsInfo.AGL_Bonus);
  fprintf(fpLegsInfoExt, "\n");

  // DP
  fprintf(fpLegsInfoExt, "DURABILITY\n");
  fprintf(fpLegsInfoExt, "===========\n");
  fprintf(fpLegsInfoExt, "DP: %3i/%3i\n", (LegsInfo.DamagePoints + 99) / 100,
      (LegsInfo.DamagePointsMax + 99) / 100);
  fprintf(fpLegsInfoExt, "\n");

  // Type
  fprintf(fpLegsInfoExt, "TYPE\n");
  fprintf(fpLegsInfoExt, "============\n");
  fprintf(fpLegsInfoExt, "Blunt:    %2i\n", LegsInfo.TypeBlunt);
  fprintf(fpLegsInfoExt, "Edged:    %2i\n", LegsInfo.TypeEdged);
  fprintf(fpLegsInfoExt, "Piercing: %2i\n", LegsInfo.TypePiercing);
  fprintf(fpLegsInfoExt, "\n");

  // Class
  fprintf(fpLegsInfoExt, "CLASS\n");
  fprintf(fpLegsInfoExt, "=============\n");
  fprintf(fpLegsInfoExt, "Human:    %3i\n", LegsInfo.ClassHuman);
  fprintf(fpLegsInfoExt, "Beast:    %3i\n", LegsInfo.ClassBeast);
  fprintf(fpLegsInfoExt, "Undead:   %3i\n", LegsInfo.ClassUndead);
  fprintf(fpLegsInfoExt, "Phantom:  %3i\n", LegsInfo.ClassPhantom);
  fprintf(fpLegsInfoExt, "Dragon:   %3i\n", LegsInfo.ClassDragon);
  fprintf(fpLegsInfoExt, "Evil:     %3i\n", LegsInfo.ClassEvil);
  fprintf(fpLegsInfoExt, "\n");

  // Affinity
  fprintf(fpLegsInfoExt, "AFFINITY\n");
  fprintf(fpLegsInfoExt, "=============\n");
  fprintf(fpLegsInfoExt, "Physical: %3i\n", LegsInfo.AffinityPhysical);
  fprintf(fpLegsInfoExt, "Air:      %3i\n", LegsInfo.AffinityAir);
  fprintf(fpLegsInfoExt, "Fire:     %3i\n", LegsInfo.AffinityFire);
  fprintf(fpLegsInfoExt, "Earth:    %3i\n", LegsInfo.AffinityEarth);
  fprintf(fpLegsInfoExt, "Water:    %3i\n", LegsInfo.AffinityWater);
  fprintf(fpLegsInfoExt, "Light:    %3i\n", LegsInfo.AffinityLight);
  fprintf(fpLegsInfoExt, "Dark:     %3i\n", LegsInfo.AffinityDark);

  fclose(fpLegsInfoExt);
}

void
WriteLegsArmorInfoShort(DWORD processID)
{
  equip_item_info LegsInfo;
  SIZE_T BytesToRead = sizeof(equip_item_info);
  DWORD BytesRead;

  BytesRead =
      ReadGameMemory(processID, OFFSET_EQUIPPED_LEGS, BytesToRead, &LegsInfo);

  FILE *fpLegsInfoShort = fopen("game_stats/armor-legs-short.txt", "w");

  // Check if a leg armor is eqipped.
  // If not, write the warning and skip the rest.
  if (LegsInfo.ListPosition == 0)
  {
    fprintf(fpLegsInfoShort, "No legs armor equipped!\n");
    fclose(fpLegsInfoShort);

    return;
  }

  fprintf(fpLegsInfoShort, "Leggings Basic Stats\n\n");

  // Class
  fprintf(fpLegsInfoShort, "CLASS\n");
  fprintf(fpLegsInfoShort, "=============\n");
  fprintf(fpLegsInfoShort, "Human:    %3i\n", LegsInfo.ClassHuman);
  fprintf(fpLegsInfoShort, "Beast:    %3i\n", LegsInfo.ClassBeast);
  fprintf(fpLegsInfoShort, "Undead:   %3i\n", LegsInfo.ClassUndead);
  fprintf(fpLegsInfoShort, "Phantom:  %3i\n", LegsInfo.ClassPhantom);
  fprintf(fpLegsInfoShort, "Dragon:   %3i\n", LegsInfo.ClassDragon);
  fprintf(fpLegsInfoShort, "Evil:     %3i\n", LegsInfo.ClassEvil);
  fprintf(fpLegsInfoShort, "\n");

  // Affinity
  fprintf(fpLegsInfoShort, "AFFINITY\n");
  fprintf(fpLegsInfoShort, "=============\n");
  fprintf(fpLegsInfoShort, "Physical: %3i\n", LegsInfo.AffinityPhysical);
  fprintf(fpLegsInfoShort, "Air:      %3i\n", LegsInfo.AffinityAir);
  fprintf(fpLegsInfoShort, "Fire:     %3i\n", LegsInfo.AffinityFire);
  fprintf(fpLegsInfoShort, "Earth:    %3i\n", LegsInfo.AffinityEarth);
  fprintf(fpLegsInfoShort, "Water:    %3i\n", LegsInfo.AffinityWater);
  fprintf(fpLegsInfoShort, "Light:    %3i\n", LegsInfo.AffinityLight);
  fprintf(fpLegsInfoShort, "Dark:     %3i\n", LegsInfo.AffinityDark);

  fclose(fpLegsInfoShort);
}

void
WriteNecklaceInfo(DWORD processID)
{
  equip_item_info NeckInfo;
  SIZE_T BytesToRead = sizeof(equip_item_info);
  DWORD BytesRead;

  BytesRead =
      ReadGameMemory(processID, OFFSET_EQUIPPED_NECK, BytesToRead, &NeckInfo);

  FILE *fpNeckInfoExt = fopen("game_stats/accessory.txt", "w");

  // Check if a necklace is eqipped.
  // If not, write the warning and skip the rest.
  if (NeckInfo.ListPosition == 0)
  {
    fprintf(fpNeckInfoExt, "No necklace equipped!\n");
    fclose(fpNeckInfoExt);

    return;
  }

  fprintf(fpNeckInfoExt, "Necklace Stats\n\n");

  fprintf(
      fpNeckInfoExt, "Name: %s\n", ItemNamesList[NeckInfo.NamesListPosition]);
  fprintf(fpNeckInfoExt, "\n");

  // Bonuses
  fprintf(fpNeckInfoExt, "BONUSES\n");
  fprintf(fpNeckInfoExt, "========\n");
  fprintf(fpNeckInfoExt, "STR: %3i\n", NeckInfo.STR_Bonus);
  fprintf(fpNeckInfoExt, "INT: %3i\n", NeckInfo.INT_Bonus);
  fprintf(fpNeckInfoExt, "AGL: %3i\n", NeckInfo.AGL_Bonus);
  fprintf(fpNeckInfoExt, "\n");

  // Type
  fprintf(fpNeckInfoExt, "TYPE\n");
  fprintf(fpNeckInfoExt, "============\n");
  fprintf(fpNeckInfoExt, "Blunt:    %2i\n", NeckInfo.TypeBlunt);
  fprintf(fpNeckInfoExt, "Edged:    %2i\n", NeckInfo.TypeEdged);
  fprintf(fpNeckInfoExt, "Piercing: %2i\n", NeckInfo.TypePiercing);
  fprintf(fpNeckInfoExt, "\n");

  // Class
  fprintf(fpNeckInfoExt, "CLASS\n");
  fprintf(fpNeckInfoExt, "=============\n");
  fprintf(fpNeckInfoExt, "Human:    %3i\n", NeckInfo.ClassHuman);
  fprintf(fpNeckInfoExt, "Beast:    %3i\n", NeckInfo.ClassBeast);
  fprintf(fpNeckInfoExt, "Undead:   %3i\n", NeckInfo.ClassUndead);
  fprintf(fpNeckInfoExt, "Phantom:  %3i\n", NeckInfo.ClassPhantom);
  fprintf(fpNeckInfoExt, "Dragon:   %3i\n", NeckInfo.ClassDragon);
  fprintf(fpNeckInfoExt, "Evil:     %3i\n", NeckInfo.ClassEvil);
  fprintf(fpNeckInfoExt, "\n");

  // Affinity
  fprintf(fpNeckInfoExt, "AFFINITY\n");
  fprintf(fpNeckInfoExt, "=============\n");
  fprintf(fpNeckInfoExt, "Physical: %3i\n", NeckInfo.AffinityPhysical);
  fprintf(fpNeckInfoExt, "Air:      %3i\n", NeckInfo.AffinityAir);
  fprintf(fpNeckInfoExt, "Fire:     %3i\n", NeckInfo.AffinityFire);
  fprintf(fpNeckInfoExt, "Earth:    %3i\n", NeckInfo.AffinityEarth);
  fprintf(fpNeckInfoExt, "Water:    %3i\n", NeckInfo.AffinityWater);
  fprintf(fpNeckInfoExt, "Light:    %3i\n", NeckInfo.AffinityLight);
  fprintf(fpNeckInfoExt, "Dark:     %3i\n", NeckInfo.AffinityDark);

  fclose(fpNeckInfoExt);
}

#endif
