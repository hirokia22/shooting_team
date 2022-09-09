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
	void Update(int* key);

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
	void Manual(int* key);

	void Shot(int *key);
	void AutoShot();

	void OnCollision();
	
	//弾リストを取得
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