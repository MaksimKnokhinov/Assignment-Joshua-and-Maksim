#ifndef _INPUTMANAGER_H
#define _INPUTMANAGER_H
#include <SDL.h>
#include "MathHelper.h"
#include <string>

namespace SDLFramework {
	class InputManager
	{
	public:
		enum MouseButton { Left = 0, Right, Middle, Back, Forward };
	private:
		static InputManager* sInstance;

	public:
		static InputManager* Instance();
		static void Release();

	private:
		const Uint8* m_pKeyboardState; //means unsigned 8 bit interger
		Uint8* m_pPrevKeyboardState; //both are arrays of 8 bit intergers
		int mKeyLength;

		Uint32 mPrevMouseState;
		Uint32 mMouseState;
		int mMouseXPosition;
		int mMouseYPosition;

	public:
		bool KeyDown(SDL_Scancode scancode); // Is for holding down the key
		bool KeyPressed(SDL_Scancode scancode); // Single press
		bool KeyReleased(SDL_Scancode scancode); // Releasing the key

		bool MouseButtonDown(MouseButton button);   //This is for mouse movement
		bool MouseButtonPressed(MouseButton button);
		bool MouseButtonReleased(MouseButton button);

		Vector2 MousePosition();

		void Update();
		void UpdatePrevInput();

	private:
		InputManager();
		~InputManager();


	};
};

#endif //!_INPUTMANAGER_H

