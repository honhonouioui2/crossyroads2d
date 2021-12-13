#include "gameState.h"

gameState::gameState(gameDataRef data) : _data(data)
{
}

gameState::~gameState() {
}

void gameState::init()
{
	
}

void gameState::handleInput()
{
	Event event;
	while (_data->window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			_data->window.close();
	}
}

void gameState::update(float dt)
{
}


void gameState::draw(float dt) const
{
	_data->window.clear();
	_data->window.display();
}