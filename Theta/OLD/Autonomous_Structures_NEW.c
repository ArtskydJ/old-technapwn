//All of these 10's following, were 9's


void AutonomousControl() //No errors with this one :)
{
	int tempArray[10];
	if      (DriverMode == DriverSubPyramid && !IsRobotInAutonomousMode)
		for (int j=0; j<10; j++) {tempArray[j] = AutoPyramid[AutonomousStep][j];}
	else if (DriverMode == DriverSubDescore && !IsRobotInAutonomousMode)
		for (int j=0; j<10; j++) {tempArray[j] = AutoDescore[AutonomousStep][j];}
	else switch (AutonomousRoutine)
	{
		case 1: for (int j=0; j<10; j++) {tempArray[j] = auto01[AutonomousStep][j];} break; // Left Autonomous  bite with yellow								(scores 022 ideally)
		case 2: for (int j=0; j<10; j++) {tempArray[j] = auto02[AutonomousStep][j];} break; // Right Autonomous gets pyrimid and a yellow						(scores 040 ideally)
		case 3: for (int j=0; j<10; j++) {tempArray[j] = auto03[AutonomousStep][j];} break; // Left Autonomous  Scoop up wall, and bite with yellow			(scores 060 ideally)
		case 4: for (int j=0; j<10; j++) {tempArray[j] = auto04[AutonomousStep][j];} break; // Right Autonomous gets pyramid, bite and preload				(scores 045 ideally)
//		case 5: for (int j=0; j<10; j++) {tempArray[j] = auto05[AutonomousStep][j];} break;
		case 6: for (int j=0; j<10; j++) {tempArray[j] = auto06[AutonomousStep][j];} break; // Right Autonomous gets pyramid, bite and preload, then descores	(scores 045  ideally)
//		case 7: for (int j=0; j<10; j++) {tempArray[j] = auto07[AutonomousStep][j];} break;
		case 8: for (int j=0; j<10; j++) {tempArray[j] = auto08[AutonomousStep][j];} break; // Right Autonomous Skills										(Scores 240 ideally)
		case 9: for (int j=0; j<10; j++) {tempArray[j] = auto09[AutonomousStep][j];} break; // Right Autonomous Skills										(Scores 175 ideally)
		default: //nothing
	}
	AutonomousStructure(tempArray);
}
