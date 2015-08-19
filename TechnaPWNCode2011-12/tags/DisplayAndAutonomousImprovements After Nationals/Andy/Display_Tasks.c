task pick_autonomous()
{
  LockInAutonomous = 0;
	TotalMenuItems = NumOfAutonomusRoutines;
  CurrentMenuItem = AutonomousRoutine;
  while(!LockInAutonomous)
  {
		if (DisplayNeedsRefreshing)
		{
			DisplayMenu("Pick Autonomous", AutonomousMenu[CurrentMenuItem]);
			DisplayNeedsRefreshing = 0;
		}
		DisplayButtonHandling();
		if (IsMenuItemActivated())
		{
			AutonomousRoutine = CurrentMenuItem;
			initializeAutonomousArray(AutonomousRoutine);
			CurrentMenuItem = 0;
			CurrentMenu = 0;
			LockInAutonomous = 1;
		}
		wait1Msec(DISPLAYDELAYMS); //Release time to other tasks -- Display refresh rate 20hz
	}
	DisplayState = DISPLAYMENU;
	while(nLCDButtons); // Wait for all buttons to be released
}

task motor_test()
{
  int MotorNumber1 = 4;
	int ButtonBitMap = nLCDButtons;
	int LeftDisplayButton1;
	int CenterDisplayButton1 = 0;
  int RightDisplayButton1;
  int LeftJoystickButton1;
  int RightJoystickButton1;
  int LeftDisplayButton2;
  int RightDisplayButton2;
  int LeftJoystickButton2;
  int RightJoystickButton2;
  int LeftDisplayButtonPressed1;
  int RightDisplayButtonPressed1;
  int LeftJoystickButtonPressed1;
  int RightJoystickButtonPressed1;
  int LeftDisplayButtonPressed2;
  int RightDisplayButtonPressed2;
  int LeftJoystickButtonPressed2;
  int RightJoystickButtonPressed2;
  allMotorsOff();
  displayLCDString(0, 0, "Motor           ");
  displayLCDNumber(1, 0, MotorNumber1);
  while (!CheckJoystick())
	{
		ButtonBitMap = nLCDButtons;
	  LeftDisplayButton1 = (ButtonBitMap & 1) && 1;
	  CenterDisplayButton1 = (ButtonBitMap & 2) && 1;
	  RightDisplayButton1 = (ButtonBitMap & 4) && 1;
	  LeftJoystickButton1 = vexRT[Btn8L];
	  RightJoystickButton1 = vexRT[Btn8R];

		if ((WasPressedOnce(LeftJoystickButton1, LeftJoystickButtonPressed1) || WasPressedOnce(LeftDisplayButton1, LeftDisplayButtonPressed1)) && MotorNumber1 > 1)
		{
		  MotorNumber1--;
		  clearLCDLine(1);
		  displayLCDNumber(1, 0, MotorNumber1);
		}
		if ((WasPressedOnce(RightJoystickButton1, RightJoystickButtonPressed1) || WasPressedOnce(RightDisplayButton1, RightDisplayButtonPressed1)) && MotorNumber1 < 10)
		{
		  MotorNumber1++;
		  clearLCDLine(1);
		  displayLCDNumber(1, 0, MotorNumber1);
		}
		if (vexRT[Btn5U])
			motor[MotorNumber1 - 1] = 127;
		else if (vexRT[Btn5D])
			motor[MotorNumber1 - 1] = -127;
		else
			motor[MotorNumber1 - 1] = 0;
	  wait1Msec(DISPLAYDELAYMS); //Release time to other tasks -- Display refresh rate 20hz
  }
  DisplayState = DISPLAYMENU;
  StartTask(usercontrol);
}

task show_variables()
{
	TotalMenuItems = 8;
  CurrentMenuItem = 0;
  float VariableValue = 0;
  string VariableMenu[8] = {"MainBatteryLvl", "LiftEncoder", "stkDriveX", "stkDriveY", "stkDriveS", "gyrGyroscope", "LoadedAutonomous", "BtmLftLiftSwitch"};
  while(true)
  {
		if (DisplayNeedsRefreshing)
		{
		  clearLCDLine(0);
	    displayLCDCenteredString(0, VariableMenu[CurrentMenuItem]);
			DisplayNeedsRefreshing = 0;
		}
    clearLCDLine(1);
    if (CurrentMenuItem == 0)
		  VariableValue = (float) MainBatteryVoltageLevel;
		else if (CurrentMenuItem == 1)
		  VariableValue = (float) LiftEncoder;
		else if (CurrentMenuItem == 2)
		  VariableValue = (float) stkDriveX;
		else if (CurrentMenuItem == 3)
		  VariableValue = (float) stkDriveY;
		else if (CurrentMenuItem == 4)
		  VariableValue = (float) stkDriveS;
		else if (CurrentMenuItem == 5)
		  VariableValue = (float) gyrGyroscope;
		else if (CurrentMenuItem == 6)
		  VariableValue = (float) AutonomousRoutine;
		else if (CurrentMenuItem == 7)
		  VariableValue = (float) BottomLeftLiftLimitSwitch;

    displayLCDNumber(1, 4, VariableValue);
		DisplayButtonHandling();
		if (IsMenuItemActivated())
		{
		  break;
		}
		wait1Msec(DISPLAYDELAYMS); //Release time to other tasks -- Display refresh rate 20hz
	}
	CurrentMenuItem = 0;
	CurrentMenu = 0;
	DisplayState = DISPLAYMENU;
	while(nLCDButtons); // Wait for all buttons to be released
}

task settings_menu()
{
  int NumberOfSettings = 6;
  int VariableIndex = 0;
  float VariablePrecision = 1;
  TotalMenuItems = NumberOfSettings;
  CurrentMenuItem = 0;
  TSettingsMenuMode SettingsMenuMode = CHOOSINGSETTING;
  bool UseEnumStrings;
  string SettingsMenu[6] = {"AutonAdvanceMode", "EnableOutput", "PIDLift.Kp", "PIDLift.Ki", "PIDLift.Kd", "Back"};
  string VariableEnumMenu[10];
  while(true)
  {
    if (SettingsMenuMode == CHOOSINGSETTING)
    {
			if (DisplayNeedsRefreshing)
			{
				DisplayMenu("Settings", SettingsMenu[CurrentMenuItem]);
				DisplayNeedsRefreshing = 0;
			}
			DisplayButtonHandling();
			if (IsMenuItemActivated())
			{
			  VariableIndex = CurrentMenuItem;
			  SettingsMenuMode = EDITINGSETTING;
			  if (VariableIndex == 0)
			  {
			    UseEnumStrings = true;
			    TotalMenuItems = 2;
			    VariableEnumMenu[0] = "AUTOADVANCE";
			    VariableEnumMenu[1] = "MANUALADVANCE";
			    CurrentMenuItem = AutonomousAdvanceMode;
			  }
			  else if (VariableIndex == 1)
			  {
			    UseEnumStrings = true;
			    TotalMenuItems = 2;
			    VariableEnumMenu[0] = "No";
			    VariableEnumMenu[1] = "Yes";
 			    CurrentMenuItem = EnableOutput;
			  }
			  else if (VariableIndex == 2)
			  {
			    UseEnumStrings = false;
			    VariablePrecision = .1;
 			    CurrentMenuItem = PIDLift.Kp;
			  }
			  else if (VariableIndex == 3)
			  {
			    UseEnumStrings = true;
			    TotalMenuItems = 2;
			    VariableEnumMenu[0] = "No";
			    VariableEnumMenu[1] = "Yes";
 			    CurrentMenuItem = PIDLift.Ki;
			  }
			  else if (VariableIndex == 4)
			  {
			    UseEnumStrings = true;
			    TotalMenuItems = 2;
			    VariableEnumMenu[0] = "No";
			    VariableEnumMenu[1] = "Yes";
 			    CurrentMenuItem = PIDLift.Kd;
			  }
			  else if (VariableIndex == 5)
			  {
			    break;
			  }
			}
    }
    else if(SettingsMenuMode == EDITINGSETTING)
    {
	    if (DisplayNeedsRefreshing)
			{
			  clearLCDLine(0);
	      clearLCDLine(1);
		    displayLCDCenteredString(0, SettingsMenu[VariableIndex]);
	      if (UseEnumStrings)
	        displayLCDCenteredString(1, VariableEnumMenu[CurrentMenuItem]);
	      else
	        displayLCDNumber(1, 4, CurrentMenuItem);
	      DisplayNeedsRefreshing = 0;
			}
			DisplayButtonHandling();
			if (IsMenuItemActivated())
			{
			  if (VariableIndex == 0)
			    AutonomousAdvanceMode = (TAutonomousAdvanceMode) CurrentMenuItem;
			  else if (VariableIndex == 1)
 			    EnableOutput = CurrentMenuItem;

			  TotalMenuItems = NumberOfSettings;
	      SettingsMenuMode = CHOOSINGSETTING;
			}
    }
		wait1Msec(DISPLAYDELAYMS); //Release time to other tasks -- Display refresh rate 20hz
	}
	CurrentMenuItem = 0;
	CurrentMenu = 0;
	DisplayState = DISPLAYMENU;
	while(nLCDButtons); // Wait for all buttons to be released
}
