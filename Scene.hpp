#pragma once
#include <SFML/Graphics.hpp>
class ILayout;

class Scene : public sf::Drawable {
protected:
	ILayout* layout;
public:
	Scene(ILayout* layout);
	virtual void start() = 0;
	virtual void update() = 0;
	void draw(sf::RenderTarget& target, sf::RenderStates states)const;
};



/*
// Ornek

class SomeGame : public Scene {
	sf::RectangleShape* shape;
public:
	SomeGame() : Scene(new VerticalLayout) {}
	void start() {
		shape = new sf::RectangleShape(sf::Vector2f(200, 100));
		shape->setFillColor(sf::Color::Red);
		layout->add(new LayoutAdapter<sf::RectangleShape>(*shape));
	}

	void update() {
		shape->move(sf::Vector2f(1, 0));
	}
};
*/
