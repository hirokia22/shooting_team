#include "Hero.h"
#include"DxLib.h"
void Hero::Initialize() {
	posX = 320.0f;
	posY = 640.0f;
	speed_M = 2.0f;
	speed_A = 2.0f;
	HP = 100;
	heroTimer = 1800.0f;
	shotTimer = 60.0f;
	animeTime = 0;
	index = 0;
}
void Hero::Update(char* key,bool &moveFlag) {
	//デスフラグのたった弾を削除
	bullets_.remove_if([](std::unique_ptr<Hero_B>& bullet) {
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
	for (std::unique_ptr<Hero_B>& bullet : bullets_) {
		bullet->Update();
	}
}
void Hero::Manual(char* key) {
	if (key[KEY_INPUT_A]) {
		posX -= speed_M;
	}
	else if (key[KEY_INPUT_D]) {
		posX += speed_M;
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
	if (key[KEY_INPUT_SPACE]) {
		//弾を生成し、初期化
		std::unique_ptr<Hero_B> newBullet = std::make_unique<Hero_B>();
		newBullet->Initialize(posX,posY);
		
		bullets_.push_back(std::move(newBullet));
	}
}
void Hero::AutoShot() {
	if (--shotTimer <= 0) {
		//弾を生成し、初期化
		std::unique_ptr<Hero_B> newBullet = std::make_unique<Hero_B>();
		newBullet->Initialize(posX, posY);

		bullets_.push_back(std::move(newBullet));
		shotTimer = 60.0f;
	}
}

void Hero::Draw() {
	animeTime++;
	if (animeTime >= 6)
	{
		index = (index + 1) % 4;

		animeTime = 0;

	}
	DrawGraph(posX, posY, heroGraph[&index], TRUE);


}