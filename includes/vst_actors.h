#ifndef _VST_ACTORS_H
#define _VST_ACTORS_H

#define OFFSET_ACTOR_DATA_POINTERS 0xf1928
#define OFFSET_ACTOR_DATA_FIRST_NODE 0x11f9f0
#define MAX_ACTORS_NUMBER 15
#define ACTORS_NAMES_LIST_LENGTH 108

wchar_t *ActorsNamesList[ACTORS_NAMES_LIST_LENGTH] = { //
    L"Air Elemental", //
    L"Arch Dragon", //
    L"Ashley Riot", //
    L"Asura", //
    L"Bandit", //
    L"Basilisk", //
    L"Bat", //
    L"Bejart", //
    L"Blood Lizard", //
    L"Callo Merlose", //
    L"City Gaurd", //
    L"Crimson Blade", //
    L"Damascus Crab", //
    L"Damascus Golem", //
    L"Dao", //
    L"Dark Crusader", //
    L"Dark Dragon", //
    L"Dark Elemental", //
    L"Dark Skeleton", //
    L"Dark Eye", //
    L"Dead Crimson Blade", //
    L"Death", //
    L"Djinn", //
    L"Dragon", //
    L"Dragon Zombie", //
    L"Duane", //
    L"Duke Bardorba", //
    L"Dullahan", //
    L"Dummy", //
    L"Earth Dragon", //
    L"Earth Elemental", //
    L"Fire Elemental", //
    L"Flame Dragon", //
    L"Gargoyle", //
    L"Ghast", //
    L"Ghost", //
    L"Ghoul", //
    L"Giant Crab", //
    L"Goblin", //
    L"Goblin Leader", //
    L"Golem", //
    L"Goodwin", //
    L"Gremlin", //
    L"Grissom", //
    L"Guildenstern", //
    L"Harpy", //
    L"Hellhound", //
    L"Ichthious", //
    L"Ifrit", //
    L"Imp", //
    L"Iron Crab", //
    L"Iron Golem", //
    L"John Hardin", //
    L"Joshua Bardorba", //
    L"Kali", //
    L"Last Crusader", //
    L"Lich", //
    L"Lich Lord", //
    L"Lizardman", //
    L"Lord Joshua", //
    L"Mandel", //
    L"Marco Riot", //
    L"Marid", //
    L"Matrix Ashley", //
    L"Matrix Merlose", //
    L"Mimic", //
    L"Minotaur", //
    L"Minotaur Lord", //
    L"Minotaur Zombie", //
    L"Müllenkamp Soldier", // change 'ü' to 'u'?
                           //L"Mullenkamp Soldier", // change 'ü' to 'u'?
    L"Mummy", //
    L"Neesa", //
    L"Nightmare", //
    L"Nightstalker", //
    L"Ogre", //
    L"Ogre Lord", //
    L"Ogre Zombie", //
    L"Orc", //
    L"Orc Leader", //
    L"Poison Slime", //
    L"Quicksilver", //
    L"Ravana", //
    L"Rosencrantz", //
    L"Sackheim", //
    L"Samantha", //
    L"Sarjik", //
    L"Shadow", //
    L"Shrieker", //
    L"Silver Wolf", //
    L"Skeleton", //
    L"Skeleton Knight", //
    L"Sky Dragon", //
    L"Slime", //
    L"Snow Dragon", //
    L"Stirge", //
    L"Sydney Losstarot", // probably not used in this form (look below)
    L"Sydney", //
    L"Tia Riot", //
    L"Tieger", //
    L"Water Elemental", //
    L"Wraith", //
    L"Wyvern", //
    L"Wyvern Knight", //
    L"Wyvern Queen", //
    L"Zombie", //
    L"Zombie Fighter", //
    L"Zombie Knight", //
    L"Zombie Mage"
};

void
ReadActorPointer(u32 *ActorPointer, usize ActorNumber) {
    usize BytesToRead = sizeof(u32);

    ReadGameMemory(processID,
            OFFSET_ACTOR_DATA_POINTERS + (ActorNumber * sizeof(u32)), BytesToRead,
            ActorPointer);
}

void
ReadActorData(actor_data *ActorData, u32 ActorPointer) {
    usize BytesToRead = sizeof(actor_data);

    ReadGameMemory(processID, (usize) ActorPointer, BytesToRead, ActorData);
}

void
ReadNextActorPointer(u32 *ActorPointerCur, u32 *ActorPointerNext) {
    actor_data ActorDataTemp;
    ReadActorData(&ActorDataTemp, *ActorPointerCur);
    *ActorPointerNext = ActorDataTemp.NextActorPtr;
}

BOOL
IsActorNameValid(wchar_t *ActorName) {
    for (int i = 0; i < ACTORS_NAMES_LIST_LENGTH; i++) {
        if (wcscmp(ActorName, ActorsNamesList[i]) == 0) {
            return TRUE;
        }
    }
    return FALSE;
}

void
PrintActorsDataOld() {
    swprintf_s(szBuffer, _countof(szBuffer), L"\nACTIVE ACTORS:\n");
    WriteToBackBuffer();

    actor_data ActorData;
    u32 ActorPointer = 0;
    u32 ActiveActorMarker = 0;

    // ReadActiveActorMarker(OFFSET_ACTIVE_ACTOR_MARKER, &ActiveActorMarker);
    // swprintf_s(szBuffer, _countof(szBuffer), L"ActiveActorMarker: 0x%x\n", ActiveActorMarker);
    // WriteToBackBuffer();

    for (int i = 2; i < MAX_ACTORS_NUMBER; i++) {
        ReadActorPointer(&ActorPointer, i);
        if (ActorPointer) {
            ReadActorData(&ActorData, ActorPointer);

            // u32 NameOffset = ActorPointer + (u32) offsetof(actor_data, Name);
            ReadActorName(ActorData.NamePointer);

            if (IsActorNameValid(ActorName)) {
                u16 HPCur = ActorData.HPCur;
                u16 HPMax = ActorData.HPMax;
                u16 MPCur = ActorData.MPCur;
                u16 MPMax = ActorData.MPMax;

                if (GameStatus == GAME_STATUS_CUTSCENE && HPMax == 100 &&
                        MPMax == 100) { // cutscene
                    return;
                }

                if (HPCur == 0) continue;

                swprintf_s(szBuffer, _countof(szBuffer), L"%s -- ", ActorName);
                WriteToBackBuffer();

                swprintf_s(szBuffer, _countof(szBuffer), L"HP %d/%d ", HPCur, HPMax);
                WriteToBackBuffer();

                if (MPMax > 0) {
                    swprintf_s(szBuffer, _countof(szBuffer), L"MP %d/%d ", MPCur, MPMax);
                }

                swprintf_s(szBuffer, _countof(szBuffer), L"ADDR 0x%x ", ActorPointer);
                WriteToBackBuffer();

                swprintf_s(szBuffer, _countof(szBuffer), L"\n");
                WriteToBackBuffer();
            }
        }
    }
}

void
PrintActorsData() {
    swprintf_s(szBuffer, _countof(szBuffer), L"\nACTIVE ACTORS:\n");
    WriteToBackBuffer();

    actor_data ActorData;
    u32 ActorPointerCur = OFFSET_ACTOR_DATA_POINTERS;
    u32 ActorPointerNext = 0x000000;

    // swprintf_s(szBuffer, _countof(szBuffer), L"ADDR 0x%x\n", ActorPointerCur);
    // WriteToBackBuffer();

    ReadNextActorPointer(&ActorPointerCur, &ActorPointerNext);
    while (ActorPointerNext) {
        ReadActorData(&ActorData, ActorPointerNext);

        ReadActorName(ActorData.NamePointer);

        u16 HPCur = ActorData.HPCur;
        u16 HPMax = ActorData.HPMax;
        u16 MPCur = ActorData.MPCur;
        u16 MPMax = ActorData.MPMax;

        if (GameStatus == GAME_STATUS_CUTSCENE && HPMax == 100 &&
                MPMax == 100) { // cutscene
            return;
        }

        swprintf_s(szBuffer, _countof(szBuffer), L"0x%x -- ", ActorPointerNext);
        WriteToBackBuffer();

        swprintf_s(szBuffer, _countof(szBuffer), L"%s -- ", ActorName);
        WriteToBackBuffer();

        if (HPCur == 0) {
            swprintf_s(szBuffer, _countof(szBuffer), L"Dead ");
            WriteToBackBuffer();
        } else {
            swprintf_s(szBuffer, _countof(szBuffer), L"HP %d/%d ", HPCur, HPMax);
            WriteToBackBuffer();

            if (MPMax > 0) {
                swprintf_s(szBuffer, _countof(szBuffer), L"MP %d/%d ", MPCur, MPMax);
                WriteToBackBuffer();
            }
        }
        swprintf_s(szBuffer, _countof(szBuffer), L"\n");
        WriteToBackBuffer();

        ActorPointerCur = ActorPointerNext;
        ReadNextActorPointer(&ActorPointerCur, &ActorPointerNext);
    }
}

void
WriteActorsData() {
    FILE *fpActorsData = _wfopen(L"game_data/map/enemy_data.txt", L"w");

    fwprintf(fpActorsData, L"Active Enemies\n");

    actor_data ActorData;
    // Use this one if you want to include player data:
    // u32 ActorPointerCur = OFFSET_ACTOR_DATA_POINTERS;
    u32 ActorPointerCur = OFFSET_ACTOR_DATA_FIRST_NODE;
    u32 ActorPointerNext = 0x000000;

    // swprintf_s(fpActorsData, _countof(szBuffer), L"ADDR 0x%x\n", ActorPointerCur);
    // WriteToBackBuffer();

    ReadNextActorPointer(&ActorPointerCur, &ActorPointerNext);
    while (ActorPointerNext) {
        ReadActorData(&ActorData, ActorPointerNext);

        ReadActorName(ActorData.NamePointer);

        u16 HPCur = ActorData.HPCur;
        u16 HPMax = ActorData.HPMax;
        u16 MPCur = ActorData.MPCur;
        u16 MPMax = ActorData.MPMax;

        if (GameStatus == GAME_STATUS_CUTSCENE && HPMax == 100 &&
                MPMax == 100) { // cutscene
            return;
        }

        // fwprintf(fpActorsData, L"0x%x -- ", ActorPointerNext);

        fwprintf(fpActorsData, L"%s -- ", ActorName);

        if (HPCur == 0) {
            fwprintf(fpActorsData, L"Dead ");
        } else {
            fwprintf(fpActorsData, L"HP %d/%d ", HPCur, HPMax);

            if (MPMax > 0) {
                fwprintf(fpActorsData, L"MP %d/%d ", MPCur, MPMax);
            }
        }
        fwprintf(fpActorsData, L"\n");

        ActorPointerCur = ActorPointerNext;
        ReadNextActorPointer(&ActorPointerCur, &ActorPointerNext);
    }

    fclose(fpActorsData);
}

#endif

