#pragma once
#include "Meteo.h"
#include<memory>
#include<list>
class unknown {
public:
	void Initialize();
	void Update();
	//’eƒŠƒXƒg‚ðŽæ“¾
	const std::list<std::unique_ptr<meteo>>& GetBullet() { return meteo_; }
	void Draw();
private:
	int posX = 0;
	int posY = -32;
	int time = 60;
	const int  limitTime = 60;
	std::list<std::unique_ptr<meteo>> meteo_;
 };