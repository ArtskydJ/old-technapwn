float SlopeFilter(int MotorValue, int LastMotorValue, float SlopeLimit)
{
	int Delta = MotorValue-LastMotorValue;
	if (Delta >=  SlopeLimit) Delta =  SlopeLimit;
	if (Delta <= -SlopeLimit) Delta = -SlopeLimit;
	return Delta;
}


void LogEncoders()
{
	writeDebugStreamLine(
	"SenLeft:%d , SenRight:%d , nMotEncLeft:%d , nMotEncRight:%d",
	SensorValue(BackLeftEncoder), SensorValue(BackRightEncoder), nMotorEncoder[DriveBR], nMotorEncoder[DriveBL] );
}


void UpdateAutonomousRoutine()
{
	AutonomousRoutine = PotPosition(NumOfAutoRoutines);
	AutonomousRoutine++;
	CapValue(1, AutonomousRoutine, NumOfAutoRoutines);
}


void UpdateBatteryLevels()
{
	StringFormat(BatteryLevel[0],  "Main:%1.3f  ",  (float)nAvgBatteryLevel/1000);
	//StringFormat(BatteryLevel[1],  "PwrExp:%1.3f  ",(float)X/1000);
	StringFormat(BatteryLevel[1],  "Backup:%1.3f   ",(float)BackupBatteryLevel/1000);
}


bool JoystickCheck(bool CheckCh1) //Check if no buttons are pressed and the joysticks are in their "Dead Zones"
{
	bool ControlActivated = true;
	if(vexRT[Btn5D]		||vexRT[Btn5U]		||vexRT[Btn6D]		||vexRT[Btn6U])			ControlActivated = false;
	if(vexRT[Btn5DXmtr2]||vexRT[Btn5UXmtr2]	||vexRT[Btn6DXmtr2]	||vexRT[Btn6UXmtr2])	ControlActivated = false;
//	if(vexRT[Btn7U]		||vexRT[Btn7L]		||vexRT[Btn7D]		||vexRT[Btn7R])			ControlActivated = false;
//	if(vexRT[Btn7UXmtr2]||vexRT[Btn7LXmtr2]	||vexRT[Btn7DXmtr2]	||vexRT[Btn7RXmtr2])	ControlActivated = false;
//	if(vexRT[Btn8U]		||vexRT[Btn8L]		||vexRT[Btn8D]		||vexRT[Btn8R])			ControlActivated = false;
//	if(vexRT[Btn8UXmtr2]||vexRT[Btn8LXmtr2]	||vexRT[Btn8DXmtr2]	||vexRT[Btn8RXmtr2])	ControlActivated = false;
	if(sqrt(pow(vexRT[Ch4],     2) + pow(vexRT[Ch3],     2)) > JoystickDZ) ControlActivated = false;
	if(sqrt(pow(vexRT[Ch4Xmtr2],2) + pow(vexRT[Ch3Xmtr2],2)) > JoystickDZ) ControlActivated = false;
	if(CheckCh1 && sqrt(pow(vexRT[Ch1],     2))				 > JoystickDZ) ControlActivated = false;

	return ControlActivated;
}


int UpdatePIDController(TPID &PIDController, int Error)
{
	PIDController.Error = Error;
	PIDController.Integral = (PIDController.Integral * (3 / 4)) + PIDController.Error;
	PIDController.Derivative = PIDController.Error - PIDController.LastError;
	PIDController.LastError = PIDController.Error;
	PIDController.Output = ((float) PIDController.Error * PIDController.Kp) //Added float typecasting
						 + (PIDController.Integral * PIDController.Ki)
						 + (PIDController.Derivative * PIDController.Kd);
	return (PIDController.Output);
}
