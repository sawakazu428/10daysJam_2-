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
		

			//状態変化--------------------------------------------------------------------------------------------------
			


			//ゴール条件---------------------------------
		
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
			

			Novice::DrawSprite(playerPosX, playerPosY, player, 1, 1, 0, WHITE);
			Novice::DrawSprite(864, 0, MANUAL, 1, 1, 0, WHITE);
			break;

		case STAGE2:
			Novice::DrawBox(0, 0, 1280, 720, 0, BLACK, kFillModeSolid);
			
			Novice::DrawSprite(playerPosX, playerPosY, player, 1, 1, 0, WHITE);
			Novice::DrawSprite(864, 0, MANUAL, 1, 1, 0, WHITE);
			break;

		case STAGE3:
			Novice::DrawBox(0, 0, 1280, 720, 0, BLACK, kFillModeSolid);
			
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
