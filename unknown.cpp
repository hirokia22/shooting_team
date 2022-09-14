#include "unknown.h"
#include"DxLib.h"
void unknown::Initialize() {
	posX = 16;
	posY = -32;
	time = limitTime;
}
void unknown::Update() {
	//デスフラグのたった弾を削除
	meteo_.remove_if([](std::unique_ptr<meteo>& Meteo) {
		return Meteo->IsDead();
		});
	if (--time <= 0) {
		posX = GetRand(568)+16;
		//弾を生成し、初期化
		std::unique_ptr<meteo> newBullet = std::make_unique<meteo>();
		newBullet->Initialize(posX);
		meteo_.push_back(std::move(newBullet));
		time = limitTime;
	}
	//弾の更新処理
	for (std::unique_ptr<meteo>& Meteo : meteo_) {
		Meteo->meteoFall();
	}
}
void unknown::Draw() {
	//弾の描画
	for (std::unique_ptr<meteo>& Meteo : meteo_) {
		Meteo->Draw();
	}
}
