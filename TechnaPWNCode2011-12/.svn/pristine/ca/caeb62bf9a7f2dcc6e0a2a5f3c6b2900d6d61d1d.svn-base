task display_handler()
{
	//Initialization code

	//Main Display Loop
	//This should be able to hold the contents of whatever is on the display, be able to 'hook into'
	//stuff that
	wait1Msec(100); // Wait for program to initialize

	while(true)
	{
		if (DisplayState == DISPLAYMENU)
		{
			switch(CurrentMenu)
			{
			case 1:   //Start Autonomous
				DisplayState = DISPLAYDISABLED;
				CurrentMenu = 0;
				StopTask(usercontrol);
				StartTask(autonomous);
				break;
			case 2:   //Pick Autonomous
				DisplayState = DISPLAYDISABLED;
				StartTask(pick_autonomous);
				break;
			case 3:
				DisplayState = DISPLAYDISABLED;
				CurrentMenu = 0;
				StopTask(usercontrol);
				StartTask(motor_test);
				break;
			case 4:
				DisplayState = DISPLAYDISABLED;
				StartTask(show_variables);
				break;
			case 5:
				DisplayState = DISPLAYDISABLED;
				StartTask(settings_menu);
				break;

			default:
				DisplayMainMenu();
				break;
			} // </switch(CurrentMenu)>
		}
		else if (DisplayState == DISPLAYDISABLED)
		{
		} // </if (DisplayState == DISPLAYMENU)>

		switch (DisplayBacklightState)
		{
			case BACKLIGHTON:
				bLCDBacklight = true;
				break;
			case BACKLIGHTFASTBLINK:
				if ((nPgmTime/100.0) - LastBacklightBlink100Msec > FASTBACKLIGHTBLINKDELAY100MSEC)
				{
					bLCDBacklight = !bLCDBacklight;
					LastBacklightBlink100Msec = (nPgmTime/100.0);
				}
				break;
			case BACKLIGHTSLOWBLINK:
				if ((nPgmTime/100.0) - LastBacklightBlink100Msec > SLOWBACKLIGHTBLINKDELAY100MSEC)
				{
					bLCDBacklight = !bLCDBacklight;
					LastBacklightBlink100Msec = (nPgmTime/100.0);
				}
				break;
			case BACKLIGHTOFF:
				bLCDBacklight = false;
				break;
		}

		wait1Msec(DISPLAYDELAYMS); //Release time to other tasks -- Display refresh rate 20hz
	} // </while(true)>
}

void DisplayMainMenu()
{
	string MainBatteryVoltageString = "";
	if (time1[T3] > 100)
	{
		DisplayNeedsRefreshing = 1;
		ClearTimer(T3);
	}

	TotalMenuItems = 7;
	if (DisplayNeedsRefreshing)
	{
		StringFormat(MainBatteryVoltageString, "%1.2f", MainBatteryVoltageLevel/1000.0);
		//DisplayMenu("Main Menu", MainMenu[CurrentMenuItem]);
		displayLCDString(0, 0, "Main Bat:      v");
		displayLCDString(0, 11, MainBatteryVoltageString);
		displayLCDCenteredString(1, MainMenu[CurrentMenuItem]);
		DisplayNeedsRefreshing = 0;
	}
	DisplayButtonHandling();
	if (IsMenuItemActivated())
	{
		CurrentMenu = CurrentMenuItem + 1;
	}
}

void DisplayMenu(string MenuTitle, string MenuItem)
{
	clearLCDLine(0);
	clearLCDLine(1);
	displayLCDCenteredString(0, MenuTitle);
	displayLCDCenteredString(1, MenuItem);
}

void DisplayButtonHandling()
{
	if (LeftDisplayButton && !LeftDisplayButtonPressed && CurrentMenuItem > 0)
	{
		CurrentMenuItem--;
		DisplayNeedsRefreshing = 1;
	}
	LeftDisplayButtonPressed = LeftDisplayButton;
	if (RightDisplayButton && !RightDisplayButtonPressed && CurrentMenuItem < TotalMenuItems - 1)
	{
		CurrentMenuItem++;
		DisplayNeedsRefreshing = 1;
	}
	RightDisplayButtonPressed = RightDisplayButton;
	if (CenterDisplayButton && !CenterDisplayButtonPressed)
	{
		ActivateMenuItem = 1;
		DisplayNeedsRefreshing = 1;
	}
	CenterDisplayButtonPressed = CenterDisplayButton;
}
