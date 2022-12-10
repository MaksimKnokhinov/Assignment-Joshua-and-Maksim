#include "Player.h"
using namespace SDLFramework;
float t_timer = 0;
Player* Player::sInstance = nullptr;
Player* Player::Instance()
    {
        if (sInstance == nullptr) {
            sInstance = new Player;
           
        }
        return sInstance;
    }

    Player::Player()
    {
        mState = Idle;
      
        mDirect = Up;
        oldPos = Position();
        m_pAudioMan = AudioManager::Instance();
        mAlive = true;

        mJumpDown = new AnimatedTexture("JumpDown.png", 0, 0, 49, 49, 2,1.9f, AnimatedTexture::Horizontal);
        mJumpDown->Parent(this);
        mJumpDown->Position(oldPos);
                mJumpUp = new AnimatedTexture("JumpUp.png", 0, 0, 49, 49, 2,1.9f, AnimatedTexture::Horizontal);
        mJumpUp->Parent(this);
        mJumpUp->Position(oldPos);
                mJumpRight = new AnimatedTexture("JumpRight.png", 0, 0, 49, 49, 2,1.9f, AnimatedTexture::Horizontal);
        mJumpRight->Parent(this);
        mJumpRight->Position(oldPos);
        mJumpLeft = new AnimatedTexture("JumpLeft.png", 0, 0, 49, 49, 2,1.9f, AnimatedTexture::Horizontal);
        mJumpLeft->Parent(this);
        mJumpLeft->Position(oldPos);  
        mIdleDown = new AnimatedTexture("downidle.png", 0, 0, 49, 49, 2,1.9f, AnimatedTexture::Horizontal);
        mIdleDown->Parent(this);
        mIdleDown->Position(oldPos);
                mIdleUp = new AnimatedTexture("idleup.png", 0, 0, 49, 49, 2,1.9f, AnimatedTexture::Horizontal);
        mIdleUp->Parent(this);
        mIdleUp->Position(oldPos);
       mIdleRight = new AnimatedTexture("idleright.png", 0, 0, 49, 49, 2,1.9f, AnimatedTexture::Horizontal);
        mIdleRight->Parent(this);
        mIdleRight->Position(oldPos);
        mIdleLeft = new AnimatedTexture("idleleft.png", 0, 0, 49, 49, 2,1.9f, AnimatedTexture::Horizontal);
        mIdleLeft->Parent(this);
        mIdleLeft->Position(oldPos);
        
        m_pTimer = Timer::Instance();
        mAnimationTimer = 0.0f;
        mAnimationTotalTime = 3.0f;
        
        m_pInput = InputManager::Instance();


        m_pShownTexture = mJumpUp;
    }

    Player::~Player()
    {
    }

    void Player::Move()
    {
        Vector2 newPos;

        if (mDirect==Up) {
            t_timer = 0;
            mAnimationTimer = 0;
            mAnimationTimer += m_pTimer->DeltaTime();
            oldPos = Position();
            newPos = Vector2{ oldPos.x * 1.0f, oldPos.y - (Graphics::SCREEN_HEIGHT * .7f) };
           Position(Lerp(oldPos, newPos, mAnimationTimer / mAnimationTotalTime));
            m_pAudioMan->PlaySFX("frogger-hop.wav", 0, -1);
            m_pShownTexture = mJumpUp;
            mState = Jump;
        }
        if (mDirect==Down) {
            t_timer = 0;
            mAnimationTimer = 0;
          mAnimationTimer += m_pTimer->DeltaTime();
          oldPos = Position();
          newPos = Vector2{ oldPos.x, oldPos.y+(Graphics::SCREEN_HEIGHT*.7f)};
          
          Position(Lerp(oldPos, newPos, mAnimationTimer / mAnimationTotalTime));
          m_pAudioMan->PlaySFX("frogger-hop.wav", 0, -1);
          m_pShownTexture = mJumpDown;
          mState = Jump;
        
        } 
        if (mDirect==Left) {
            t_timer = 0;
            mAnimationTimer = 0;
            mAnimationTimer += m_pTimer->DeltaTime();
            oldPos =Position();
            newPos =  Vector2{ oldPos.x-(Graphics::SCREEN_WIDTH*.7f), oldPos.y * 1.0f};
         Position(Lerp(oldPos ,newPos, mAnimationTimer / mAnimationTotalTime));
            m_pAudioMan->PlaySFX("frogger-hop.wav", 0, -1);
            mState = Jump;
            m_pShownTexture = mJumpLeft;   //
         
        } 
        if (mDirect==Right) {
            t_timer = 0;
     
            mAnimationTimer = 0;
            mAnimationTimer += m_pTimer->DeltaTime();
            oldPos = Position();
            newPos = Vector2{ oldPos.x + (Graphics::SCREEN_WIDTH * .7f), oldPos.y * 1.0f };
            Position(Lerp(oldPos, newPos, mAnimationTimer / mAnimationTotalTime));
            m_pAudioMan->PlaySFX("frogger-hop.wav", 0, -1);
            mState = Jump;
            m_pShownTexture = mJumpRight;
        }

        
    }

    void Player::Direction(std::string Direct)
    {
        if (Direct == "up" || Direct=="Up") {
            mDirect = Up;
        }    if (Direct == "down" || Direct=="Down") {
            mDirect = Down;
        }    if (Direct == "left" || Direct=="Left") {
            mDirect = Left;
        }    if (Direct == "right" || Direct=="Right") {
            mDirect = Right;
        }
        
    }

    void Player::LoopTexture()
    {

        if (mDirect = Up) {
            if (mState == Idle) {
                m_pShownTexture = mIdleUp;
            }
            else { mJumpUp->Update(); }
        }



        if (mDirect = Left) {
            if (mState == Idle) {
                m_pShownTexture = mIdleLeft;
            }
            else { mJumpLeft->Update(); }
        }


        if (mDirect = Right) {
            if (mState == Idle) {
                m_pShownTexture = mIdleRight;
            }
            else { mJumpRight->Update(); }
        }




        if (mDirect = Down) {

            if (mState == Idle) {
                m_pShownTexture = mIdleDown;
            }
            else { mJumpDown->Update(); }
        }



    }
    
       void Player::Update() {

           t_timer += m_pTimer->DeltaTime();
           if (t_timer > 0.5f) {
               mState = Idle;
               LoopTexture();
           }
       }
    bool Player::DIE()
    {
        return false;
    }
    void Player::Render() {
        m_pShownTexture->Render();
        m_pShownTexture->Update();
    }