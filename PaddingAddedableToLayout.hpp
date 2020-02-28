#pragma once
#include "SpacedAddedableToLayout.hpp"
class PaddingAddedableToLayout : public SpacedAddedableToLayout
{
public:
	using SpacedAddedableToLayout::SpacedAddedableToLayout;

	sf::Vector2f getPosition()const;
	void setPosition(const sf::Vector2f& position);
	sf::FloatRect getGlobalBounds()const;
};
