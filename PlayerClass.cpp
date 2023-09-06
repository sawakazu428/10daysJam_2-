#include "PlayerClass.h"


void PlayerClass::Initialize()
{
	playerPosX = 13 * KBlockSize;
	playerPosY = 576;
	playerR = 32;
	playerSpeed = KBlockSize;

	playerTmpX = 0;
	playerTmpY = 0;
	playerMapX = 0;
	playerMapY = 0;

	correctFlag = false;

	player = Novice::LoadTexture("./images/player.png");
}

void PlayerClass::Update()
{
	// マップ情報
	playerMapX = playerPosX / KBlockSize;
	playerMapY = playerPosY / KBlockSize;
}

void PlayerClass::Draw()
{
	Novice::DrawSprite(playerPosX, playerPosY, player, 1, 1, 0, WHITE);
}

void PlayerClass::Move()
{
	if (keys[DIK_W] && preKeys[DIK_W] == 0 || keys[DIK_UP] && preKeys[DIK_UP] == 0)
	{
		playerTmpY = playerPosY - playerSpeed;
		playerMapY = playerTmpY / KBlockSize;
		//何もないから実際に進ませる
		if (map[playerMapY][playerMapX] == YU                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        KA)
		{
			playerPosY -= playerSpeed;
		}

		if (map[playerMapY][playerMapX] == GOAL)
		{
			playerPosY -= playerSpeed;
		}
		if (map[playerMapY][playerMapX] == THORN)
		{
			playerPosY -= playerSpeed;
		}
		//シロップを動かす処理
		if (map[playerMapY][playerMapX] == A || )
		{
			if (map[playerMapY - 1][playerMapX] == YUKA)
			{
				map[playerMapY][playerMapX] = YUKA;
				map[playerMapY - 1][playerMapX] = SYRUP;
				playerPosY -= playerSpeed;
			}
		}
	}

	if (keys[DIK_A] && preKeys[DIK_A] == 0 || keys[DIK_LEFT] && preKeys[DIK_LEFT] == 0)
	{
		playerTmpX = playerPosX - playerSpeed;
		playerMapX = playerTmpX / KBlockSize;
		//何もないから実際に進ませる
		if (map[playerMapY][playerMapX] == YUKA)
		{
			playerPosX -= playerSpeed;
		}
		if (map[playerMapY][playerMapX] == GOAL)
		{
			playerPosX -= playerSpeed;
		}
		if (map[playerMapY][playerMapX] == THORN)
		{
			playerPosX -= playerSpeed;
		}
		//シロップを動かす処理
		if (map[playerMapY][playerMapX] == SYRUP)
		{
			if (map[playerMapY][playerMapX - 1] == YUKA)
			{
				map[playerMapY][playerMapX] = YUKA;
				map[playerMapY][playerMapX - 1] = SYRUP;
				playerPosX -= playerSpeed;
			}
		}
	}

	if (keys[DIK_D] && preKeys[DIK_D] == 0 || keys[DIK_RIGHT] && preKeys[DIK_RIGHT] == 0)
	{
		playerTmpX = playerPosX + playerSpeed;
		playerMapX = playerTmpX / KBlockSize;
		//何もないから実際に進ませる
		if (map[playerMapY][playerMapX] == YUKA)
		{
			playerPosX += playerSpeed;
		}
		if (map[playerMapY][playerMapX] == GOAL)
		{
			playerPosX += playerSpeed;
		}
		if (map[playerMapY][playerMapX] == THORN)
		{
			playerPosX += playerSpeed;
		}
		//シロップを動かす処理
		if (map[playerMapY][playerMapX] == SYRUP)
		{
			if (map[playerMapY][playerMapX + 1] == YUKA)
			{
				map[playerMapY][playerMapX] = YUKA;
				map[playerMapY][playerMapX + 1] = SYRUP;
				playerPosX += playerSpeed;
			}
		}
	}

	if (keys[DIK_S] && preKeys[DIK_S] == 0 || keys[DIK_DOWN] && preKeys[DIK_DOWN] == 0)
	{
		playerTmpY = playerPosY + playerSpeed;
		playerMapY = playerTmpY / KBlockSize;
		//何もないから実際に進ませる
		if (map[playerMapY][playerMapX] == YUKA)
		{
			playerPosY += playerSpeed;
		}
		if (map[playerMapY][playerMapX] == GOAL)
		{
			playerPosY += playerSpeed;
		}
		if (map[playerMapY][playerMapX] == THORN)
		{
			playerPosY += playerSpeed;
		}
		//シロップを動かす処理
		if (map[playerMapY][playerMapX] == SYRUP)
		{
			if (map[playerMapY + 1][playerMapX] == YUKA)
			{
				map[playerMapY][playerMapX] = YUKA;
				map[playerMapY + 1][playerMapX] = SYRUP;
				playerPosY += playerSpeed;
			}
		}
	}
}

// 正解の時
void PlayerClass::Correct()
{
	//　goalから次に行けるflagを立てる

}

//　正解じゃない時
void PlayerClass::Wrong()
{
	//　ライフが一つなくなる
}
