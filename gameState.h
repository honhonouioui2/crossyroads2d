#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITIONS.hpp"
#include "TileMap.h"
#include "game.h"
#include "state.hpp"
#include "Player.h"

using namespace sf;
using namespace std;

class gameState : public state
{
private:

	gameDataRef _data;
	
	TileMap* _world;
	Player* _player;

	Clock _clock;
public:
	gameState(gameDataRef data);
	~gameState();
	void init();
	void handleInput();
	void update(float dt);
	void draw(float dt) const;
};