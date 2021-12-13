#pragma once
#include <map>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;
class assetManager
{
private:
	map<string, Texture> _textures; //combine le nom de la texture à la Texture sfml
	map<string, Font> _fonts; //combine le nom de la font à la Font sfml
public:
	void loadTexture(string name, string fileName);
	Texture& getTexture(string name); //pas de const pour ce getteur, car setteur aussi
	void loadFont(string name, string fileName);
	Font& getFont(string name); //pas de const pour ce getteur, car setteur aussi
};
/*
//load la texture et la met dans la map
void assetManager::loadFont(string name, string fileName) {
	Font font;
	if (font.loadFromFile(fileName)) {
		_fonts[name] = font;
	}
}

Font& assetManager::getFont(string name) {
	return _fonts.at(name);
}

//load la texture et la met dans la map
void assetManager::loadTexture(string name, string fileName)
{
	Texture tex;
	if (tex.loadFromFile(fileName)) {
		_textures[name] = tex;
	}
}
//retourne la texture de la map correspondant au nom reçu
Texture& assetManager::getTexture(string name)
{
	return _textures.at(name);
}*/