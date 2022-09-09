#pragma once
class EnemyBullet {
private:
	void Initialize();
	void Shot_M();
	void Shot_A();
	void Draw();
public:
	float posX, posY, speed;
	bool death = false;
};