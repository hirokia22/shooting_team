#include"Game.h"

Game::Game() {}

Game::~Game() {
	delete hero_;
	delete enemy_;
	delete unknown_;
}

void Game::Initialize() {
	allTimer = allTimeMax;
	Move = true;
	hero_ = new Hero();
	hero_->Initialize();
	enemy_ = new Enemy();
	enemy_->Initialize();
	unknown_ = new unknown();
	unknown_->Initialize();
}

int Game::Update(char* key) {
	if (--allTimer <= 0) {
		if (Move == true) {
			Move = false;
		}
		else if (Move == false) {
			Move = true;
		}
		allTimer = allTimeMax;
	}
	hero_->Update(key,Move);
	enemy_->Update(key, Move);
	unknown_->Update();
	CheckAllCollision();
	if (hero_->heromode == 0) {
		return 1; //over
	}
	else if (enemy_->enemymode == 0) {
		return 2; //clear
	}
}
void Game::Draw() {
	DrawGraph(0, 0, back, true);
	unknown_->Draw();
	enemy_->Draw();
	hero_->Draw();
}
void Game::CheckAllCollision() {
	const std::list<std::unique_ptr<Hero_B>>& playerBullets =
		hero_->GetBullet();
	const std::list<std::unique_ptr<Enemy_B>>& enemyBullets =
		enemy_->GetBullet();
	const std::list<std::unique_ptr<meteo>>& meteos =
		unknown_->GetBullet();
#pragma region ���L�����ƓG�e�̓����蔻��

	for (const std::unique_ptr<Enemy_B>& bullet : enemyBullets) {
		float dx = hero_->posX - bullet->posX_;
		float dy = hero_->posY - bullet->posY_;

		float d = dx * dx + dy * dy;

		float r = (hero_->radius + bullet->kRadius) * (hero_->radius + bullet->kRadius);

		if (d <= r) {
			//���L�����̏Փˎ��R�[���o�b�N���Ăяo��
			hero_->OnCollision();
			//�G�e�̏Փˎ��R�[���o�b�N�֐����Ăяo��
			bullet->OnCollision();
		}
	}
#pragma endregion

#pragma region ���e�ƓG�L�����̓����蔻��

	for (const std::unique_ptr<Hero_B>& bullet : playerBullets) {
		float dx = enemy_->posX - bullet->posX_;
		float dy = enemy_->posY - bullet->posY_;

		float d = dx * dx + dy * dy;

		float r = (enemy_->radius + bullet->kRadius) * (enemy_->radius + bullet->kRadius);

		if (d <= r) {
			//�G�L�����̏Փˎ��R�[���o�b�N���Ăяo��
			enemy_->OnCollision();
			//���e�̏Փˎ��R�[���o�b�N�֐����Ăяo��
			bullet->OnCollision();
		}
	}
#pragma endregion

#pragma region ���L������覐΂̓����蔻��

	for (const std::unique_ptr<meteo>& bullet : meteos) {
		float dx = hero_->posX - bullet->posX_;
		float dy = hero_->posY - bullet->posY_;

		float d = dx * dx + dy * dy;

		float r = (hero_->radius + bullet->kRadius) * (hero_->radius + bullet->kRadius);

		if (d <= r) {
			//���L�����̏Փˎ��R�[���o�b�N���Ăяo��
			hero_->OnCollision();
			//�G�e�̏Փˎ��R�[���o�b�N�֐����Ăяo��
			bullet->OnCollision();
		}
	}
#pragma endregion
#pragma region ���e��覐΂̓����蔻��
	//���e�S�ĂƓG�e�S�Ă̓����蔻��
	for (const std::unique_ptr<Hero_B>& bullet : playerBullets) {
		//���e�S�ĂƓG�e�S�Ă̓����蔻��
		for (const std::unique_ptr<meteo>& meteo_ : meteos) {
			float dx = meteo_->posX_ - bullet->posX_;
			float dy = meteo_->posY_ - bullet->posY_;


			float d = dx * dx + dy * dy;

			float r = (meteo_->kRadius + bullet->kRadius) * (meteo_->kRadius + bullet->kRadius);

			//���Ƌ��̌�������
			if (d <= r) {
				//���e�̏Փˎ��R�[���o�b�N���Ăяo��
				bullet->OnCollision();
			}
		}
	}
#pragma endregion

#pragma region �G�e��覐΂̓����蔻��
	for (const std::unique_ptr<Enemy_B>& bullet : enemyBullets) {
		for (const std::unique_ptr<meteo>& meteo_ : meteos) {
			float dx = meteo_->posX_ - bullet->posX_;
			float dy = meteo_->posY_ - bullet->posY_;


			float d = dx * dx + dy * dy;

			float r = (meteo_->kRadius + bullet->kRadius) * (meteo_->kRadius + bullet->kRadius);

			//���Ƌ��̌�������
			if (d <= r) {
				//�G�e�̏Փˎ��R�[���o�b�N���Ăяo��
				bullet->OnCollision();
				//覐΂̏Փˎ��R�[���o�b�N���Ăяo��
				meteo_->OnCollision();
			}
		}
	}
#pragma endregion
}