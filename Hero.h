#pragma once
#include"Hero_B.h"
#include<memory>
#include<list>

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
	void Update(char* key);

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
	float posX, posY, speed;
	bool death = false;//生存フラグ
	bool move = false;//行動フラグ
	int HP;
	float heroTimer;
	float shotTimer;
	std::list<std::unique_ptr<Hero_B>> bullets_;
};