/*
** EPITECH PROJECT, 2018
** Game
** File description:
** Implementation of Game
*/

#include "Game.hpp"
#include "GameObject.hpp"
#include "Eagle.hpp"

MapObject *Game::map = nullptr;
Game::Game() = default;
Game::~Game()
= default;

void Game::init(const char *title, int xpos, int ypos, int width, int height,
		bool fullscreen)
{
	Mix_Music *musique = Mix_LoadMUS("data/theme.ogg");
	int flags = 0;
	if (fullscreen)
		flags = SDL_WINDOW_FULLSCREEN;
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		window = SDL_CreateWindow(title, xpos, ypos, width, height,
					  flags);
		if (!window) {
			std::cout << "window issue" << std::endl;
			return;
		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (!renderer) {
			std::cout << "renderer issue" << std::endl;
			return;
		} else
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		isRunning = true;
	} else {
		std::cout << "init issue" << std::endl;
		isRunning = false;
	}
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
	Mix_PlayMusic(musique, -1);
	map = new MapObject(renderer);
	background2 = TextureManager::LoadTexture("data/background.png",
						  renderer);
	background = TextureManager::LoadTexture("data/background2.png",
						 renderer);

	keyLeft = false;
	keyRight = false;
	keySpace = false;
	keyDown = false;
	keyF = false;
	keyUp = false;

	piaf = new Eagle("data/eagle-attack.png", renderer,
			 64 * 10, HEIGHT - 8 * 64, 4);
	player = new GameObject("data/player.png", renderer,
				64 * 3, HEIGHT - 4 * 64, 8);
}

void Game::update()
{
	player->Update();
	if (!piaf->isDead())
		piaf->Update();

	if (keyLeft)
		player->moveLeft();
	if (keyRight)
		player->moveRight();
	if (keySpace && !player->IsEagle())
		player->jump();
	if (keyUp && player->IsEagle())
		player->flyUp();
	if (keyDown && player->IsEagle())
		player->flyDown();
	if (keyF && !player->IsEagle())
	{
		player->isEagle = true;
		piaf->Die();
	}
}

void Game::render()
{
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, background, nullptr, nullptr);
	SDL_RenderCopy(renderer, background2, nullptr, nullptr);
	map->DrawMap();
	if (!piaf->isDead())
		piaf->Render();
	player->Render();
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

bool Game::running() const
{
	return isRunning;
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
				case SDLK_LEFT:
					keyLeft = true;
					break;
				case SDLK_RIGHT:
					keyRight = true;
					break;
				case SDLK_SPACE:
					keySpace = true;
					break;
				case SDLK_f:
					keyF = true;
					break;
				case SDLK_UP:
					keyUp = true;
					break;
				case SDLK_DOWN:
					keyDown = true;
					break;
			}
			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym) {
				case SDLK_LEFT:
					keyLeft = false;
					break;
				case SDLK_RIGHT:
					keyRight = false;
					break;
				case SDLK_SPACE:
					keySpace = false;
					break;
				case SDLK_f:
					keyF = false;
					break;
				case SDLK_UP:
					keyUp = false;
					break;
				case SDLK_DOWN:
					keyDown = false;
					break;
			}
			break;
		case SDL_QUIT:
			isRunning = false;
			break;

		default:
			break;
	}
}

void Game::handleEventsHelper()
{

}
