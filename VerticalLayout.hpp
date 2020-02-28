#pragma once
#include "RectangleLayout.hpp"

class VerticalLayout : public RectangleLayout {
protected:
	sf::Vector2f getAvailableNextPosition(const Element* element)const;
public:
	using RectangleLayout::RectangleLayout;
	
};