#pragma once
#include"DxLib.h"
class Hero_B {
public:
	void Initialize(float& posX, float& posY);
	void Update();
	void Draw();
	void OnCollision();
	static const int kRadius = 16;
	bool IsDead()const { return isDead_; }
public:
	float posX_, posY_, speed = 0;
	int deathTime = 60;//�N�[���^�C��
	bool isDead_ = false;//�t���O
	int playerBulletGraph = LoadGraph("Resource/playerballet.png", true);
};