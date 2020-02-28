#pragma once
#include "SpacedAddedableToLayout.hpp"
class MarginAddedableToLayout : public SpacedAddedableToLayout
{
	public:
	//  using SpacedAddedableToLayout::SpacedAddedableToLayout;
		MarginAddedableToLayout(Element* element, float x = 0, float y = 0, float width = 0, float height = 0) 
			: SpacedAddedableToLayout(element,x,y,width,height)
		{
			element->setPosition(element->getPosition() + leftTop);
		}
		sf::Vector2f getPosition()const;
		void setPosition(const sf::Vector2f& position);
		sf::FloatRect getGlobalBounds()const;
};

