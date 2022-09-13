#pragma once
#include"Hero_B.h"
#include<memory>
#include<list>

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
	void Update(char* key);

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
	float posX, posY, speed;
	bool death = false;//�����t���O
	bool move = false;//�s���t���O
	int HP;
	float heroTimer;
	float shotTimer;
	std::list<std::unique_ptr<Hero_B>> bullets_;
};