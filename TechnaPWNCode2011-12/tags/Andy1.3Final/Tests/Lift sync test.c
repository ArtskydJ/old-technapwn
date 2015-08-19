#pragma config(UART_Usage, UART2, VEX_2x16_LCD, baudRate1200, IOPins, None, None)
#pragma config(Sensor, in1,		Gyro,								 sensorGyro)
#pragma config(Sensor, dgtl3,	liftEncoder1,				sensorQuadEncoder)
#pragma config(Sensor, dgtl5,	liftEncoder2,				sensorQuadEncoder)
#pragma config(Sensor, dgtl11, Holonomic1,					sensorDigitalOut)
#pragma config(Sensor, dgtl12, Holonomic2,					sensorDigitalOut)
#pragma config(Motor,	port1,					 IntakeLF,			 tmotorNormal, openLoop)
#pragma config(Motor,	port2,					 IntakeRF,			 tmotorNormal, openLoop)
#pragma config(Motor,	port3,					 DriveLF,			 tmotorNormal, openLoop, reversed)
#pragma config(Motor,	port4,					 DriveRF,			 tmotorNormal, openLoop)
#pragma config(Motor,	port5,					 LiftL,				 tmotorNormal, openLoop, reversed)
#pragma config(Motor,	port6,					 LiftR,				 tmotorNormal, openLoop)
#pragma config(Motor,	port7,					 DriveLB,			 tmotorNormal, openLoop, reversed)
#pragma config(Motor,	port8,					 DriveRB,			 tmotorNormal, openLoop)
#pragma config(Motor,	port9,					 IntakeLB,			 tmotorNormal, openLoop)
#pragma config(Motor,	port10,					 IntakeRB,			 tmotorNormal, openLoop)

//-----------------------initialize--------------------------\\
typedef struct
{
	float Kp;
	float Ki;
	float Kd;
	float Integral;
	float Derivative;
	float Error;
	float LastError;
	float TargetValue;
	float Output;
} TPidSystem;

//-------------------------execute----------------------------\\

void PIDController(TPidSystem &PIDObject)
{
	PIDObject.Integral = ((2 / 3) * PIDObject.Integral) + PIDObject.Error;
	PIDObject.Derivative = PIDObject.Error - PIDObject.LastError;
	PIDObject.Output = (PIDObject.Error * PIDObject.Kp) + (PIDObject.Integral * PIDObject.Ki) +(PIDObject.Derivative * PIDObject.Kd);
	PIDObject.LastError = PIDObject.Error;
}


task main()
{
	TPidSystem PIDLift;
	PIDLift.Kp = 0.1;
	PIDLift.Ki = 0.001;
	PIDLift.Kd = 0.5;
	PIDLift.Integral = 0;
	PIDLift.Derivative = 0;
	PIDLift.Error = 0;
	PIDLift.LastError = 0;
	PIDLift.TargetValue = 0;
	PIDLift.Output = 0;

	while(vexRT[Btn8D] == 0)
	{
		PIDLift.Error = SensorValue[liftEncoder1] - SensorValue[liftEncoder2];
		PIDLift.TargetValue = vexRT[Ch3];
		PIDController(PIDLift);
		motor[port3] = PIDLift.TargetValue + PIDLift.Output;
		motor[port9] = PIDLift.TargetValue - PIDLift.Output;
		wait1Msec(10);
	}
}
