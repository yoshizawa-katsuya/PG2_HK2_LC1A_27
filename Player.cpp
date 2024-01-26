#include <Novice.h>
#include "Player.h"

Player::Player() {

	bullet_ = new Bullet();

	pos_.x = 640;
	pos_.y = 200;
	velocity_ = { 0 };
	radius_ = 20;
	speed_ = 6;

}

Player::~Player() {
	delete bullet_;
}

void Player::Initial() {

	bullet_->Initial();

	pos_.x = 640;
	pos_.y = 200;
	velocity_ = { 0 };
	radius_ = 20;
	speed_ = 6;
}

void Player::Update(char* keys, char* prekeys) {

	if (keys[DIK_W] || keys[DIK_UP]) {
		velocity_.y += speed_;
	}
	if (keys[DIK_S] || keys[DIK_DOWN]) {
		velocity_.y -= speed_;
	}
	if (keys[DIK_A] || keys[DIK_LEFT]) {
		velocity_.x -= speed_;
	}
	if (keys[DIK_D] || keys[DIK_RIGHT]) {
		velocity_.x += speed_;
	}

	if (bullet_->isshot_ == 0) {
		if (keys[DIK_SPACE] && !prekeys[DIK_SPACE]) {
			bullet_->isshot_ = 1;
			bullet_->pos_.x = pos_.x;
			bullet_->pos_.y = pos_.y;
			for (int i = 0; i < 5; i++) {
				bullet_->prepos_[i] = bullet_->pos_;
			}
		}
	}

	bullet_->Update();

}

void Player::Draw() {
	bullet_->Draw();
	Novice::DrawEllipse(int(pos_.x), int((pos_.y - 720) * -1), radius_, radius_, 0.0f, BLUE, kFillModeSolid);
}