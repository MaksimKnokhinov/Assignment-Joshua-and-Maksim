

#include "StartScreen.h"
bool t_bool = false;

StartScreen::StartScreen() {
	m_pTimer = Timer::Instance();
	m_pInputManager = InputManager::Instance();
	mAninmationTitleStage = 0;
	// Top bar entities
	m_pTopBar = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, 80.0f);
	m_pPlayerOne = new Texture("1UP", "emulogic.ttf", 32, { 200,0,0 });

	m_pHiScore = new Texture("HI SCORE", "emulogic.ttf", 32, { 200,0,0 });
	m_pPlayerOneScore = new ScoreBoard;

	m_pTopScore = new ScoreBoard;

	// Play mode entities
	m_pPlayModes = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.55f);
	m_pOnePlayerMode = new Texture("1 Player ", "emulogic.ttf", 32, { 230,230,230 });

	m_pCursor = new Texture("Cursor.png");

	// Bottom Bar Entities
	m_pBottomBar = new GameEntity(Graphics::SCREEN_WIDTH * 0.5f, Graphics::SCREEN_HEIGHT * 0.7f);

	m_pKonami = new Texture("namcot", "namco__.ttf", 36, { 200,0,0 });
	m_pDates = new Texture("1982 1985 NAMCO LTD.", "emulogic.ttf", 32, { 230, 230, 230 });
	m_pRights = new Texture("ALL RIGHTS RESERVED", "emulogic.ttf", 32, { 230,230,230 });

	// Logo Entities
	m_pFrogLogo = new GameEntity(Graphics::SCREEN_WIDTH , Graphics::SCREEN_HEIGHT );
	m_pLogo = new Texture("FroggerLogo.png", 0, 0, 901, 442);

	m_pLogo->Position(Graphics::SCREEN_WIDTH, Graphics::SCREEN_HEIGHT);
	m_pLogo->Parent(m_pFrogLogo);
	m_pAnimatedLogo = new Texture("FroggerLogo.png", 0, 0, 901, 442);
	m_pAnimatedLogo->Parent(m_pFrogLogo);
	m_pAnimatedLogo->Position(Graphics::SCREEN_WIDTH, Graphics::SCREEN_HEIGHT);

	// Top bar entities
	m_pTopBar->Parent(this);
	m_pPlayerOne->Parent(m_pTopBar);

	m_pHiScore->Parent(m_pTopBar);
	m_pPlayerOneScore->Parent(m_pTopBar);

	m_pTopScore->Parent(m_pTopBar);

	// Play mode entities
	m_pPlayModes->Parent(this);
	m_pOnePlayerMode->Parent(m_pPlayModes);

	m_pCursor->Parent(m_pPlayModes);

	// Bottom Bar Entities
	m_pBottomBar->Parent(this);
	m_pKonami->Parent(m_pBottomBar);
	m_pDates->Parent(m_pBottomBar);
	m_pRights->Parent(m_pBottomBar);

	// Top bar entities
	m_pPlayerOne->Position(-Graphics::SCREEN_WIDTH * 0.35f, 0.0f);

	m_pHiScore->Position(-30.0f, 0.0f);
	m_pPlayerOneScore->Position(-Graphics::SCREEN_WIDTH * 0.32f, 40.0f);

	m_pTopScore->Position(Graphics::SCREEN_WIDTH * 0.05f, 40.0f);
	m_pTopScore->Score(4242564);

	// Play mode entities
	m_pOnePlayerMode->Position(0.0f, -35.0f);

	m_pCursor->Position(-175.0f, -35.0f);

	// Bottom Bar Entities
	m_pKonami->Position(Vec2_Zero);
	m_pDates->Position(0.0f, 90.0f);
	m_pRights->Position(0.0f, 170.0f);

	mAnimationStartPos = Vector2(Graphics::SCREEN_WIDTH,0.0f);
	mAnimationEndPos = Vector2(Graphics::SCREEN_WIDTH*.5F, Graphics::SCREEN_HEIGHT);
	mAnimationTotalTime = 5.0f;
	mAnimationTimer = 0.0f;
	mAnimationDone = false;

	Position(mAnimationStartPos);

	/*mCursorStartPos = m_pCursor->Position(Local);
	mCursorOffset = Vector2(0.0f, 70.0f);*/
	mSelectedMode = 0; // 0 for single player and 1 for 2 players

	ResetAnimation();


}

StartScreen::~StartScreen() {
	delete m_pTopBar;
	m_pTopBar = nullptr;

	delete m_pPlayerOne;
	m_pPlayerOne = nullptr;
	delete m_pFrogLogo;
	m_pFrogLogo = nullptr;


	delete m_pHiScore;
	m_pHiScore = nullptr;

	m_pTimer = nullptr;
	m_pInputManager = nullptr;

	delete m_pPlayModes;
	m_pPlayModes = nullptr;

	delete m_pOnePlayerMode;
	m_pOnePlayerMode = nullptr;



	//delete m_pCursor;
	//m_pCursor = nullptr;

	delete m_pBottomBar;
	m_pBottomBar = nullptr;

	delete m_pKonami;
	m_pKonami = nullptr;

	delete m_pDates;
	m_pDates = nullptr;

	delete m_pRights;
	m_pRights = nullptr;

	delete m_pLogo;
	m_pLogo = nullptr;

	delete m_pAnimatedLogo;
	m_pAnimatedLogo = nullptr;

	delete m_pPlayerOneScore;
	m_pPlayerOneScore = nullptr;



	delete m_pTopScore;
	m_pTopScore = nullptr;
}

void StartScreen::FrogTitleAnimStage()
{
	if (mAninmationTitleStage == 0) {

		mAnimationStartPos = Vector2(0, Graphics::SCREEN_HEIGHT * 1.0f);
		mAnimationEndPos = Vector2(Graphics::SCREEN_WIDTH*.5f, Graphics::SCREEN_HEIGHT * 1.0f);
	}
	 if(mAninmationTitleStage==1){

		 if (!t_bool) {
			 mAnimationTimer = 0;
			 mAnimationStartPos = Vector2(Graphics::SCREEN_WIDTH * .5f, 1.0f);

			 mAnimationEndPos = Vector2(.5f, Graphics::SCREEN_HEIGHT * -0.5f);
			 t_bool = true;
		 }//a check to make onlyfireonce


	}
	
																					
}

void StartScreen::ChangeFrogTitleAnimStage()
{
	
	if (mAninmationTitleStage <=0) {
		mAninmationTitleStage = 1;
	}
	else if(mAninmationTitleStage>=1){
		//mAninmationTitleStage = 0;
		mAnimationDone = true;
	}
}

void StartScreen::ChangeSelectedMode(int change) {
	mSelectedMode += change;

	if (mSelectedMode < 0) {
		mSelectedMode = 1;
	}
	else if (mSelectedMode > 1) {
		mSelectedMode = 0;
	}

	m_pCursor->Position(mCursorStartPos + mCursorOffset * (float)mSelectedMode);
}

void StartScreen::Update() {
	
	
	if (!mAnimationDone) {
		FrogTitleAnimStage();	
		mAnimationTimer += m_pTimer->DeltaTime();
		m_pFrogLogo->Position(Lerp(mAnimationStartPos, mAnimationEndPos, mAnimationTimer / mAnimationTotalTime));
		
	
		
		if (mAnimationTimer >= mAnimationTotalTime) {
			

			ChangeFrogTitleAnimStage();
			FrogTitleAnimStage();
			m_pFrogLogo->Position(Lerp(mAnimationStartPos, mAnimationEndPos, mAnimationTimer / mAnimationTotalTime));
			if (mAnimationTimer >= mAnimationTotalTime) {
				
				ChangeFrogTitleAnimStage();
			}
		}
	}
}
void StartScreen::Render() {



	m_pPlayerOne->Render();

	m_pHiScore->Render();
	m_pOnePlayerMode->Render();

	//m_pCursor->Render();
	m_pKonami->Render();
	m_pDates->Render();
	m_pRights->Render();

	m_pTopScore->Render();

	if (!mAnimationDone) {
		m_pLogo->Render();
	}
	else {
		m_pAnimatedLogo->Render();
	}
}

void StartScreen::ResetAnimation() {

	mAnimationStartPos = Vector2(0, Graphics::SCREEN_HEIGHT * 1.0f);
	mAnimationEndPos = Vector2(Graphics::SCREEN_WIDTH * .5F, Graphics::SCREEN_HEIGHT * 1.0f);
	mAnimationTotalTime = 5.0f;
	mAnimationTimer = 0.0f;
	mAnimationDone = false;
	Position(mAnimationStartPos);

	//m_pCursor->Position(-175.0f, -35.0f);
	//mCursorStartPos = m_pCursor->Position(Local);
	//mCursorOffset = Vector2(0.0f, 70.0f);
	mSelectedMode = 0;
}

int StartScreen::SelectedMode() {
	return mSelectedMode;
}