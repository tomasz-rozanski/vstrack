#ifndef _VS_ROOMS_H
#define _VS_ROOMS_H

// Location struct - 2 bytes
#define OFFSET_LOCATION 0x0f1ab0

// Room data (1 byte each)
#define OFFSET_LOCATION_AREA_NUMBER 0x0f1ab0
#define OFFSET_LOCATION_ROOM_NUMBER 0x0f1ab1

// write 0x02 at this address, to teleport
#define OFFSET_LOCATION_ROOM_TELEPORT 0x0f1a48

typedef struct {
    u8 ZoneNumber;
    u8 MapNumber;
    wchar_t *ZoneName;
    wchar_t *MapName;
} map_data;

map_data MapDataList[] = {
    // Loading screen
    { 0, 0, L"In the void", L"Nothing to see here..." }, //

    // Intro 1
    { 1, 0, L"Intro", L"Guildenstern talks with the knight" }, //
    { 2, 0, L"Intro", L"Ashley at the gate" }, //
    { 3, 0, L"Intro", L"Ashley at the courtyard" }, //
    { 4, 0, L"Intro", L"Ashley in the hall" }, //
    { 5, 0, L"Intro", L"Ashley meets Sydney" }, //
    { 6, 0, L"Intro", L"Ashley fights Wyvern" }, //
    { 7, 0, L"Intro", L"Ashley walks to the window" }, //
    { 8, 0, L"Intro", L"Ashley stares through the window" }, //
    { 18, 0, L"Intro", L"Bardorba and Rosencrantz in Graylands Manor" }, //
    { 33, 0, L"Intro", L"Merlose finds corpses at Lea Monde's entrance" }, //
    { 10, 0, L"Intro", L"Ashley and Merlose at the tunnel entrance" }, //
    { 9, 14, L"Intro", L"Ashley and Merlose at the Wine Cellar gate" }, //

    // Intro 2
    { 20, 0, L"Intro", L"VKP briefing" }, //
    { 21, 0, L"Intro", L"Ashley meets Merlose outside manor" }, //

    // Outro
    { 60, 0, L"Epilogue", L"Merlose, Hardin, and Joshua fleeing the city" }, //
    { 61, 0, L"Epilogue", L"Pigmen crushed by the falling debris" }, //
    { 62, 0, L"Epilogue", L"Tieger and Neesa stopped by Grissom" }, //
    { 63, 0, L"Epilogue", L"Ashley carries Sydney" }, //
    { 64, 0, L"Epilogue", L"Creatures of the dark vanish" }, //
    { 65, 0, L"Epilogue", L"The Well explodes" }, //
    { 66, 0, L"Epilogue", L"Hardin dies" }, //
    { 67, 0, L"Epilogue", L"Bardorba reunion" }, //
    { 68, 0, L"Epilogue", L"Ashley patrols the streets" }, //

    // Wine Cellar
    { 9, 0, L"Wine Cellar", L"Entrance to Darkness" }, //
    { 9, 1, L"Wine Cellar", L"Room of Cheap Red Wine" }, //
    { 9, 2, L"Wine Cellar", L"Room of Cheap White Wine" }, //
    { 9, 3, L"Wine Cellar", L"Hall of Struggle" }, //
    { 9, 4, L"Wine Cellar", L"Smokebarrel Stair" }, //
    { 9, 5, L"Wine Cellar", L"Wine Guild Hall" }, //
    { 9, 6, L"Wine Cellar", L"Wine Magnate\'s Chambers" }, //
    { 9, 7, L"Wine Cellar", L"Fine Vintage Vault" }, //
    { 9, 8, L"Wine Cellar", L"Chamber of Fear" }, //
    { 9, 9, L"Wine Cellar", L"The Reckoning Room" }, //
    { 9, 10, L"Wine Cellar", L"A Laborer's Thirst" }, //
    { 9, 11, L"Wine Cellar", L"The Rich Drown in Wine" }, //
    { 9, 12, L"Wine Cellar", L"Room of Rotten Grapes" }, //
    { 9, 13, L"Wine Cellar", L"Chamber of Fear" }, //
    { 9, 15, L"Wine Cellar", L"The Greedy One's Den" }, //
    { 9, 16, L"Wine Cellar", L"Worker's Breakroom" }, //
    { 9, 17, L"Wine Cellar", L"Blackmarket of Wines" }, //
    { 9, 18, L"Wine Cellar", L"Room of Rotten Grapes" }, //
    { 11, 0, L"Wine Cellar", L"The Hero's Winehall" }, //
    { 12, 0, L"Wine Cellar", L"The Gallows" }, //
    { 12, 1, L"Wine Cellar", L"The Gallows" }, //

    // Catacombs
    { 13, 0, L"Catacombs", L"Hall of Sworn Revenge" }, //
    { 13, 1, L"Catacombs", L"The Last Blessing" }, //
    { 13, 2, L"Catacombs", L"The Weeping Corridor" }, //
    { 13, 3, L"Catacombs", L"Persecution Hall" }, //
    { 13, 4, L"Catacombs", L"The Lamenting Mother" }, //
    { 13, 5, L"Catacombs", L"Rodent-Ridden Chamber" }, //
    { 13, 6, L"Catacombs", L"Shrine to the Martyrs" }, //
    { 13, 8, L"Catacombs", L"Hall of Dying Hope" }, //
    { 13, 9, L"Catacombs", L"Bandits' Hideout" }, //
    { 13, 10, L"Catacombs", L"The Bloody Hallway" }, //
    { 13, 11, L"Catacombs", L"Faith Overcame Fear" }, //
    { 13, 12, L"Catacombs", L"The Withered Spring" }, //
    { 13, 13, L"Catacombs", L"Repent, O ye Sinners" }, //
    { 13, 14, L"Catacombs", L"The Reaper's Victims" }, //
    { 13, 15, L"Catacombs", L"The Last Stab of Hope" }, //
    { 13, 16, L"Catacombs", L"Hallway of Heroes" }, //
    { 13, 17, L"Catacombs", L"The Lamenting Mother" }, //
    { 14, 0, L"Catacombs", L"The Beast's Domain" }, //
    { 42, 0, L"Catacombs", L"Workshop \"Work of Art\"" }, //

    // Sanctum
    { 15, 0, L"Sanctum", L"Prisoners' Niche" }, //
    { 15, 1, L"Sanctum", L"Corridor of the Clerics" }, //
    { 15, 2, L"Sanctum", L"Priests' Confinement" }, //
    { 15, 3, L"Sanctum", L"Alchemists' Laboratory" }, //
    { 15, 4, L"Sanctum", L"Theology Classroom" }, //
    { 15, 5, L"Sanctum", L"Shrine of the Martyrs" }, //
    { 15, 6, L"Sanctum", L"Advent Ground" }, //
    { 15, 7, L"Sanctum", L"Passage of the Refugees" }, //
    { 15, 8, L"Sanctum", L"Passage of the Refugees" }, //
    { 15, 10, L"Sanctum", L"Stairway to the Light" }, //
    { 15, 11, L"Sanctum", L"Hallowed Hope" }, //
    { 15, 12, L"Sanctum", L"The Academia Corridor" }, //
    { 16, 0, L"Sanctum", L"Hall of Sacrilege" }, //
    { 17, 0, L"Sanctum", L"The Cleansing Chantry" }, //

    // Abandoned Mines B1
    { 50, 0, L"Abandoned Mines B1", L"Dreamers' Entrance" }, //
    { 50, 1, L"Abandoned Mines B1", L"Miners' Resting Hall" }, //
    { 50, 2, L"Abandoned Mines B1", L"The Crossing" }, //
    { 50, 3, L"Abandoned Mines B1", L"Conflict and Accord" }, //
    { 50, 4, L"Abandoned Mines B1", L"The Suicide King" }, //
    { 50, 5, L"Abandoned Mines B1", L"The End of the Line" }, //
    { 50, 6, L"Abandoned Mines B1", L"The Battle's Beginning" }, //
    { 50, 7, L"Abandoned Mines B1", L"What Lies Ahead?" }, //
    { 50, 8, L"Abandoned Mines B1", L"The Fruits of Friendship" }, //
    { 50, 9, L"Abandoned Mines B1", L"The Earthquake's Mark" }, //
    { 50, 10, L"Abandoned Mines B1", L"Coal Mine Storage" }, //
    { 50, 11, L"Abandoned Mines B1", L"The Passion of Lovers" }, //
    { 50, 12, L"Abandoned Mines B1", L"The Hall of Hope" }, //
    { 50, 13, L"Abandoned Mines B1", L"The Dark Tunnel" }, //
    { 50, 14, L"Abandoned Mines B1", L"Rust in Peace" }, //
    { 50, 15, L"Abandoned Mines B1", L"Everwant Passage" }, //
    { 50, 16, L"Abandoned Mines B1", L"Mining Regrets" }, //
    { 50, 17, L"Abandoned Mines B1", L"The Smeltry" }, //
    { 50, 18, L"Abandoned Mines B1", L"Clash of Hyaenas" }, //
    { 50, 19, L"Abandoned Mines B1", L"Greed Knows No Bounds" }, //
    { 50, 20, L"Abandoned Mines B1", L"Live Long and Prosper" }, //
    { 50, 21, L"Abandoned Mines B1", L"Pray to the Mineral Gods" }, //
    { 50, 22, L"Abandoned Mines B1", L"Traitor's Parting" }, //
    { 50, 23, L"Abandoned Mines B1", L"Escapeway" }, //

    // Abandoned Mines B2
    { 51, 0, L"Abandoned Mines B2", L"Gambler's Passage" }, //
    { 51, 1, L"Abandoned Mines B2", L"Treaty Room" }, //
    { 51, 2, L"Abandoned Mines B2", L"The Miner's End" }, //
    { 51, 3, L"Abandoned Mines B2", L"Work, Then Die" }, //
    { 51, 4, L"Abandoned Mines B2", L"Bandits' Hollow" }, //
    { 51, 5, L"Abandoned Mines B2", L"Delusions of Happiness" }, //
    { 51, 6, L"Abandoned Mines B2", L"Dining in Darkness" }, //
    { 51, 7, L"Abandoned Mines B2", L"Subtellurian Horrors" }, //
    { 51, 8, L"Abandoned Mines B2", L"Hidden Resources" }, //
    { 51, 9, L"Abandoned Mines B2", L"Way of Lost Children" }, //
    { 51, 10, L"Abandoned Mines B2", L"Hall of the Empty Sconce" }, //
    { 51, 11, L"Abandoned Mines B2", L"Acolyte's Burial Vault" }, //
    { 51, 12, L"Abandoned Mines B2", L"Hall of Contemplation" }, //
    { 51, 13, L"Abandoned Mines B2", L"The Abandoned Catspaw" }, //
    { 51, 14, L"Abandoned Mines B2", L"Tomb of the Reborn" }, //
    { 51, 15, L"Abandoned Mines B2", L"The Fallen Bricklayer" }, //
    { 51, 16, L"Abandoned Mines B2", L"Crossing of Blood" }, //
    { 51, 17, L"Abandoned Mines B2", L"Fool's Gold, Fool's Loss" }, //
    { 51, 18, L"Abandoned Mines B2", L"Cry of the Beast" }, //
    { 51, 19, L"Abandoned Mines B2", L"Senses Lost" }, //
    { 51, 20, L"Abandoned Mines B2", L"Desire's Passage" }, //
    { 51, 21, L"Abandoned Mines B2", L"Kilroy Was Here" }, //
    { 51, 22, L"Abandoned Mines B2", L"Suicidal Desires" }, //
    { 51, 23, L"Abandoned Mines B2", L"The Ore of Legend" }, //
    { 51, 24, L"Abandoned Mines B2", L"Lambs to the Slaughter" }, //
    { 51, 25, L"Abandoned Mines B2", L"A Wager of Noble Gold" }, //
    { 51, 26, L"Abandoned Mines B2", L"The Lunatic Veins" }, //
    { 51, 27, L"Abandoned Mines B2", L"Corridor of Shade" }, //
    { 51, 28, L"Abandoned Mines B2", L"Revelation Shaft" }, //

    // Limestone Quarry
    { 53, 0, L"Limestone Quarry", L"Dark Abhors Light" }, //
    { 53, 1, L"Limestone Quarry", L"Dream of the Holy Land" }, //
    { 53, 2, L"Limestone Quarry", L"The Ore Road" }, //
    { 53, 3, L"Limestone Quarry", L"Atone for Eternity" }, //
    { 53, 4, L"Limestone Quarry", L"The Air Stirs" }, //
    { 53, 5, L"Limestone Quarry", L"Bonds of Friendship" }, //
    { 53, 6, L"Limestone Quarry", L"Stair to Sanctuary" }, //
    { 53, 7, L"Limestone Quarry", L"The Fallen Hall" }, //
    { 53, 8, L"Limestone Quarry", L"The Rotten Core" }, //
    { 53, 9, L"Limestone Quarry", L"Bacchus is Cheap" }, //
    { 53, 10, L"Limestone Quarry", L"Screams of the Wounded" }, //
    { 53, 11, L"Limestone Quarry", L"The Ore-Bearers" }, //
    { 53, 12, L"Limestone Quarry", L"The Dreamer's Climb" }, //
    { 53, 13, L"Limestone Quarry", L"Sinner's Sustenence" }, //
    { 53, 14, L"Limestone Quarry", L"The Timely Dew of Sleep" }, //
    { 53, 15, L"Limestone Quarry", L"Companions in Arms" }, //
    { 53, 16, L"Limestone Quarry", L"The Auction Block" }, //
    { 53, 17, L"Limestone Quarry", L"Ascension" }, //
    { 53, 18, L"Limestone Quarry", L"Where the Serpent Hunts" }, //
    { 53, 19, L"Limestone Quarry", L"Ants Prepare for Winter" }, //
    { 53, 20, L"Limestone Quarry", L"Drowned in Fleeting Joy" }, //
    { 53, 21, L"Limestone Quarry", L"The Laborer's Bonfire" }, //
    { 53, 22, L"Limestone Quarry", L"Stone and Sulfurous Fire" }, //
    { 53, 23, L"Limestone Quarry", L"Torture Without End" }, //
    { 53, 24, L"Limestone Quarry", L"Way Down" }, //
    { 53, 25, L"Limestone Quarry", L"Excavated Hollow" }, //
    { 53, 26, L"Limestone Quarry", L"Parting Regrets" }, //
    { 53, 27, L"Limestone Quarry", L"Corridor of Tales" }, //
    { 53, 28, L"Limestone Quarry", L"Dust Shall Eat the Days" }, //
    { 53, 29, L"Limestone Quarry", L"Hall of the Wage-Paying" }, //
    { 53, 31, L"Limestone Quarry", L"Tunnel of the Heartless" }, //

    // Temple of Kiltia
    { 30, 0, L"Temple of Kiltia", L"The Dark Coast" }, //
    { 30, 1, L"Temple of Kiltia", L"Hall of Prayer" }, //
    { 30, 2, L"Temple of Kiltia", L"Those who Drink the Dark" }, //
    { 30, 3, L"Temple of Kiltia", L"The Chapel of Meschaunce" }, //
    { 30, 4, L"Temple of Kiltia", L"The Resentful Ones" }, //
    { 30, 5, L"Temple of Kiltia", L"Those who Fear the Light" }, //
    { 31, 0, L"Temple of Kiltia", L"Chamber of Reason" }, //
    { 31, 1, L"Temple of Kiltia", L"Exit to City Center" }, //

    // Great Cathedral B1
    { 22, 0, L"Great Cathedral B1", L"Sanity and Madness" }, //
    { 22, 4, L"Great Cathedral B1", L"Truth and Lies" }, //
    { 22, 6, L"Great Cathedral B1", L"Order and Chaos" }, //
    { 22, 7, L"Great Cathedral B1", L"The Victor's Laurels" }, //
    { 22, 8, L"Great Cathedral B1", L"Struggle for the Soul" }, //
    { 22, 9, L"Great Cathedral B1", L"An Offering of Souls" }, //

    // Great Cathedral L1
    { 24, 0, L"Great Cathedral L1", L"The Flayed Confessional" }, //
    { 24, 1, L"Great Cathedral L1", L"Monk's Leap" }, //
    { 24, 2, L"Great Cathedral L1", L"Where Darkness Spreads" }, //
    { 24, 3, L"Great Cathedral L1", L"Hieratic Recollections" }, //
    { 24, 4, L"Great Cathedral L1", L"A Light in the Dark" }, //
    { 24, 5, L"Great Cathedral L1", L"The Poisoned Chapel" }, //
    { 24, 6, L"Great Cathedral L1", L"Sin and Punishment" }, //
    { 24, 7, L"Great Cathedral L1", L"Cracked Pleasures" }, //
    { 24, 8, L"Great Cathedral L1", L"Into Holy Battle" }, //

    // Great Cathedral L2
    { 23, 1, L"Great Cathedral L2", L"He Screams for Mercy" }, //
    { 23, 2, L"Great Cathedral L2", L"Light and Dark Wage War" }, //
    { 23, 3, L"Great Cathedral L2", L"Abasement from Above" }, //
    { 24, 9, L"Great Cathedral L2", L"Maelstrom of Malice" }, //
    { 24, 10, L"Great Cathedral L2", L"The Acolyte's Weakness" }, //
    { 24, 11, L"Great Cathedral L2", L"The Hall of Broken Vows" }, //
    { 24, 12, L"Great Cathedral L2", L"The Melodics of Madness" }, //
    { 24, 13, L"Great Cathedral L2", L"Free from Base Desires" }, //
    { 24, 14, L"Great Cathedral L2", L"The Convent Room" }, //
    { 25, 0, L"Great Cathedral L2", L"An Arrow into Darkness" }, //
    { 25, 1, L"Great Cathedral L2", L"What Ails You, Kills You" }, //

    // Great Cathedral L3
    { 23, 4, L"Great Cathedral L3", L"The Heretics' Story" }, //
    { 23, 5, L"Great Cathedral L3", L"The Wine-Lecher's Fall" }, //
    { 24, 15, L"Great Cathedral L3", L"Hopes of the Idealist" }, //
    { 25, 2, L"Great Cathedral L3", L"Where the Soul Rots" }, //
    { 25, 3, L"Great Cathedral L3", L"Despair of the Fallen" }, //

    // Great Cathedral L4
    { 25, 4, L"Great Cathedral L4", L"The Atrium" }, //

    // Forgotten Pathway
    { 54, 0, L"Forgotten Pathway", L"Stair to the Sinners" }, //
    { 54, 1, L"Forgotten Pathway", L"Slaugher of the Innocent" }, //
    { 54, 2, L"Forgotten Pathway", L"The Fallen Knight" }, //
    { 54, 3, L"Forgotten Pathway", L"The Oracle Sins No More" }, //
    { 54, 4, L"Forgotten Pathway", L"Awaiting Retribution" }, //

    // Escapeway
    { 52, 0, L"Escapeway", L"Shelter From the Quake" }, //
    { 52, 1, L"Escapeway", L"Buried Alive" }, //
    { 52, 2, L"Escapeway", L"Movement of Fear" }, //
    { 52, 3, L"Escapeway", L"Facing Your Illusions" }, //
    { 52, 4, L"Escapeway", L"The Darkness Drinks" }, //
    { 52, 5, L"Escapeway", L"Fear and Loathing" }, //
    { 52, 6, L"Escapeway", L"Blood and the Beast" }, //
    { 52, 7, L"Escapeway", L"Where Body and Soul Part" }, //

    // Iron Maiden B1
    { 55, 0, L"Iron Maiden B1", L"The Cage" }, //
    { 55, 1, L"Iron Maiden B1", L"The Cauldron" }, //
    { 55, 2, L"Iron Maiden B1", L"Wooden Horse" }, //
    { 55, 3, L"Iron Maiden B1", L"Starvation" }, //
    { 55, 4, L"Iron Maiden B1", L"The Breast Ripper" }, //
    { 55, 5, L"Iron Maiden B1", L"The Pear" }, //
    { 55, 6, L"Iron Maiden B1", L"The Whirligig" }, //
    { 55, 7, L"Iron Maiden B1", L"Spanish Tickler" }, //
    { 55, 8, L"Iron Maiden B1", L"Heretic's Fork" }, //
    { 55, 9, L"Iron Maiden B1", L"The Chair of Spikes" }, //
    { 55, 10, L"Iron Maiden B1", L"Blooding" }, //
    { 55, 11, L"Iron Maiden B1", L"Bootikens" }, //
    { 55, 12, L"Iron Maiden B1", L"Burial" }, //
    { 55, 13, L"Iron Maiden B1", L"Burning" }, //
    { 55, 14, L"Iron Maiden B1", L"Cleansing the Soul" }, //
    { 55, 15, L"Iron Maiden B1", L"The Garotte" }, //
    { 55, 16, L"Iron Maiden B1", L"Hanging" }, //
    { 55, 17, L"Iron Maiden B1", L"Impalement" }, //
    { 55, 18, L"Iron Maiden B1", L"Knotting" }, //
    { 55, 19, L"Iron Maiden B1", L"The Branks" }, //
    { 55, 20, L"Iron Maiden B1", L"The Wheel" }, //
    { 55, 21, L"Iron Maiden B1", L"The Judas Cradle" }, //
    { 55, 22, L"Iron Maiden B1", L"The Ducking Stool" }, //

    // Iron Maiden B2
    { 56, 0, L"Iron Maiden B2", L"The Eunics' Lot" }, //
    { 56, 1, L"Iron Maiden B2", L"Ordeal By Fire" }, //
    { 56, 2, L"Iron Maiden B2", L"Tablillas" }, //
    { 56, 3, L"Iron Maiden B2", L"The Oven at Neisse" }, //
    { 56, 4, L"Iron Maiden B2", L"Strangulation" }, //
    { 56, 5, L"Iron Maiden B2", L"Pressing" }, //
    { 56, 6, L"Iron Maiden B2", L"The Strappado" }, //
    { 56, 7, L"Iron Maiden B2", L"The Mind Burns" }, //
    { 56, 8, L"Iron Maiden B2", L"Thumbscrews" }, //
    { 56, 9, L"Iron Maiden B2", L"The Rack" }, //
    { 56, 10, L"Iron Maiden B2", L"The Saw" }, //
    { 56, 11, L"Iron Maiden B2", L"Ordeal By Water" }, //
    { 56, 12, L"Iron Maiden B2", L"The Cold's Bridle" }, //
    { 56, 13, L"Iron Maiden B2", L"Brank" }, //
    { 56, 14, L"Iron Maiden B2", L"The Shin-Vice" }, //
    { 56, 15, L"Iron Maiden B2", L"Squassation" }, //
    { 56, 16, L"Iron Maiden B2", L"The Spider" }, //
    { 56, 17, L"Iron Maiden B2", L"Lead Sprinkler" }, //
    { 56, 18, L"Iron Maiden B2", L"Pendulum" }, //
    { 56, 19, L"Iron Maiden B2", L"Dragging" }, //
    { 56, 20, L"Iron Maiden B2", L"Tongue Slicer" }, //
    { 56, 21, L"Iron Maiden B2", L"Tormentum Insomniae" }, //

    // Iron Maiden B3
    { 56, 22, L"Iron Maiden B3", L"The Iron Maiden" }, //
    { 56, 23, L"Iron Maiden B3", L"Saint Elmo's Belt" }, //
    { 56, 24, L"Iron Maiden B3", L"Judgement" }, //
    { 56, 25, L"Iron Maiden B3", L"Dunking the Witch" }, //

    // Undercity West
    { 47, 0, L"Undercity West", L"Workshop \"Godhands\"" }, //
    { 48, 0, L"Undercity West", L"The Bread Peddler's Way" }, //
    { 48, 1, L"Undercity West", L"Way of the Mother Lode" }, //
    { 48, 2, L"Undercity West", L"Sewer of Ravenous Rats" }, //
    { 48, 3, L"Undercity West", L"Underdark Fishmarket" }, //
    { 48, 4, L"Undercity West", L"The Sunless Way" }, //
    { 48, 5, L"Undercity West", L"Remembering Days of Yore" }, //
    { 48, 6, L"Undercity West", L"Where the Hunter Climbed" }, //
    { 48, 7, L"Undercity West", L"Larder for a Lean Winter" }, //
    { 48, 8, L"Undercity West", L"Hall of Poverty" }, //
    { 48, 9, L"Undercity West", L"The Washing-Woman's Way" }, //
    { 48, 10, L"Undercity West", L"Beggars of the Mouthharp" }, //
    { 48, 11, L"Undercity West", L"Corner of the Wretched" }, //
    { 48, 12, L"Undercity West", L"Path to the Greengrocer" }, //
    { 48, 13, L"Undercity West", L"Crossroads of Rest" }, //
    { 48, 14, L"Undercity West", L"Path of the Children" }, //
    { 48, 15, L"Undercity West", L"Fear of the Fall" }, //
    { 48, 16, L"Undercity West", L"Sinner's Corner" }, //
    { 48, 17, L"Undercity West", L"Nameless Dark Oblivion" }, //
    { 48, 18, L"Undercity West", L"Corner of Prayers" }, //
    { 48, 19, L"Undercity West", L"Hope Obstructed" }, //
    { 48, 20, L"Undercity West", L"The Children's Hideout" }, //
    { 48, 21, L"Undercity West", L"The Crumbling Market" }, //
    { 48, 22, L"Undercity West", L"Tears from Empty Sockets" }, //
    { 48, 23, L"Undercity West", L"Where Flood Waters Ran" }, //
    { 48, 24, L"Undercity West", L"The Body Fragile Yields" }, //
    { 48, 25, L"Undercity West", L"Salvation for the Mother" }, //
    { 48, 26, L"Undercity West", L"Bite the Master's Wounds" }, //

    { 49, 0, L"Undercity East", L"Hall to a New World" }, //
    { 49, 1, L"Undercity East", L"Place of Free Words" }, //
    { 49, 2, L"Undercity East", L"Bazaar of the Bizarre" }, //
    { 49, 3, L"Undercity East", L"Noble Gold and Silk" }, //
    { 49, 4, L"Undercity East", L"A Knight Sells his Sword" }, //
    { 49, 5, L"Undercity East", L"Gemsword Blackmarket" }, //
    { 49, 6, L"Undercity East", L"The Pirate's Son" }, //
    { 49, 7, L"Undercity East", L"Sale of the Sword" }, //
    { 49, 8, L"Undercity East", L"Weapons Not Allowed" }, //
    { 49, 9, L"Undercity East", L"The Greengrocer's Stair" }, //
    { 49, 10, L"Undercity East", L"Where Black Waters Ran" }, //
    { 49, 11, L"Undercity East", L"Arms Against Invaders" }, //
    { 49, 12, L"Undercity East", L"Catspaw Blackmarket" }, //

    // The Keep
    { 29, 0, L"The Keep", L"The Warrior's Rest" }, //
    { 29, 2, L"The Keep", L"The Soldier's Bedding" }, //
    { 29, 3, L"The Keep", L"A Storm of Arrows" }, //
    { 29, 4, L"The Keep", L"Urge the Boy On" }, //
    { 29, 5, L"The Keep", L"A Taste of the Spoils" }, //
    { 29, 6, L"The Keep", L"Wiping Blood from Blades" }, //
    { 44, 0, L"The Keep", L"Workshop \"Keane's Crafts\"" }, //

    // City Walls West
    { 28, 0, L"City Walls West", L"Students of Death" }, //
    { 28, 1, L"City Walls West", L"The Gabled Hall" }, //
    { 28, 2, L"City Walls West", L"Where the Master Fell" }, //

    // City Walls South
    { 28, 3, L"City Walls South", L"The Weeping Boy" }, //
    { 28, 4, L"City Walls South", L"Swords for the Land" }, //
    { 28, 5, L"City Walls South", L"In Wait of the Foe" }, //
    { 28, 6, L"City Walls South", L"Where Weary Riders Rest" }, //
    { 28, 7, L"City Walls South", L"The Boy's Training Room" }, //

    // City Walls East
    { 28, 8, L"City Walls East", L"Train and Grow Strong" }, //
    { 28, 9, L"City Walls East", L"The Squire's Gathering" }, //
    { 28, 10, L"City Walls East", L"The Invaders are Found" }, //
    { 28, 11, L"City Walls East", L"The Dream-Weavers" }, //
    { 28, 12, L"City Walls East", L"The Cornered Savage" }, //

    { 28, 13, L"City Walls North", L"Traces of Invasion Past" }, //
    { 28, 14, L"City Walls North", L"From Squire to Knight" }, //
    { 28, 15, L"City Walls North", L"Be for Battle Prepared" }, //
    { 28, 16, L"City Walls North", L"Destruction and Rebirth" }, //
    { 28, 17, L"City Walls North", L"From Boy to Hero" }, //
    { 28, 18, L"City Walls North", L"A Welcome Invasion" }, //

    // Snowfly Forest
    { 40, 0, L"Snowfly Forest", L"The Hunt Begins" }, //
    { 40, 1, L"Snowfly Forest", L"Which Way Home" }, //
    { 40, 2, L"Snowfly Forest", L"The Giving Trees" }, //
    { 40, 3, L"Snowfly Forest", L"The Wounded Boar" }, //
    { 40, 4, L"Snowfly Forest", L"Golden Egg Way" }, //
    { 40, 5, L"Snowfly Forest", L"The Birds and the Bees" }, //
    { 40, 6, L"Snowfly Forest", L"The Woodcutter's Run" }, //
    { 40, 7, L"Snowfly Forest", L"The Wolves' Choice" }, //
    { 40, 8, L"Snowfly Forest", L"Howl of the Wolf King" }, //
    { 40, 9, L"Snowfly Forest", L"Fluttering Hope" }, //
    { 40, 10, L"Snowfly Forest", L"Traces of the Beast" }, //
    { 40, 11, L"Snowfly Forest", L"The Yellow Wood" }, //
    { 40, 12, L"Snowfly Forest", L"They Also Feed" }, //
    { 40, 13, L"Snowfly Forest", L"Where Soft Rains Fell" }, //
    { 40, 14, L"Snowfly Forest", L"The Spirit Trees" }, //
    { 40, 15, L"Snowfly Forest", L"The Silent Hedges" }, //
    { 40, 16, L"Snowfly Forest", L"Lamenting to the Moon" }, //
    { 40, 17, L"Snowfly Forest", L"The Hollow Hills" }, //
    { 40, 18, L"Snowfly Forest", L"Running with the Wolves" }, //
    { 40, 19, L"Snowfly Forest", L"You Are the Prey" }, //
    { 40, 20, L"Snowfly Forest", L"The Secret Path" }, //
    { 40, 21, L"Snowfly Forest", L"The Faerie Circle" }, //
    { 40, 22, L"Snowfly Forest", L"Return to the Land" }, //
    { 40, 23, L"Snowfly Forest", L"Forest River" }, //
    { 40, 24, L"Snowfly Forest", L"Hewn from Nature" }, //
    { 40, 25, L"Snowfly Forest", L"The Wood Gate" }, //

    // Snowfly Forest East
    { 41, 0, L"Snowfly Forest East", L"Steady the Boar-Spears" }, //
    { 41, 1, L"Snowfly Forest East", L"The Boar's Revenge" }, //
    { 41, 2, L"Snowfly Forest East", L"Nature's Womb" }, //

    // Town Center West
    { 32, 0, L"Town Center West", L"Rue Vermillion" }, //
    { 32, 1, L"Town Center West", L"The Rene Coastroad" }, //
    { 32, 2, L"Town Center West", L"Rue Mal Fallde" }, //
    { 32, 3, L"Town Center West", L"Tircolas Flow" }, //
    { 32, 4, L"Town Center West", L"Glacialdra Kirk Ruins" }, //
    { 32, 5, L"Town Center West", L"Rue Bouquet" }, //
    { 32, 6, L"Town Center West", L"Villeport Way" }, //
    { 32, 7, L"Town Center West", L"Rue Sant D'alsa" }, //
    { 34, 0, L"Town Center West", L"Dinas Walk" }, //
    { 43, 0, L"Town Center West", L"Workshop \"Magic Hammer\"" }, //

    { 32, 8, L"Town Center South", L"Valdiman Gates" }, //
    { 32, 9, L"Town Center South", L"Rue Faltes" }, //
    { 32, 10, L"Town Center South", L"Forcas Rise" }, //
    { 32, 11, L"Town Center South", L"Rue Aliano" }, //
    { 32, 12, L"Town Center South", L"Rue Volnac" }, //
    { 32, 13, L"Town Center South", L"Rue Morgue" }, //
    { 35, 0, L"Town Center South", L"Zebel's Walk" }, //
    { 37, 0, L"Town Center South", L"The House Khazabas" }, //

    { 32, 15, L"Town Center East", L"Rue Lejour" }, //
    { 32, 16, L"Town Center East", L"Kesch Bridge" }, //
    { 32, 17, L"Town Center East", L"Rue Crimnade" }, //
    { 32, 18, L"Town Center East", L"Rue Fisserano" }, //
    { 32, 19, L"Town Center East", L"Shasras Hill Park" }, //
    { 36, 0, L"Town Center East", L"Gharmes Walk" }, //
    { 38, 0, L"Town Center East", L"The House Gilgitte" }, //
    { 39, 0, L"Town Center East", L"Plateia Lumitar" }, //
    { 45, 0, L"Town Center East", L"Workshop \"Metal Works\"" }, //
    { 46, 0, L"Town Center East", L"Workshop \"Junction Point\"" }, //

    { 26, 0, L"Great Cathedral L5", L"Ashley finds dying Sydney" }, //
    { 70, 0, L"Somewhere...", L"The Dark tempts Ashley" }, //

    { 27, 0, L"The Paling", L"Guildenstern fight - P1" }, //
    { 27, 1, L"The Paling", L"Guildenstern fight - P2" }
};

void
ReadLocation() {
    usize BytesToRead = sizeof(location);
    usize BytesRead =
        ReadGameMemory(processID, OFFSET_LOCATION, BytesToRead, &LocationCur);
}

BOOL
LocationChanged() {
    usize DataSize = sizeof(location);

    BOOL Result =
        DataChanged((void *) &LocationPrev, (void *) &LocationCur, DataSize);

    return Result;
}

void
ReadZoneAndMapName(location *Location, wchar_t *ZoneName, wchar_t *MapName) {
    // Clear the strings
    ZoneName[0] = L'\0';
    MapName[0] = L'\0';

    u8 ZoneNumber = Location->ZoneNumber;
    u8 MapNumber = Location->MapNumber;

    int counter = _countof(MapDataList);

    for (int i = 0; i < counter; i++) {
        if (MapDataList[i].ZoneNumber == ZoneNumber &&
                MapDataList[i].MapNumber == (MapNumber)) {
            swprintf_s(ZoneName, LOCATION_MAX_NAME_LENGTH, L"%ls", MapDataList[i].ZoneName);
            swprintf_s(MapName, LOCATION_MAX_NAME_LENGTH, L"%ls", MapDataList[i].MapName);

            break;
        }
    }
}

void
ReadZoneAndMapNameCustom(location *Location, wchar_t *nameZone, wchar_t *nameMap) {
    // Clear the strings
    nameZone[0] = L'\0';
    nameMap[0] = L'\0';

    u8 ZoneNumber = Location->ZoneNumber;
    u8 MapNumber = Location->MapNumber;

    int counter = _countof(MapDataList);

    for (int i = 0; i < counter; i++) {
        if (MapDataList[i].ZoneNumber == ZoneNumber &&
                MapDataList[i].MapNumber == MapNumber) {
            swprintf_s(nameZone, LOCATION_MAX_NAME_LENGTH, L"%s", MapDataList[i].ZoneName);
            swprintf_s(nameMap, LOCATION_MAX_NAME_LENGTH, L"%s", MapDataList[i].MapName);

            break;
        }
    }
}

void
WriteLocation() {
    u8 ZoneNumber = LocationCur.ZoneNumber;
    u8 MapNumber = LocationCur.MapNumber;

    FILE *fpLocation = _wfopen(L"game_data/map/location.txt", L"w");
    FILE *fpLocationDebug = _wfopen(L"game_data/map/location_debug.txt", L"w");

    fwprintf(fpLocation, L"%s, %s\n", nameZone, nameMap);
    fwprintf(fpLocationDebug, L"%i,%i,%s,%s\n", ZoneNumber, MapNumber, nameZone,
            nameMap);

    fclose(fpLocation);
    fclose(fpLocationDebug);
}

void
PrintLocation() {
    u8 ZoneNumber = LocationCur.ZoneNumber;
    u8 MapNumber = LocationCur.MapNumber;

    swprintf_s(szBuffer, _countof(szBuffer), L"\n\nLOCATION:\n");
    WriteToBackBuffer();

    swprintf_s(szBuffer, _countof(szBuffer), L"%s, %s ( Zone %i, Map %i )\n",
            nameZone, nameMap, ZoneNumber, MapNumber);
    WriteToBackBuffer();
}

BOOL
IsThisTheLastBossMap() {
    if ((LocationCur.ZoneNumber == 27) && (LocationCur.MapNumber == 1)) {
        return TRUE;
    }
    return FALSE;
}

#endif

