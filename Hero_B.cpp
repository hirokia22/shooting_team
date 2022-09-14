#include "Hero_B.h"

void Hero_B::Initialize(float& posX,float& posY) {
	posX_= posX;
	posY_ = posY;
	speed = 5.0f;
	isDead_ = false;
}
void Hero_B::Update() {
	posY_ -= speed;
	if (posY_ <= 0) {
		isDead_ = true;
	}
}
void Hero_B::Draw() {

}
void Hero_B::OnCollision() {
	isDead_ = true;
}
