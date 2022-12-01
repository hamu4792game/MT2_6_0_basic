#include <Novice.h>
#include "Matrix.h"

const char* kWindowTitle = "学籍番号";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR lpCmdLine, _In_ int nShowCmd) {

	// ライブラリの初期化
	int kWindowWidth = 1280, kWindowHeight = 720;
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Matrix2x2 m1;
	m1.m1[0][0] = 1.0f;	m1.m1[0][1] = 2.0f;
	m1.m1[1][0] = 3.0f;	m1.m1[1][1] = 4.0f;

	Matrix3x3 m2;
	m2.m2[0][0] = 1.0f;	m2.m2[0][1] = 2.0f;	m2.m2[0][2] = 0.0f;
	m2.m2[1][0] = 3.0f;	m2.m2[1][1] = 4.0f;	m2.m2[1][2] = 0.0f;
	m2.m2[2][0] = 5.0f;	m2.m2[2][1] = 6.0f;	m2.m2[2][2] = 1.0f;

	Matrix2x2 InverseM1;
	Matrix3x3 InverseM2;

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

		InverseM1 = Inverse(m1);
		InverseM2 = Inverse(m2);

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		MatrixScreenPrintf(0, kRowHeight * 0, InverseM1);
		MatrixScreenPrintf(0, kRowHeight * 2 + 10, InverseM2);

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
