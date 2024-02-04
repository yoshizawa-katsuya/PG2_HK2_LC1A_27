#include <Novice.h>
#include "SceneChange.h"

SceneChange::SceneChange() {
	ScreenH_ = ScreenH;
	ScreenW_ = ScreenW;

	frame_ = 0.0f;
	endframe_ = 30.0f;
	x_ = 0.0f;

	ischange_start_ = 0;
	ischange_end_ = 0;
}

void SceneChange::Initial() {

	frame_ = 0.0f;
	endframe_ = 30.0f;
	x_ = 0.0f;

	ischange_start_ = 0;
	ischange_end_ = 0;
}

void SceneChange::Start1() {

	if (ischange_start_ == 1 && frame_ < endframe_) {
		frame_++;

		x_ = frame_ / endframe_;

		Novice::DrawBox(0, int(ScreenH_ - (ScreenH_ * EaseOut(x_))), ScreenW_, ScreenH_, 0.0f, BLACK, kFillModeSolid);
		
		if (frame_ >= endframe_) {
			ischange_end_ = 1;
			frame_ = endframe_;
		}
	}

}

void SceneChange::End1() {

	if (ischange_start_ == 1 && frame_ < endframe_) {
		frame_++;

		x_ = frame_ / endframe_;

		Novice::DrawBox(0, int(-ScreenH_ * EaseIn(x_)), ScreenW_, ScreenH_, 0.0f, BLACK, kFillModeSolid);

		if (frame_ >= endframe_) {
			ischange_end_ = 1;
			frame_ = endframe_;
		}
	}

}

void SceneChange::Setischange_start_(bool start) { ischange_start_ = start; }

bool SceneChange::Getischange_end_() { return ischange_end_; }