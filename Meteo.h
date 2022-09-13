#pragma once
#include"DxLib.h"
class meteo
{
public:
	void meteoFall();
	void Initialize(int &posX);
private:
	float timer = 20.0f;
	int meteoGraph = LoadGraph("meteo.png", true);
	int posX_ = 0;
	int posY_ = -32;
};

