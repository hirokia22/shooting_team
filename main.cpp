#include "Game.h"
// ウィンドウのタイトルに表示する文字列
const char TITLE[] = "xx2x_xx_ナマエ: タイトル";

// ウィンドウ横幅
const int WIN_WIDTH = 600;

// ウィンドウ縦幅
const int WIN_HEIGHT = 800;
enum Scene {
	GAMETITLE,
	RULE,
	GAME,
	CLEAR,
	OVER
};
Scene scene = GAMETITLE;
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,
	_In_ int nCmdShow) {
	// ウィンドウモードに設定
	ChangeWindowMode(TRUE);

	// ウィンドウサイズを手動では変更させず、
	// かつウィンドウサイズに合わせて拡大できないようにする
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// タイトルを変更
	SetMainWindowText(TITLE);

	// 画面サイズの最大サイズ、カラービット数を設定(モニターの解像度に合わせる)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// 画面サイズを設定(解像度との比率で設定)
	SetWindowSizeExtendRate(1.0);

	// 画面の背景色を設定する
	SetBackgroundColor(0x00, 0x00, 0x00);

	// DXlibの初期化
	if (DxLib_Init() == -1) { return -1; }

	// (ダブルバッファ)描画先グラフィック領域は裏面を指定
	SetDrawScreen(DX_SCREEN_BACK);

	// 画像などのリソースデータの変数宣言と読み込み
	int titleGraph = LoadGraph("Resource/title.png", true);
	int rule_1 = LoadGraph("Resource/RULE1.png", true);
	int rule_2 = LoadGraph("Resource/RULE2.png", true);
	int rule_3 = LoadGraph("Resource/RULE3.png", true);
	int gameover = LoadGraph("Resource/gameover.png", true);
	int clear = LoadGraph("Resource/gameclear.png", true);
	// ゲームループで使う変数の宣言
	Game* game_ = new Game;
	int ruleNum = 0;
	int gamemode = 0;
	// 最新のキーボード情報用
	char keys[256] = { 0 };

	// 1ループ(フレーム)前のキーボード情報
	char oldkeys[256] = { 0 };

	// ゲームループ
	while (true) {
		// 最新のキーボード情報だったものは1フレーム前のキーボード情報として保存
		for (int i = 0; i < 256; ++i) {
			oldkeys[i] = keys[i];
		}
		// 最新のキーボード情報を取得
		GetHitKeyStateAll(keys);

		// 画面クリア
		ClearDrawScreen();
		//---------  ここからプログラムを記述  ----------//
		switch (scene) {
		case GAMETITLE:
			if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
				scene = RULE;
			}
			//初期化
			ruleNum = 0;
			gamemode = 0;
			game_->Initialize();
			DrawGraph(0, 0, titleGraph, true);
			break;
		case RULE:
			if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
				if (ruleNum >= 2) {
					scene = GAME;
				}
				ruleNum++;
			}
			if (ruleNum == 0) {
				DrawGraph(0, 0, rule_1, true);
			}
			else if (ruleNum == 1) {
				DrawGraph(0, 0, rule_2, true);
			}
			else if (ruleNum == 2) {
				DrawGraph(0, 0, rule_3, true);
			}
			break;
		case GAME:
			gamemode = game_->Update(keys);
			if (gamemode == 1) {
				scene = OVER;
			}
			else if (gamemode == 2) {
				scene = CLEAR;
			}
			game_->Draw();
			break;
		case CLEAR:
			if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
				scene = GAMETITLE;
			}
			DrawGraph(0, 0, clear, true);
			break;
		case OVER:
			if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
				scene = GAMETITLE;
			}
			DrawGraph(0, 0, gameover, true);
			break;
		}
		//---------  ここまでにプログラムを記述  ---------//
		// (ダブルバッファ)裏面
		ScreenFlip();

		// 20ミリ秒待機(疑似60FPS)
		WaitTimer(20);

		// Windowsシステムからくる情報を処理する
		if (ProcessMessage() == -1) {
			break;
		}

		// ESCキーが押されたらループから抜ける
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}
	}
	// Dxライブラリ終了処理
	DxLib_End();
	delete game_;
	// 正常終了
	return 0;
}
