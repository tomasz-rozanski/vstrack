#ifndef _VST_GAZETTE_H
#define _VST_GAZETTE_H

// Basic info
// 52 treasure chests
// 361 locations (last boss battle counts as 2 extra locations)

#define OFFSET_GAZETTE_KILL_LIST_HUMAN 0x05fea4
#define OFFSET_GAZETTE_KILL_LIST_BEAST 0x05fea6
#define OFFSET_GAZETTE_KILL_LIST_UNDEAD 0x05fea8
#define OFFSET_GAZETTE_KILL_LIST_PHANTOM 0x05feaa
#define OFFSET_GAZETTE_KILL_LIST_DRAGON 0x05feac
#define OFFSET_GAZETTE_KILL_LIST_EVIL 0x05feae

#define OFFSET_GAZETTE_WEAPON_USAGE_UNARMED 0x05feb4
#define OFFSET_GAZETTE_WEAPON_USAGE_DAGGER 0x05feb6
#define OFFSET_GAZETTE_WEAPON_USAGE_SWORD 0x05feb8
#define OFFSET_GAZETTE_WEAPON_USAGE_GREATSWORD 0x05feba
#define OFFSET_GAZETTE_WEAPON_USAGE_AXEMACE 0x05febc
#define OFFSET_GAZETTE_WEAPON_USAGE_GREATAXE 0x05febe
#define OFFSET_GAZETTE_WEAPON_USAGE_STAFF 0x05fec0
#define OFFSET_GAZETTE_WEAPON_USAGE_HEAVYMACE 0x05fec2
#define OFFSET_GAZETTE_WEAPON_USAGE_POLEARM 0x05fec4
#define OFFSET_GAZETTE_WEAPON_USAGE_CROSSBOW 0x05fec6

#define OFFSET_GAZETTE_CHEST_COUNT_CURRENT 0x05ff38
#define OFFSET_GAZETTE_MAP_COUNT_CURRENT 0x10a46a

#define OFFSET_GAZETTE_CHEST_COUNT_FLAGS 0x061958
#define OFFSET_GAZETTE_MAP_COUNT_FLAGS 0x05ffd8

#define OFFSET_GAZETTE_MAP_COUNT_CHECK_FLAGS 0x0e8508

// This is used to generate list of missing treasure chests
chest_flag_check ChestFlagChecklist[CHEST_COUNT_MAX] = { //
    { 1, 11, 0 }, { 2, 12, 0 }, { 3, 15, 3 }, { 4, 25, 0 }, //
    { 5, 40, 24 }, { 11, 51, 8 }, { 12, 9, 9 }, { 13, 53, 22 }, //
    { 14, 53, 15 }, { 15, 50, 14 }, { 16, 13, 5 }, { 17, 13, 9 }, //
    { 18, 13, 4 }, { 19, 40, 23 }, { 20, 9, 16 }, { 21, 24, 0 }, //
    { 22, 53, 25 }, { 23, 53, 5 }, { 24, 53, 20 }, { 25, 55, 20 }, //
    { 26, 55, 21 }, { 27, 55, 19 }, { 28, 56, 15 }, { 29, 56, 17 }, //
    { 30, 56, 25 }, { 31, 12, 1 }, { 32, 36, 0 }, { 33, 51, 22 }, //
    { 34, 51, 11 }, { 38, 38, 0 }, { 39, 24, 2 }, { 40, 50, 1 }, //
    { 42, 50, 16 }, { 45, 54, 4 }, { 46, 52, 1 }, { 47, 9, 17 }, //
    { 48, 48, 7 }, { 49, 49, 12 }, { 50, 41, 2 }, { 51, 51, 5 }, //
    { 52, 54, 2 }, { 53, 48, 20 }, { 54, 49, 8 }, { 55, 49, 7 }, //
    { 56, 55, 22 }, { 57, 30, 3 }, { 58, 48, 21 }, { 59, 50, 10 }, //
    { 60, 37, 0 }, { 61, 56, 23 }, { 62, 52, 7 }, { 63, 29, 0 }
};

// This is used to generate list of missing locations
map_flag_check MapFlagChecklist[MAP_COUNT_MAX] = { //
    { 1, 1, 9, 0 }, { 1, 2, 9, 1 }, { 1, 3, 9, 2 }, //
    { 1, 4, 9, 3 }, { 1, 5, 9, 4 }, { 1, 6, 9, 5 }, //
    { 1, 7, 9, 6 }, { 2, 0, 9, 7 }, { 2, 1, 9, 8 }, //
    { 2, 2, 9, 9 }, { 2, 3, 9, 10 }, { 2, 4, 9, 11 }, //
    { 2, 5, 9, 12 }, { 3, 0, 9, 15 }, { 3, 1, 11, 0 }, //
    { 3, 2, 12, 0 }, { 3, 3, 9, 16 }, { 3, 4, 13, 0 }, //
    { 3, 5, 13, 1 }, { 3, 6, 13, 2 }, { 3, 7, 13, 3 }, //
    { 4, 0, 13, 4 }, { 4, 1, 13, 5 }, { 4, 2, 13, 6 }, //
    { 4, 4, 13, 8 }, { 4, 5, 13, 9 }, { 4, 6, 13, 10 }, //
    { 4, 7, 13, 11 }, { 5, 0, 13, 12 }, { 5, 1, 13, 13 }, //
    { 5, 2, 13, 14 }, { 5, 3, 13, 15 }, { 5, 4, 13, 16 }, //
    { 5, 6, 14, 0 }, { 5, 7, 15, 0 }, { 6, 0, 15, 1 }, //
    { 6, 1, 15, 2 }, { 6, 2, 15, 3 }, { 6, 3, 15, 4 }, //
    { 6, 4, 15, 5 }, { 6, 5, 15, 6 }, { 6, 7, 15, 8 }, //
    { 7, 1, 15, 10 }, { 7, 2, 15, 11 }, { 7, 3, 15, 12 }, //
    { 7, 4, 16, 0 }, { 7, 5, 17, 0 }, { 7, 7, 22, 0 }, //
    { 8, 3, 22, 4 }, { 8, 5, 22, 6 }, { 8, 6, 22, 7 }, //
    { 8, 7, 22, 8 }, { 9, 0, 22, 9 }, { 9, 2, 23, 1 }, //
    { 9, 3, 23, 2 }, { 9, 4, 23, 3 }, { 9, 5, 23, 4 }, //
    { 9, 6, 23, 5 }, { 9, 7, 24, 0 }, { 10, 0, 24, 1 }, //
    { 10, 1, 24, 2 }, { 10, 2, 24, 3 }, { 10, 3, 24, 4 }, //
    { 10, 4, 24, 5 }, { 10, 5, 24, 6 }, { 10, 6, 24, 7 }, //
    { 10, 7, 24, 8 }, { 11, 0, 24, 9 }, { 11, 1, 24, 10 }, //
    { 11, 2, 24, 11 }, { 11, 3, 24, 12 }, { 11, 4, 24, 13 }, //
    { 11, 5, 24, 14 }, { 11, 6, 24, 15 }, { 11, 7, 25, 0 }, //
    { 12, 0, 25, 1 }, { 12, 1, 25, 2 }, { 12, 2, 25, 3 }, //
    { 12, 3, 25, 4 }, { 12, 5, 27, 0 }, { 12, 6, 27, 1 }, //
    { 13, 1, 28, 0 }, { 13, 2, 28, 1 }, { 13, 3, 28, 2 }, //
    { 13, 4, 28, 3 }, { 13, 5, 28, 4 }, { 13, 6, 28, 5 }, //
    { 13, 7, 28, 6 }, { 14, 0, 28, 7 }, { 14, 1, 28, 8 }, //
    { 14, 2, 28, 9 }, { 14, 3, 28, 10 }, { 14, 4, 28, 11 }, //
    { 14, 5, 28, 12 }, { 14, 6, 28, 13 }, { 14, 7, 28, 14 }, //
    { 15, 0, 28, 15 }, { 15, 1, 28, 16 }, { 15, 2, 28, 17 }, //
    { 15, 3, 28, 18 }, { 15, 4, 29, 0 }, { 15, 6, 29, 2 }, //
    { 15, 7, 29, 3 }, { 16, 0, 29, 4 }, { 16, 1, 29, 5 }, //
    { 16, 2, 29, 6 }, { 17, 3, 30, 0 }, { 17, 4, 30, 1 }, //
    { 17, 5, 30, 2 }, { 17, 6, 30, 3 }, { 17, 7, 30, 4 }, //
    { 18, 0, 30, 5 }, { 18, 1, 31, 0 }, { 18, 2, 31, 1 }, //
    { 18, 3, 32, 1 }, { 18, 4, 32, 1 }, { 18, 5, 32, 2 }, //
    { 18, 6, 32, 3 }, { 18, 7, 32, 4 }, { 19, 0, 32, 5 }, //
    { 19, 1, 32, 6 }, { 19, 2, 32, 7 }, { 19, 3, 32, 8 }, //
    { 19, 4, 32, 9 }, { 19, 5, 32, 10 }, { 19, 6, 32, 11 }, //
    { 19, 7, 32, 12 }, { 20, 0, 32, 13 }, { 20, 2, 32, 15 }, //
    { 20, 3, 32, 16 }, { 20, 4, 32, 17 }, { 20, 5, 32, 18 }, //
    { 20, 6, 32, 19 }, { 21, 3, 39, 0 }, { 21, 5, 34, 0 }, //
    { 21, 6, 35, 0 }, { 21, 7, 36, 0 }, { 22, 0, 37, 0 }, //
    { 22, 1, 38, 0 }, { 22, 3, 40, 0 }, { 22, 4, 40, 1 }, //
    { 22, 5, 40, 2 }, { 22, 6, 40, 3 }, { 22, 7, 40, 4 }, //
    { 23, 0, 40, 5 }, { 23, 1, 40, 6 }, { 23, 2, 40, 7 }, //
    { 23, 3, 40, 8 }, { 23, 4, 40, 9 }, { 23, 5, 40, 10 }, //
    { 23, 6, 40, 11 }, { 23, 7, 40, 12 }, { 24, 0, 40, 13 }, //
    { 24, 1, 40, 14 }, { 24, 2, 40, 15 }, { 24, 3, 40, 16 }, //
    { 24, 4, 40, 17 }, { 24, 5, 40, 18 }, { 24, 6, 40, 19 }, //
    { 24, 7, 40, 20 }, { 25, 0, 40, 21 }, { 25, 1, 40, 22 }, //
    { 25, 2, 40, 23 }, { 25, 3, 40, 24 }, { 25, 4, 40, 25 }, //
    { 25, 5, 42, 0 }, { 25, 6, 43, 0 }, { 25, 7, 44, 0 }, //
    { 26, 0, 45, 0 }, { 26, 1, 46, 0 }, { 26, 2, 47, 0 }, //
    { 27, 4, 48, 0 }, { 27, 5, 48, 1 }, { 27, 6, 48, 2 }, //
    { 27, 7, 48, 3 }, { 28, 0, 48, 4 }, { 28, 1, 48, 5 }, //
    { 28, 2, 48, 6 }, { 28, 3, 48, 7 }, { 28, 4, 48, 8 }, //
    { 28, 5, 48, 9 }, { 28, 6, 48, 10 }, { 28, 7, 48, 11 }, //
    { 29, 0, 48, 12 }, { 29, 1, 48, 13 }, { 29, 2, 48, 14 }, //
    { 29, 3, 48, 15 }, { 29, 4, 48, 16 }, { 29, 5, 48, 17 }, //
    { 29, 6, 48, 18 }, { 29, 7, 48, 19 }, { 30, 0, 48, 20 }, //
    { 30, 1, 48, 21 }, { 30, 2, 48, 22 }, { 30, 3, 48, 23 }, //
    { 30, 4, 48, 24 }, { 30, 5, 48, 25 }, { 30, 6, 48, 26 }, //
    { 30, 7, 49, 0 }, { 31, 0, 49, 1 }, { 31, 1, 49, 2 }, //
    { 31, 2, 49, 3 }, { 31, 3, 49, 4 }, { 31, 4, 49, 5 }, //
    { 31, 5, 49, 6 }, { 31, 6, 49, 7 }, { 31, 7, 49, 8 }, //
    { 32, 0, 49, 9 }, { 32, 1, 49, 10 }, { 32, 2, 49, 11 }, //
    { 32, 3, 49, 12 }, { 32, 4, 50, 0 }, { 32, 5, 50, 1 }, //
    { 32, 6, 50, 2 }, { 32, 7, 50, 3 }, { 33, 0, 50, 4 }, //
    { 33, 1, 50, 5 }, { 33, 2, 50, 6 }, { 33, 3, 50, 7 }, //
    { 33, 4, 50, 8 }, { 33, 5, 50, 9 }, { 33, 6, 50, 10 }, //
    { 33, 7, 50, 11 }, { 34, 0, 50, 12 }, { 34, 1, 50, 13 }, //
    { 34, 2, 50, 14 }, { 34, 3, 50, 15 }, { 34, 4, 50, 16 }, //
    { 34, 5, 50, 17 }, { 34, 6, 50, 18 }, { 34, 7, 50, 19 }, //
    { 35, 0, 50, 20 }, { 35, 1, 50, 21 }, { 35, 2, 50, 22 }, //
    { 35, 3, 50, 23 }, { 35, 4, 51, 0 }, { 35, 5, 51, 1 }, //
    { 35, 6, 51, 2 }, { 35, 7, 51, 3 }, { 36, 0, 51, 4 }, //
    { 36, 1, 51, 5 }, { 36, 2, 51, 6 }, { 36, 3, 51, 7 }, //
    { 36, 4, 51, 8 }, { 36, 5, 51, 9 }, { 36, 6, 51, 10 }, //
    { 36, 7, 51, 11 }, { 37, 0, 51, 12 }, { 37, 1, 51, 13 }, //
    { 37, 2, 51, 14 }, { 37, 3, 51, 15 }, { 37, 4, 51, 16 }, //
    { 37, 5, 51, 17 }, { 37, 6, 51, 18 }, { 37, 7, 51, 19 }, //
    { 38, 0, 51, 20 }, { 38, 1, 51, 21 }, { 38, 2, 51, 22 }, //
    { 38, 3, 51, 23 }, { 38, 4, 51, 24 }, { 38, 5, 51, 25 }, //
    { 38, 6, 51, 26 }, { 38, 7, 53, 0 }, { 39, 0, 53, 1 }, //
    { 39, 1, 53, 2 }, { 39, 2, 53, 3 }, { 39, 3, 53, 4 }, //
    { 39, 4, 53, 5 }, { 39, 5, 53, 6 }, { 39, 6, 53, 7 }, //
    { 39, 7, 53, 8 }, { 40, 0, 53, 9 }, { 40, 1, 53, 10 }, //
    { 40, 2, 53, 11 }, { 40, 3, 53, 12 }, { 40, 4, 53, 13 }, //
    { 40, 5, 53, 14 }, { 40, 6, 53, 15 }, { 40, 7, 53, 16 }, //
    { 41, 0, 53, 17 }, { 41, 1, 53, 18 }, { 41, 2, 53, 19 }, //
    { 41, 3, 53, 20 }, { 41, 4, 53, 21 }, { 41, 5, 53, 22 }, //
    { 41, 6, 53, 23 }, { 41, 7, 53, 24 }, { 42, 0, 53, 25 }, //
    { 42, 1, 53, 26 }, { 42, 2, 53, 27 }, { 42, 3, 53, 28 }, //
    { 42, 4, 53, 29 }, { 42, 6, 53, 31 }, { 42, 7, 54, 0 }, //
    { 43, 0, 54, 1 }, { 43, 1, 54, 2 }, { 43, 2, 54, 3 }, //
    { 43, 3, 54, 4 }, { 43, 4, 41, 0 }, { 43, 5, 41, 1 }, //
    { 43, 6, 41, 2 }, { 43, 7, 52, 0 }, { 44, 0, 52, 1 }, //
    { 44, 1, 52, 2 }, { 44, 2, 52, 3 }, { 44, 3, 52, 4 }, //
    { 44, 4, 52, 5 }, { 44, 5, 52, 6 }, { 44, 6, 52, 7 }, //
    { 44, 7, 55, 0 }, { 45, 0, 55, 1 }, { 45, 1, 55, 2 }, //
    { 45, 2, 55, 3 }, { 45, 3, 55, 4 }, { 45, 4, 55, 5 }, //
    { 45, 5, 55, 6 }, { 45, 6, 55, 7 }, { 45, 7, 55, 8 }, //
    { 46, 0, 55, 9 }, { 46, 1, 55, 10 }, { 46, 2, 55, 11 }, //
    { 46, 3, 55, 12 }, { 46, 4, 55, 13 }, { 46, 5, 55, 14 }, //
    { 46, 6, 55, 15 }, { 46, 7, 55, 16 }, { 47, 0, 55, 17 }, //
    { 47, 1, 55, 18 }, { 47, 2, 55, 19 }, { 47, 3, 55, 20 }, //
    { 47, 4, 55, 21 }, { 47, 5, 55, 22 }, { 47, 6, 56, 0 }, //
    { 47, 7, 56, 1 }, { 48, 0, 56, 2 }, { 48, 1, 56, 3 }, //
    { 48, 2, 56, 4 }, { 48, 3, 56, 5 }, { 48, 4, 56, 6 }, //
    { 48, 5, 56, 7 }, { 48, 6, 56, 8 }, { 48, 7, 56, 9 }, //
    { 49, 0, 56, 10 }, { 49, 1, 56, 11 }, { 49, 2, 56, 12 }, //
    { 49, 3, 56, 13 }, { 49, 4, 56, 14 }, { 49, 5, 56, 15 }, //
    { 49, 6, 56, 16 }, { 49, 7, 56, 17 }, { 50, 0, 56, 18 }, //
    { 50, 1, 56, 19 }, { 50, 2, 56, 20 }, { 50, 3, 56, 21 }, //
    { 50, 4, 56, 22 }, { 50, 5, 56, 23 }, { 50, 6, 56, 24 }, //
    { 50, 7, 56, 25 }, { 51, 1, 9, 17 }, { 51, 2, 51, 27 }, //
    { 51, 3, 51, 28 }
};

void
ReadKillList() {
    usize BytesToRead = sizeof(kill_list);
    usize BytesRead = ReadGameMemory(
            processID, OFFSET_GAZETTE_KILL_LIST_HUMAN, BytesToRead, &KillListCur);
}

void
PrintKillList() {
    swprintf_s(szBuffer, _countof(szBuffer), L"\nKILL LIST:\n");
    WriteToBackBuffer();
    swprintf_s(szBuffer, _countof(szBuffer), L"Human:   %5i\n", KillListCur.Human);
    WriteToBackBuffer();
    swprintf_s(szBuffer, _countof(szBuffer), L"Beast:   %5i\n", KillListCur.Beast);
    WriteToBackBuffer();
    swprintf_s(szBuffer, _countof(szBuffer), L"Undead:  %5i\n", KillListCur.Undead);
    WriteToBackBuffer();
    swprintf_s(
            szBuffer, _countof(szBuffer), L"Phantom: %5i\n", KillListCur.Phantom);
    WriteToBackBuffer();
    swprintf_s(szBuffer, _countof(szBuffer), L"Dragon:  %5i\n", KillListCur.Dragon);
    WriteToBackBuffer();
    swprintf_s(szBuffer, _countof(szBuffer), L"Evil:    %5i\n", KillListCur.Evil);
    WriteToBackBuffer();
}

BOOL
KillListChanged() {
    usize DataSize = sizeof(kill_list);

    BOOL Result =
        DataChanged((void *) &KillListPrev, (void *) &KillListCur, DataSize);

    return Result;
}

void
WriteKillList() { FILE *fpKillList = _wfopen(L"game_data/score/kill_list.txt", L"w");

    fwprintf(fpKillList, L"== KILL LIST ==\n\n");
    fwprintf(fpKillList, L"Human:   %5i\n", KillListCur.Human);
    fwprintf(fpKillList, L"Beast:   %5i\n", KillListCur.Beast);
    fwprintf(fpKillList, L"Undead:  %5i\n", KillListCur.Undead);
    fwprintf(fpKillList, L"Phantom: %5i\n", KillListCur.Phantom);
    fwprintf(fpKillList, L"Dragon:  %5i\n", KillListCur.Dragon);
    fwprintf(fpKillList, L"Evil:    %5i\n", KillListCur.Evil);

    fclose(fpKillList);
}

void
ReadWeaponUsage() {
    usize BytesToRead = sizeof(weapon_usage);
    usize BytesRead = ReadGameMemory(processID,
            OFFSET_GAZETTE_WEAPON_USAGE_UNARMED, BytesToRead, &WeaponUsageCur);
}

void
PrintWeaponUsage() {
    swprintf_s(szBuffer, _countof(szBuffer), L"\nWEAPON USAGE:\n");
    WriteToBackBuffer();
    swprintf_s(szBuffer, _countof(szBuffer), L"Dagger:      %5i\n",
            WeaponUsageCur.Dagger);
    WriteToBackBuffer();
    swprintf_s(
            szBuffer, _countof(szBuffer), L"Sword:       %5i\n", WeaponUsageCur.Sword);
    WriteToBackBuffer();
    swprintf_s(szBuffer, _countof(szBuffer), L"Great Sword: %5i\n",
            WeaponUsageCur.GreatSword);
    WriteToBackBuffer();
    swprintf_s(szBuffer, _countof(szBuffer), L"Axe/Mace:    %5i\n",
            WeaponUsageCur.AxeMace);
    WriteToBackBuffer();
    swprintf_s(szBuffer, _countof(szBuffer), L"Great Axe:   %5i\n",
            WeaponUsageCur.GreatAxe);
    WriteToBackBuffer();
    swprintf_s(
            szBuffer, _countof(szBuffer), L"Staff:       %5i\n", WeaponUsageCur.Staff);
    WriteToBackBuffer();
    swprintf_s(szBuffer, _countof(szBuffer), L"Heavy Mace:  %5i\n",
            WeaponUsageCur.HeavyMace);
    WriteToBackBuffer();
    swprintf_s(szBuffer, _countof(szBuffer), L"Polearm:     %5i\n",
            WeaponUsageCur.Polearm);
    WriteToBackBuffer();
    swprintf_s(szBuffer, _countof(szBuffer), L"Crossbow:    %5i\n",
            WeaponUsageCur.Crossbow);
    WriteToBackBuffer();
    swprintf_s(szBuffer, _countof(szBuffer), L"Unarmed:     %5i\n",
            WeaponUsageCur.Unarmed);
    WriteToBackBuffer();
}

void
WriteWeaponUsage() {
    FILE *fpWeaponUsage = _wfopen(L"game_data/score/weapon_usage.txt", L"w");

    fwprintf(fpWeaponUsage, L"== WEAPON USAGE ==\n\n");
    fwprintf(fpWeaponUsage, L"Dagger:      %5i\n", WeaponUsageCur.Dagger);
    fwprintf(fpWeaponUsage, L"Sword:       %5i\n", WeaponUsageCur.Sword);
    fwprintf(fpWeaponUsage, L"Great Sword: %5i\n", WeaponUsageCur.GreatSword);
    fwprintf(fpWeaponUsage, L"Axe/Mace:    %5i\n", WeaponUsageCur.AxeMace);
    fwprintf(fpWeaponUsage, L"Great Axe:   %5i\n", WeaponUsageCur.GreatAxe);
    fwprintf(fpWeaponUsage, L"Staff:       %5i\n", WeaponUsageCur.Staff);
    fwprintf(fpWeaponUsage, L"Heavy Mace:  %5i\n", WeaponUsageCur.HeavyMace);
    fwprintf(fpWeaponUsage, L"Polearm:     %5i\n", WeaponUsageCur.Polearm);
    fwprintf(fpWeaponUsage, L"Crossbow:    %5i\n", WeaponUsageCur.Crossbow);
    fwprintf(fpWeaponUsage, L"Unarmed:     %5i\n", WeaponUsageCur.Unarmed);

    fclose(fpWeaponUsage);
}

BOOL
WeaponUsageChanged() {
    usize DataSize = sizeof(weapon_usage);

    BOOL Result = DataChanged(
            (void *) &WeaponUsagePrev, (void *) &WeaponUsageCur, DataSize);

    return Result;
}

void
ReadChestFlags(chest_flag_mem *ChestFlags) {
    usize BytesToRead = sizeof(chest_flag_mem);

    usize BytesRead = ReadGameMemory(
            processID, OFFSET_GAZETTE_CHEST_COUNT_FLAGS, BytesToRead, ChestFlags);
}

void
CalculateChestCount(u8 *ChestCount, chest_flag_mem *ChestFlags) {
    *ChestCount = 0; // Clear the counter

    for (int i = 0; i < CHEST_COUNT_FLAGS; ++i) {
        if (ChestFlags->Flags[i] == 0x01) {
            *ChestCount += 1;
        }
    }
}

void
WriteMissingChestList(chest_flag_mem *ChestFlags,
        chest_flag_check ChestFlagChecklist[CHEST_COUNT_MAX]) {
    location Location = { 0 };
    wchar_t ZoneName[MAX_PATH];
    wchar_t MapName[MAX_PATH];

    FILE *fpChestMissing = _wfopen(L"game_data/map/chest_missing.txt", L"w");

    if (ChestCount == CHEST_COUNT_MAX) {
        fwprintf(fpChestMissing, L"You've got them all. Nice!\n");

        fclose(fpChestMissing);

        return;
    } else {
        fwprintf(fpChestMissing, L"Missing Treasure Chests\n\n");

        for (int i = 0; i < CHEST_COUNT_MAX; ++i) {
            if (ChestFlags->Flags[ChestFlagChecklist[i].FlagByte] == 0) {
                Location.ZoneNumber = ChestFlagChecklist[i].Zone;
                Location.MapNumber = ChestFlagChecklist[i].Map;

                ReadZoneAndMapName(&Location, ZoneName, MapName);

                fwprintf(fpChestMissing, L"%s, %s\n", ZoneName, MapName);
            }
        }
    }
    fclose(fpChestMissing);
}

void
ReadMapFlags(map_flag_mem *MapFlags) {
    usize BytesToRead = sizeof(map_flag_mem);

    usize BytesRead = ReadGameMemory(
            processID, OFFSET_GAZETTE_MAP_COUNT_FLAGS, BytesToRead, MapFlags);
}

void
ReadMapCheckFlags(map_flag_mem *MapCheckFlags) {
    usize BytesToRead = sizeof(map_flag_mem);

    usize BytesRead = ReadGameMemory(processID,
            OFFSET_GAZETTE_MAP_COUNT_CHECK_FLAGS, BytesToRead, MapCheckFlags);
}

    void
WriteMapFlagsDiffs()
{
    FILE *fpMapFlagsDiff = _wfopen(L"debug/map_flag_diff.txt", L"a");

    u8 FlagPrev, FlagCur, FlagDiff, BitMask;

    for (int i = 0; i < MAP_COUNT_FLAGS; ++i) {
        FlagPrev = MapFlagMemPrev.Flags[i];
        FlagCur = MapFlagMemCur.Flags[i];

        if (FlagPrev != FlagCur) {
            FlagDiff = FlagCur - FlagPrev;

            for (int j = 0; j < 8; ++j) {
                BitMask = 0x1 << j;
                if (BitMask & FlagDiff) {
                    fwprintf(fpMapFlagsDiff, L"%i,%i,", i, j);
                    fwprintf(fpMapFlagsDiff, L"%s,%s,%i,%i\n", nameZone, nameMap,
                            LocationCur.ZoneNumber, LocationCur.MapNumber);
                }
            }
        }
    }
    fclose(fpMapFlagsDiff);
}

void
WriteChestFlagsDiffs() {
    FILE *fpChestFlagsDiff = _wfopen(L"debug/chest_flag_diff.txt", L"a");

    u8 FlagPrev, FlagCur;

    for (int i = 0; i < CHEST_COUNT_FLAGS; ++i) {
        FlagPrev = ChestFlagMemPrev.Flags[i];
        FlagCur = ChestFlagMemCur.Flags[i];

        if (FlagPrev != FlagCur) {
            fwprintf(fpChestFlagsDiff, L"%i,", i);
            fwprintf(fpChestFlagsDiff, L"%s,%s,%i,%i\n", nameZone, nameMap,
                    LocationCur.ZoneNumber, LocationCur.MapNumber);
        }
    }
    fclose(fpChestFlagsDiff);
}

BOOL
MapFlagsChanged() {
    usize DataSize = sizeof(map_flag_mem);

    BOOL Result = DataChanged(
            (void *) &ChestFlagMemPrev, (void *) &ChestFlagMemCur, DataSize);

    return Result;
}

BOOL
ChestFlagsChanged() {
    usize DataSize = sizeof(chest_flag_mem);

    BOOL Result = DataChanged(
            (void *) &ChestFlagMemPrev, (void *) &ChestFlagMemCur, DataSize);

    return Result;
}

void
CalculateMapCount(u16 *MapCount) {
    // Clear the counter
    *MapCount = 0;
    u8 BitMask = 0;
    u8 CheckByte, FlagByte, AndByte;

    for (int i = 0; i < MAP_COUNT_FLAGS; ++i) {

        FlagByte = MapFlagMemCur.Flags[i];
        CheckByte = MapCheckFlagMem.Flags[i];

        AndByte = FlagByte & CheckByte;

        for (int j = 0; j < 8; ++j) {
            BitMask = 1 << j;

            if (BitMask & AndByte) {
                *MapCount += 1;
            }
        }
    }
}

void
GenerateMapCheckFlagList() {
    u8 BitMask = 0;
    u8 CheckByte;

    FILE *fpCheckFlags = _wfopen(L"debug/map/check_flags.txt", L"w");

    for (int i = 0; i < MAP_COUNT_FLAGS; ++i) {
        CheckByte = MapCheckFlagMem.Flags[i];

        for (int j = 0; j < 8; ++j) {
            BitMask = 1 << j;

            if (BitMask & CheckByte) {
                fwprintf(fpCheckFlags, L"%i,%i\n", i, j);
            }
        }
    }
    fclose(fpCheckFlags);
}

void
WriteMissingMapList(
        map_flag_mem *MapFlags, map_flag_check MapFlagChecklist[MAP_COUNT_MAX]) {
    location Location = { 0 };
    wchar_t nameZone[MAX_PATH];
    wchar_t nameMap[MAX_PATH];
    u8 FlagBitmask = 0;
    u8 CurrentByte;

    FILE *fpMapMissing = _wfopen(L"game_data/map/room_missing.txt", L"w");

    if (MapCount == MAP_COUNT_MAX) {
        fwprintf(fpMapMissing, L"You've been everywhere. You've seen everything.\n");

        fclose(fpMapMissing);

        return;
    } else {
        fwprintf(fpMapMissing, L"Missing Locations\n\n");

        for (int i = 0; i < MAP_COUNT_MAX; ++i) {
            CurrentByte = MapFlags->Flags[MapFlagChecklist[i].MaskByte];
            FlagBitmask = 1 << MapFlagChecklist[i].MaskBit;

            if ((CurrentByte & FlagBitmask) == 0) {
                Location.ZoneNumber = MapFlagChecklist[i].Zone;
                Location.MapNumber = MapFlagChecklist[i].Map;

                ReadZoneAndMapNameCustom(&Location, nameZone, nameMap);

                fwprintf(fpMapMissing, L"%s, %s\n", nameZone, nameMap);
            }
        }
    }
    fclose(fpMapMissing);
}

void
PrintChestCount(u8 *ChestCount) {
    u16 ChestCountScore = (*ChestCount * 100) / CHEST_COUNT_MAX;
    swprintf_s(szBuffer, _countof(szBuffer), L"\nCHEST COUNT:\n");
    WriteToBackBuffer();

    swprintf_s(szBuffer, _countof(szBuffer), L"%i/%i ( %i%% )\n", *ChestCount,
            CHEST_COUNT_MAX, ChestCountScore);
    WriteToBackBuffer();
}

void
WriteChestCount(u8 *ChestCount) {
    u16 ChestCountScore = (*ChestCount * 100) / CHEST_COUNT_MAX;

    FILE *fpChestCount = _wfopen(L"game_data/map/chest_count.txt", L"w");

    fwprintf(fpChestCount, L"== CHEST COUNT ==\n\n");

    fwprintf(fpChestCount, L"%i/%i ( %i%% )\n", *ChestCount, CHEST_COUNT_MAX,
            ChestCountScore);

    fclose(fpChestCount);
}

void
PrintMapCount(u16 *MapCount) {
    u16 MapCountScore = (*MapCount * 100) / MAP_COUNT_MAX;
    swprintf_s(szBuffer, _countof(szBuffer), L"\nROOM COUNT:\n");
    WriteToBackBuffer();

    swprintf_s(szBuffer, _countof(szBuffer), L"%i/%i ( %i%% )\n", *MapCount,
            MAP_COUNT_MAX, MapCountScore);
    WriteToBackBuffer();
}

void
WriteMapCount(u16 *MapCount) {
    u16 MapCountScore = (*MapCount * 100) / MAP_COUNT_MAX;

    FILE *fpMapCount = _wfopen(L"game_data/map/room_count.txt", L"w");

    fwprintf(fpMapCount, L"== ROOM COUNT ==\n\n");

    fwprintf(
            fpMapCount, L"%i/%i ( %i%% )\n", *MapCount, MAP_COUNT_MAX, MapCountScore);

    fclose(fpMapCount);
}

#endif

