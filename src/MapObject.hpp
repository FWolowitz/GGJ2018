/*
** EPITECH PROJECT, 2018
** MapObject
** File description:
** Declaration of MapObject
*/

#ifndef GGJ18_MAPOBJECT_HPP
#define GGJ18_MAPOBJECT_HPP


#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <vector>
#include "Map.hpp"

class MapObject
{
public:
	explicit MapObject(SDL_Renderer *renderer);
	virtual ~MapObject();
	void LoadMap(const std::string &);
	void DrawMap();
	Map *getMap() const;
private:
	SDL_Rect src, dest;
	SDL_Texture *dirt;
	SDL_Texture *sign;
	SDL_Texture *grass;
	SDL_Texture *cliff;
	SDL_Texture *platform;
	SDL_Renderer *renderer;
	Map *map;
};


#endif //GGJ18_MAPOBJECT_HPP
