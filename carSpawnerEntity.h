#pragma once
#include "game.h"
#include "entity.hpp"
class carSpawnerEntity// : public entity
{
private:
	gameDataRef _data;
public:
	carSpawnerEntity(gameDataRef data);
	~carSpawnerEntity();
	void init();
	void update();
	void draw()const;
};

