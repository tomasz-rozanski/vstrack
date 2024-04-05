#ifndef _VST_TRANSLATE_H
#define _VST_TRANSLATE_H

#define OFFSET_EQUIPPED_WEAPON_NAME_STRING 0x11fa7c

typedef struct text_char {
    u8 HexCode;
    char* Glyph;
} text_char;

text_char TranslationTable[] = {
    { 0x00, "0" },
    { 0x01, "1" },
    { 0x02, "2" },
    { 0x03, "3" },
    { 0x04, "4" },
    { 0x05, "5" },
    { 0x06, "6" },
    { 0x07, "7" },
    { 0x08, "8" },
    { 0x09, "9" },
    { 0x0A, "A" },
    { 0x0B, "B" },
    { 0x0C, "C" },
    { 0x0D, "D" },
    { 0x0E, "E" },
    { 0x0F, "F" },
    { 0x10, "G" },
    { 0x11, "H" },
    { 0x12, "I" },
    { 0x13, "J" },
    { 0x14, "K" },
    { 0x15, "L" },
    { 0x16, "M" },
    { 0x17, "N" },
    { 0x18, "O" },
    { 0x19, "P" },
    { 0x1A, "Q" },
    { 0x1B, "R" },
    { 0x1C, "S" },
    { 0x1D, "T" },
    { 0x1E, "U" },
    { 0x1F, "V" },
    { 0x20, "W" },
    { 0x21, "X" },
    { 0x22, "Y" },
    { 0x23, "Z" },
    { 0x24, "a" },
    { 0x25, "b" },
    { 0x26, "c" },
    { 0x27, "d" },
    { 0x28, "e" },
    { 0x29, "f" },
    { 0x2A, "g" },
    { 0x2B, "h" },
    { 0x2C, "i" },
    { 0x2D, "j" },
    { 0x2E, "k" },
    { 0x2F, "l" },
    { 0x30, "m" },
    { 0x31, "n" },
    { 0x32, "o" },
    { 0x33, "p" },
    { 0x34, "q" },
    { 0x35, "r" },
    { 0x36, "s" },
    { 0x37, "t" },
    { 0x38, "u" },
    { 0x39, "v" },
    { 0x3A, "w" },
    { 0x3B, "x" },
    { 0x3C, "y" },
    { 0x3D, "z" },
    { 0x40, "Ć" },
    { 0x41, "Â" },
    { 0x42, "Ä" },
    { 0x43, "Ç" },
    { 0x44, "È" },
    { 0x45, "É" },
    { 0x46, "Ê" },
    { 0x47, "Ë" },
    { 0x48, "Ì" },
    { 0x49, "ő" },
    { 0x4A, "Î" },
    { 0x4B, "í" },
    { 0x4C, "Ò" },
    { 0x4D, "Ó" },
    { 0x4E, "Ô" },
    { 0x4F, "Ö" },
    { 0x50, "Ù" },
    { 0x51, "Ú" },
    { 0x52, "Û" },
    { 0x53, "Ü" },
    { 0x54, "ß" },
    { 0x55, "æ" },
    { 0x56, "à" },
    { 0x57, "á" },
    { 0x58, "â" },
    { 0x59, "ä" },
    { 0x5A, "ç" },
    { 0x5B, "è" },
    { 0x5C, "é" },
    { 0x5D, "ê" },
    { 0x5E, "ë" },
    { 0x5F, "ì" },
    { 0x60, "í" },
    { 0x61, "î" },
    { 0x62, "ï" },
    { 0x63, "ò" },
    { 0x64, "ó" },
    { 0x65, "ô" },
    { 0x66, "ö" },
    { 0x67, "ù" },
    { 0x68, "ú" },
    { 0x69, "û" },
    { 0x6A, "ü" },
    { 0x87, "‼" },
    { 0x88, "≠" },
    { 0x89, "≦" },
    { 0x8A, "≧" },
    { 0x8B, "÷" },
    { 0x8C, "-" },
    { 0x8D, "—" },
    { 0x8E, "⋯" },
    { 0x8F, " " },
    { 0x90, "!" },
    { 0x91, "\"" },
    { 0x92, "#" },
    { 0x93, "$" },
    { 0x94, "%" },
    { 0x95, "&" },
    { 0x96, "\'" },
    { 0x97, "(" },
    { 0x98, ")" },
    { 0x99, "{" },
    { 0x9A, "}" },
    { 0x9B, "[" },
    { 0x9C, "]" },
    { 0x9D, ";" },
    { 0x9E, ":" },
    { 0x9F, "," },
    { 0xA0, "." },
    { 0xA1, "/" },
    { 0xA2, "\\" },
    { 0xA3, "<" },
    { 0xA4, ">" },
    { 0xA5, "?" },
    { 0xA6, "_" },
    { 0xA7, "-" },
    { 0xA8, "+" },
    { 0xA9, "*" },
    { 0xAB, "{" },
    { 0xAC, "}" },
    { 0xAD, "♪" },
    { 0xE8, "\n" },
    { 0xEB, "_" },
    { 0xB6, "Lv." },
    /*
       { 0xF801, "«p1»" },
       { 0xF802, "«p2»" },
       { 0xF808, "«p8»" },
       { 0xF80A, "«p10»" },
       { 0xFA06, " " }
       */
};

void
ReadWeaponName() {
    nameWeaponCur[0] = L'\0';
    // Check if any weapon is eqipped
    if (itemBladeCur.ListPosition == 0 || itemBladeCur.ListPosition > 511) return;

    wchar_t *temp = malloc(WEAPON_NAME_UNICODE_LENGTH * sizeof(wchar_t));
    int temp_size = 0;
    u8 WeaponNameHex[WEAPON_NAME_HEX_LENGTH];
    usize BytesToRead = (usize) WEAPON_NAME_HEX_LENGTH;

    usize BytesRead = ReadGameMemory(processID,
            OFFSET_EQUIPPED_WEAPON_NAME_STRING, BytesToRead, WeaponNameHex);

    for (int i = 0; i < WEAPON_NAME_HEX_LENGTH; ++i) {
        u8 *HexCode = &WeaponNameHex[i];
        switch (*HexCode) { 
            case 0xe7: // end of string
                {
                    swprintf_s(nameWeaponCur, WEAPON_NAME_UNICODE_LENGTH, L"%s\00", nameWeaponCur);
                    free(temp);
                    return;
                    break;
                }
            case 0xf8: // special strings
                {
                    switch (*(HexCode+1)) {
                        case 0x01:
                            temp_size = MultiByteToWideChar(CP_UTF8, 0, "«p1»", -1, temp, ACTOR_NAME_UNICODE_LENGTH);
                            swprintf_s(ActorName, ACTOR_NAME_UNICODE_LENGTH, L"%s%s", ActorName, temp);
                            i++;
                            continue;
                            break;
                        case 0x02:
                            temp_size = MultiByteToWideChar(CP_UTF8, 0, "«p2»", -1, temp, ACTOR_NAME_UNICODE_LENGTH);
                            swprintf_s(ActorName, ACTOR_NAME_UNICODE_LENGTH, L"%s%s", ActorName, temp);
                            i++;
                            continue;
                            break;
                        case 0x08:
                            temp_size = MultiByteToWideChar(CP_UTF8, 0, "«p8»", -1, temp, ACTOR_NAME_UNICODE_LENGTH);
                            swprintf_s(ActorName, ACTOR_NAME_UNICODE_LENGTH, L"%s%s", ActorName, temp);
                            i++;
                            continue;
                            break;
                        case 0x0a:
                            temp_size = MultiByteToWideChar(CP_UTF8, 0, "«p10»", -1, temp, ACTOR_NAME_UNICODE_LENGTH);
                            swprintf_s(ActorName, ACTOR_NAME_UNICODE_LENGTH, L"%s%s", ActorName, temp);
                            i++;
                            continue;
                            break;
                    }
                }
            case 0xfa:
                switch (*(HexCode + 1)) {
                    case 0x06:
                        swprintf_s(nameWeaponCur, WEAPON_NAME_UNICODE_LENGTH, L"%s ", nameWeaponCur);
                        i++;
                        continue;
                        break;
                }
            default: // standard characters
                for (int j = 0, count = _countof(TranslationTable); j < count; j++) {
                    if (TranslationTable[j].HexCode == *HexCode) {  
                        char *mbyte = TranslationTable[j].Glyph;
                        temp_size = MultiByteToWideChar(CP_UTF8, 0, mbyte, -1, temp, WEAPON_NAME_UNICODE_LENGTH);
                        swprintf_s(nameWeaponCur, WEAPON_NAME_UNICODE_LENGTH, L"%s%s", nameWeaponCur, temp);
                        break;
                    }
                }
        } 
    }
    free(temp);
}

void
ReadActorName(u32 NameOffset) {
    ActorName[0] = L'\00';

    wchar_t *temp = malloc(ACTOR_NAME_UNICODE_LENGTH * sizeof(wchar_t));
    int temp_size = 0;
    u8 ActorNameHex[ACTOR_NAME_HEX_LENGTH];
    usize BytesToRead = (usize) ACTOR_NAME_HEX_LENGTH;

    usize BytesRead =
        ReadGameMemory(processID, NameOffset, BytesToRead, ActorNameHex);

    for (int i = 0; i < ACTOR_NAME_HEX_LENGTH; ++i) {
        u8 *HexCode = &ActorNameHex[i];
        switch (*HexCode) { 
            case 0xe7: // end of string
                {
                    swprintf_s(nameWeaponCur, ACTOR_NAME_UNICODE_LENGTH, L"%s\00", nameWeaponCur);
                    free(temp);
                    return;
                    break;
                }
            case 0xf8: // special strings
                {
                    switch (*(HexCode + 1)) {
                        case 0x01:
                            temp_size = MultiByteToWideChar(CP_UTF8, 0, "«p1»", -1, temp, ACTOR_NAME_UNICODE_LENGTH);
                            swprintf_s(ActorName, ACTOR_NAME_UNICODE_LENGTH, L"%s%s", ActorName, temp);
                            i++;
                            continue;
                            break;
                        case 0x02:
                            temp_size = MultiByteToWideChar(CP_UTF8, 0, "«p2»", -1, temp, ACTOR_NAME_UNICODE_LENGTH);
                            swprintf_s(ActorName, ACTOR_NAME_UNICODE_LENGTH, L"%s%s", ActorName, temp);
                            i++;
                            continue;
                            break;
                        case 0x08:
                            temp_size = MultiByteToWideChar(CP_UTF8, 0, "«p8»", -1, temp, ACTOR_NAME_UNICODE_LENGTH);
                            swprintf_s(ActorName, ACTOR_NAME_UNICODE_LENGTH, L"%s%s", ActorName, temp);
                            i++;
                            continue;
                            break;
                        case 0x0a:
                            temp_size = MultiByteToWideChar(CP_UTF8, 0, "«p10»", -1, temp, ACTOR_NAME_UNICODE_LENGTH);
                            swprintf_s(ActorName, ACTOR_NAME_UNICODE_LENGTH, L"%s%s", ActorName, temp);
                            i++;
                            continue;
                            break;
                    }
                }
            case 0xfa:
                switch (*(HexCode + 1)) {
                    case 0x06:
                        swprintf_s(ActorName, ACTOR_NAME_UNICODE_LENGTH, L"%s ", ActorName);
                        i++;
                        continue;
                        break;
                }
            default: // standard characters
                for (int j = 0, count = _countof(TranslationTable); j < count; j++) {
                    if (TranslationTable[j].HexCode == *HexCode) {  
                        char *mbyte = TranslationTable[j].Glyph;
                        temp_size = MultiByteToWideChar(CP_UTF8, 0, mbyte, -1, temp, ACTOR_NAME_UNICODE_LENGTH);
                        swprintf_s(ActorName, ACTOR_NAME_UNICODE_LENGTH, L"%s%s", ActorName, temp);
                        break;
                    }
                }
        } 
    }
    free(temp);
}

void
_ReadActorName(u32 NameOffset) {
    ActorName[0] = L'\00';

    char ActorNameHex[ACTOR_NAME_HEX_LENGTH];
    usize BytesToRead = (usize) ACTOR_NAME_HEX_LENGTH;

    usize BytesRead =
        ReadGameMemory(processID, NameOffset, BytesToRead, ActorNameHex);

    for (int i = 0, k = 0; i < ACTOR_NAME_HEX_LENGTH; ++i) {
        u8 *HexCode = (u8 *) &ActorNameHex[i];
        if (*HexCode == 0xe7 || *HexCode == 0x00)
        {
            swprintf_s(ActorName, ACTOR_NAME_UNICODE_LENGTH, L"%ls\00", ActorName);
            break;
        }

        if (*HexCode == 0xfa && *(HexCode + 1) == 0x06)
        {
            swprintf_s(ActorName, ACTOR_NAME_UNICODE_LENGTH, L"%ls ", ActorName);
            i++;
            continue;
        }

        for (int j = 0, size = _countof(TranslationTable); j < size; ++j)
        {
            if (TranslationTable[j].HexCode == (char) *HexCode)
            {

                swprintf_s(ActorName, ACTOR_NAME_UNICODE_LENGTH, L"%ls%hs", ActorName, TranslationTable[j].Glyph);
                break;
            }
        }
    }
}

void
ReadWeaponNumber() {
    u8 *tempBuffer;

    char number_s[1];
    number_s[0] = nameWeaponCur[wcslen(nameWeaponCur) - 1];

    WeaponNumber = strtoul(number_s, &tempBuffer, 10);
}

BOOL
WeaponNameChanged() {
    if (wcscmp(nameWeaponPrev, nameWeaponCur) == 0) {
        return FALSE;
    }
    return TRUE;
}

void
PrintWeaponName() {
    swprintf_s(
            szBuffer, _countof(szBuffer), L"\nWEAPON NAME:\n%s\n", nameWeaponCur);
    WriteToBackBuffer();
}

#endif
