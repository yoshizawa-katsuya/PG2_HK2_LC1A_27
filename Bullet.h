#pragma once
#include "Struct.h"

class Bullet {
public:

	Bullet();
	void Initial();
	void Update();
	void Draw();

private:

	Vector2 pos_;
	Vector2 velocity_;
	
	int radius_;
	bool isshot_;

};
