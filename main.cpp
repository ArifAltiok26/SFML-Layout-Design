#include <iostream>
#include "Window.hpp"
#include "GridLayout.hpp"
#include "ConstraitLayout.hpp"
#include "HorizontalLayout.hpp"
#include "VerticalLayout.hpp"
#include "LayoutAdapter.hpp"
#include "MarginAddedableToLayout.hpp"
#include "PaddingAddedableToLayout.hpp"
using namespace std;


struct GLayout : sf::Drawable{
	ILayout** layouts;
	size_t size;
	GLayout(size_t size) : size(size) {
		layouts = new ILayout*[size];
	}

	ILayout*& operator[](size_t index) {
		return layouts[index];
	}

	void draw(sf::RenderTarget& target, sf::RenderStates states)const {
		for (int i = 0; i < size; i++) {
			target.draw(*layouts[i], states);
		}
	}
};

using LayoutShapeAdapter = LayoutAdapter<sf::Shape>;


int main() {
	
	sf::RenderWindow& window = Window::getInstance()->getWindow();
	window.create(sf::VideoMode(800, 600), "Title");
	sf::Event event;
	ConstraintLayout layout(new VerticalLayout, sf::FloatRect(0, 0, 300, 300));
	sf::RectangleShape shape(sf::Vector2f(100, 100));
	shape.setFillColor(sf::Color::Red);
	
	sf::RectangleShape shape2(sf::Vector2f(100, 100));
	shape2.setFillColor(sf::Color::Yellow);
	layout.add(new MarginAddedableToLayout(new PaddingAddedableToLayout(new LayoutShapeAdapter(shape2),10,20),10,20));
	layout.add(new MarginAddedableToLayout(new PaddingAddedableToLayout(new LayoutShapeAdapter(shape), 10, 50),10,50));
	/*
	GLayout layout(2);
	layout[0] = new HorizontalLayout(0,0);
	layout[1] = new VerticalLayout(200,0);
	

	sf::RectangleShape shape(sf::Vector2f(100, 100));
	shape.setFillColor(sf::Color::Red);
	sf::RectangleShape shape2(sf::Vector2f(100, 100));
	shape2.setFillColor(sf::Color::Blue);
	cout << layout[0]->add(new PaddingAddedableToLayout(new LayoutShapeAdapter(shape2)));
	cout << layout[1]->add(new PaddingAddedableToLayout(new LayoutShapeAdapter(shape)));
	
	sf::CircleShape circle(10);
	circle.setFillColor(sf::Color::Green);
	layout[1]->add(new LayoutShapeAdapter(circle));
	/*sf::RectangleShape shape3(sf::Vector2f(100, 100));
	shape3.setFillColor(sf::Color::Yellow);
	layout.add(new PaddingAddedableToLayout(new LayoutShapeAdapter(shape3),5,5));
	*/
	//layout.setPosition(sf::Vector2f(100, 0));
	/*
	ConstraintLayout layout(new HorizontalLayout,sf::FloatRect(150,0,550,50));
	printVec(layout.limits);
	sf::RectangleShape shape(sf::Vector2f(100, 50));
	shape.setFillColor(sf::Color::Red);
	LayoutAdapter<sf::RectangleShape> adapter(shape);
	layout.add(&adapter);
	//layout.setPosition(sf::Vector2f(400, 0));
	sf::RectangleShape shape2(sf::Vector2f(100, 50));
	shape2.setFillColor(sf::Color::Blue);
	LayoutAdapter<sf::RectangleShape> adapter2(shape2);
	layout.add(&adapter2);
	sf::RectangleShape shape3(sf::Vector2f(300, 50));
	shape3.setFillColor(sf::Color::White);
	LayoutAdapter<sf::RectangleShape> adapter3(shape3);
	RectToVec<float> r = layout.getGlobalBounds();
	r.print();
	
	layout.add(&adapter3);
	*/
	bool first = false;
	sf::Vector2i mouse;
	while (window.isOpen()) {
		while(window.pollEvent(event)){
			switch (event.type)
			{
				case sf::Event::MouseButtonPressed:
					mouse = sf::Mouse::getPosition(window);
					cout << mouse.x << " " << mouse.y << endl;
					break;
				case sf::Event::Closed:
					window.close();
					break;
			}
		}
		window.clear();
		window.draw(layout);
		window.display();
	}
	
	
	system("pause");
	return 0;
}