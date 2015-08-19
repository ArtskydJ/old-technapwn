//////////////////////
//  LCD.c           //
//  Joseph Dykstra  //
//  VRC team 3018   //
//////////////////////

//Constants
static const string AUTO_STRINGS[NO_AUTOS] =
	{
	"NONE!!!",
	"Blue Hang Zone",
	"Red Hang Zone",
	"Blue Mid Zone",
	"Red Mid Zone"
	};

//Variables
static bool itemSelected = false;
static int menuItem = 0;
static int itemSelection[NO_MENU_ITEMS] = {0, 0, 0, 0, 0, 0};
static string LCDLine1, LCDLine2;

//Functions
#ifdef USE_AUTO_POT
	int potPosition(int INMaxVal)
		{
		int n = (float)INMaxVal*senAutoPot/4096;
		return capIntValue(0, n, INMaxVal-1);
		};
#endif


#ifdef USE_AUTO_POT
void LCDprocessInput(void)
	{
	//BUTTONS, ETC
	itemSelection[menuItem] = potPosition(noItemSelections[menuItem]-1);
	if (senLeftLCDBtn && !senLeftLCDBtnLast) //Left button pressed
		menuItem--;
	if (senRightLCDBtn && !senRightLCDBtnLast) //Right button pressed
		menuItem++;
	menuItem = capIntValue(0, menuItem, NO_MENU_ITEMS-1);
	}
#else
void LCDprocessInput(void)
	{
	//BUTTONS, ETC
	if (senCenterLCDBtn && !senCenterLCDBtnLast) //Center button pressed
		itemSelected = !itemSelected;

	if (!itemSelected) //MENU control
		{
		if (senLeftLCDBtn && !senLeftLCDBtnLast) //Left button pressed
			menuItem--;
		if (senRightLCDBtn && !senRightLCDBtnLast) //Left button pressed
			menuItem++;
		menuItem = capIntValue(0, menuItem, NO_MENU_ITEMS-1);
		}

	if (itemSelected) //ITEM control
		{
		if (senLeftLCDBtn && !senLeftLCDBtnLast) //Left button pressed
			itemSelection[menuItem]--;
		if (senRightLCDBtn && !senRightLCDBtnLast) //Right button pressed
			itemSelection[menuItem]++;
		itemSelection[menuItem] = capIntValue(0, itemSelection[menuItem], noItemSelections[menuItem]-1);
		}
	}
#endif

void LCDprocessOutput(void)
	{
	//DISPLAY
#ifndef USE_AUTO_POT
	sprintf(LCDLine1, " %s%s%d%s",
		menuItemStrings[menuItem],
		(itemSelection[menuItem]>0 && itemSelected)?"<":" ",
		itemSelection[menuItem]+1,
		(itemSelection[menuItem]<noItemSelections[menuItem]-1 && itemSelected)?">":" ");
#else
	sprintf(LCDLine1, "%s%d",
		menuItemStrings[menuItem],
		itemSelection[menuItem]+1);
#endif
	switch(menuItem)
		{
		case AUTO_SELECT: //Autos
			strcpy(LCDLine2, AUTO_STRINGS[itemSelection[menuItem]]);
			autoRoutine = itemSelection[menuItem];
			break;
		case DISABLE_MTRS: //En/Disable motors
			sysMotorsEnabled = !itemSelected;
			strcpy(LCDLine1, menuItemStrings[menuItem]);
			strcpy(LCDLine2, sysMotorsEnabled ? "Enabled":"Disabled");
			break;
		case SET_MODE:
			sysDisabledMode = (itemSelection[menuItem]==(short)DISABLED);
			sysAutonomousMode = (itemSelection[menuItem]==(short)AUTONOMOUS);
			strcpy(LCDLine2, menuModeStrings[itemSelection[menuItem]]);
			break;
		case BATT_VALUES: //Battery view
			sprintf(LCDLine2, "%1.3f", itemSelection[menuItem]==0 ?
				nAvgBatteryLevel/1000 : itemSelection[menuItem]==1 ?
				SensorValue(POW_EX_V)/70 : BackupBatteryLevel);
			break;
		case ANALOG_SENSORS: //Analog view
			sprintf(LCDLine2, "%d", SensorValue(itemSelection[menuItem]));
			break;
		case DIGITAL_SENSORS: //Digital view
			sprintf(LCDLine2, "%d", SensorValue(itemSelection[menuItem]+8));
			break;
		}
	}

void LCD(void)
	{
	LCDprocessInput();
	LCDprocessOutput();

	clearLCDLine(0);
	displayLCDCenteredString(0,LCDLine1);
	clearLCDLine(1);
	displayLCDCenteredString(1,LCDLine2);

#ifdef USE_AUTO_POT
	if (1) //If using the auto pot...
#else
	if (!itemSelected) //...or item is not selected...
#endif
		{
		if (menuItem>0) //... then display the arrows
			displayLCDChar(0,0,'<'); //display left arrow
		if (menuItem<(short)NO_MENU_ITEMS-1)
			displayLCDChar(0,15,'>'); //display right arrow
		}
	}





/*
line1 = lineones[curritem]
if menuactivated
	line2 = linetwosactivated[curritem]
else
	line2 = linetwosunactivated[curritem]

if center && !lastcenter
	menuactivated = !menuactivated

if menuactivated
	if left && !lastleft
		currnum[curritem]--
	if right && !lastright
		currnum[curritem]++
	currnum[curritem] capIntVal(0,currnum[curritem],idk)
		switch curritem
			{
			case 0: somethin(); break;
			case 1: somethin(); break;
			case 2: somethin(); break;
			}
*/
