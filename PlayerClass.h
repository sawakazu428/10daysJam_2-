#pragma once
enum HIRAGANA
{
	A, I, U, E, O,
	KA, KI, KU, KE, KO,
	SA, SHI, SU, SE, SO,
	TA, CHI, TSU, TE, TO,
	NA, NI, NU, NE, NO,
	HA, HI, FU, HE, HO,
	MA, MI, MU, ME, MO,
	YA, YU, YO,
	RA, RI, RU, RE, RO,
	WA, WO, NN,

	GA, GI, GU, GE, GO,
	ZA, ZI, ZU, ZE, ZO,
	DA, DI, DU, DE, DO,
	BA, BI, BU, BE, BO,
	PA, PI, PU, PE, PO,

	KYA, KYU, KYO,
	SYA, SYU, SYO,
	CYA, CYU, SYO,
	NYA, NYU, NYO,
	HYA, HYU, HYO,
	MYA, MYU, MYO,
	RYA, RYU, RYO,
	GYA, GYU, GYO,
	ZYA, ZYU, ZYO,
	DYA, DYU, DYO,
	BYA, BYU, BYO,
	PYA, PYU, PYO,

	BLOCK1, BLOCK2, BLOCK3, BLOCK4,
	BLOCK5, BLOCK6, BLOCK7, BLOCK8,
};

class PlayerClass
{
public:
	void Initialize();

	void Update();

	void Draw();

	void Move();

	void Correct();

	void Wrong();

	int GetPlayerPosX() { playerPosX; }
	int GetPlayerPosY() { playerPosY; }

	int GetPlayerMapX() { playerMapX; }
	int GetPlayerMapY() { playerMapY; }

private:
	int playerPosX;
	int playerPosY;
	int playerR;
	int playerSpeed;

	int playerTmpX;
	int playerTmpY;
	int playerMapX;
	int playerMapY;

	int player;
	const int KBlockSize = 32;
};
