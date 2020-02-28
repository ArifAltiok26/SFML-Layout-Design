#pragma once
#include <SFML/Graphics.hpp>

class AddedableToLayout : public sf::Drawable {
public:
	virtual sf::Vector2f getPosition()const = 0;
	virtual void setPosition(const sf::Vector2f& position) = 0;
	virtual sf::FloatRect getGlobalBounds()const = 0;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const = 0;
};

