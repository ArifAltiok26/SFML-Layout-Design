#pragma once
#pragma once
#include "ILayout.hpp"
#include <vector>

class Layout : public ILayout {
protected:
	sf::Vector2f position;
	using Elements = std::vector<Element*>;
	using Iterator = Elements::iterator;
	Elements elements;
public:

	Layout(sf::Vector2f position);
	Layout(float x = 0, float y = 0);

	size_t add(Element* element);
	void remove(size_t index);

	sf::Vector2f getPosition()const;
	void setPosition(const sf::Vector2f& position);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	
	const Element* getLastElement()const;
	virtual sf::FloatRect getGlobalBounds() const = 0;
	
	virtual sf::Vector2f getAvailableNextPosition(const Element* element) const = 0;
};




/*
int main() {

	HorizontalLayout layout(sf::Vector2f(100, 200));
	sf::RectangleShape* shape = new sf::RectangleShape(sf::Vector2f(100, 100));
	shape->setFillColor(sf::Color::Green);
	sf::CircleShape shape2(50);
	shape2.setFillColor(sf::Color::Blue);
	AddedableToLayoutShapeAdapter adapter(shape);// shape sýnýfý layouta eklenecek þekilde adapte eder -> adapter nesne, shape pointerdir.
	AddedableToLayoutShapeAdapter * adapter2 = new AddedableToLayoutShapeAdapter(&shape2); //adapter pointer, shape nesnedir
	layout.add(&adapter); //nesne olarak ekleme
	layout.add(adapter2); // pointer olarak ekleme
	sf::RenderWindow window(sf::VideoMode(800, 600), "Title");
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
			default:
				break;
			}
		}
		window.clear();
		window.draw(layout);
		window.display();
	}


	return 0;
}
*/

