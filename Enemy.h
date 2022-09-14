#pragma once
#include"Enemy_B.h"
#include<memory>
#include<list>
#include"DxLib.h"
//エネミーの機体
class Enemy {
public:
	Enemy();
	~Enemy();
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新
	/// </summary>
	void Update(char* key, bool& moveFlag);

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
	void Manual(char* key);

	void Shot(char* key);	//了
	void AutoShot();		//了

	void OnCollision();

	//弾リストを取得
	const std::list<std::unique_ptr<Enemy_B>>& GetBullet() { return Ebullets_; }
public:
	float posX = 0;
	float posY = 0;
	float speed_M = 0;
	float speed_A = 0;
	bool death = false;//生存フラグ
	bool move = false;//行動フラグ
	int HP = 100;
	float shotTimer = 60.0f;
	float shotTimerM = 30.0f;
	std::list<std::unique_ptr<Enemy_B>> Ebullets_;
	int enemyGraph = LoadGraph("Resource/boss.png", true);
	float radius = 32;
	int enemymode = 1;
};