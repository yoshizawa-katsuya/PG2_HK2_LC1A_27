#pragma once
#include "Struct.h"

class Bullet {
public:

	Bullet();
	void Initial();
	void Update();
	void Draw();

	bool Getisshot_();
	bool* Getaddisshot_();
	Vector2 Getpos_();
	Vector2 Getprepos_();
	int Getradius_();

	void Setisshot_(bool isshot);
	void Setpos_(Vector2 pos);

private:

	Vector2 pos_;
	Vector2 prepos_;
	Vector2 velocity_;
	
	int radius_;
	bool isshot_;

};
