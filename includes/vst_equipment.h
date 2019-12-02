#ifndef _VST_EQUIPMENT_H
#define _VST_EQUIPMENT_H

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

char *ArmorsList[81] = { "", "Buckler", "Pelta Shield", "Targe", "Quad Shield",
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

// The first element of this array should start at index 97 (0x61),
// so make adjustments in a funcions reading it.
char *AccessoriesList[31] = { "Rood Necklace", "Rune Earrings", "Lionhead",
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

char *ArmorsCategories[8] = { "", "Shield", "Helm", "Breast Armor", "Leggings",
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

#define LEVELING_FLAG_HUMAN 0x0001
#define LEVELING_FLAG_BEAST 0x0002
#define LEVELING_FLAG_UNDEAD 0x0004
#define LEVELING_FLAG_PHANTOM 0x0008
#define LEVELING_FLAG_DRAGON 0x0010
#define LEVELING_FLAG_EVIL 0x0020
#define LEVELING_FLAG_PHYSICAL 0x0040
#define LEVELING_FLAG_AIR 0x0080
#define LEVELING_FLAG_FIRE 0x0100
#define LEVELING_FLAG_EARTH 0x0200
#define LEVELING_FLAG_WATER 0x0400
#define LEVELING_FLAG_LIGHT 0x0800
#define LEVELING_FLAG_DARK 0x1000

void
ClearLevelingFlags()
{
  LevelingFlags.Flags.FlagsCompound = 0;
}

void
UpdateLevelingFlags()
{
  ClearLevelingFlags();

  i8 HumanCur = itemBladeCur.ClassHuman;
  i8 BeastCur = itemBladeCur.ClassBeast;
  i8 UndeadCur = itemBladeCur.ClassUndead;
  i8 PhantomCur = itemBladeCur.ClassPhantom;
  i8 DragonCur = itemBladeCur.ClassDragon;
  i8 EvilCur = itemBladeCur.ClassEvil;
  i8 PhysicalCur = itemBladeCur.AffinityPhysical;
  i8 AirCur = itemBladeCur.AffinityAir;
  i8 FireCur = itemBladeCur.AffinityFire;
  i8 EarthCur = itemBladeCur.AffinityEarth;
  i8 WaterCur = itemBladeCur.AffinityWater;
  i8 LightCur = itemBladeCur.AffinityLight;
  i8 DarkCur = itemBladeCur.AffinityDark;

  i8 HumanPrev = itemBladePrev.ClassHuman;
  i8 BeastPrev = itemBladePrev.ClassBeast;
  i8 UndeadPrev = itemBladePrev.ClassUndead;
  i8 PhantomPrev = itemBladePrev.ClassPhantom;
  i8 DragonPrev = itemBladePrev.ClassDragon;
  i8 EvilPrev = itemBladePrev.ClassEvil;
  i8 PhysicalPrev = itemBladePrev.AffinityPhysical;
  i8 AirPrev = itemBladePrev.AffinityAir;
  i8 FirePrev = itemBladePrev.AffinityFire;
  i8 EarthPrev = itemBladePrev.AffinityEarth;
  i8 WaterPrev = itemBladePrev.AffinityWater;
  i8 LightPrev = itemBladePrev.AffinityLight;
  i8 DarkPrev = itemBladePrev.AffinityDark;

  i8 HumanDiff = HumanCur - HumanPrev;
  i8 BeastDiff = BeastCur - BeastPrev;
  i8 UndeadDiff = UndeadCur - UndeadPrev;
  i8 PhantomDiff = PhantomCur - PhantomPrev;
  i8 DragonDiff = DragonCur - DragonPrev;
  i8 EvilDiff = EvilCur - EvilPrev;
  i8 PhysicalDiff = PhysicalCur - PhysicalPrev;
  i8 AirDiff = AirCur - AirPrev;
  i8 FireDiff = FireCur - FirePrev;
  i8 EarthDiff = EarthCur - EarthPrev;
  i8 WaterDiff = WaterCur - WaterPrev;
  i8 LightDiff = LightCur - LightPrev;
  i8 DarkDiff = DarkCur - DarkPrev;

  if (HumanDiff)
  {
    LevelingFlags.Flags.FlagsCompound |= LEVELING_FLAG_HUMAN;
  }
  if (BeastDiff)
  {
    LevelingFlags.Flags.FlagsCompound |= LEVELING_FLAG_BEAST;
  }
  if (UndeadDiff)
  {
    LevelingFlags.Flags.FlagsCompound |= LEVELING_FLAG_UNDEAD;
  }
  if (PhantomDiff)
  {
    LevelingFlags.Flags.FlagsCompound |= LEVELING_FLAG_PHANTOM;
  }
  if (DragonDiff)
  {
    LevelingFlags.Flags.FlagsCompound |= LEVELING_FLAG_DRAGON;
  }
  if (EvilDiff)
  {
    LevelingFlags.Flags.FlagsCompound |= LEVELING_FLAG_EVIL;
  }
  if (PhysicalDiff)
  {
    LevelingFlags.Flags.FlagsCompound |= LEVELING_FLAG_PHYSICAL;
  }
  if (AirDiff)
  {
    LevelingFlags.Flags.FlagsCompound |= LEVELING_FLAG_AIR;
  }
  if (FireDiff)
  {
    LevelingFlags.Flags.FlagsCompound |= LEVELING_FLAG_FIRE;
  }
  if (EarthDiff)
  {
    LevelingFlags.Flags.FlagsCompound |= LEVELING_FLAG_EARTH;
  }
  if (WaterDiff)
  {
    LevelingFlags.Flags.FlagsCompound |= LEVELING_FLAG_WATER;
  }
  if (LightDiff)
  {
    LevelingFlags.Flags.FlagsCompound |= LEVELING_FLAG_LIGHT;
  }
  if (DarkDiff)
  {
    LevelingFlags.Flags.FlagsCompound |= LEVELING_FLAG_DARK;
  }
}

void
ReadBladeData()
{
  usize BytesToRead = sizeof(item_data);
  usize BytesRead = ReadGameMemory(
      processID, OFFSET_EQUIPPED_WEAPON_BLADE, BytesToRead, &itemBladeCur);
}

void
ReadWeaponData()
{
  usize BytesToRead = sizeof(item_data);
  usize BytesRead;

  BytesRead = ReadGameMemory(
      processID, OFFSET_EQUIPPED_WEAPON_GRIP, BytesToRead, &itemGripCur);

  // Weapon gems
  BytesRead = ReadGameMemory(processID, OFFSET_EQUIPPED_WEAPON_GEM_SLOT1,
      BytesToRead, &itemGem1WeaponCur);
  BytesRead = ReadGameMemory(processID, OFFSET_EQUIPPED_WEAPON_GEM_SLOT2,
      BytesToRead, &itemGem2WeaponCur);
  BytesRead = ReadGameMemory(processID, OFFSET_EQUIPPED_WEAPON_GEM_SLOT3,
      BytesToRead, &itemGem3WeaponCur);
}

void
ReadShieldData()
{
  usize BytesToRead = sizeof(item_data);
  usize BytesRead;

  BytesRead = ReadGameMemory(
      processID, OFFSET_EQUIPPED_SHIELD, BytesToRead, &itemShieldCur);

  // Shield gems
  BytesRead = ReadGameMemory(processID, OFFSET_EQUIPPED_SHIELD_GEM_SLOT1,
      BytesToRead, &itemGem1ShieldCur);
  BytesRead = ReadGameMemory(processID, OFFSET_EQUIPPED_SHIELD_GEM_SLOT2,
      BytesToRead, &itemGem2ShieldCur);
  BytesRead = ReadGameMemory(processID, OFFSET_EQUIPPED_SHIELD_GEM_SLOT3,
      BytesToRead, &itemGem3ShieldCur);
}

void
ReadGlovesData()
{
  usize BytesToRead = sizeof(item_data);
  usize BytesRead;

  BytesRead = ReadGameMemory(
      processID, OFFSET_EQUIPPED_LEFT_ARM, BytesToRead, &itemGloveLeftCur);
  BytesRead = ReadGameMemory(
      processID, OFFSET_EQUIPPED_RIGHT_ARM, BytesToRead, &itemGloveRightCur);
}

void
ReadHeadData()
{
  usize BytesToRead = sizeof(item_data);
  usize BytesRead;

  BytesRead = ReadGameMemory(
      processID, OFFSET_EQUIPPED_HEAD, BytesToRead, &itemHeadCur);
}

void
ReadBodyData()
{
  usize BytesToRead = sizeof(item_data);
  usize BytesRead;

  BytesRead = ReadGameMemory(
      processID, OFFSET_EQUIPPED_BODY, BytesToRead, &itemBodyCur);
}

void
ReadLegsData()
{
  usize BytesToRead = sizeof(item_data);
  usize BytesRead;

  BytesRead = ReadGameMemory(
      processID, OFFSET_EQUIPPED_LEGS, BytesToRead, &itemLegsCur);
}

void
ReadNeckData()
{
  usize BytesToRead = sizeof(item_data);
  usize BytesRead;

  BytesRead = ReadGameMemory(
      processID, OFFSET_EQUIPPED_NECK, BytesToRead, &itemNeckCur);
}

void
ReadArmorData()
{
  ReadGlovesData();
  ReadBodyData();
  ReadHeadData();
  ReadLegsData();
  ReadNeckData();
}

BOOL
ItemDataChanged(item_data *Item1, item_data *Item2)
{
  usize DataSize = sizeof(item_data);

  BOOL Result = DataChanged((void *) Item1, (void *) Item2, DataSize);

  return Result;
}

BOOL
BladeDataChanged()
{
  if (ItemDataChanged(&itemBladePrev, &itemBladeCur))
  {
    return TRUE;
  }
  return FALSE;
}

BOOL
WeaponDataChanged()
{
  if (ItemDataChanged(&itemGripPrev, &itemGripCur) ||
      ItemDataChanged(&itemGem1WeaponPrev, &itemGem1WeaponCur) ||
      ItemDataChanged(&itemGem2WeaponPrev, &itemGem2WeaponCur) ||
      ItemDataChanged(&itemGem3WeaponPrev, &itemGem3WeaponCur))
  {
    return TRUE;
  }
  return FALSE;
}

BOOL
ShieldDataChanged()
{
  if (ItemDataChanged(&itemShieldPrev, &itemShieldCur) ||
      ItemDataChanged(&itemGem1ShieldPrev, &itemGem1ShieldCur) ||
      ItemDataChanged(&itemGem2ShieldPrev, &itemGem2ShieldCur) ||
      ItemDataChanged(&itemGem3ShieldPrev, &itemGem3ShieldCur))
  {
    return TRUE;
  }
  return FALSE;
}

BOOL
ArmorDataChanged()
{
  if (ItemDataChanged(&itemGloveLeftPrev, &itemGloveLeftCur) ||
      ItemDataChanged(&itemGloveRightPrev, &itemGloveRightCur) ||
      ItemDataChanged(&itemHeadPrev, &itemHeadCur) ||
      ItemDataChanged(&itemBodyPrev, &itemBodyCur) ||
      ItemDataChanged(&itemLegsPrev, &itemLegsCur) ||
      ItemDataChanged(&itemNeckPrev, &itemNeckCur))
  {
    return TRUE;
  }
  return FALSE;
}

void
PrintBladeLeveling(u8 BladeNumber)
{

  i8 HumanCur = itemBladeCur.ClassHuman;
  i8 BeastCur = itemBladeCur.ClassBeast;
  i8 UndeadCur = itemBladeCur.ClassUndead;
  i8 PhantomCur = itemBladeCur.ClassPhantom;
  i8 DragonCur = itemBladeCur.ClassDragon;
  i8 EvilCur = itemBladeCur.ClassEvil;
  i8 PhysicalCur = itemBladeCur.AffinityPhysical;
  i8 AirCur = itemBladeCur.AffinityAir;
  i8 FireCur = itemBladeCur.AffinityFire;
  i8 EarthCur = itemBladeCur.AffinityEarth;
  i8 WaterCur = itemBladeCur.AffinityWater;
  i8 LightCur = itemBladeCur.AffinityLight;
  i8 DarkCur = itemBladeCur.AffinityDark;

  i8 HumanFlag = LevelingFlags.Flags.Human;
  i8 BeastFlag = LevelingFlags.Flags.Beast;
  i8 UndeadFlag = LevelingFlags.Flags.Undead;
  i8 PhantomFlag = LevelingFlags.Flags.Phantom;
  i8 DragonFlag = LevelingFlags.Flags.Dragon;
  i8 EvilFlag = LevelingFlags.Flags.Evil;
  i8 PhysicalFlag = LevelingFlags.Flags.Physical;
  i8 AirFlag = LevelingFlags.Flags.Air;
  i8 FireFlag = LevelingFlags.Flags.Fire;
  i8 EarthFlag = LevelingFlags.Flags.Earth;
  i8 WaterFlag = LevelingFlags.Flags.Water;
  i8 LightFlag = LevelingFlags.Flags.Light;
  i8 DarkFlag = LevelingFlags.Flags.Dark;

  switch (BladeNumber)
  {
    case 1:
    {
      sprintf_s(szBuffer, _countof(szBuffer), "\n\n== BLADE 1 ==\n\n");
      WriteToBackBuffer();

      if (DragonCur == 100)
      {
        sprintf_s(
            szBuffer, _countof(szBuffer), "Dragon:   %4i OK\n", DragonCur);
      }
      else
      {
        sprintf_s(szBuffer, _countof(szBuffer), "Dragon:   %4i %s\n", DragonCur,
            DragonFlag ? "++" : "");
      }
      WriteToBackBuffer();

      if (PhysicalCur == 100)
      {

        sprintf_s(
            szBuffer, _countof(szBuffer), "Physical: %4i OK\n", PhysicalCur);
      }
      else
      {
        sprintf_s(szBuffer, _countof(szBuffer), "Physical: %4i %s\n",
            PhysicalCur, PhysicalFlag ? "++" : "");
      }
      WriteToBackBuffer();

      if (BeastCur == 100)
      {

        sprintf_s(szBuffer, _countof(szBuffer), "Beast:    %4i OK\n", BeastCur);
      }
      else
      {
        sprintf_s(szBuffer, _countof(szBuffer), "Beast:    %4i %s\n", BeastCur,
            BeastFlag ? "++" : "");
      }
      WriteToBackBuffer();

      break;
    }

    case 2:
    {
      sprintf_s(szBuffer, _countof(szBuffer), "\n\n== BLADE 2 ==\n\n");
      WriteToBackBuffer();

      if (PhantomCur == 100)
      {

        sprintf_s(
            szBuffer, _countof(szBuffer), "Phantom: %4i OK\n", PhantomCur);
      }
      else
      {
        sprintf_s(szBuffer, _countof(szBuffer), "Phantom: %4i %s\n", PhantomCur,
            PhantomFlag ? "++" : "");
      }
      WriteToBackBuffer();

      if (HumanCur == 100)
      {
        sprintf_s(szBuffer, _countof(szBuffer), "Human:   %4i OK\n", HumanCur);
      }
      else
      {
        sprintf_s(szBuffer, _countof(szBuffer), "Human:   %4i %s\n", HumanCur,
            HumanFlag ? "++" : "");
      }
      WriteToBackBuffer();

      if (EarthCur == 100)
      {

        sprintf_s(szBuffer, _countof(szBuffer), "Earth:   %4i OK\n", EarthCur);
      }
      else
      {
        sprintf_s(szBuffer, _countof(szBuffer), "Earth:   %4i %s\n", EarthCur,
            EarthFlag ? "++" : "");
      }
      WriteToBackBuffer();

      if (DarkCur == 100)
      {

        sprintf_s(szBuffer, _countof(szBuffer), "Dark:    %4i OK\n", DarkCur);
      }
      else
      {
        sprintf_s(szBuffer, _countof(szBuffer), "Dark:    %4i %s\n", DarkCur,
            DarkFlag ? "++" : "");
      }
      WriteToBackBuffer();

      if (WaterCur == 100)
      {

        sprintf_s(szBuffer, _countof(szBuffer), "Water:   %4i OK\n", WaterCur);
      }
      else
      {
        sprintf_s(szBuffer, _countof(szBuffer), "Water:   %4i %s\n", WaterCur,
            WaterFlag ? "++" : "");
      }
      WriteToBackBuffer();

      break;
    }

    case 3:
    {
      sprintf_s(szBuffer, _countof(szBuffer), "\n\n== BLADE 3 ==\n\n");
      WriteToBackBuffer();

      if (FireCur == 100)
      {

        sprintf_s(szBuffer, _countof(szBuffer), "Fire: %4i OK\n", FireCur);
      }
      else
      {
        sprintf_s(szBuffer, _countof(szBuffer), "Fire: %4i %s\n", FireCur,
            FireFlag ? "++" : "");
      }
      WriteToBackBuffer();

      if (AirCur == 100)
      {
        sprintf_s(szBuffer, _countof(szBuffer), "Air:  %4i OK\n", AirCur);
      }
      else
      {
        sprintf_s(szBuffer, _countof(szBuffer), "Air:  %4i %s\n", AirCur,
            AirFlag ? "++" : "");
      }
      WriteToBackBuffer();

      break;
    }

    case 4:
    {
      sprintf_s(szBuffer, _countof(szBuffer), "\n\n== BLADE 4 ==\n\n");
      WriteToBackBuffer();

      if (UndeadCur == 100)
      {

        sprintf_s(szBuffer, _countof(szBuffer), "Undead: %4i OK\n", UndeadCur);
      }
      else
      {
        sprintf_s(szBuffer, _countof(szBuffer), "Undead: %4i %s\n", UndeadCur,
            UndeadFlag ? "++" : "");
      }
      WriteToBackBuffer();

      if (EvilCur == 100)
      {
        sprintf_s(szBuffer, _countof(szBuffer), "Evil:   %4i OK\n", EvilCur);
      }
      else
      {
        sprintf_s(szBuffer, _countof(szBuffer), "Evil:   %4i %s\n", EvilCur,
            EvilFlag ? "++" : "");
      }
      WriteToBackBuffer();

      if (LightCur == 100)
      {
        sprintf_s(szBuffer, _countof(szBuffer), "Light:  %4i OK\n", LightCur);
      }
      else
      {
        sprintf_s(szBuffer, _countof(szBuffer), "Light:  %4i %s\n", LightCur,
            LightFlag ? "++" : "");
      }
      WriteToBackBuffer();

      break;
    }

    default:
    {
      sprintf_s(
          szBuffer, _countof(szBuffer), "\n\nNo leveling weapon equipped\n\n");
      WriteToBackBuffer();
    }
  }
}

void
WriteBladeLeveling(u8 BladeNumber)
{

  i8 HumanCur = itemBladeCur.ClassHuman;
  i8 BeastCur = itemBladeCur.ClassBeast;
  i8 UndeadCur = itemBladeCur.ClassUndead;
  i8 PhantomCur = itemBladeCur.ClassPhantom;
  i8 DragonCur = itemBladeCur.ClassDragon;
  i8 EvilCur = itemBladeCur.ClassEvil;
  i8 PhysicalCur = itemBladeCur.AffinityPhysical;
  i8 AirCur = itemBladeCur.AffinityAir;
  i8 FireCur = itemBladeCur.AffinityFire;
  i8 EarthCur = itemBladeCur.AffinityEarth;
  i8 WaterCur = itemBladeCur.AffinityWater;
  i8 LightCur = itemBladeCur.AffinityLight;
  i8 DarkCur = itemBladeCur.AffinityDark;

  i8 HumanFlag = LevelingFlags.Flags.Human;
  i8 BeastFlag = LevelingFlags.Flags.Beast;
  i8 UndeadFlag = LevelingFlags.Flags.Undead;
  i8 PhantomFlag = LevelingFlags.Flags.Phantom;
  i8 DragonFlag = LevelingFlags.Flags.Dragon;
  i8 EvilFlag = LevelingFlags.Flags.Evil;
  i8 PhysicalFlag = LevelingFlags.Flags.Physical;
  i8 AirFlag = LevelingFlags.Flags.Air;
  i8 FireFlag = LevelingFlags.Flags.Fire;
  i8 EarthFlag = LevelingFlags.Flags.Earth;
  i8 WaterFlag = LevelingFlags.Flags.Water;
  i8 LightFlag = LevelingFlags.Flags.Light;
  i8 DarkFlag = LevelingFlags.Flags.Dark;

  FILE *fpBladeLeveling = fopen("game_data/weapon/blade_leveling.txt", "w");

  switch (BladeNumber)
  {
    case 1:
    {
      fprintf(fpBladeLeveling, "== BLADE 1 ==\n\n");

      if (DragonCur == 100)
      {
        fprintf(fpBladeLeveling, "Dragon:   %4i OK\n", DragonCur);
      }
      else
      {
        fprintf(fpBladeLeveling, "Dragon:   %4i %s\n", DragonCur,
            DragonFlag ? "++" : "");
      }

      if (PhysicalCur == 100)
      {
        fprintf(fpBladeLeveling, "Physical: %4i OK\n", PhysicalCur);
      }
      else
      {
        fprintf(fpBladeLeveling, "Physical: %4i %s\n", PhysicalCur,
            PhysicalFlag ? "++" : "");
      }

      if (BeastCur == 100)
      {
        fprintf(fpBladeLeveling, "Beast:    %4i OK\n", BeastCur);
      }
      else
      {
        fprintf(fpBladeLeveling, "Beast:    %4i %s\n", BeastCur,
            BeastFlag ? "++" : "");
      }

      break;
    }

    case 2:
    {
      fprintf(fpBladeLeveling, "== BLADE 2 ==\n\n");

      if (PhantomCur == 100)
      {
        fprintf(fpBladeLeveling, "Phantom: %4i OK\n", PhantomCur);
      }
      else
      {
        fprintf(fpBladeLeveling, "Phantom: %4i %s\n", PhantomCur,
            PhantomFlag ? "++" : "");
      }

      if (HumanCur == 100)
      {
        fprintf(fpBladeLeveling, "Human:   %4i OK\n", HumanCur);
      }
      else
      {
        fprintf(fpBladeLeveling, "Human:   %4i %s\n", HumanCur,
            HumanFlag ? "++" : "");
      }

      if (EarthCur == 100)
      {
        fprintf(fpBladeLeveling, "Earth:   %4i OK\n", EarthCur);
      }
      else
      {
        fprintf(fpBladeLeveling, "Earth:   %4i %s\n", EarthCur,
            EarthFlag ? "++" : "");
      }

      if (DarkCur == 100)
      {
        fprintf(fpBladeLeveling, "Dark:    %4i OK\n", DarkCur);
      }
      else
      {
        fprintf(fpBladeLeveling, "Dark:    %4i %s\n", DarkCur,
            DarkFlag ? "++" : "");
      }

      if (WaterCur == 100)
      {
        fprintf(fpBladeLeveling, "Water:   %4i OK\n", WaterCur);
      }
      else
      {
        fprintf(fpBladeLeveling, "Water:   %4i %s\n", WaterCur,
            WaterFlag ? "++" : "");
      }

      break;
    }

    case 3:
    {
      fprintf(fpBladeLeveling, "== BLADE 3 ==\n\n");

      if (FireCur == 100)
      {
        fprintf(fpBladeLeveling, "Fire: %4i OK\n", FireCur);
      }
      else
      {
        fprintf(
            fpBladeLeveling, "Fire: %4i %s\n", FireCur, FireFlag ? "++" : "");
      }

      if (AirCur == 100)
      {
        fprintf(fpBladeLeveling, "Air:  %4i OK\n", AirCur);
      }
      else
      {
        fprintf(fpBladeLeveling, "Air:  %4i %s\n", AirCur, AirFlag ? "++" : "");
      }

      break;
    }

    case 4:
    {
      fprintf(fpBladeLeveling, "== BLADE 4 ==\n\n");

      if (UndeadCur == 100)
      {
        fprintf(fpBladeLeveling, "Undead: %4i OK\n", UndeadCur);
      }
      else
      {
        fprintf(fpBladeLeveling, "Undead: %4i %s\n", UndeadCur,
            UndeadFlag ? "++" : "");
      }

      if (EvilCur == 100)
      {
        fprintf(fpBladeLeveling, "Evil:   %4i OK\n", EvilCur);
      }
      else
      {
        fprintf(
            fpBladeLeveling, "Evil:   %4i %s\n", EvilCur, EvilFlag ? "++" : "");
      }

      if (LightCur == 100)
      {
        fprintf(fpBladeLeveling, "Light:  %4i OK\n", LightCur);
      }
      else
      {
        fprintf(fpBladeLeveling, "Light:  %4i %s\n", LightCur,
            LightFlag ? "++" : "");
      }
      break;
    }

    default:
    {
      fprintf(fpBladeLeveling, "No leveling weapon equipped\n");
    }
  }
  fclose(fpBladeLeveling);
}

void
WriteBladeData()
{
  // Check for out-of-bound indexes
  if (itemBladeCur.NamesListPosition > _countof(ItemNamesList) - 1 || //
      itemBladeCur.ListPosition > _countof(WeaponsList) - 1 || //
      itemBladeCur.Category > _countof(WeaponsCategories) - 1)
  {
    return;
  }

  FILE *fpBladeData = fopen("game_data/weapon/blade.txt", "w");

  // Check if weapon is eqipped
  if (itemBladeCur.ListPosition == 0)
  {
    fprintf(
        fpBladeData, "Can't read the blade data: weapon is not equipped!\n");
    fclose(fpBladeData);

    return;
  }

  fprintf(fpBladeData, "Blade Stats\n\n");

  fprintf(fpBladeData, "Name: %s\n", WeaponsList[itemBladeCur.ListPosition]);
  fprintf(
      fpBladeData, "Category: %s\n", WeaponsCategories[itemBladeCur.Category]);
  fprintf(
      fpBladeData, "Material: %s\n", CraftingMaterials[itemBladeCur.Material]);
  fprintf(fpBladeData, "Damage type: %s\n",
      WeaponDamageType[itemBladeCur.DamageType]);
  fprintf(fpBladeData, "\n");

  // Bonuses
  fprintf(fpBladeData, "BONUSES\n");
  fprintf(fpBladeData, "========\n");
  fprintf(fpBladeData, "STR: %3i\n", itemBladeCur.STR);
  fprintf(fpBladeData, "INT: %3i\n", itemBladeCur.INT);
  fprintf(fpBladeData, "AGL: %3i\n", itemBladeCur.AGL);
  fprintf(fpBladeData, "\n");

  // DP & PP
  fprintf(fpBladeData, "DURABILITY\n");
  fprintf(fpBladeData, "===========\n");
  fprintf(fpBladeData, "DP: %3i/%3i\n", (itemBladeCur.DPCur + 99) / 100,
      (itemBladeCur.DPMax + 99) / 100);
  fprintf(fpBladeData, "PP: %3i/%3i\n", itemBladeCur.PPCur, itemBladeCur.PPMax);
  fprintf(fpBladeData, "\n");

  // Misc
  fprintf(fpBladeData, "MISC\n");
  fprintf(fpBladeData, "=======================\n");

  // Range
  fprintf(fpBladeData, "Range (x/y/z): %2i/%2i/%2i\n", itemBladeCur.Range.x,
      itemBladeCur.Range.y, itemBladeCur.Range.z);

  // Resource cost
  fprintf(fpBladeData, "Attack cost: %i %s\n", itemBladeCur.StatsCostValue,
      WeaponAttackCostType[itemBladeCur.StatsCostType]);
  fprintf(fpBladeData, "\n");

  // Class
  fprintf(fpBladeData, "CLASS\n");
  fprintf(fpBladeData, "=============\n");
  fprintf(fpBladeData, "Human:    %3i\n", itemBladeCur.ClassHuman);
  fprintf(fpBladeData, "Beast:    %3i\n", itemBladeCur.ClassBeast);
  fprintf(fpBladeData, "Undead:   %3i\n", itemBladeCur.ClassUndead);
  fprintf(fpBladeData, "Phantom:  %3i\n", itemBladeCur.ClassPhantom);
  fprintf(fpBladeData, "Dragon:   %3i\n", itemBladeCur.ClassDragon);
  fprintf(fpBladeData, "Evil:     %3i\n", itemBladeCur.ClassEvil);
  fprintf(fpBladeData, "\n");

  // Affinity
  fprintf(fpBladeData, "AFFINITY\n");
  fprintf(fpBladeData, "=============\n");
  fprintf(fpBladeData, "Physical: %3i\n", itemBladeCur.AffinityPhysical);
  fprintf(fpBladeData, "Air:      %3i\n", itemBladeCur.AffinityAir);
  fprintf(fpBladeData, "Fire:     %3i\n", itemBladeCur.AffinityFire);
  fprintf(fpBladeData, "Earth:    %3i\n", itemBladeCur.AffinityEarth);
  fprintf(fpBladeData, "Water:    %3i\n", itemBladeCur.AffinityWater);
  fprintf(fpBladeData, "Light:    %3i\n", itemBladeCur.AffinityLight);
  fprintf(fpBladeData, "Dark:     %3i\n", itemBladeCur.AffinityDark);

  fclose(fpBladeData);
}

void
WriteWeaponData()
{
  // Check for out-of-bound indexes
  if (itemBladeCur.NamesListPosition > _countof(ItemNamesList) - 1 || //
      itemBladeCur.ListPosition > _countof(WeaponsList) - 1 || //
      itemBladeCur.Category > _countof(WeaponsCategories) - 1 || //
      itemBladeCur.Material > _countof(CraftingMaterials) - 1 || //
      itemGripCur.ListPosition > _countof(GripsList) - 1 || //
      itemGem1WeaponCur.ListPosition > _countof(GemsList) - 1 || //
      itemGem2WeaponCur.ListPosition > _countof(GemsList) - 1 || //
      itemGem3WeaponCur.ListPosition > _countof(GemsList) - 1)
  {
    return;
  }

  FILE *fpWeaponData = fopen("game_data/weapon/weapon.txt", "w");

  // Check if weapon is eqipped
  if (itemBladeCur.ListPosition == 0)
  {
    fprintf(fpWeaponData, "Weapon not equipped!\n");
    fclose(fpWeaponData);

    return;
  }

  fprintf(fpWeaponData, "Weapon Stats\n\n");

  fprintf(fpWeaponData, "Weapon name: %s\n", nameWeaponCur);
  fprintf(
      fpWeaponData, "Blade name: %s\n", WeaponsList[itemBladeCur.ListPosition]);
  fprintf(
      fpWeaponData, "Category: %s\n", WeaponsCategories[itemBladeCur.Category]);
  fprintf(
      fpWeaponData, "Material: %s\n", CraftingMaterials[itemBladeCur.Material]);
  fprintf(fpWeaponData, "Grip: %s\n", GripsList[itemGripCur.ListPosition]);
  fprintf(fpWeaponData, "Damage type: %s\n",
      WeaponDamageType[itemBladeCur.DamageType]);
  fprintf(fpWeaponData, "\n");

  // Bonuses
  i16 STRTotal = itemBladeCur.STR + itemGripCur.STR + itemGem1WeaponCur.STR +
                 itemGem2WeaponCur.STR + itemGem3WeaponCur.STR;
  i16 INTTotal = itemBladeCur.INT + itemGripCur.INT + itemGem1WeaponCur.INT +
                 itemGem2WeaponCur.INT + itemGem3WeaponCur.INT;
  i16 AGLTotal = itemBladeCur.AGL + itemGripCur.AGL + itemGem1WeaponCur.AGL +
                 itemGem2WeaponCur.AGL + itemGem3WeaponCur.AGL;

  fprintf(fpWeaponData, "BONUSES\n");
  fprintf(fpWeaponData, "========\n");
  fprintf(fpWeaponData, "STR: %3i\n", STRTotal);
  fprintf(fpWeaponData, "INT: %3i\n", INTTotal);
  fprintf(fpWeaponData, "AGL: %3i\n", AGLTotal);
  fprintf(fpWeaponData, "\n");

  // DP & PP
  fprintf(fpWeaponData, "DURABILITY\n");
  fprintf(fpWeaponData, "===========\n");
  fprintf(fpWeaponData, "DP: %3i/%3i\n", (itemBladeCur.DPCur + 99) / 100,
      (itemBladeCur.DPMax + 99) / 100);
  fprintf(
      fpWeaponData, "PP: %3i/%3i\n", itemBladeCur.PPCur, itemBladeCur.PPMax);
  fprintf(fpWeaponData, "\n");

  // Misc
  fprintf(fpWeaponData, "MISC\n");
  fprintf(fpWeaponData, "=======================\n");

  // Range
  fprintf(fpWeaponData, "Range (x/y/z): %2i/%2i/%2i\n", itemBladeCur.Range.x,
      itemBladeCur.Range.y, itemBladeCur.Range.z);

  // Resource cost
  fprintf(fpWeaponData, "Attack cost: %i %s\n", itemBladeCur.StatsCostValue,
      WeaponAttackCostType[itemBladeCur.StatsCostType]);

  fprintf(fpWeaponData, "\n");

  // Gems
  u8 GemSlots = itemGripCur.GemSlots;
  if (GemSlots)
  {
    fprintf(fpWeaponData, "GEMS\n");
    fprintf(fpWeaponData, "=========================\n");

    fprintf(fpWeaponData, "Slot 1: %17s\n",
        GemsList[itemGem1WeaponCur.ListPosition]);

    if (GemSlots > 1)
    {
      fprintf(fpWeaponData, "Slot 2: %17s\n",
          GemsList[itemGem2WeaponCur.ListPosition]);
    }
    if (GemSlots > 2)
    {
      fprintf(fpWeaponData, "Slot 3: %17s\n",
          GemsList[itemGem3WeaponCur.ListPosition]);
    }
  }

  fprintf(fpWeaponData, "\n");

  // Type
  fprintf(fpWeaponData, "TYPE\n");
  fprintf(fpWeaponData, "============\n");
  fprintf(fpWeaponData, "Blunt:    %2i\n", itemGripCur.TypeBlunt);
  fprintf(fpWeaponData, "Edged:    %2i\n", itemGripCur.TypeEdged);
  fprintf(fpWeaponData, "Piercing: %2i\n", itemGripCur.TypePiercing);
  fprintf(fpWeaponData, "\n");

  // Class summary
  i16 ClassHumanTotal = itemBladeCur.ClassHuman + itemGem1WeaponCur.ClassHuman +
                        itemGem2WeaponCur.ClassHuman +
                        itemGem3WeaponCur.ClassHuman;
  i16 ClassBeastTotal = itemBladeCur.ClassBeast + itemGem1WeaponCur.ClassBeast +
                        itemGem2WeaponCur.ClassBeast +
                        itemGem3WeaponCur.ClassBeast;
  i16 ClassUndeadTotal =
      itemBladeCur.ClassUndead + itemGem1WeaponCur.ClassUndead +
      itemGem2WeaponCur.ClassUndead + itemGem3WeaponCur.ClassUndead;
  i16 ClassPhantomTotal =
      itemBladeCur.ClassPhantom + itemGem1WeaponCur.ClassPhantom +
      itemGem2WeaponCur.ClassPhantom + itemGem3WeaponCur.ClassPhantom;
  i16 ClassDragonTotal =
      itemBladeCur.ClassDragon + itemGem1WeaponCur.ClassDragon +
      itemGem2WeaponCur.ClassDragon + itemGem3WeaponCur.ClassDragon;
  i16 ClassEvilTotal = itemBladeCur.ClassEvil + itemGem1WeaponCur.ClassEvil +
                       itemGem2WeaponCur.ClassEvil +
                       itemGem3WeaponCur.ClassEvil;

  // Affinity summary
  i16 AffinityPhysicalTotal =
      itemBladeCur.AffinityPhysical + itemGem1WeaponCur.AffinityPhysical +
      itemGem2WeaponCur.AffinityPhysical + itemGem3WeaponCur.AffinityPhysical;
  i16 AffinityAirTotal =
      itemBladeCur.AffinityAir + itemGem1WeaponCur.AffinityAir +
      itemGem2WeaponCur.AffinityAir + itemGem3WeaponCur.AffinityAir;
  i16 AffinityFireTotal =
      itemBladeCur.AffinityFire + itemGem1WeaponCur.AffinityFire +
      itemGem2WeaponCur.AffinityFire + itemGem3WeaponCur.AffinityFire;
  i16 AffinityEarthTotal =
      itemBladeCur.AffinityEarth + itemGem1WeaponCur.AffinityEarth +
      itemGem2WeaponCur.AffinityEarth + itemGem3WeaponCur.AffinityEarth;
  i16 AffinityWaterTotal =
      itemBladeCur.AffinityWater + itemGem1WeaponCur.AffinityWater +
      itemGem2WeaponCur.AffinityWater + itemGem3WeaponCur.AffinityWater;
  i16 AffinityLightTotal =
      itemBladeCur.AffinityLight + itemGem1WeaponCur.AffinityLight +
      itemGem2WeaponCur.AffinityLight + itemGem3WeaponCur.AffinityLight;
  i16 AffinityDarkTotal =
      itemBladeCur.AffinityDark + itemGem1WeaponCur.AffinityDark +
      itemGem2WeaponCur.AffinityDark + itemGem3WeaponCur.AffinityDark;

  // Class
  fprintf(fpWeaponData, "CLASS\n");
  fprintf(fpWeaponData, "=============\n");
  fprintf(fpWeaponData, "Human:    %3i\n", ClassHumanTotal);
  fprintf(fpWeaponData, "Beast:    %3i\n", ClassBeastTotal);
  fprintf(fpWeaponData, "Undead:   %3i\n", ClassUndeadTotal);
  fprintf(fpWeaponData, "Phantom:  %3i\n", ClassPhantomTotal);
  fprintf(fpWeaponData, "Dragon:   %3i\n", ClassDragonTotal);
  fprintf(fpWeaponData, "Evil:     %3i\n", ClassEvilTotal);
  fprintf(fpWeaponData, "\n");

  // Affinity
  fprintf(fpWeaponData, "AFFINITY\n");
  fprintf(fpWeaponData, "=============\n");
  fprintf(fpWeaponData, "Physical: %3i\n", AffinityPhysicalTotal);
  fprintf(fpWeaponData, "Air:      %3i\n", AffinityAirTotal);
  fprintf(fpWeaponData, "Fire:     %3i\n", AffinityFireTotal);
  fprintf(fpWeaponData, "Earth:    %3i\n", AffinityEarthTotal);
  fprintf(fpWeaponData, "Water:    %3i\n", AffinityWaterTotal);
  fprintf(fpWeaponData, "Light:    %3i\n", AffinityLightTotal);
  fprintf(fpWeaponData, "Dark:     %3i\n", AffinityDarkTotal);

  fclose(fpWeaponData);
}

void
WriteShieldData()
{
  // Check for out-of-bound indexes
  if (itemShieldCur.ListPosition > _countof(ArmorsList) - 1 || //
      itemShieldCur.Material > _countof(CraftingMaterials) - 1 || //
      itemGem1ShieldCur.ListPosition > _countof(GemsList) - 1 || //
      itemGem2ShieldCur.ListPosition > _countof(GemsList) - 1 || //
      itemGem3ShieldCur.ListPosition > _countof(GemsList) - 1)
  {
    return;
  }

  FILE *fpShieldData = fopen("game_data/armor/shield.txt", "w");

  // Check if shield is eqipped. If not, write the warning and skip the rest.
  if (itemShieldCur.ListPosition == 0)
  {
    fprintf(fpShieldData, "Shield not equipped!\n");
    fclose(fpShieldData);

    return;
  }

  fprintf(fpShieldData, "Shield Stats\n\n");

  fprintf(fpShieldData, "Name: %s\n", ArmorsList[itemShieldCur.ListPosition]);
  fprintf(fpShieldData, "Material: %s\n",
      CraftingMaterials[itemShieldCur.Material]);

  fprintf(fpShieldData, "\n");

  // Bonuses
  i16 STRTotal = itemShieldCur.STR + itemGem1ShieldCur.STR +
                 itemGem2ShieldCur.STR + itemGem3ShieldCur.STR;
  i16 INTTotal = itemShieldCur.INT + itemGem1ShieldCur.INT +
                 itemGem2ShieldCur.INT + itemGem3ShieldCur.INT;
  i16 AGLTotal = itemShieldCur.AGL + itemGem1ShieldCur.AGL +
                 itemGem2ShieldCur.AGL + itemGem3ShieldCur.AGL;

  fprintf(fpShieldData, "BONUSES\n");
  fprintf(fpShieldData, "========\n");
  fprintf(fpShieldData, "STR: %3i\n", STRTotal);
  fprintf(fpShieldData, "INT: %3i\n", INTTotal);
  fprintf(fpShieldData, "AGL: %3i\n", AGLTotal);
  fprintf(fpShieldData, "\n");

  // DP & PP
  fprintf(fpShieldData, "DURABILITY\n");
  fprintf(fpShieldData, "===========\n");
  fprintf(fpShieldData, "DP: %3i/%3i\n", (itemShieldCur.DPCur + 99) / 100,
      (itemShieldCur.DPMax + 99) / 100);
  fprintf(
      fpShieldData, "PP: %3i/%3i\n", itemShieldCur.PPCur, itemShieldCur.PPMax);
  fprintf(fpShieldData, "\n");

  // Gems

  // Gems
  u8 GemSlots = itemShieldCur.GemSlots;
  if (GemSlots)
  {
    fprintf(fpShieldData, "GEMS\n");
    fprintf(fpShieldData, "=========================\n");

    fprintf(fpShieldData, "Slot 1: %17s\n",
        GemsList[itemGem1ShieldCur.ListPosition]);

    if (GemSlots > 1)
    {
      fprintf(fpShieldData, "Slot 2: %17s\n",
          GemsList[itemGem2ShieldCur.ListPosition]);
    }
    if (GemSlots > 2)
    {
      fprintf(fpShieldData, "Slot 3: %17s\n",
          GemsList[itemGem3ShieldCur.ListPosition]);
    }
  }
  fprintf(fpShieldData, "\n");

  // Type
  fprintf(fpShieldData, "TYPE\n");
  fprintf(fpShieldData, "============\n");
  fprintf(fpShieldData, "Blunt:    %2i\n", itemShieldCur.TypeBlunt);
  fprintf(fpShieldData, "Edged:    %2i\n", itemShieldCur.TypeEdged);
  fprintf(fpShieldData, "Piercing: %2i\n", itemShieldCur.TypePiercing);
  fprintf(fpShieldData, "\n");

  // Class summary
  i16 ClassHumanTotal =
      itemShieldCur.ClassHuman + itemGem1ShieldCur.ClassHuman +
      itemGem2ShieldCur.ClassHuman + itemGem3ShieldCur.ClassHuman;
  i16 ClassBeastTotal =
      itemShieldCur.ClassBeast + itemGem1ShieldCur.ClassBeast +
      itemGem2ShieldCur.ClassBeast + itemGem3ShieldCur.ClassBeast;
  i16 ClassUndeadTotal =
      itemShieldCur.ClassUndead + itemGem1ShieldCur.ClassUndead +
      itemGem2ShieldCur.ClassUndead + itemGem3ShieldCur.ClassUndead;
  i16 ClassPhantomTotal =
      itemShieldCur.ClassPhantom + itemGem1ShieldCur.ClassPhantom +
      itemGem2ShieldCur.ClassPhantom + itemGem3ShieldCur.ClassPhantom;
  i16 ClassDragonTotal =
      itemShieldCur.ClassDragon + itemGem1ShieldCur.ClassDragon +
      itemGem2ShieldCur.ClassDragon + itemGem3ShieldCur.ClassDragon;
  i16 ClassEvilTotal = itemShieldCur.ClassEvil + itemGem1ShieldCur.ClassEvil +
                       itemGem2ShieldCur.ClassEvil +
                       itemGem3ShieldCur.ClassEvil;

  // Affinity summary
  i16 AffinityPhysicalTotal =
      itemShieldCur.AffinityPhysical + itemGem1ShieldCur.AffinityPhysical +
      itemGem2ShieldCur.AffinityPhysical + itemGem3ShieldCur.AffinityPhysical;
  i16 AffinityAirTotal =
      itemShieldCur.AffinityAir + itemGem1ShieldCur.AffinityAir +
      itemGem2ShieldCur.AffinityAir + itemGem3ShieldCur.AffinityAir;
  i16 AffinityFireTotal =
      itemShieldCur.AffinityFire + itemGem1ShieldCur.AffinityFire +
      itemGem2ShieldCur.AffinityFire + itemGem3ShieldCur.AffinityFire;
  i16 AffinityEarthTotal =
      itemShieldCur.AffinityEarth + itemGem1ShieldCur.AffinityEarth +
      itemGem2ShieldCur.AffinityEarth + itemGem3ShieldCur.AffinityEarth;
  i16 AffinityWaterTotal =
      itemShieldCur.AffinityWater + itemGem1ShieldCur.AffinityWater +
      itemGem2ShieldCur.AffinityWater + itemGem3ShieldCur.AffinityWater;
  i16 AffinityLightTotal =
      itemShieldCur.AffinityLight + itemGem1ShieldCur.AffinityLight +
      itemGem2ShieldCur.AffinityLight + itemGem3ShieldCur.AffinityLight;
  i16 AffinityDarkTotal =
      itemShieldCur.AffinityDark + itemGem1ShieldCur.AffinityDark +
      itemGem2ShieldCur.AffinityDark + itemGem3ShieldCur.AffinityDark;

  // Class
  fprintf(fpShieldData, "CLASS\n");
  fprintf(fpShieldData, "=============\n");
  fprintf(fpShieldData, "Human:    %3i\n", ClassHumanTotal);
  fprintf(fpShieldData, "Beast:    %3i\n", ClassBeastTotal);
  fprintf(fpShieldData, "Undead:   %3i\n", ClassUndeadTotal);
  fprintf(fpShieldData, "Phantom:  %3i\n", ClassPhantomTotal);
  fprintf(fpShieldData, "Dragon:   %3i\n", ClassDragonTotal);
  fprintf(fpShieldData, "Evil:     %3i\n", ClassEvilTotal);
  fprintf(fpShieldData, "\n");

  // Affinity
  fprintf(fpShieldData, "AFFINITY\n");
  fprintf(fpShieldData, "=============\n");
  fprintf(fpShieldData, "Physical: %3i\n", AffinityPhysicalTotal);
  fprintf(fpShieldData, "Air:      %3i\n", AffinityAirTotal);
  fprintf(fpShieldData, "Fire:     %3i\n", AffinityFireTotal);
  fprintf(fpShieldData, "Earth:    %3i\n", AffinityEarthTotal);
  fprintf(fpShieldData, "Water:    %3i\n", AffinityWaterTotal);
  fprintf(fpShieldData, "Light:    %3i\n", AffinityLightTotal);
  fprintf(fpShieldData, "Dark:     %3i\n", AffinityDarkTotal);

  fclose(fpShieldData);
}

void
WriteGloveLeftData()
{
  // Check for out-of-bound indexes
  if (itemGloveLeftCur.ListPosition > _countof(ArmorsList) - 1 || //
      itemGloveLeftCur.Material > _countof(CraftingMaterials) - 1)
  {
    return;
  }

  FILE *fpGloveLeftData = fopen("game_data/armor/glove_left.txt", "w");

  // Check if a glove is eqipped. If not, write the warning and skip the rest.
  if (itemGloveLeftCur.ListPosition == 0)
  {
    fprintf(fpGloveLeftData, "No left glove equipped!\n");

    fclose(fpGloveLeftData);

    return;
  }

  fprintf(fpGloveLeftData, "Left Glove Stats\n\n");

  fprintf(
      fpGloveLeftData, "Name: %s\n", ArmorsList[itemGloveLeftCur.ListPosition]);
  fprintf(fpGloveLeftData, "Material: %s\n",
      CraftingMaterials[itemGloveLeftCur.Material]);
  fprintf(fpGloveLeftData, "\n");

  // Bonuses
  fprintf(fpGloveLeftData, "BONUSES\n");
  fprintf(fpGloveLeftData, "========\n");
  fprintf(fpGloveLeftData, "STR: %3i\n", itemGloveLeftCur.STR);
  fprintf(fpGloveLeftData, "INT: %3i\n", itemGloveLeftCur.INT);
  fprintf(fpGloveLeftData, "AGL: %3i\n", itemGloveLeftCur.AGL);
  fprintf(fpGloveLeftData, "\n");

  // DP
  fprintf(fpGloveLeftData, "DURABILITY\n");
  fprintf(fpGloveLeftData, "===========\n");
  fprintf(fpGloveLeftData, "DP: %3i/%3i\n", (itemGloveLeftCur.DPCur + 99) / 100,
      (itemGloveLeftCur.DPMax + 99) / 100);
  fprintf(fpGloveLeftData, "\n");

  // Type
  fprintf(fpGloveLeftData, "TYPE\n");
  fprintf(fpGloveLeftData, "============\n");
  fprintf(fpGloveLeftData, "Blunt:    %2i\n", itemGloveLeftCur.TypeBlunt);
  fprintf(fpGloveLeftData, "Edged:    %2i\n", itemGloveLeftCur.TypeEdged);
  fprintf(fpGloveLeftData, "Piercing: %2i\n", itemGloveLeftCur.TypePiercing);
  fprintf(fpGloveLeftData, "\n");

  // Class
  fprintf(fpGloveLeftData, "CLASS\n");
  fprintf(fpGloveLeftData, "=============\n");
  fprintf(fpGloveLeftData, "Human:    %3i\n", itemGloveLeftCur.ClassHuman);
  fprintf(fpGloveLeftData, "Beast:    %3i\n", itemGloveLeftCur.ClassBeast);
  fprintf(fpGloveLeftData, "Undead:   %3i\n", itemGloveLeftCur.ClassUndead);
  fprintf(fpGloveLeftData, "Phantom:  %3i\n", itemGloveLeftCur.ClassPhantom);
  fprintf(fpGloveLeftData, "Dragon:   %3i\n", itemGloveLeftCur.ClassDragon);
  fprintf(fpGloveLeftData, "Evil:     %3i\n", itemGloveLeftCur.ClassEvil);
  fprintf(fpGloveLeftData, "\n");

  // Affinity
  fprintf(fpGloveLeftData, "AFFINITY\n");
  fprintf(fpGloveLeftData, "=============\n");
  fprintf(
      fpGloveLeftData, "Physical: %3i\n", itemGloveLeftCur.AffinityPhysical);
  fprintf(fpGloveLeftData, "Air:      %3i\n", itemGloveLeftCur.AffinityAir);
  fprintf(fpGloveLeftData, "Fire:     %3i\n", itemGloveLeftCur.AffinityFire);
  fprintf(fpGloveLeftData, "Earth:    %3i\n", itemGloveLeftCur.AffinityEarth);
  fprintf(fpGloveLeftData, "Water:    %3i\n", itemGloveLeftCur.AffinityWater);
  fprintf(fpGloveLeftData, "Light:    %3i\n", itemGloveLeftCur.AffinityLight);
  fprintf(fpGloveLeftData, "Dark:     %3i\n", itemGloveLeftCur.AffinityDark);

  fclose(fpGloveLeftData);
}

void
WriteGloveRightData()
{
  // Check for out-of-bound indexes
  if (itemGloveRightCur.ListPosition > _countof(ArmorsList) - 1 || //
      itemGloveRightCur.Material > _countof(CraftingMaterials) - 1)
  {
    return;
  }

  FILE *fpGloveRightData = fopen("game_data/armor/glove_right.txt", "w");

  // Check if a glove is eqipped. If not, write the warning and skip the rest.
  if (itemGloveRightCur.ListPosition == 0)
  {
    fprintf(fpGloveRightData, "No left glove equipped!\n");

    fclose(fpGloveRightData);

    return;
  }

  fprintf(fpGloveRightData, "Right Glove Stats\n\n");

  fprintf(fpGloveRightData, "Name: %s\n",
      ArmorsList[itemGloveRightCur.ListPosition]);
  fprintf(fpGloveRightData, "Material: %s\n",
      CraftingMaterials[itemGloveRightCur.Material]);
  fprintf(fpGloveRightData, "\n");

  // Bonuses
  fprintf(fpGloveRightData, "BONUSES\n");
  fprintf(fpGloveRightData, "========\n");
  fprintf(fpGloveRightData, "STR: %3i\n", itemGloveRightCur.STR);
  fprintf(fpGloveRightData, "INT: %3i\n", itemGloveRightCur.INT);
  fprintf(fpGloveRightData, "AGL: %3i\n", itemGloveRightCur.AGL);
  fprintf(fpGloveRightData, "\n");

  // DP
  fprintf(fpGloveRightData, "DURABILITY\n");
  fprintf(fpGloveRightData, "===========\n");
  fprintf(fpGloveRightData, "DP: %3i/%3i\n",
      (itemGloveRightCur.DPCur + 99) / 100,
      (itemGloveRightCur.DPMax + 99) / 100);
  fprintf(fpGloveRightData, "\n");

  // Type
  fprintf(fpGloveRightData, "TYPE\n");
  fprintf(fpGloveRightData, "============\n");
  fprintf(fpGloveRightData, "Blunt:    %2i\n", itemGloveRightCur.TypeBlunt);
  fprintf(fpGloveRightData, "Edged:    %2i\n", itemGloveRightCur.TypeEdged);
  fprintf(fpGloveRightData, "Piercing: %2i\n", itemGloveRightCur.TypePiercing);
  fprintf(fpGloveRightData, "\n");

  // Class
  fprintf(fpGloveRightData, "CLASS\n");
  fprintf(fpGloveRightData, "=============\n");
  fprintf(fpGloveRightData, "Human:    %3i\n", itemGloveRightCur.ClassHuman);
  fprintf(fpGloveRightData, "Beast:    %3i\n", itemGloveRightCur.ClassBeast);
  fprintf(fpGloveRightData, "Undead:   %3i\n", itemGloveRightCur.ClassUndead);
  fprintf(fpGloveRightData, "Phantom:  %3i\n", itemGloveRightCur.ClassPhantom);
  fprintf(fpGloveRightData, "Dragon:   %3i\n", itemGloveRightCur.ClassDragon);
  fprintf(fpGloveRightData, "Evil:     %3i\n", itemGloveRightCur.ClassEvil);
  fprintf(fpGloveRightData, "\n");

  // Affinity
  fprintf(fpGloveRightData, "AFFINITY\n");
  fprintf(fpGloveRightData, "=============\n");
  fprintf(
      fpGloveRightData, "Physical: %3i\n", itemGloveRightCur.AffinityPhysical);
  fprintf(fpGloveRightData, "Air:      %3i\n", itemGloveRightCur.AffinityAir);
  fprintf(fpGloveRightData, "Fire:     %3i\n", itemGloveRightCur.AffinityFire);
  fprintf(fpGloveRightData, "Earth:    %3i\n", itemGloveRightCur.AffinityEarth);
  fprintf(fpGloveRightData, "Water:    %3i\n", itemGloveRightCur.AffinityWater);
  fprintf(fpGloveRightData, "Light:    %3i\n", itemGloveRightCur.AffinityLight);
  fprintf(fpGloveRightData, "Dark:     %3i\n", itemGloveRightCur.AffinityDark);

  fclose(fpGloveRightData);
}

void
WriteHeadData()
{
  // Check for out-of-bound indexes
  if (itemHeadCur.ListPosition > _countof(ArmorsList) - 1 || //
      itemHeadCur.Material > _countof(CraftingMaterials) - 1)
  {
    return;
  }

  FILE *fpHeadData = fopen("game_data/armor/head.txt", "w");

  // Check if a head armor is eqipped.
  // If not, write the warning and skip the rest.
  if (itemHeadCur.ListPosition == 0)
  {
    fprintf(fpHeadData, "No head armor equipped!\n");
    fclose(fpHeadData);

    return;
  }

  fprintf(fpHeadData, "Helm Stats\n\n");

  fprintf(fpHeadData, "Name: %s\n", ArmorsList[itemHeadCur.ListPosition]);
  fprintf(
      fpHeadData, "Material: %s\n", CraftingMaterials[itemHeadCur.Material]);
  fprintf(fpHeadData, "\n");

  // Bonuses
  fprintf(fpHeadData, "BONUSES\n");
  fprintf(fpHeadData, "========\n");
  fprintf(fpHeadData, "STR: %3i\n", itemHeadCur.STR);
  fprintf(fpHeadData, "INT: %3i\n", itemHeadCur.INT);
  fprintf(fpHeadData, "AGL: %3i\n", itemHeadCur.AGL);
  fprintf(fpHeadData, "\n");

  // DP
  fprintf(fpHeadData, "DURABILITY\n");
  fprintf(fpHeadData, "===========\n");
  fprintf(fpHeadData, "DP: %3i/%3i\n", (itemHeadCur.DPCur + 99) / 100,
      (itemHeadCur.DPMax + 99) / 100);
  fprintf(fpHeadData, "\n");

  // Type
  fprintf(fpHeadData, "TYPE\n");
  fprintf(fpHeadData, "============\n");
  fprintf(fpHeadData, "Blunt:    %2i\n", itemHeadCur.TypeBlunt);
  fprintf(fpHeadData, "Edged:    %2i\n", itemHeadCur.TypeEdged);
  fprintf(fpHeadData, "Piercing: %2i\n", itemHeadCur.TypePiercing);
  fprintf(fpHeadData, "\n");

  // Class
  fprintf(fpHeadData, "CLASS\n");
  fprintf(fpHeadData, "=============\n");
  fprintf(fpHeadData, "Human:    %3i\n", itemHeadCur.ClassHuman);
  fprintf(fpHeadData, "Beast:    %3i\n", itemHeadCur.ClassBeast);
  fprintf(fpHeadData, "Undead:   %3i\n", itemHeadCur.ClassUndead);
  fprintf(fpHeadData, "Phantom:  %3i\n", itemHeadCur.ClassPhantom);
  fprintf(fpHeadData, "Dragon:   %3i\n", itemHeadCur.ClassDragon);
  fprintf(fpHeadData, "Evil:     %3i\n", itemHeadCur.ClassEvil);
  fprintf(fpHeadData, "\n");

  // Affinity
  fprintf(fpHeadData, "AFFINITY\n");
  fprintf(fpHeadData, "=============\n");
  fprintf(fpHeadData, "Physical: %3i\n", itemHeadCur.AffinityPhysical);
  fprintf(fpHeadData, "Air:      %3i\n", itemHeadCur.AffinityAir);
  fprintf(fpHeadData, "Fire:     %3i\n", itemHeadCur.AffinityFire);
  fprintf(fpHeadData, "Earth:    %3i\n", itemHeadCur.AffinityEarth);
  fprintf(fpHeadData, "Water:    %3i\n", itemHeadCur.AffinityWater);
  fprintf(fpHeadData, "Light:    %3i\n", itemHeadCur.AffinityLight);
  fprintf(fpHeadData, "Dark:     %3i\n", itemHeadCur.AffinityDark);

  fclose(fpHeadData);
}

void
WriteBodyData()
{
  // Check for out-of-bound indexes
  if (itemBodyCur.ListPosition > _countof(ArmorsList) - 1 || //
      itemBodyCur.Material > _countof(CraftingMaterials) - 1)
  {
    return;
  }

  FILE *fpBodyData = fopen("game_data/armor/body.txt", "w");

  // Check if a body armor is eqipped. If not, write the warning and skip the
  // rest.
  if (itemBodyCur.ListPosition == 0)
  {
    // fprintf(fpBodyData, "No body armor equipped!\n");
    fprintf(fpBodyData, "No Breastplate Equipped!\n");
    fclose(fpBodyData);

    return;
  }

  fprintf(fpBodyData, "Body Armor Stats\n\n");

  fprintf(fpBodyData, "Name: %s\n", ArmorsList[itemBodyCur.ListPosition]);
  fprintf(
      fpBodyData, "Material: %s\n", CraftingMaterials[itemBodyCur.Material]);
  fprintf(fpBodyData, "\n");

  // Bonuses
  fprintf(fpBodyData, "BONUSES\n");
  fprintf(fpBodyData, "========\n");
  fprintf(fpBodyData, "STR: %3i\n", itemBodyCur.STR);
  fprintf(fpBodyData, "INT: %3i\n", itemBodyCur.INT);
  fprintf(fpBodyData, "AGL: %3i\n", itemBodyCur.AGL);
  fprintf(fpBodyData, "\n");

  // DP
  fprintf(fpBodyData, "DURABILITY\n");
  fprintf(fpBodyData, "===========\n");
  fprintf(fpBodyData, "DP: %3i/%3i\n", (itemBodyCur.DPCur + 99) / 100,
      (itemBodyCur.DPMax + 99) / 100);
  fprintf(fpBodyData, "\n");

  // Type
  fprintf(fpBodyData, "TYPE\n");
  fprintf(fpBodyData, "============\n");
  fprintf(fpBodyData, "Blunt:    %2i\n", itemBodyCur.TypeBlunt);
  fprintf(fpBodyData, "Edged:    %2i\n", itemBodyCur.TypeEdged);
  fprintf(fpBodyData, "Piercing: %2i\n", itemBodyCur.TypePiercing);
  fprintf(fpBodyData, "\n");

  // Class
  fprintf(fpBodyData, "CLASS\n");
  fprintf(fpBodyData, "=============\n");
  fprintf(fpBodyData, "Human:    %3i\n", itemBodyCur.ClassHuman);
  fprintf(fpBodyData, "Beast:    %3i\n", itemBodyCur.ClassBeast);
  fprintf(fpBodyData, "Undead:   %3i\n", itemBodyCur.ClassUndead);
  fprintf(fpBodyData, "Phantom:  %3i\n", itemBodyCur.ClassPhantom);
  fprintf(fpBodyData, "Dragon:   %3i\n", itemBodyCur.ClassDragon);
  fprintf(fpBodyData, "Evil:     %3i\n", itemBodyCur.ClassEvil);
  fprintf(fpBodyData, "\n");

  // Affinity
  fprintf(fpBodyData, "AFFINITY\n");
  fprintf(fpBodyData, "=============\n");
  fprintf(fpBodyData, "Physical: %3i\n", itemBodyCur.AffinityPhysical);
  fprintf(fpBodyData, "Air:      %3i\n", itemBodyCur.AffinityAir);
  fprintf(fpBodyData, "Fire:     %3i\n", itemBodyCur.AffinityFire);
  fprintf(fpBodyData, "Earth:    %3i\n", itemBodyCur.AffinityEarth);
  fprintf(fpBodyData, "Water:    %3i\n", itemBodyCur.AffinityWater);
  fprintf(fpBodyData, "Light:    %3i\n", itemBodyCur.AffinityLight);
  fprintf(fpBodyData, "Dark:     %3i\n", itemBodyCur.AffinityDark);

  fclose(fpBodyData);
}

void
WriteLegsData()
{
  // Check for out-of-bound indexes
  if (itemLegsCur.ListPosition > _countof(ArmorsList) - 1 || //
      itemLegsCur.Material > _countof(CraftingMaterials) - 1)
  {
    return;
  }

  FILE *fpLegsData = fopen("game_data/armor/legs.txt", "w");

  // Check if a leg armor is eqipped.
  // If not, write the warning and skip the rest.
  if (itemLegsCur.ListPosition == 0)
  {
    fprintf(fpLegsData, "No legs armor equipped!\n");
    fclose(fpLegsData);

    return;
  }

  fprintf(fpLegsData, "Leggings Stats\n\n");

  fprintf(fpLegsData, "Name: %s\n", ArmorsList[itemLegsCur.ListPosition]);
  fprintf(
      fpLegsData, "Material: %s\n", CraftingMaterials[itemLegsCur.Material]);
  fprintf(fpLegsData, "\n");

  // Bonuses
  fprintf(fpLegsData, "BONUSES\n");
  fprintf(fpLegsData, "========\n");
  fprintf(fpLegsData, "STR: %3i\n", itemLegsCur.STR);
  fprintf(fpLegsData, "INT: %3i\n", itemLegsCur.INT);
  fprintf(fpLegsData, "AGL: %3i\n", itemLegsCur.AGL);
  fprintf(fpLegsData, "\n");

  // DP
  fprintf(fpLegsData, "DURABILITY\n");
  fprintf(fpLegsData, "===========\n");
  fprintf(fpLegsData, "DP: %3i/%3i\n", (itemLegsCur.DPCur + 99) / 100,
      (itemLegsCur.DPMax + 99) / 100);
  fprintf(fpLegsData, "\n");

  // Type
  fprintf(fpLegsData, "TYPE\n");
  fprintf(fpLegsData, "============\n");
  fprintf(fpLegsData, "Blunt:    %2i\n", itemLegsCur.TypeBlunt);
  fprintf(fpLegsData, "Edged:    %2i\n", itemLegsCur.TypeEdged);
  fprintf(fpLegsData, "Piercing: %2i\n", itemLegsCur.TypePiercing);
  fprintf(fpLegsData, "\n");

  // Class
  fprintf(fpLegsData, "CLASS\n");
  fprintf(fpLegsData, "=============\n");
  fprintf(fpLegsData, "Human:    %3i\n", itemLegsCur.ClassHuman);
  fprintf(fpLegsData, "Beast:    %3i\n", itemLegsCur.ClassBeast);
  fprintf(fpLegsData, "Undead:   %3i\n", itemLegsCur.ClassUndead);
  fprintf(fpLegsData, "Phantom:  %3i\n", itemLegsCur.ClassPhantom);
  fprintf(fpLegsData, "Dragon:   %3i\n", itemLegsCur.ClassDragon);
  fprintf(fpLegsData, "Evil:     %3i\n", itemLegsCur.ClassEvil);
  fprintf(fpLegsData, "\n");

  // Affinity
  fprintf(fpLegsData, "AFFINITY\n");
  fprintf(fpLegsData, "=============\n");
  fprintf(fpLegsData, "Physical: %3i\n", itemLegsCur.AffinityPhysical);
  fprintf(fpLegsData, "Air:      %3i\n", itemLegsCur.AffinityAir);
  fprintf(fpLegsData, "Fire:     %3i\n", itemLegsCur.AffinityFire);
  fprintf(fpLegsData, "Earth:    %3i\n", itemLegsCur.AffinityEarth);
  fprintf(fpLegsData, "Water:    %3i\n", itemLegsCur.AffinityWater);
  fprintf(fpLegsData, "Light:    %3i\n", itemLegsCur.AffinityLight);
  fprintf(fpLegsData, "Dark:     %3i\n", itemLegsCur.AffinityDark);

  fclose(fpLegsData);
}

void
WriteNeckData()
{
  u8 ListPositionMax = 127;
  u8 ListPositionMin = (ListPositionMax - (_countof(AccessoriesList) - 1));
  // Check for out-of-bound indexes
  if (itemNeckCur.NamesListPosition > _countof(ItemNamesList))
  {
    return;
  }

  FILE *fpNeckData = fopen("game_data/armor/neck.txt", "w");

  // Check if a necklace is eqipped.
  // If not, write the warning and skip the rest.
  if (itemNeckCur.ListPosition < ListPositionMin ||
      itemNeckCur.ListPosition > ListPositionMax)
  {
    fprintf(fpNeckData, "No necklace equipped!\n");
    fclose(fpNeckData);

    return;
  }

  fprintf(fpNeckData, "Necklace Stats\n\n");

  fprintf(
      fpNeckData, "Name: %s\n", ItemNamesList[itemNeckCur.NamesListPosition]);
  fprintf(fpNeckData, "\n");

  // Bonuses
  fprintf(fpNeckData, "BONUSES\n");
  fprintf(fpNeckData, "========\n");
  fprintf(fpNeckData, "STR: %3i\n", itemNeckCur.STR);
  fprintf(fpNeckData, "INT: %3i\n", itemNeckCur.INT);
  fprintf(fpNeckData, "AGL: %3i\n", itemNeckCur.AGL);
  fprintf(fpNeckData, "\n");

  // Type
  fprintf(fpNeckData, "TYPE\n");
  fprintf(fpNeckData, "============\n");
  fprintf(fpNeckData, "Blunt:    %2i\n", itemNeckCur.TypeBlunt);
  fprintf(fpNeckData, "Edged:    %2i\n", itemNeckCur.TypeEdged);
  fprintf(fpNeckData, "Piercing: %2i\n", itemNeckCur.TypePiercing);
  fprintf(fpNeckData, "\n");

  // Class
  fprintf(fpNeckData, "CLASS\n");
  fprintf(fpNeckData, "=============\n");
  fprintf(fpNeckData, "Human:    %3i\n", itemNeckCur.ClassHuman);
  fprintf(fpNeckData, "Beast:    %3i\n", itemNeckCur.ClassBeast);
  fprintf(fpNeckData, "Undead:   %3i\n", itemNeckCur.ClassUndead);
  fprintf(fpNeckData, "Phantom:  %3i\n", itemNeckCur.ClassPhantom);
  fprintf(fpNeckData, "Dragon:   %3i\n", itemNeckCur.ClassDragon);
  fprintf(fpNeckData, "Evil:     %3i\n", itemNeckCur.ClassEvil);
  fprintf(fpNeckData, "\n");

  // Affinity
  fprintf(fpNeckData, "AFFINITY\n");
  fprintf(fpNeckData, "=============\n");
  fprintf(fpNeckData, "Physical: %3i\n", itemNeckCur.AffinityPhysical);
  fprintf(fpNeckData, "Air:      %3i\n", itemNeckCur.AffinityAir);
  fprintf(fpNeckData, "Fire:     %3i\n", itemNeckCur.AffinityFire);
  fprintf(fpNeckData, "Earth:    %3i\n", itemNeckCur.AffinityEarth);
  fprintf(fpNeckData, "Water:    %3i\n", itemNeckCur.AffinityWater);
  fprintf(fpNeckData, "Light:    %3i\n", itemNeckCur.AffinityLight);
  fprintf(fpNeckData, "Dark:     %3i\n", itemNeckCur.AffinityDark);

  fclose(fpNeckData);
}

void
WriteArmorData()
{
  WriteGloveLeftData();
  WriteGloveRightData();
  WriteHeadData();
  WriteBodyData();
  WriteLegsData();
  WriteNeckData();
}

#endif
