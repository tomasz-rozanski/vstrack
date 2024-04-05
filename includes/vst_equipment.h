#ifndef _VST_EQUIPMENT_H
#define _VST_EQUIPMENT_H

//
// Entry Points
//

// Weapon
#define OFFSET_EQUIPPED_WEAPON_BLADE 0x11fa94
#define OFFSET_EQUIPPED_WEAPON_GRIP 0x11fac4
#define OFFSET_EQUIPPED_WEAPON_GEM_SLOT1 0x11faf4
#define OFFSET_EQUIPPED_WEAPON_GEM_SLOT2 0x11fb24
#define OFFSET_EQUIPPED_WEAPON_GEM_SLOT3 0x11fb54

// Shield
#define OFFSET_EQUIPPED_SHIELD 0x11fc2c
#define OFFSET_EQUIPPED_SHIELD_GEM_SLOT1 0x11fc5c
#define OFFSET_EQUIPPED_SHIELD_GEM_SLOT2 0x11fc8c
#define OFFSET_EQUIPPED_SHIELD_GEM_SLOT3 0x11fcbc

// Armor
#define OFFSET_EQUIPPED_RIGHT_ARM 0x11fdf8
#define OFFSET_EQUIPPED_LEFT_ARM 0x11fed4
#define OFFSET_EQUIPPED_BODY 0x12008c
#define OFFSET_EQUIPPED_LEGS 0x120168
#define OFFSET_EQUIPPED_HEAD 0x11ffb0
#define OFFSET_EQUIPPED_NECK 0x11fd78

//
// Weapon Class (Equipped)
//
#define OFFSET_WEAPON_CLASS_HUMAN 0x11fab4
#define OFFSET_WEAPON_CLASS_BEAST 0x11fab5
#define OFFSET_WEAPON_CLASS_UNDEAD 0x11fab6
#define OFFSET_WEAPON_CLASS_PHANTOM 0x11fab7
#define OFFSET_WEAPON_CLASS_DRAGON 0x11fab8
#define OFFSET_WEAPON_CLASS_EVIL 0x11fab9

//
// Weapon Affinity (Equipped)
//
#define OFFSET_WEAPON_AFFINITY_PHYSICAL 0x11fabc
#define OFFSET_WEAPON_AFFINITY_AIR 0x11fabd
#define OFFSET_WEAPON_AFFINITY_FIRE 0x11fabe
#define OFFSET_WEAPON_AFFINITY_EARTH 0x11fabf
#define OFFSET_WEAPON_AFFINITY_WATER 0x11fac0
#define OFFSET_WEAPON_AFFINITY_LIGHT 0x11fac1
#define OFFSET_WEAPON_AFFINITY_DARK 0x11fac2

wchar_t *ItemNamesList[512] = { L"", L"Battle Knife", L"Scramasax", L"Dirk",
    L"Throwing Knife", L"Kudi", L"Cinquedea", L"Kris", L"Hatchet", L"Khukuri",
    L"Baselard", L"Stiletto", L"Jamadhar", L"Spatha", L"Scimitar", L"Rapier",
    L"Short Sword", L"Firangi", L"Shamshir", L"Falchion", L"Shotel", L"Khora",
    L"Khopesh", L"Wakizashi", L"Rhomphaia", L"Broad Sword", L"Norse Sword", L"Katana",
    L"Executioner", L"Claymore", L"Schiavona", L"Bastard Sword", L"Nodachi",
    L"Rune Blade", L"Holy Win", L"Hand Axe", L"Battle Axe", L"Francisca", L"Tabarzin",
    L"Chamkaq", L"Tabar", L"Bullova", L"Crescent", L"Goblin Club", L"Spiked Club",
    L"Ball Mace", L"Footman\'s Mace", L"Morning Star", L"War Hammer", L"Bec de Corbin",
    L"War Maul", L"Guisarme", L"Large Crescent", L"Sabre Halberd", L"Balbriggan",
    L"Double Blade", L"Halberd", L"Wizard Staff", L"Clergy Rod", L"Summoner Baton",
    L"Shamanic Staff", L"Bishop\'s Crosier", L"Sage\'s Cane", L"Langdebeve",
    L"Sabre Mace", L"Footman\'s Mace", L"Gloomwing", L"Mjolnir", L"Griever",
    L"Destroyer", L"Hand of Light", L"Spear", L"Glaive", L"Scorpion", L"Corcesca",
    L"Trident", L"Awl Pike", L"Boar Spear", L"Fauchard", L"Voulge", L"Pole Axe",
    L"Bardysh", L"Brandestoc", L"Gastraph Bow", L"Light Crossbow", L"Target Bow",
    L"Windlass", L"Cranequin", L"Lug Crossbow", L"Siege Bow", L"Arbalest", L"untitled",
    L"untitled", L"untitled", L"untitled", L"untitled", L"Short Hilt", L"Swept Hilt",
    L"Cross Guard", L"Knuckle Guard", L"Counter Guard", L"Side Ring", L"Power Palm",
    L"Murderer\'s Hilt", L"Spiral Hilt", L"Wooden Grip", L"Sand Face", L"Czekan Type",
    L"Sarissa Grip", L"Gendarme", L"Heavy Grip", L"Runkasyle", L"Bhuj Type",
    L"Grimoire Grip", L"Elephant", L"Wooden Pole", L"Spiculum Pole", L"Winged Pole",
    L"Framea Pole", L"Ahlspies", L"Spiral Pole", L"Simple Bolt", L"Steel Bolt",
    L"Javelin Bolt", L"Falarica Bolt", L"Stone Bullet", L"Sonic Bullet", L"Buckler",
    L"Pelta Shield", L"Targe", L"Quad Shield", L"Circle Shield", L"Tower Shield",
    L"Spiked Shield", L"Round Shield", L"Kite Shield", L"Casserole Shield",
    L"Heater Shield", L"Oval Shield", L"Knight Shield", L"Hoplite Shield",
    L"Jazeraint Shield", L"Dread Shield", L"Bandana", L"Bear Mask", L"Wizard Hat",
    L"Bone Helm", L"Chain Coif", L"Spangenhelm", L"Cabasset", L"Sallet", L"Barbut",
    L"Basinet", L"Armet", L"Close Helm", L"Burgonet", L"Hoplite Helm",
    L"Jazeraint Helm", L"Dread Helm", L"Jerkin", L"Hauberk", L"Wizard Robe", L"Cuirass",
    L"Banded Mail", L"Ring Mail", L"Chain Mail", L"Breastplate", L"Segmentata",
    L"Scale Armor", L"Brigandine", L"Plate Mail", L"Fluted Armor", L"Hoplite Armor",
    L"Jazeraint Armor", L"Dread Armor", L"Sandals", L"Boots", L"Long Boots", L"Cuisse",
    L"Light Greave", L"Ring Leggings", L"Chain Leggings", L"Fusskampf", L"Poleyn",
    L"Jambeau", L"Missaglia", L"Plate Leggings", L"Fluted Leggings",
    L"Hoplite Leggings", L"Jazeraint Leggings", L"Dread Leggings", L"Bandage",
    L"Leather Glove", L"Reinforced Glove", L"Knuckles", L"Ring Sleeve",
    L"Chain Sleeve", L"Gauntlet", L"Vambrace", L"Plate Glove", L"Rondanche",
    L"Tilt Glove", L"Freiturnier", L"Fluted Glove", L"Hoplite Glove",
    L"Jazeraint Glove", L"Dread Glove", L"untitled", L"untitled", L"untitled",
    L"untitled", L"untitled", L"untitled", L"untitled", L"untitled", L"untitled",
    L"untitled", L"untitled", L"untitled", L"untitled", L"untitled", L"untitled",
    L"untitled", L"Rood Necklace", L"Rune Earrings", L"Lionhead", L"Rusted Nails",
    L"Sylphid Ring", L"Marduk", L"Salamander Ring", L"Tamulis Tongue",
    L"Gnome Bracelet", L"Palolo\'s Ring", L"Undine Bracelet", L"Talian Ring",
    L"Agrias\'s Balm", L"Kadesh Ring", L"Agrippa\'s Choker", L"Diadra\'s Earring",
    L"Titan\'s Ring", L"Lau Fei\'s Armlet", L"Swan Song", L"Pushpaka",
    L"Edgar\'s Earrings", L"Cross Choker", L"Ghost Hound", L"Beaded Anklet",
    L"Dragonhead", L"Faufnir\'s Tear", L"Agales\'s Chain", L"Balam Ring",
    L"Nimje Coif", L"Morgan\'s Nails", L"Marlene\'s Ring", L"Wood", L"Leather",
    L"Bronze", L"Iron", L"Hagane", L"Silver", L"Damascus", L"Talos Feldspar",
    L"Titan Malachite", L"Sylphid Topaz", L"Djinn Amber", L"Salamander Ruby",
    L"Ifrit Carnelian", L"Gnome Emerald", L"Dao Moonstone", L"Undine Jasper",
    L"Marid Aquamarine", L"Angel Pearl", L"Seraphim Diamond", L"Morlock Jet",
    L"Berial Blackpearl", L"Haeralis", L"Orlandu", L"Orion", L"Ogmius", L"Iocus",
    L"Balvus", L"Trinity", L"Beowulf", L"Dragonite", L"Sigguld", L"Demonia", L"Altema",
    L"Polaris", L"Basivalen", L"Galerian", L"Vedivier", L"Berion", L"Gervin", L"Tertia",
    L"Lancer", L"Arturos", L"Braveheart", L"Hellraiser", L"Nightkiller", L"Manabreaker",
    L"Powerfist", L"Brainshield", L"Speedster", L"untitled", L"Silent Queen",
    L"Dark Queen", L"Death Queen", L"White Queen", L"untitled", L"untitled",
    L"untitled", L"untitled", L"untitled", L"untitled", L"untitled", L"untitled",
    L"untitled", L"untitled", L"untitled", L"untitled", L"untitled", L"untitled",
    L"untitled", L"Cure Root", L"Cure Bulb", L"Cure Tonic", L"Cure Potion",
    L"Mana Root", L"Mana Bulb", L"Mana Tonic", L"Mana Potion", L"Vera Root",
    L"Vera Bulb", L"Vera Tonic", L"Vera Potion", L"Acolyte\'s Nostrum",
    L"Saint\'s Nostrum", L"Alchemist\'s Reagent", L"Sorcerer\'s Reagent",
    L"Yggdrasil\'s Tears", L"Faerie Chortle", L"Spirit Orison", L"Angelic Paean",
    L"Panacea", L"Snowfly Draught", L"Faerie Wing", L"Elixir of Kings",
    L"Elixir of Sages", L"Elixir of Dragoons", L"Elixir of Queens",
    L"Elixir of Mages", L"Valens", L"Prudens", L"Volare", L"Audentia", L"Virtus",
    L"Eye of Argon", L"untitled", L"untitled", L"untitled", L"untitled", L"untitled",
    L"untitled", L"untitled", L"untitled", L"untitled", L"untitled", L"untitled",
    L"untitled", L"untitled", L"untitled", L"untitled", L"untitled", L"untitled",
    L"untitled", L"untitled", L"untitled", L"untitled", L"untitled", L"untitled",
    L"untitled", L"untitled", L"untitled", L"untitled", L"untitled", L"untitled",
    L"Grimoire Zephyr", L"Grimoire Teslae", L"Grimoire Incendie", L"Grimoire Terre",
    L"Grimoire Glace", L"Grimoire Lux", L"Grimoire Patir", L"Grimoire Exsorcer",
    L"Grimoire Banish", L"Grimoire Demolir", L"untitled", L"untitled", L"untitled",
    L"Grimoire Foudre", L"untitled", L"untitled", L"untitled", L"Grimoire Flamme",
    L"untitled", L"untitled", L"untitled", L"Grimoire Gaea", L"untitled", L"untitled",
    L"untitled", L"Grimoire Avalanche", L"untitled", L"untitled", L"untitled",
    L"Grimoire Radius", L"untitled", L"untitled", L"untitled", L"Grimoire Meteore",
    L"untitled", L"untitled", L"untitled", L"Grimoire Egout", L"Grimoire Demance",
    L"Grimoire Guerir", L"Grimoire Mollesse", L"Grimoire Antidote", L"Grimoire Benir",
    L"Grimoire Purifier", L"Grimoire Vie", L"Grimoire Intensite", L"Grimoire Debile",
    L"Grimoire Eclairer", L"Grimoire Nuageux", L"Grimoire Agilite",
    L"Grimoire Tardif", L"Grimoire Ameliorer", L"Grimoire Deteriorer",
    L"Grimoire Muet", L"Grimoire Annuler", L"Grimoire Paralysie", L"Grimoire Venin",
    L"Grimoire Fleau", L"Grimoire Halte", L"Grimoire Dissiper", L"Grimoire Clef",
    L"Grimoire Visible", L"Grimoire Analyse", L"Grimoire Sylphe",
    L"Grimoire Salamandre", L"Grimoire Gnome", L"Grimoire Undine",
    L"Grimoire Parebrise", L"Grimoire Ignifuge", L"Grimoire Rempart",
    L"Grimoire Barrer", L"untitled", L"Bronze Key", L"Iron Key", L"Silver Key",
    L"Gold Key", L"Platinum Key", L"Steel Key", L"Crimson Key", L"Chest Key",
    L"Chamomile Sigil", L"Lily Sigil", L"Tearose Sigil", L"Clematis Sigil",
    L"Hyacinth Sigil", L"Fern Sigil", L"Aster Sigil", L"Eulelia Sigil",
    L"Melissa Sigil", L"Calla Sigil", L"Laurel Sigil", L"Acacia Sigil", L"Palm Sigil",
    L"Kalmia Sigil", L"Colombine Sigil", L"Anemone Sigil", L"Verbena Sigil",
    L"Schirra Sigil", L"Marigold Sigil", L"Azalea Sigil", L"Tigertail Sigil",
    L"Stock Sigil", L"Cattleya Sigil", L"Mandrake Sigil", L"untitled", L"untitled",
    L"untitled", L"untitled", L"untitled", L"untitled", L"untitled", L"untitled",
    L"untitled", L"untitled", L"untitled", L"untitled", L"untitled", L"untitled",
    L"untitled", L"untitled", L"untitled", L"untitled", L"untitled", L"untitled",
    L"untitled", L"untitled" };

wchar_t *ArmorsList[81] = { L"", L"Buckler", L"Pelta Shield", L"Targe", L"Quad Shield",
    L"Circle Shield", L"Tower Shield", L"Spiked Shield", L"Round Shield",
    L"Kite Shield", L"Casserole Shield", L"Heater Shield", L"Oval Shield",
    L"Knight Shield", L"Hoplite Shield", L"Jazeraint Shield", L"Dread Shield",
    L"Bandana", L"Bear Mask", L"Wizard Hat", L"Bone Helm", L"Chain Coif",
    L"Spangenhelm", L"Cabasset", L"Sallet", L"Barbut", L"Basinet", L"Armet",
    L"Close Helm", L"Burgonet", L"Hoplite Helm", L"Jazeraint Helm", L"Dread Helm",
    L"Jerkin", L"Hauberk", L"Wizard Robe", L"Cuirass", L"Banded Mail", L"Ring Mail",
    L"Chain Mail", L"Breastplate", L"Segmentata", L"Scale Armor", L"Brigandine",
    L"Plate Mail", L"Fluted Armor", L"Hoplite Armor", L"Jazeraint Armor",
    L"Dread Armor", L"Sandals", L"Boots", L"Long Boots", L"Cuisse", L"Light Greave",
    L"Ring Leggings", L"Chain Leggings", L"Fusskampf", L"Poleyn", L"Jambeau",
    L"Missaglia", L"Plate Leggings", L"Fluted Leggings", L"Hoplite Leggings",
    L"Jazeraint Leggings", L"Dread Leggings", L"Bandage", L"Leather Glove",
    L"Reinforced Glove", L"Knuckles", L"Ring Sleeve", L"Chain Sleeve", L"Gauntlet",
    L"Vambrace", L"Plate Glove", L"Rondanche", L"Tilt Glove", L"Freiturnier",
    L"Fluted Glove", L"Hoplite Glove", L"Jazeraint Glove", L"Dread Glove" };

wchar_t *WeaponsList[91] = { L"", L"Battle Knife", L"Scramasax", L"Dirk",
    L"Throwing Knife", L"Kudi", L"Cinquedea", L"Kris", L"Hatchet", L"Khukuri",
    L"Baselard", L"Stiletto", L"Jamadhar", L"Spatha", L"Scimitar", L"Rapier",
    L"Short Sword", L"Firangi", L"Shamshir", L"Falchion", L"Shotel", L"Khora",
    L"Khopesh", L"Wakizashi", L"Rhomphaia", L"Broad Sword", L"Norse Sword", L"Katana",
    L"Executioner", L"Claymore", L"Schiavona", L"Bastard Sword", L"Nodachi",
    L"Rune Blade", L"Holy Win", L"Hand Axe", L"Battle Axe", L"Francisca", L"Tabarzin",
    L"Chamkaq", L"Tabar", L"Bullova", L"Crescent", L"Goblin Club", L"Spiked Club",
    L"Ball Mace", L"Footman\'s Mace", L"Morning Star", L"War Hammer", L"Bec de Corbin",
    L"War Maul", L"Guisarme", L"Large Crescent", L"Sabre Halberd", L"Balbriggan",
    L"Double Blade", L"Halberd", L"Wizard Staff", L"Clergy Rod", L"Summoner Baton",
    L"Shamanic Staff", L"Bishop\'s Crosier", L"Sage\'s Cane", L"Langdebeve",
    L"Sabre Mace", L"Footman\'s Mace", L"Gloomwing", L"Mjolnir", L"Griever",
    L"Destroyer", L"Hand of Light", L"Spear", L"Glaive", L"Scorpion", L"Corcesca",
    L"Trident", L"Awl Pike", L"Boar Spear", L"Fauchard", L"Voulge", L"Pole Axe",
    L"Bardysh", L"Brandestoc", L"Gastraph Bow", L"Light Crossbow", L"Target Bow",
    L"Windlass", L"Cranequin", L"Lug Crossbow", L"Siege Bow", L"Arbalest" };

// The first element of this array should start at index 97 (0x61),
// so make adjustments in a funcions reading it.
wchar_t *AccessoriesList[31] = { L"Rood Necklace", L"Rune Earrings", L"Lionhead",
    L"Rusted Nails", L"Sylphid Ring", L"Marduk", L"Salamander Ring", L"Tamulis Tongue",
    L"Gnome Bracelet", L"Palolo\'s Ring", L"Undine Bracelet", L"Talian Ring",
    L"Agrias\'s Balm", L"Kadesh Ring", L"Agrippa\'s Choker", L"Diadra\'s Earring",
    L"Titan\'s Ring", L"Lau Fei\'s Armlet", L"Swan Song", L"Pushpaka",
    L"Edgar\'s Earrings", L"Cross Choker", L"Ghost Hound", L"Beaded Anklet",
    L"Dragonhead", L"Faufnir\'s Tear", L"Agales\'s Chain", L"Balam Ring",
    L"Nimje Coif", L"Morgan\'s Nails", L"Marlene\'s Ring" };

wchar_t *GripsList[32] = { L"", L"Short Hilt", L"Swept Hilt", L"Cross Guard",
    L"Knuckle Guard", L"Counter Guard", L"Side Ring", L"Power Palm",
    L"Murderer's Hilt", L"Spiral Hilt", L"Wooden Grip", L"Sand Face", L"Czekan Type",
    L"Sarissa Grip", L"Gendarme", L"Heavy Grip", L"Runkasyle", L"Bhuj Type",
    L"Grimoire Grip", L"Elephant", L"Wooden Pole", L"Spiculum Pole", L"Winged Pole",
    L"Framea Pole", L"Ahlspies", L"Spiral Pole", L"Simple Bolt", L"Steel Bolt",
    L"Javelin Bolt", L"Falarica Bolt", L"Stone Bullet", L"Sonic Bullet" };

wchar_t *GemsList[63] = { L"None", L"Talos Feldspar", L"Titan Malachite",
    L"Sylphid Topaz", L"Djinn Amber", L"Salamander Ruby", L"Ifrit Carnelian",
    L"Gnome Emerald", L"Dao Moonstone", L"Undine Jasper", L"Marid Aquamarine",
    L"Angel Pearl", L"Seraphim Diamond", L"Morlock Jet", L"Berial Blackpearl",
    L"Haeralis", L"Orlandu", L"Orion", L"Ogmius", L"Iocus", L"Balvus", L"Trinity",
    L"Beowulf", L"Dragonite", L"Sigguld", L"Demonia", L"Altema", L"Polaris",
    L"Basivalen", L"Galerian", L"Vedivier", L"Berion", L"Gervin", L"Tertia", L"Lancer",
    L"Arturos", L"Braveheart", L"Hellraiser", L"Nightkiller", L"Manabreaker",
    L"Powerfist", L"Brainshield", L"Speedster", L"untitled", L"Silent Queen",
    L"Dark Queen", L"Death Queen", L"White Queen", L"untitled", L"untitled",
    L"untitled", L"untitled", L"untitled", L"untitled", L"untitled", L"untitled",
    L"untitled", L"untitled", L"untitled", L"untitled", L"untitled", L"untitled",
    L"untitled" };

wchar_t *ArmorsCategories[8] = { L"", L"Shield", L"Helm", L"Breast Armor", L"Leggings",
    L"Glove", L"unused", L"Accessory" };

wchar_t *WeaponsCategories[11] = { L"", L"Daggers", L"Swords", L"Great Swords",
    L"Axes & Maces", L"Great Axes", L"Staves", L"Heavy Maces", L"Polearms",
    L"Crossbows", L"Bare Hands" };

wchar_t *WeaponDamageType[4] = { L"", L"Blunt", L"Edged", L"Piercing" };

wchar_t *WeaponAttackCostType[6] = { L"", L"MP", L"RISK", L"HP", L"PP", L"nothing" };

wchar_t *CraftingMaterials[8] = { L"", L"Wood", L"Leather", L"Bronze", L"Iron",
    L"Hagane", L"Silver", L"Damascus" };

wchar_t *ItemClass[10] = { L"", L"Warrior's ", L"Knightly ", L"Prestigious ", L"Brave ",
    L"Warlord ", L"Champion ", L"Glorious ", L"Supreme ", L"Divine " };

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
ClearLevelingFlags() {
    LevelingFlags.Flags.FlagsCompound = 0;
}

void
UpdateLevelingFlags() {
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

    if (HumanDiff) LevelingFlags.Flags.FlagsCompound |= LEVELING_FLAG_HUMAN;
    if (BeastDiff) LevelingFlags.Flags.FlagsCompound |= LEVELING_FLAG_BEAST;
    if (UndeadDiff) LevelingFlags.Flags.FlagsCompound |= LEVELING_FLAG_UNDEAD;
    if (PhantomDiff) LevelingFlags.Flags.FlagsCompound |= LEVELING_FLAG_PHANTOM;
    if (DragonDiff) LevelingFlags.Flags.FlagsCompound |= LEVELING_FLAG_DRAGON;
    if (EvilDiff) LevelingFlags.Flags.FlagsCompound |= LEVELING_FLAG_EVIL;
    if (PhysicalDiff) LevelingFlags.Flags.FlagsCompound |= LEVELING_FLAG_PHYSICAL;
    if (AirDiff) LevelingFlags.Flags.FlagsCompound |= LEVELING_FLAG_AIR;
    if (FireDiff) LevelingFlags.Flags.FlagsCompound |= LEVELING_FLAG_FIRE;
    if (EarthDiff) LevelingFlags.Flags.FlagsCompound |= LEVELING_FLAG_EARTH;
    if (WaterDiff) LevelingFlags.Flags.FlagsCompound |= LEVELING_FLAG_WATER;
    if (LightDiff) LevelingFlags.Flags.FlagsCompound |= LEVELING_FLAG_LIGHT;
    if (DarkDiff) LevelingFlags.Flags.FlagsCompound |= LEVELING_FLAG_DARK;
}

void
ReadBladeData() {
    usize BytesToRead = sizeof(item_data);
    usize BytesRead = ReadGameMemory(
            processID, OFFSET_EQUIPPED_WEAPON_BLADE, BytesToRead, &itemBladeCur);
}

void
ReadWeaponData() {
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
ReadShieldData() {
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
ReadGlovesData() {
    usize BytesToRead = sizeof(item_data);
    usize BytesRead;

    BytesRead = ReadGameMemory(
            processID, OFFSET_EQUIPPED_LEFT_ARM, BytesToRead, &itemGloveLeftCur);
    BytesRead = ReadGameMemory(
            processID, OFFSET_EQUIPPED_RIGHT_ARM, BytesToRead, &itemGloveRightCur);
}

void
ReadHeadData() {
    usize BytesToRead = sizeof(item_data);
    usize BytesRead;

    BytesRead = ReadGameMemory(
            processID, OFFSET_EQUIPPED_HEAD, BytesToRead, &itemHeadCur);
}

void
ReadBodyData() {
    usize BytesToRead = sizeof(item_data);
    usize BytesRead;

    BytesRead = ReadGameMemory(
            processID, OFFSET_EQUIPPED_BODY, BytesToRead, &itemBodyCur);
}

void
ReadLegsData() {
    usize BytesToRead = sizeof(item_data);
    usize BytesRead;

    BytesRead = ReadGameMemory(
            processID, OFFSET_EQUIPPED_LEGS, BytesToRead, &itemLegsCur);
}

void
ReadNeckData() {
    usize BytesToRead = sizeof(item_data);
    usize BytesRead;

    BytesRead = ReadGameMemory(
            processID, OFFSET_EQUIPPED_NECK, BytesToRead, &itemNeckCur);
}

void
ReadArmorData() {
    ReadGlovesData();
    ReadBodyData();
    ReadHeadData();
    ReadLegsData();
    ReadNeckData();
}

BOOL
ItemDataChanged(item_data *Item1, item_data *Item2) {
    usize DataSize = sizeof(item_data);

    BOOL Result = DataChanged((void *) Item1, (void *) Item2, DataSize);

    return Result;
}

BOOL
BladeDataChanged() {
    if (ItemDataChanged(&itemBladePrev, &itemBladeCur))
    {
        return TRUE;
    }
    return FALSE;
}

BOOL
WeaponDataChanged() {
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
ShieldDataChanged() {
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
ArmorDataChanged() {
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
PrintBladeLeveling(u8 BladeNumber) {

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

    switch (BladeNumber) {
        case 1:
            {
                swprintf_s(szBuffer, _countof(szBuffer), L"\n\n== BLADE 1 ==\n\n");
                WriteToBackBuffer();

                if (DragonCur == 100) {
                    swprintf_s(
                            szBuffer, _countof(szBuffer), L"Dragon:   %4i OK\n", DragonCur);
                } else {
                    swprintf_s(szBuffer, _countof(szBuffer), L"Dragon:   %4i %s\n", DragonCur,
                            DragonFlag ? L"++" : L"");
                }
                WriteToBackBuffer();

                if (PhysicalCur == 100) {
                    swprintf_s(
                            szBuffer, _countof(szBuffer), L"Physical: %4i OK\n", PhysicalCur);
                } else {
                    swprintf_s(szBuffer, _countof(szBuffer), L"Physical: %4i %s\n",
                            PhysicalCur, PhysicalFlag ? L"++" : L"");
                }
                WriteToBackBuffer();

                if (BeastCur == 100) {
                    swprintf_s(szBuffer, _countof(szBuffer), L"Beast:    %4i OK\n", BeastCur);
                } else {
                    swprintf_s(szBuffer, _countof(szBuffer), L"Beast:    %4i %s\n", BeastCur,
                            BeastFlag ? L"++" : L"");
                }
                WriteToBackBuffer();

                break;
            }

        case 2:
            {
                swprintf_s(szBuffer, _countof(szBuffer), L"\n\n== BLADE 2 ==\n\n");
                WriteToBackBuffer();

                if (PhantomCur == 100) {
                    swprintf_s(
                            szBuffer, _countof(szBuffer), L"Phantom: %4i OK\n", PhantomCur);
                } else {
                    swprintf_s(szBuffer, _countof(szBuffer), L"Phantom: %4i %s\n", PhantomCur,
                            PhantomFlag ? L"++" : L"");
                }
                WriteToBackBuffer();

                if (HumanCur == 100) {
                    swprintf_s(szBuffer, _countof(szBuffer), L"Human:   %4i OK\n", HumanCur);
                } else {
                    swprintf_s(szBuffer, _countof(szBuffer), L"Human:   %4i %s\n", HumanCur,
                            HumanFlag ? L"++" : L"");
                }
                WriteToBackBuffer();

                if (EarthCur == 100) {
                    swprintf_s(szBuffer, _countof(szBuffer), L"Earth:   %4i OK\n", EarthCur);
                } else {
                    swprintf_s(szBuffer, _countof(szBuffer), L"Earth:   %4i %s\n", EarthCur,
                            EarthFlag ? L"++" : L"");
                }
                WriteToBackBuffer();

                if (DarkCur == 100) {
                    swprintf_s(szBuffer, _countof(szBuffer), L"Dark:    %4i OK\n", DarkCur);
                } else {
                    swprintf_s(szBuffer, _countof(szBuffer), L"Dark:    %4i %s\n", DarkCur,
                            DarkFlag ? L"++" : L"");
                }
                WriteToBackBuffer();

                if (WaterCur == 100) {
                    swprintf_s(szBuffer, _countof(szBuffer), L"Water:   %4i OK\n", WaterCur);
                } else {
                    swprintf_s(szBuffer, _countof(szBuffer), L"Water:   %4i %s\n", WaterCur,
                            WaterFlag ? L"++" : L"");
                }
                WriteToBackBuffer();

                break;
            }

        case 3:
            {
                swprintf_s(szBuffer, _countof(szBuffer), L"\n\n== BLADE 3 ==\n\n");
                WriteToBackBuffer();

                if (FireCur == 100) {
                    swprintf_s(szBuffer, _countof(szBuffer), L"Fire: %4i OK\n", FireCur);
                } else {
                    swprintf_s(szBuffer, _countof(szBuffer), L"Fire: %4i %s\n", FireCur,
                            FireFlag ? L"++" : L"");
                }
                WriteToBackBuffer();

                if (AirCur == 100) {
                    swprintf_s(szBuffer, _countof(szBuffer), L"Air:  %4i OK\n", AirCur);
                } else {
                    swprintf_s(szBuffer, _countof(szBuffer), L"Air:  %4i %s\n", AirCur,
                            AirFlag ? L"++" : L"");
                }
                WriteToBackBuffer();

                break;
            }

        case 4:
            {
                swprintf_s(szBuffer, _countof(szBuffer), L"\n\n== BLADE 4 ==\n\n");
                WriteToBackBuffer();

                if (UndeadCur == 100) {
                    swprintf_s(szBuffer, _countof(szBuffer), L"Undead: %4i OK\n", UndeadCur);
                } else {
                    swprintf_s(szBuffer, _countof(szBuffer), L"Undead: %4i %s\n", UndeadCur,
                            UndeadFlag ? L"++" : L"");
                }
                WriteToBackBuffer();

                if (EvilCur == 100) {
                    swprintf_s(szBuffer, _countof(szBuffer), L"Evil:   %4i OK\n", EvilCur);
                } else {
                    swprintf_s(szBuffer, _countof(szBuffer), L"Evil:   %4i %s\n", EvilCur,
                            EvilFlag ? L"++" : L"");
                }
                WriteToBackBuffer();

                if (LightCur == 100) {
                    swprintf_s(szBuffer, _countof(szBuffer), L"Light:  %4i OK\n", LightCur);
                } else {
                    swprintf_s(szBuffer, _countof(szBuffer), L"Light:  %4i %s\n", LightCur,
                            LightFlag ? L"++" : L"");
                }
                WriteToBackBuffer();

                break;
            }

        default:
            {
                swprintf_s(
                        szBuffer, _countof(szBuffer), L"\nNo leveling weapon equipped\n\n");
                WriteToBackBuffer();
            }
    }
}

void
WriteBladeLeveling(u8 BladeNumber) {

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
                fwprintf(fpBladeLeveling, L"== BLADE 1 ==\n\n");

                if (DragonCur == 100) {
                    fwprintf(fpBladeLeveling, L"Dragon:   %4i OK\n", DragonCur);
                } else {
                    fwprintf(fpBladeLeveling, L"Dragon:   %4i %s\n", DragonCur,
                            DragonFlag ? L"++" : L"");
                }

                if (PhysicalCur == 100) {
                    fwprintf(fpBladeLeveling, L"Physical: %4i OK\n", PhysicalCur);
                } else {
                    fwprintf(fpBladeLeveling, L"Physical: %4i %s\n", PhysicalCur,
                            PhysicalFlag ? L"++" : L"");
                }

                if (BeastCur == 100) {
                    fwprintf(fpBladeLeveling, L"Beast:    %4i OK\n", BeastCur);
                } else {
                    fwprintf(fpBladeLeveling, L"Beast:    %4i %s\n", BeastCur,
                            BeastFlag ? L"++" : L"");
                }

                break;
            }

        case 2:
            {
                fwprintf(fpBladeLeveling, L"== BLADE 2 ==\n\n");

                if (PhantomCur == 100) {
                    fwprintf(fpBladeLeveling, L"Phantom: %4i OK\n", PhantomCur);
                } else {
                    fwprintf(fpBladeLeveling, L"Phantom: %4i %s\n", PhantomCur,
                            PhantomFlag ? L"++" : L"");
                }

                if (HumanCur == 100) {
                    fwprintf(fpBladeLeveling, L"Human:   %4i OK\n", HumanCur);
                } else {
                    fwprintf(fpBladeLeveling, L"Human:   %4i %s\n", HumanCur,
                            HumanFlag ? L"++" : L"");
                }

                if (EarthCur == 100) {
                    fwprintf(fpBladeLeveling, L"Earth:   %4i OK\n", EarthCur);
                } else {
                    fwprintf(fpBladeLeveling, L"Earth:   %4i %s\n", EarthCur,
                            EarthFlag ? L"++" : L"");
                }

                if (DarkCur == 100) {
                    fwprintf(fpBladeLeveling, L"Dark:    %4i OK\n", DarkCur);
                } else {
                    fwprintf(fpBladeLeveling, L"Dark:    %4i %s\n", DarkCur,
                            DarkFlag ? L"++" : L"");
                }

                if (WaterCur == 100) {
                    fwprintf(fpBladeLeveling, L"Water:   %4i OK\n", WaterCur);
                } else {
                    fwprintf(fpBladeLeveling, L"Water:   %4i %s\n", WaterCur,
                            WaterFlag ? L"++" : L"");
                }

                break;
            }

        case 3:
            {
                fwprintf(fpBladeLeveling, L"== BLADE 3 ==\n\n");

                if (FireCur == 100) {
                    fwprintf(fpBladeLeveling, L"Fire: %4i OK\n", FireCur);
                } else {
                    fwprintf(
                            fpBladeLeveling, L"Fire: %4i %s\n", FireCur, FireFlag ? L"++" : L"");
                }

                if (AirCur == 100) {
                    fwprintf(fpBladeLeveling, L"Air:  %4i OK\n", AirCur);
                } else {
                    fwprintf(fpBladeLeveling, L"Air:  %4i %s\n", AirCur, AirFlag ? L"++" : L"");
                }

                break;
            }

        case 4:
            {
                fwprintf(fpBladeLeveling, L"== BLADE 4 ==\n\n");

                if (UndeadCur == 100) {
                    fwprintf(fpBladeLeveling, L"Undead: %4i OK\n", UndeadCur);
                } else {
                    fwprintf(fpBladeLeveling, L"Undead: %4i %s\n", UndeadCur,
                            UndeadFlag ? L"++" : L"");
                }

                if (EvilCur == 100) {
                    fwprintf(fpBladeLeveling, L"Evil:   %4i OK\n", EvilCur);
                } else {
                    fwprintf(
                            fpBladeLeveling, L"Evil:   %4i %s\n", EvilCur, EvilFlag ? L"++" : L"");
                }

                if (LightCur == 100) {
                    fwprintf(fpBladeLeveling, L"Light:  %4i OK\n", LightCur);
                } else {
                    fwprintf(fpBladeLeveling, L"Light:  %4i %s\n", LightCur,
                            LightFlag ? L"++" : L"");
                }
                break;
            }

        default:
            {
                fwprintf(fpBladeLeveling, L"No leveling weapon equipped\n");
            }
    }
    fclose(fpBladeLeveling);
}

void
WriteBladeData() {
    // Check for out-of-bound indexes
    if (itemBladeCur.NamesListPosition > _countof(ItemNamesList) - 1 || //
            itemBladeCur.ListPosition > _countof(WeaponsList) - 1 || //
            itemBladeCur.Category > _countof(WeaponsCategories) - 1)
    {
        return;
    }

    FILE *fpBladeData = fopen("game_data/weapon/blade.txt", "w");

    // Check if weapon is eqipped
    if (itemBladeCur.ListPosition == 0) {
        fwprintf(
                fpBladeData, L"Can't read the blade data: weapon is not equipped!\n");
        fclose(fpBladeData);

        return;
    }

    fwprintf(fpBladeData, L"Blade Stats\n\n");

    fwprintf(fpBladeData, L"Name: %s\n", WeaponsList[itemBladeCur.ListPosition]);
    fwprintf(
            fpBladeData, L"Category: %s\n", WeaponsCategories[itemBladeCur.Category]);
    fwprintf(
            fpBladeData, L"Material: %s\n", CraftingMaterials[itemBladeCur.Material]);
    fwprintf(fpBladeData, L"Damage type: %s\n",
            WeaponDamageType[itemBladeCur.DamageType]);
    fwprintf(fpBladeData, L"\n");

    // Bonuses
    fwprintf(fpBladeData, L"BONUSES\n");
    fwprintf(fpBladeData, L"========\n");
    fwprintf(fpBladeData, L"STR: %3i\n", itemBladeCur.STR);
    fwprintf(fpBladeData, L"INT: %3i\n", itemBladeCur.INT);
    fwprintf(fpBladeData, L"AGL: %3i\n", itemBladeCur.AGL);
    fwprintf(fpBladeData, L"\n");

    // DP & PP
    fwprintf(fpBladeData, L"DURABILITY\n");
    fwprintf(fpBladeData, L"===========\n");
    fwprintf(fpBladeData, L"DP: %3i/%3i\n", (itemBladeCur.DPCur + 99) / 100,
            (itemBladeCur.DPMax + 99) / 100);
    fwprintf(fpBladeData, L"PP: %3i/%3i\n", itemBladeCur.PPCur, itemBladeCur.PPMax);
    fwprintf(fpBladeData, L"\n");

    // Misc
    fwprintf(fpBladeData, L"MISC\n");
    fwprintf(fpBladeData, L"=======================\n");

    // Range
    fwprintf(fpBladeData, L"Range (x/y/z): %2i/%2i/%2i\n", itemBladeCur.Range.x,
            itemBladeCur.Range.y, itemBladeCur.Range.z);

    // Resource cost
    fwprintf(fpBladeData, L"Attack cost: %i %s\n", itemBladeCur.StatsCostValue,
            WeaponAttackCostType[itemBladeCur.StatsCostType]);
    fwprintf(fpBladeData, L"\n");

    // Class
    fwprintf(fpBladeData, L"CLASS\n");
    fwprintf(fpBladeData, L"=============\n");
    fwprintf(fpBladeData, L"Human:    %3i\n", itemBladeCur.ClassHuman);
    fwprintf(fpBladeData, L"Beast:    %3i\n", itemBladeCur.ClassBeast);
    fwprintf(fpBladeData, L"Undead:   %3i\n", itemBladeCur.ClassUndead);
    fwprintf(fpBladeData, L"Phantom:  %3i\n", itemBladeCur.ClassPhantom);
    fwprintf(fpBladeData, L"Dragon:   %3i\n", itemBladeCur.ClassDragon);
    fwprintf(fpBladeData, L"Evil:     %3i\n", itemBladeCur.ClassEvil);
    fwprintf(fpBladeData, L"\n");

    // Affinity
    fwprintf(fpBladeData, L"AFFINITY\n");
    fwprintf(fpBladeData, L"=============\n");
    fwprintf(fpBladeData, L"Physical: %3i\n", itemBladeCur.AffinityPhysical);
    fwprintf(fpBladeData, L"Air:      %3i\n", itemBladeCur.AffinityAir);
    fwprintf(fpBladeData, L"Fire:     %3i\n", itemBladeCur.AffinityFire);
    fwprintf(fpBladeData, L"Earth:    %3i\n", itemBladeCur.AffinityEarth);
    fwprintf(fpBladeData, L"Water:    %3i\n", itemBladeCur.AffinityWater);
    fwprintf(fpBladeData, L"Light:    %3i\n", itemBladeCur.AffinityLight);
    fwprintf(fpBladeData, L"Dark:     %3i\n", itemBladeCur.AffinityDark);

    fclose(fpBladeData);
}

void
WriteWeaponData() {
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
    if (itemBladeCur.ListPosition == 0) {
        fwprintf(fpWeaponData, L"Weapon not equipped!\n");
        fclose(fpWeaponData);

        return;
    }

    fwprintf(fpWeaponData, L"Weapon Stats\n\n");

    fwprintf(fpWeaponData, L"Weapon name: %s\n", nameWeaponCur);
    fwprintf(
            fpWeaponData, L"Blade name: %s\n", WeaponsList[itemBladeCur.ListPosition]);
    fwprintf(
            fpWeaponData, L"Category: %s\n", WeaponsCategories[itemBladeCur.Category]);
    fwprintf(
            fpWeaponData, L"Material: %s\n", CraftingMaterials[itemBladeCur.Material]);
    fwprintf(fpWeaponData, L"Grip: %s\n", GripsList[itemGripCur.ListPosition]);
    fwprintf(fpWeaponData, L"Damage type: %s\n",
            WeaponDamageType[itemBladeCur.DamageType]);
    fwprintf(fpWeaponData, L"\n");

    // Bonuses
    i16 STRTotal = itemBladeCur.STR + itemGripCur.STR + itemGem1WeaponCur.STR +
        itemGem2WeaponCur.STR + itemGem3WeaponCur.STR;
    i16 INTTotal = itemBladeCur.INT + itemGripCur.INT + itemGem1WeaponCur.INT +
        itemGem2WeaponCur.INT + itemGem3WeaponCur.INT;
    i16 AGLTotal = itemBladeCur.AGL + itemGripCur.AGL + itemGem1WeaponCur.AGL +
        itemGem2WeaponCur.AGL + itemGem3WeaponCur.AGL;

    fwprintf(fpWeaponData, L"BONUSES\n");
    fwprintf(fpWeaponData, L"========\n");
    fwprintf(fpWeaponData, L"STR: %3i\n", STRTotal);
    fwprintf(fpWeaponData, L"INT: %3i\n", INTTotal);
    fwprintf(fpWeaponData, L"AGL: %3i\n", AGLTotal);
    fwprintf(fpWeaponData, L"\n");

    // DP & PP
    fwprintf(fpWeaponData, L"DURABILITY\n");
    fwprintf(fpWeaponData, L"===========\n");
    fwprintf(fpWeaponData, L"DP: %3i/%3i\n", (itemBladeCur.DPCur + 99) / 100,
            (itemBladeCur.DPMax + 99) / 100);
    fwprintf(
            fpWeaponData, L"PP: %3i/%3i\n", itemBladeCur.PPCur, itemBladeCur.PPMax);
    fwprintf(fpWeaponData, L"\n");

    // Misc
    fwprintf(fpWeaponData, L"MISC\n");
    fwprintf(fpWeaponData, L"=======================\n");

    // Range
    fwprintf(fpWeaponData, L"Range (x/y/z): %2i/%2i/%2i\n", itemBladeCur.Range.x,
            itemBladeCur.Range.y, itemBladeCur.Range.z);

    // Resource cost
    fwprintf(fpWeaponData, L"Attack cost: %i %s\n", itemBladeCur.StatsCostValue,
            WeaponAttackCostType[itemBladeCur.StatsCostType]);

    fwprintf(fpWeaponData, L"\n");

    // Gems
    u8 GemSlots = itemGripCur.GemSlots;
    if (GemSlots) {
        fwprintf(fpWeaponData, L"GEMS\n");
        fwprintf(fpWeaponData, L"=========================\n");

        fwprintf(fpWeaponData, L"Slot 1: %17s\n",
                GemsList[itemGem1WeaponCur.ListPosition]);

        if (GemSlots > 1) {
            fwprintf(fpWeaponData, L"Slot 2: %17s\n",
                    GemsList[itemGem2WeaponCur.ListPosition]);
        }
        if (GemSlots > 2) {
            fwprintf(fpWeaponData, L"Slot 3: %17s\n",
                    GemsList[itemGem3WeaponCur.ListPosition]);
        }
    }

    fwprintf(fpWeaponData, L"\n");

    // Type
    fwprintf(fpWeaponData, L"TYPE\n");
    fwprintf(fpWeaponData, L"============\n");
    fwprintf(fpWeaponData, L"Blunt:    %2i\n", itemGripCur.TypeBlunt);
    fwprintf(fpWeaponData, L"Edged:    %2i\n", itemGripCur.TypeEdged);
    fwprintf(fpWeaponData, L"Piercing: %2i\n", itemGripCur.TypePiercing);
    fwprintf(fpWeaponData, L"\n");

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
    fwprintf(fpWeaponData, L"CLASS\n");
    fwprintf(fpWeaponData, L"=============\n");
    fwprintf(fpWeaponData, L"Human:    %3i\n", ClassHumanTotal);
    fwprintf(fpWeaponData, L"Beast:    %3i\n", ClassBeastTotal);
    fwprintf(fpWeaponData, L"Undead:   %3i\n", ClassUndeadTotal);
    fwprintf(fpWeaponData, L"Phantom:  %3i\n", ClassPhantomTotal);
    fwprintf(fpWeaponData, L"Dragon:   %3i\n", ClassDragonTotal);
    fwprintf(fpWeaponData, L"Evil:     %3i\n", ClassEvilTotal);
    fwprintf(fpWeaponData, L"\n");

    // Affinity
    fwprintf(fpWeaponData, L"AFFINITY\n");
    fwprintf(fpWeaponData, L"=============\n");
    fwprintf(fpWeaponData, L"Physical: %3i\n", AffinityPhysicalTotal);
    fwprintf(fpWeaponData, L"Air:      %3i\n", AffinityAirTotal);
    fwprintf(fpWeaponData, L"Fire:     %3i\n", AffinityFireTotal);
    fwprintf(fpWeaponData, L"Earth:    %3i\n", AffinityEarthTotal);
    fwprintf(fpWeaponData, L"Water:    %3i\n", AffinityWaterTotal);
    fwprintf(fpWeaponData, L"Light:    %3i\n", AffinityLightTotal);
    fwprintf(fpWeaponData, L"Dark:     %3i\n", AffinityDarkTotal);

    fclose(fpWeaponData);
}

void
WriteShieldData() {
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
    if (itemShieldCur.ListPosition == 0) {
        fwprintf(fpShieldData, L"Shield not equipped!\n");
        fclose(fpShieldData);

        return;
    }

    fwprintf(fpShieldData, L"Shield Stats\n\n");

    fwprintf(fpShieldData, L"Name: %s\n", ArmorsList[itemShieldCur.ListPosition]);
    fwprintf(fpShieldData, L"Material: %s\n",
            CraftingMaterials[itemShieldCur.Material]);

    fwprintf(fpShieldData, L"\n");

    // Bonuses
    i16 STRTotal = itemShieldCur.STR + itemGem1ShieldCur.STR +
        itemGem2ShieldCur.STR + itemGem3ShieldCur.STR;
    i16 INTTotal = itemShieldCur.INT + itemGem1ShieldCur.INT +
        itemGem2ShieldCur.INT + itemGem3ShieldCur.INT;
    i16 AGLTotal = itemShieldCur.AGL + itemGem1ShieldCur.AGL +
        itemGem2ShieldCur.AGL + itemGem3ShieldCur.AGL;

    fwprintf(fpShieldData, L"BONUSES\n");
    fwprintf(fpShieldData, L"========\n");
    fwprintf(fpShieldData, L"STR: %3i\n", STRTotal);
    fwprintf(fpShieldData, L"INT: %3i\n", INTTotal);
    fwprintf(fpShieldData, L"AGL: %3i\n", AGLTotal);
    fwprintf(fpShieldData, L"\n");

    // DP & PP
    fwprintf(fpShieldData, L"DURABILITY\n");
    fwprintf(fpShieldData, L"===========\n");
    fwprintf(fpShieldData, L"DP: %3i/%3i\n", (itemShieldCur.DPCur + 99) / 100,
            (itemShieldCur.DPMax + 99) / 100);
    fwprintf(
            fpShieldData, L"PP: %3i/%3i\n", itemShieldCur.PPCur, itemShieldCur.PPMax);
    fwprintf(fpShieldData, L"\n");

    // Gems

    // Gems
    u8 GemSlots = itemShieldCur.GemSlots;
    if (GemSlots) {
        fwprintf(fpShieldData, L"GEMS\n");
        fwprintf(fpShieldData, L"=========================\n");

        fwprintf(fpShieldData, L"Slot 1: %17s\n",
                GemsList[itemGem1ShieldCur.ListPosition]);

        if (GemSlots > 1) {
            fwprintf(fpShieldData, L"Slot 2: %17s\n",
                    GemsList[itemGem2ShieldCur.ListPosition]);
        }
        if (GemSlots > 2) {
            fwprintf(fpShieldData, L"Slot 3: %17s\n",
                    GemsList[itemGem3ShieldCur.ListPosition]);
        }
    }
    fwprintf(fpShieldData, L"\n");

    // Type
    fwprintf(fpShieldData, L"TYPE\n");
    fwprintf(fpShieldData, L"============\n");
    fwprintf(fpShieldData, L"Blunt:    %2i\n", itemShieldCur.TypeBlunt);
    fwprintf(fpShieldData, L"Edged:    %2i\n", itemShieldCur.TypeEdged);
    fwprintf(fpShieldData, L"Piercing: %2i\n", itemShieldCur.TypePiercing);
    fwprintf(fpShieldData, L"\n");

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
    fwprintf(fpShieldData, L"CLASS\n");
    fwprintf(fpShieldData, L"=============\n");
    fwprintf(fpShieldData, L"Human:    %3i\n", ClassHumanTotal);
    fwprintf(fpShieldData, L"Beast:    %3i\n", ClassBeastTotal);
    fwprintf(fpShieldData, L"Undead:   %3i\n", ClassUndeadTotal);
    fwprintf(fpShieldData, L"Phantom:  %3i\n", ClassPhantomTotal);
    fwprintf(fpShieldData, L"Dragon:   %3i\n", ClassDragonTotal);
    fwprintf(fpShieldData, L"Evil:     %3i\n", ClassEvilTotal);
    fwprintf(fpShieldData, L"\n");

    // Affinity
    fwprintf(fpShieldData, L"AFFINITY\n");
    fwprintf(fpShieldData, L"=============\n");
    fwprintf(fpShieldData, L"Physical: %3i\n", AffinityPhysicalTotal);
    fwprintf(fpShieldData, L"Air:      %3i\n", AffinityAirTotal);
    fwprintf(fpShieldData, L"Fire:     %3i\n", AffinityFireTotal);
    fwprintf(fpShieldData, L"Earth:    %3i\n", AffinityEarthTotal);
    fwprintf(fpShieldData, L"Water:    %3i\n", AffinityWaterTotal);
    fwprintf(fpShieldData, L"Light:    %3i\n", AffinityLightTotal);
    fwprintf(fpShieldData, L"Dark:     %3i\n", AffinityDarkTotal);

    fclose(fpShieldData);
}

void
WriteGloveLeftData() {
    // Check for out-of-bound indexes
    if (itemGloveLeftCur.ListPosition > _countof(ArmorsList) - 1 || //
            itemGloveLeftCur.Material > _countof(CraftingMaterials) - 1)
    {
        return;
    }

    FILE *fpGloveLeftData = fopen("game_data/armor/glove_left.txt", "w");

    // Check if a glove is eqipped. If not, write the warning and skip the rest.
    if (itemGloveLeftCur.ListPosition == 0) {
        fwprintf(fpGloveLeftData, L"No left glove equipped!\n");

        fclose(fpGloveLeftData);

        return;
    }

    fwprintf(fpGloveLeftData, L"Left Glove Stats\n\n");

    fwprintf(
            fpGloveLeftData, L"Name: %s\n", ArmorsList[itemGloveLeftCur.ListPosition]);
    fwprintf(fpGloveLeftData, L"Material: %s\n",
            CraftingMaterials[itemGloveLeftCur.Material]);
    fwprintf(fpGloveLeftData, L"\n");

    // Bonuses
    fwprintf(fpGloveLeftData, L"BONUSES\n");
    fwprintf(fpGloveLeftData, L"========\n");
    fwprintf(fpGloveLeftData, L"STR: %3i\n", itemGloveLeftCur.STR);
    fwprintf(fpGloveLeftData, L"INT: %3i\n", itemGloveLeftCur.INT);
    fwprintf(fpGloveLeftData, L"AGL: %3i\n", itemGloveLeftCur.AGL);
    fwprintf(fpGloveLeftData, L"\n");

    // DP
    fwprintf(fpGloveLeftData, L"DURABILITY\n");
    fwprintf(fpGloveLeftData, L"===========\n");
    fwprintf(fpGloveLeftData, L"DP: %3i/%3i\n", (itemGloveLeftCur.DPCur + 99) / 100,
            (itemGloveLeftCur.DPMax + 99) / 100);
    fwprintf(fpGloveLeftData, L"\n");

    // Type
    fwprintf(fpGloveLeftData, L"TYPE\n");
    fwprintf(fpGloveLeftData, L"============\n");
    fwprintf(fpGloveLeftData, L"Blunt:    %2i\n", itemGloveLeftCur.TypeBlunt);
    fwprintf(fpGloveLeftData, L"Edged:    %2i\n", itemGloveLeftCur.TypeEdged);
    fwprintf(fpGloveLeftData, L"Piercing: %2i\n", itemGloveLeftCur.TypePiercing);
    fwprintf(fpGloveLeftData, L"\n");

    // Class
    fwprintf(fpGloveLeftData, L"CLASS\n");
    fwprintf(fpGloveLeftData, L"=============\n");
    fwprintf(fpGloveLeftData, L"Human:    %3i\n", itemGloveLeftCur.ClassHuman);
    fwprintf(fpGloveLeftData, L"Beast:    %3i\n", itemGloveLeftCur.ClassBeast);
    fwprintf(fpGloveLeftData, L"Undead:   %3i\n", itemGloveLeftCur.ClassUndead);
    fwprintf(fpGloveLeftData, L"Phantom:  %3i\n", itemGloveLeftCur.ClassPhantom);
    fwprintf(fpGloveLeftData, L"Dragon:   %3i\n", itemGloveLeftCur.ClassDragon);
    fwprintf(fpGloveLeftData, L"Evil:     %3i\n", itemGloveLeftCur.ClassEvil);
    fwprintf(fpGloveLeftData, L"\n");

    // Affinity
    fwprintf(fpGloveLeftData, L"AFFINITY\n");
    fwprintf(fpGloveLeftData, L"=============\n");
    fwprintf(
            fpGloveLeftData, L"Physical: %3i\n", itemGloveLeftCur.AffinityPhysical);
    fwprintf(fpGloveLeftData, L"Air:      %3i\n", itemGloveLeftCur.AffinityAir);
    fwprintf(fpGloveLeftData, L"Fire:     %3i\n", itemGloveLeftCur.AffinityFire);
    fwprintf(fpGloveLeftData, L"Earth:    %3i\n", itemGloveLeftCur.AffinityEarth);
    fwprintf(fpGloveLeftData, L"Water:    %3i\n", itemGloveLeftCur.AffinityWater);
    fwprintf(fpGloveLeftData, L"Light:    %3i\n", itemGloveLeftCur.AffinityLight);
    fwprintf(fpGloveLeftData, L"Dark:     %3i\n", itemGloveLeftCur.AffinityDark);

    fclose(fpGloveLeftData);
}

void
WriteGloveRightData() {
    // Check for out-of-bound indexes
    if (itemGloveRightCur.ListPosition > _countof(ArmorsList) - 1 || //
            itemGloveRightCur.Material > _countof(CraftingMaterials) - 1)
    {
        return;
    }

    FILE *fpGloveRightData = fopen("game_data/armor/glove_right.txt", "w");

    // Check if a glove is eqipped. If not, write the warning and skip the rest.
    if (itemGloveRightCur.ListPosition == 0) {
        fwprintf(fpGloveRightData, L"No left glove equipped!\n");

        fclose(fpGloveRightData);

        return;
    }

    fwprintf(fpGloveRightData, L"Right Glove Stats\n\n");

    fwprintf(fpGloveRightData, L"Name: %s\n",
            ArmorsList[itemGloveRightCur.ListPosition]);
    fwprintf(fpGloveRightData, L"Material: %s\n",
            CraftingMaterials[itemGloveRightCur.Material]);
    fwprintf(fpGloveRightData, L"\n");

    // Bonuses
    fwprintf(fpGloveRightData, L"BONUSES\n");
    fwprintf(fpGloveRightData, L"========\n");
    fwprintf(fpGloveRightData, L"STR: %3i\n", itemGloveRightCur.STR);
    fwprintf(fpGloveRightData, L"INT: %3i\n", itemGloveRightCur.INT);
    fwprintf(fpGloveRightData, L"AGL: %3i\n", itemGloveRightCur.AGL);
    fwprintf(fpGloveRightData, L"\n");

    // DP
    fwprintf(fpGloveRightData, L"DURABILITY\n");
    fwprintf(fpGloveRightData, L"===========\n");
    fwprintf(fpGloveRightData, L"DP: %3i/%3i\n",
            (itemGloveRightCur.DPCur + 99) / 100,
            (itemGloveRightCur.DPMax + 99) / 100);
    fwprintf(fpGloveRightData, L"\n");

    // Type
    fwprintf(fpGloveRightData, L"TYPE\n");
    fwprintf(fpGloveRightData, L"============\n");
    fwprintf(fpGloveRightData, L"Blunt:    %2i\n", itemGloveRightCur.TypeBlunt);
    fwprintf(fpGloveRightData, L"Edged:    %2i\n", itemGloveRightCur.TypeEdged);
    fwprintf(fpGloveRightData, L"Piercing: %2i\n", itemGloveRightCur.TypePiercing);
    fwprintf(fpGloveRightData, L"\n");

    // Class
    fwprintf(fpGloveRightData, L"CLASS\n");
    fwprintf(fpGloveRightData, L"=============\n");
    fwprintf(fpGloveRightData, L"Human:    %3i\n", itemGloveRightCur.ClassHuman);
    fwprintf(fpGloveRightData, L"Beast:    %3i\n", itemGloveRightCur.ClassBeast);
    fwprintf(fpGloveRightData, L"Undead:   %3i\n", itemGloveRightCur.ClassUndead);
    fwprintf(fpGloveRightData, L"Phantom:  %3i\n", itemGloveRightCur.ClassPhantom);
    fwprintf(fpGloveRightData, L"Dragon:   %3i\n", itemGloveRightCur.ClassDragon);
    fwprintf(fpGloveRightData, L"Evil:     %3i\n", itemGloveRightCur.ClassEvil);
    fwprintf(fpGloveRightData, L"\n");

    // Affinity
    fwprintf(fpGloveRightData, L"AFFINITY\n");
    fwprintf(fpGloveRightData, L"=============\n");
    fwprintf(
            fpGloveRightData, L"Physical: %3i\n", itemGloveRightCur.AffinityPhysical);
    fwprintf(fpGloveRightData, L"Air:      %3i\n", itemGloveRightCur.AffinityAir);
    fwprintf(fpGloveRightData, L"Fire:     %3i\n", itemGloveRightCur.AffinityFire);
    fwprintf(fpGloveRightData, L"Earth:    %3i\n", itemGloveRightCur.AffinityEarth);
    fwprintf(fpGloveRightData, L"Water:    %3i\n", itemGloveRightCur.AffinityWater);
    fwprintf(fpGloveRightData, L"Light:    %3i\n", itemGloveRightCur.AffinityLight);
    fwprintf(fpGloveRightData, L"Dark:     %3i\n", itemGloveRightCur.AffinityDark);

    fclose(fpGloveRightData);
}

void
WriteHeadData() {
    // Check for out-of-bound indexes
    if (itemHeadCur.ListPosition > _countof(ArmorsList) - 1 || //
            itemHeadCur.Material > _countof(CraftingMaterials) - 1)
    {
        return;
    }

    FILE *fpHeadData = fopen("game_data/armor/head.txt", "w");

    // Check if a head armor is eqipped.
    // If not, write the warning and skip the rest.
    if (itemHeadCur.ListPosition == 0) {
        fwprintf(fpHeadData, L"No head armor equipped!\n");
        fclose(fpHeadData);

        return;
    }

    fwprintf(fpHeadData, L"Helm Stats\n\n");

    fwprintf(fpHeadData, L"Name: %s\n", ArmorsList[itemHeadCur.ListPosition]);
    fwprintf(
            fpHeadData, L"Material: %s\n", CraftingMaterials[itemHeadCur.Material]);
    fwprintf(fpHeadData, L"\n");

    // Bonuses
    fwprintf(fpHeadData, L"BONUSES\n");
    fwprintf(fpHeadData, L"========\n");
    fwprintf(fpHeadData, L"STR: %3i\n", itemHeadCur.STR);
    fwprintf(fpHeadData, L"INT: %3i\n", itemHeadCur.INT);
    fwprintf(fpHeadData, L"AGL: %3i\n", itemHeadCur.AGL);
    fwprintf(fpHeadData, L"\n");

    // DP
    fwprintf(fpHeadData, L"DURABILITY\n");
    fwprintf(fpHeadData, L"===========\n");
    fwprintf(fpHeadData, L"DP: %3i/%3i\n", (itemHeadCur.DPCur + 99) / 100,
            (itemHeadCur.DPMax + 99) / 100);
    fwprintf(fpHeadData, L"\n");

    // Type
    fwprintf(fpHeadData, L"TYPE\n");
    fwprintf(fpHeadData, L"============\n");
    fwprintf(fpHeadData, L"Blunt:    %2i\n", itemHeadCur.TypeBlunt);
    fwprintf(fpHeadData, L"Edged:    %2i\n", itemHeadCur.TypeEdged);
    fwprintf(fpHeadData, L"Piercing: %2i\n", itemHeadCur.TypePiercing);
    fwprintf(fpHeadData, L"\n");

    // Class
    fwprintf(fpHeadData, L"CLASS\n");
    fwprintf(fpHeadData, L"=============\n");
    fwprintf(fpHeadData, L"Human:    %3i\n", itemHeadCur.ClassHuman);
    fwprintf(fpHeadData, L"Beast:    %3i\n", itemHeadCur.ClassBeast);
    fwprintf(fpHeadData, L"Undead:   %3i\n", itemHeadCur.ClassUndead);
    fwprintf(fpHeadData, L"Phantom:  %3i\n", itemHeadCur.ClassPhantom);
    fwprintf(fpHeadData, L"Dragon:   %3i\n", itemHeadCur.ClassDragon);
    fwprintf(fpHeadData, L"Evil:     %3i\n", itemHeadCur.ClassEvil);
    fwprintf(fpHeadData, L"\n");

    // Affinity
    fwprintf(fpHeadData, L"AFFINITY\n");
    fwprintf(fpHeadData, L"=============\n");
    fwprintf(fpHeadData, L"Physical: %3i\n", itemHeadCur.AffinityPhysical);
    fwprintf(fpHeadData, L"Air:      %3i\n", itemHeadCur.AffinityAir);
    fwprintf(fpHeadData, L"Fire:     %3i\n", itemHeadCur.AffinityFire);
    fwprintf(fpHeadData, L"Earth:    %3i\n", itemHeadCur.AffinityEarth);
    fwprintf(fpHeadData, L"Water:    %3i\n", itemHeadCur.AffinityWater);
    fwprintf(fpHeadData, L"Light:    %3i\n", itemHeadCur.AffinityLight);
    fwprintf(fpHeadData, L"Dark:     %3i\n", itemHeadCur.AffinityDark);

    fclose(fpHeadData);
}

void
WriteBodyData() {
    // Check for out-of-bound indexes
    if (itemBodyCur.ListPosition > _countof(ArmorsList) - 1 || //
            itemBodyCur.Material > _countof(CraftingMaterials) - 1)
    {
        return;
    }

    FILE *fpBodyData = fopen("game_data/armor/body.txt", "w");

    // Check if a body armor is eqipped. If not, write the warning and skip the
    // rest.
    if (itemBodyCur.ListPosition == 0) {
        // fwprintf(fpBodyData, L"No body armor equipped!\n");
        fwprintf(fpBodyData, L"No Breastplate Equipped!\n");
        fclose(fpBodyData);

        return;
    }

    fwprintf(fpBodyData, L"Body Armor Stats\n\n");

    fwprintf(fpBodyData, L"Name: %s\n", ArmorsList[itemBodyCur.ListPosition]);
    fwprintf(
            fpBodyData, L"Material: %s\n", CraftingMaterials[itemBodyCur.Material]);
    fwprintf(fpBodyData, L"\n");

    // Bonuses
    fwprintf(fpBodyData, L"BONUSES\n");
    fwprintf(fpBodyData, L"========\n");
    fwprintf(fpBodyData, L"STR: %3i\n", itemBodyCur.STR);
    fwprintf(fpBodyData, L"INT: %3i\n", itemBodyCur.INT);
    fwprintf(fpBodyData, L"AGL: %3i\n", itemBodyCur.AGL);
    fwprintf(fpBodyData, L"\n");

    // DP
    fwprintf(fpBodyData, L"DURABILITY\n");
    fwprintf(fpBodyData, L"===========\n");
    fwprintf(fpBodyData, L"DP: %3i/%3i\n", (itemBodyCur.DPCur + 99) / 100,
            (itemBodyCur.DPMax + 99) / 100);
    fwprintf(fpBodyData, L"\n");

    // Type
    fwprintf(fpBodyData, L"TYPE\n");
    fwprintf(fpBodyData, L"============\n");
    fwprintf(fpBodyData, L"Blunt:    %2i\n", itemBodyCur.TypeBlunt);
    fwprintf(fpBodyData, L"Edged:    %2i\n", itemBodyCur.TypeEdged);
    fwprintf(fpBodyData, L"Piercing: %2i\n", itemBodyCur.TypePiercing);
    fwprintf(fpBodyData, L"\n");

    // Class
    fwprintf(fpBodyData, L"CLASS\n");
    fwprintf(fpBodyData, L"=============\n");
    fwprintf(fpBodyData, L"Human:    %3i\n", itemBodyCur.ClassHuman);
    fwprintf(fpBodyData, L"Beast:    %3i\n", itemBodyCur.ClassBeast);
    fwprintf(fpBodyData, L"Undead:   %3i\n", itemBodyCur.ClassUndead);
    fwprintf(fpBodyData, L"Phantom:  %3i\n", itemBodyCur.ClassPhantom);
    fwprintf(fpBodyData, L"Dragon:   %3i\n", itemBodyCur.ClassDragon);
    fwprintf(fpBodyData, L"Evil:     %3i\n", itemBodyCur.ClassEvil);
    fwprintf(fpBodyData, L"\n");

    // Affinity
    fwprintf(fpBodyData, L"AFFINITY\n");
    fwprintf(fpBodyData, L"=============\n");
    fwprintf(fpBodyData, L"Physical: %3i\n", itemBodyCur.AffinityPhysical);
    fwprintf(fpBodyData, L"Air:      %3i\n", itemBodyCur.AffinityAir);
    fwprintf(fpBodyData, L"Fire:     %3i\n", itemBodyCur.AffinityFire);
    fwprintf(fpBodyData, L"Earth:    %3i\n", itemBodyCur.AffinityEarth);
    fwprintf(fpBodyData, L"Water:    %3i\n", itemBodyCur.AffinityWater);
    fwprintf(fpBodyData, L"Light:    %3i\n", itemBodyCur.AffinityLight);
    fwprintf(fpBodyData, L"Dark:     %3i\n", itemBodyCur.AffinityDark);

    fclose(fpBodyData);
}

void
WriteLegsData() {
    // Check for out-of-bound indexes
    if (itemLegsCur.ListPosition > _countof(ArmorsList) - 1 || //
            itemLegsCur.Material > _countof(CraftingMaterials) - 1)
    {
        return;
    }

    FILE *fpLegsData = fopen("game_data/armor/legs.txt", "w");

    // Check if a leg armor is eqipped.
    // If not, write the warning and skip the rest.
    if (itemLegsCur.ListPosition == 0) {
        fwprintf(fpLegsData, L"No legs armor equipped!\n");
        fclose(fpLegsData);

        return;
    }

    fwprintf(fpLegsData, L"Leggings Stats\n\n");

    fwprintf(fpLegsData, L"Name: %s\n", ArmorsList[itemLegsCur.ListPosition]);
    fwprintf(
            fpLegsData, L"Material: %s\n", CraftingMaterials[itemLegsCur.Material]);
    fwprintf(fpLegsData, L"\n");

    // Bonuses
    fwprintf(fpLegsData, L"BONUSES\n");
    fwprintf(fpLegsData, L"========\n");
    fwprintf(fpLegsData, L"STR: %3i\n", itemLegsCur.STR);
    fwprintf(fpLegsData, L"INT: %3i\n", itemLegsCur.INT);
    fwprintf(fpLegsData, L"AGL: %3i\n", itemLegsCur.AGL);
    fwprintf(fpLegsData, L"\n");

    // DP
    fwprintf(fpLegsData, L"DURABILITY\n");
    fwprintf(fpLegsData, L"===========\n");
    fwprintf(fpLegsData, L"DP: %3i/%3i\n", (itemLegsCur.DPCur + 99) / 100,
            (itemLegsCur.DPMax + 99) / 100);
    fwprintf(fpLegsData, L"\n");

    // Type
    fwprintf(fpLegsData, L"TYPE\n");
    fwprintf(fpLegsData, L"============\n");
    fwprintf(fpLegsData, L"Blunt:    %2i\n", itemLegsCur.TypeBlunt);
    fwprintf(fpLegsData, L"Edged:    %2i\n", itemLegsCur.TypeEdged);
    fwprintf(fpLegsData, L"Piercing: %2i\n", itemLegsCur.TypePiercing);
    fwprintf(fpLegsData, L"\n");

    // Class
    fwprintf(fpLegsData, L"CLASS\n");
    fwprintf(fpLegsData, L"=============\n");
    fwprintf(fpLegsData, L"Human:    %3i\n", itemLegsCur.ClassHuman);
    fwprintf(fpLegsData, L"Beast:    %3i\n", itemLegsCur.ClassBeast);
    fwprintf(fpLegsData, L"Undead:   %3i\n", itemLegsCur.ClassUndead);
    fwprintf(fpLegsData, L"Phantom:  %3i\n", itemLegsCur.ClassPhantom);
    fwprintf(fpLegsData, L"Dragon:   %3i\n", itemLegsCur.ClassDragon);
    fwprintf(fpLegsData, L"Evil:     %3i\n", itemLegsCur.ClassEvil);
    fwprintf(fpLegsData, L"\n");

    // Affinity
    fwprintf(fpLegsData, L"AFFINITY\n");
    fwprintf(fpLegsData, L"=============\n");
    fwprintf(fpLegsData, L"Physical: %3i\n", itemLegsCur.AffinityPhysical);
    fwprintf(fpLegsData, L"Air:      %3i\n", itemLegsCur.AffinityAir);
    fwprintf(fpLegsData, L"Fire:     %3i\n", itemLegsCur.AffinityFire);
    fwprintf(fpLegsData, L"Earth:    %3i\n", itemLegsCur.AffinityEarth);
    fwprintf(fpLegsData, L"Water:    %3i\n", itemLegsCur.AffinityWater);
    fwprintf(fpLegsData, L"Light:    %3i\n", itemLegsCur.AffinityLight);
    fwprintf(fpLegsData, L"Dark:     %3i\n", itemLegsCur.AffinityDark);

    fclose(fpLegsData);
}

void
WriteNeckData() {
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
        fwprintf(fpNeckData, L"No necklace equipped!\n");
        fclose(fpNeckData);

        return;
    }

    fwprintf(fpNeckData, L"Necklace Stats\n\n");

    fwprintf(
            fpNeckData, L"Name: %s\n", ItemNamesList[itemNeckCur.NamesListPosition]);
    fwprintf(fpNeckData, L"\n");

    // Bonuses
    fwprintf(fpNeckData, L"BONUSES\n");
    fwprintf(fpNeckData, L"========\n");
    fwprintf(fpNeckData, L"STR: %3i\n", itemNeckCur.STR);
    fwprintf(fpNeckData, L"INT: %3i\n", itemNeckCur.INT);
    fwprintf(fpNeckData, L"AGL: %3i\n", itemNeckCur.AGL);
    fwprintf(fpNeckData, L"\n");

    // Type
    fwprintf(fpNeckData, L"TYPE\n");
    fwprintf(fpNeckData, L"============\n");
    fwprintf(fpNeckData, L"Blunt:    %2i\n", itemNeckCur.TypeBlunt);
    fwprintf(fpNeckData, L"Edged:    %2i\n", itemNeckCur.TypeEdged);
    fwprintf(fpNeckData, L"Piercing: %2i\n", itemNeckCur.TypePiercing);
    fwprintf(fpNeckData, L"\n");

    // Class
    fwprintf(fpNeckData, L"CLASS\n");
    fwprintf(fpNeckData, L"=============\n");
    fwprintf(fpNeckData, L"Human:    %3i\n", itemNeckCur.ClassHuman);
    fwprintf(fpNeckData, L"Beast:    %3i\n", itemNeckCur.ClassBeast);
    fwprintf(fpNeckData, L"Undead:   %3i\n", itemNeckCur.ClassUndead);
    fwprintf(fpNeckData, L"Phantom:  %3i\n", itemNeckCur.ClassPhantom);
    fwprintf(fpNeckData, L"Dragon:   %3i\n", itemNeckCur.ClassDragon);
    fwprintf(fpNeckData, L"Evil:     %3i\n", itemNeckCur.ClassEvil);
    fwprintf(fpNeckData, L"\n");

    // Affinity
    fwprintf(fpNeckData, L"AFFINITY\n");
    fwprintf(fpNeckData, L"=============\n");
    fwprintf(fpNeckData, L"Physical: %3i\n", itemNeckCur.AffinityPhysical);
    fwprintf(fpNeckData, L"Air:      %3i\n", itemNeckCur.AffinityAir);
    fwprintf(fpNeckData, L"Fire:     %3i\n", itemNeckCur.AffinityFire);
    fwprintf(fpNeckData, L"Earth:    %3i\n", itemNeckCur.AffinityEarth);
    fwprintf(fpNeckData, L"Water:    %3i\n", itemNeckCur.AffinityWater);
    fwprintf(fpNeckData, L"Light:    %3i\n", itemNeckCur.AffinityLight);
    fwprintf(fpNeckData, L"Dark:     %3i\n", itemNeckCur.AffinityDark);

    fclose(fpNeckData);
}

void
WriteArmorData() {
    WriteGloveLeftData();
    WriteGloveRightData();
    WriteHeadData();
    WriteBodyData();
    WriteLegsData();
    WriteNeckData();
}

#endif

