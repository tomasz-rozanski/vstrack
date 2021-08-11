#ifndef _VS_ROOMS_H
#define _VS_ROOMS_H

// Location struct - 2 bytes
#define OFFSET_LOCATION 0x0f1ab0

// Room data (1 byte each)
#define OFFSET_LOCATION_AREA_NUMBER 0x0f1ab0
#define OFFSET_LOCATION_ROOM_NUMBER 0x0f1ab1

typedef struct
{
  u8 ZoneNumber;
  u8 MapNumber;
  char *ZoneName;
  char *MapName;
} map_data;

map_data MapDataList[] = {
  // Loading screen
  { 0, 0, "In the void", "Nothing to see here..." }, //

  // Intro 1
  { 1, 0, "Intro", "Guildenstern talks with the knight" }, //
  { 2, 0, "Intro", "Ashley at the gate" }, //
  { 3, 0, "Intro", "Ashley at the courtyard" }, //
  { 4, 0, "Intro", "Ashley in the hall" }, //
  { 5, 0, "Intro", "Ashley meets Sydney" }, //
  { 6, 0, "Intro", "Ashley fights Wyvern" }, //
  { 7, 0, "Intro", "Ashley walks to the window" }, //
  { 8, 0, "Intro", "Ashley stares through the window" }, //
  { 18, 0, "Intro", "Bardorba and Rosencrantz in Graylands Manor" }, //
  { 33, 0, "Intro", "Merlose finds corpses at Lea Monde's entrance" }, //
  { 10, 0, "Intro", "Ashley and Merlose at the tunnel entrance" }, //
  { 9, 14, "Intro", "Ashley and Merlose at the Wine Cellar gate" }, //

  // Intro 2
  { 20, 0, "Intro", "VKP briefing" }, //
  { 21, 0, "Intro", "Ashley meets Merlose outside manor" }, //

  // Outro
  { 60, 0, "Epilogue", "Merlose, Hardin, and Joshua fleeing the city" }, //
  { 61, 0, "Epilogue", "Pigmen crushed by the falling debris" }, //
  { 62, 0, "Epilogue", "Tieger and Neesa stopped by Grissom" }, //
  { 63, 0, "Epilogue", "Ashley carries Sydney" }, //
  { 64, 0, "Epilogue", "Creatures of the dark vanish" }, //
  { 65, 0, "Epilogue", "The Well explodes" }, //
  { 66, 0, "Epilogue", "Hardin dies" }, //
  { 67, 0, "Epilogue", "Bardorba reunion" }, //
  { 68, 0, "Epilogue", "Ashley patrols the streets" }, //

  // Wine Cellar
  { 9, 0, "Wine Cellar", "Entrance to Darkness" }, //
  { 9, 1, "Wine Cellar", "Room of Cheap Red Wine" }, //
  { 9, 2, "Wine Cellar", "Room of Cheap White Wine" }, //
  { 9, 3, "Wine Cellar", "Hall of Struggle" }, //
  { 9, 4, "Wine Cellar", "Smokebarrel Stair" }, //
  { 9, 5, "Wine Cellar", "Wine Guild Hall" }, //
  { 9, 6, "Wine Cellar", "Wine Magnate's Chambers" }, //
  { 9, 7, "Wine Cellar", "Fine Vintage Vault" }, //
  { 9, 8, "Wine Cellar", "Chamber of Fear" }, //
  { 9, 9, "Wine Cellar", "The Reckoning Room" }, //
  { 9, 10, "Wine Cellar", "A Laborer's Thirst" }, //
  { 9, 11, "Wine Cellar", "The Rich Drown in Wine" }, //
  { 9, 12, "Wine Cellar", "Room of Rotten Grapes" }, //
  { 9, 13, "Wine Cellar", "Chamber of Fear" }, //
  { 9, 15, "Wine Cellar", "The Greedy One's Den" }, //
  { 9, 16, "Wine Cellar", "Worker's Breakroom" }, //
  { 9, 17, "Wine Cellar", "Blackmarket of Wines" }, //
  { 9, 18, "Wine Cellar", "Room of Rotten Grapes" }, //
  { 11, 0, "Wine Cellar", "The Hero's Winehall" }, //
  { 12, 0, "Wine Cellar", "The Gallows" }, //
  { 12, 1, "Wine Cellar", "The Gallows" }, //

  // Catacombs
  { 13, 0, "Catacombs", "Hall of Sworn Revenge" }, //
  { 13, 1, "Catacombs", "The Last Blessing" }, //
  { 13, 2, "Catacombs", "The Weeping Corridor" }, //
  { 13, 3, "Catacombs", "Persecution Hall" }, //
  { 13, 4, "Catacombs", "The Lamenting Mother" }, //
  { 13, 5, "Catacombs", "Rodent-Ridden Chamber" }, //
  { 13, 6, "Catacombs", "Shrine to the Martyrs" }, //
  { 13, 8, "Catacombs", "Hall of Dying Hope" }, //
  { 13, 9, "Catacombs", "Bandits' Hideout" }, //
  { 13, 10, "Catacombs", "The Bloody Hallway" }, //
  { 13, 11, "Catacombs", "Faith Overcame Fear" }, //
  { 13, 12, "Catacombs", "The Withered Spring" }, //
  { 13, 13, "Catacombs", "Repent, O ye Sinners" }, //
  { 13, 14, "Catacombs", "The Reaper's Victims" }, //
  { 13, 15, "Catacombs", "The Last Stab of Hope" }, //
  { 13, 16, "Catacombs", "Hallway of Heroes" }, //
  { 13, 17, "Catacombs", "The Lamenting Mother" }, //
  { 14, 0, "Catacombs", "The Beast's Domain" }, //
  { 42, 0, "Catacombs", "Workshop \"Work of Art\"" }, //

  // Sanctum
  { 15, 0, "Sanctum", "Prisoners' Niche" }, //
  { 15, 1, "Sanctum", "Corridor of the Clerics" }, //
  { 15, 2, "Sanctum", "Priests' Confinement" }, //
  { 15, 3, "Sanctum", "Alchemists' Laboratory" }, //
  { 15, 4, "Sanctum", "Theology Classroom" }, //
  { 15, 5, "Sanctum", "Shrine of the Martyrs" }, //
  { 15, 6, "Sanctum", "Advent Ground" }, //
  { 15, 7, "Sanctum", "Passage of the Refugees" }, //
  { 15, 8, "Sanctum", "Passage of the Refugees" }, //
  { 15, 10, "Sanctum", "Stairway to the Light" }, //
  { 15, 11, "Sanctum", "Hallowed Hope" }, //
  { 15, 12, "Sanctum", "The Academia Corridor" }, //
  { 16, 0, "Sanctum", "Hall of Sacrilege" }, //
  { 17, 0, "Sanctum", "The Cleansing Chantry" }, //

  // Abandoned Mines B1
  { 50, 0, "Abandoned Mines B1", "Dreamers' Entrance" }, //
  { 50, 1, "Abandoned Mines B1", "Miners' Resting Hall" }, //
  { 50, 2, "Abandoned Mines B1", "The Crossing" }, //
  { 50, 3, "Abandoned Mines B1", "Conflict and Accord" }, //
  { 50, 4, "Abandoned Mines B1", "The Suicide King" }, //
  { 50, 5, "Abandoned Mines B1", "The End of the Line" }, //
  { 50, 6, "Abandoned Mines B1", "The Battle's Beginning" }, //
  { 50, 7, "Abandoned Mines B1", "What Lies Ahead?" }, //
  { 50, 8, "Abandoned Mines B1", "The Fruits of Friendship" }, //
  { 50, 9, "Abandoned Mines B1", "The Earthquake's Mark" }, //
  { 50, 10, "Abandoned Mines B1", "Coal Mine Storage" }, //
  { 50, 11, "Abandoned Mines B1", "The Passion of Lovers" }, //
  { 50, 12, "Abandoned Mines B1", "The Hall of Hope" }, //
  { 50, 13, "Abandoned Mines B1", "The Dark Tunnel" }, //
  { 50, 14, "Abandoned Mines B1", "Rust in Peace" }, //
  { 50, 15, "Abandoned Mines B1", "Everwant Passage" }, //
  { 50, 16, "Abandoned Mines B1", "Mining Regrets" }, //
  { 50, 17, "Abandoned Mines B1", "The Smeltry" }, //
  { 50, 18, "Abandoned Mines B1", "Clash of Hyaenas" }, //
  { 50, 19, "Abandoned Mines B1", "Greed Knows No Bounds" }, //
  { 50, 20, "Abandoned Mines B1", "Live Long and Prosper" }, //
  { 50, 21, "Abandoned Mines B1", "Pray to the Mineral Gods" }, //
  { 50, 22, "Abandoned Mines B1", "Traitor's Parting" }, //
  { 50, 23, "Abandoned Mines B1", "Escapeway" }, //

  // Abandoned Mines B2
  { 51, 0, "Abandoned Mines B2", "Gambler's Passage" }, //
  { 51, 1, "Abandoned Mines B2", "Treaty Room" }, //
  { 51, 2, "Abandoned Mines B2", "The Miner's End" }, //
  { 51, 3, "Abandoned Mines B2", "Work, Then Die" }, //
  { 51, 4, "Abandoned Mines B2", "Bandits' Hollow" }, //
  { 51, 5, "Abandoned Mines B2", "Delusions of Happiness" }, //
  { 51, 6, "Abandoned Mines B2", "Dining in Darkness" }, //
  { 51, 7, "Abandoned Mines B2", "Subtellurian Horrors" }, //
  { 51, 8, "Abandoned Mines B2", "Hidden Resources" }, //
  { 51, 9, "Abandoned Mines B2", "Way of Lost Children" }, //
  { 51, 10, "Abandoned Mines B2", "Hall of the Empty Sconce" }, //
  { 51, 11, "Abandoned Mines B2", "Acolyte's Burial Vault" }, //
  { 51, 12, "Abandoned Mines B2", "Hall of Contemplation" }, //
  { 51, 13, "Abandoned Mines B2", "The Abandoned Catspaw" }, //
  { 51, 14, "Abandoned Mines B2", "Tomb of the Reborn" }, //
  { 51, 15, "Abandoned Mines B2", "The Fallen Bricklayer" }, //
  { 51, 16, "Abandoned Mines B2", "Crossing of Blood" }, //
  { 51, 17, "Abandoned Mines B2", "Fool's Gold, Fool's Loss" }, //
  { 51, 18, "Abandoned Mines B2", "Cry of the Beast" }, //
  { 51, 19, "Abandoned Mines B2", "Senses Lost" }, //
  { 51, 20, "Abandoned Mines B2", "Desire's Passage" }, //
  { 51, 21, "Abandoned Mines B2", "Kilroy Was Here" }, //
  { 51, 22, "Abandoned Mines B2", "Suicidal Desires" }, //
  { 51, 23, "Abandoned Mines B2", "The Ore of Legend" }, //
  { 51, 24, "Abandoned Mines B2", "Lambs to the Slaughter" }, //
  { 51, 25, "Abandoned Mines B2", "A Wager of Noble Gold" }, //
  { 51, 26, "Abandoned Mines B2", "The Lunatic Veins" }, //
  { 51, 27, "Abandoned Mines B2", "Corridor of Shade" }, //
  { 51, 28, "Abandoned Mines B2", "Revelation Shaft" }, //

  // Limestone Quarry
  { 53, 0, "Limestone Quarry", "Dark Abhors Light" }, //
  { 53, 1, "Limestone Quarry", "Dream of the Holy Land" }, //
  { 53, 2, "Limestone Quarry", "The Ore Road" }, //
  { 53, 3, "Limestone Quarry", "Atone for Eternity" }, //
  { 53, 4, "Limestone Quarry", "The Air Stirs" }, //
  { 53, 5, "Limestone Quarry", "Bonds of Friendship" }, //
  { 53, 6, "Limestone Quarry", "Stair to Sanctuary" }, //
  { 53, 7, "Limestone Quarry", "The Fallen Hall" }, //
  { 53, 8, "Limestone Quarry", "The Rotten Core" }, //
  { 53, 9, "Limestone Quarry", "Bacchus is Cheap" }, //
  { 53, 10, "Limestone Quarry", "Screams of the Wounded" }, //
  { 53, 11, "Limestone Quarry", "The Ore-Bearers" }, //
  { 53, 12, "Limestone Quarry", "The Dreamer's Climb" }, //
  { 53, 13, "Limestone Quarry", "Sinner's Sustenence" }, //
  { 53, 14, "Limestone Quarry", "The Timely Dew of Sleep" }, //
  { 53, 15, "Limestone Quarry", "Companions in Arms" }, //
  { 53, 16, "Limestone Quarry", "The Auction Block" }, //
  { 53, 17, "Limestone Quarry", "Ascension" }, //
  { 53, 18, "Limestone Quarry", "Where the Serpent Hunts" }, //
  { 53, 19, "Limestone Quarry", "Ants Prepare for Winter" }, //
  { 53, 20, "Limestone Quarry", "Drowned in Fleeting Joy" }, //
  { 53, 21, "Limestone Quarry", "The Laborer's Bonfire" }, //
  { 53, 22, "Limestone Quarry", "Stone and Sulfurous Fire" }, //
  { 53, 23, "Limestone Quarry", "Torture Without End" }, //
  { 53, 24, "Limestone Quarry", "Way Down" }, //
  { 53, 25, "Limestone Quarry", "Excavated Hollow" }, //
  { 53, 26, "Limestone Quarry", "Parting Regrets" }, //
  { 53, 27, "Limestone Quarry", "Corridor of Tales" }, //
  { 53, 28, "Limestone Quarry", "Dust Shall Eat the Days" }, //
  { 53, 29, "Limestone Quarry", "Hall of the Wage-Paying" }, //
  { 53, 31, "Limestone Quarry", "Tunnel of the Heartless" }, //

  // Temple of Kiltia
  { 30, 0, "Temple of Kiltia", "The Dark Coast" }, //
  { 30, 1, "Temple of Kiltia", "Hall of Prayer" }, //
  { 30, 2, "Temple of Kiltia", "Those who Drink the Dark" }, //
  { 30, 3, "Temple of Kiltia", "The Chapel of Meschaunce" }, //
  { 30, 4, "Temple of Kiltia", "The Resentful Ones" }, //
  { 30, 5, "Temple of Kiltia", "Those who Fear the Light" }, //
  { 31, 0, "Temple of Kiltia", "Chamber of Reason" }, //
  { 31, 1, "Temple of Kiltia", "Exit to City Center" }, //

  // Great Cathedral B1
  { 22, 0, "Great Cathedral B1", "Sanity and Madness" }, //
  { 22, 4, "Great Cathedral B1", "Truth and Lies" }, //
  { 22, 6, "Great Cathedral B1", "Order and Chaos" }, //
  { 22, 7, "Great Cathedral B1", "The Victor's Laurels" }, //
  { 22, 8, "Great Cathedral B1", "Struggle for the Soul" }, //
  { 22, 9, "Great Cathedral B1", "An Offering of Souls" }, //

  // Great Cathedral L1
  { 24, 0, "Great Cathedral L1", "The Flayed Confessional" }, //
  { 24, 1, "Great Cathedral L1", "Monk's Leap" }, //
  { 24, 2, "Great Cathedral L1", "Where Darkness Spreads" }, //
  { 24, 3, "Great Cathedral L1", "Hieratic Recollections" }, //
  { 24, 4, "Great Cathedral L1", "A Light in the Dark" }, //
  { 24, 5, "Great Cathedral L1", "The Poisoned Chapel" }, //
  { 24, 6, "Great Cathedral L1", "Sin and Punishment" }, //
  { 24, 7, "Great Cathedral L1", "Cracked Pleasures" }, //
  { 24, 8, "Great Cathedral L1", "Into Holy Battle" }, //

  // Great Cathedral L2
  { 23, 1, "Great Cathedral L2", "He Screams for Mercy" }, //
  { 23, 2, "Great Cathedral L2", "Light and Dark Wage War" }, //
  { 23, 3, "Great Cathedral L2", "Abasement from Above" }, //
  { 24, 9, "Great Cathedral L2", "Maelstrom of Malice" }, //
  { 24, 10, "Great Cathedral L2", "The Acolyte's Weakness" }, //
  { 24, 11, "Great Cathedral L2", "The Hall of Broken Vows" }, //
  { 24, 12, "Great Cathedral L2", "The Melodics of Madness" }, //
  { 24, 13, "Great Cathedral L2", "Free from Base Desires" }, //
  { 24, 14, "Great Cathedral L2", "The Convent Room" }, //
  { 25, 0, "Great Cathedral L2", "An Arrow into Darkness" }, //
  { 25, 1, "Great Cathedral L2", "What Ails You, Kills You" }, //

  // Great Cathedral L3
  { 23, 4, "Great Cathedral L3", "The Heretics' Story" }, //
  { 23, 5, "Great Cathedral L3", "The Wine-Lecher's Fall" }, //
  { 24, 15, "Great Cathedral L3", "Hopes of the Idealist" }, //
  { 25, 2, "Great Cathedral L3", "Where the Soul Rots" }, //
  { 25, 3, "Great Cathedral L3", "Despair of the Fallen" }, //

  // Great Cathedral L4
  { 25, 4, "Great Cathedral L4", "The Atrium" }, //

  // Forgotten Pathway
  { 54, 0, "Forgotten Pathway", "Stair to the Sinners" }, //
  { 54, 1, "Forgotten Pathway", "Slaugher of the Innocent" }, //
  { 54, 2, "Forgotten Pathway", "The Fallen Knight" }, //
  { 54, 3, "Forgotten Pathway", "The Oracle Sins No More" }, //
  { 54, 4, "Forgotten Pathway", "Awaiting Retribution" }, //

  // Escapeway
  { 52, 0, "Escapeway", "Shelter From the Quake" }, //
  { 52, 1, "Escapeway", "Buried Alive" }, //
  { 52, 2, "Escapeway", "Movement of Fear" }, //
  { 52, 3, "Escapeway", "Facing Your Illusions" }, //
  { 52, 4, "Escapeway", "The Darkness Drinks" }, //
  { 52, 5, "Escapeway", "Fear and Loathing" }, //
  { 52, 6, "Escapeway", "Blood and the Beast" }, //
  { 52, 7, "Escapeway", "Where Body and Soul Part" }, //

  // Iron Maiden B1
  { 55, 0, "Iron Maiden B1", "The Cage" }, //
  { 55, 1, "Iron Maiden B1", "The Cauldron" }, //
  { 55, 2, "Iron Maiden B1", "Wooden Horse" }, //
  { 55, 3, "Iron Maiden B1", "Starvation" }, //
  { 55, 4, "Iron Maiden B1", "The Breast Ripper" }, //
  { 55, 5, "Iron Maiden B1", "The Pear" }, //
  { 55, 6, "Iron Maiden B1", "The Whirligig" }, //
  { 55, 7, "Iron Maiden B1", "Spanish Tickler" }, //
  { 55, 8, "Iron Maiden B1", "Heretic's Fork" }, //
  { 55, 9, "Iron Maiden B1", "The Chair of Spikes" }, //
  { 55, 10, "Iron Maiden B1", "Blooding" }, //
  { 55, 11, "Iron Maiden B1", "Bootikens" }, //
  { 55, 12, "Iron Maiden B1", "Burial" }, //
  { 55, 13, "Iron Maiden B1", "Burning" }, //
  { 55, 14, "Iron Maiden B1", "Cleansing the Soul" }, //
  { 55, 15, "Iron Maiden B1", "The Garotte" }, //
  { 55, 16, "Iron Maiden B1", "Hanging" }, //
  { 55, 17, "Iron Maiden B1", "Impalement" }, //
  { 55, 18, "Iron Maiden B1", "Knotting" }, //
  { 55, 19, "Iron Maiden B1", "The Branks" }, //
  { 55, 20, "Iron Maiden B1", "The Wheel" }, //
  { 55, 21, "Iron Maiden B1", "The Judas Cradle" }, //
  { 55, 22, "Iron Maiden B1", "The Ducking Stool" }, //

  // Iron Maiden B2
  { 56, 0, "Iron Maiden B2", "The Eunics' Lot" }, //
  { 56, 1, "Iron Maiden B2", "Ordeal By Fire" }, //
  { 56, 2, "Iron Maiden B2", "Tablillas" }, //
  { 56, 3, "Iron Maiden B2", "The Oven at Neisse" }, //
  { 56, 4, "Iron Maiden B2", "Strangulation" }, //
  { 56, 5, "Iron Maiden B2", "Pressing" }, //
  { 56, 6, "Iron Maiden B2", "The Strappado" }, //
  { 56, 7, "Iron Maiden B2", "The Mind Burns" }, //
  { 56, 8, "Iron Maiden B2", "Thumbscrews" }, //
  { 56, 9, "Iron Maiden B2", "The Rack" }, //
  { 56, 10, "Iron Maiden B2", "The Saw" }, //
  { 56, 11, "Iron Maiden B2", "Ordeal By Water" }, //
  { 56, 12, "Iron Maiden B2", "The Cold's Bridle" }, //
  { 56, 13, "Iron Maiden B2", "Brank" }, //
  { 56, 14, "Iron Maiden B2", "The Shin-Vice" }, //
  { 56, 15, "Iron Maiden B2", "Squassation" }, //
  { 56, 16, "Iron Maiden B2", "The Spider" }, //
  { 56, 17, "Iron Maiden B2", "Lead Sprinkler" }, //
  { 56, 18, "Iron Maiden B2", "Pendulum" }, //
  { 56, 19, "Iron Maiden B2", "Dragging" }, //
  { 56, 20, "Iron Maiden B2", "Tongue Slicer" }, //
  { 56, 21, "Iron Maiden B2", "Tormentum Insomniae" }, //

  // Iron Maiden B3
  { 56, 22, "Iron Maiden B3", "The Iron Maiden" }, //
  { 56, 23, "Iron Maiden B3", "Saint Elmo's Belt" }, //
  { 56, 24, "Iron Maiden B3", "Judgement" }, //
  { 56, 25, "Iron Maiden B3", "Dunking the Witch" }, //

  // Undercity West
  { 47, 0, "Undercity West", "Workshop \"Godhands\"" }, //
  { 48, 0, "Undercity West", "The Bread Peddler's Way" }, //
  { 48, 1, "Undercity West", "Way of the Mother Lode" }, //
  { 48, 2, "Undercity West", "Sewer of Ravenous Rats" }, //
  { 48, 3, "Undercity West", "Underdark Fishmarket" }, //
  { 48, 4, "Undercity West", "The Sunless Way" }, //
  { 48, 5, "Undercity West", "Remembering Days of Yore" }, //
  { 48, 6, "Undercity West", "Where the Hunter Climbed" }, //
  { 48, 7, "Undercity West", "Larder for a Lean Winter" }, //
  { 48, 8, "Undercity West", "Hall of Poverty" }, //
  { 48, 9, "Undercity West", "The Washing-Woman's Way" }, //
  { 48, 10, "Undercity West", "Beggars of the Mouthharp" }, //
  { 48, 11, "Undercity West", "Corner of the Wretched" }, //
  { 48, 12, "Undercity West", "Path to the Greengrocer" }, //
  { 48, 13, "Undercity West", "Crossroads of Rest" }, //
  { 48, 14, "Undercity West", "Path of the Children" }, //
  { 48, 15, "Undercity West", "Fear of the Fall" }, //
  { 48, 16, "Undercity West", "Sinner's Corner" }, //
  { 48, 17, "Undercity West", "Nameless Dark Oblivion" }, //
  { 48, 18, "Undercity West", "Corner of Prayers" }, //
  { 48, 19, "Undercity West", "Hope Obstructed" }, //
  { 48, 20, "Undercity West", "The Children's Hideout" }, //
  { 48, 21, "Undercity West", "The Crumbling Market" }, //
  { 48, 22, "Undercity West", "Tears from Empty Sockets" }, //
  { 48, 23, "Undercity West", "Where Flood Waters Ran" }, //
  { 48, 24, "Undercity West", "The Body Fragile Yields" }, //
  { 48, 25, "Undercity West", "Salvation for the Mother" }, //
  { 48, 26, "Undercity West", "Bite the Master's Wounds" }, //

  { 49, 0, "Undercity East", "Hall to a New World" }, //
  { 49, 1, "Undercity East", "Place of Free Words" }, //
  { 49, 2, "Undercity East", "Bazaar of the Bizarre" }, //
  { 49, 3, "Undercity East", "Noble Gold and Silk" }, //
  { 49, 4, "Undercity East", "A Knight Sells his Sword" }, //
  { 49, 5, "Undercity East", "Gemsword Blackmarket" }, //
  { 49, 6, "Undercity East", "The Pirate's Son" }, //
  { 49, 7, "Undercity East", "Sale of the Sword" }, //
  { 49, 8, "Undercity East", "Weapons Not Allowed" }, //
  { 49, 9, "Undercity East", "The Greengrocer's Stair" }, //
  { 49, 10, "Undercity East", "Where Black Waters Ran" }, //
  { 49, 11, "Undercity East", "Arms Against Invaders" }, //
  { 49, 12, "Undercity East", "Catspaw Blackmarket" }, //

  // The Keep
  { 29, 0, "The Keep", "The Warrior's Rest" }, //
  { 29, 2, "The Keep", "The Soldier's Bedding" }, //
  { 29, 3, "The Keep", "A Storm of Arrows" }, //
  { 29, 4, "The Keep", "Urge the Boy On" }, //
  { 29, 5, "The Keep", "A Taste of the Spoils" }, //
  { 29, 6, "The Keep", "Wiping Blood from Blades" }, //
  { 44, 0, "The Keep", "Workshop \"Keane's Crafts\"" }, //

  // City Walls West
  { 28, 0, "City Walls West", "Students of Death" }, //
  { 28, 1, "City Walls West", "The Gabled Hall" }, //
  { 28, 2, "City Walls West", "Where the Master Fell" }, //

  // City Walls South
  { 28, 3, "City Walls South", "The Weeping Boy" }, //
  { 28, 4, "City Walls South", "Swords for the Land" }, //
  { 28, 5, "City Walls South", "In Wait of the Foe" }, //
  { 28, 6, "City Walls South", "Where Weary Riders Rest" }, //
  { 28, 7, "City Walls South", "The Boy's Training Room" }, //

  // City Walls East
  { 28, 8, "City Walls East", "Train and Grow Strong" }, //
  { 28, 9, "City Walls East", "The Squire's Gathering" }, //
  { 28, 10, "City Walls East", "The Invaders are Found" }, //
  { 28, 11, "City Walls East", "The Dream-Weavers" }, //
  { 28, 12, "City Walls East", "The Cornered Savage" }, //

  { 28, 13, "City Walls North", "Traces of Invasion Past" }, //
  { 28, 14, "City Walls North", "From Squire to Knight" }, //
  { 28, 15, "City Walls North", "Be for Battle Prepared" }, //
  { 28, 16, "City Walls North", "Destruction and Rebirth" }, //
  { 28, 17, "City Walls North", "From Boy to Hero" }, //
  { 28, 18, "City Walls North", "A Welcome Invasion" }, //

  // Snowfly Forest
  { 40, 0, "Snowfly Forest", "The Hunt Begins" }, //
  { 40, 1, "Snowfly Forest", "Which Way Home" }, //
  { 40, 2, "Snowfly Forest", "The Giving Trees" }, //
  { 40, 3, "Snowfly Forest", "The Wounded Boar" }, //
  { 40, 4, "Snowfly Forest", "Golden Egg Way" }, //
  { 40, 5, "Snowfly Forest", "The Birds and the Bees" }, //
  { 40, 6, "Snowfly Forest", "The Woodcutter's Run" }, //
  { 40, 7, "Snowfly Forest", "The Wolves' Choice" }, //
  { 40, 8, "Snowfly Forest", "Howl of the Wolf King" }, //
  { 40, 9, "Snowfly Forest", "Fluttering Hope" }, //
  { 40, 10, "Snowfly Forest", "Traces of the Beast" }, //
  { 40, 11, "Snowfly Forest", "The Yellow Wood" }, //
  { 40, 12, "Snowfly Forest", "They Also Feed" }, //
  { 40, 13, "Snowfly Forest", "Where Soft Rains Fell" }, //
  { 40, 14, "Snowfly Forest", "The Spirit Trees" }, //
  { 40, 15, "Snowfly Forest", "The Silent Hedges" }, //
  { 40, 16, "Snowfly Forest", "Lamenting to the Moon" }, //
  { 40, 17, "Snowfly Forest", "The Hollow Hills" }, //
  { 40, 18, "Snowfly Forest", "Running with the Wolves" }, //
  { 40, 19, "Snowfly Forest", "You Are the Prey" }, //
  { 40, 20, "Snowfly Forest", "The Secret Path" }, //
  { 40, 21, "Snowfly Forest", "The Faerie Circle" }, //
  { 40, 22, "Snowfly Forest", "Return to the Land" }, //
  { 40, 23, "Snowfly Forest", "Forest River" }, //
  { 40, 24, "Snowfly Forest", "Hewn from Nature" }, //
  { 40, 25, "Snowfly Forest", "The Wood Gate" }, //

  // Snowfly Forest East
  { 41, 0, "Snowfly Forest East", "Steady the Boar-Spears" }, //
  { 41, 1, "Snowfly Forest East", "The Boar's Revenge" }, //
  { 41, 2, "Snowfly Forest East", "Nature's Womb" }, //

  // Town Center West
  { 32, 0, "Town Center West", "Rue Vermillion" }, //
  { 32, 1, "Town Center West", "The Rene Coastroad" }, //
  { 32, 2, "Town Center West", "Rue Mal Fallde" }, //
  { 32, 3, "Town Center West", "Tircolas Flow" }, //
  { 32, 4, "Town Center West", "Glacialdra Kirk Ruins" }, //
  { 32, 5, "Town Center West", "Rue Bouquet" }, //
  { 32, 6, "Town Center West", "Villeport Way" }, //
  { 32, 7, "Town Center West", "Rue Sant D'alsa" }, //
  { 34, 0, "Town Center West", "Dinas Walk" }, //
  { 43, 0, "Town Center West", "Workshop \"Magic Hammer\"" }, //

  { 32, 8, "Town Center South", "Valdiman Gates" }, //
  { 32, 9, "Town Center South", "Rue Faltes" }, //
  { 32, 10, "Town Center South", "Forcas Rise" }, //
  { 32, 11, "Town Center South", "Rue Aliano" }, //
  { 32, 12, "Town Center South", "Rue Volnac" }, //
  { 32, 13, "Town Center South", "Rue Morgue" }, //
  { 35, 0, "Town Center South", "Zebel's Walk" }, //
  { 37, 0, "Town Center South", "The House Khazabas" }, //

  { 32, 15, "Town Center East", "Rue Lejour" }, //
  { 32, 16, "Town Center East", "Kesch Bridge" }, //
  { 32, 17, "Town Center East", "Rue Crimnade" }, //
  { 32, 18, "Town Center East", "Rue Fisserano" }, //
  { 32, 19, "Town Center East", "Shasras Hill Park" }, //
  { 36, 0, "Town Center East", "Gharmes Walk" }, //
  { 38, 0, "Town Center East", "The House Gilgitte" }, //
  { 39, 0, "Town Center East", "Plateia Lumitar" }, //
  { 45, 0, "Town Center East", "Workshop \"Metal Works\"" }, //
  { 46, 0, "Town Center East", "Workshop \"Junction Point\"" }, //

  { 26, 0, "Great Cathedral L5", "Ashley finds dying Sydney" }, //
  { 70, 0, "Somewhere...", "The Dark tempts Ashley" }, //

  { 27, 0, "The Paling", "Guildenstern fight - P1" }, //
  { 27, 1, "The Paling", "Guildenstern fight - P2" }
};

void
ReadLocation()
{
  usize BytesToRead = sizeof(location);
  usize BytesRead =
      ReadGameMemory(processID, OFFSET_LOCATION, BytesToRead, &LocationCur);
}

BOOL
LocationChanged()
{
  usize DataSize = sizeof(location);

  BOOL Result =
      DataChanged((void *) &LocationPrev, (void *) &LocationCur, DataSize);

  return Result;
}

void
ReadZoneAndMapName(location *Location, char *ZoneName, char *MapName)
{
  // Clear the strings
  ZoneName[0] = '\0';
  MapName[0] = '\0';

  u8 ZoneNumber = Location->ZoneNumber;
  u8 MapNumber = Location->MapNumber;

  int counter = _countof(MapDataList);

  for (int i = 0; i < counter; i++)
  {
    if (MapDataList[i].ZoneNumber == ZoneNumber &&
        MapDataList[i].MapNumber == MapNumber)
    {
      sprintf(ZoneName, "%s", MapDataList[i].ZoneName);
      sprintf(MapName, "%s", MapDataList[i].MapName);

      break;
    }
  }
}

void
ReadZoneAndMapNameCustom(location *Location, char *nameZone, char *nameMap)
{
  // Clear the strings
  nameZone[0] = '\0';
  nameMap[0] = '\0';

  u8 ZoneNumber = Location->ZoneNumber;
  u8 MapNumber = Location->MapNumber;

  int counter = _countof(MapDataList);

  for (int i = 0; i < counter; i++)
  {
    if (MapDataList[i].ZoneNumber == ZoneNumber &&
        MapDataList[i].MapNumber == (MapNumber))
    {
      sprintf(nameZone, "%s", MapDataList[i].ZoneName);
      sprintf(nameMap, "%s", MapDataList[i].MapName);

      break;
    }
  }
}

void
WriteLocation()
{
  u8 ZoneNumber = LocationCur.ZoneNumber;
  u8 MapNumber = LocationCur.MapNumber;

  FILE *fpLocation = fopen("game_data/map/location.txt", "w");
  FILE *fpLocationDebug = fopen("game_data/map/location_debug.txt", "w");

  fprintf(fpLocation, "%s, %s\n", nameZone, nameMap);
  fprintf(fpLocationDebug, "%i,%i,%s,%s\n", ZoneNumber, MapNumber, nameZone,
      nameMap);

  fclose(fpLocation);
  fclose(fpLocationDebug);
}

void
PrintLocation()
{
  u8 ZoneNumber = LocationCur.ZoneNumber;
  u8 MapNumber = LocationCur.MapNumber;

  sprintf(szBuffer, "\n\nLOCATION:\n");
  WriteToBackBuffer();

  sprintf_s(szBuffer, _countof(szBuffer), "%s, %s ( Zone %i, Map %i )\n",
      nameZone, nameMap, ZoneNumber, MapNumber);
  WriteToBackBuffer();
}

BOOL
IsThisTheLastBossMap()
{
  if ((LocationCur.ZoneNumber == 27) && (LocationCur.MapNumber == 1))
  {
    return TRUE;
  }
  return FALSE;
}

#endif
