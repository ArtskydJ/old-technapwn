//////////////////////
//  Autonomous.c    //
//  Joseph Dykstra  //
//  VRC team 3018   //
//////////////////////

//Constants
static const int PID_WAIT_MS = 300;
static const int PID_ZONE = 20;

//Variables
static T_PID PIDLift;
static T_PID PIDGyro;
static T_PID PIDDriveL;
static T_PID PIDDriveR;
static T_PID PIDStrafe;

static int autoStep;
static int autoStepCheck;
static int autoClockRunning = true;
static int autoFoundLeft = false;
static int autoFoundRight = false;
static int autoDriveReady = false;
static int autoLiftReady = false;
static int autoIntkReady = false;

static T_HIT autoHitTarget=NOT_HIT;

//Functions
void autoNextStep(void)
	{
	string msg1, msg2;
	if (autoStep)
		{
		if (time1(T1)<100)
			writeDebugStreamLine(msg1,"|%d\t\t|%d\t|",time1(T1),autoStep);
		else
			writeDebugStreamLine(msg1,"|%d\t|%d\t|",time1(T1),autoStep);
		}

	autoClockRunning = true;
	autoFoundLeft = false;
	autoFoundRight = false;
	autoDriveReady = false;
	autoLiftReady = false;
	autoIntkReady = false;
	autoStep++;
	senGyro = 0;
	autoHitTarget=NOT_HIT;
#ifdef USE_ENCODERS
	senLeftEnc = 0;
	senRightEnc = 0;
	nMotorEncoder[LEFT_ENC] = 0;
	nMotorEncoder[RIGHT_ENC] = 0;
#endif
	//setAutoStepsStarts();
	ClearTimer(T1);
	//beep
	}

void autoResetStart(int INjumpToStep)
	{
	if (autoStepCheck==autoStep)
		{
		writeDebugStreamLine("+---------------+");
		writeDebugStreamLine("|Routine: %d\t\t|",autoRoutine);
		writeDebugStreamLine("+-----------+---+");

		autoNextStep();
		if (INjumpToStep>=2)
			{
			autoStep=INjumpToStep;
			writeDebugStreamLine("Skip to\t|%d\t|",INjumpToStep);
			}
		timerAuto = 0;
		}
	autoStepCheck++;
	}


void auto(int INleft, int INright, int INstrafe, int INlift, int INintake, T_END INendType, int INtarget)
	{
	if (autoStepCheck==autoStep)
		{
		//--Set Outputs--//
		targetLeft = INleft;
		targetRight = INright;
		targetStrafe = INstrafe;

		autoDriveReady = (abs(targetLeft) < PID_ZONE &&
						abs(targetRight) < PID_ZONE &&
						abs(targetStrafe) < PID_ZONE);

		targetLift = INlift;
		if (abs(INlift)<=127)
			autoLiftReady = true;
		else if (abs(PIDLift.error) < PID_ZONE)
			autoLiftReady = true;
		targetIntake = INintake;

#ifdef USE_GYROSCOPE
		if (targetStrafe != 0)
			{
			updatePIDController(PIDGyro, senGyro);
			targetLeft -= PIDGyro.output;
			targetRight += PIDGyro.output;
			}
#endif

		if (autoHitTarget==NOT_HIT)
			{
			ClearTimer(T2); //Timer for PID wait
			switch(INendType) // This code asks "What type of target condition are we looking for? Have we met it?"
				{
				case TIME: if (time1(T1)>=INtarget)			autoHitTarget = HIT_NEXT; break;
				case LIFT_READY: if (autoLiftReady)			autoHitTarget = HIT_NEXT; break;
				case DRIV_READY: if (autoDriveReady)		autoHitTarget = HIT_PID; break;
				case FULL_READY: if (autoDriveReady && autoLiftReady) autoHitTarget = HIT_PID; break;
				case LCD_BTN: if ((nLCDButtons>0) == INtarget) autoHitTarget = HIT_NEXT; break;
				}
			}
		if ((autoHitTarget==HIT_PID && time1(T2)>=PID_WAIT_MS) || //PID timeout after hit...
			autoHitTarget==HIT_NEXT) //...OR was just hit...
			autoNextStep(); //...Go to the next step
		}
	autoStepCheck++;
	}


void autoResetEnd(void)
	{
	if (autoStepCheck==autoStep)
		{
		zeroMotors();

		writeDebugStreamLine("+-----------+---+");
		writeDebugStreamLine("|Time: %.1f\t\t|",((float)timerAuto/1000));
		writeDebugStreamLine("+---------------+");
		autoClockRunning = false;
		autoRoutine = 0;
		sysAutonomousMode = false;
#ifdef FULL_DEBUG_STREAM
		writeDebugStreamLine("autoResetEnd");
#endif
		}
	}

void processAutonomous(void)
	{
	switch (autoRoutine)
		{
		case 00: break; //No autonomous Routine
		case 01: autoBlueHangingZone(); break;
		case 02: autoRedHangingZone(); break;
		case 03: autoBlueMiddleZone(); break;
		case 04: autoRedMiddleZone(); break;
		}
	}
