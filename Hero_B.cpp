#include "Hero_B.h"

void Hero_B::Initialize(float& posX,float& posY) {
	posX_= posX;
	posY_ = posY;
	speed = 5.0f;
	deathTime = 200;
	death = false;
}
void Hero_B::Update() {
	posY_ -= speed;
	if (--deathTime <= 0) {
		death = true;
	}
}
void Hero_B::Draw() {

}
void Hero_B::OnCollision() {
	death = true;
}
