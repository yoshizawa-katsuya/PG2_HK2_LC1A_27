#include <Novice.h>
#include "Over.h"

Over::Over() {

}

Over::~Over() {

}

void Over::Initial() {

}

void Over::Update(char* keys, char* prekeys, int* SceneNo) {

	if (keys[DIK_SPACE] && !prekeys[DIK_SPACE]) {
		*SceneNo = START;
	}

}

void Over::Draw() {

	Novice::ScreenPrintf(400, 400, "GAME OVER");
	Novice::ScreenPrintf(400, 420, "press to SPACE");

}