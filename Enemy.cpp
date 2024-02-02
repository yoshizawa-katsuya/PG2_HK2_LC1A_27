#include <Novice.h>
#include <time.h>
#include "Enemy.h"
#include "Collision.h"

Enemy::Enemy() {



	pos_.x = 640;
	pos_.y = 550;
	prepos_ = pos_;
	velocity_.x = 5;
	velocity_.y = 0;
	radius_ = 20;
	hitcount_ = 0;
	hp_ = 10;
	max_hp_ = hp_;

	isalive_ = 1;

	shake_ = { 0 };

}



void Enemy::Initial() {
	pos_.x = 640;
	pos_.y = 550;
	prepos_ = pos_;
	velocity_.x = 5;
	velocity_.y = 0;
	radius_ = 20;
	hitcount_ = 0;
	hp_ = 10;
	max_hp_ = hp_;

	isalive_ = 1;

	shake_ = { 0 };
}

void Enemy::Update() {

	prepos_ = pos_;

	pos_.x += velocity_.x;

	if (velocity_.x < 0 && pos_.x - radius_ < 0) {
		pos_.x = float(radius_);
		velocity_.x *= -1;
	}
	else if (velocity_.x > 0 && pos_.x + radius_ > 1280) {
		pos_.x = float(1280 - radius_);
		velocity_.x *= -1;
	}

	if (hitcount_ > 0) {
		hitcount_--;

		srand(rand());
		shake_.x = float(rand() % 5 - 2);
		shake_.x *= (hitcount_ / 2);

		srand(rand());
		shake_.y = float(rand() % 5 - 2);
		shake_.y *= (hitcount_ / 2);

	}

	if (hp_ <= 0) {
		isalive_ = 0;
	}

}

void Enemy::BulletColision(Vector2 bullet_pos, Vector2 bullet_prepos, int bullet_radius, bool *bullet_isshot) {

	if (*bullet_isshot == 1) {
		if (CapsuleCollision(bullet_pos, bullet_prepos, pos_, float(radius_), float(bullet_radius))) {

			*bullet_isshot = 0;
			hitcount_ = 15;
			hp_--;

			srand(int(time(nullptr)));

		}
	}
}

void Enemy::Draw()
{
	if (isalive_ == 1) {
		if (hitcount_ > 0) {
			Novice::DrawEllipse(int(pos_.x + shake_.x), int((pos_.y + shake_.y - 720) * -1), radius_, radius_, 0.0f, WHITE, kFillModeSolid);

		}
		else {
			Novice::DrawEllipse(int(pos_.x), int((pos_.y - 720) * -1), radius_, radius_, 0.0f, RED, kFillModeSolid);
		}
	}

	Novice::DrawBox(int(pos_.x - radius_), int((pos_.y + 13 + radius_ - 720) * -1), int(radius_ * 2), 10, 0.0f, BLACK, kFillModeSolid);
	Novice::DrawBox(int(pos_.x - radius_), int((pos_.y + 13 + radius_ - 720) * -1), int(hp_ / max_hp_ * (radius_ * 2)), 10, 0.0f, RED, kFillModeSolid);
	Novice::DrawBox(int(pos_.x - radius_), int((pos_.y + 13 + radius_ - 720) * -1), int(radius_ * 2), 10, 0.0f, WHITE, kFillModeWireFrame);

}

bool Enemy::Getisalive_() { return isalive_; }

Vector2 Enemy::Getpos_() { return pos_; }

Vector2 Enemy::Getprepos_() { return prepos_; }

int Enemy::Getradius_() { return radius_; }