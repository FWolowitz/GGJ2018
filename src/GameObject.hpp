/*
** EPITECH PROJECT, 2018
** GameObject
** File description:
** Declaration of GameObject
*/

#ifndef GGJ18_GAMEOBJECT_HPP
#define GGJ18_GAMEOBJECT_HPP

#include "Game.hpp"

#define LEFT -1
#define RIGHT 1

class GameObject
{
public:
	GameObject(const char *texture, SDL_Renderer *ren, int x, int y, int spritesCount);
	~GameObject();

	virtual void moveRight();
	virtual void moveLeft();
	virtual void jump();
	virtual void processJump();
	virtual void Update();
	virtual void Render();
	bool IsEagle() const;

	void flyUp();

	void flyDown();
	bool isEagle;

protected:
	bool isRight;
	int cnt2;
	float speed;
	float jumpSpeed;
	float maxJump;
	int direction;
	int animationStatus;
	int jumpStatus;
	int ysave;
	int xpos;
	int ypos;
	int spritesCount;
	SDL_Surface *objSurface;
	SDL_Texture *objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer *renderer;

	SDL_Surface *objSurfaceEagle;
	SDL_Texture *objTextureEagle;
};


#endif //GGJ18_GAMEOBJECT_HPP
