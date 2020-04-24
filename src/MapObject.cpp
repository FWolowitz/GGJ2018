/*
** EPITECH PROJECT, 2018
** MapObject
** File description:
** Implementation of MapObject
*/

#include "MapObject.hpp"
#include "TextureManager.hpp"

MapObject::MapObject(SDL_Renderer *renderer) : renderer(renderer)
{
	grass = TextureManager::LoadTexture("data/grass.png", renderer);
	dirt = TextureManager::LoadTexture("data/dirt.png", renderer);
	cliff = TextureManager::LoadTexture("data/cliff.png", renderer);
	platform = TextureManager::LoadTexture("data/platform.png", renderer);
	sign = TextureManager::LoadTexture("data/sign.png", renderer);
	map = new Map(std::string("level1"));

	src.x = src.y = 0;
	src.w = src.h = 64;
	dest.h = dest.w = 64;
	dest.x = dest.y = 0;
}

MapObject::~MapObject()
= default;

void MapObject::LoadMap(const std::string &s)
{
	map->loadFromFile(s);
}

void MapObject::DrawMap()
{
	auto tmp = map->getMap();
	for (size_t y = 0; y < tmp.size(); y++) {
		for (size_t x = 0; x < tmp[y].size(); x++) {
			Map::BlocType type = map->getBlocType(y, x);

			dest.x = (x * 64);
			dest.y = ((y) * 64) + HEIGHT - tmp.size() * 64;
			switch (type) {
				case Map::GRASS:
					TextureManager::Draw(grass, src, dest,
							     renderer);
					break;
				case Map::DIRT:
					TextureManager::Draw(dirt, src, dest,
							     renderer);
					break;
				case Map::CLIFF:
					TextureManager::Draw(cliff, src, dest,
							     renderer);
					break;
				case Map::PLATFORM:
					TextureManager::Draw(platform, src,
							     dest,
							     renderer);
					break;
				case Map::SIGN:
					TextureManager::Draw(sign, src,
							     dest,
							     renderer);
				default:
					break;
			}
		}
	}
}

Map *MapObject::getMap() const
{
	return map;
}
