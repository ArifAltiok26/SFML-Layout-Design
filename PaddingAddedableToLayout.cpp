#include "PaddingAddedableToLayout.hpp"

sf::Vector2f PaddingAddedableToLayout::getPosition()const {
	return element->getPosition() + leftTop;
}

void PaddingAddedableToLayout::setPosition(const sf::Vector2f& position) {
	element->setPosition(position - leftTop);
}

sf::FloatRect PaddingAddedableToLayout::getGlobalBounds()const {
	sf::FloatRect bounds = element->getGlobalBounds();
	sf::Vector2f boundsLeftTop(bounds.left, bounds.top);
	sf::Vector2f boundsRightBottom(bounds.width, bounds.height);
	boundsLeftTop += leftTop;
	boundsRightBottom -= rightBottom;
	return sf::FloatRect(boundsLeftTop, boundsRightBottom);
}
