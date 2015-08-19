#pragma config(UART_Usage, UART2, VEX_2x16_LCD, baudRate1200, IOPins, None, None)
#pragma config(Motor,  port1,           IntakeLF,      tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port2,           IntakeRF,      tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port3,           DriveLF,       tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port4,           DriveRF,       tmotorNormal, openLoop)
#pragma config(Motor,  port5,           LiftL,         tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port6,           LiftR,         tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port7,           DriveLB,       tmotorNormal, openLoop, reversed)
#pragma config(Motor,  port8,           DriveRB,       tmotorNormal, openLoop)
#pragma config(Motor,  port9,           IntakeLB,      tmotorNormal, openLoop)
#pragma config(Motor,  port10,          IntakeRB,      tmotorNormal, openLoop)
#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

typedef enum
{
	NORMAL,
	REVERSED
} TRobotDirection;

int btnFrontBackDrivePressed;
int btnFrontBackDrive;
int bFrontBackDrive;
int motorLeftFrontDrive;
int motorLeftBackDrive;
int motorRightFrontDrive;
int motorRightBackDrive;

void ToggleCheck (int CurrentButtonState, int &WasAlreadyPressed, int &ToBeToggled)
{
	if (CurrentButtonState && !WasAlreadyPressed)
	{
		ToBeToggled = !ToBeToggled;			//If Old Drive, switch to New Drive. If New Drive, switch to Old Drive
	}
	WasAlreadyPressed = CurrentButtonState;
}

void pre_auton()
{
}

task autonomous()
{
	AutonomousCodePlaceholderForTesting();  // Remove this function call once you have "real" code.
}


task usercontrol()
{
	//Create "deadzone" variables. Adjust threshold value to increase/decrease deadzone
	int X2 = 0, Y1 = 0, X1 = 0, threshold = 15;

	//Loop Forever
	while(1 == 1)
	{
	btnFrontBackDrive = vexRT[Btn8U];
	ToggleCheck(btnFrontBackDrive, btnFrontBackDrivePressed, bFrontBackDrive);

	//Create "deadzone" for Y1/Ch3
	if(abs(vexRT[Ch3]) > threshold)
	Y1 = vexRT[Ch3];
	else
	Y1 = 0;
	//Create "deadzone" for X1/Ch4
	if(abs(vexRT[Ch4]) > threshold)
	X1 = vexRT[Ch4];
	else
	X1 = 0;
	//Create "deadzone" for X2/Ch1
	if(abs(vexRT[Ch1]) > threshold)
	X2 = vexRT[Ch1];
	else
	X2 = 0;

	//Remote Control Commands
	motorLeftFrontDrive = Y1 + X1 + X2;
	motorLeftBackDrive =  Y1 + X1 - X2;
	motorRightFrontDrive = Y1 - X1 - X2;
	motorRightBackDrive =  Y1 - X1 + X2;


	if(bFrontBackDrive)
		{
			motor[DriveRB] = 0 - motorLeftFrontDrive;
			motor[DriveRF] = 0 - motorLeftBackDrive;
			motor[DriveLB] = 0 - motorRightFrontDrive;
			motor[DriveLF] = 0 - motorRightBackDrive;
		}
		else
		{
			motor[DriveLF] = motorLeftFrontDrive;
			motor[DriveLB] = motorLeftBackDrive;
			motor[DriveRF] = motorRightFrontDrive;
			motor[DriveRB] = motorRightBackDrive;
		}
	}
}
