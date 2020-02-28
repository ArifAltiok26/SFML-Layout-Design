#pragma once
#include "CompozitAddedableToLayout.hpp"
class SpacedAddedableToLayout : public CompozitAddedableToLayout{
protected:
	sf::Vector2f leftTop;
	sf::Vector2f rightBottom;
public:
	SpacedAddedableToLayout(
		Element* element,
		sf::Vector2f leftTop,
		sf::Vector2f rightBottom
	)
		:
		CompozitAddedableToLayout(element),
		leftTop(leftTop),
		rightBottom(rightBottom)
	{
		
	}

	SpacedAddedableToLayout(
		Element* element,
		float left = 0,
		float top = 0,
		float right = 0,
		float bottom = 0
	)
		:
		SpacedAddedableToLayout(element, sf::Vector2f(left, top), sf::Vector2f(right, bottom))
	{	}

	virtual sf::Vector2f getPosition()const = 0;
	virtual void setPosition(const sf::Vector2f& position) = 0;
	virtual sf::FloatRect getGlobalBounds()const = 0;
};
