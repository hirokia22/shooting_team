#pragma once
#include"Hero_B.h"
#include<memory>
#include<list>
#include"DxLib.h"
//主人公の機体
class Hero {
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新
	/// </summary>
	void Update(char* key,bool &moveFlag);

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

	void Shot(char *key);	//了
	void AutoShot();		//了

	void OnCollision();
	
	//弾リストを取得
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