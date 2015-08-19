//////////////////////
//  Initialize.c    //
//  Joseph Dykstra  //
//  VRC team 3018   //
//  2013-11-25      //
//////////////////////

void initialize(void)
	{
#ifdef USE_ENCODERS
	nMotorEncoder[LEFT_ENC] = 0;
	nMotorEncoder[RIGHT_ENC] = 0;
#endif

	zeroMotors();
	bLCDBacklight = true;
	writeDebugStreamLine("================");

	noItemSelections[AUTO_SELECT] = NO_AUTOS;
	noItemSelections[DISABLE_MTRS] = 1;
	noItemSelections[SET_MODE] = 3;
	noItemSelections[BATT_VALUES] = 3;
	noItemSelections[ANALOG_SENSORS] = 8;
	noItemSelections[DIGITAL_SENSORS] = 12;

	menuModeStrings[DISABLED] = "Disabled";
	menuModeStrings[AUTONOMOUS] = "Autonomous";
	menuModeStrings[OPERATOR] = "Operator";

	menuItemStrings[AUTO_SELECT] = "Routine:";
	menuItemStrings[DISABLE_MTRS] = "Motors:";
	menuItemStrings[SET_MODE] = "Set mode:";
	menuItemStrings[BATT_VALUES] = "Battery:";
	menuItemStrings[ANALOG_SENSORS] = "Analog:";
	menuItemStrings[DIGITAL_SENSORS] = "Digital:";
	}
