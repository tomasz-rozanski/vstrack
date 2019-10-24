#ifndef _VST_TIME_H
#define _VST_TIME_H

//
// Time Played
//

// 4 bytes
#define OFFSET_TIME_PLAYED 0x80061074

typedef struct
{
  union {
    UINT32 TimeCompound;
    struct
    {
      UINT8 Centiseconds;
      UINT8 Seconds;
      UINT8 Minutes;
      UINT8 Hours;
    };
  } Time;
} playtime;

playtime PlayTimeCurrent = { -1 };
playtime PlayTimeTemp = { -1 };
playtime RecordTime = { -1 };

void
PrintPlayTimeFull(playtime *PlayTime)
{
  UINT8 Centiseconds = PlayTime->Time.Centiseconds;
  UINT8 Seconds = PlayTime->Time.Seconds;
  UINT8 Minutes = PlayTime->Time.Minutes;
  UINT8 Hours = PlayTime->Time.Hours;

  fprintf(stdout, "\n= PLAY TIME =\n");
  fprintf(
      stdout, "%02i:%02i:%02i.%02i\n", Hours, Minutes, Seconds, Centiseconds);
}

void
PrintPlayTimeShort(playtime *PlayTime)
{
  UINT8 Seconds = PlayTime->Time.Seconds;
  UINT8 Minutes = PlayTime->Time.Minutes;
  UINT8 Hours = PlayTime->Time.Hours;

  fprintf(stdout, "\n= PLAY TIME =\n");
  fprintf(stdout, "%02i:%02i:%02i\n", Hours, Minutes, Seconds);
}

void
PrintPlayTimeShort2(playtime *PlayTime)
{
  DWORD BytesWritten;

  UINT8 Seconds = PlayTime->Time.Seconds;
  UINT8 Minutes = PlayTime->Time.Minutes;
  UINT8 Hours = PlayTime->Time.Hours;

  sprintf(szBuffer, "\n\n== PLAY TIME ==\n\n");
  WriteToBackBuffer();

  sprintf(szBuffer, "%02i:%02i:%02i\n", Hours, Minutes, Seconds);
  WriteToBackBuffer();
}

void
PrintRecordTime(playtime *RecordTime)
{
  UINT8 Seconds = RecordTime->Time.Seconds;
  UINT8 Minutes = RecordTime->Time.Minutes;
  UINT8 Hours = RecordTime->Time.Hours;

  fprintf(stdout, "\n== RECORD TIME ==\n\n");
  fprintf(stdout, "%02i:%02i:%02i\n", Hours, Minutes, Seconds);
}

DWORD
ReadPlayTime(playtime *PlayTime)
{
  SIZE_T BytesToRead = sizeof(playtime);
  DWORD BytesRead;

  BytesRead = ReadGameMemory(
      processID, OFFSET_TIME_PLAYED, BytesToRead, &PlayTime->Time.TimeCompound);

  return BytesRead;
}

void
WritePlayTimeToFile(playtime *PlayTime, TCHAR FileName[MAX_PATH])
{
  UINT8 Seconds = PlayTime->Time.Seconds;
  UINT8 Minutes = PlayTime->Time.Minutes;
  UINT8 Hours = PlayTime->Time.Hours;

  FILE *fpPlayTime = fopen(FileName, "w");

  // Standard time (seconds accuracy)
  fprintf(fpPlayTime, "%02i:%02i:%02i", Hours, Minutes, Seconds);

  fclose(fpPlayTime);
}

void
WriteRecordTimeToFile(playtime *RecordTime, TCHAR FileName[MAX_PATH])
{
  UINT8 Seconds = RecordTime->Time.Seconds;
  UINT8 Minutes = RecordTime->Time.Minutes;
  UINT8 Hours = RecordTime->Time.Hours;

  FILE *fpRecordTime = fopen(FileName, "w");

  // Standard time (seconds accuracy)
  fprintf(fpRecordTime, "Record Time\n%02i:%02i:%02i", Hours, Minutes, Seconds);

  fclose(fpRecordTime);
}

BOOL
ComparePlayTimeShort(playtime *Time1, playtime *Time2)
{
  if ((Time1->Time.TimeCompound & 0x0fff) ==
      (Time2->Time.TimeCompound & 0x0fff))
  {
    return TRUE;
  }
  return FALSE;
}

BOOL
IsItLater(playtime *TimeOld, playtime *TimeNew)
{
  UINT32 Old = TimeOld->Time.TimeCompound & 0xfff0;
  UINT32 New = TimeNew->Time.TimeCompound & 0xfff0;

  return New > Old;
}

#endif