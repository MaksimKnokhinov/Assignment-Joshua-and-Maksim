#include "GameManager.h"

using SDLFramework::GameManager; //this is how small your main.cpp should be

int main(int argc, char* args[]) {
	GameManager* game = GameManager::Instance();

	game->Run();

	GameManager::Release();
	game = nullptr;

	return 0;
}