#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class inputManager
{
public:
	Vector2i getMousePosition(RenderWindow& window) const;
};