#include "ScreenManager.h"
namespace SDLFramework {
	ScreenManager* ScreenManager::sInstance = nullptr;

	ScreenManager* ScreenManager::Instance() {
		if (sInstance == nullptr) {
			sInstance = new ScreenManager();
		}

		return sInstance;
	}

	void ScreenManager::Release() {
		delete sInstance;
		sInstance = nullptr;
	}

	ScreenManager::ScreenManager() {
		m_pTimer = Timer::Instance();
		m_pInput = InputManager::Instance();
		m_pStartScreen = new StartScreen();
		m_pPlayScreen = new PlayScreen();
		mCurrentScreen = Start;
	}

	ScreenManager::~ScreenManager() {
		m_pInput = nullptr;
		delete m_pStartScreen;
		m_pStartScreen = nullptr;
		delete m_pPlayScreen;
		m_pPlayScreen = nullptr;

	}

	void ScreenManager::Update() {
		float t = 0.0f;

		switch (mCurrentScreen) {
		case Start:
			m_pStartScreen->Update();
			if(m_pStartScreen->GetStartDone()){
				mCurrentScreen = Play;
			}
		;
		if (m_pInput->KeyPressed(SDL_SCANCODE_RETURN)) {

			mCurrentScreen = Play;
		}

			break;

		case Play:
			m_pPlayScreen->Update();
			break;
		}
	}

	void ScreenManager::Render() {


		switch (mCurrentScreen) {
		case Start:
			m_pStartScreen->Render();


			break;

		case Play:
			m_pPlayScreen->Render();
			break;
		}
	}
	void ScreenManager::ChangeScreen(int in){
		if (in >= 1) {

			mCurrentScreen = Play;
	 }
		if (in <= 0) {
			mCurrentScreen = Start;
		}
	
	
	}
}