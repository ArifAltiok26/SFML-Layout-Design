#pragma once
#include "AddableToLayout.hpp"

class ILayout : public AddedableToLayout {
public:
	using Element = AddedableToLayout;
	virtual sf::Vector2f getPosition() const = 0;
	virtual void setPosition(const sf::Vector2f&) = 0;
	virtual size_t add(Element* element) = 0;
	virtual void remove(size_t id) = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const = 0;
protected:
	virtual sf::FloatRect getGlobalBounds()const = 0;
	virtual sf::Vector2f getAvailableNextPosition(const Element* element)const = 0;
};
