const int AutoDescore[][]={
{0,		0,		0,		0,		0,		0,		0,		0,		NoDriving,	ResetAuto},
{GLPos,	0,		0,		0,		Rev,	Rev,	0,		-300,	DriveNorm,	EncodStra},  //straif left and drive forward
{GLPos,	0,		0,		Down,	0,		0,		0,		500,	DriveNorm,	TimeLimit},  //straif left and drive forward
{GLPos,	0,		0,		-50,	Rev,	Rev,	0,		-400,	DriveNorm,	EncodStra},  //straif left and drive forward
{GLPos,	0,		0,		-50,	-75,	-75,	0,		-300,	DriveNorm,	EncodStra},  //straif left and drive forward
{GLPos,	0,		0,		Up,		Fwd,	Fwd,	0,		550,	DriveNorm,	EncodStra},
{0,		0,		0,		0,		0,		0,		0,		0,		NoDriving,	ResetAuto}}; //straif left and drive forward
//Lift,Conveyor,Spatula,Descorer,Leftd,Rightd,Strafe,TargetValue,DriveType,EndCondition

const int AutoPyramid[][]={
{0,		0,		0,		0,		0,		0,		0,		0,		NoDriving,	ResetAuto},
{GLPos,	0,		Up,		0,		0,		0,		0,		500,	DriveNorm,	TimeLimit},  //scoop up bags in pyramid part 1
{GLPos,	Rev,	LSPos,	0,		Rev,	Rev,	0,		-200,	DriveNorm,	EncodStra},  //back up
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		300,	DriveNorm,	EncodStra},  //drive forward
{GLPos,	0,		Up,		0,		0,		0,		0,		500,	DriveNorm,	TimeLimit},  //scoop up bags in pyramid part 2
{GLPos,	Rev,	LSPos,	0,		Rev,	Rev,	0,		-100,	DriveNorm,	EncodStra},  //back up
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		300,	DriveNorm,	EncodStra},  //drive forward
{GLPos,	0,		Up,		0,		0,		0,		0,		500,	DriveNorm,	TimeLimit},
{0,		0,		0,		0,		0,		0,		0,		0,		NoDriving,	ResetAuto}}; //scoop up bags in pyramid part 3
//Lift,Conveyor,Spatula,Descorer,Leftd,Rightd,Strafe,TargetValue,DriveType,EndCondition

/*
const int AutoTestMotors[][]={
{0,		0,		0,		0,		0,		0,		0,		0,		NoDriving,	ResetAuto},
{GLPos,	0,		0,		HDPos,	Fwd,	Fwd,	0,		1000,	DriveNorm,	TimeLimit},  //Drive Forward
{GLPos,	0,		LSPos,	0,		Rev,	Rev,	0,		1000,	DriveNorm,	TimeLimit},  //Drive Backward
{TLPos,	0,		0,		0,		0,		0,		0,		3000,	DriveNorm,	TimeLimit},  //Lift the lift
{GLPos,	0,		0,		0,		0,		0,		0,		3000,	DriveNorm,	TimeLimit},
{0,		0,		0,		0,		0,		0,		0,		0,		NoDriving,	ResetAuto}}; //Drop the lift
//Lift,Conveyor,Spatula,Descorer,Leftd,Rightd,Strafe,TargetValue,DriveType,EndCondition
*/









const int auto01[][]={
{0,		0,		0,		0,		0,		0,		0,		0,		NoDriving,	ResetAuto},  //Reset
{GLPos,	0,		HSPos,	Up,		120,	120,	Left,	240,	DriveNorm,	EncodStra},  //strafe left and drive forward
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		1700,	DriveNorm,	EncodStra},  //drive to trough
{GLPos,	0,		Up,		0,		0,		0,		0,		0800,	DriveNorm,	TimeLimit},  //scoop bags under trough
{GLPos,	0,		LSPos,	0,		Rev,	Rev,	0,		-200,	DriveNorm,	EncodStra},  //back up and raise lift
{TLPos,	0,		LSPos,	0,		0,		0,		0,		2500,	DriveNorm,	TimeLimit},  //raise lift
{TLPos,	50,		MSPos,	0,		Fwd,	Fwd,	0,		0100,	DriveNorm,	EncodStra},  //drive forward to trough
{TLPos,	Fwd,	MSPos,	0,		0,		0,		0,		1300,	DriveNorm,	TimeLimit},  //dump bags in trough
{GLPos,	0,		MSPos,	0,		Rev,	Rev,	0,		-10,	DriveNorm,	EncodStra},  //drive backward
{GLPos,	0,		MSPos,	0,		0,		0,		0,		800,	PIDGyrosc,	RelGyrosc},  //Gyro Spin //maybe lessen this
{GLPos,	0,		LSPos,	0,		0,		0,		0,		700,	DriveNorm,	TimeLimit},  //Wait for lift to go down all the way
{GLPos,	0,		LSPos,	0,		100,	100,	0,		0400,	DriveNorm,	EncodStra},  //drive to pyramid
{GLPos,	0,		Up,		0,		0,		0,		0,		0800,	DriveNorm,	TimeLimit},  //scoop up bags in pyramid part 1
{GLPos,	Rev,	LSPos,	0,		-80,	-80,	0,		-100,	DriveNorm,	EncodStra},  //back up
{GLPos,	0,		LSPos,	0,		100,	100,	0,		0150,	DriveNorm,	EncodStra},  //drive forward
{GLPos,	0,		Up,		0,		0,		0,		0,		0800,	DriveNorm,	TimeLimit},  //scoop up bags in pyramid part 2
{GLPos,	0,		LSPos,	0,		-80,	-80,	0,		-70,	DriveNorm,	EncodStra},  //back up
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		0150,	DriveNorm,	EncodStra},  //drive forward
{GLPos,	0,		Up,		0,		0,		0,		0,		0800,	DriveNorm,	TimeLimit},  //scoop up bags in pyramid part 3
{0,		0,		0,		0,		0,		0,		0,		0,		NoDriving,	ResetAuto}}; //Autonomous is done
//Lift,Conveyor,Spatula,Descorer,Leftd,Rightd,Strafe,TargetValue,DriveType,EndCondition










const int auto02[][]={ //New Two (not used, not working after picking up wall)
{0,		0,		0,		0,		0,		0,		0,		0,		NoDriving,	ResetAuto},  //Reset
//{-100,0,		Up,		Up,		0,		0,		Left,	-001,	DriveNorm,	EncodTurn},  //strafe right, lower spatula
{-100,	0,		LSPos,	Up,		0,		0,		0,		0200,	DriveNorm,	TimeLimit},  //Descorer Up
{GLPos,	0,		LSPos,	0,		100,	100,	0,		0700,	DriveNorm,	EncodStra},  //drive forward, spatula down
{GLPos,	0,		Up,		0,		0,		0,		0,		0800,	DriveNorm,	TimeLimit},  //scoop up sacks
{GLPos,	0,		MSPos,	0,		-80,	-80,	0,		-100,	DriveNorm,	EncodStra},  //drive backward
{GLPos,	0,		LSPos,	0,		0,		0,		Left,	250,	GyrStrafe,	AbsRigtUS},  //strafe right, lower spatula
{GLPos,	0,		LSPos,	0,		100,	100,	0,		0600,	DriveNorm,	TimeLimit},  //drive forward
{GLPos,	0,		Up, 	0,		0,		0,		0,		0800,	DriveNorm,	TimeLimit},  //scoop up sacks
{GLPos,	0,		MSPos,	0,		-100,	-100,	0,		-80,	DriveNorm,	EncodStra},  //drive backward
{GLPos,	0,		LSPos,	0,		0,		0,		Left,	600,	GyrStrafe,	AbsRigtUS},  //strafe right, lower spatula
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		550,	DriveNorm,	TimeLimit},  //drive forward
{GLPos,	0,		Up, 	0,		0,		0,		0,		0800,	DriveNorm,	TimeLimit},  //scoop up sacks
{GLPos,	0,		MSPos,	0,		-100,	-100,	0,		-100,	DriveNorm,	EncodStra},  //drive backward
{GLPos,	0,		MSPos,	0,		0,		0,		0,		-1760,	PIDGyrosc,	RelGyrosc},  //Gyro Spin
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		850,	DriveNorm,	EncodStra},  //drive to trough
{GLPos,	0,		Up,		0,		0,		0,		0,		0700,	DriveNorm,	TimeLimit},  //scoop bags under trough
{0,		50,		LSPos,	0,		Rev,	Rev,	0,		-250,	DriveNorm,	EncodStra},  //back up and raise lift
{ULPos,	0,		MSPos,	0,		0,		0,		0,		3000,	DriveNorm,	TimeLimit},  //raise lift
{TLPos,	50,		MSPos,	0,		Fwd,	Fwd,	0,		200,	DriveNorm,	EncodStra},  //drive forward to trough
{TLPos,	Fwd,	0,		0,		0,		0,		0,		2000,	DriveNorm,	TimeLimit},  //Outtake
{TLPos,	Fwd,	0,		0,		Rev,	Fwd,	0,		100,	DriveNorm,	TimeLimit},  //back up
//{TLPos,-50,	0,		0,		Fwd,	Fwd,	0,		200,	DriveNorm,	TimeLimit},  //Push in
{GLPos,	Fwd,	LSPos,	0,		Rev,	Rev,	0,		-1100,	DriveNorm,	EncodStra},  //back up
//{GLPos,Fwd,	LSPos,	0,		0,		0,		Right,	900,	DriveNorm,	TimeLimit},  //strafe onto tile
{0,		0,		0,		0,		0,		0,		0,		0,		NoDriving,	ResetAuto}}; //Reset
//Lift,Conveyor,Spatula,Descorer,Leftd,Rightd,Strafe,TargetValue,DriveType,EndCondition










const int auto03[][]={
{0,		0,		0,		0,		0,		0,		0,		0,		NoDriving,	ResetAuto},  //Reset
//{-100,0,		Up,		Up,	0,		0,		Left,	-001,	DriveNorm,	EncodTurn},  //strafe right, lower spatula
{-100,	0,		LSPos,	Up,	0,		0,		0,		0200,	DriveNorm,	TimeLimit},  //Descorer Up
{GLPos,	0,		LSPos,	0,		80,		127,	0,		0700,	DriveNorm,	EncodStra},  //drive forward, spatula down
{GLPos,	0,		Up,		0,		0,		0,		0,		0800,	DriveNorm,	TimeLimit},  //scoop up sacks
{GLPos,	0,		MSPos,	0,		-80,	-80,	0,		-150,	DriveNorm,	EncodStra},  //drive backward
{GLPos,	0,		LSPos,	0,		0,		0,		Right,	250,	GyrStrafe,	AbsLeftUS},  //strafe right, lower spatula
{GLPos,	0,		LSPos,	0,		100,	100,	0,		0600,	DriveNorm,	TimeLimit},  //drive forward
{GLPos,	0,		Up, 	0,		0,		0,		0,		0800,	DriveNorm,	TimeLimit},  //scoop up sacks
{GLPos,	0,		MSPos,	0,		-100,	-100,	0,		-150,	DriveNorm,	EncodStra},  //drive backward
{GLPos,	0,		LSPos,	0,		0,		0,		Right,	600,	GyrStrafe,	AbsLeftUS},  //strafe right, lower spatula
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		550,	DriveNorm,	TimeLimit},  //drive forward
{GLPos,	0,		Up, 	0,		0,		0,		0,		0800,	DriveNorm,	TimeLimit},  //scoop up sacks
{GLPos,	0,		MSPos,	0,		-80,	-80,	0,		10,		DriveNorm,	TimeLimit},  //drive backward
{GLPos,	0,		MSPos,	0,		0,		0,		0,		860,	PIDGyrosc,	RelGyrosc},  //Gyro Spin
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		850,	DriveNorm,	EncodStra},  //drive to trough
{GLPos,	0,		Up,		0,		0,		0,		0,		0700,	DriveNorm,	TimeLimit},  //scoop bags under trough
{0,		50,		LSPos,	0,		Rev,	Rev,	0,		-250,	DriveNorm,	EncodStra},  //back up and raise lift
{ULPos,	0,		MSPos,	0,		0,		0,		0,		2500,	DriveNorm,	TimeLimit},  //raise lift
{TLPos,	50,		MSPos,	0,		Fwd,	Fwd,	0,		200,	DriveNorm,	EncodStra},  //drive forward to trough
{TLPos,	Fwd,	0,		0,		0,		0,		0,		2000,	DriveNorm,	TimeLimit},  //Outtake
{TLPos,	50,		MSPos,	0,		100,	100,	0,		200,	DriveNorm,	TimeLimit},  //drive forward to trough
{TLPos,	Fwd,	0,		0,		Rev,	Fwd,	0,		100,	DriveNorm,	TimeLimit},  //back up
//{TLPos,-50,	0,		0,		Fwd,	Fwd,	0,		200,	DriveNorm,	TimeLimit},  //Push in
{GLPos,	Fwd,	LSPos,	0,		Rev,	Rev,	0,		-1100,	DriveNorm,	EncodStra},  //back up
//{GLPos,Fwd,	LSPos,	0,		0,		0,		Right,	900,	DriveNorm,	TimeLimit},  //strafe onto tile

{0,		0,		0,		0,		0,		0,		0,		0,		NoDriving,	ResetAuto}}; //Reset
//Lift,Conveyor,Spatula,Descorer,Leftd,Rightd,Strafe,TargetValue,DriveType,EndCondition
/*
//Autonomous 3:
  //Less UltraSonic sensors
  //More Time
  //More Encoders

{GLPos,	0,		Up,		Up,		0,		0,		Left,	-001,	DriveNorm,	EncodTurn},  //strafe right, lower spatula
{GLPos,	0,		LSPos,	Up,		0,		0,		0,		0200,	DriveNorm,	TimeLimit},  //Descorer Up
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		0800,	DriveNorm,	EncodStra},  //drive forward, spatula down
{GLPos,	0,		Up,		0,		0,		0,		0,		0700,	DriveNorm,	TimeLimit},  //scoop up sacks
{GLPos,	0,		MSPos,	0,		-100,	-100,	0,		-250,	DriveNorm,	EncodStra},  //drive backward
{GLPos,	0,		LSPos,	0,		0,		0,		Right,	0720,	DriveNorm,	EncodTurn},  //strafe right, lower spatula
{GLPos,	Rev,	LSPos,	0,		Fwd,	Fwd,	0,		0500,	DriveNorm,	TimeLimit},  //drive forward
{GLPos,	0,		Up, 	0,		0,		0,		0,		0600,	DriveNorm,	TimeLimit},  //scoop up sacks
{GLPos,	0,		MSPos,	0,		-100,	-100,	0,		-300,	DriveNorm,	EncodStra},  //drive backward
{GLPos,	0,		LSPos,	0,		0,		0,		Right,	0500,	DriveNorm,	EncodTurn},  //strafe right, lower spatula
{GLPos,	Rev,	LSPos,	0,		Fwd,	Fwd,	0,		750,	DriveNorm,	TimeLimit},  //drive forward
{GLPos,	0,		Up, 	0,		0,		0,		0,		0700,	DriveNorm,	TimeLimit},  //scoop up sacks
{GLPos,	0,		MSPos,	0,		Fwd,	Rev,	0,		-920,	DriveNorm,	EncodTurn},  //turn
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		1050,	DriveNorm,	EncodStra},  //drive to trough
{GLPos,	0,		Up,		0,		0,		0,		0,		0500,	DriveNorm,	TimeLimit},  //scoop bags under trough
{TLPos,	50,		LSPos,	0,		Rev,	Rev,	0,		-250,	DriveNorm,	EncodStra},  //back up and raise lift
{TLPos,	0,		LSPos,	0,		0,		0,		0,		2500,	DriveNorm,	TimeLimit},  //raise lift
{TLPos,	50,		LSPos,	0,		Fwd,	Fwd,	0,		200,	DriveNorm,	EncodStra},  //drive forward to trough
{TLPos,	Fwd,	0,		0,		0,		0,		40,		1900,	DriveNorm,	TimeLimit},  //Outtake
{TLPos,	Rev,	0,		0,		Fwd,	Fwd,	0,		300,	DriveNorm,	TimeLimit},  //Push in
{TLPos,	Fwd,	0,		0,		Rev,	Rev,	0,		800,	DriveNorm,	TimeLimit},  //back up
//Lift,Conveyor,Spatula,Descorer,Leftd,Rightd,Strafe,TargetValue,DriveType,EndCondition
*/











const int auto04[][]={
{0,		0,		0,		0,		0,		0,		0,		0,		NoDriving,	ResetAuto},  //Reset
{GLPos,	0,		HSPos,	Up,		110,	110,	Left,	700,	DriveNorm,	TimeLimit},  //strafe left and drive forward
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		600,	DriveNorm,	EncodStra},  //drive to pyramid
{GLPos,	0,		Up,		0,		0,		0,		0,		800,	DriveNorm,	TimeLimit},  //scoop up bags in pyramid part 1
{GLPos,	0,		LSPos,	0,		Rev,	Rev,	0,		-100,	DriveNorm,	EncodStra},  //back up
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		100,	DriveNorm,	EncodStra},  //drive forward
{GLPos,	0,		Up,		0,		0,		0,		0,		800,	DriveNorm,	TimeLimit},  //scoop up bags in pyramid part 2
{GLPos,	0,		LSPos,	0,		0,		0,		Left,	-250,	GyrStrafe,	EncodStra},  //strafe
{GLPos,	0,		MSPos,	0,		0,		0,		0,		200,	DriveNorm,	TimeLimit},  //pause for motor slew to rest
{GLPos,	0,		MSPos,	0,		Rev,	Rev,	0,		180,	DriveNorm,	TimeLimit},  //back up
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		50,		DriveNorm,	EncodStra},  //drive forward to trough           maybe make this longer
{GLPos,	0,		Up,		0,		0,		0,		0,		800,	DriveNorm,	TimeLimit},  //scoop up bags
{GLPos,	0,		MSPos,	0,		0,		0,		0,		200,	DriveNorm,	TimeLimit},  //back up, start lifting
{TLPos,	0,		MSPos,	0,		Rev,	Rev,	0,		-125,	DriveNorm,	EncodStra},  //back up, start lifting
{TLPos,	0,		MSPos,	0,		0,		0,		0,		2400,	DriveNorm,	TimeLimit},  //keep lifting
{TLPos,	0,		MSPos,	0,		100,	100,	0,		600,	DriveNorm,	TimeLimit},  //drive forward to trough
{TLPos,	Fwd,	MSPos,	0,		20,		20,		0,		1800,	DriveNorm,	TimeLimit},  //dump sacks
{0,		Fwd,	2800,	0,		-40,	-40,	0,		-575,	DriveNorm,	EncodStra},  //output bags and backing up
{0,		0,		0,		0,		0,		0,		0,		0,		NoDriving,	ResetAuto}}; //Autonomous is done
//Lift,Conveyor,Spatula,Descorer,Leftd,Rightd,Strafe,TargetValue,DriveType,EndCondition











const int auto05[][]={
{0,		0,		0,		0,		0,		0,		0,		0,		NoDriving,	ResetAuto},  //Reset
{0,		0,		0,		Rev,	Fwd,	0,		0,		900,	DriveNorm,	TimeLimit},  //square up gyro
{0,		0,		0,		0,		0,      0,		0,		0,		PIDGyrosc,	AbsGyrosc},
{0,		0,		0,		0,		0,      0,		0,		0,		NoDriving,	ResetAuto}}; //Reset
//Lift,Conveyor,Spatula,Descorer,Leftd,Rightd,Strafe,TargetValue,DriveType,EndCondition
/*
{0,		Rev,	0,		0,		0,		0,		0,		1000,	DriveNorm,	TimeLimit},  //strafe right, lower spatula
{0,		Fwd,	0,		0,		0,		0,		0,		1000,	DriveNorm,	TimeLimit},  //strafe right, lower spatula
{0,		0,		0,		0,		0,		0,		Left,	250,	GyrStrafe,	AbsRigtUS},  //strafe
{0,		0,		0,		0,		0,		0,		0,		-900,	PIDGyrosc,	RelGyrosc},  //square up gyro
{0,		0,		0,		0,		0,		0,		1000,	850,	gyrsqreup,	AbsGyrosc},  //square up gyro
{GLPos,	0,		LSPos,	0,		0,		0,		Left,	-450,	GyrStrafe,	EncodStra},  //strafe
{0,		0,		0,		0,		0,		0,		Left,	100,	GyrStrafe,	AbsRigtUS},  //drive forward
*/










const int auto06[][]={
{0,		0,		0,		0,		0,		0,		0,		0,		NoDriving,	ResetAuto},  //Reset
{GLPos,	0,		HSPos,	Up,		110,	110,	Left,	700,	DriveNorm,	TimeLimit},  //strafe left and drive forward
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		600,	DriveNorm,	EncodStra},  //drive to pyramid
{GLPos,	0,		Up,		0,		0,		0,		0,		800,	DriveNorm,	TimeLimit},  //scoop up bags in pyramid part 1
{GLPos,	0,		LSPos,	0,		Rev,	Rev,	0,		-100,	DriveNorm,	EncodStra},  //back up
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		100,	DriveNorm,	EncodStra},  //drive forward
{GLPos,	0,		Up,		0,		0,		0,		0,		800,	DriveNorm,	TimeLimit},  //scoop up bags in pyramid part 2
{GLPos,	0,		LSPos,	0,		0,		0,		Left,	-250,	GyrStrafe,	EncodStra},  //strafe
{GLPos,	0,		MSPos,	0,		0,		0,		0,		200,	DriveNorm,	TimeLimit},  //pause for motor slew to rest
{GLPos,	0,		MSPos,	0,		Rev,	Rev,	0,		180,	DriveNorm,	TimeLimit},  //back up
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		50,		DriveNorm,	EncodStra},  //drive forward to trough           maybe make this longer
{GLPos,	0,		Up,		0,		0,		0,		0,		800,	DriveNorm,	TimeLimit},  //scoop up bags
{GLPos,	0,		MSPos,	0,		0,		0,		0,		200,	DriveNorm,	TimeLimit},  //back up, start lifting
{TLPos,	0,		MSPos,	0,		Rev,	Rev,	0,		-125,	DriveNorm,	EncodStra},  //back up, start lifting
{TLPos,	0,		MSPos,	0,		0,		0,		0,		2400,	DriveNorm,	TimeLimit},  //keep lifting
{TLPos,	0,		MSPos,	0,		100,	100,	0,		600,	DriveNorm,	TimeLimit},  //drive forward to trough
{TLPos,	Fwd,	MSPos,	0,		20,		20,		0,		1800,	DriveNorm,	TimeLimit},  //dump sacks

{0,		Fwd,	2800,	0,		-40,	-40,	0,		-300,	DriveNorm,	EncodStra},  //output bags and backing up

{GLPos,	0,		MSPos,	0,		0,		0,		0,		800,	PIDGyrosc,	RelGyrosc},  //Gyro Spin
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		1000,	DriveNorm,	EncodStra},  //drive forward
{GLPos,	0,		LSPos,	0,		0,		0,		0,		200,	DriveNorm,	TimeLimit},  //Wait
{GLPos,	0,		LSPos,	0,		0,		0,		0,		-880,	PIDGyrosc,	RelGyrosc},  //Gyro Spin

//{GLPos,0,		LSPos,	0,		0,		0,		0,		600,	DriveNorm,	TimeLimit},  //wait for lift
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		500,	DriveNorm,	EncodStra},  //drive forward
{GLPos,	0,		Up,		Down,	0,		0,		0,		700,	DriveNorm,	TimeLimit},  //scoop up bags in pyramid part 2
{GLPos,	0,		MSPos,	0,		-90,	-90,	0,		1000,	DriveNorm,	TimeLimit},  //back up, start lifting

{0,		0,		     0,	0,	      0,      0,	0,	       0,	NoDriving,	ResetAuto}}; //Autonomous is done
//Lift,Conveyor,Spatula,Descorer,Leftd,Rightd,Strafe,TargetValue,DriveType,EndCondition










const int auto08[][]={ //New Programming Skills Start with 3 preloads in intake

{0,		0,		0,		0,		0,		0,		0,		0,		NoDriving,	ResetAuto},  //Reset


//{-100,0,		Up,		127,	0,		0,		Left,	-001,	DriveNorm,	EncodTurn},  //strafe right, lower spatula
{-100,	0,		LSPos,	127,	0,		0,		0,		0100,	DriveNorm,	TimeLimit},  //Descorer Up
{GLPos,	0,		LSPos,	0,		100,	100,	0,		0700,	DriveNorm,	EncodStra},  //drive forward, spatula down
{GLPos,	0,		Up,		0,		0,		0,		0,		0800,	DriveNorm,	TimeLimit},  //scoop up sacks
{0,		Rev,	MSPos,	0,		-80,	-80,	0,		-100,	DriveNorm,	EncodStra},  //drive backward
{0,		0,		LSPos,	0,		0,		0,		Left,	270,	GyrStrafe,	AbsRigtUS},  //strafe left, lower spatula
{0,		0,		LSPos,	0,		100,	100,	0,		0550,	DriveNorm,	TimeLimit},  //drive forward
{0,		0,		Up, 	0,		0,		0,		0,		0800,	DriveNorm,	TimeLimit},  //scoop up sacks
{0,		0,		MSPos,	0,		-100,	-100,	0,		-80,	DriveNorm,	EncodStra},  //drive backward
{0,		Rev,	LSPos,	0,		0,		0,		Left,	570,	GyrStrafe,	AbsRigtUS},  //strafe left, lower spatula
{0,		0,		LSPos,	0,		100,	100,	0,		560,	DriveNorm,	TimeLimit},  //drive forward
{0,		0,		100, 	0,		0,		0,		0,		0800,	DriveNorm,	TimeLimit},  //scoop up 2 sacks
//{0,	0,		MSPos,	0,		0,		-80,	-80,	300,	DriveNorm,	TimeLimit},
{0,		0,		MSPos,	0,		0,		0,		0,		-925,	PIDGyrosc,	RelGyrosc},  //Gyro Spin to trough
//{0,	0,		LSPos,	0,		0,		0,		Right,	50,		GyrStrafe,	EncodStra},  //strafe right, lower spatula
//{0,	Rev,	LSPos,	0,		0,		0,		Left,	300,	GyrStrafe,	AbsRigtUS},  //strafe left, lower spatula
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		920,	DriveNorm,	EncodStra},  //drive to trough
{GLPos,	0,		Up,		0,		0,		0,		0,		0800,	DriveNorm,	TimeLimit},  //scoop bags under trough
//Lift,Conveyor,Spatula,Descorer,Leftd,Rightd,Strafe,TargetValue,DriveType,EndCondition
{0,		0,		LSPos,	0,		Rev,	Rev,	0,		-150,	DriveNorm,	EncodStra},  //back up and raise lift
{Up,	0,		MSPos,	0,		0,		0,		0,		2500,	DriveNorm,	TimeLimit},  //raise lift
{TLPos,	100,	MSPos,	0,		90,		90,		0,		800,	DriveNorm,	TimeLimit},  //drive forward to trough
{TLPos,	Fwd,	0,		0,		10,		10,		0,		2400,	DriveNorm,	TimeLimit},  //Outtake
{Up,	Fwd,	0,		0,		80,		80,		0,		120,	DriveNorm,	TimeLimit},  //Outtake
{0,		Fwd,	0,		0,		80,		80,		0,		80,		DriveNorm,	TimeLimit},  //Push sacks
{0,		Fwd,	MSPos,	0,		Rev,	Rev,	0,		340,	DriveNorm,	TimeLimit},  //back up
//{0,	Fwd,	MSPos,	0,		-50,	-50,	0,		-30,	backulstr},	//back up
//             SCORE                   SCORE                      score               SCORE
{GLPos,	0,		MSPos,	0,		0,		0,		0,		-860,	PIDGyrosc,	RelGyrosc},  //Gyro Spin to next stack
//{GLPos,0,		MSPos,	0,		Rev,	Rev,	0,		-50,	DriveNorm,	EncodStra},  //back up
//{GLPos,Fwd,	MSPos,	0,		Rev,	Rev,	0,		-800,	DriveNorm,	TimeLimit},  //back up
//{GLPos,Fwd,	0,		0,		Fwd,	Fwd,	0,		200,	DriveNorm,	EncodStra},  //Push sacks
//{GLPos,0,		0,		0,		0,		0,		0,		700,	DriveNorm,	TimeLimit},  //Wait for lift
{GLPos,	0,		0,		0,		0,		0,		0,		1000,	DriveNorm,	TimeLimit},


{GLPos,	0,		LSPos,	0,		95,		127,	0,		350,	DriveNorm,	EncodStra},  //drive to first pyramid
{GLPos,	0,		Up,		0,		0,		0,		0,		700,	DriveNorm,	TimeLimit},  //scoop up pyramid take 1
{0,		-50,	LSPos,	0,		-80,	-80,	0,		-150,	DriveNorm,	EncodStra},  //back up

{0,		0,		LSPos,	0,		95,		127,	0,		165,	DriveNorm,	EncodStra},  //drive forward first pyramid 2
{0,		0,		Up,		0,		0,		0,		0,		700,	DriveNorm,	TimeLimit},  //scoop up pyramid take 2
{0,		0,		LSPos,	0,		-80,	-80,	0,		-10,	DriveNorm,	EncodStra},  //scoop up bags

{0,		0,		LSPos,	0,		95,		127,	0,		170,	DriveNorm,	EncodStra},  //drive forward yellow sack
{0,		0,		Up,		0,		0,		0,		0,		700,	DriveNorm,	TimeLimit},  //scoop up yellow
{0,		0,		LSPos,	0,		-95,	-100,	0,		150,	DriveNorm,	TimeLimit},  //hmm
//Lift,Conveyor,Spatula,Descorer,Leftd,Rightd,Strafe,TargetValue,DriveType,EndCondition
{0,		0,		LSPos,	0,		95,		127,	0,		360,	DriveNorm,	EncodStra},  //drive forward to second stack
{0,		0,		Up,		0,		0,		0,		0,		700,	DriveNorm,	TimeLimit},  //scoop up pyraid take 1
{0,		-50,	LSPos,	0,		-80,	-80,	0,		-150,	DriveNorm,	EncodStra},  //back up

{0,		0,		LSPos,	0,		95,		127,	0,		130,	DriveNorm,	EncodStra},  //drive to second pyramid
{0,		0,		Up,		0,		0,		0,		0,		700,	DriveNorm,	TimeLimit},  //scoop up pyramid take 2
{0,		-50,	LSPos,	0,		-80,	-80,	0,		-200,	DriveNorm,	EncodStra},  //back up

{0,		0,		LSPos,	0,		95,		120,	0,		175,	DriveNorm,	EncodStra},  //drive forward
{0,		0,		Up,		0,		0,		0,		0,		700,	DriveNorm,	TimeLimit},  //scoop up pyramid take 3
{0,		0,		LSPos,	0,		-100,	-100,	0,		-375,	DriveNorm,	EncodStra},  //back up to trough

{0,		0,		MSPos,	0,		0,		0,		0,		880,	PIDGyrosc,	RelGyrosc},  //Gyro Spin
{GLPos,	-50,	LSPos,	0,		-80,	-80,	0,		-100,	DriveNorm,	EncodStra},  //back up
{0,		0,		LSPos,	0,		Fwd,	Fwd,	0,		400,	DriveNorm,	EncodStra},  //drive to trough
{GLPos,	0,		Up,		0,		0,		0,		0,		700,	DriveNorm,	TimeLimit},  //scoop bags under trough
{TLPos,	0,		LSPos,	0,		-100,	-100,	0,		-200,	DriveNorm,	EncodStra},  //flag ..... back up and raise lift
{TLPos,	0,		MSPos,	0,		0,		0,		0,		2500,	DriveNorm,	TimeLimit},  //raise lift
{TLPos+50,50,	MSPos,	0,		100,	100,	0,		200,	DriveNorm,	EncodStra},  //drive forward to trough
{TLPos,	Fwd,	0,		0,		0,		0,		0,		2000,	DriveNorm,	TimeLimit},  //Outtake
{Up,	Rev,	LSPos,	0,		100,	100,	0,		150,	DriveNorm,	TimeLimit},  //drive to trough
{0,		Fwd,	MSPos,	0,		Rev,	Rev,	0,		-200,	DriveNorm,	EncodStra},  //back up from trough
//             SCORE                   SCORE                      score               SCORE
{GLPos,		0,	MSPos,	0,		Fwd,	Rev,	0,		-200,	DriveNorm,	EncodTurn},  //turn
{GLPos,		0,	MSPos,	0,		Rev,	Rev,	0,		-900,	DriveNorm,	EncodStra},  //back up from trough
//{GLPos,	0,	MSPos,	0,		0,		0,	 	Left,	-1700,	DriveNorm,	EncodStra},  //drive back to blue left start tile
{GLPos,		0,	MSPos,	0,		Rev,	Fwd,	0,		10,		DriveNorm,	EncodTurn},  //turn
{GLPos,	0,		MSPos,	0,		Fwd,	Fwd,	0,		400,	DriveNorm,	TimeLimit},

//Robot is realigned on other starting tile

{GLPos,	0,		MSPos,	0,		0,		0,		0,		1300,	DriveNorm,	TimeLimit},  //Wait for Lift
{0,		0,		MSPos,	0,		0,		0,		0,		2700,	DriveNorm,	ScreenBtn},  //Wait for screen button

//Fourth Step
{-100,	0,		LSPos,	127,	0,		0,		0,		0200,	DriveNorm,	TimeLimit},  //Descorer Up
{GLPos,	0,		LSPos,	0,		70,		127,	0,		0700,	DriveNorm,	EncodStra},  //drive forward, spatula down
{GLPos,	0,		Up,		0,		0,		0,		0,		0800,	DriveNorm,	TimeLimit},  //scoop up sacks
{GLPos,	0,		MSPos,	0,		-80,	-80,	0,		-150,	DriveNorm,	EncodStra},  //drive backward
{GLPos,	0,		LSPos,	0,		0,		0,		Right,	250,	GyrStrafe,	AbsLeftUS},  //strafe right, lower spatula
{GLPos,	0,		LSPos,	0,		100,	100,	0,		0600,	DriveNorm,	TimeLimit},  //drive forward
{GLPos,	0,		Up, 	0,		0,		0,		0,		0800,	DriveNorm,	TimeLimit},  //scoop up sacks
{GLPos,	0,		MSPos,	0,		-100,	-100,	0,		-150,	DriveNorm,	EncodStra},  //drive backward
{GLPos,	0,		LSPos,	0,		0,		0,		Right,	600,	GyrStrafe,	AbsLeftUS},  //strafe right, lower spatula
{GLPos,	Rev,	LSPos,	0,		Fwd,	Fwd,	0,		550,	DriveNorm,	TimeLimit},  //drive forward
{GLPos,	0,		Up, 	0,		0,		0,		0,		0800,	DriveNorm,	TimeLimit},  //scoop up sacks
//{GLPos,0,		MSPos,	0,		-100,	-100,	0,		-1,		DriveNorm,	EncodStra},  //drive backward
{GLPos,	0,		MSPos,	0,		0,		0,		0,		860,	PIDGyrosc,	RelGyrosc},  //Gyro Spin
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		900,	DriveNorm,	EncodStra},  //drive to trough
{GLPos,	0,		Up,		0,		0,		0,		0,		0800,	DriveNorm,	TimeLimit},  //scoop bags under trough
{0,		50,		LSPos,	0,		Rev,	Rev,	0,		-250,	DriveNorm,	EncodStra},  //back up and raise lift
{ULPos,	0,		MSPos,	0,		0,		0,		0,		3000,	DriveNorm,	TimeLimit},  //raise lift
{TLPos,	50,		MSPos,	0,		Fwd,	Fwd,	0,		200,	DriveNorm,	EncodStra},  //drive forward to trough
{TLPos,	Fwd,	0,		0,		0,		0,		0,		2000,	DriveNorm,	TimeLimit},  //Outtake
{TLPos,	Fwd,	0,		0,		Rev,	Fwd,	0,		100,	DriveNorm,	TimeLimit},  //back up
{TLPos,	-50,	0,		0,		Fwd,	Fwd,	0,		200,	DriveNorm,	TimeLimit},  //Push in
{GLPos,	Fwd,	LSPos,	0,		Rev,	Rev,	0,		-1100,	DriveNorm,	EncodStra},  //back up
//{GLPos,Fwd,	LSPos,	0,		0,		0,		Right,	900,	DriveNorm,	TimeLimit},  //strafe onto tile

{0,		0,		0,		0,		0,		0,		0,		0,		NoDriving,	ResetAuto}}; //Reset
//Lift,Conveyor,Spatula,Descorer,Leftd,Rightd,Strafe,TargetValue,DriveType,EndCondition









const int auto09[][]={
{0,		0,		0,		0,		0,		0,		0,		0,		NoDriving,	ResetAuto},  //Reset

{GLPos,	0,		HSPos,	Up,		100,	100,	Right,	500,	GyrStrafe,	EncodStra},  //strafe right and drive forward
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		2300,	DriveNorm,	EncodStra},  //drive to trough
{GLPos,	0,		Up,		0,		0,		0,		0,		0800,	DriveNorm,	TimeLimit},  //scoop bags under trough
{TLPos,	0,		LSPos,	0,		Rev,	Rev,	0,		-200,	DriveNorm,	EncodStra},  //back up and raise lift
{TLPos,	0,		LSPos,	0,		0,		0,		0,		2500,	DriveNorm,	TimeLimit},  //raise lift
{TLPos,	50,		MSPos,	0,		100,	100,	0,		0120,	DriveNorm,	EncodStra},  //drive forward to trough
{TLPos,	Fwd,	MSPos,	0,		0,		0,		0,		1300,	DriveNorm,	TimeLimit},  //dump bags in trough
{GLPos,	0,		MSPos,	0,		Rev,	Rev,	0,		-1600,	DriveNorm,	EncodStra},  //drive backward
{GLPos,	0,		MSPos,	0,		0,		0,		0,		800,	DriveNorm,	TimeLimit},  //lower lift
{0,		0,		MSPos,	0,		0,		0,		0,		1000,	DriveNorm,	ScreenBtn},  //reposition


/*{GLPos,0,		MSPos,	0,		0,		0,		0,		-880,	PIDGyrosc,	RelGyrosc},  //Gyro Spin
{GLPos,	0,		LSPos,	0,		0,		0,		0,		700,	DriveNorm,	TimeLimit},  //Wait for lift to go down all the way
{GLPos,	0,		LSPos,	0,	Fwd,	Fwd,	0,		0400,	DriveNorm,	EncodStra},  //drive to pyramid
{GLPos,	0,		Up,		0,		0,		0,		0,		0800,	DriveNorm,	TimeLimit},  //scoop up bags in pyramid part 1
{GLPos,	Rev,	LSPos,	0,		Rev,	Rev,	0,		-100,	DriveNorm,	EncodStra},  //back up
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		0150,	DriveNorm,	EncodStra},  //drive forward
{GLPos,	0,		Up,		0,		0,		0,		0,		0800,	DriveNorm,	TimeLimit},  //scoop up bags in pyramid part 2
{GLPos,	0,		LSPos,	0,		Rev,	Rev,	0,		-70,	DriveNorm,	EncodStra},  //back up
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		0150,	DriveNorm,	EncodStra},  //drive forward
{GLPos,	0,		Up,		0,		0,		0,		0,		0800,	DriveNorm,	TimeLimit},  //scoop up bags in pyramid part 3*/


{GLPos,	0,		MSPos,	0,	110,	110,	Left,	800,	DriveNorm,	TimeLimit},  //strafe left and drive forward
{GLPos,	0,		LSPos,	0,	100,	100,	0,		500,	DriveNorm,	EncodStra},  //drive to pyramid
{GLPos,	0,		Up,		0,		0,		0,		0,		800,	DriveNorm,	TimeLimit},  //scoop up bags in pyramid part 1
{GLPos,	0,		LSPos,	0,		-80,	-80,	0,		-150,	DriveNorm,	EncodStra},  //back up
{GLPos,	0,		LSPos,	0,		100,	100,	0,		100,	DriveNorm,	EncodStra},  //drive forward
{GLPos,	0,		Up,		0,		0,		0,		0,		800,	DriveNorm,	TimeLimit},  //scoop up bags in pyramid part 2
{GLPos,	0,		LSPos,	0,		-80,	-80,	0,		-150,	DriveNorm,	EncodStra},  //back up
{GLPos,	0,		LSPos,	0,		0,		0,		Left,	-400,	DriveNorm,	EncodTurn},  //strafe
{GLPos,	0,		LSPos,	0,		100,	100,	0,		200,	DriveNorm,	EncodStra},  //drive forward
{GLPos,	0,		Up,		0,		0,		0,		0,		800,	DriveNorm,	TimeLimit},  //scoop up bags in pyramid part 2
{GLPos,	0,		LSPos,	0,		-80,	-80,	0,		-200,	DriveNorm,	EncodStra},  //back up
{GLPos,	0,		LSPos,	0,		0,		0,		Left,	-500,	DriveNorm,	EncodTurn},  //strafe
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		150,	DriveNorm,	EncodStra},  //drive forward to trough           maybe make this longer
{GLPos,	0,		Up,		0,		0,		0,		0,		800,	DriveNorm,	TimeLimit},  //scoop up bags
{TLPos,	Fwd,	MSPos,	0,		Rev,	Rev,	0,		-100,	DriveNorm,	EncodStra},  //back up, start lifting
{TLPos,	0,		MSPos,	0,		0,		0,		0,		2400,	DriveNorm,	TimeLimit},  //keep lifting
{TLPos,	0,		MSPos,	0,		Fwd,	Fwd,	0,		80,		DriveNorm,	EncodStra},  //drive forward to trough
{TLPos,	Fwd,	MSPos,	0,		0,		0,		0,		1800,	DriveNorm,	TimeLimit},  //dump sacks
{TLPos,	Fwd,	MSPos,	0,		Rev,	Rev,	0,		-100,	DriveNorm,	EncodStra},  //Reverse
//Lift,Conveyor,Spatula,Descorer,Leftd,Rightd,Strafe,TargetValue,DriveType,EndCondition
{GLPos,	Fwd,	MSPos,	0,		-40,	-40,	0,		-205,	DriveNorm,	EncodStra},  //output bags and backing up

// Second trough scored

{GLPos,	0,		MSPos,	0,		0,		0,		0,		-880,	PIDGyrosc,	RelGyrosc},  //Gyro Spin
// Third Part

{GLPos,	0,		LSPos,	0,		0,		0,		0,		300,	DriveNorm,	TimeLimit},  //Wait for lift to go down all the way
{GLPos,	0,		LSPos,	0,		-100,	-100,	0,		150,	DriveNorm,	TimeLimit},  //back up to get yellow //This should be less
{GLPos,	0,		LSPos,	0,		100,	100,	0,		200,	DriveNorm,	EncodStra},  //drive forward to yellow
{GLPos,	0,		Up,		0,		0,		0,		0,		700,	DriveNorm,	TimeLimit},  //scoop up yellow bag
{GLPos,	Fwd,	LSPos,	0,		0,		0,		0,		400,	DriveNorm,	TimeLimit},  //put spatula down
{GLPos,	0,		LSPos,	0,		100,	100,	0,		250,	DriveNorm,	EncodStra},  //drive to second pyramid
{GLPos,	0,		Up,		0,		0,		0,		0,		700,	DriveNorm,	TimeLimit},  //scoop up pyramid take 1
{GLPos,	-50,	LSPos,	0,		-80,	-80,	0,		-200,	DriveNorm,	EncodStra},  //back up
{GLPos,	0,		LSPos,	0,		100,	100,	0,		150,	DriveNorm,	EncodStra},  //drive forward
{GLPos,	0,		Up,		0,		0,		0,		0,		700,	DriveNorm,	TimeLimit},  //scoop up pyramid take 2
{GLPos,	0,		LSPos,	0,		-80,	-80,	0,		-100,	DriveNorm,	EncodStra},  //scoop up bags
{GLPos,	0,		LSPos,	0,		100,	100,	0,		150,	DriveNorm,	EncodStra},  //drive forward
{0,		0,		Up,		0,		0,		0,		0,		700,	DriveNorm,	TimeLimit},  //scoop up pyramid take 3
{0,		0,		LSPos,	0,		-100,	-100,	0,		-500,	DriveNorm,	EncodStra},  //back up to line up with trough
{0,		0,		MSPos,	0,		0,		0,		0,		880,	PIDGyrosc,	RelGyrosc},  //Gyro Spin
{0,		0,		LSPos,	0,		Fwd,	Fwd,	0,		400,	DriveNorm,	EncodStra},  //drive to trough
{GLPos,	0,		Up,		0,		0,		0,		0,		700,	DriveNorm,	TimeLimit},  //scoop bags under trough
{TLPos,	0,		LSPos,	0,		-80,	-80,	0,		-180,	DriveNorm,	EncodStra},  //flag ..... back up and raise lift
{TLPos,	0,		MSPos,	0,		0,		0,		0,		2400,	DriveNorm,	TimeLimit},  //raise lift
{TLPos,	Fwd,	MSPos,	0,		100,	100,	0,		100,	DriveNorm,	EncodStra},  //flag2 ..... if good bat maybe, change to 500 drive forward to trough
{TLPos,	Fwd,	MSPos,	0,		0,		0,		-30,	1500,	DriveNorm,	TimeLimit},  //dump bags in trough while straifing
{TLPos,	Rev,	LSPos,	0,		100,	100,	0,		150,	DriveNorm,	TimeLimit},  //drive to trough
{0,		Fwd,	MSPos,	0,		Rev,	Rev,	0,		-300,	DriveNorm,	EncodStra},  //back up from trough
{GLPos,	0,		MSPos,	0,		-20,	-127,	0,		-1700,	DriveNorm,	EncodStra},  //drive back to blue left start tile
{0,		0,		MSPos,	0,		Rev,	Fwd,	0,		10,		DriveNorm,	EncodTurn},  //turn

//Robot is realigned on other starting tile

{-127,	0,		MSPos,	0,		0,		0,		0,		300,	DriveNorm,	TimeLimit},  //Wait for screen button
{0,		0,		MSPos,	0,		0,		0,		0,		2000,	DriveNorm,	ScreenBtn},  //Wait for screen button

//Fourth Step
{GLPos,	0,		LSPos,	127,	0,		0,		0,		0200,	DriveNorm,	TimeLimit},  //Descorer Up
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		0800,	DriveNorm,	EncodStra},  //drive forward, spatula down
{GLPos,	0,		Up,		0,		0,		0,		0,		0700,	DriveNorm,	TimeLimit},  //scoop up sacks
{GLPos,	0,		MSPos,	0,		-80,	-80,	0,		-250,	DriveNorm,	EncodStra},  //drive backward
{GLPos,	0,		LSPos,	0,		0,		0,		Right,	0310,	DriveNorm,	EncodTurn},  //strafe right, lower spatula
{GLPos,	Rev,	LSPos,	0,		100,	100,	0,		0800,	DriveNorm,	TimeLimit},  //drive forward
{GLPos,	0,		Up, 	0,		0,		0,		0,		0600,	DriveNorm,	TimeLimit},  //scoop up sacks
{GLPos,	0,		MSPos,	0,		-100,	-100,	0,		-200,	DriveNorm,	EncodStra},  //drive backward
{GLPos,	0,		LSPos,	0,		0,		0,		Right,	0280,	DriveNorm,	EncodTurn},  //strafe right, lower spatula
{GLPos,	Rev,	LSPos,	0,		Fwd,	Fwd,	0,		800,	DriveNorm,	TimeLimit},  //drive forward
{GLPos,	0,		Up, 	0,		0,		0,		0,		0700,	DriveNorm,	TimeLimit},  //scoop up sacks
{GLPos,	0,		MSPos,	0,		-100,	-100,	0,		-40,	DriveNorm,	EncodStra},  //drive backward
{GLPos,	Rev,	MSPos,	0,		0,		0,		0,		880,	PIDGyrosc,	RelGyrosc},  //Gyro Spin
{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		850,	DriveNorm,	EncodStra},  //drive to trough
{GLPos,	0,		Up,		0,		0,		0,		0,		0700,	DriveNorm,	TimeLimit},  //scoop bags under trough
{TLPos,	50,		LSPos,	0,		Rev,	Rev,	0,		-250,	DriveNorm,	EncodStra},  //back up and raise lift
{TLPos,	0,		LSPos,	0,		0,		0,		0,		2500,	DriveNorm,	TimeLimit},  //raise lift
{TLPos,	50,		LSPos,	0,		Fwd,	Fwd,	0,		200,	DriveNorm,	EncodStra},  //drive forward to trough
{TLPos,	Fwd,	0,		0,		0,		0,		40,		2000,	DriveNorm,	TimeLimit},  //Outtake
//{TLPos,-50,	0,		0,		Fwd,	Fwd,	0,		200,	DriveNorm,	TimeLimit},  //Push in
{TLPos,	Fwd,	LSPos,	0,		Rev,	Rev,	0,		-1700,	DriveNorm,	EncodStra},  //back up
{GLPos,	Fwd,	LSPos,	0,		0,		0,		Right,	900,	DriveNorm,	TimeLimit},  //strafe onto tile

{0,		0,		0,		0,		0,      0,		0,		0,		NoDriving,	ResetAuto}}; //Autonomous is done
//Lift,Conveyor,Spatula,Descorer,Leftd,Rightd,Strafe,TargetValue,DriveType,EndCondition
