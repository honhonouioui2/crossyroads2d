#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class inputManager
{
public:
	bool isSpriteClicked(const Sprite& object, Mouse::Button button, RenderWindow& window);
	Vector2i getMousePosition(RenderWindow& window) const;
};
/*
//vérifie si on a cliqué sur le sprite de la fenêtre reçus en paramètre
bool inputManager::isSpriteClicked(const Sprite& object, Mouse::Button button, RenderWindow& window)
{
	if (Mouse::isButtonPressed(button))
	{
		IntRect tempRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);
		if (tempRect.contains(Mouse::getPosition(window)))
		{
			return true;
		}
	}
	return false;
}

//retourne la position de la souris de la fenêtre reçue en paramètre
Vector2i inputManager::getMousePosition(RenderWindow& window) const
{
	return Mouse::getPosition(window);
}*/