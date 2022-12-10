#include "PlayScreen.h"

PlayScreen::PlayScreen()
{
	m_pPlayer = Player::Instance();
	m_pPlayer->Parent(this);
	m_pPlayer->Position(Graphics::SCREEN_WIDTH * .5f, Graphics::SCREEN_HEIGHT * .5f);

	PlayScore = 4242564;
	ssScore << PlayScore;
	HiScore = PlayScore * 2;
	ssHiscore << HiScore;
	m_pTimer = Timer::Instance();
	mAnimationTimer = 0.0f;
	mAnimationTotalTime = 3.0f;
	m_pAudioMan = AudioManager::Instance();

	m_pTopBar = new GameEntity(Graphics::SCREEN_WIDTH, Graphics::SCREEN_HEIGHT);
	m_pTopBar->Parent(this);
	m_pTopBar->Position(Graphics::SCREEN_WIDTH * .5f, 0.35f);

	st_HiScore = ssHiscore.str();
	m_pHiScore  = new Texture("Hi-Score", "emulogic.ttf", 22, { 230, 230, 230 });
	m_pHiScoreDisp  = new Texture(st_HiScore, "emulogic.ttf", 12, { 230, 230, 230 });
	m_pHiScoreDisp->Position(350.0f, 45.0f);
	m_pHiScoreDisp->Parent(m_pTopBar);	m_pHiScore->Position(350.0f, 25.0f);
	m_pHiScore->Parent(m_pTopBar);

	m_pPlayerOne=new Texture("frogup1.gif", 0, 0, 24, 27);
	m_pPlayerOne->Position(Graphics::SCREEN_WIDTH*.9f,Graphics::SCREEN_HEIGHT*0.99f);

	st_PScore = ssScore.str();
	m_pPlayerOneScore = new Texture("1-up", "emulogic.ttf", 22, { 255, 191, 0 });
	m_pPlayerOneScoreDisp = new Texture(st_PScore, "emulogic.ttf", 12, { 255, 191, 0 });
	m_pPlayerOneScoreDisp->Parent(m_pTopBar);
	m_pPlayerOneScoreDisp->Position(Graphics::SCREEN_WIDTH * -.27f, 45.0f );	
	m_pPlayerOneScore->Parent(m_pTopBar);
	m_pPlayerOneScore->Position(Graphics::SCREEN_WIDTH * -.27f, 25.0f );
	//m_pHiScore->Position(Graphics::SCREEN_WIDTH * .5f, 1);


	//
	m_pBackGround = new GameEntity(0, Graphics::SCREEN_HEIGHT);
	m_pBackGround->Parent(this);
	m_pBackGroundTexture = new Texture("frogger_Background.png", 0, 0, 581, 569);
	m_pBackGroundTexture->Parent(this);
	m_pBackGround->Position(Graphics::SCREEN_WIDTH * .5f, Graphics::SCREEN_HEIGHT * .5f);
	m_pBackGroundTexture->Position(Graphics::SCREEN_WIDTH*.5f, Graphics::SCREEN_HEIGHT*.5f);

	m_pAudioMan->PlayMusic("Frogger_Stage.wav", 2);
		m_pInputManager = InputManager::Instance();
	//FroghopSfx = Mix_LoadWAV();

}

PlayScreen::~PlayScreen()
{
	delete m_pBackGround;
	m_pBackGround = nullptr;
	delete m_pBackGroundTexture;
	m_pBackGroundTexture = nullptr;


}

void PlayScreen::GenAndDisplayBackrgound()
{
}

void PlayScreen::ChangeFrogTitleAnimStage()
{
}

void PlayScreen::ChangeSelectedMode(int change)
{
}

void PlayScreen::ResetAnimation()
{
}

int PlayScreen::SelectedMode()
{
	return 0;
}

void PlayScreen::Update()
{

	Vector2 oldPos;
	Vector2 newPos;

	
	if (m_pInputManager->KeyDown(SDL_SCANCODE_LEFT)) {
	
		m_pPlayer->Direction("Left");

		m_pPlayer->Move();
	}
	if (m_pInputManager->KeyDown(SDL_SCANCODE_RIGHT)) {
		m_pPlayer->Direction("Right");

		m_pPlayer->Move();
	}

	if (m_pInputManager->KeyDown(SDL_SCANCODE_UP)) {
		
		m_pPlayer->Direction("Up");
	
		m_pPlayer->Move();
	}
	if (m_pInputManager->KeyDown(SDL_SCANCODE_DOWN)) {
		
		m_pPlayer->Direction("Down");

		m_pPlayer->Move();
	}
	m_pPlayer->Update();
}

void PlayScreen::Render()
{


	m_pBackGroundTexture -> Render();
	m_pPlayer->Render();
	m_pTopBar->Render();
	m_pHiScore -> Render();
	m_pHiScoreDisp->Render();
	m_pPlayerOneScore->Render();
	m_pPlayerOneScoreDisp->Render();

}

//Writen By Joshua Michalik