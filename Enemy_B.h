#pragma once
class Enemy_B {
public:
	void Initialize(float& posX, float& posY);
	void Update();
	void Draw();
	void OnCollision();
	static const int kRadius = 16;
	bool IsDead()const { return isDead_; }
private:
	float posX_, posY_, speed;
	int deathTime;//クールタイム
	bool isDead_ = false;//フラグ
};