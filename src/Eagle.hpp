/*
** EPITECH PROJECT, 2018
** Eagle
** File description:
** Declaration of Eagle
*/

#ifndef GGJ18_EAGLE_HPP
#define GGJ18_EAGLE_HPP


#include "GameObject.hpp"

class Eagle : public GameObject
{
public:
	Eagle(const char *texture, SDL_Renderer *ren, int x, int y,
	      int spritesCount);
	void Update() override;
	void Render() override;
	void Die();
	bool isDead();
private:
	int cnt;
	bool Dead;
};


#endif //GGJ18_EAGLE_HPP
