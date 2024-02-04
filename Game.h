#pragma once
#include "Player.h"
#include "Enemy.h"
#include "Scene.h"
#include "SceneChange.h"

class Game {
public:

	Game();
	~Game();
	void Initial();
	void Update(char* keys, char* prekeys, int* SceneNo);
	void Draw();

private:

	Player* player;
	Enemy* enemy;

	SceneChange* change;
};