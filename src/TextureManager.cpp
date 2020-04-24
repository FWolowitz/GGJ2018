/*
** EPITECH PROJECT, 2018
** TextureManager
** File description:
** Implementation of TextureManager
*/

#include "TextureManager.hpp"

SDL_Texture *TextureManager::LoadTexture(const char *filename, SDL_Renderer *ren)
{
	SDL_Surface *tmpSurface = IMG_Load(filename);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(ren, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	return texture;
}

void TextureManager::Draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest, SDL_Renderer *renderer)
{
	SDL_RenderCopy(renderer, tex, &src, &dest);
}
