#include "MarginAddedableToLayout.hpp"

sf::Vector2f MarginAddedableToLayout::getPosition()const {
	return element->getPosition() - leftTop;
}

void MarginAddedableToLayout::setPosition(const sf::Vector2f& position) {
	element->setPosition(position + leftTop);
}

sf::FloatRect MarginAddedableToLayout::getGlobalBounds()const {
	sf::FloatRect bounds = element->getGlobalBounds();
	sf::Vector2f boundsLeftTop(bounds.left, bounds.top);
	sf::Vector2f boundsRightBottom(bounds.width, bounds.height);
	boundsLeftTop -= leftTop;
	boundsRightBottom += rightBottom + leftTop;
	return sf::FloatRect(boundsLeftTop, boundsRightBottom);
}