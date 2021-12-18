#include "inputManager.h"

//retourne la position de la souris de la fenêtre reçue en paramètre
Vector2i inputManager::getMousePosition(RenderWindow& window) const
{
	return Mouse::getPosition(window);
}