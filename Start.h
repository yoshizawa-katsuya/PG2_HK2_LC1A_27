#pragma once
#include "Scene.h"
#include "SceneChange.h"

class Start {
public:

	Start();
	~Start();
	void Initial();
	void Update(char* keys, char* prekeys, int *SceneNo);
	void Draw();

private:

	SceneChange* change;

};