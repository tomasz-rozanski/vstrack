#ifndef _VST_TRANSLATE_H
#define _VST_TRANSLATE_H

#define OFFSET_EQUIPPED_WEAPON_NAME_STRING 0x8011FA7C

INT8 TranslationTableHex[125] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06,
  0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10, 0x11, 0x12, 0x13,
  0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x20,
  0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D,
  0x2E, 0x2F, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A,
  0x3B, 0x3C, 0x3D, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x4A, 0x4C,
  0x4D, 0x4E, 0x4F, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59,
  0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F, 0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66,
  0x67, 0x68, 0x69, 0x6A, 0x8F, 0x90, 0x91, 0x94, 0x96, 0x97, 0x98, 0x99, 0x9A,
  0x9B, 0x9C, 0x9D, 0x9E, 0x9F, 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA7, 0xA8,
  0xE8 };

char TranslationTableChars[125] = { '0', '1', '2', '3', '4', '5', '6', '7', '8',
  '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
  'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c',
  'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
  's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'Â', 'Ä', 'Ç', 'È', 'É', 'Ê', 'Ë',
  'Ì', 'Î', 'Ò', 'Ó', 'Ô', 'Ö', 'Ù', 'Ú', 'Û', 'Ü', 'ß', 'æ', 'à', 'á', 'â',
  'ä', 'ç', 'è', 'é', 'ê', 'ë', 'ì', 'í', 'î', 'ï', 'ò', 'ó', 'ô', 'ö', 'ù',
  'ú', 'û', 'ü', ' ', '!', '"', '%', '\'', '(', ')', '{', '}', '[', ']', ';',
  ':', ',', '.', '/', '\\', '<', '>', '?', '-', '+', '\n' };

typedef struct
{
  char Name[18];
} weapon_name;

void
GetWeaponName(DWORD processID, char *WeaponName)
{
  equip_item_info BladeInfo;

  SIZE_T BytesToRead = sizeof(equip_item_info);
  DWORD BytesRead;

  BytesRead = ReadGameMemory(
      processID, OFFSET_EQUIPPED_WEAPON_BLADE, BytesToRead, &BladeInfo);

  // Check if weapon is eqipped
  if (BladeInfo.ListPosition == 0)
  {
    return;
  }

  WeaponName[0] = '\0';
  weapon_name WeaponNameStruct;
  BytesToRead = sizeof(weapon_name);

  BytesRead = ReadGameMemory(processID, OFFSET_EQUIPPED_WEAPON_NAME_STRING,
      BytesToRead, &WeaponNameStruct);

  for (int i = 0; i < 18; ++i)
  {
    UINT8 HexCode = WeaponNameStruct.Name[i];
    if (HexCode == 0xE7)
    {
      break;
    }

    if (HexCode == 0xFA)
    {
      if (WeaponNameStruct.Name[i + 1] == 0x06)
      {
        wsprintf(WeaponName, "%s ", WeaponName);
        i++;
        continue;
      }
    }

    for (int j = 0, size = NELEMS(TranslationTableHex); j < size; ++j)
    {
      if (TranslationTableHex[j] == HexCode)
      {
        wsprintf(WeaponName, "%s%c", WeaponName, TranslationTableChars[j]);
      }
    }
  }

  // Some DEBUG info
  sprintf(szBuffer, "\n\n== WEAPON NAME ==\n\n");
  WriteToBackBuffer();
  sprintf(szBuffer, "In memory (HEX): ");
  WriteToBackBuffer();

  for (int i = 0; i < 18; ++i)
  {
    UINT8 HexCode = WeaponNameStruct.Name[i];

    sprintf(szBuffer, "%02X ", HexCode);
    WriteToBackBuffer();
  }

  sprintf(szBuffer, "\nAfter translation: \"%s\"\n", WeaponName);
  WriteToBackBuffer();
}

#endif