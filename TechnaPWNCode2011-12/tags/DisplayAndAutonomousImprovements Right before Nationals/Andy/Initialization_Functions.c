//---------------------------------------------< Initialize >---------------------------------------------------\\
void initializeTimers()
{
	ClearTimer(T1);
	ClearTimer(T2);
}

int initializeDisplay()
{
	//clearLCDLine(0);
    //clearLCDLine(1);
    bLCDBacklight = true;							//Turn Backlight on
	displayLCDPos(1, 0);							//Move "Cursor" to first spot
	displayNextLCDString("Ready to PWN :-D");		//Display motivational message
	return 0;
}

int initializeGyro()
{
	//Completely clear out any previous sensor readings by setting the port to "sensorNone"
	SensorType[Gyro] = sensorNone;
	wait1Msec(1000);
	//Reconfigure Gyro port as a Gyro sensor and allow time for ROBOTC to calibrate it
	SensorType[Gyro] = sensorGyro;
	SensorFullCount[Gyro] = 7200; //Increase our available range of motion
	wait1Msec(2000);

	return 0;
}

int initializeAutonomous()
{
  SensorValue[LiftEncoderPort] = 0;
 	AutonomousStep = 0;
	ReadyForNextAutonomousStep = 1;
 	PIDGyro.Integral = 0;

 	TAutonomousState AutonomousState = SETUPSTEP;
  return 0;
}

int initializeOperator()
{
 	return 0;
}
