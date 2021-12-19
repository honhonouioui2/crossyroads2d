#include "gameState.h"

gameState::gameState(gameDataRef data) : _data(data)
{
	_world = nullptr;
	_player = nullptr;
	//_player = new Player(_data);
}

gameState::~gameState() {
}

void gameState::init()
{
	_data->assets.loadTexture("chick left", "Resources/player/chick/left.png");
	_data->assets.loadTexture("chick right", "Resources/player/chick/right.png");
	_data->assets.loadTexture("chick up", "Resources/player/chick/up.png");

	string temp_str = "Resources/segmentexample0.txt";
	string temp_str2 = "Resources/segmentexample1.txt";

	_world = new TileMap(_data);
	_player = new Player(_data);

	_world->init();
	_world->fetchTileMapMetaData(temp_str);
	_world->fetchTileMapMetaData(temp_str);
	_world->fetchTileMapMetaData(temp_str2);

	_player->init();
	_player->setPosition(_world->at(6, 3).sprite.getPosition());

	//carSpawnerEntity player(_data);
	//_playerObject = &player;// .push_back(_player);
	//_playerObject->init();
	//_playerObject->move();
}

void gameState::handleInput()
{
	Event event;
	while (_data->window.pollEvent(event))
	{
		if (event.type == Event::Closed)
			_data->window.close();

		if (event.type == sf::Event::EventType::KeyPressed) {
			if (event.key.code == sf::Keyboard::W) {
				cout << "UP";
				
				int _x = (_player->getPosition().x / TILE_WIDTH);
				int _y = ((SCREEN_HEIGHT - _player->getPosition().y) / TILE_WIDTH) - 1;
				
				//cout << _player->getPosition().x << ", " <<  _player->getPosition().y << endl;
				//cout << "player currently on : " << _x << ", " << _y - 1;
				//Vector2f position = _world->at(0, 0).sprite.getPosition();
				_player->move(_world->at(_x, _y + 1).sprite.getPosition());
			}
			else if (event.key.code == sf::Keyboard::A) {
				cout << "LEFT";
				int _x = (_player->getPosition().x / TILE_WIDTH);
				int _y = ((SCREEN_HEIGHT - _player->getPosition().y) / TILE_WIDTH) - 1;
				//_player->setPosition(_world->at(_x - 1, _y).sprite.getPosition());
				_player->move(_world->at(_x - 1, _y).sprite.getPosition());
			}
			else if (event.key.code == sf::Keyboard::D) {
				cout << "RIGHT";
				int _x = (_player->getPosition().x / TILE_WIDTH);
				int _y = ((SCREEN_HEIGHT - _player->getPosition().y) / TILE_WIDTH) - 1;
				//_player->setPosition(_world->at(_x + 1, _y).sprite.getPosition());
				_player->move(_world->at(_x + 1, _y).sprite.getPosition());
			}
			else if (event.key.code == sf::Keyboard::S) { // not in the final game, for debug
				cout << "DOWN";
				int _x = (_player->getPosition().x / TILE_WIDTH);
				int _y = ((SCREEN_HEIGHT - _player->getPosition().y) / TILE_WIDTH) - 1;
				//_player->setPosition(_world->at(_x, _y - 1).sprite.getPosition());
				_player->move(_world->at(_x, _y - 1).sprite.getPosition());
			}
		}
	}
}

void gameState::update(float dt)
{
	//update entities
	_world->update(dt);
	_player->update(dt);
}


void gameState::draw(float dt) const
{
	_data->window.clear();
	_world->draw(dt);
	_player->draw(dt);
	_world->drawDecor();
	_data->window.display();
}