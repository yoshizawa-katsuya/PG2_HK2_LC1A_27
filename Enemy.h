#pragma once
#include "Struct.h"

class Enemy {
public:

	Enemy();
	//~Enemy();
	void Initial();
	void Update();
	void Draw();

	bool Getisalive_();
	Vector2 Getpos_();
	Vector2 Getprepos_();
	int Getradius_();


	void BulletColision(Vector2 bullet_pos, Vector2 bullet_prepos, int bullet_radius, bool *bullet_isshot);

private:

	Vector2 pos_;
	Vector2 prepos_;
	int radius_;
	int hitcount_;
	float hp_;
	float max_hp_;

	bool isalive_;

	Vector2 shake_;

};
