#include "HorizontalLayout.hpp"

sf::Vector2f HorizontalLayout::getAvailableNextPosition(const Element* element)const {
	sf::Vector2f retval;
	if (element) {
		retval = element->getPosition();
		retval.x += element->getGlobalBounds().width;
	}
	else
		retval = getPosition();
	return retval;
}