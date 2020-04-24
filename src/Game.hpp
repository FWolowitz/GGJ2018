/*
** EPITECH PROJECT, 2018
** Game
** File description:
** Declaration of Game
*/

#ifndef GGJ18_GAME_HPP
#define GGJ18_GAME_HPP

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"
#include <iostream>
#include "TextureManager.hpp"
#include "MapObject.hpp"

#define HEIGHT 732
#define WIDTH 1366
#define RES 64

class GameObject;
class Eagle;

class Game
{
public:
	Game();
	~Game();
	void init(const char *title, int xpos, int ypos, int width, int height,
		  bool fullscreen);
	void update();
	void render();
	void clean();
	void handleEvents();
	void handleEventsHelper();
	bool running() const;
	static MapObject *map;
private:
	bool keyLeft;
	bool keyRight;
	bool keySpace;
	bool keyDown;
	bool keyF;
	bool keyUp;

	bool isRunning;
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Texture *background;
	SDL_Texture *background2;
	GameObject *player;
	Eagle *piaf;
};


#endif //GGJ18_GAME_HPP
