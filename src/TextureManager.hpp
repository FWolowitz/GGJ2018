/*
** EPITECH PROJECT, 2018
** TextureManager
** File description:
** Declaration of TextureManager
*/

#ifndef GGJ18_TEXTUREMANAGER_HPP
	#define GGJ18_TEXTUREMANAGER_HPP

#include "Game.hpp"

class TextureManager
{
public:
	static SDL_Texture *LoadTexture(const char *filename, SDL_Renderer *ren);
	static void Draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest, SDL_Renderer *renderer);
};


#endif //GGJ18_TEXTUREMANAGER_HPP
