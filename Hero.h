#pragma once
#include"Hero_B.h"
#include<memory>
#include<list>
//主人公の機体
class Hero {
public:
	Hero();
	~Hero();
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