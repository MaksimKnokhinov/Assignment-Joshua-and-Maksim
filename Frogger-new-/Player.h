#ifndef  _Player_h
#define _Player_h
#include"Texture.h"
#include "InputManager.h"
#include "AudioManager.h"
#include"Timer.h"
#include"AnimatedTexture.h"
#include "GameEntity.h"
using namespace SDLFramework;
class Player : public GameEntity
{
public :
	enum State {
		Jump, Idle
	};
	enum Direction {
		Up, Down, Left,Right
	};
private:
	static Player* sInstance;
	Timer* m_pTimer;
	AnimatedTexture* m_pShownTexture;
	AnimatedTexture* mIdleDown;
	AnimatedTexture* mIdleRight;
	AnimatedTexture* mIdleLeft;
	AnimatedTexture* mIdleUp;
	AnimatedTexture* mJumpRight;
	AnimatedTexture* mJumpLeft;
	AnimatedTexture* mJumpUp;
	AnimatedTexture* mJumpDown;
	bool mAlive;
	State mState = Idle;
	Vector2 oldPos;
	AudioManager* m_pAudioMan;
	InputManager* m_pInput;
	float mAnimationTotalTime;
	float mAnimationTimer;
	Direction mDirect;
	int lives =5 ;
public:
	static Player* Instance();
	
	Player();


	~Player();
	void Update();
	void Move();
	void Direction(std::string Direct );

	void LoopTexture();


public:
	bool DIE();

	void Render();
};

#endif // ! _Player_h
