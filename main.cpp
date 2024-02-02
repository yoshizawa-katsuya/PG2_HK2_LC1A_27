#include <Novice.h>
#include "Struct.h"
#include "Scene.h"
#include "Start.h"
#include "Game.h"
#include "Clear.h"
#include "Over.h"

const char kWindowTitle[] = "LC1A_27_ヨシザワ_カツヤ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	//シーン
	int SceneNo = START;

	Start* start = new Start;
	Game* game = NULL;
	Clear* clear = NULL;
	Over* over = NULL;
	

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

		switch (SceneNo)
		{
		case START:

			start->Update(keys, preKeys, &SceneNo);

			if (SceneNo != START) {
				delete start;
				game = new Game;
			}

			break;

		case GAME:

			game->Update(keys, preKeys, &SceneNo);

			if (SceneNo != GAME) {
				delete game;
				if (SceneNo == CLEAR) {
					clear = new Clear;
				}
				else if (SceneNo == OVER) {
					over = new Over;
				}
			}

			break;

		case CLEAR:

			clear->Update(keys, preKeys, &SceneNo);

			if (SceneNo != CLEAR) {
				delete clear;
				start = new Start;	
			}

			break;

		case OVER:

			over->Update(keys, preKeys, &SceneNo);

			if (SceneNo != OVER) {
				delete over;
				start = new Start;
			}

			break;

		default:

			break;
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		switch (SceneNo)
		{
		case START:

			start->Draw();

			break;

		case GAME:

			game->Draw();

			break;

		case CLEAR:

			clear->Draw();

			break;

		case OVER:

			over->Draw();

			break;

		default:

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
