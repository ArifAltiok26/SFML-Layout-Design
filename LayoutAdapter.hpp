#pragma once
#include "AddableToLayout.hpp"

template<typename Adaptee>
class LayoutAdapter : public AddedableToLayout {
	Adaptee& adaptee;
public:
	LayoutAdapter(Adaptee& adaptee)
		: adaptee(adaptee)
	{	}

	sf::Vector2f getPosition()const {
		return adaptee.getPosition();
	}

	void setPosition(const sf::Vector2f& position) {
		adaptee.setPosition(position);
	}

	sf::FloatRect getGlobalBounds()const {
		return adaptee.getGlobalBounds();
	}

	void draw(sf::RenderTarget& target, sf::RenderStates states)const {
		target.draw(adaptee, states);
	}
};
