#include <Novice.h>
#include "MapClass.h"

const char kWindowTitle[] = "GC2B_04_サワダカズキ";

enum SCENE {
	TITLE,//タイトル画面
	STAGE1,//ゲーム画面
	STAGE2,
	STAGE3,
	GAMECLEAR,//ゲームクリア
	GAMECLEAR2,//STAGE2
	GAMECLEAR3,//STAGE3
	GAMEOVER,//ゲームオーバー
	GAMEOVER2,//STAGE2
};

int sceneNo = TITLE;
// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};
	//画像読み込み-----------------------------------------------------------
	int thorn = Novice::LoadTexture("./images/THORN.png");
	int block = Novice::LoadTexture("./images/block.png");
	int syrup = Novice::LoadTexture("./images/SYRUP.png");
	int candy = Novice::LoadTexture("./images/CANDY.png");
	int caramel = Novice::LoadTexture("./images/CARAMEL.png");
	int goal = Novice::LoadTexture("./images/GOALS.png");
	int player = Novice::LoadTexture("./images/player.png");
	int gameClear = Novice::LoadTexture("./images/GAMECLEARR.png");
	int gameOver = Novice::LoadTexture("./images/GAMEOVERR.png");
	int title = Novice::LoadTexture("./images/TITLE.png");
	int MANUAL = Novice::LoadTexture("./images/MANUALS.png");

	//ブロックサイズの設定
	const int KBlockSize = 32;
	int playerPosX = 13 * KBlockSize;
	int playerPosY = 576;
	int playerR = 32;
	int playerSpeed = KBlockSize;

	int playerTmpX = 0;
	int playerTmpY = 0;
	int playerMapX = 0;
	int playerMapY = 0;

	MapClass mapClass;

	//ステージ2
	/*int playerPosX = 13 * KBlockSize;
	int playerPosY = 320;*/


	//タイマー
	int goalTimer = 60;//ゴール
	int caramelTimer = 200;//カラメル
	int deathTimer = 60;//ゲームオーバー	

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

	mapClass.Initialize();
	mapClass.stage1();
	mapClass.stage2();
	mapClass.stage3();

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		switch (sceneNo)
		{
		case TITLE:
			//初期化------------------------------------------------------------
			goalTimer = 60;
			deathTimer = 60;
			playerPosY = 576;
			playerSpeed = KBlockSize;
			mapClass.Initialize();
			mapClass.stage1();
			//--------------------------------------------------------------------
			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0)
			{
				sceneNo = STAGE1;
			}

			break;

		case STAGE1:
			//マップ情報-----------------------------------------------------------------------------------
			playerMapX = playerPosX / KBlockSize;//map[x][]
			playerMapY = playerPosY / KBlockSize;//map[][y]

			mapClass.Update();

			//リスタート
			if (keys[DIK_R] && preKeys[DIK_R] == 0)
			{
				goalTimer = 60;//初期化
				deathTimer = 60;
				playerPosX = 13 * KBlockSize;//プレイヤーの位置
				playerPosY = 576;
				playerSpeed = KBlockSize;
				// map初期化
				mapClass.stage1();
			}

			//プレイヤー移動-------------------------------------------------------------------------------
			if (keys[DIK_W] && preKeys[DIK_W] == 0 || keys[DIK_UP] && preKeys[DIK_UP] == 0)
			{
				playerTmpY = playerPosY - playerSpeed;
				playerMapY = playerTmpY / KBlockSize;
				//何もないから実際に進ませる
				if (map[playerMapY][playerMapX] == YUKA)
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
				if (map[playerMapY][playerMapX] == A ||)
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

			//状態変化--------------------------------------------------------------------------------------------------
		
			//ゴール条件---------------------------------
			if (map[playerMapY][playerMapX] == GOAL)
			{
				goalTimer--;
				playerSpeed = 0;
				if (goalTimer == 0)
				{
					sceneNo = GAMECLEAR;
				}
			}
			

			if (map[playerMapY][playerMapX] == THORN)
			{
				deathTimer--;
				playerSpeed = 0;
				if (deathTimer == 0)
				{
					sceneNo = GAMEOVER;
				}
			}
			break;

		case STAGE2:
			//マップ情報-----------------------------------------------------------------------------------
			playerMapX = playerPosX / KBlockSize;//map[x][]
			playerMapY = playerPosY / KBlockSize;//map[][y]
			mapClass.Update();
			//リスタート
			if (keys[DIK_R] && preKeys[DIK_R] == 0)
			{
				goalTimer = 60;//初期化
				deathTimer = 60;
				playerPosX = 1 * KBlockSize;//プレイヤーの位置
				playerPosY = 20 * KBlockSize;
				playerSpeed = KBlockSize;
				mapClass.stage2();
			}

			//プレイヤー移動-------------------------------------------------------------------------------
			if (keys[DIK_W] && preKeys[DIK_W] == 0 || keys[DIK_UP] && preKeys[DIK_UP] == 0)
			{
				playerTmpY = playerPosY - playerSpeed;
				playerMapY = playerTmpY / KBlockSize;
				//何もないから実際に進ませる
				if (map2[playerMapY][playerMapX] == YUKA)
				{
					playerPosY -= playerSpeed;
				}
				if (map2[playerMapY][playerMapX] == GOAL)
				{
					playerPosY -= playerSpeed;
				}
				if (map2[playerMapY][playerMapX] == THORN)
				{
					playerPosY -= playerSpeed;
				}
				if (map2[playerMapY][playerMapX] == SYRUP)
				{
					if (map2[playerMapY - 1][playerMapX] == YUKA)
					{
						map2[playerMapY][playerMapX] = YUKA;
						map2[playerMapY - 1][playerMapX] = SYRUP;
						playerPosY -= playerSpeed;
					}
				}
			}

			if (keys[DIK_A] && preKeys[DIK_A] == 0 || keys[DIK_LEFT] && preKeys[DIK_LEFT] == 0)
			{
				playerTmpX = playerPosX - playerSpeed;
				playerMapX = playerTmpX / KBlockSize;
				//何もないから実際に進ませる
				if (map2[playerMapY][playerMapX] == YUKA)
				{
					playerPosX -= playerSpeed;
				}
				if (map2[playerMapY][playerMapX] == GOAL)
				{
					playerPosX -= playerSpeed;
				}
				if (map2[playerMapY][playerMapX] == THORN)
				{
					playerPosX -= playerSpeed;
				}
				if (map2[playerMapY][playerMapX] == SYRUP)
				{
					if (map2[playerMapY][playerMapX - 1] == YUKA)
					{
						map2[playerMapY][playerMapX] = YUKA;
						map2[playerMapY][playerMapX - 1] = SYRUP;
						playerPosX -= playerSpeed;
					}
				}
			}

			if (keys[DIK_D] && preKeys[DIK_D] == 0 || keys[DIK_RIGHT] && preKeys[DIK_RIGHT] == 0)
			{
				playerTmpX = playerPosX + playerSpeed;
				playerMapX = playerTmpX / KBlockSize;
				//何もないから実際に進ませる
				if (map2[playerMapY][playerMapX] == YUKA)
				{
					playerPosX += playerSpeed;
				}
				if (map2[playerMapY][playerMapX] == GOAL)
				{
					playerPosX += playerSpeed;
				}
				if (map2[playerMapY][playerMapX] == THORN)
				{
					playerPosX += playerSpeed;
				}
				if (map2[playerMapY][playerMapX] == SYRUP)
				{
					if (map2[playerMapY][playerMapX + 1] == YUKA)
					{
						map2[playerMapY][playerMapX] = YUKA;
						map2[playerMapY][playerMapX + 1] = SYRUP;
						playerPosX += playerSpeed;
					}
				}
			}

			if (keys[DIK_S] && preKeys[DIK_S] == 0 || keys[DIK_DOWN] && preKeys[DIK_DOWN] == 0)
			{
				playerTmpY = playerPosY + playerSpeed;
				playerMapY = playerTmpY / KBlockSize;
				//何もないから実際に進ませる
				if (map2[playerMapY][playerMapX] == YUKA)
				{
					playerPosY += playerSpeed;
				}
				if (map2[playerMapY][playerMapX] == GOAL)
				{
					playerPosY += playerSpeed;
				}
				if (map2[playerMapY][playerMapX] == THORN)
				{
					playerPosY += playerSpeed;
				}
				//シロップを動かす処理
				if (map2[playerMapY][playerMapX] == SYRUP)
				{
					if (map2[playerMapY + 1][playerMapX] == YUKA)
					{
						map2[playerMapY][playerMapX] = YUKA;
						map2[playerMapY + 1][playerMapX] = SYRUP;
						playerPosY += playerSpeed;
					}
				}
			}

			//状態変化--------------------------------------------------------------------------------------------------
			


			//ゴール条件---------------------------------
			if (map2[playerMapY][playerMapX] == GOAL)
			{
				goalTimer--;
				playerSpeed = 0;
				if (goalTimer == 0)
				{
					sceneNo = GAMECLEAR2;
				}
			}

			if (map2[playerMapY][playerMapX] == THORN)
			{
				deathTimer--;
				playerSpeed = 0;
				if (deathTimer == 0)
				{
					sceneNo = GAMEOVER;
				}
			}

			break;

		case STAGE3:
			//マップ情報-----------------------------------------------------------------------------------
			playerMapX = playerPosX / KBlockSize;//map[x][]
			playerMapY = playerPosY / KBlockSize;//map[][y]

			mapClass.Update();
			//リスタート
			if (keys[DIK_R] && preKeys[DIK_R] == 0)
			{
				goalTimer = 60;//初期化
				deathTimer = 60;
				playerPosX = 12 * KBlockSize;//プレイヤーの位置
				playerPosY = 18 * KBlockSize;
				playerSpeed = KBlockSize;
				mapClass.stage3();
			}

			//プレイヤー移動-------------------------------------------------------------------------------
			if (keys[DIK_W] && preKeys[DIK_W] == 0 || keys[DIK_UP] && preKeys[DIK_UP] == 0)
			{
				playerTmpY = playerPosY - playerSpeed;
				playerMapY = playerTmpY / KBlockSize;
				//何もないから実際に進ませる
				if (map3[playerMapY][playerMapX] == YUKA)
				{
					playerPosY -= playerSpeed;
				}
				if (map3[playerMapY][playerMapX] == GOAL)
				{
					playerPosY -= playerSpeed;
				}
				if (map3[playerMapY][playerMapX] == THORN)
				{
					playerPosY -= playerSpeed;
				}
				if (map3[playerMapY][playerMapX] == SYRUP)
				{
					if (map3[playerMapY - 1][playerMapX] == YUKA)
					{
						map3[playerMapY][playerMapX] = YUKA;
						map3[playerMapY - 1][playerMapX] = SYRUP;
						playerPosY -= playerSpeed;
					}
				}
			}

			if (keys[DIK_A] && preKeys[DIK_A] == 0 || keys[DIK_LEFT] && preKeys[DIK_LEFT] == 0)
			{
				playerTmpX = playerPosX - playerSpeed;
				playerMapX = playerTmpX / KBlockSize;
				//何もないから実際に進ませる
				if (map3[playerMapY][playerMapX] == YUKA)
				{
					playerPosX -= playerSpeed;
				}
				if (map3[playerMapY][playerMapX] == GOAL)
				{
					playerPosX -= playerSpeed;
				}
				if (map3[playerMapY][playerMapX] == THORN)
				{
					playerPosX -= playerSpeed;
				}
				if (map3[playerMapY][playerMapX] == SYRUP)
				{
					if (map3[playerMapY][playerMapX - 1] == YUKA)
					{
						map3[playerMapY][playerMapX] = YUKA;
						map3[playerMapY][playerMapX - 1] = SYRUP;
						playerPosX -= playerSpeed;
					}
				}
			}

			if (keys[DIK_D] && preKeys[DIK_D] == 0 || keys[DIK_RIGHT] && preKeys[DIK_RIGHT] == 0)
			{
				playerTmpX = playerPosX + playerSpeed;
				playerMapX = playerTmpX / KBlockSize;
				//何もないから実際に進ませる
				if (map3[playerMapY][playerMapX] == YUKA)
				{
					playerPosX += playerSpeed;
				}
				if (map3[playerMapY][playerMapX] == GOAL)
				{
					playerPosX += playerSpeed;
				}
				if (map3[playerMapY][playerMapX] == THORN)
				{
					playerPosX += playerSpeed;
				}
				if (map3[playerMapY][playerMapX] == SYRUP)
				{
					if (map3[playerMapY][playerMapX + 1] == YUKA)
					{
						map3[playerMapY][playerMapX] = YUKA;
						map3[playerMapY][playerMapX + 1] = SYRUP;
						playerPosX += playerSpeed;
					}
				}
			}

			if (keys[DIK_S] && preKeys[DIK_S] == 0 || keys[DIK_DOWN] && preKeys[DIK_DOWN] == 0)
			{
				playerTmpY = playerPosY + playerSpeed;
				playerMapY = playerTmpY / KBlockSize;
				//何もないから実際に進ませる
				if (map3[playerMapY][playerMapX] == YUKA)
				{
					playerPosY += playerSpeed;
				}
				if (map3[playerMapY][playerMapX] == GOAL)
				{
					playerPosY += playerSpeed;
				}
				if (map3[playerMapY][playerMapX] == THORN)
				{
					playerPosY += playerSpeed;
				}
				//シロップを動かす処理
				if (map3[playerMapY][playerMapX] == SYRUP)
				{
					if (map3[playerMapY + 1][playerMapX] == YUKA)
					{
						map3[playerMapY][playerMapX] = YUKA;
						map3[playerMapY + 1][playerMapX] = SYRUP;
						playerPosY += playerSpeed;
					}
				}
			}

			//状態変化--------------------------------------------------------------------------------------------------
			

			//ゴール条件---------------------------------
			if (map3[playerMapY][playerMapX] == GOAL)
			{
				goalTimer--;
				playerSpeed = 0;
				if (goalTimer == 0)
				{
					sceneNo = GAMECLEAR3;
				}
			}

			if (map3[playerMapY][playerMapX] == THORN)
			{
				deathTimer--;
				playerSpeed = 0;
				if (deathTimer == 0)
				{
					sceneNo = GAMEOVER;
				}
			}

			break;

		case GAMECLEAR:
			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0)
			{
				playerPosX = 1 * KBlockSize;//プレイヤーの位置
				playerPosY = 20 * KBlockSize;
				playerMapX = playerPosX / KBlockSize;//map[x][]
				playerMapY = playerPosY / KBlockSize;//map[][y]
				playerSpeed = KBlockSize;
				goalTimer = 60;

				sceneNo = STAGE2;
			}
			break;

		case GAMECLEAR2:
			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0)
			{
				playerPosX = 12 * KBlockSize;//プレイヤーの位置
				playerPosY = 18 * KBlockSize;
				playerMapX = playerPosX / KBlockSize;//map[x][]
				playerMapY = playerPosY / KBlockSize;//map[][y]
				playerSpeed = KBlockSize;
				goalTimer = 60;

				sceneNo = STAGE3;
			}
			break;

		case GAMECLEAR3:
			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0)
			{
				sceneNo = TITLE;
			}
			break;


		case GAMEOVER:
			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0)
			{
				sceneNo = TITLE;
			}
			break;
		}
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		switch (sceneNo)
		{
		case TITLE:
			Novice::DrawSprite(0, 0, title, 2, 2.3, 0, WHITE);
			break;
		case STAGE1:
			//数値見やすく--------------------------------------------------------------
			/*Novice::ScreenPrintf(865, 32, "goalTimer=%d", goalTimer);
			Novice::ScreenPrintf(865, 64, "deathTimer=%d",deathTimer);
			Novice::ScreenPrintf(865, 96, "playerSpeed=%d", playerSpeed);
			Novice::ScreenPrintf(865, 128, "caramelTimer=%d", caramelTimer);*/



			Novice::DrawBox(0, 0, 1280, 720, 0, BLACK, kFillModeSolid);
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

			Novice::DrawSprite(playerPosX, playerPosY, player, 1, 1, 0, WHITE);
			Novice::DrawSprite(864, 0, MANUAL, 1, 1, 0, WHITE);
			break;

		case STAGE2:
			Novice::DrawBox(0, 0, 1280, 720, 0, BLACK, kFillModeSolid);
			for (int y = 0; y < mapCountY2; y++)
			{
				for (int x = 0; x < mapCountX2; x++)
				{
					if (map2[y][x] == YUKA)
					{
						Novice::DrawBox(x * KBlockSize, y * KBlockSize, KBlockSize, KBlockSize, 0, BLUE, kFillModeSolid);
					}
					if (map2[y][x] == BLOCK)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, block, 1, 1, 0, WHITE);
					}
					if (map2[y][x] == THORN)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, thorn, 1, 1, 0, WHITE);
					}
					if (map2[y][x] == BLOCK2)
					{
						Novice::DrawBox(x * KBlockSize, y * KBlockSize, KBlockSize, KBlockSize, 0, RED, kFillModeSolid);
					}
					if (map2[y][x] == GOAL)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, goal, 1, 1, 0, WHITE);
					}
					if (map2[y][x] == SYRUP)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, syrup, 1, 1, 0, WHITE);
					}
					if (map2[y][x] == CANDY)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, candy, 1, 1, 0, WHITE);
					}
					if (map2[y][x] == CARAMEL)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, caramel, 1, 1, 0, WHITE);
					}
				}
			}
			Novice::DrawSprite(playerPosX, playerPosY, player, 1, 1, 0, WHITE);
			Novice::DrawSprite(864, 0, MANUAL, 1, 1, 0, WHITE);
			break;

		case STAGE3:
			Novice::DrawBox(0, 0, 1280, 720, 0, BLACK, kFillModeSolid);
			for (int y = 0; y < mapCountY3; y++)
			{
				for (int x = 0; x < mapCountX3; x++)
				{
					if (map3[y][x] == YUKA)
					{
						Novice::DrawBox(x * KBlockSize, y * KBlockSize, KBlockSize, KBlockSize, 0, BLUE, kFillModeSolid);
					}
					if (map3[y][x] == BLOCK)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, block, 1, 1, 0, WHITE);
					}
					if (map3[y][x] == THORN)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, thorn, 1, 1, 0, WHITE);
					}
					if (map3[y][x] == BLOCK2)
					{
						Novice::DrawBox(x * KBlockSize, y * KBlockSize, KBlockSize, KBlockSize, 0, RED, kFillModeSolid);
					}
					if (map3[y][x] == GOAL)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, goal, 1, 1, 0, WHITE);
					}
					if (map3[y][x] == SYRUP)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, syrup, 1, 1, 0, WHITE);
					}
					if (map3[y][x] == CANDY)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, candy, 1, 1, 0, WHITE);
					}
					if (map3[y][x] == CARAMEL)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, caramel, 1, 1, 0, WHITE);
					}
				}
			}
			Novice::DrawSprite(playerPosX, playerPosY, player, 1, 1, 0, WHITE);
			Novice::DrawSprite(864, 0, MANUAL, 1, 1, 0, WHITE);
			break;

		case GAMECLEAR:
			Novice::DrawSprite(0, 0, gameClear, 2, 2, 0, WHITE);
			break;

		case GAMECLEAR2:
			Novice::DrawSprite(0, 0, gameClear, 2, 2, 0, WHITE);
			break;

		case GAMECLEAR3:
			Novice::DrawSprite(0, 0, gameClear, 2, 2, 0, WHITE);
			break;

		case GAMEOVER2:
			Novice::DrawSprite(0, 0, gameOver, 2, 2, 0, WHITE);
			break;

		case GAMEOVER:
			Novice::DrawSprite(0, 0, gameOver, 2, 2, 0, WHITE);
			break;

		}

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
