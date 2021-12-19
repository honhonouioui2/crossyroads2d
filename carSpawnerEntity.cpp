#include "carSpawnerEntity.h"
carSpawnerEntity::carSpawnerEntity(gameDataRef data) : _data(data)
{
}

carSpawnerEntity::~carSpawnerEntity() {
}

void carSpawnerEntity::init()
{
	cout << "Car spawner initialized";
}

void carSpawnerEntity::update(float delta)
{
	cout << "Car spawner update";
}

void carSpawnerEntity::draw(float delta) const
{
	cout << "Car spawner draw";
}

