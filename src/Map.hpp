/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#ifndef PROJECT_MAP_HPP
#define PROJECT_MAP_HPP

#include <vector>
#include <map>
#include <fstream>
#include <algorithm>
#include <iostream>
#include <string>

class Map
{
public:
	explicit Map(const std::string &);
	~Map() = default;
	void loadFromFile(const std::string &);
	void dump();
	enum BlocType
	{
		EMPTY,
		CLIFF,
		GRASS,
		PLATFORM,
		SIGN,
		DIRT
	};
	BlocType getBlocType(int, int);
	std::vector<char> operator[](size_t);
	size_t size();
	std::vector<std::vector<char>> getMap() const;
protected:
	std::vector<std::vector<char>> _Map;
	std::map<const char, BlocType> _BlocTypes;
};

#endif //PROJECT_MAP_HPP
