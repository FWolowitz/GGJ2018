/*
** EPITECH PROJECT, 2017
** main.cpp
** File description:
** main file for bacterium project
*/

#include <SDL2/SDL.h>
#include "Game.hpp"

int main()
{
	const int FPS = 60;
	const int frameDelay = 1000/ FPS;

	Uint32 frameStart;
	Uint32 frameTime;

	Game *game = new Game();

	game->init("Bacterium", SDL_WINDOWPOS_CENTERED,
		   SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, false);
	while (game->running())
	{
		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}
	game->clean();
	return (0);
}