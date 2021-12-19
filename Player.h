#pragma once
#include "DEFINITIONS.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
//#include <cmath> // lerp a+t*(b-a) pour l'interpolation
#include "gameObject.hpp"
#include "game.h"

using namespace sf;
using namespace std;

class Player : public gameObject
{
private:
	gameDataRef _data;
	pair<Sprite, Sprite> _sprite;
	Clock _clock; // clock utilisé pour l'interpolation de move dans update
	
	int _state;
	Vector2f _goalPosition;
	Vector2f _initialPosition;
	//pair<Vector2f, Vector2f> _movement; // pointeur goalPosition et initialPosition
	//Vector2i _position; // position sur le tilemap, inutile car calculable?
public:
	Player(gameDataRef data);
	void init(); //init de entity
	void update(float delta); //update entity
	void draw(float delta) const; //draw de l'entity après l'update
	//delta:la différence de temps avec le frame rate)

	void move(Vector2f position); // set les propriété et start le clock pour le jump animation et l'interpolation
	//void gameOver(); // set state à 2, flash l'opacité du sprite dans update, pendant 3 secondes

	void setPosition(Vector2f position);
	const Vector2f getPosition() const;
	const int getState() const;


	// getteurs
};
