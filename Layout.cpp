#include "Layout.hpp"


Layout::Layout(sf::Vector2f position)
	: position(position)
{	}

Layout::Layout(float x, float y)
	: Layout(sf::Vector2f(x, y))
{	}

size_t Layout::add(Element* element) {
	sf::Vector2f position = getAvailableNextPosition(getLastElement());
	element->setPosition(position);
	elements.push_back(element);
	return elements.size() - 1;
}

void Layout::remove(size_t index) {
	elements.erase(elements.begin() + index);
}

sf::Vector2f Layout::getPosition()const {
	return position;
}

void Layout::setPosition(const sf::Vector2f& position) {
	sf::Vector2f diff = position - this->position;
	this->position = position;
	for (Element* element : elements) 
		element->setPosition(element->getPosition() + diff);
}

const Layout::Element* Layout::getLastElement()const {
	return elements.empty() ? NULL : elements.back();
}

void Layout::draw(sf::RenderTarget& target, sf::RenderStates states) const {
	for (Element* element : elements) {
		target.draw(*element, states);
	}
}
