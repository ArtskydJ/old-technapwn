//////////////////////
//  Operator.c      //
//  Joseph Dykstra  //
//  VRC team 3018   //
//////////////////////

//Constants
static const int JOYSTICK_DEAD_ZONE = 10;

//Variables
static int liftPresetIndex=0;

//Functions
bool joystickIsMoved()
	{
	return (abs(joyLYStk) > JOYSTICK_DEAD_ZONE ||
			abs(joyRXStk) > JOYSTICK_DEAD_ZONE ||
			abs(joyLXStk) > JOYSTICK_DEAD_ZONE);
	}

int joystickFilter(int INraw)
	{
	if (abs(INraw) < JOYSTICK_DEAD_ZONE) //Dead Zone
		INraw=0;
	INraw = capIntValue(REV, ((float)INraw*abs(INraw)/FWD), FWD); //Exponential function
	return (INraw);
	}

void processOperator(void)
	{
#ifdef ARCADE_DRIVE //Arcade drive
	targetLeft =	capIntValue(REV,joystickFilter(joyLYStk) + joystickFilter(joyRXStk), FWD);
	targetRight =	capIntValue(REV,joystickFilter(joyLYStk) - joystickFilter(joyRXStk), FWD);
	targetStrafe =					joystickFilter(joyLXStk);
#else //Tank drive
	targetLeft =					joystickFilter(joyLYStk);
	targetRight =					joystickFilter(joyRYStk);
	targetStrafe =  capIntValue(REV,joystickFilter(joyLXStk) - joystickFilter(joyRXStk), FWD);
#endif

#ifdef USE_LIFT_POT
	if (joyLiftUpBtn)         liftPresetIndex++;
	else if (joyLiftDownBtn)  liftPresetIndex--;
	else if (joyLiftUpBtn2)   liftPresetIndex++;
	else if (joyLiftDownBtn2) liftPresetIndex--;

	liftPresetIndex = capIntValue(0, liftPresetIndex, NO_L_PRES-1);
	targetLift = L_PRE[liftPresetIndex];
#else
	if (joyLiftUpBtn)         targetLift = UP;
	else if (joyLiftDownBtn)  targetLift = DOWN;
	else if (joyLiftUpBtn2)   targetLift = UP;
	else if (joyLiftDownBtn2) targetLift = DOWN;
	else                      targetLift = OFF;
#endif
	if (joyIntakeInBtn)         targetIntake = IN;
	else if (joyIntakeOutBtn)   targetIntake = OUT;
	else if (joyIntakeInBtn2)   targetIntake = IN;
	else if (joyIntakeOutBtn2)  targetIntake = OUT;
	else                        targetIntake = OFF;
	}
