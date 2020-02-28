#pragma once
#include <SFML/Graphics.hpp>

class Window {
	sf::RenderWindow window;
	static Window* instance;
	Window() {	}
public:
	static Window* getInstance() {
		if (instance)
			return instance;
		else
			instance = new Window;
	}

	sf::RenderWindow& getWindow() {
		return window;
	}


};

