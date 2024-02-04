#include "Game.h"

Game::Game() {

	player = new Player;
	enemy = new Enemy;

	change = new SceneChange;
	change->Setischange_start_(1);
}

Game::~Game() {

	delete player;
	delete enemy;

	delete change;
}

void Game::Initial() {

	player->Initial();
	enemy->Initial();

	change->Initial();
}

void Game::Update(char* keys, char* prekeys, int* SceneNo) {

	player->Update(keys, prekeys);
	enemy->Update();

	enemy->BulletColision(player->Getbullet_()->Getpos_(), player->Getbullet_()->Getprepos_(), player->Getbullet_()->Getradius_(), player->Getbullet_()->Getaddisshot_());
	player->EnemyColision(enemy->Getpos_(), enemy->Getprepos_(), enemy->Getradius_(), enemy->Getisalive_());


	if (enemy->Getisalive_() == 0) {
		*SceneNo = CLEAR;
	}
	if (player->Getisalive_() == 0) {
		*SceneNo = OVER;
	}
	

}

void Game::Draw() {

	player->Draw();
	enemy->Draw();

	change->End1();
}