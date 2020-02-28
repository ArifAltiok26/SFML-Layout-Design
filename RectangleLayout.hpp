#pragma once
#include "Layout.hpp"

class RectangleLayout : public Layout {
protected:
	sf::Vector2f dimensions;
public:
	RectangleLayout(
		sf::Vector2f position, 
		sf::Vector2f dimensions = sf::Vector2f(0,0));

	RectangleLayout(
		float x = 0,
		float y = 0,
		float width = 0,
		float height = 0);

	sf::FloatRect getGlobalBounds()const;

	virtual sf::Vector2f getAvailableNextPosition(const Element* element)const = 0;
	//virtual void calculateNewBound(const sf::FloatRect& rect) = 0;
};

