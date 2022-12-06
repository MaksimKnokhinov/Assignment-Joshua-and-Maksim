#ifndef _SCREENMANAGER_H
#define _SCREENMANAGER_H
#include "InputManager.h"
#include "StartScreen.h"
#include "Timer.h"
#include "PlayScreen.h"
namespace SDLFramework {

	class ScreenManager
	{
	private:
		static ScreenManager* sInstance;

	public:
		static ScreenManager* Instance();
		static void Release();

	private:
		ScreenManager();
		~ScreenManager();

	private:
		bool timerDone = false;
		Timer* m_pTimer;
		enum Screens { Start, Play };
		Screens mCurrentScreen; // <-- used to determine which screens needs to be render and updating
		InputManager* m_pInput;
		StartScreen* m_pStartScreen;
		PlayScreen* m_pPlayScreen;

	public:
		void Update();
		void Render();
	};
}
#endif // !_SCREENMANAGER_H

