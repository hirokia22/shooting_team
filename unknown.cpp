#include "unknown.h"
#include"DxLib.h"
void unknown::Initialize() {
	
}
void unknown::Update() {
	if (--time <= 0) {
		posX = GetRand(584);
		//弾を生成し、初期化
		std::unique_ptr<meteo> newBullet = std::make_unique<meteo>();
		newBullet->Initialize(posX);

		meteo_.push_back(std::move(newBullet));
	}
}
