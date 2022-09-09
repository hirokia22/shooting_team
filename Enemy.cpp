#include "Enemy.h"
#include"DxLib.h"
void Enemy::Initialize() {
	posX = 320.0f;
	posY = 160.0f;
	speed = 1.0f;
	death = false;
	move = false;
	HP = 100;
	max = 440.0f;
	min = 200.0f;
	enemyTimer = 1800.0f;
}
void Enemy::Update(int *key) {
	enemyTimer--;
	if (enemyTimer <= 0) {
		if (move == true) {
			move = false;
		}
		else if (move == false) {
			move = true;
		}
		enemyTimer = 1800.0f;
	}
	if (move == true) {
		Manual(key);
	}
	else if (move == false) {
		Auto();
	}
}
void Enemy::Manual(int*key) {
	if (key[KEY_INPUT_A]) {
		posX-=speed;
	}
	else if (key[KEY_INPUT_D]) {
		posX += speed;
	}
}
void Enemy::Auto() {
	//ˆÚ“®
	posX++;
	if ((posX < min)||(posX>max)) {
		posX = -posX;
	}

}
void Enemy::Draw() {

}