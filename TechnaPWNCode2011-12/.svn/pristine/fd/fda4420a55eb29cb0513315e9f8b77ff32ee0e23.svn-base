int initializePID()
{
	PIDLift.Kp = 2;
	PIDLift.Ki = 1;
	PIDLift.Kd = 50.0;
	PIDLift.Integral = 0;
	PIDLift.Derivative = 0;
	PIDLift.Error = 0;
	PIDLift.LastError = 0;
	PIDLift.TargetValue = 0;
	PIDLift.TargetPower = 0;
	PIDLift.Output = 0;

	PIDGyro.Kp = .5;
	PIDGyro.Ki = 0;
	PIDGyro.Kd = 0.0;
	PIDGyro.Integral = 0;
	PIDGyro.Derivative = 0;
	PIDGyro.Error = 0;
	PIDGyro.LastError = 0;
	PIDGyro.TargetValue = 0;
	PIDGyro.TargetPower = 0;
	PIDGyro.Output = 0;
	return 0;
}

task UpdatePIDControllers()
{
  while(true)
  {
		PIDController(PIDLift);
		PIDController(PIDGyro);
		wait1Msec(PIDDELAYMS);
	}
}

void PIDController(TPidSystem &PIDObject)
{
	hogCPU();
	PIDObject.Integral = ((3 / 4) * PIDObject.Integral) + PIDObject.Error;
	if (PIDObject.Integral > INTEGRALCAP) PIDObject.Integral = INTEGRALCAP;
	if (PIDObject.Integral < 0-INTEGRALCAP) PIDObject.Integral = 0-INTEGRALCAP;
	PIDObject.Derivative = PIDObject.Error - PIDObject.LastError;
	PIDObject.Output = (PIDObject.Error * PIDObject.Kp) + (PIDObject.Integral * PIDObject.Ki) + (PIDObject.Derivative * PIDObject.Kd);
	PIDObject.LastError = PIDObject.Error;
	releaseCPU();
}
