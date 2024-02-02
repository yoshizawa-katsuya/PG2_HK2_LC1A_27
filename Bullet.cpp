#include <Novice.h>
#include "Bullet.h"

Bullet::Bullet() {
	pos_ = { 0 };
	prepos_ = { 0 };
	velocity_ = { 0,8 };

	radius_ = 10;
	isshot_ = 0;

}

void Bullet::Initial() {
	pos_ = { 0 };
	prepos_ = { 0 };
	velocity_ = { 0 , 8 };

	radius_ = 10;
	isshot_ = 0;
}

void Bullet::Update() {
	if (isshot_ == 1) {
		prepos_ = pos_;
		pos_.x += velocity_.x;
		pos_.y += velocity_.y;

		if (pos_.x + radius_ < 0 || pos_.x - radius_ > 1280 || pos_.y + radius_ < 0 || pos_.y - radius_ > 720) {
			isshot_ = 0;
		}

	}
}

void Bullet::Draw() {
	
	if (isshot_ == 1) {

		Novice::DrawEllipse(int(pos_.x), int((pos_.y - 720) * -1), radius_, radius_, 0.0f, WHITE, kFillModeSolid);

	}
}

bool Bullet::Getisshot_() { return isshot_; }

bool* Bullet::Getaddisshot_() { return &isshot_; }

Vector2 Bullet::Getpos_() { return pos_; }

Vector2 Bullet::Getprepos_() { return prepos_; }

int Bullet::Getradius_() { return radius_; }

void Bullet::Setisshot_(bool isshot) { isshot_ = isshot; }

void Bullet::Setpos_(Vector2 pos) { pos_ = pos; }