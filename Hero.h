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
	void Update(int* key);

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
	void Manual(int* key);

	void Shot(int *key);
	void AutoShot();

	void OnCollision();
	
	//�e���X�g���擾
	const std::list<std::unique_ptr<Hero_B>>& GetBullet() { return bullets_; }
private:
	float posX, posY, speed;
	bool death = false;
	bool move = false;
	int HP;
	float lim;
	float heroTimer;

	std::list<std::unique_ptr<Hero_B>> bullets_;
};