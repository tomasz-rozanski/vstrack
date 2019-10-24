#ifndef _VS_ROOMS_H
#define _VS_ROOMS_H

// Location struct - 2 bytes
#define OFFSET_LOCATION 0x800F1AB0

// Room data (1 byte each)
#define OFFSET_LOCATION_AREA_NUMBER 0x800F1AB0
#define OFFSET_LOCATION_ROOM_NUMBER 0x800F1AB1

#define NELEMS(x) (sizeof(x) / sizeof(x[0]))

typedef struct
{
  char unsigned AreaNumber;
  char unsigned RoomNumber;
  TCHAR *AreaName;
  TCHAR *RoomName;
} room;

typedef struct
{
  union {
    UINT16 LocationCompound;
    struct
    {
      UINT8 AreaNumber;
      UINT8 RoomNumber;
    };
  } Location;
} location;

static location Location;
static TCHAR szAreaName[MAX_PATH];
static TCHAR szRoomName[MAX_PATH];

room Rooms[] = { //
  // Wine Cellar - verified
  { 9, 1, _T("Wine Cellar"), _T("Entrance to Darkness") },
  { 9, 2, _T("Wine Cellar"), _T("Room of Cheap Red Wine") },
  { 9, 3, _T("Wine Cellar"), _T("Room of Cheap White Wine") },
  { 9, 4, _T("Wine Cellar"), _T("Hall of Struggle") },
  { 9, 5, _T("Wine Cellar"), _T("Smokebarrel Stair") },
  { 9, 6, _T("Wine Cellar"), _T("Wine Guild Hall") },
  { 9, 7, _T("Wine Cellar"), _T("Wine Magnate's Chambers") },
  { 9, 8, _T("Wine Cellar"), _T("Fine Vintage Vault") },
  { 9, 9, _T("Wine Cellar"), _T("Chamber of Fear") }, // ver.1
  { 9, 10, _T("Wine Cellar"), _T("The Reckoning Room") },
  { 9, 11, _T("Wine Cellar"), _T("A Laborer's Thirst") },
  { 9, 12, _T("Wine Cellar"), _T("The Rich Drown in Wine") },
  { 9, 13, _T("Wine Cellar"), _T("Room of Rotten Grapes") }, // ver.1
  { 9, 14, _T("Wine Cellar"), _T("Chamber of Fear") }, // ver.2
  { 9, 16, _T("Wine Cellar"), _T("The Greedy One's Den") },
  { 9, 17, _T("Wine Cellar"), _T("Worker's Breakroom") },
  { 9, 18, _T("Wine Cellar"), _T("Blackmarket of Wines") },
  { 9, 19, _T("Wine Cellar"), _T("Room of Rotten Grapes") }, // ver.2
  { 11, 1, _T("Wine Cellar"), _T("The Hero's Winehall") },
  { 12, 1, _T("Wine Cellar"), _T("The Gallows") }, // ver.1
  { 12, 2, _T("Wine Cellar"), _T("The Gallows") }, // ver.2

  // Catacombs - verified
  { 13, 1, _T("Catacombs"), _T("Hall of Sworn Revenge") },
  { 13, 2, _T("Catacombs"), _T("The Last Blessing") },
  { 13, 3, _T("Catacombs"), _T("The Weeping Corridor") },
  { 13, 4, _T("Catacombs"), _T("Persecution Hall") },
  { 13, 5, _T("Catacombs"), _T("The Lamenting Mother") },
  { 13, 6, _T("Catacombs"), _T("Rodent-Ridden Chamber") },
  { 13, 7, _T("Catacombs"), _T("Shrine to the Martyrs") },
  { 13, 9, _T("Catacombs"), _T("Hall of Dying Hope") },
  { 13, 10, _T("Catacombs"), _T("Bandits' Hideout") },
  { 13, 11, _T("Catacombs"), _T("The Bloody Hallway") },
  { 13, 12, _T("Catacombs"), _T("Faith Overcame Fear") },
  { 13, 13, _T("Catacombs"), _T("The Withered Spring") },
  { 13, 14, _T("Catacombs"), _T("Repent, O ye Sinners") },
  { 13, 15, _T("Catacombs"), _T("The Reaper's Victims") },
  { 13, 16, _T("Catacombs"), _T("The Last Stab of Hope") },
  { 13, 17, _T("Catacombs"), _T("Hallway of Heroes") },
  { 13, 18, _T("Catacombs"), _T("The Lamenting Mother") },
  { 14, 1, _T("Catacombs"), _T("The Beast's Domain") },
  { 42, 1, _T("Catacombs"), _T("Workshop \"Work of Art\"") },

  // Sanctum - verified
  { 15, 1, _T("Sanctum"), _T("Prisoners' Niche") },
  { 15, 2, _T("Sanctum"), _T("Corridor of the Clerics") },
  { 15, 3, _T("Sanctum"), _T("Priests' Confinement") },
  { 15, 4, _T("Sanctum"), _T("Alchemists' Laboratory") },
  { 15, 5, _T("Sanctum"), _T("Theology Classroom") },
  { 15, 6, _T("Sanctum"), _T("Shrine of the Martyrs") },
  { 15, 7, _T("Sanctum"), _T("Advent Ground") },
  { 15, 8, _T("Sanctum"), _T("Passage of the Refugees") }, // ver.1
  { 15, 9, _T("Sanctum"), _T("Passage of the Refugees") }, // ver.2
  { 15, 11, _T("Sanctum"), _T("Stairway to the Light") },
  { 15, 12, _T("Sanctum"), _T("Hallowed Hope") },
  { 15, 13, _T("Sanctum"), _T("The Academia Corridor") },
  { 16, 1, _T("Sanctum"), _T("Hall of Sacrilege") },
  { 17, 1, _T("Sanctum"), _T("The Cleansing Chantry") },

  // Abandoned Mines B1 - verified
  { 50, 1, _T("Abandoned Mines B1"), _T("Dreamers' Entrance") },
  { 50, 2, _T("Abandoned Mines B1"), _T("Miners' Resting Hall") },
  { 50, 3, _T("Abandoned Mines B1"), _T("The Crossing") },
  { 50, 4, _T("Abandoned Mines B1"), _T("Conflict and Accord") },
  { 50, 5, _T("Abandoned Mines B1"), _T("The Suicide King") },
  { 50, 6, _T("Abandoned Mines B1"), _T("The End of the Line") },
  { 50, 7, _T("Abandoned Mines B1"), _T("The Battle's Beginning") },
  { 50, 8, _T("Abandoned Mines B1"), _T("What Lies Ahead?") },
  { 50, 9, _T("Abandoned Mines B1"), _T("The Fruits of Friendship") },
  { 50, 10, _T("Abandoned Mines B1"), _T("The Earthquake's Mark") },
  { 50, 11, _T("Abandoned Mines B1"), _T("Coal Mine Storage") },
  { 50, 12, _T("Abandoned Mines B1"), _T("The Passion of Lovers") },
  { 50, 13, _T("Abandoned Mines B1"), _T("The Hall of Hope") },
  { 50, 14, _T("Abandoned Mines B1"), _T("The Dark Tunnel") },
  { 50, 15, _T("Abandoned Mines B1"), _T("Rust in Peace") },
  { 50, 16, _T("Abandoned Mines B1"), _T("Everwant Passage") },
  { 50, 17, _T("Abandoned Mines B1"), _T("Mining Regrets") },
  { 50, 18, _T("Abandoned Mines B1"), _T("The Smeltry") },
  { 50, 19, _T("Abandoned Mines B1"), _T("Clash of Hyaenas") },
  { 50, 20, _T("Abandoned Mines B1"), _T("Greed Knows No Bounds") },
  { 50, 21, _T("Abandoned Mines B1"), _T("Live Long and Prosper") },
  { 50, 22, _T("Abandoned Mines B1"), _T("Pray to the Mineral Gods") },
  { 50, 23, _T("Abandoned Mines B1"), _T("Traitor's Parting") },
  { 50, 24, _T("Abandoned Mines B1"), _T("Escapeway") },

  // Abandoned Mines B2 - verified
  { 51, 1, _T("Abandoned Mines B2"), _T("Gambler's Passage") },
  { 51, 2, _T("Abandoned Mines B2"), _T("Treaty Room") },
  { 51, 3, _T("Abandoned Mines B2"), _T("The Miner's End") },
  { 51, 4, _T("Abandoned Mines B2"), _T("Work, Then Die") },
  { 51, 5, _T("Abandoned Mines B2"), _T("Bandits' Hollow") },
  { 51, 6, _T("Abandoned Mines B2"), _T("Delusions of Happiness") },
  { 51, 7, _T("Abandoned Mines B2"), _T("Dining in Darkness") },
  { 51, 8, _T("Abandoned Mines B2"), _T("Subtellurian Horrors") },
  { 51, 9, _T("Abandoned Mines B2"), _T("Hidden Resources") },
  { 51, 10, _T("Abandoned Mines B2"), _T("Way of Lost Children") },
  { 51, 11, _T("Abandoned Mines B2"), _T("Hall of the Empty Sconce") },
  { 51, 12, _T("Abandoned Mines B2"), _T("Acolyte's Burial Vault") },
  { 51, 13, _T("Abandoned Mines B2"), _T("Hall of Contemplation") },
  { 51, 14, _T("Abandoned Mines B2"), _T("The Abandoned Catspaw") },
  { 51, 15, _T("Abandoned Mines B2"), _T("Tomb of the Reborn") },
  { 51, 16, _T("Abandoned Mines B2"), _T("The Fallen Bricklayer") },
  { 51, 17, _T("Abandoned Mines B2"), _T("Crossing of Blood") },
  { 51, 18, _T("Abandoned Mines B2"), _T("Fool's Gold, Fool's Loss") },
  { 51, 19, _T("Abandoned Mines B2"), _T("Cry of the Beast") },
  { 51, 20, _T("Abandoned Mines B2"), _T("Senses Lost") },
  { 51, 21, _T("Abandoned Mines B2"), _T("Desire's Passage") },
  { 51, 22, _T("Abandoned Mines B2"), _T("Kilroy Was Here") },
  { 51, 23, _T("Abandoned Mines B2"), _T("Suicidal Desires") },
  { 51, 24, _T("Abandoned Mines B2"), _T("The Ore of Legend") },
  { 51, 25, _T("Abandoned Mines B2"), _T("Lambs to the Slaughter") },
  { 51, 26, _T("Abandoned Mines B2"), _T("A Wager of Noble Gold") },
  { 51, 27, _T("Abandoned Mines B2"), _T("The Lunatic Veins") },
  { 51, 28, _T("Abandoned Mines B2"), _T("Corridor of Shade") },
  { 51, 29, _T("Abandoned Mines B2"), _T("Revelation Shaft") },

  // Limestone Quarry - verified
  { 53, 1, _T("Limestone Quarry"), _T("Dark Abhors Light") },
  { 53, 2, _T("Limestone Quarry"), _T("Dream of the Holy Land") },
  { 53, 3, _T("Limestone Quarry"), _T("The Ore Road") },
  { 53, 4, _T("Limestone Quarry"), _T("Atone for Eternity") },
  { 53, 5, _T("Limestone Quarry"), _T("The Air Stirs") },
  { 53, 6, _T("Limestone Quarry"), _T("Bonds of Friendship") },
  { 53, 7, _T("Limestone Quarry"), _T("Stair to Sanctuary") },
  { 53, 8, _T("Limestone Quarry"), _T("The Fallen Hall") },
  { 53, 9, _T("Limestone Quarry"), _T("The Rotten Core") },
  { 53, 10, _T("Limestone Quarry"), _T("Bacchus is Cheap") },
  { 53, 11, _T("Limestone Quarry"), _T("Screams of the Wounded") },
  { 53, 12, _T("Limestone Quarry"), _T("The Ore-Bearers") },
  { 53, 13, _T("Limestone Quarry"), _T("The Dreamer's Climb") },
  { 53, 14, _T("Limestone Quarry"), _T("Sinner's Sustenence") },
  { 53, 15, _T("Limestone Quarry"), _T("The Timely Dew of Sleep") },
  { 53, 16, _T("Limestone Quarry"), _T("Companions in Arms") },
  { 53, 17, _T("Limestone Quarry"), _T("The Auction Block") },
  { 53, 18, _T("Limestone Quarry"), _T("Ascension") },
  { 53, 19, _T("Limestone Quarry"), _T("Where the Serpent Hunts") },
  { 53, 20, _T("Limestone Quarry"), _T("Ants Prepare for Winter") },
  { 53, 21, _T("Limestone Quarry"), _T("Drowned in Fleeting Joy") },
  { 53, 22, _T("Limestone Quarry"), _T("The Laborer's Bonfire") },
  { 53, 23, _T("Limestone Quarry"), _T("Stone and Sulfurous Fire") },
  { 53, 24, _T("Limestone Quarry"), _T("Torture Without End") },
  { 53, 25, _T("Limestone Quarry"), _T("Way Down") },
  { 53, 26, _T("Limestone Quarry"), _T("Excavated Hollow") },
  { 53, 27, _T("Limestone Quarry"), _T("Parting Regrets") },
  { 53, 28, _T("Limestone Quarry"), _T("Corridor of Tales") },
  { 53, 29, _T("Limestone Quarry"), _T("Dust Shall Eat the Days") },
  { 53, 30, _T("Limestone Quarry"), _T("Hall of the Wage-Paying") },
  { 53, 32, _T("Limestone Quarry"), _T("Tunnel of the Heartless") },

  // Temple of Kiltia - verified
  { 30, 1, _T("Temple of Kiltia"), _T("The Dark Coast") },
  { 30, 2, _T("Temple of Kiltia"), _T("Hall of Prayer") },
  { 30, 3, _T("Temple of Kiltia"), _T("Those who Drink the Dark") },
  { 30, 4, _T("Temple of Kiltia"), _T("The Chapel of Meschaunce") },
  { 30, 5, _T("Temple of Kiltia"), _T("The Resentful Ones") },
  { 30, 6, _T("Temple of Kiltia"), _T("Those who Fear the Light") },
  { 31, 1, _T("Temple of Kiltia"), _T("Chamber of Reason") },
  { 31, 2, _T("Temple of Kiltia"), _T("Exit to City Center") },

  // Great Cathedral B1 - verified
  { 22, 1, _T("Great Cathedral B1"), _T("Sanity and Madness") },
  { 22, 5, _T("Great Cathedral B1"), _T("Truth and Lies") },
  { 22, 7, _T("Great Cathedral B1"), _T("Order and Chaos") },
  { 22, 8, _T("Great Cathedral B1"), _T("The Victor's Laurels") },
  { 22, 9, _T("Great Cathedral B1"), _T("Struggle for the Soul") },
  { 22, 10, _T("Great Cathedral B1"), _T("An Offering of Souls") },

  // Great Cathedral L1 - verified
  { 24, 1, _T("Great Cathedral L1"), _T("The Flayed Confessional") },
  { 24, 2, _T("Great Cathedral L1"), _T("Monk's Leap") },
  { 24, 3, _T("Great Cathedral L1"), _T("Where Darkness Spreads") },
  { 24, 4, _T("Great Cathedral L1"), _T("Hieratic Recollections") },
  { 24, 5, _T("Great Cathedral L1"), _T("A Light in the Dark") },
  { 24, 6, _T("Great Cathedral L1"), _T("The Poisoned Chapel") },
  { 24, 7, _T("Great Cathedral L1"), _T("Sin and Punishment") },
  { 24, 8, _T("Great Cathedral L1"), _T("Cracked Pleasures") },
  { 24, 9, _T("Great Cathedral L1"), _T("Into Holy Battle") },

  // Great Cathedral L2 - verified
  { 23, 2, _T("Great Cathedral L2"), _T("He Screams for Mercy") },
  { 23, 3, _T("Great Cathedral L2"), _T("Light and Dark Wage War") },
  { 23, 4, _T("Great Cathedral L2"), _T("Abasement from Above") },
  { 24, 10, _T("Great Cathedral L2"), _T("Maelstrom of Malice") },
  { 24, 11, _T("Great Cathedral L2"), _T("The Acolyte's Weakness") },
  { 24, 12, _T("Great Cathedral L2"), _T("The Hall of Broken Vows") },
  { 24, 13, _T("Great Cathedral L2"), _T("The Melodics of Madness") },
  { 24, 14, _T("Great Cathedral L2"), _T("Free from Base Desires") },
  { 24, 15, _T("Great Cathedral L2"), _T("The Convent Room") },
  { 25, 1, _T("Great Cathedral L2"), _T("An Arrow into Darkness") },
  { 25, 2, _T("Great Cathedral L2"), _T("What Ails You, Kills You") },

  // Great Cathedral L3 - verified
  { 23, 5, _T("Great Cathedral L3"), _T("The Heretics' Story") },
  { 23, 6, _T("Great Cathedral L3"), _T("The Wine-Lecher's Fall") },
  { 24, 16, _T("Great Cathedral L3"), _T("Hopes of the Idealist") },
  { 25, 3, _T("Great Cathedral L3"), _T("Where the Soul Rots") },
  { 25, 4, _T("Great Cathedral L3"), _T("Despair of the Fallen") },

  // Great Cathedral L4 - verified
  { 25, 5, _T("Great Cathedral L4"), _T("The Atrium") },

  // Forgotten Pathway - verified
  { 54, 1, _T("Forgotten Pathway"), _T("Stair to the Sinners") },
  { 54, 2, _T("Forgotten Pathway"), _T("Slaugher of the Innocent") },
  { 54, 3, _T("Forgotten Pathway"), _T("The Fallen Knight") },
  { 54, 4, _T("Forgotten Pathway"), _T("The Oracle Sins No More") },
  { 54, 5, _T("Forgotten Pathway"), _T("Awaiting Retribution") },

  // Escapeway - verified
  { 52, 1, _T("Escapeway"), _T("Shelter From the Quake") },
  { 52, 2, _T("Escapeway"), _T("Buried Alive") },
  { 52, 3, _T("Escapeway"), _T("Movement of Fear") },
  { 52, 4, _T("Escapeway"), _T("Facing Your Illusions") },
  { 52, 5, _T("Escapeway"), _T("The Darkness Drinks") },
  { 52, 6, _T("Escapeway"), _T("Fear and Loathing") },
  { 52, 7, _T("Escapeway"), _T("Blood and the Beast") },
  { 52, 8, _T("Escapeway"), _T("Where Body and Soul Part") },

  // Iron Maiden B1 - verified
  { 55, 1, _T("Iron Maiden B1"), _T("The Cage") },
  { 55, 2, _T("Iron Maiden B1"), _T("The Cauldron") },
  { 55, 3, _T("Iron Maiden B1"), _T("Wooden Horse") },
  { 55, 4, _T("Iron Maiden B1"), _T("Starvation") },
  { 55, 5, _T("Iron Maiden B1"), _T("The Breast Ripper") },
  { 55, 6, _T("Iron Maiden B1"), _T("The Pear") },
  { 55, 7, _T("Iron Maiden B1"), _T("The Whirligig") },
  { 55, 8, _T("Iron Maiden B1"), _T("Spanish Tickler") },
  { 55, 9, _T("Iron Maiden B1"), _T("Heretic's Fork") },
  { 55, 10, _T("Iron Maiden B1"), _T("The Chair of Spikes") },
  { 55, 11, _T("Iron Maiden B1"), _T("Blooding") },
  { 55, 12, _T("Iron Maiden B1"), _T("Bootikens") },
  { 55, 13, _T("Iron Maiden B1"), _T("Burial") },
  { 55, 14, _T("Iron Maiden B1"), _T("Burning") },
  { 55, 15, _T("Iron Maiden B1"), _T("Cleansing the Soul") },
  { 55, 16, _T("Iron Maiden B1"), _T("The Garotte") },
  { 55, 17, _T("Iron Maiden B1"), _T("Hanging") },
  { 55, 18, _T("Iron Maiden B1"), _T("Impalement") },
  { 55, 19, _T("Iron Maiden B1"), _T("Knotting") },
  { 55, 20, _T("Iron Maiden B1"), _T("The Branks") },
  { 55, 21, _T("Iron Maiden B1"), _T("The Wheel") },
  { 55, 22, _T("Iron Maiden B1"), _T("The Judas Cradle") },
  { 55, 23, _T("Iron Maiden B1"), _T("The Ducking Stool") },

  // Iron Maiden B2 - verified
  { 56, 1, _T("Iron Maiden B2"), _T("The Eunics' Lot") },
  { 56, 2, _T("Iron Maiden B2"), _T("Ordeal By Fire") },
  { 56, 3, _T("Iron Maiden B2"), _T("Tablillas") },
  { 56, 4, _T("Iron Maiden B2"), _T("The Oven at Neisse") },
  { 56, 5, _T("Iron Maiden B2"), _T("Strangulation") },
  { 56, 6, _T("Iron Maiden B2"), _T("Pressing") },
  { 56, 7, _T("Iron Maiden B2"), _T("The Strappado") },
  { 56, 8, _T("Iron Maiden B2"), _T("The Mind Burns") },
  { 56, 9, _T("Iron Maiden B2"), _T("Thumbscrews") },
  { 56, 10, _T("Iron Maiden B2"), _T("The Rack") },
  { 56, 11, _T("Iron Maiden B2"), _T("The Saw") },
  { 56, 12, _T("Iron Maiden B2"), _T("Ordeal By Water") },
  { 56, 13, _T("Iron Maiden B2"), _T("The Cold's Bridle") },
  { 56, 14, _T("Iron Maiden B2"), _T("Brank") },
  { 56, 15, _T("Iron Maiden B2"), _T("The Shin-Vice") },
  { 56, 16, _T("Iron Maiden B2"), _T("Squassation") },
  { 56, 17, _T("Iron Maiden B2"), _T("The Spider") },
  { 56, 18, _T("Iron Maiden B2"), _T("Lead Sprinkler") },
  { 56, 19, _T("Iron Maiden B2"), _T("Pendulum") },
  { 56, 20, _T("Iron Maiden B2"), _T("Dragging") },
  { 56, 21, _T("Iron Maiden B2"), _T("Tongue Slicer") },
  { 56, 22, _T("Iron Maiden B2"), _T("Tormentum Insomniae") },

  // Iron Maiden B3 - verified
  { 56, 23, _T("Iron Maiden B3"), _T("The Iron Maiden") },
  { 56, 24, _T("Iron Maiden B3"), _T("Saint Elmo's Belt") },
  { 56, 25, _T("Iron Maiden B3"), _T("Judgement") },
  { 56, 26, _T("Iron Maiden B3"), _T("Dunking the Witch") },

  // Undercity West - verified
  { 47, 1, _T("Undercity West"), _T("Workshop \"Godhands\"") },
  { 48, 1, _T("Undercity West"), _T("The Bread Peddler's Way") },
  { 48, 2, _T("Undercity West"), _T("Way of the Mother Lode") },
  { 48, 3, _T("Undercity West"), _T("Sewer of Ravenous Rats") },
  { 48, 4, _T("Undercity West"), _T("Underdark Fishmarket") },
  { 48, 5, _T("Undercity West"), _T("The Sunless Way") },
  { 48, 6, _T("Undercity West"), _T("Remembering Days of Yore") },
  { 48, 7, _T("Undercity West"), _T("Where the Hunter Climbed") },
  { 48, 8, _T("Undercity West"), _T("Larder for a Lean Winter") },
  { 48, 9, _T("Undercity West"), _T("Hall of Poverty") },
  { 48, 10, _T("Undercity West"), _T("The Washing-Woman's Way") },
  { 48, 11, _T("Undercity West"), _T("Beggars of the Mouthharp") },
  { 48, 12, _T("Undercity West"), _T("Corner of the Wretched") },
  { 48, 13, _T("Undercity West"), _T("Path to the Greengrocer") },
  { 48, 14, _T("Undercity West"), _T("Crossroads of Rest") },
  { 48, 15, _T("Undercity West"), _T("Path of the Children") },
  { 48, 16, _T("Undercity West"), _T("Fear of the Fall") },
  { 48, 17, _T("Undercity West"), _T("Sinner's Corner") },
  { 48, 18, _T("Undercity West"), _T("Nameless Dark Oblivion") },
  { 48, 19, _T("Undercity West"), _T("Corner of Prayers") },
  { 48, 20, _T("Undercity West"), _T("Hope Obstructed") },
  { 48, 21, _T("Undercity West"), _T("The Children's Hideout") },
  { 48, 22, _T("Undercity West"), _T("The Crumbling Market") },
  { 48, 23, _T("Undercity West"), _T("Tears from Empty Sockets") },
  { 48, 24, _T("Undercity West"), _T("Where Flood Waters Ran") },
  { 48, 25, _T("Undercity West"), _T("The Body Fragile Yields") },
  { 48, 26, _T("Undercity West"), _T("Salvation for the Mother") },
  { 48, 27, _T("Undercity West"), _T("Bite the Master's Wounds") },

  { 49, 1, _T("Undercity East"), _T("Hall to a New World") },
  { 49, 2, _T("Undercity East"), _T("Place of Free Words") },
  { 49, 3, _T("Undercity East"), _T("Bazaar of the Bizarre") },
  { 49, 4, _T("Undercity East"), _T("Noble Gold and Silk") },
  { 49, 5, _T("Undercity East"), _T("A Knight Sells his Sword") },
  { 49, 6, _T("Undercity East"), _T("Gemsword Blackmarket") },
  { 49, 7, _T("Undercity East"), _T("The Pirate's Son") },
  { 49, 8, _T("Undercity East"), _T("Sale of the Sword") },
  { 49, 9, _T("Undercity East"), _T("Weapons Not Allowed") },
  { 49, 10, _T("Undercity East"), _T("The Greengrocer's Stair") },
  { 49, 11, _T("Undercity East"), _T("Where Black Waters Ran") },
  { 49, 12, _T("Undercity East"), _T("Arms Against Invaders") },
  { 49, 13, _T("Undercity East"), _T("Catspaw Blackmarket") },

  // The Keep - verified
  { 29, 1, _T("The Keep"), _T("The Warrior's Rest") },
  { 29, 3, _T("The Keep"), _T("The Soldier's Bedding") },
  { 29, 4, _T("The Keep"), _T("A Storm of Arrows") },
  { 29, 5, _T("The Keep"), _T("Urge the Boy On") },
  { 29, 6, _T("The Keep"), _T("A Taste of the Spoils") },
  { 29, 7, _T("The Keep"), _T("Wiping Blood from Blades") },
  { 44, 1, _T("The Keep"), _T("Workshop \"Keane's Crafts\"") },

  // City Walls West - verified
  { 28, 1, _T("City Walls West"), _T("Students of Death") },
  { 28, 2, _T("City Walls West"), _T("The Gabled Hall") },
  { 28, 3, _T("City Walls West"), _T("Where the Master Fell") },

  // City Walls South - verified
  { 28, 4, _T("City Walls South"), _T("The Weeping Boy") },
  { 28, 5, _T("City Walls South"), _T("Swords for the Land") },
  { 28, 6, _T("City Walls South"), _T("In Wait of the Foe") },
  { 28, 7, _T("City Walls South"), _T("Where Weary Riders Rest") },
  { 28, 8, _T("City Walls South"), _T("The Boy's Training Room") },

  // City Walls East
  { 28, 9, _T("City Walls East"), _T("Train and Grow Strong") },
  { 28, 10, _T("City Walls East"), _T("The Squire's Gathering") },
  { 28, 11, _T("City Walls East"), _T("The Invaders are Found") },
  { 28, 12, _T("City Walls East"), _T("The Dream-Weavers") },
  { 28, 13, _T("City Walls East"), _T("The Cornered Savage") },

  { 28, 14, _T("City Walls North"), _T("Traces of Invasion Past") },
  { 28, 15, _T("City Walls North"), _T("From Squire to Knight") },
  { 28, 16, _T("City Walls North"), _T("Be for Battle Prepared") },
  { 28, 17, _T("City Walls North"), _T("Destruction and Rebirth") },
  { 28, 18, _T("City Walls North"), _T("From Boy to Hero") },
  { 28, 19, _T("City Walls North"), _T("A Welcome Invasion") },

  // Snowfly Forest - verified
  { 40, 1, _T("Snowfly Forest"), _T("The Hunt Begins") },
  { 40, 2, _T("Snowfly Forest"), _T("Which Way Home") },
  { 40, 3, _T("Snowfly Forest"), _T("The Giving Trees") },
  { 40, 4, _T("Snowfly Forest"), _T("The Wounded Boar") },
  { 40, 5, _T("Snowfly Forest"), _T("Golden Egg Way") },
  { 40, 6, _T("Snowfly Forest"), _T("The Birds and the Bees") },
  { 40, 7, _T("Snowfly Forest"), _T("The Woodcutter's Run") },
  { 40, 8, _T("Snowfly Forest"), _T("The Wolves' Choice") },
  { 40, 9, _T("Snowfly Forest"), _T("Howl of the Wolf King") },
  { 40, 10, _T("Snowfly Forest"), _T("Fluttering Hope") },
  { 40, 11, _T("Snowfly Forest"), _T("Traces of the Beast") },
  { 40, 12, _T("Snowfly Forest"), _T("The Yellow Wood") },
  { 40, 13, _T("Snowfly Forest"), _T("They Also Feed") },
  { 40, 14, _T("Snowfly Forest"), _T("Where Soft Rains Fell") },
  { 40, 15, _T("Snowfly Forest"), _T("The Spirit Trees") },
  { 40, 16, _T("Snowfly Forest"), _T("The Silent Hedges") },
  { 40, 17, _T("Snowfly Forest"), _T("Lamenting to the Moon") },
  { 40, 18, _T("Snowfly Forest"), _T("The Hollow Hills") },
  { 40, 19, _T("Snowfly Forest"), _T("Running with the Wolves") },
  { 40, 20, _T("Snowfly Forest"), _T("You Are the Prey") },
  { 40, 21, _T("Snowfly Forest"), _T("The Secret Path") },
  { 40, 22, _T("Snowfly Forest"), _T("The Faerie Circle") },
  { 40, 23, _T("Snowfly Forest"), _T("Return to the Land") },
  { 40, 24, _T("Snowfly Forest"), _T("Forest River") },
  { 40, 25, _T("Snowfly Forest"), _T("Hewn from Nature") },
  { 40, 26, _T("Snowfly Forest"), _T("The Wood Gate") },

  // Snowfly Forest East
  { 41, 1, _T("Snowfly Forest East"), _T("Steady the Boar-Spears") },
  { 41, 2, _T("Snowfly Forest East"), _T("The Boar's Revenge") },
  { 41, 3, _T("Snowfly Forest East"), _T("Nature's Womb") },

  // Town Center West - verified
  { 32, 1, _T("Town Center West"), _T("Rue Vermillion") },
  { 32, 2, _T("Town Center West"), _T("The Rene Coastroad") },
  { 32, 3, _T("Town Center West"), _T("Rue Mal Fallde") },
  { 32, 4, _T("Town Center West"), _T("Tircolas Flow") },
  { 32, 5, _T("Town Center West"), _T("Glacialdra Kirk Ruins") },
  { 32, 6, _T("Town Center West"), _T("Rue Bouquet") },
  { 32, 7, _T("Town Center West"), _T("Villeport Way") },
  { 32, 8, _T("Town Center West"), _T("Rue Sant D'alsa") },
  { 34, 1, _T("Town Center West"), _T("Dinas Walk") },
  { 43, 1, _T("Town Center West"), _T("Workshop \"Magic Hammer\"") },

  { 32, 9, _T("Town Center South"), _T("Valdiman Gates") },
  { 32, 10, _T("Town Center South"), _T("Rue Faltes") },
  { 32, 11, _T("Town Center South"), _T("Forcas Rise") },
  { 32, 12, _T("Town Center South"), _T("Rue Aliano") },
  { 32, 13, _T("Town Center South"), _T("Rue Volnac") },
  { 32, 14, _T("Town Center South"), _T("Rue Morgue") },
  { 35, 1, _T("Town Center South"), _T("Zebel's Walk") },
  { 37, 1, _T("Town Center South"), _T("The House Khazabas") },

  { 32, 16, _T("Town Center East"), _T("Rue Lejour") },
  { 32, 17, _T("Town Center East"), _T("Kesch Bridge") },
  { 32, 18, _T("Town Center East"), _T("Rue Crimnade") },
  { 32, 19, _T("Town Center East"), _T("Rue Fisserano") },
  { 32, 20, _T("Town Center East"), _T("Shasras Hill Park") },
  { 36, 1, _T("Town Center East"), _T("Gharmes Walk") },
  { 38, 1, _T("Town Center East"), _T("The House Gilgitte") },
  { 39, 1, _T("Town Center East"), _T("Plateia Lumitar") },
  { 45, 1, _T("Town Center East"), _T("Workshop \"Metal Works\"") },
  { 46, 1, _T("Town Center East"), _T("Workshop \"Junction Point\"") },

  { 27, 1, _T("The Paling"), _T("Phase 1") },
  { 27, 2, _T("The Paling"), _T("Phase 2") }

};

void
ReadLocation(location *Location)
{
  SIZE_T BytesToRead = sizeof(location);
  DWORD BytesRead;

  BytesRead = ReadGameMemory(processID, OFFSET_LOCATION, BytesToRead, Location);
}

void
GetAreaAndRoomName(location *Location, TCHAR *szAreaName, TCHAR *szRoomName)
{
  UINT8 AreaNumber = Location->Location.AreaNumber;
  UINT8 RoomNumber = Location->Location.RoomNumber;

  int counter = NELEMS(Rooms);

  for (int i = 0; i < counter; i++)
  {
    if (Rooms[i].AreaNumber == AreaNumber &&
        Rooms[i].RoomNumber == (RoomNumber + 1))
    {
      wsprintf(szAreaName, "%s", Rooms[i].AreaName);
      wsprintf(szRoomName, "%s", Rooms[i].RoomName);

      break;
    }
  }
}

void
WriteLocationIntoFile(location *Location, TCHAR *szAreaName, TCHAR *szRoomName)
{
  UINT8 AreaNumber = Location->Location.AreaNumber;
  UINT8 RoomNumber = Location->Location.RoomNumber;

  FILE *fpLocation = fopen("game_stats/location.txt", "w");
  FILE *fpLocationDebug = fopen("game_stats/location-debug.txt", "w");

  fprintf(fpLocation, "%s / %s\n", szAreaName, szRoomName);
  fprintf(fpLocationDebug, "Location ( %2i, %2i ):\n%s / %s\n", AreaNumber,
      RoomNumber, szAreaName, szRoomName);

  fclose(fpLocation);
  fclose(fpLocationDebug);
}

void
PrintLocation(location *Location, TCHAR *szAreaName, TCHAR *szRoomName)
{
  UINT8 AreaNumber = Location->Location.AreaNumber;
  UINT8 RoomNumber = Location->Location.RoomNumber;

  fprintf(stdout, "\n== LOCATION ==\n\n");
  if (DEBUG)
  {
    fprintf(stdout, "Area %2i, Room %2i - %s / %s\n", AreaNumber, RoomNumber,
        szAreaName, szRoomName);
  }
  else
  {
    fprintf(stdout, "%s / %s\n", szAreaName, szRoomName);
  }
}

void
PrintLocation2(location *Location, TCHAR *szAreaName, TCHAR *szRoomName)
{
  UINT8 AreaNumber = Location->Location.AreaNumber;
  UINT8 RoomNumber = Location->Location.RoomNumber;

  sprintf(szBuffer, "\n\n== LOCATION ==\n\n");
  WriteToBackBuffer();

  sprintf(szBuffer, "%s, %s ( Area %2i, Room %2i )", szAreaName, szRoomName,
      AreaNumber, RoomNumber);
  WriteToBackBuffer();
}

BOOL
IsThisTheLastBossRoom(location *Location)
{
  if ((Location->Location.AreaNumber == 27) &&
      (Location->Location.RoomNumber == 1))
  {
    return TRUE;
  }
  return FALSE;
}

#endif