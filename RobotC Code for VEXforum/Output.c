//////////////////////
//  Output.c        //
//  Joseph Dykstra  //
//  VRC team 3018   //
//////////////////////

//Constants
static const int SLEW_DRIVE = 4;
static const int SLEW_LIFT = 6;
static const int SLEW_INTAKE = 12;
static int motorTarget[10];
static int motorSlewed[10];


//Functions
void zeroMotors(void)
	{
	targetLift = 0;
	targetIntake = 0;
	targetLeft = 0;
	targetRight = 0;
	targetStrafe = 0;
	for (int j=0; j<10; j++)
		motorTarget[j] = 0;
	}

int slew(int INtarget, int INlast, int INslew)
	{
	int result = INtarget;
	if (result>INlast+INslew) result = INlast+INslew;
	if (result<INlast-INslew) result = INlast-INslew;
	return result;
	}

void output(void)
	{
#ifndef ENABLE_STRAFING
	targetStrafe = 0;
#endif
	if (sysMotorsEnabled)
		{
		motor[DRV_F_L] =  slew(targetLeft  + targetStrafe, motorSlewed[DRV_F_L],  SLEW_DRIVE);
		motor[DRV_B_L] =  slew(targetLeft  - targetStrafe, motorSlewed[DRV_B_L],  SLEW_DRIVE);
		motor[DRV_F_R] =  slew(targetRight - targetStrafe, motorSlewed[DRV_F_R],  SLEW_DRIVE);
		motor[DRV_B_R] =  slew(targetRight + targetStrafe, motorSlewed[DRV_B_R],  SLEW_DRIVE);
		motor[LIFT_L_1] = slew(targetLift,                 motorSlewed[LIFT_L_1], SLEW_LIFT);
		motor[LIFT_L_2] = slew(targetLift,                 motorSlewed[LIFT_L_2], SLEW_LIFT);
		motor[LIFT_R_1] = slew(targetLift,                 motorSlewed[LIFT_R_1], SLEW_LIFT);
		motor[LIFT_R_2] = slew(targetLift,                 motorSlewed[LIFT_R_2], SLEW_LIFT);
		motor[INTAKE_1] = slew(targetIntake,               motorSlewed[INTAKE_1], SLEW_INTAKE);
		motor[INTAKE_2] = slew(targetIntake,               motorSlewed[INTAKE_2], SLEW_INTAKE);
		}
	else
		zeroMotors();
	}
