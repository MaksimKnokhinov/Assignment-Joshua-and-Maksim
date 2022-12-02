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
		// this is how we check which key is pressed on the keyboard or mouse.

		if (m_pInputManager->KeyDown(SDL_SCANCODE_W)) { //this is for the W key
			m_pTexture->Translate(Vector2(0, -25.f) * m_pTimer->DeltaTime(), GameEntity::World); //this moves the ship up 40 pixels
		}
		else if (m_pInputManager->KeyDown(SDL_SCANCODE_S)) {
			m_pTexture->Translate(Vector2(0, 25.f) * m_pTimer->DeltaTime(), GameEntity::World); //this moves down
		}

		if (m_pInputManager->KeyPressed(SDL_SCANCODE_E)) { //This will cause the ship to rotate with the e key
			m_pTexture->Rotate(20.0f);                     //If we want to do it constantly change pressed to KeyDown
		}                                                   //To rotate in the opposite direction you would change to negative number

		if (m_pInputManager->KeyPressed(SDL_SCANCODE_SPACE)) {
			std::cout << "Space pressed!" << std::endl;
		}
		if (m_pInputManager->KeyReleased(SDL_SCANCODE_SPACE)) {
			std::cout << "Space released!" << std::endl;
		}
		if (m_pInputManager->MouseButtonPressed(InputManager::Left)) { //this will display Left Mouse Button Pressed
			std::cout << "Left Mouse Button Pressed!" << std::endl;
		}
		if (m_pInputManager->MouseButtonReleased(InputManager::Left)) { 
			std::cout << "Left Mouse Button Released!" << std::endl;

		}
		if (m_pInputManager->KeyDown(SDL_SCANCODE_1)) {
			m_pAudioManager->PlaySFX("SFX/coin_credit.wav", 0, 0);
		}

	}
	void GameManager::LateUpdate() {
		m_pInputManager->UpdatePrevInput();
	}
	void GameManager::Render() {
		m_pGraphics->ClearBackBuffer(); // call on this one first
		//The order we render matters
		//We render on top of each one.
		m_pTexture->Render();
		m_pFontTex->Render();

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

		m_pTexture = new AnimatedTexture("GalagaSpriteSheet.png", 204,45,40,38,4,0.5f, AnimatedTexture::Horizontal);
		m_pTexture->Position(Vector2(Graphics::SCREEN_WIDTH * 0.5f,
			Graphics::SCREEN_HEIGHT * 0.5f));

		//Adding a font texture to the game window
		m_pFontTex = new Texture("BRICK BREAKER!", "ARCADE.TTF", 75, { 100,100,255 });
		//Setting the position for the text
		m_pFontTex->Position(Vector2(400, 200));
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
		delete m_pFontTex;
		m_pFontTex = nullptr;
		AudioManager::Release();
		m_pAudioManager = nullptr;

		SDL_Quit();
	}
}