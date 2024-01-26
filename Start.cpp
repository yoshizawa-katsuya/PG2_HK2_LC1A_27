#include <Novice.h>
#include "Start.h"

Start::Start() {

}

Start::~Start() {

}

void Start::Initial() {

}

void Start::Update(char* keys, char* prekeys, int* SceneNo) {

	if (keys[DIK_SPACE] && !prekeys[DIK_SPACE]) {
		*SceneNo = GAME;
	}

}

void Start::Draw() {

	Novice::ScreenPrintf(400, 400, "START");
	Novice::ScreenPrintf(400, 420, "press to SPACE");

}