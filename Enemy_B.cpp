#include "Enemy_B.h"

void Enemy_B::Initialize(float& posX, float& posY) {
	posX_ = posX;
	posY_ = posY;
	speed = 5.0f;
	isDead_ = false;
}
void Enemy_B::Update() {
	posY_ += speed;
	if (posY_ >= 800) {
		isDead_ = true;
	}
}
void Enemy_B::Draw() {
	DrawGraph(posX_, posY_, bulletGraph, true);
}
void Enemy_B::OnCollision() {
	isDead_ = true;
}
