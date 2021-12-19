#pragma once
#include "DEFINITIONS.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "gameObject.hpp"
#include "game.h"

using namespace sf;
using namespace std;

class carSpawnerEntity : public gameObject
{
private:
	gameDataRef _data;
	Vector2i _position;
public:
	carSpawnerEntity(gameDataRef data);
	~carSpawnerEntity();
	void init(); //init de entity
	void update(float delta); //update entity
	void draw(float delta) const; //draw de l'entity apr�s l'update
	//delta:la diff�rence de temps avec le frame rate)
};
