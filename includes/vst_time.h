#ifndef _VST_TIME_H
#define _VST_TIME_H

#define OFFSET_TIME_PLAYED 0x061074 // 4 bytes

void
PrintGameTimeShort(game_time *GameTime) {
    u32 BytesWritten;

    u8 Seconds = GameTime->Seconds;
    u8 Minutes = GameTime->Minutes;
    u8 Hours = GameTime->Hours;

    swprintf_s(szBuffer, _countof(szBuffer), L"\nGAME TIME:\n");
    WriteToBackBuffer();

    swprintf_s(szBuffer, _countof(szBuffer), L"%02i:%02i:%02i\n", Hours, Minutes,
            Seconds);
    WriteToBackBuffer();
}

void
PrintGameTimeRecord(game_time *RecordTime) {
    u8 Seconds = RecordTime->Seconds;
    u8 Minutes = RecordTime->Minutes;
    u8 Hours = RecordTime->Hours;

    fwprintf(stdout, L"\nRECORD TIME:\n");
    fwprintf(stdout, L"%02i:%02i:%02i\n", Hours, Minutes, Seconds);
}

void
ReadGameTime(game_time *GameTime) {

    usize BytesToRead = sizeof(game_time);
    usize BytesRead;

    ReadGameMemory(processID, OFFSET_TIME_PLAYED, BytesToRead, GameTime);
}

void
WriteGameTimeToFile(game_time *GameTime) {
    u8 Seconds = GameTime->Seconds;
    u8 Minutes = GameTime->Minutes;
    u8 Hours = GameTime->Hours;

    FILE *fpGameTime = _wfopen(L"game_data/time/game_time.txt", L"w");

    // Standard time (seconds accuracy)
    fwprintf(fpGameTime, L"%02i:%02i:%02i", Hours, Minutes, Seconds);

    fclose(fpGameTime);
}

void
WriteGameTimeRecordToFile(game_time *RecordTime) {
    TCHAR szFullPath[MAX_PATH];

    WriteTimeStampFileString();

    swprintf_s(
            szFullPath, _countof(szFullPath), L"game_data/time/records/%s-record-time.txt", szTimeStampFile);

    u8 Seconds = RecordTime->Seconds;
    u8 Minutes = RecordTime->Minutes;
    u8 Hours = RecordTime->Hours;

    FILE *fpRecordTime = _wfopen(szFullPath, L"w");

    // Standard time (seconds accuracy)
    fwprintf(fpRecordTime, L"Record Time\n%02i:%02i:%02i", Hours, Minutes, Seconds);

    fclose(fpRecordTime);
}

BOOL
GameTimeChanged(game_time *Time1, game_time *Time2) {
    usize DataSize = sizeof(game_time);

    BOOL Result = DataChanged((void *) Time1, (void *) Time2, DataSize);

    return Result;
}

BOOL
IsItLater(game_time *TimeOld, game_time *TimeNew) {
    u32 Old = (u32)(((u32)(TimeOld->Seconds) << 16) | //
            ((u32)(TimeOld->Minutes) << 8) | //
            ((u32)(TimeOld->Hours)));
    u32 New = (u32)(((u32)(TimeNew->Seconds) << 16) | //
            ((u32)(TimeNew->Minutes) << 8) | //
            ((u32)(TimeNew->Hours)));

    return New > Old;
}

#endif

