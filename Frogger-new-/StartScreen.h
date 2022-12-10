#ifndef _STARTSCREEN_H
#define _STARTSCREEN_H
#include "AnimatedTexture.h"
#include "InputManager.h"
#include "ScoreBoard.h"
#include "AudioManager.h"


using namespace SDLFramework;

class StartScreen : public GameEntity {
private:
	Timer* m_pTimer;
	InputManager* m_pInputManager;
	AudioManager* m_pAudio;
	// Top Bar Entities
	GameEntity* m_pTopBar;
	Texture* m_pPlayerOne;

	Texture* m_pHiScore;
	ScoreBoard* m_pPlayerOneScore;
	
	ScoreBoard* m_pTopScore;

	// Play Mode Entities
	GameEntity* m_pPlayModes;
	Texture* m_pOnePlayerMode;
	GameEntity* m_pFrogLogo;
	Texture* m_pCursor;
	Vector2 mCursorStartPos;
	Vector2 mCursorOffset;
	int mSelectedMode;

	// Bottom Bar Entities
	GameEntity* m_pBottomBar;
	Texture* m_pKonami;
	Texture* m_pDates;
	Texture* m_pRights;

	// Logo Entities
	Texture* m_pLogo;
	Texture* m_pAnimatedLogo;

	// screen animation variables
	Vector2 mAnimationStartPos;
	Vector2 mAnimationEndPos;
	float mAnimationTotalTime;
	float mAnimationTimer;
	bool mAnimationDone;
	int mAninmationTitleStage = 0;


public:
	StartScreen();
	~StartScreen();
	void FrogTitleAnimStage();
	void ChangeFrogTitleAnimStage();
	void ChangeSelectedMode(int change);
	bool GetStartDone();
	void ResetAnimation();
	int SelectedMode();
	
	void Update() override;
	void Render() override;
};
#endif // !_STARTSCREEN_H

