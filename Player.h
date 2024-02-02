#pragma once
#pragma once
#include "Bullet.h"
#include "Struct.h"

class Player {
public:

	Player();
	~Player();
	void Initial();
	void Update(char* keys, char* prekeys);
	void Draw();

	void EnemyColision(Vector2 enemy_pos, Vector2 enemy_prepos, int enemy_radius, bool enemy_isalive);

	bool Getisalive_();

	Bullet* Getbullet_();

private:

	Bullet* bullet_;

	Vector2 pos_;
	Vector2 velocity_;
	int radius_;
	int speed_;

	bool isalive_;

};