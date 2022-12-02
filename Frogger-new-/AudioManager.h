#ifndef _AUDIOMANAGER_H
#define _AUDIOMANAGER_H
#include "AssetManager.h"

namespace SDLFramework {
	class AudioManager {
	private:
		static AudioManager* sInstance;
		AssetManager* m_pAssetManager;

	public:
		static AudioManager* Instance();
		static void Release();

	private:
		AudioManager();
		~AudioManager();

	public:
		void PlayMusic(std::string filename, int loops = -1); //-1 plays music infinitely 
		void PlayMusic(Mix_Music* music, int loops = -1);
		void PauseMusic();
		void ResumeMusic();
		void PlaySFX(std::string filename, int loops = 0, int channel = -1);
		void PlaySFX(Mix_Chunk* sfx, int loops = 0, int channel = -1);

	};

}

#endif // !_AUDIOMANAGER_H



