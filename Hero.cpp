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
	shotTimer = 60.0f;
}
void Hero::Update(char* key) {
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
		Shot(key);
	}
	else if (move == false) {
		Auto();
	}
}
void Hero::Manual(char* key) {
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
	//à⁄ìÆ
	posX+=speed;
	if ((posX <= 0) || (posX >= 600) ){
		speed = -speed;
	}
	AutoShot();
}

void Hero::Shot(char *key) {
	if (key[KEY_INPUT_SPACE]) {
		//íeÇê∂ê¨ÇµÅAèâä˙âª
		std::unique_ptr<Hero_B> newBullet = std::make_unique<Hero_B>();
		newBullet->Initialize(posX,posY);
		
		bullets_.push_back(std::move(newBullet));
	}
}
void Hero::AutoShot() {
	if (--shotTimer <= 0) {
		//íeÇê∂ê¨ÇµÅAèâä˙âª
		std::unique_ptr<Hero_B> newBullet = std::make_unique<Hero_B>();
		newBullet->Initialize(posX, posY);

		bullets_.push_back(std::move(newBullet));
		shotTimer = 60.0f;
	}
}

void Hero::Draw() {

}