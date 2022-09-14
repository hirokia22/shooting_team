#pragma once
#include"DxLib.h"
class meteo
{
public:
	void meteoFall();
	void Initialize(int &posX);
	bool IsDead()const { return isDead_ ; }
	void Draw();
	static const int kRadius = 16;
	void OnCollision();
public:
	float timer = 20.0f;
	int meteoGraph = LoadGraph("Resource/meteo.png", true);
	int posX_ = 0;
	int posY_ = -32;
	bool isDead_ = false;

};

