#pragma once
#include"Hero_B.h"
#include<memory>
#include<list>
//��l���̋@��
class Hero {
public:
	Hero();
	~Hero();
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
	const std::list<std::unique_ptr<Hero_B>>& GetBullet() { return Hbullets_; }
public:
	float posX = 0;
	float posY = 0;
	float speed_M = 0;
	float speed_A = 0;
	int HP= 3;
	float heroTimer=0;
	float shotTimer=0;
	float shotTimerM = 30.0f;
	std::list<std::unique_ptr<Hero_B>> Hbullets_;
	int heroGraph = LoadGraph("Resource/player.png",true);
	int animeTime = 0;
	int index = 0;
	float radius = 16.0f;
	int heromode = 1;
};