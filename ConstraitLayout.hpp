#pragma once
#include "CompozitLayout.hpp"
#include <iostream>
template<typename T>
void printVec(const sf::Vector2<T>& vec, std::string endLine = "\n") {
	std::cout << vec.x << "," << vec.y << endLine;
}


template<typename T>
struct RectToVec {
	sf::Vector2<T> upperVector;
	sf::Vector2<T> lowerVector;
	RectToVec(const sf::Rect<T>& rect)
		:
		upperVector(rect.left, rect.top),
		lowerVector(rect.width, rect.height)
	{	}

	void print() {
		printVec(upperVector, " ");
		printVec(lowerVector);
	}
};

class ConstraintLayout : public CompozitLayout {
protected:
	
	sf::Vector2f getAvailableNextPosition(const Element* element)const {
		return layout->getAvailableNextPosition(element);
	}
public:
	sf::Vector2f limits;
	ConstraintLayout(
		Layout* layout,
		sf::FloatRect limits)
		:
		CompozitLayout(layout),
		limits(sf::Vector2f(limits.width, limits.height))
	{
		layout->setPosition(sf::Vector2f(limits.left, limits.top));
	}


	ConstraintLayout(
		Layout* layout,
		sf::Vector2f limits)
		:
		ConstraintLayout(layout, sf::FloatRect(0, 0, limits.x, limits.y))
	{	}

	ConstraintLayout(
		Layout* layout,
		float x,
		float y)
		:
		ConstraintLayout(layout, sf::Vector2f(x, y))
	{	}

	ConstraintLayout(
		Layout* layout,
		float x,
		float y,
		float witdh,
		float height)
		:
		ConstraintLayout(layout, sf::FloatRect(x, y,witdh,height))
	{	}

	void setLimits(sf::Vector2f limits) {
		this->limits = limits;
	}

	sf::Vector2f getPosition() const {
		return layout->getPosition();
	}

	void setPosition(const sf::Vector2f& position) {
		layout->setPosition(position);
	}

	sf::FloatRect getGlobalBounds()const {
		return sf::FloatRect(layout->getPosition(), limits);
	}

	size_t add(Element* element) {
		const Element* last = layout->getLastElement();
		sf::Vector2f position = getAvailableNextPosition(last);
		RectToVec<float> rtv(element->getGlobalBounds());
		std::cout << "rtv ";
		rtv.print();
		sf::FloatRect bounds = getGlobalBounds();
		RectToVec<float> r = bounds;
		printVec(position + rtv.upperVector, " ");
		printVec(position + rtv.lowerVector);
		std::cout << "bounds : "; r.print();
		bool b1 = bounds.contains(position + rtv.upperVector);
		bool b2 = bounds.contains(position + rtv.lowerVector - sf::Vector2f(1,1));
		std::cout << b1 << " " << b2 << std::endl;
		if (b1 == true && b2 == true) {
			element->setPosition(position);
			return layout->add(element);
		}
		else
			return -1;
	}

	void remove(size_t id) {
		layout->remove(id);
	}
};