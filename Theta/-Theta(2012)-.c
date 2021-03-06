#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, in1,    SpatulaPotentiometer, sensorNone)
#pragma config(Sensor, in2,    LiftPotentiometer, sensorPotentiometer)
#pragma config(Sensor, in3,    AutoSelector,   sensorPotentiometer)
#pragma config(Sensor, in4,    RightLineFollower, sensorLineFollower)
#pragma config(Sensor, in5,    LeftLineFollower, sensorLineFollower)
#pragma config(Sensor, in6,    LeftLineEdgeDetector, sensorLineFollower)
#pragma config(Sensor, in7,    Gyro,           sensorGyro)
#pragma config(Sensor, in8,    RightLineEdgeDetector, sensorLineFollower)
#pragma config(Sensor, dgtl1,  BackRightQuad,  sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  ConveyerSwitch, sensorTouch)
#pragma config(Sensor, dgtl4,  BackSideUltrasonic, sensorSONAR_mm)
#pragma config(Sensor, dgtl6,  LeftSideUltrasonic, sensorSONAR_mm)
#pragma config(Sensor, dgtl9,  BackLeftQuad,   sensorQuadEncoder)
#pragma config(Sensor, dgtl11, RightSideUltrasonic, sensorSONAR_mm)
#pragma config(Sensor, I2C_1,  BackRightEncoder, sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  BackLeftEncoder, sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port1,           DriveBR,       tmotorVex393HighSpeed, openLoop, reversed, encoder, encoderPort, I2C_1, 1000)
#pragma config(Motor,  port2,           DriveFR,       tmotorVex393HighSpeed, openLoop, reversed)
#pragma config(Motor,  port3,           Conveyor,      tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port4,           LiftR,         tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port5,           DriveBL,       tmotorVex393HighSpeed, openLoop, encoder, encoderPort, I2C_2, 1000)
#pragma config(Motor,  port6,           SpatulaR,      tmotorVex393, openLoop)
#pragma config(Motor,  port7,           SpatulaL,      tmotorVex393, openLoop)
#pragma config(Motor,  port8,           Descorer,      tmotorVex269, openLoop, reversed)
#pragma config(Motor,  port9,           DriveFL,       tmotorVex393, openLoop)
#pragma config(Motor,  port10,          LiftL,         tmotorVex393HighSpeed, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	Hello there! Welcome to the programming that makes the robot work well. This is where all of intructions for the motors and	//
//	sensors are located. A portion of this code was formed from another robot; FILSS. It was mostly created by Josiah Krutz and	//
//	Ryan Plummer with contributions by Joseph Dykstra. Below, the different files of the code are included so that they can be 	//
//	referenced when needed but they do not clutter up the main file.															//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
//#define LOGENCODERS
#define COMPETITION //Comment this out to allow the pc simulator
//#define ET

#include "Definitions_and_Declarations.c"
#include "Other_Functions.c"
#include "Driver_Control.c"
#include "Input_and_Output.c"
#include "LCD.c"
	#ifndef ET
#include "Driver_Autos.c"
#include "Auto01HighSpeed.c"
#include "Auto02HighSpeed.c"
#include "Auto03HighSpeed.c"
#include "Auto04HighSpeed.c"
#include "Auto05HighSpeed.c" //Test Autonomous
#include "Auto06HighSpeed.c"
#include "Auto07HighSpeed.c"
#include "Auto08HighSpeed.c"
#include "Auto09HighSpeed.c"
	#else
#include "etAutos2.c"
	#endif
#include "Autonomous_Structures_NEW.c"
#include "Initialization.c"


//Here, the distinctions between the autonomous personality and driver personality is defined.
task main()
{
	InitializeLCDScreen();
	InitializePIDControllers();
	InitializeDebugStream();
	InitializeTimers();
	InitializeEncoders();
	SenAutoPot = SensorValue(AutoSelector);
	UpdateAutonomousRoutine();
	while(true)
	{
		Input();
		if(!IsRobotDisabled) //Simulation Allowed but Competiton still works if defined
		{
			if (IsRobotInAutonomousMode || IsRobotInVirtualAutonomousMode ||
				(DriverMode != DriverJoystickControl && DriverMode != DriverMotorTest))
			{
				AutonomousControl();
				UpdateScreen(DispAutonomousMode);
				#ifdef LOGENCODERS
					LogEncoders();
				#endif
				if (!IsRobotInAutonomousMode)
					if (!JoystickCheck(true))
						IsRobotInVirtualAutonomousMode = false;
			}
			else
			{
				AutonomousStep=0;
				UpdateAutonomousRoutine();
				UpdateScreen(DispDriverMode);
				if (DriverMode == DriverJoystickControl)
				{
					AutonomousReset(Finish);
					SubroutineCheck();
					DriveControl();
					IntakeControl();
					LiftControl();
					DescorerControl();
				}
				else if (DriverMode == DriverMotorTest)
				{
					if (!JoystickCheck(false))
						DriverMode = DriverJoystickControl;
				}
			}
		}
		else
		{
			AutonomousStep=0;
			AutonomousReset(Finish);
			UpdateAutonomousRoutine();
			UpdateScreen(DispDisabledMode);
		}
		Output();
		MainNonDelayedLoopTime = time1[T4];
		while (time1[T4] < MinLoopMS) {}
		MainLoopTime = time1[T4];
		ClearTimer(T4);
	}
}
