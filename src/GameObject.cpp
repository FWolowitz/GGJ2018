/*
** EPITECH PROJECT, 2018
** GameObject
** File description:
** Implementation of GameObject
*/

#include "GameObject.hpp"

GameObject::GameObject(const char *filename, SDL_Renderer *ren, int x, int y,
		       int spritesNb)
{
	xpos = x;
	ypos = y;
	renderer = ren;
	spritesCount = spritesNb;
	direction = 1;
	animationStatus = 0;
	jumpStatus = 0;
	jumpSpeed = 7;
	maxJump = 160;
	speed = 8;
	objSurface = IMG_Load(filename);
	objTexture = SDL_CreateTextureFromSurface(ren, objSurface);
	objSurfaceEagle = IMG_Load("data/bad-eagle.png");
	objTextureEagle = SDL_CreateTextureFromSurface(ren, objSurfaceEagle);
	isEagle = false;
	cnt2 = 0;
}

GameObject::~GameObject()
{
	SDL_FreeSurface(objSurface);
}

void GameObject::Update()
{
	if (isEagle)
	{
		if (++cnt2 == 1)
			animationStatus++;
		if (cnt2 >= (60 / 6))
			cnt2 = 0;
		srcRect.w = objSurfaceEagle->w / 4;
		srcRect.h = objSurfaceEagle->h;

		srcRect.x = objSurfaceEagle->w / 4 * (animationStatus % 4);
		srcRect.y = 0;

		destRect.w = srcRect.w * 4;
		destRect.h = srcRect.h * 4;
		destRect.x = xpos;
		destRect.y = ypos - srcRect.w * 4;
	}
	else
	{
		processJump();
		srcRect.h = objSurface->h / 3;
		srcRect.w = objSurface->w / spritesCount;
		if (jumpStatus) {
			srcRect.x =
				objSurface->w / spritesCount * (animationStatus % 3);
			srcRect.y = objSurface->h / 3;
		} else {
			srcRect.x = objSurface->w / spritesCount *
				    (animationStatus % spritesCount);
			srcRect.y = 0;
		}

		destRect.w = srcRect.w * 2;
		destRect.h = srcRect.h * 2;
		destRect.x = xpos;
		destRect.y = ypos - srcRect.w * 2;
	}
}

void GameObject::processJump()
{
	int tmpPosY;
	int tmpPosX;
	int tmpPosXb;
	auto map = Game::map->getMap();

	switch (jumpStatus) {
		case 1:
			animationStatus = 0;
			if (ysave - ypos >= maxJump * 0.6)
				animationStatus = 1;
			tmpPosX = ((xpos + 25) / 64);
			tmpPosXb = ((xpos + 32) / 64);
			tmpPosY = static_cast<int>(
				(ypos - jumpSpeed * 1.2) / 64 + 0.9);
			if (map->getBlocType(tmpPosY, tmpPosX) ==
			    Map::EMPTY &&
			    map->getBlocType(tmpPosY, tmpPosXb) ==
			    Map::EMPTY) {
				if (ysave - ypos + jumpSpeed < maxJump)
					ypos -= jumpSpeed * 1.2;
				else {
					ypos = ysave - maxJump;
					jumpStatus = -1;
				}
			} else {
				jumpStatus = -1;
			}
			break;
		case 0:
			tmpPosX = ((xpos + 25) / 64);
			tmpPosXb = ((xpos + 32) / 64);
			tmpPosY = static_cast<int>(
				(ypos + jumpSpeed) / 64 + 1.7);
			if (map->getBlocType(tmpPosY, tmpPosX) ==
			    Map::EMPTY &&
			    map->getBlocType(tmpPosY, tmpPosXb) ==
			    Map::EMPTY) {
				ypos += jumpSpeed;
			}
			break;
		default:
			animationStatus = 2;
			if (ysave - ypos >= maxJump * 0.6)
				animationStatus = 1;
			tmpPosX = ((xpos + 25) / 64);
			tmpPosXb = ((xpos + 32) / 64);
			tmpPosY = static_cast<int>(
				(ypos + jumpSpeed) / 64 + 1.7);
			if (map->getBlocType(tmpPosY, tmpPosX) ==
			    Map::EMPTY &&
			    map->getBlocType(tmpPosY, tmpPosXb) ==
			    Map::EMPTY) {
				ypos += (jumpSpeed);
			} else {
				jumpStatus = 0;
			}
			break;

	}
}

void GameObject::moveLeft()
{
	isRight = false;
	double tmpspeed = jumpStatus >= 0 ? speed * 1 : speed * 0.7;
	int tmpPosY = ypos / 64 + 1;
	int tmpPosYb = (ypos + 40) / 64 + 1;
	int tmpPosX = static_cast<int>((xpos - tmpspeed + 25) / 64);
	auto map = Game::map->getMap();

	if (map->getBlocType(tmpPosY, tmpPosX) == Map::EMPTY &&
	    map->getBlocType(tmpPosYb, tmpPosX) == Map::EMPTY) {
		xpos -= tmpspeed;
		if (!isEagle)
			animationStatus++;
		if (direction != -1)
			direction = -1;
	}
}

void GameObject::moveRight()
{
	isRight = true;
	double tmpspeed = jumpStatus >= 0 ? speed * 1 : speed * 0.7;
	int tmpPosY = ypos / 64 + 1;
	int tmpPosYb = (ypos + 40) / 64 + 1;
	int tmpPosX = static_cast<int>((xpos + tmpspeed + 32) / 64);
	auto map = Game::map->getMap();

	if (map->getBlocType(tmpPosY, tmpPosX) == Map::EMPTY &&
	    map->getBlocType(tmpPosYb, tmpPosX) == Map::EMPTY) {
		xpos += tmpspeed;
		if (!isEagle)
			animationStatus++;
		if (direction != 1)
			direction = 1;
	}
}

void GameObject::jump()
{
	int tmpPosY;
	int tmpPosX;
	int tmpPosXb;
	auto map = Game::map->getMap();

	tmpPosX = (xpos / 64);
	tmpPosXb = ((xpos + 64) / 64);
	tmpPosY = static_cast<int>(
		(ypos + jumpSpeed) / 64 + 1.7);
	if ((map->getBlocType(tmpPosY, tmpPosX) !=
	    Map::EMPTY ||
	    map->getBlocType(tmpPosY, tmpPosXb) !=
	    Map::EMPTY) && jumpStatus == 0) {
		ysave = ypos;
		jumpStatus = 1;
	}
}

void GameObject::Render()
{
	if (!isEagle)
	SDL_RenderCopyEx(renderer, objTexture, &srcRect, &destRect, 0,
			 NULL,
			 (direction == LEFT ? SDL_FLIP_HORIZONTAL
					    : SDL_FLIP_NONE));
	else
		SDL_RenderCopyEx(renderer, objTextureEagle, &srcRect, &destRect, 0,
				 NULL,
				 (isRight ? SDL_FLIP_HORIZONTAL
						    : SDL_FLIP_NONE));

}

bool GameObject::IsEagle() const
{
	return isEagle;
}

void GameObject::flyDown()
{
	double tmpspeed = jumpStatus >= 0 ? speed * 1 : speed * 0.7;
	int tmpPosX = xpos / 64 + 1;
	int tmpPosXb = (xpos + 40) / 64 + 1;
	int tmpPosY = static_cast<int>((ypos + tmpspeed + 32) / 64);
	auto map = Game::map->getMap();

	if (map->getBlocType(tmpPosY, tmpPosX) == Map::EMPTY &&
	    map->getBlocType(tmpPosY, tmpPosXb) == Map::EMPTY) {
		ypos += tmpspeed;
		if (direction != 1)
			direction = 1;
	}

}

void GameObject::flyUp()
{
	double tmpspeed = jumpStatus >= 0 ? speed * 1 : speed * 0.7;
	int tmpPosX = xpos / 64 + 1;
	int tmpPosXb = (xpos + 40) / 64 + 1;
	int tmpPosY = static_cast<int>((ypos - tmpspeed + 32) / 64);
	auto map = Game::map->getMap();

	if (map->getBlocType(tmpPosY, tmpPosX) == Map::EMPTY &&
	    map->getBlocType(tmpPosY, tmpPosXb) == Map::EMPTY) {
		ypos -= tmpspeed;
		if (direction != 1)
			direction = 1;
	}
}
