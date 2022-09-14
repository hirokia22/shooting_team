#pragma once
#include"Enemy_B.h"
#include<memory>
#include<list>
#include"DxLib.h"
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
	const std::list<std::unique_ptr<Enemy_B>>& GetBullet() { return bullets_; }
private:
	float posX, posY, speed_M,speed_A;
	bool death = false;//生存フラグ
	bool move = false;//行動フラグ
	int HP;
	float enemyTimer;
	float shotTimer;
	std::list<std::unique_ptr<Enemy_B>> bullets_;
	int enemyGraph = LoadDivGraph("Resource/boss.png", 4, 4, 1, 64, 64, &enemyGraph);
	int animeTime = 0;
	int index = 0;
};