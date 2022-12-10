#ifndef _PLAYSCREEN_H

#define _PLAYSCREEN_H
#include "Player.h"
#include "GameEntity.h"
#include "Graphics.h"
#include "Texture.h"
#include"Timer.h"
#include<string>
#include"InputManager.h"
#include"ScoreBoard.h"
#include "AudioManager.h"
#include <sstream>
using namespace SDLFramework;
class PlayScreen :public GameEntity
{private:
	Mix_Chunk* FroghopSfx;
	float mAnimationTotalTime;
	float mAnimationTimer;
	SDL_Renderer* m_pRenderer;
	AudioManager* m_pAudioMan;
	Timer* m_pTimer;
	InputManager* m_pInputManager;
	Graphics* m_pGrahpics;
	// Top Bar Entities
	GameEntity* m_pTopBar;
	GameEntity* m_pBackGround;
	Texture* m_pBackGroundTexture;
	
	std::stringstream ssScore;
	std::stringstream ssHiscore;
	Texture* m_pPlayerOne;

	Player* m_pPlayer;


	Texture* m_pHiScore;
	Texture* m_pHiScoreDisp;
	Texture* m_pPlayerOneScore;
	Texture* m_pPlayerOneScoreDisp;
	
	ScoreBoard* m_pTopScore;
	

	int PlayScore;
	int HiScore;
	std::string st_PScore;
	std::string st_HiScore;


	// Logo Entities
	Texture* m_pLogo;
	Texture* m_pAnimatedLogo;



public:
	PlayScreen();
	~PlayScreen();
	void GenAndDisplayBackrgound();
	void ChangeFrogTitleAnimStage();
	void ChangeSelectedMode(int change);

	void ResetAnimation();
	int SelectedMode();

	void Update() override;
	void Render() override;


};

#endif // !_STARTSCREEN_H

//Writen By Joshua Michalik