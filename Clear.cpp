#include <Novice.h>
#include "Clear.h"

Clear::Clear() {

}

Clear::~Clear() {

}

void Clear::Initial() {

}

void Clear::Update(char* keys, char* prekeys, int* SceneNo) {

	if (keys[DIK_SPACE] && !prekeys[DIK_SPACE]) {
		*SceneNo = START;
	}

}

void Clear::Draw() {

	Novice::ScreenPrintf(400, 400, "GAME CLEAR");
	Novice::ScreenPrintf(400, 420, "press to SPACE");

}