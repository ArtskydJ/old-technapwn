int SlopeLimiter(int OldValue, int NewValue, int MaxStepSize)
{
  int Delta = NewValue - OldValue;
  if (Delta >     MaxStepSize) Delta =     MaxStepSize;
  if (Delta < 0 - MaxStepSize) Delta = 0 - MaxStepSize;
  return Delta;
}

task MotorSlewController()
{
  while(true)
  {
    ActualMotorPower += SlopeLimiter(ActualMotorPower, TargetMotorPower, MOTORSTEPMAX);
    wait1Msec(MOTORSLEWLOOPDELAYMS);
  }
}