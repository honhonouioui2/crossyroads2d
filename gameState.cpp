#include "gameState.h"

gameState::gameState(gameDataRef data) : _data(data)
{
	_world = new TileMap(_data);
}

gameState::~gameState() {
}

void gameState::init()
{
	string temp_str = "Resources/segmentexample0.txt";
	string temp_str2 = "Resources/segmentexample1.txt";
	_world->init();
	_world->fetchTileMapMetaData(temp_str);
	_world->fetchTileMapMetaData(temp_str);
	_world->fetchTileMapMetaData(temp_str);
	_world->fetchTileMapMetaData(temp_str);
	_world->fetchTileMapMetaData(temp_str);
	_world->fetchTileMapMetaData(temp_str);
	_world->fetchTileMapMetaData(temp_str);
	_world->fetchTileMapMetaData(temp_str);
	_world->fetchTileMapMetaData(temp_str);
	_world->fetchTileMapMetaData(temp_str);
	_world->fetchTileMapMetaData(temp_str);
	_world->fetchTileMapMetaData(temp_str);
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
	_world->draw();
	_world->drawDecor();
	_data->window.display();
}