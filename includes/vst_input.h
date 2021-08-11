#ifndef _VST_INPUT_H
#define _VST_INPUT_H

// Controller input
#define OFFSET_CONTROLLER_INPUT 0x05e1c0
#define OFFSET_BUTTONS_TIMERS 0x055c90

#define MASK_CONTROLLER_INPUT_L2 0x0001
#define MASK_CONTROLLER_INPUT_R2 0x0002
#define MASK_CONTROLLER_INPUT_L1 0x0004
#define MASK_CONTROLLER_INPUT_R1 0x0008
#define MASK_CONTROLLER_INPUT_TRIANGLE 0x0010
#define MASK_CONTROLLER_INPUT_CIRCLE 0x0020
#define MASK_CONTROLLER_INPUT_CROSS 0x0040
#define MASK_CONTROLLER_INPUT_SQUARE 0x0080
#define MASK_CONTROLLER_INPUT_SELECT 0x0100
#define MASK_CONTROLLER_INPUT_L3 0x0200
#define MASK_CONTROLLER_INPUT_R3 0x0400
#define MASK_CONTROLLER_INPUT_START 0x0800
#define MASK_CONTROLLER_INPUT_UP 0x1000
#define MASK_CONTROLLER_INPUT_RIGHT 0x2000
#define MASK_CONTROLLER_INPUT_DOWN 0x4000
#define MASK_CONTROLLER_INPUT_LEFT 0x8000

char *ControllerInputNames[16] = { //
  "L2", //
  "R2", //
  "L1", //
  "R1", //
  "Triangle", //
  "Circle", //
  "Cross", //
  "Square", //
  "Select", //
  "L3", //
  "R3", //
  "Start", //
  "Up", //
  "Right", //
  "Down", //
  "Left"
};

u16 ControllerInputMasks[16] = { //
  MASK_CONTROLLER_INPUT_L2, //
  MASK_CONTROLLER_INPUT_R2, //
  MASK_CONTROLLER_INPUT_L1, //
  MASK_CONTROLLER_INPUT_R1, //
  MASK_CONTROLLER_INPUT_TRIANGLE, //
  MASK_CONTROLLER_INPUT_CIRCLE, //
  MASK_CONTROLLER_INPUT_CROSS, //
  MASK_CONTROLLER_INPUT_SQUARE, //
  MASK_CONTROLLER_INPUT_SELECT, //
  MASK_CONTROLLER_INPUT_L3, //
  MASK_CONTROLLER_INPUT_R3, //
  MASK_CONTROLLER_INPUT_START,
  MASK_CONTROLLER_INPUT_UP, //
  MASK_CONTROLLER_INPUT_RIGHT,
  MASK_CONTROLLER_INPUT_DOWN, //
  MASK_CONTROLLER_INPUT_LEFT
};

void
ReadControllerInput(u16 *ControllerInput)
{
  usize BytesToRead = sizeof(u16);

  ReadGameMemory(
      processID, OFFSET_CONTROLLER_INPUT, BytesToRead, ControllerInput);
}

void
ReadButtonsTimers(buttons_timers *ButtonsTimers)
{
  usize BytesToRead = sizeof(buttons_timers);

  ReadGameMemory(processID, OFFSET_BUTTONS_TIMERS, BytesToRead, ButtonsTimers);
}

void
PrintControllerInput(u16 *ControllerInput)
{
  u16 Input = *ControllerInput;

  sprintf(szBuffer, "\nCONTROLLER INPUT:\n");
  WriteToBackBuffer();

  if (!Input) // if the register is empty, skip to the end
  {
    sprintf(szBuffer, "None\n");
    WriteToBackBuffer();
  }
  else
  {
    for (int i = 0; i < 16; ++i)
    {
      if (ControllerInputMasks[i] & Input)
      {
        sprintf(szBuffer, "%s(%d) ", ControllerInputNames[i],
            ButtonsTimers.Timers[i]);
        WriteToBackBuffer();
      }
    }
    sprintf(szBuffer, "\n");
    WriteToBackBuffer();
  }
}

void
WriteControllerInput(u16 *ControllerInput)
{
  FILE *fpControllerInput = fopen("game_data/player/controller_input.txt", "w");
  u16 Input = *ControllerInput;

  if (!Input) // if the register is empty, skip to the end
  {
    fprintf(fpControllerInput, "No controller input\n");
  }
  else
  {
    for (int i = 0; i < 16; ++i)
    {
      if (ControllerInputMasks[i] & Input)
      {
        fprintf(fpControllerInput, "%s ", ControllerInputNames[i]);
      }
    }
    fprintf(fpControllerInput, "\n");
  }
  fclose(fpControllerInput);
}

BOOL
ControllerInputChanged()
{
  usize DataSize = sizeof(u16);

  BOOL Result = DataChanged(
      (void *) &ControllerInputPrev, (void *) &ControllerInputCur, DataSize);

  return Result;
}
#endif
