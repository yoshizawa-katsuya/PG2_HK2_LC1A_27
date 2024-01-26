#include <Novice.h>
#include "Bullet.h"

Bullet::Bullet() {
	pos_ = { 0 };
	velocity_ = { 0,8 };

	radius_ = 10;
	isshot_ = 0;

}

void Bullet::Initial() {
	pos_ = { 0 };
	velocity_ = { 0 , 8 };

	radius_ = 10;
	isshot_ = 0;
}

void Bullet::Update() {
	if (isshot_ == 1) {
		pos_.x += velocity_.x;
		pos_.y += velocity_.y;
	}
}

void Bullet::Draw() {
	
	Novice::DrawEllipse(int(pos_.x), int((pos_.y - 720) * -1), radius_, radius_, 0.0f, WHITE, kFillModeSolid);

}