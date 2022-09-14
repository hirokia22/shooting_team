#include "Game.h"
// �E�B���h�E�̃^�C�g���ɕ\�����镶����
const char TITLE[] = "xx2x_xx_�i�}�G: �^�C�g��";

// �E�B���h�E����
const int WIN_WIDTH = 600;

// �E�B���h�E�c��
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
	// �E�B���h�E���[�h�ɐݒ�
	ChangeWindowMode(TRUE);

	// �E�B���h�E�T�C�Y���蓮�ł͕ύX�������A
	// ���E�B���h�E�T�C�Y�ɍ��킹�Ċg��ł��Ȃ��悤�ɂ���
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// �^�C�g����ύX
	SetMainWindowText(TITLE);

	// ��ʃT�C�Y�̍ő�T�C�Y�A�J���[�r�b�g����ݒ�(���j�^�[�̉𑜓x�ɍ��킹��)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// ��ʃT�C�Y��ݒ�(�𑜓x�Ƃ̔䗦�Őݒ�)
	SetWindowSizeExtendRate(1.0);

	// ��ʂ̔w�i�F��ݒ肷��
	SetBackgroundColor(0x00, 0x00, 0x00);

	// DXlib�̏�����
	if (DxLib_Init() == -1) { return -1; }

	// (�_�u���o�b�t�@)�`���O���t�B�b�N�̈�͗��ʂ��w��
	SetDrawScreen(DX_SCREEN_BACK);

	// �摜�Ȃǂ̃��\�[�X�f�[�^�̕ϐ��錾�Ɠǂݍ���
	int titleGraph = LoadGraph("Resource/title.png", true);
	int rule_1 = LoadGraph("Resource/RULE1.png", true);
	int rule_2 = LoadGraph("Resource/RULE2.png", true);
	int rule_3 = LoadGraph("Resource/RULE3.png", true);
	int gameover = LoadGraph("Resource/gameover.png", true);
	int clear = LoadGraph("Resource/gameclear.png", true);
	// �Q�[�����[�v�Ŏg���ϐ��̐錾
	Game* game_ = new Game;
	int ruleNum = 0;
	int gamemode = 0;
	// �ŐV�̃L�[�{�[�h���p
	char keys[256] = { 0 };

	// 1���[�v(�t���[��)�O�̃L�[�{�[�h���
	char oldkeys[256] = { 0 };

	// �Q�[�����[�v
	while (true) {
		// �ŐV�̃L�[�{�[�h��񂾂������̂�1�t���[���O�̃L�[�{�[�h���Ƃ��ĕۑ�
		for (int i = 0; i < 256; ++i) {
			oldkeys[i] = keys[i];
		}
		// �ŐV�̃L�[�{�[�h�����擾
		GetHitKeyStateAll(keys);

		// ��ʃN���A
		ClearDrawScreen();
		//---------  ��������v���O�������L�q  ----------//
		switch (scene) {
		case GAMETITLE:
			if (keys[KEY_INPUT_SPACE] == 1 && oldkeys[KEY_INPUT_SPACE] == 0) {
				scene = RULE;
			}
			//������
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
		//---------  �����܂łɃv���O�������L�q  ---------//
		// (�_�u���o�b�t�@)����
		ScreenFlip();

		// 20�~���b�ҋ@(�^��60FPS)
		WaitTimer(20);

		// Windows�V�X�e�����炭�������������
		if (ProcessMessage() == -1) {
			break;
		}

		// ESC�L�[�������ꂽ�烋�[�v���甲����
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}
	}
	// Dx���C�u�����I������
	DxLib_End();
	delete game_;
	// ����I��
	return 0;
}
