#include "assetManager.h"

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
}