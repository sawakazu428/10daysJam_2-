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

int sceneNo = TITLE;
// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};
	//画像読み込み-----------------------------------------------------

	
	MapClass mapClass;

	mapClass.Initialize();
	mapClass.stage1();
	mapClass.stage2();
	mapClass.stage3();

	//Map Classに移動する
	int a = Novice::LoadTexture("./images/a.png");
	int i = Novice::LoadTexture("./images/i.png");
	int u = Novice::LoadTexture("./images/u.png");
	int e = Novice::LoadTexture("./images/e.png");
	int o = Novice::LoadTexture("./images/o.png");

	int ka = Novice::LoadTexture("./images/ka.png");
	int ki = Novice::LoadTexture("./images/ki.png");
	int ku = Novice::LoadTexture("./images/ku.png");
	int ke = Novice::LoadTexture("./images/ke.png");
	int ko = Novice::LoadTexture("./images/ko.png");

	int sa = Novice::LoadTexture("./images/sa.png");
	int shi = Novice::LoadTexture("./images/shi.png");
	int su = Novice::LoadTexture("./images/su.png");
	int se = Novice::LoadTexture("./images/se.png");
	int so = Novice::LoadTexture("./images/so.png");

	int ta = Novice::LoadTexture("./images/ta.png");
	int chi = Novice::LoadTexture("./images/chi.png");
	int tsu = Novice::LoadTexture("./images/tsu.png");
	int te = Novice::LoadTexture("./images/te.png");
	int to = Novice::LoadTexture("./images/to.png");
	
	int na = Novice::LoadTexture("./images/na.png");
	int ni = Novice::LoadTexture("./images/ni.png");
	int nu = Novice::LoadTexture("./images/nu.png");
	int ne = Novice::LoadTexture("./images/ne.png");
	int no = Novice::LoadTexture("./images/no.png");

	int ha = Novice::LoadTexture("./images/ha.png");
	int hi = Novice::LoadTexture("./images/hi.png");
	int hu = Novice::LoadTexture("./images/hu.png");
	int he = Novice::LoadTexture("./images/he.png");
	int ho = Novice::LoadTexture("./images/ho.png");

	int ma = Novice::LoadTexture("./images/ma.png");
	int mi = Novice::LoadTexture("./images/mi.png");
	int mu = Novice::LoadTexture("./images/mu.png");
	int me = Novice::LoadTexture("./images/me.png");
	int mo = Novice::LoadTexture("./images/mo.png");

	int ya = Novice::LoadTexture("./images/ya.png");
	int yu = Novice::LoadTexture("./images/yu.png");
	int yo = Novice::LoadTexture("./images/yo.png");

	int ra = Novice::LoadTexture("./images/ra.png");
	int ri = Novice::LoadTexture("./images/ri.png");
	int ru = Novice::LoadTexture("./images/ru.png");
	int re = Novice::LoadTexture("./images/re.png");
	int ro = Novice::LoadTexture("./images/ro.png");

	int wa = Novice::LoadTexture("./images/wa.png");
	int wo = Novice::LoadTexture("./images/wo.png");
	int nn = Novice::LoadTexture("./images/nn.png");

	int ga = Novice::LoadTexture("./images/ga.png");
	int gi = Novice::LoadTexture("./images/gi.png");
	int gu = Novice::LoadTexture("./images/gu.png");
	int ge = Novice::LoadTexture("./images/ge.png");
	int go = Novice::LoadTexture("./images/go.png");

	int za = Novice::LoadTexture("./images/za.png");
	int zi = Novice::LoadTexture("./images/zi.png");
	int zu = Novice::LoadTexture("./images/zu.png");
	int ze = Novice::LoadTexture("./images/ze.png");
	int zo = Novice::LoadTexture("./images/zo.png");

	int da = Novice::LoadTexture("./images/da.png");
	int di = Novice::LoadTexture("./images/di.png");
	int du = Novice::LoadTexture("./images/du.png");
	int de = Novice::LoadTexture("./images/de.png");
	int do = Novice::LoadTexture("./images/do.png");

	int ba = Novice::LoadTexture("./images/ba.png");
	int bi = Novice::LoadTexture("./images/bi.png");
	int bu = Novice::LoadTexture("./images/bu.png");
	int be = Novice::LoadTexture("./images/be.png");
	int bo = Novice::LoadTexture("./images/bo.png");

	int pa = Novice::LoadTexture("./images/pa.png");
	int pi = Novice::LoadTexture("./images/pi.png");
	int pu = Novice::LoadTexture("./images/pu.png");
	int pe = Novice::LoadTexture("./images/pe.png");
	int po = Novice::LoadTexture("./images/po.png");

	//タイマー (2023.09.05 タイマーは MapClassへ移動予定）
	//　STAGEを移動する時初期化する必要あり
	int goalTimer = 60;//ゴール
	int deathTimer = 60;//ゲームオーバー

	// goalFlag, gameOverFlag MapClassへ移動予定 STAGEを移動する時初期化する必要あり
	bool goalFlag = false;
	bool gameOverFlag = false;

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
			// SPACEを押したらSTAGE1に移動

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
			
=======

			// goalに入ったらgoalFlagがtrueになって次に移動
				if (map[playerMapY][playerMapX] == GOAL)
				{
					goalFlag == true;
					if (goalFlag == true)
					{
						goalTimer--;
						playerSpeed = 0;
						if (goalTimer == 0)
						{
							sceneNo = STAGE2;
						}
					｝

				}
			


			// gameOverFlagがtrueになればGAMEOVERに移動する
			if (gameOverFlag == true)
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
			
			// goalに入ったらgoalFlagがtrueになって次に移動
			if (map[playerMapY][playerMapX] == GOAL)
			{
				goalFlag == true;
				if (goalFlag == true)
				{
					goalTimer--;
					playerSpeed = 0;
					if (goalTimer == 0)
					{
						sceneNo = STAGE2;
					}
					｝

				}

			// gameOverFlagがtrueになればGAMEOVERに移動する
			if (gameOverFlag == true)
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

			// goalに入ったらgoalFlagがtrueになって次に移動
			if (map[playerMapY][playerMapX] == GOAL)
			{
				goalFlag == true;
				if (goalFlag == true)
				{
					goalTimer--;
					playerSpeed = 0;
					if (goalTimer == 0)
					{
						sceneNo = STAGE2;
					}
					｝

				}

			// gameOverFlagがtrueになればGAMEOVERに移動する
			if (gameOverFlag == true)
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
			// SPACEを押したらTITLEに移動
			if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0)
			{
				sceneNo = TITLE;
			}
			break;

		case GAMEOVER:
			// SPACEを押したらTITLEに移動
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

			Novice::DrawBox(0, 0, 1280, 720, 0, BLACK, kFillModeSolid);

			

	
			// Map Classに移動する STAGE2, STAGE3 にもコピー
			for (int y = 0; y < mapCountY; y++)
			{
				for (int x = 0; x < mapCountX; x++)
				{
					//あ
					if (map[y][x] == A)
					{
						Novice::DrawSprite(x* KBlockSize, y* KBlockSize, a, 1, 1, 0, WHITE);
					}
					if (map[y][x] == I)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, i, 1, 1, 0, WHITE);
					}
					if (map[y][x] == U)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, u, 1, 1, 0, WHITE);
					}
					if (map[y][x] == E)
					{
						Novice::DrawSprite(x* KBlockSize, y* KBlockSize, e, 1, 1, 0, WHITE);
					}
					if (map[y][x] == O)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, o, 1, 1, 0, WHITE);
					}

					//か
					if (map[y][x] == KA)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, ka, 1, 1, 0, WHITE);
					}
					if (map[y][x] == KI)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, ki, 1, 1, 0, WHITE);
					}
					if (map[y][x] == KU)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, ku, 1, 1, 0, WHITE);
					}
					if (map[y][x] == KE)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, ke, 1, 1, 0, WHITE);
					]
					if (map[y][x] == KO)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, ko, 1, 1, 0, WHITE);
					}

					//さ
					if (map[y][x] == SA)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, sa, 1, 1, 0, WHITE);
					}
					if (map[y][x] == SHI)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, si, 1, 1, 0, WHITE);
					}
					if (map[y][x] == SU)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, su, 1, 1, 0, WHITE);
					}
					if (map[y][x] == SE)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, ke, 1, 1, 0, WHITE);
					}
					if (map[y][x] == SO)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, so, 1, 1, 0, WHITE);
					}

					//た
					if (map[y][x] == TA)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, ta, 1, 1, 0, WHITE);
					}
					if (map[y][x] == CHI)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, chi, 1, 1, 0, WHITE);
					}
					if (map[y][x] == TSU)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, tsu, 1, 1, 0, WHITE);
					}
					if (map[y][x] == TE)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, te, 1, 1, 0, WHITE);
					}
					if (map[y][x] == TO)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, to, 1, 1, 0, WHITE);
					}

					//な
					if (map[y][x] == NA)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, na, 1, 1, 0, WHITE);
					}
					if (map[y][x] == NI)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, ni, 1, 1, 0, WHITE);
					}
					if (map[y][x] == NU)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, nu, 1, 1, 0, WHITE);
					}
					if (map[y][x] == NE)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, ne, 1, 1, 0, WHITE);
					}
					if (map[y][x] == NO)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, no, 1, 1, 0, WHITE);
					}

					//は
					if (map[y][x] == HA)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, ha, 1, 1, 0, WHITE);
					}
					if (map[y][x] == HI)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, hi, 1, 1, 0, WHITE);
					}
					if (map[y][x] == HU)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, hu, 1, 1, 0, WHITE);
					}
					if (map[y][x] == HE)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, he, 1, 1, 0, WHITE);
					}
					if (map[y][x] == HO)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, ho, 1, 1, 0, WHITE);
					}

					//ま
					if (map[y][x] == MA)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, ma, 1, 1, 0, WHITE);
					}
					if (map[y][x] == MI)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, mi, 1, 1, 0, WHITE);
					}
					if (map[y][x] == MU)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, mu, 1, 1, 0, WHITE);
					}
					if (map[y][x] == ME)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, me, 1, 1, 0, WHITE);
					}
					if (map[y][x] == MO)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, mo, 1, 1, 0, WHITE);
					}

					//や
					if (map[y][x] == YA)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, ya, 1, 1, 0, WHITE);
					}
					if (map[y][x] == YU)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, yu, 1, 1, 0, WHITE);
					}
					if (map[y][x] == YO)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, yo, 1, 1, 0, WHITE);
					}

					//ら
					if (map[y][x] == RA)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, ra, 1, 1, 0, WHITE);
					}
					if (map[y][x] == RI)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, ri, 1, 1, 0, WHITE);
					}
					if (map[y][x] == RU)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, ru, 1, 1, 0, WHITE);
					}
					if (map[y][x] == RE)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, re, 1, 1, 0, WHITE);
					}
					if (map[y][x] == RO)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, ro, 1, 1, 0, WHITE);
					}

					//わ
					if (map[y][x] == WA)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, wa, 1, 1, 0, WHITE);
					}
					if (map[y][x] == WO)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, wo, 1, 1, 0, WHITE);
					}
					if (map[y][x] == NN)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, nn, 1, 1, 0, WHITE);
					}

					//が
					if (map[y][x] == GA)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, ga, 1, 1, 0, WHITE);
					}
					if (map[y][x] == GI)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, gi, 1, 1, 0, WHITE);
					}
					if (map[y][x] == GU)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, gu, 1, 1, 0, WHITE);
					}
					if (map[y][x] == GE)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, ge, 1, 1, 0, WHITE);
					}
					if (map[y][x] == GO)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, go, 1, 1, 0, WHITE);
					}

					//ざ
					if (map[y][x] == ZA)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, za, 1, 1, 0, WHITE);
					}
					if (map[y][x] == ZI)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, zi, 1, 1, 0, WHITE);
					}
					if (map[y][x] == ZU)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, zu, 1, 1, 0, WHITE);
					}
					if (map[y][x] == ZE)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, ze, 1, 1, 0, WHITE);
					}
					if (map[y][x] == ZO)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, zo, 1, 1, 0, WHITE);
					}

					//だ
					if (map[y][x] == DA)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, da, 1, 1, 0, WHITE);
					}
					if (map[y][x] == DI)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, di, 1, 1, 0, WHITE);
					}
					if (map[y][x] == DU)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, du, 1, 1, 0, WHITE);
					}
					if (map[y][x] == DE)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, de, 1, 1, 0, WHITE);
					}
					if (map[y][x] == DO)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, do, 1, 1, 0, WHITE);
					}

					//ば
					if (map[y][x] == BA)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, ba, 1, 1, 0, WHITE);
					}
					if (map[y][x] == BI)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, bi, 1, 1, 0, WHITE);
					}
					if (map[y][x] == BU)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, bu, 1, 1, 0, WHITE);
					}
					if (map[y][x] == BE)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, be, 1, 1, 0, WHITE);
					}
					if (map[y][x] == BO)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, bo, 1, 1, 0, WHITE);
					}

					//ぱ
					if (map[y][x] == PA)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, pa, 1, 1, 0, WHITE);
					}
					if (map[y][x] == PI)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, pi, 1, 1, 0, WHITE);
					}
					if (map[y][x] == PU)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, pu, 1, 1, 0, WHITE);
					}
					if (map[y][x] == PE)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, pe, 1, 1, 0, WHITE);
					}
					if (map[y][x] == PO)
					{
						Novice::DrawSprite(x * KBlockSize, y * KBlockSize, po, 1, 1, 0, WHITE);
					}
				}
			}

			break;
			
		case STAGE2:
			Novice::DrawBox(0, 0, 1280, 720, 0, BLACK, kFillModeSolid);

			break;

		case STAGE3:
			Novice::DrawBox(0, 0, 1280, 720, 0, BLACK, kFillModeSolid);
			
			break;

		case GAMECLEAR:
			Novice::DrawSprite(0, 0, gameClear, 2, 2, 0, WHITE);
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
