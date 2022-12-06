#include "GameManager.h"

namespace SDLFramework {
	GameManager* GameManager::sInstance = nullptr;

	GameManager* GameManager::Instance() {

		if (sInstance == nullptr) {
			sInstance = new GameManager();
		}
		return sInstance;
	}

	void GameManager::Release() {
		delete sInstance;
		sInstance = nullptr;
	}



	void GameManager::Run() {
		while (!mQuit) {
			m_pTimer->Update();
			while (SDL_PollEvent(&mEvent)) {
				switch (mEvent.type) {
				case SDL_QUIT:
					mQuit = true;
					break;
				}
			}
			
			if (m_pTimer->DeltaTime() >= 1.0f / FRAME_RATE) {
				m_pTimer->Reset();
				Update();
				LateUpdate();
				Render();
			}

			Update();
			LateUpdate();
			Render();
		}
	}
	void GameManager::Update() {
		m_pInputManager->Update();
		m_pTexture->Update();
		m_pScreenManager->Update();
		// this is how we check which key is pressed on the keyboard or mouse.

		
		}
	void GameManager::LateUpdate() {
		m_pInputManager->UpdatePrevInput();
	}
	void GameManager::Render() {
		m_pGraphics->ClearBackBuffer(); // call on this one first
		//The order we render matters
		//We render on top of each one.
		m_pTexture->Render();

		m_pScreenManager->Render();
		m_pGraphics->Render(); // This should be called last, code reads top to bottom. this is like layers in canva
	}

	GameManager::GameManager() : mQuit(false) {
		m_pGraphics = Graphics::Instance();
		m_pTimer = Timer::Instance();
		if (!Graphics::Initialized()) {
			mQuit = true;
		}

		m_pAssetManager = AssetManager::Instance();
		m_pInputManager = InputManager::Instance();
		m_pAudioManager = AudioManager::Instance();
		m_pScreenManager = ScreenManager::Instance();
		m_pTexture = new AnimatedTexture("GalagaSpriteSheet.png", 204,45,40,38,4,0.5f, AnimatedTexture::Horizontal);
		m_pTexture->Position(Vector2(Graphics::SCREEN_WIDTH * 0.5f,
			Graphics::SCREEN_HEIGHT * 0.5f));

		//Adding a font texture to the game window
	

	}

	GameManager::~GameManager() {
		Graphics::Release();
		Timer::Release();
		m_pGraphics = nullptr;
		m_pTimer = nullptr;
		delete m_pTexture;
		m_pTexture = nullptr;
		AssetManager::Release();
		m_pAssetManager = nullptr;
		InputManager::Release();
		m_pInputManager = nullptr;
		
		
		AudioManager::Release();
		m_pAudioManager = nullptr;

		ScreenManager::Release();
		m_pScreenManager = nullptr;
		SDL_Quit();
	}
}