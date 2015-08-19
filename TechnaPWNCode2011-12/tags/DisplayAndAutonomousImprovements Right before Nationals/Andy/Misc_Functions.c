int IsMenuItemActivated() //This function makes sure that the activate action happens only when it is supposed to
{
	int Dummy = ActivateMenuItem;
	ActivateMenuItem = 0;
	return Dummy;
}

int CheckJoystick()
{
	//Are the joystick tests
	if (abs(vexRT[Ch1]) > JOYSTICKDEADZONE || abs(vexRT[Ch2]) > JOYSTICKDEADZONE || abs(vexRT[Ch3]) > JOYSTICKDEADZONE || abs(vexRT[Ch4]) > JOYSTICKDEADZONE)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void ToggleCheck (int CurrentButtonState, int &WasAlreadyPressed, int &ToBeToggled)
{
	if (CurrentButtonState && !WasAlreadyPressed)
	{
		ToBeToggled = !ToBeToggled;			//If Old Drive, switch to New Drive. If New Drive, switch to Old Drive
	}
	WasAlreadyPressed = CurrentButtonState;
}

void RangeCheck (int LowerLimit, int &Value, int UpperLimit)
{
	if (Value > UpperLimit)
	{
		Value = UpperLimit;
	}
	if (Value < LowerLimit)
	{
		Value = LowerLimit;
	}
}

int WasPressedOnce(int CurrentButtonState, int &WasAlreadyPressed)
{
  int Pressed = 0;
	if (CurrentButtonState && !WasAlreadyPressed)
		Pressed = 1;
	WasAlreadyPressed = CurrentButtonState;
	return Pressed;
}

int SlopeLimiter(int OldValue, int NewValue, int MaxStepSize)
{
  int Delta = NewValue - OldValue;
  if (Delta >     MaxStepSize) Delta =     MaxStepSize;
  if (Delta < 0 - MaxStepSize) Delta = 0 - MaxStepSize;
  return Delta;
}
