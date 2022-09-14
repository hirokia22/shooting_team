#include "Enemy.h"
#include"DxLib.h"

Enemy::Enemy(){}
Enemy::~Enemy(){}
void Enemy::Initialize() {
	posX = 300.0f;
	posY = 160.0f;
	speed_M = 1.0f;
	speed_A = 1.0f;
	HP = 100;
	shotTimer = 60.0f;
	enemymode = 1;
    shotTimerM = 60.0f;
}
void Enemy::Update(char* key, bool& moveFlag) {
	//デスフラグのたった弾を削除
	Ebullets_.remove_if([](std::unique_ptr<Enemy_B>& bullet) {
		return bullet->IsDead();
		});
	if (moveFlag == false) {
		Manual(key);
		Shot(key);
	}
	else if (moveFlag == true) {
		Auto();
	}
	//弾の更新処理
	for (std::unique_ptr<Enemy_B>& bullet : Ebullets_) {
		bullet->Update();
	}
	if (HP <= 0) {
		enemymode = 0;
	}
}
void Enemy::Manual(char* key) {
	if (posX >= 1 && posX <= 535) {
		if (key[KEY_INPUT_A]) {
			posX -= speed_M;
		}
		else if (key[KEY_INPUT_D]) {
			posX += speed_M;
		}
	}
}
void Enemy::Auto() {
	//移動
	posX += speed_A;
	if ((posX <= 0) || (posX >= 536)) {
		speed_A = -speed_A;
	}
	AutoShot();
}

void Enemy::Shot(char* key) {
	if (shotTimerM >= 0) {
		shotTimerM--;
	}
	if (shotTimerM <= 0) {
		if (key[KEY_INPUT_SPACE]) {
			//弾を生成し、初期化
			std::unique_ptr<Enemy_B> newBullet = std::make_unique<Enemy_B>();
			newBullet->Initialize(posX, posY);

			Ebullets_.push_back(std::move(newBullet));
			shotTimerM = 30.0f;
		}
	}
}
void Enemy::AutoShot() {
	if (--shotTimer <= 0) {
		//弾を生成し、初期化
		std::unique_ptr<Enemy_B> newBullet = std::make_unique<Enemy_B>();
		newBullet->Initialize(posX, posY);

		Ebullets_.push_back(std::move(newBullet));
		shotTimer = 60.0f;
	}
}

void Enemy::Draw() {
	DrawGraph(posX, posY, enemyGraph, TRUE);
	for (std::unique_ptr<Enemy_B>& bullet : Ebullets_) {
		bullet->Draw();
	}
}
void Enemy::OnCollision() {
	HP--;
}