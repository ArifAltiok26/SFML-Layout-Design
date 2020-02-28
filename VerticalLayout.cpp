#include "VerticalLayout.hpp"

sf::Vector2f VerticalLayout::getAvailableNextPosition(const Element* element)const {
	sf::Vector2f retval;
	if (element) {
		retval = element->getPosition();
		retval.y += element->getGlobalBounds().height;
	}
	else
		retval = getPosition();
	return retval;
}
