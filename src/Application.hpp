
#ifndef __APPLICATION_H__
#define __APPLICATION_H__

namespace sf {
	class RenderTarget;
	class Time;
}

namespace spine {
	class Skeleton;
	class Animation;
}

class Application
{
private:
	sf::RenderTarget& _target;
	spine::Skeleton* _skeleton;
	spine::Animation* _animation;

	void loadSkeleton();
	void updateSkeleton(const sf::Time& dt);
public:
	Application(sf::RenderTarget& target);
	~Application();
	void draw();
	void update(const sf::Time& dt);
};

#endif