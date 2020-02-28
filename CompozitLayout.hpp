#pragma once
#include "Layout.hpp"

class CompozitLayout : public ILayout {
protected:
	Layout* layout;
	virtual sf::FloatRect getGlobalBounds()const = 0;
	virtual sf::Vector2f getAvailableNextPosition(const Element* element)const = 0;
public:
	CompozitLayout(Layout* layout) : layout(layout) {	}
	virtual sf::Vector2f getPosition() const = 0;
	virtual void setPosition(const sf::Vector2f&) = 0;
	virtual size_t add(Element* element) = 0;
	virtual void remove(size_t id) = 0;
	void draw(sf::RenderTarget& target, sf::RenderStates states)const {
		target.draw(*layout, states);
	}
};