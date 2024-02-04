#pragma once
#include "Easing.h"
#include "ScreenSize.h"

class SceneChange {
public:

	SceneChange();

	void Initial();

	void Start1();
	void End1();

	void Setischange_start_(bool start);

	bool Getischange_start_();
	bool Getischange_end_();

private:

	int ScreenH_;
	int ScreenW_;
	float frame_;
	float endframe_;
	
	float x_;
	
	bool ischange_start_;
	bool ischange_end_;

};
