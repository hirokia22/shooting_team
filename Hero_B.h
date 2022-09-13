#pragma once
class Hero_B {
public:
	void Initialize(float& posX,float& posY);
	void Update();
	void Draw();
	void OnCollision();
	static const int kRadius = 16;
private:
	float posX_,posY_,speed;
	int deathTime;//クールタイム
	bool death = false;//フラグ
};