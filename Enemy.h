#pragma once
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
	void Update(int *key);

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
	void Manual(int*key);
private:
	float posX, posY, speed;
	bool death = false;
	bool move = false;
	int HP;
	float max, min;
	float enemyTimer;
};