#pragma once
#include"Hero_B.h"
#include<memory>
#include<list>
#include"DxLib.h"
//��l���̋@��
class Hero {
public:
	/// <summary>
	/// ������
	/// </summary>
	void Initialize();

	/// <summary>
	/// �X�V
	/// </summary>
	void Update(char* key,bool &moveFlag);

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

	void Shot(char *key);	//��
	void AutoShot();		//��

	void OnCollision();
	
	//�e���X�g���擾
	const std::list<std::unique_ptr<Hero_B>>& GetBullet() { return bullets_; }
private:
	float posX, posY, speed_M,speed_A;
	int HP;
	float heroTimer;
	float shotTimer;
	std::list<std::unique_ptr<Hero_B>> bullets_;
	int heroGraph = LoadDivGraph("Resource/player_anime32.png", 4, 4, 1, 32, 32, &heroGraph);
	int animeTime = 0;
	int index = 0;
};