#ifndef _VST_TIME_H
#define _VST_TIME_H

#define OFFSET_TIME_PLAYED 0x80061074 // 4 bytes

void
PrintPlayTimeFull(playtime *PlayTime)
{
  u8 Centiseconds = PlayTime->Centiseconds;
  u8 Seconds = PlayTime->Seconds;
  u8 Minutes = PlayTime->Minutes;
  u8 Hours = PlayTime->Hours;

  fprintf(stdout, "\n= PLAY TIME =\n");
  fprintf(
      stdout, "%02i:%02i:%02i.%02i\n", Hours, Minutes, Seconds, Centiseconds);
}

void
PrintPlayTimeShort(playtime *PlayTime)
{
  u32 BytesWritten;

  u8 Seconds = PlayTime->Seconds;
  u8 Minutes = PlayTime->Minutes;
  u8 Hours = PlayTime->Hours;

  sprintf_s(szBuffer, _countof(szBuffer), "\n\n== PLAY TIME ==\n\n");
  WriteToBackBuffer();

  sprintf_s(szBuffer, _countof(szBuffer), "%02i:%02i:%02i\n", Hours, Minutes,
      Seconds);
  WriteToBackBuffer();
}

void
PrintRecordTime(playtime *RecordTime)
{
  u8 Seconds = RecordTime->Seconds;
  u8 Minutes = RecordTime->Minutes;
  u8 Hours = RecordTime->Hours;

  fprintf(stdout, "\n== RECORD TIME ==\n\n");
  fprintf(stdout, "%02i:%02i:%02i\n", Hours, Minutes, Seconds);
}

void
ReadPlayTime(playtime *PlayTime)
{

  usize BytesToRead = sizeof(playtime);
  usize BytesRead;

  ReadGameMemory(processID, OFFSET_TIME_PLAYED, BytesToRead, PlayTime);
}

void
WritePlayTimeToFile(playtime *PlayTime, TCHAR FileName[MAX_PATH])
{
  u8 Seconds = PlayTime->Seconds;
  u8 Minutes = PlayTime->Minutes;
  u8 Hours = PlayTime->Hours;

  FILE *fpPlayTime = fopen(FileName, "w");

  // Standard time (seconds accuracy)
  fprintf(fpPlayTime, "%02i:%02i:%02i", Hours, Minutes, Seconds);

  fclose(fpPlayTime);
}

void
WriteRecordTimeToFile(
    playtime *RecordTime, TCHAR szFolderName[128], TCHAR FileName[128])
{
  TCHAR szFullPath[MAX_PATH];

  WriteTimeStampFileString();

  sprintf(szFullPath, "%s/%s-%s", szFolderName, szTimeStampFile, FileName);

  u8 Seconds = RecordTime->Seconds;
  u8 Minutes = RecordTime->Minutes;
  u8 Hours = RecordTime->Hours;

  FILE *fpRecordTime = fopen(szFullPath, "w");

  // Standard time (seconds accuracy)
  fprintf(fpRecordTime, "Record Time\n%02i:%02i:%02i", Hours, Minutes, Seconds);

  fclose(fpRecordTime);
}

BOOL
ComparePlayTimeShort(playtime *Time1, playtime *Time2)
{
  if (Time1->Hours == Time2->Hours && Time1->Minutes == Time2->Minutes &&
      Time1->Seconds == Time2->Seconds)
  {
    return TRUE;
  }
  return FALSE;
}

BOOL
IsItLater(playtime *TimeOld, playtime *TimeNew)
{
  u32 Old = (u32)(((u32)(TimeOld->Seconds) << 16) | //
                  ((u32)(TimeOld->Minutes) << 8) | //
                  ((u32)(TimeOld->Hours)));
  u32 New = (u32)(((u32)(TimeNew->Seconds) << 16) | //
                  ((u32)(TimeNew->Minutes) << 8) | //
                  ((u32)(TimeNew->Hours)));

  return New > Old;
}

#endif