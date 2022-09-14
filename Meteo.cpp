#include "meteo.h"
void meteo::Initialize(int& posX) {
	posX_ = posX;
	posY_ = -32;
	isDead_ = false;
}
void meteo::meteoFall() {
	posY_ += 3;
	if (posY_ >= 800) {
		isDead_ = true;
	}
	//DrawFormatString(0,0,GetColor(255,255,255),"timer = %f",timer);
}
void meteo::Draw() {
	DrawGraph(posX_, posY_, meteoGraph, true);
}
