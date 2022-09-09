#pragma once
//エネミーの機体
class Enemy {
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新
	/// </summary>
	void Update(int *key);

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();
	
	/// <summary>
	/// 自動
	/// </summary>
	void Auto();

	/// <summary>
	/// 手動
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