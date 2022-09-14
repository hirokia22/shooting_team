#pragma once
#include"DxLib.h"
class meteo
{
public:
	void meteoFall();
	void Initialize(int &posX);
	bool IsDead()const { return isDead_ ; }
	void Draw();
private:
	float timer = 20.0f;
	int meteoGraph = LoadGraph("Resource/meteo.png", true);
	int posX_ = 0;
	int posY_ = -32;
	bool isDead_ = false;
};

