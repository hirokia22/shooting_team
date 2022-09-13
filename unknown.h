#pragma once
#include "Meteo.h"
#include<memory>
#include<list>
class unknown {
public:
	void Initialize();
	void Update();
	//’eƒŠƒXƒg‚ğæ“¾
	const std::list<std::unique_ptr<meteo>>& GetBullet() { return meteo_; }
private:
	int posX = 0;
	int posY = -32;
	int time = 60;
	std::list<std::unique_ptr<meteo>> meteo_;
 };