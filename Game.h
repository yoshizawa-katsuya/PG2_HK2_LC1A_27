#pragma once

class Game {
public:

	Game();
	~Game();
	void Initial();
	void Update(char* keys, char* prekeys, int* SceneNo);
	void Draw();

private:


};