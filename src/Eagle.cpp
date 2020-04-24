/*
** EPITECH PROJECT, 2018
** Eagle
** File description:
** Implementation of Eagle
*/

#include "Eagle.hpp"
#define NUMBER_OF_ANIM_PER_FRAME 6

Eagle::Eagle(const char *texture, SDL_Renderer *ren, int x, int y,
	     int spritesCount) : GameObject(texture, ren, x, y, spritesCount)
{
	cnt = 0;

	objSurfaceEagle = IMG_Load("data/Possession.png");
	objTextureEagle = SDL_CreateTextureFromSurface(ren, objSurfaceEagle);
	Dead = false;
}

void Eagle::Update()
{
		if (++cnt == 1)
			animationStatus++;
		if (cnt >= (60 / NUMBER_OF_ANIM_PER_FRAME))
			cnt = 0;
		srcRect.w = objSurface->w / spritesCount;
		srcRect.h = objSurface->h;

		srcRect.x = objSurface->w / spritesCount * (animationStatus % spritesCount);
		srcRect.y = 0;

		destRect.w = srcRect.w * 4;
		destRect.h = srcRect.h * 4;
		destRect.x = xpos;
		destRect.y = ypos - srcRect.w * 4;
}

void Eagle::Render()
{
	SDL_RenderCopyEx(renderer, objTexture, &srcRect, &destRect, 0, nullptr,
			 (direction == LEFT ? SDL_FLIP_HORIZONTAL
					    : SDL_FLIP_NONE));
}

void Eagle::Die()
{
	Dead = true;
	animationStatus = 0;
	spritesCount = 5;
	objSurface = objSurfaceEagle;
	objTexture = objTextureEagle;
}

bool Eagle::isDead()
{
	return (Dead && animationStatus > 4);
}
