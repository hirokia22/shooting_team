#include "Hero.h"
#include"DxLib.h"

Hero::Hero() {}
Hero::~Hero() {}
void Hero::Initialize() {
	posX = 300.0f;
	posY = 640.0f;
	speed_M = 2.0f;
	speed_A = 2.0f;
	HP = 3;
	shotTimer = 60.0f;
	heromode = 1;
	shotTimerM = 30.0f;
}
void Hero::Update(char* key,bool& moveFlag) {
	//デスフラグのたった弾を削除
	Hbullets_.remove_if([](std::unique_ptr<Hero_B>& bullet) {
		return bullet->IsDead();
		});
	if (moveFlag == true) {
		Manual(key);
		Shot(key);
	}
	else if (moveFlag == false) {
		Auto();
	}
	//弾の更新処理
	for (std::unique_ptr<Hero_B>& bullet : Hbullets_) {
		bullet->Update();
	}
	if (HP <= 0) {
		heromode = 0;
	}
}
void Hero::Manual(char* key) {
	if (posX >= 0 && posX <= 600) {
		if (key[KEY_INPUT_A]) {
			posX -= speed_M;
		}
		else if (key[KEY_INPUT_D]) {
			posX += speed_M;
		}
	}
}
void Hero::Auto() {
	//移動
	posX+=speed_A;
	if ((posX <= 0) || (posX >= 600) ){
		speed_A = -speed_A;
	}
	AutoShot();
}

void Hero::Shot(char *key) {
	if (shotTimerM >= 0) {
		shotTimerM--;
	}
	if (shotTimerM <= 0) {
		if (key[KEY_INPUT_SPACE]) {
			//弾を生成し、初期化
			std::unique_ptr<Hero_B> newBullet = std::make_unique<Hero_B>();
			newBullet->Initialize(posX, posY);

			Hbullets_.push_back(std::move(newBullet));
			shotTimerM = 30.0f;
		}
	}
}
void Hero::AutoShot() {
	if (--shotTimer <= 0) {
		//弾を生成し、初期化
		std::unique_ptr<Hero_B> newBullet = std::make_unique<Hero_B>();
		newBullet->Initialize(posX, posY);

		Hbullets_.push_back(std::move(newBullet));
		shotTimer = 60.0f;
	}
}

void Hero::Draw() {
	DrawGraph(posX, posY, heroGraph, TRUE);
	for (std::unique_ptr<Hero_B>& bullet : Hbullets_) {
		bullet->Draw();
	}
	DrawFormatString(0, 0, GetColor(111, 111, 111), "%f,%f", posX, posY, true);
}
void Hero::OnCollision() {
	HP--;
}