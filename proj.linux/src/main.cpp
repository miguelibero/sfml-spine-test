#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include "Application.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "SFML Spine test");
    sf::Clock clock;
    Application app(window);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        app.update(clock.getElapsedTime());
        app.draw();
        window.display();
    }

    return 0;
}