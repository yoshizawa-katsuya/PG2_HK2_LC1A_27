#include <Novice.h>
#include "Start.h"


Start::Start() {
	change = new SceneChange;
}

Start::~Start() {
	delete change;
}

void Start::Initial() {
	change->Initial();
}

void Start::Update(char* keys, char* prekeys, int* SceneNo) {

	if (keys[DIK_SPACE] && !prekeys[DIK_SPACE]) {
		//*SceneNo = GAME;
		change->Setischange_start_(1);
	}
	if (change->Getischange_end_() == 1) {
		*SceneNo = GAME;
	}

}

void Start::Draw() {

	Novice::ScreenPrintf(400, 400, "START");
	Novice::ScreenPrintf(400, 420, "press to SPACE");

	change->Start1();

}