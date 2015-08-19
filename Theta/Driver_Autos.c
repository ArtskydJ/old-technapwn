const int AutoDescore[][]={
	{0,		0,		0,		0,		0,		0,		0,		0,		RESETAUTO},
	{GLPos,	0,		0,		0,		Rev,	Rev,	0,		-300,	ENCODSTRA},	//straif left and drive forward
	{GLPos,	0,		0,		Down,	0,		0,		0,		500,	TIMELIMIT},	//straif left and drive forward
	{GLPos,	0,		0,		-50,	Rev,	Rev,	0,		-400,	ENCODSTRA},	//straif left and drive forward
	{GLPos,	0,		0,		-50,	-75,	-75,	0,		-300,	ENCODSTRA},	//straif left and drive forward
	{GLPos,	0,		0,		Up,		Fwd,	Fwd,	0,		550,	ENCODSTRA},
	{0,		0,		0,		0,		0,		0,		0,		0,		RESETAUTO}};	//straif left and drive forward


const int AutoPyramid[][]={
	{0,		0,		0,		0,		0,		0,		0,		0,		RESETAUTO},
	{GLPos,	0,		Up,		0,		0,		0,		0,		500,	TIMELIMIT},	//scoop up bags in pyramid part 1
	{GLPos,	Rev,	LSPos,	0,		Rev,	Rev,	0,		-200,	ENCODSTRA},	//back up
	{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		300,	ENCODSTRA},	//drive forward
	{GLPos,	0,		Up,		0,		0,		0,		0,		500,	TIMELIMIT},	//scoop up bags in pyramid part 2
	{GLPos,	Rev,	LSPos,	0,		Rev,	Rev,	0,		-100,	ENCODSTRA},	//back up
	{GLPos,	0,		LSPos,	0,		Fwd,	Fwd,	0,		300,	ENCODSTRA},	//drive forward
	{GLPos,	0,		Up,		0,		0,		0,		0,		500,	TIMELIMIT},
	{0,		0,		0,		0,		0,		0,		0,		0,		RESETAUTO}};	//scoop up bags in pyramid part 3

/*
const int AutoTestMotors[][]={
	{0,		0,		0,		0,		0,		0,		0,		0,		RESETAUTO},
	{GLPos,	0,		0,		HDPos,	Fwd,	Fwd,	0,		1000,	TIMELIMIT},	//Drive Forward
	{GLPos,	0,		LSPos,	0,		Rev,	Rev,	0,		1000,	TIMELIMIT},	//Drive Backward
	{TLPos,	0,		0,		0,		0,		0,		0,		3000,	TIMELIMIT},	//Lift the lift
	{GLPos,	0,		0,		0,		0,		0,		0,		3000,	TIMELIMIT},
	{0,		0,		0,		0,		0,		0,		0,		0,		RESETAUTO}};	//Drop the lift
*/
