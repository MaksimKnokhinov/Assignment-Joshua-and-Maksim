#include "Graphics.h"

namespace SDLFramework {
	Graphics* Graphics::sInstance = nullptr;
	bool Graphics::sInitialized = false;

	Graphics* Graphics::Instance() {
		if (sInstance == nullptr) {
			sInstance = new Graphics();

		}
		return sInstance;

	}

	void Graphics::Release() {
		delete sInstance;
		sInstance = nullptr;
		sInitialized = false;
	}

	bool Graphics::Initialized() {
		return sInitialized;
	}

	void Graphics::ClearBackBuffer() {
		SDL_RenderClear(m_pRenderer);
	}

	void Graphics::Render() {
		SDL_RenderPresent(m_pRenderer);
	}

	Graphics::Graphics() {
		sInitialized = Init();
	}

	Graphics::~Graphics() {
		SDL_DestroyRenderer(m_pRenderer);
		SDL_DestroyWindow(m_pWindow);
	}

	bool Graphics::Init() {
		if (SDL_InitSubSystem(SDL_INIT_VIDEO) < 0) {
			std::cerr << "Unable to initialize SDL! SDL Error: " << SDL_GetError() << std::endl;
			return false;
		}

		if (TTF_Init() == -1) {
			std::cerr << "Unable to initialize SDL_ttf! TTF Error: " << TTF_GetError() << std::endl;
			return false; // return false will kill the game
		}

		m_pWindow = SDL_CreateWindow(
			"SDL_Tutorial",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN);

		if (m_pWindow == nullptr) {
			std::cerr << "Unable to create Window! SDL Error: " << SDL_GetError() << std::endl;
			return false;
		}

		m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED);

		if (m_pRenderer == nullptr) {
			std::cerr << "Unable to create renderer! SDL Error: " << SDL_GetError() << std::endl;
			return false;
		}

		return true;
	}

	SDL_Texture* Graphics::LoadTexture(std::string path) {
		SDL_Texture* tex = nullptr;

		SDL_Surface* surface = IMG_Load(path.c_str());

		if (surface == nullptr) {
			std::cerr << "Unable to load " << path << ". IMG_Error: " << IMG_GetError() << std::endl;
			SDL_FreeSurface(surface);
			return nullptr;
		}

		tex = SDL_CreateTextureFromSurface(m_pRenderer, surface);

		SDL_FreeSurface(surface);
		return tex;
	}

	void Graphics::DrawTexture(SDL_Texture* tex, SDL_Rect* srcRect, SDL_Rect* dstRect,
		float angle, SDL_RendererFlip flip) {

		SDL_RenderCopyEx(m_pRenderer, tex, srcRect, dstRect, angle, nullptr, flip);
	}

	SDL_Texture* Graphics::CreateTextTexture(TTF_Font* font, std::string text, SDL_Color color) {
		SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);

		if (surface == nullptr) {
			std::cerr << "CreateTextTexture:: TTF_RenderText_Solid Error: " << TTF_GetError() << std::endl;
			return nullptr;
		}

		SDL_Texture* tex = SDL_CreateTextureFromSurface(m_pRenderer, surface);

		if (tex == nullptr) {
			std::cerr << "CreateTExtTexture:: SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
			return nullptr;
		}

		SDL_FreeSurface(surface);
		return tex;
	}
}

