#include "MapClass.h"

void MapClass::Initialize()
{
	mapCountX;
	mapCountY;
	mapCountX2;
	mapCountY2;
	mapCountX3;
	mapCountY3;
	blockPosX = 32;
	blockPosY = 32;
	blockTmpX = 0;
	blockTmpY = 0;
	blockMapX = 0;
	blockMapY = 0;
}
void MapClass::Update()
{
	blockMapX = blockPosX / KBlockSize;
	blockMapY = blockPosY / KBlockSize;

	mapCountX = sizeof(map[0]) / sizeof(map[0][0]);
	mapCountY = sizeof(map) / sizeof(map[0]);

	mapCountX2 = sizeof(map2[0]) / sizeof(map2[0][0]);
	mapCountY2 = sizeof(map2) / sizeof(map2[0]);

	mapCountX3 = sizeof(map3[0]) / sizeof(map3[0][0]);
	mapCountY3 = sizeof(map3) / sizeof(map3[0]);

}

void MapClass::stage1()
{
	for (int y = 0; y < mapCountY; y++)
	{
		for (int x = 0; x < mapCountX; x++)
		{
			map[y][x] = mapFormat[y][x];
		}
	}
}

void MapClass::stage2()
{
	for (int y = 0; y < mapCountY2; y++)
	{
		for (int x = 0; x < mapCountX2; x++)
		{
			map2[y][x] = mapFormat2[y][x];
		}
	}
}

void MapClass::stage3()
{
	for (int y = 0; y < mapCountY3; y++)
	{
		for (int x = 0; x < mapCountX3; x++)
		{
			map3[y][x] = mapFormat3[y][x];
		}
	}
}

void MapClass::DrawStage()
{
	for (int y = 0; y < mapCountY; y++)
	{
		for (int x = 0; x < mapCountX; x++)
		{
			if (map[y][x] == I)
			{
				Novice::DrawBox(x * KBlockSize, y * KBlockSize, KBlockSize, KBlockSize, 0, BLUE, kFillModeSolid);
			}
			if (map[y][x] == NU)
			{
				Novice::DrawSprite(x * KBlockSize, y * KBlockSize, block, 1, 1, 0, WHITE);
			}
			if (map[y][x] == NE)
			{
				Novice::DrawSprite(x * KBlockSize, y * KBlockSize, thorn, 1, 1, 0, WHITE);
			}
			if (map[y][x] == KO)
			{
				Novice::DrawBox(x * KBlockSize, y * KBlockSize, KBlockSize, KBlockSize, 0, RED, kFillModeSolid);
			}
			if (map[y][x] == KI)
			{
				Novice::DrawSprite(x * KBlockSize, y * KBlockSize, goal, 1, 1, 0, WHITE);
			}
			if (map[y][x] == RI)
			{
				Novice::DrawSprite(x * KBlockSize, y * KBlockSize, syrup, 1, 1, 0, WHITE);
			}
			if (map[y][x] == NN)
			{
				Novice::DrawSprite(x * KBlockSize, y * KBlockSize, candy, 1, 1, 0, WHITE);
			}
			if (map[y][x] == SU)
			{
				Novice::DrawSprite(x * KBlockSize, y * KBlockSize, caramel, 1, 1, 0, WHITE);
			}
			if (map[y][x] == BA)
			{
				Novice::DrawBox(x * KBlockSize, y * KBlockSize, KBlockSize, KBlockSize, 0, BLUE, kFillModeSolid);
			}
			if (map[y][x] == KA)
			{
				Novice::DrawBox(x * KBlockSize, y * KBlockSize, KBlockSize, KBlockSize, 0, BLUE, kFillModeSolid);
			}
			if (map[y][x] == RA)
			{
				Novice::DrawBox(x * KBlockSize, y * KBlockSize, KBlockSize, KBlockSize, 0, BLUE, kFillModeSolid);
			}
			if (map[y][x] == SU)
			{
				Novice::DrawBox(x * KBlockSize, y * KBlockSize, KBlockSize, KBlockSize, 0, BLUE, kFillModeSolid);
			}
			if (map[y][x] == RU)
			{
				Novice::DrawBox(x * KBlockSize, y * KBlockSize, KBlockSize, KBlockSize, 0, BLUE, kFillModeSolid);
			}

		}
	}
}

void MapClass::Drawstage2()
{
	for (int y = 0; y < mapCountY; y++)
	{
		for (int x = 0; x < mapCountX; x++)
		{
			if (map[y][x] == YUKA)
			{
				Novice::DrawBox(x * KBlockSize, y * KBlockSize, KBlockSize, KBlockSize, 0, BLUE, kFillModeSolid);
			}
			if (map[y][x] == BLOCK)
			{
				Novice::DrawSprite(x * KBlockSize, y * KBlockSize, block, 1, 1, 0, WHITE);
			}
			if (map[y][x] == THORN)
			{
				Novice::DrawSprite(x * KBlockSize, y * KBlockSize, thorn, 1, 1, 0, WHITE);
			}
			if (map[y][x] == BLOCK2)
			{
				Novice::DrawBox(x * KBlockSize, y * KBlockSize, KBlockSize, KBlockSize, 0, RED, kFillModeSolid);
			}
			if (map[y][x] == GOAL)
			{
				Novice::DrawSprite(x * KBlockSize, y * KBlockSize, goal, 1, 1, 0, WHITE);
			}
			if (map[y][x] == SYRUP)
			{
				Novice::DrawSprite(x * KBlockSize, y * KBlockSize, syrup, 1, 1, 0, WHITE);
			}
			if (map[y][x] == CANDY)
			{
				Novice::DrawSprite(x * KBlockSize, y * KBlockSize, candy, 1, 1, 0, WHITE);
			}
			if (map[y][x] == CARAMEL)
			{
				Novice::DrawSprite(x * KBlockSize, y * KBlockSize, caramel, 1, 1, 0, WHITE);
			}
		}
	}
}

void MapClass::Drawstage3()
{
	for (int y = 0; y < mapCountY; y++)
	{
		for (int x = 0; x < mapCountX; x++)
		{
			if (map[y][x] == YUKA)
			{
				Novice::DrawBox(x * KBlockSize, y * KBlockSize, KBlockSize, KBlockSize, 0, BLUE, kFillModeSolid);
			}
			if (map[y][x] == BLOCK)
			{
				Novice::DrawSprite(x * KBlockSize, y * KBlockSize, block, 1, 1, 0, WHITE);
			}
			if (map[y][x] == THORN)
			{
				Novice::DrawSprite(x * KBlockSize, y * KBlockSize, thorn, 1, 1, 0, WHITE);
			}
			if (map[y][x] == BLOCK2)
			{
				Novice::DrawBox(x * KBlockSize, y * KBlockSize, KBlockSize, KBlockSize, 0, RED, kFillModeSolid);
			}
			if (map[y][x] == GOAL)
			{
				Novice::DrawSprite(x * KBlockSize, y * KBlockSize, goal, 1, 1, 0, WHITE);
			}
			if (map[y][x] == SYRUP)
			{
				Novice::DrawSprite(x * KBlockSize, y * KBlockSize, syrup, 1, 1, 0, WHITE);
			}
			if (map[y][x] == CANDY)
			{
				Novice::DrawSprite(x * KBlockSize, y * KBlockSize, candy, 1, 1, 0, WHITE);
			}
			if (map[y][x] == CARAMEL)
			{
				Novice::DrawSprite(x * KBlockSize, y * KBlockSize, caramel, 1, 1, 0, WHITE);
			}
		}
	}
}
