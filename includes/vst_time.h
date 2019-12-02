#ifndef _VST_TIME_H
#define _VST_TIME_H

#define OFFSET_TIME_PLAYED 0x80061074 // 4 bytes

void
PrintGameTimeShort(game_time *GameTime)
{
  u32 BytesWritten;

  u8 Seconds = GameTime->Seconds;
  u8 Minutes = GameTime->Minutes;
  u8 Hours = GameTime->Hours;

  sprintf_s(szBuffer, _countof(szBuffer), "\n\n== GAME TIME ==\n\n");
  WriteToBackBuffer();

  sprintf_s(szBuffer, _countof(szBuffer), "%02i:%02i:%02i\n", Hours, Minutes,
      Seconds);
  WriteToBackBuffer();
}

void
PrintGameTimeRecord(game_time *RecordTime)
{
  u8 Seconds = RecordTime->Seconds;
  u8 Minutes = RecordTime->Minutes;
  u8 Hours = RecordTime->Hours;

  fprintf(stdout, "\n== RECORD TIME ==\n\n");
  fprintf(stdout, "%02i:%02i:%02i\n", Hours, Minutes, Seconds);
}

void
ReadGameTime(game_time *GameTime)
{

  usize BytesToRead = sizeof(game_time);
  usize BytesRead;

  ReadGameMemory(processID, OFFSET_TIME_PLAYED, BytesToRead, GameTime);
}

void
WriteGameTimeToFile(game_time *GameTime)
{
  u8 Seconds = GameTime->Seconds;
  u8 Minutes = GameTime->Minutes;
  u8 Hours = GameTime->Hours;

  FILE *fpGameTime = fopen("game_data/time/game_time.txt", "w");

  // Standard time (seconds accuracy)
  fprintf(fpGameTime, "%02i:%02i:%02i", Hours, Minutes, Seconds);

  fclose(fpGameTime);
}

void
WriteGameTimeRecordToFile(game_time *RecordTime)
{
  TCHAR szFullPath[MAX_PATH];

  WriteTimeStampFileString();

  sprintf(
      szFullPath, "game_data/time/records/%s-record-time.txt", szTimeStampFile);

  u8 Seconds = RecordTime->Seconds;
  u8 Minutes = RecordTime->Minutes;
  u8 Hours = RecordTime->Hours;

  FILE *fpRecordTime = fopen(szFullPath, "w");

  // Standard time (seconds accuracy)
  fprintf(fpRecordTime, "Record Time\n%02i:%02i:%02i", Hours, Minutes, Seconds);

  fclose(fpRecordTime);
}

BOOL
GameTimeChanged(game_time *Time1, game_time *Time2)
{
  usize DataSize = sizeof(game_time);

  BOOL Result = DataChanged((void *) Time1, (void *) Time2, DataSize);

  return Result;
}

BOOL
IsItLater(game_time *TimeOld, game_time *TimeNew)
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