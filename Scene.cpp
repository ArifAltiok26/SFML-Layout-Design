#include "Scene.hpp"
#include "Layout.hpp"
Scene::Scene(ILayout* layout)
	: layout(layout)
{	}


void Scene::draw(sf::RenderTarget& target, sf::RenderStates states)const {
	target.draw(*layout, states);
}