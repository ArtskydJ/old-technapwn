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

    wait1Msec(DISPLAYDELAYMS); //Release time to other tasks -- Display refresh rate 20hz
  } // </while(true)>
}

void DisplayMainMenu()
{
	TotalMenuItems = 7;
	if (DisplayNeedsRefreshing)
	{
		DisplayMenu("Main Menu", MainMenu[CurrentMenuItem]);
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
