#pragma once
#include "DEFINITIONS.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <vector>
#include <string>
#include <cassert>
#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include "rapidxml.hpp"
#include "game.h"
//#include "entity.hpp"
#include "carSpawnerEntity.h"

using namespace std;
using namespace rapidxml;
using namespace sf;

struct TileData {
	bool collision;
	string textureName, decorTextureName;
	string type;
	int id;
	Sprite sprite, decorSprite;
	entity *tileEntity=nullptr;
};

class TileMap {
private:
	gameDataRef _data;
	TileData _xmlData[N_TILE_TYPES];
	vector<vector<pair<TileData, TileData>>> _imageBuffer;
	vector<pair<int, int>> _decorSpritesBuffer; // vector or stack/queue: need only top
public:
	//https://stackoverflow.com/questions/9659234/drawing-a-tile-map-with-sfml
	TileMap(gameDataRef data);
	~TileMap();

	void fetchTileMapMetaData(string filePath);
	void parseXMLData();
	void init(); // load XML tile data into an array, load sprites & set texture
	
	void draw(); // draw in view cells (TileData pair)
	void drawDecor(); // draw in view decor sprites 

	//const TileData& at(int position) const; // read-only data
	const vector<vector<pair<TileData, TileData>>> getImageBuffer() const;
};
