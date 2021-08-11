#ifndef _VST_TRANSLATE_H
#define _VST_TRANSLATE_H

#define OFFSET_EQUIPPED_WEAPON_NAME_STRING 0x11fa7c

u8 TranslationTableHex[125] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
  0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14,
  0x15, 0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 0x20, 0x21,
  0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e,
  0x2f, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x3b,
  0x3c, 0x3d, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x4a, 0x4c, 0x4d,
  0x4e, 0x4f, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59, 0x5a,
  0x5b, 0x5c, 0x5d, 0x5e, 0x5f, 0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67,
  0x68, 0x69, 0x6a, 0x8f, 0x90, 0x91, 0x94, 0x96, 0x97, 0x98, 0x99, 0x9a, 0x9b,
  0x9c, 0x9d, 0x9e, 0x9f, 0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa7, 0xa8,
  0xe8 };

char TranslationTableChars[125] = { '0', '1', '2', '3', '4', '5', '6', '7', '8',
  '9', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
  'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c',
  'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
  's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'Â', 'Ä', 'Ç', 'È', 'É', 'Ê', 'Ë',
  'Ì', 'Î', 'Ò', 'Ó', 'Ô', 'Ö', 'Ù', 'Ú', 'Û', 'Ü', 'ß', 'æ', 'à', 'á', 'â',
  'ä', 'ç', 'è', 'é', 'ê', 'ë', 'ì', 'í', 'î', 'ï', 'ò', 'ó', 'ô', 'ö', 'ù',
  'ú', 'û', 'u', ' ', '!', '"', '%', '\'', '(', ')', '{', '}', '[', ']', ';',
  ':', ',', '.', '/', '\\', '<', '>', '?', '-', '+', '\n' };

void
ReadWeaponName()
{
  nameWeaponCur[0] = '\0';

  // Check if weapon is eqipped
  if (itemBladeCur.ListPosition == 0 || itemBladeCur.ListPosition > 511)
  {
    return;
  }

  char WeaponNameHex[WEAPON_NAME_LENGTH];
  usize BytesToRead = (usize) WEAPON_NAME_LENGTH;

  usize BytesRead = ReadGameMemory(processID,
      OFFSET_EQUIPPED_WEAPON_NAME_STRING, BytesToRead, WeaponNameHex);

  for (int i = 0, k = 0; i < WEAPON_NAME_LENGTH; ++i)
  {
    u8 *HexCode = (u8 *) &WeaponNameHex[i];
    if (*HexCode == 0xe7)
    {
      nameWeaponCur[k] = '\0';
      break;
    }

    if (*HexCode == 0xfa && *(HexCode + 1) == 0x06)
    {
      nameWeaponCur[k++] = ' ';
      i++;
      continue;
    }

    for (int j = 0, size = _countof(TranslationTableHex); j < size; ++j)
    {
      if (TranslationTableHex[j] == (char) *HexCode)
      {
        nameWeaponCur[k++] = TranslationTableChars[j];
        break;
      }
    }
  }
}

void
ReadActorName(u32 NameOffset)
{
  ActorName[0] = '\0';

  char ActorNameHex[ACTOR_NAME_LENGTH];
  usize BytesToRead = (usize) ACTOR_NAME_LENGTH;

  usize BytesRead =
      ReadGameMemory(processID, NameOffset, BytesToRead, ActorNameHex);

  for (int i = 0, k = 0; i < ACTOR_NAME_LENGTH; ++i)
  {
    u8 *HexCode = (u8 *) &ActorNameHex[i];
    if (*HexCode == 0xe7 || *HexCode == 0x00)
    {
      ActorName[k] = '\0';
      break;
    }

    if (*HexCode == 0xfa && *(HexCode + 1) == 0x06)
    {
      ActorName[k++] = ' ';
      i++;
      continue;
    }

    for (int j = 0, size = _countof(TranslationTableHex); j < size; ++j)
    {
      if (TranslationTableHex[j] == (char) *HexCode)
      {
        ActorName[k++] = TranslationTableChars[j];
        break;
      }
    }
  }
}

void
ReadWeaponNumber()
{
  u8 *tempBuffer;

  char number_s[1];
  number_s[0] = nameWeaponCur[strlen(nameWeaponCur) - 1];

  WeaponNumber = strtoul(number_s, &tempBuffer, 10);
}

BOOL
WeaponNameChanged()
{
  if (strcmp(nameWeaponPrev, nameWeaponCur) == 0)
  {
    return FALSE;
  }

  return TRUE;
}

void
PrintWeaponName()
{
  sprintf_s(
      szBuffer, _countof(szBuffer), "\nWEAPON NAME:\n%s\n", nameWeaponCur);
  WriteToBackBuffer();
}

#endif
