//////////////////////
//  OtherFuncs.c    //
//  Joseph Dykstra  //
//  VRC team 3018   //
//////////////////////

//Constants
static const int MIN_LOOP_MS = 15; //Motor updates are ~15 ms apart

//Variables
static int sysLooptime;


//Functions
void nextLoopIteration()
	{
	sysLooptime=time1[T4];
	while (time1[T4] < MIN_LOOP_MS)
		{}
	ClearTimer(T4);
	}

int capIntValue(int min, int value, int max)
	{
	if (value<min) value = min;
	if (value>max) value = max;
	return value;
	}

int updatePIDController(T_PID &INPID, int INerror)
	{
	INPID.error = INerror;
	INPID.integral = (INPID.integral * 4 / 5) + INPID.error;
	INPID.derivative = INPID.error - INPID.errorLast;
	INPID.errorLast = INPID.error;
	INPID.output = (float)(INPID.error      * INPID.kp)
						+ (INPID.integral   * INPID.ki)
						+ (INPID.derivative * INPID.kd);
	return (INPID.output);
	}
