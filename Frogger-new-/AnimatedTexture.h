#ifndef _ANIMATEDTEXTURE_H
#define _ANIMATEDTEXTURE_H
#include "Texture.h"
#include "Timer.h"

namespace SDLFramework {
	
	class AnimatedTexture : public Texture
	{
	public:
		enum WrapMode { Once = 0, Loop = 1 };
		enum AnimDir { Horizontal = 0, Vertical = 1 };

	private:
		Timer* m_pTimer;
		int mStartX;
		int mStartY;
		int mFrameCount; //how many frames
		float mAnimationSpeed; //This is in seconds
		float mTimerPerFrame; //time to display
		float mAnimationTimer; //time the animation is displayed

		WrapMode mWrapMode;
		AnimDir mAnimationDirection;

		bool mAnimationDone;

	public:
		AnimatedTexture(std::string filename, int x, int y, int w, int h, int frameCount, float animationSpeed,
			AnimDir animationDir, bool managed = false);
		~AnimatedTexture();
		
		void SetWrapMode(WrapMode mode);
		void ResetAnimation();
		bool IsAnimation();

		void Update();

	};

}



#endif // !1