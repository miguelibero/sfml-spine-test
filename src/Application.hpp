
#ifndef __APPLICATION_H__
#define __APPLICATION_H__

namespace sf {
	class RenderTarget;
	class Time;
}

class Application
{
private:
	sf::RenderTarget& _target;
public:
	Application(sf::RenderTarget& target);
	~Application();
	void draw();
	void update(const sf::Time& dt);
};

#endif