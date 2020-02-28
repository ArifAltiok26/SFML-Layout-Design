#pragma once
#include "AddableToLayout.hpp"

class CompozitAddedableToLayout : public AddedableToLayout {
public:
	using Element = AddedableToLayout;
	CompozitAddedableToLayout(Element* element)
		: element(element)
	{	}

	virtual sf::Vector2f getPosition()const = 0;
	virtual void setPosition(const sf::Vector2f& position) = 0;
	virtual sf::FloatRect getGlobalBounds()const = 0;

	void draw(sf::RenderTarget& target, sf::RenderStates states)const {
		target.draw(*element, states);
	}
protected:
	Element* element;
};