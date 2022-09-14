#pragma once
#include"Enemy_B.h"
#include<memory>
#include<list>
#include"DxLib.h"
//�G�l�~�[�̋@��
class Enemy {
public:
	Enemy();
	~Enemy();
	/// <summary>
	/// ������
	/// </summary>
	void Initialize();

	/// <summary>
	/// �X�V
	/// </summary>
	void Update(char* key, bool& moveFlag);

	/// <summary>
	/// �`��
	/// </summary>
	void Draw();

	/// <summary>
	/// ����
	/// </summary>
	void Auto();

	/// <summary>
	/// �蓮
	/// </summary>
	void Manual(char* key);

	void Shot(char* key);	//��
	void AutoShot();		//��

	void OnCollision();

	//�e���X�g���擾
	const std::list<std::unique_ptr<Enemy_B>>& GetBullet() { return Ebullets_; }
public:
	float posX = 0;
	float posY = 0;
	float speed_M = 0;
	float speed_A = 0;
	bool death = false;//�����t���O
	bool move = false;//�s���t���O
	int HP = 100;
	float shotTimer = 60.0f;
	float shotTimerM = 30.0f;
	std::list<std::unique_ptr<Enemy_B>> Ebullets_;
	int enemyGraph = LoadGraph("Resource/boss.png", true);
	float radius = 32;
	int enemymode = 1;
};