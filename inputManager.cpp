#include "inputManager.h"

//retourne la position de la souris de la fen�tre re�ue en param�tre
Vector2i inputManager::getMousePosition(RenderWindow& window) const
{
	return Mouse::getPosition(window);
}