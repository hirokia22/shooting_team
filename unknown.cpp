#include "unknown.h"
#include"DxLib.h"
void unknown::Initialize() {
	posX = 16;
	posY = -32;
	time = limitTime;
}
void unknown::Update() {
	//�f�X�t���O�̂������e���폜
	meteo_.remove_if([](std::unique_ptr<meteo>& Meteo) {
		return Meteo->IsDead();
		});
	if (--time <= 0) {
		posX = GetRand(568)+16;
		//�e�𐶐����A������
		std::unique_ptr<meteo> newBullet = std::make_unique<meteo>();
		newBullet->Initialize(posX);
		meteo_.push_back(std::move(newBullet));
		time = limitTime;
	}
	//�e�̍X�V����
	for (std::unique_ptr<meteo>& Meteo : meteo_) {
		Meteo->meteoFall();
	}
}
void unknown::Draw() {
	//�e�̕`��
	for (std::unique_ptr<meteo>& Meteo : meteo_) {
		Meteo->Draw();
	}
}
