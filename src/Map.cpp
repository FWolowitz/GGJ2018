/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#include "Map.hpp"

Map::Map(const std::string &filePath)
{
	//Associate chars to blocTypes
	_BlocTypes['G'] = GRASS;
	_BlocTypes['C'] = CLIFF;
	_BlocTypes['P'] = PLATFORM;
	_BlocTypes['D'] = DIRT;
	_BlocTypes['S'] = SIGN;
	_BlocTypes['.'] = EMPTY;

	loadFromFile(filePath);
}

void Map::loadFromFile(const std::string &filePath)
{
	std::ifstream file;
	std::vector<char> vline;
	std::string line;

	file.open(filePath + ".map");
	if (file.is_open()) {
		_Map.clear();
		while (getline(file, line)) {
			vline.clear();
			std::copy(line.begin(), line.end(),
				  std::back_inserter(vline));
			_Map.push_back(vline);
		}
	}
	file.close();
}

Map::BlocType Map::getBlocType(int y, int x)
{
	return _BlocTypes[_Map[y][x]];
}

void Map::dump()
{
	for (size_t y = 0; y < _Map.size(); y++){
		for (size_t x = 0; x < _Map[y].size(); x++) {
			std::cout << getBlocType(y, x);
		}
		std::cout << std::endl;
	}
}

std::vector<char> Map::operator[](size_t y)
{
	return (_Map[y]);
}

std::vector<std::vector<char>> Map::getMap() const
{
	return _Map;
}

size_t Map::size()
{
	return (_Map.size());
}