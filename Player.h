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

public:

	Bullet* bullet_;

	Vector2 pos_;
	Vector2 velocity_;
	int radius_;
	int speed_;

};