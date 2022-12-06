#ifndef _GAMEMANAGER_H
#define _GAMEMANAGER_H
#include "Graphics.h"
#include "Timer.h"
#include "GameEntity.h"
#include "AnimatedTexture.h"
#include "InputManager.h"
#include "AudioManager.h"
#include"ScreenManager.h"
namespace SDLFramework {
	class GameManager
	{
	private:
		const int FRAME_RATE = 60;

	private:
		static GameManager* sInstance;
		bool mQuit;
		Graphics* m_pGraphics;
		AssetManager* m_pAssetManager;
		Texture* m_pTexture;
		SDL_Event mEvent;
		Timer* m_pTimer;
	
		InputManager* m_pInputManager;

		AudioManager* m_pAudioManager;
		ScreenManager* m_pScreenManager;
	public:
		static GameManager* Instance();
		static void Release();

		void Run();
		void Update();  //player update
		void LateUpdate(); //physics or collision update
		void Render();

	private:
		GameManager();
		~GameManager();
	};
}
#endif

