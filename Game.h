#pragma once
#include "Hero.h"
#include"Enemy.h"
#include"unknown.h"

class Game {
public:
	Game();
	~Game();
	void Initialize();
	int Update(char *key);
	void Draw();

private:
	Hero* hero_ = nullptr;
	Enemy* enemy_ = nullptr;
	unknown* unknown_ = nullptr;
	void CheckAllCollision();

	int allTimer = 0;
	const int allTimeMax = 900;
	bool Move = true;
	int back = LoadGraph("Resource/back.png", true);
};
