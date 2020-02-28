#include "RectangleLayout.hpp"

RectangleLayout::RectangleLayout(
	sf::Vector2f position,
	sf::Vector2f dimensions)
	: Layout(position), dimensions(dimensions)
{	}

RectangleLayout::RectangleLayout(
	float x, float y,
	float width, float height)
	:
	RectangleLayout(
		sf::Vector2f(x, y),
		sf::Vector2f(width, height))
{	}

sf::FloatRect RectangleLayout::getGlobalBounds()const {
	return sf::FloatRect(getPosition(), dimensions);
}

