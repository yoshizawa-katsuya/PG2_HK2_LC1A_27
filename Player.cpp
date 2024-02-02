#include <Novice.h>
#include "Player.h"
#include "Collision.h"

Player::Player() {

	bullet_ = new Bullet();

	pos_.x = 640;
	pos_.y = 200;
	velocity_ = { 0 };
	radius_ = 20;
	speed_ = 6;

	isalive_ = 1;

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

	isalive_ = 1;

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

	pos_.x += velocity_.x;
	pos_.y += velocity_.y;

	velocity_ = { 0 };

	if (bullet_->Getisshot_() == 0) {
		if (keys[DIK_SPACE] && !prekeys[DIK_SPACE]) {
			bullet_->Setisshot_(1);
			bullet_->Setpos_(pos_);
			
			
		}
	}

	bullet_->Update();

}

void Player::EnemyColision(Vector2 enemy_pos, Vector2 enemy_prepos, int enemy_radius, bool enemy_isalive) {

	if (enemy_isalive == 1) {
		if (CapsuleCollision(enemy_pos, enemy_prepos, pos_, float(radius_), float(enemy_radius))) {

			isalive_ = 0;

		}


	}

}

void Player::Draw() {
	bullet_->Draw();
	Novice::DrawEllipse(int(pos_.x), int((pos_.y - 720) * -1), radius_, radius_, 0.0f, BLUE, kFillModeSolid);
}

bool Player::Getisalive_() { return isalive_; }

Bullet* Player::Getbullet_() { return bullet_; }