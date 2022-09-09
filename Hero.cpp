#include "Hero.h"
#include"DxLib.h"
void Hero::Initialize() {
	posX = 320.0f;
	posY = 160.0f;
	speed = 2.0f;
	death = false;
	move = true;
	HP = 100;
	heroTimer = 1800.0f;
}
void Hero::Update(int* key) {
	heroTimer--;
	if (heroTimer <= 0) {
		if (move == true) {
			move = false;
		}
		else if (move == false) {
			move = true;
		}
		heroTimer = 1800.0f;
	}
	if (move == true) {
		Manual(key);
	}
	else if (move == false) {
		Auto();
	}
}
void Hero::Manual(int* key) {
	if (key[KEY_INPUT_A]) {
		posX -= speed;
	}
	else if (key[KEY_INPUT_D]) {
		posX += speed;
	}
	if (key[KEY_INPUT_W]) {
		posY -= speed;
	}
	else if (key[KEY_INPUT_S]) {
		posY += speed;
	}
}
void Hero::Auto() {
	//ˆÚ“®
	posX++;
	

}

void Hero::Shot(int *key) {
	if (key[KEY_INPUT_SPACE]) {
		//’e‚ð¶¬‚µA‰Šú‰»
		std::unique_ptr<Hero_B> newBullet = std::make_unique<Hero_B>();
		newBullet->Initialize();
		
		bullets_.push_back(std::move(newBullet));
	}
}
void Hero::AutoShot() {

}

void Hero::Draw() {

}