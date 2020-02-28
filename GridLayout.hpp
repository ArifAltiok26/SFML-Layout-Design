#pragma once
#include "ILayout.hpp"
#include <SFML/Graphics.hpp>
template<typename Type>
class GridLayout : public AddedableToLayout
{
	ILayout* layouts;
	sf::Vector2f position;
	sf::Vector2f dimensions;
	size_t size;
public:
	GridLayout(size_t size) : size(size),layouts(0) {
		layouts = new Type[size];
	}

	ILayout& operator[](size_t index) {
		return layouts[index];
	}

	sf::Vector2f getPosition() const{
		return position;
	}

	void setPosition(const sf::Vector2f& position){
		sf::Vector2f diff = this->position - position;
		for (int i = 0; i < size; i++) {
			ILayout& layout = layouts[i];
			layout.setPosition(layout.getPosition() + diff);
		}
		this->position = position;
	}

	sf::FloatRect getGlobalBounds()const {
		return sf::FloatRect(position, sf::Vector2f(0,0));
	}

	void draw(sf::RenderTarget& target, sf::RenderStates states)const {
		for (int i = 0; i < size; i++) {
			target.draw(layouts[i], states);
		}
	}
};

