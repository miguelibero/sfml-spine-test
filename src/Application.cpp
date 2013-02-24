
#include "Application.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>

Application::Application(sf::RenderTarget& target) :
_target(target)
{

}

Application::~Application()
{

}

void Application::draw()
{
	sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    _target.draw(shape);
}

void Application::update(const sf::Time& dt)
{

}