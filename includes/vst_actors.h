#ifndef _VST_ACTORS_H
#define _VST_ACTORS_H

#define OFFSET_ACTOR_DATA_POINTERS 0x800F1928
#define OFFSET_ACTOR_DATA_FIRST_NODE 0x8011f9f0
#define MAX_ACTORS_NUMBER 15
#define ACTORS_NAMES_LIST_LENGTH 108

char *ActorsNamesList[ACTORS_NAMES_LIST_LENGTH] = { //
  "Air Elemental", //
  "Arch Dragon", //
  "Ashley Riot", //
  "Asura", //
  "Bandit", //
  "Basilisk", //
  "Bat", //
  "Bejart", //
  "Blood Lizard", //
  "Callo Merlose", //
  "City Gaurd", //
  "Crimson Blade", //
  "Damascus Crab", //
  "Damascus Golem", //
  "Dao", //
  "Dark Crusader", //
  "Dark Dragon", //
  "Dark Elemental", //
  "Dark Skeleton", //
  "Dark Eye", //
  "Dead Crimson Blade", //
  "Death", //
  "Djinn", //
  "Dragon", //
  "Dragon Zombie", //
  "Duane", //
  "Duke Bardorba", //
  "Dullahan", //
  "Dummy", //
  "Earth Dragon", //
  "Earth Elemental", //
  "Fire Elemental", //
  "Flame Dragon", //
  "Gargoyle", //
  "Ghast", //
  "Ghost", //
  "Ghoul", //
  "Giant Crab", //
  "Goblin", //
  "Goblin Leader", //
  "Golem", //
  "Goodwin", //
  "Gremlin", //
  "Grissom", //
  "Guildenstern", //
  "Harpy", //
  "Hellhound", //
  "Ichthious", //
  "Ifrit", //
  "Imp", //
  "Iron Crab", //
  "Iron Golem", //
  "John Hardin", //
  "Joshua Bardorba", //
  "Kali", //
  "Last Crusader", //
  "Lich", //
  "Lich Lord", //
  "Lizardman", //
  "Lord Joshua", //
  "Mandel", //
  "Marco Riot", //
  "Marid", //
  "Matrix Ashley", //
  "Matrix Merlose", //
  "Mimic", //
  "Minotaur", //
  "Minotaur Lord", //
  "Minotaur Zombie", //
  "Mullenkamp Soldier", // change 'ü' to 'u'?
  "Mummy", //
  "Neesa", //
  "Nightmare", //
  "Nightstalker", //
  "Ogre", //
  "Ogre Lord", //
  "Ogre Zombie", //
  "Orc", //
  "Orc Leader", //
  "Poison Slime", //
  "Quicksilver", //
  "Ravana", //
  "Rosencrantz", //
  "Sackheim", //
  "Samantha", //
  "Sarjik", //
  "Shadow", //
  "Shrieker", //
  "Silver Wolf", //
  "Skeleton", //
  "Skeleton Knight", //
  "Sky Dragon", //
  "Slime", //
  "Snow Dragon", //
  "Stirge", //
  "Sydney Losstarot", // probably not used in this form (look below)
  "Sydney", //
  "Tia Riot", //
  "Tieger", //
  "Water Elemental", //
  "Wraith", //
  "Wyvern", //
  "Wyvern Knight", //
  "Wyvern Queen", //
  "Zombie", //
  "Zombie Fighter", //
  "Zombie Knight", //
  "Zombie Mage"
};

void
ReadActorPointer(u32 *ActorPointer, usize ActorNumber)
{
  usize BytesToRead = sizeof(u32);

  ReadGameMemory(processID,
      OFFSET_ACTOR_DATA_POINTERS + (ActorNumber * sizeof(u32)), BytesToRead,
      ActorPointer);
}

void
ReadActorData(actor_data *ActorData, u32 ActorPointer)
{
  usize BytesToRead = sizeof(actor_data);

  ReadGameMemory(processID, (usize) ActorPointer, BytesToRead, ActorData);
}

void
ReadNextActorPointer(u32 *ActorPointerCur, u32 *ActorPointerNext)
{
  actor_data ActorDataTemp;
  ReadActorData(&ActorDataTemp, *ActorPointerCur);
  *ActorPointerNext = ActorDataTemp.NextActorPtr;
}

BOOL
IsActorNameValid(char *ActorName)
{
  for (int i = 0; i < ACTORS_NAMES_LIST_LENGTH; i++)
  {

    if (strcmp(ActorName, ActorsNamesList[i]) == 0)
    {
      return TRUE;
    }
  }
  return FALSE;
}

void
PrintActorsDataOld()
{
  sprintf(szBuffer, "\nACTIVE ACTORS:\n");
  WriteToBackBuffer();

  actor_data ActorData;
  u32 ActorPointer = 0;
  u32 ActiveActorMarker = 0;

  // ReadActiveActorMarker(OFFSET_ACTIVE_ACTOR_MARKER, &ActiveActorMarker);
  // sprintf(szBuffer, "ActiveActorMarker: 0x%x\n", ActiveActorMarker);
  // WriteToBackBuffer();

  for (int i = 2; i < MAX_ACTORS_NUMBER; i++)
  {
    ReadActorPointer(&ActorPointer, i);
    if (ActorPointer)
    {
      ReadActorData(&ActorData, ActorPointer);

      // u32 NameOffset = ActorPointer + (u32) offsetof(actor_data, Name);
      ReadActorName(ActorData.NamePointer);

      if (IsActorNameValid(ActorName))
      {
        u16 HPCur = ActorData.HPCur;
        u16 HPMax = ActorData.HPMax;
        u16 MPCur = ActorData.MPCur;
        u16 MPMax = ActorData.MPMax;

        if (GameStatus == GAME_STATUS_CUTSCENE && HPMax == 100 &&
            MPMax == 100) // cutscene
        {
          return;
        }

        if (HPCur == 0)
        {
          continue;
        }

        sprintf(szBuffer, "%s -- ", ActorName);
        WriteToBackBuffer();

        sprintf(szBuffer, "HP %d/%d ", HPCur, HPMax);
        WriteToBackBuffer();

        if (MPMax > 0)
        {
          sprintf(szBuffer, "MP %d/%d ", MPCur, MPMax);
        }

        sprintf(szBuffer, "ADDR 0x%x ", ActorPointer);
        WriteToBackBuffer();

        sprintf(szBuffer, "\n");
        WriteToBackBuffer();
      }
    }
  }
}

void
PrintActorsData()
{
  sprintf(szBuffer, "\nACTIVE ACTORS:\n");
  WriteToBackBuffer();

  actor_data ActorData;
  u32 ActorPointerCur = OFFSET_ACTOR_DATA_POINTERS;
  u32 ActorPointerNext = 0x000000;

  // sprintf(szBuffer, "ADDR 0x%x\n", ActorPointerCur);
  // WriteToBackBuffer();

  ReadNextActorPointer(&ActorPointerCur, &ActorPointerNext);
  while (ActorPointerNext)
  {
    ReadActorData(&ActorData, ActorPointerNext);

    ReadActorName(ActorData.NamePointer);

    u16 HPCur = ActorData.HPCur;
    u16 HPMax = ActorData.HPMax;
    u16 MPCur = ActorData.MPCur;
    u16 MPMax = ActorData.MPMax;

    if (GameStatus == GAME_STATUS_CUTSCENE && HPMax == 100 &&
        MPMax == 100) // cutscene
    {
      return;
    }

    sprintf(szBuffer, "0x%x -- ", ActorPointerNext);
    WriteToBackBuffer();

    sprintf(szBuffer, "%s -- ", ActorName);
    WriteToBackBuffer();

    if (HPCur == 0)
    {
      sprintf(szBuffer, "Dead ");
      WriteToBackBuffer();
    }
    else
    {
      sprintf(szBuffer, "HP %d/%d ", HPCur, HPMax);
      WriteToBackBuffer();

      if (MPMax > 0)
      {
        sprintf(szBuffer, "MP %d/%d ", MPCur, MPMax);
        WriteToBackBuffer();
      }
    }
    sprintf(szBuffer, "\n");
    WriteToBackBuffer();

    ActorPointerCur = ActorPointerNext;
    ReadNextActorPointer(&ActorPointerCur, &ActorPointerNext);
  }
}

void
WriteActorsData()
{
  FILE *fpActorsData = fopen("game_data/map/enemy_data.txt", "w");

  fprintf(fpActorsData, "Active Enemies\n");

  actor_data ActorData;
  // Use this one if you want to include player data:
  // u32 ActorPointerCur = OFFSET_ACTOR_DATA_POINTERS;
  u32 ActorPointerCur = OFFSET_ACTOR_DATA_FIRST_NODE;
  u32 ActorPointerNext = 0x000000;

  // sprintf(fpActorsData, "ADDR 0x%x\n", ActorPointerCur);
  // WriteToBackBuffer();

  ReadNextActorPointer(&ActorPointerCur, &ActorPointerNext);
  while (ActorPointerNext)
  {
    ReadActorData(&ActorData, ActorPointerNext);

    ReadActorName(ActorData.NamePointer);

    u16 HPCur = ActorData.HPCur;
    u16 HPMax = ActorData.HPMax;
    u16 MPCur = ActorData.MPCur;
    u16 MPMax = ActorData.MPMax;

    if (GameStatus == GAME_STATUS_CUTSCENE && HPMax == 100 &&
        MPMax == 100) // cutscene
    {
      return;
    }

    // fprintf(fpActorsData, "0x%x -- ", ActorPointerNext);

    fprintf(fpActorsData, "%s -- ", ActorName);

    if (HPCur == 0)
    {
      fprintf(fpActorsData, "Dead ");
    }
    else
    {
      fprintf(fpActorsData, "HP %d/%d ", HPCur, HPMax);

      if (MPMax > 0)
      {
        fprintf(fpActorsData, "MP %d/%d ", MPCur, MPMax);
      }
    }
    fprintf(fpActorsData, "\n");

    ActorPointerCur = ActorPointerNext;
    ReadNextActorPointer(&ActorPointerCur, &ActorPointerNext);
  }

  fclose(fpActorsData);
}

#endif

