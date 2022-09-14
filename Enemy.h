#pragma once
#include"Enemy_B.h"
#include<memory>
#include<list>
#include"DxLib.h"
//�G�l�~�[�̋@��
class Enemy {
public:
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
	const std::list<std::unique_ptr<Enemy_B>>& GetBullet() { return bullets_; }
private:
	float posX, posY, speed_M,speed_A;
	bool death = false;//�����t���O
	bool move = false;//�s���t���O
	int HP;
	float enemyTimer;
	float shotTimer;
	std::list<std::unique_ptr<Enemy_B>> bullets_;
	int enemyGraph = LoadDivGraph("Resource/boss.png", 4, 4, 1, 64, 64, &enemyGraph);
	int animeTime = 0;
	int index = 0;
};