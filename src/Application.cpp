
#include "Application.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System/Time.hpp>

#include <spine-sfml/spine.h>

#include <fstream>
#include <iostream>

#define RESOURCE_PATH(__RES__) "../res/" __RES__

Application::Application(sf::RenderTarget& target) :
_target(target), _skeleton(nullptr), _animation(nullptr)
{
	loadSkeleton();
}

Application::~Application()
{
	if(_skeleton)
	{
		delete _skeleton;
	}
	if(_animation)
	{
		delete _animation;
	}
}

void Application::loadSkeleton()
{
	std::cout << "loading: " << RESOURCE_PATH("spineboy.atlas") << std::endl;
	std::ifstream atlasFile(RESOURCE_PATH("spineboy.atlas"));
	spine::Atlas *atlas = new spine::Atlas(atlasFile);
	spine::SkeletonJson skeletonJson(atlas);

	std::ifstream skeletonFile(RESOURCE_PATH("spineboy-skeleton.json"));
	spine::SkeletonData *skeletonData = skeletonJson.readSkeletonData(skeletonFile);

	std::ifstream animationFile(RESOURCE_PATH("spineboy-walk.json"));
	_animation = skeletonJson.readAnimation(animationFile, skeletonData);

	_skeleton = new spine::Skeleton(skeletonData);
	_skeleton->flipX = false;
	_skeleton->flipY = false;
	_skeleton->setToBindPose();
	_skeleton->getRootBone()->x = 200;
	_skeleton->getRootBone()->y = 420;
}

void Application::updateSkeleton(const sf::Time& dt)
{
	_animation->apply(_skeleton, dt.asSeconds(), true);
	_skeleton->updateWorldTransform();
}

void Application::draw()
{
	_target.draw(*_skeleton);
}

void Application::update(const sf::Time& dt)
{
	try{
		updateSkeleton(dt);
	} catch (std::exception &ex)
	{
		std::cout << ex.what() << std::endl << std::flush;
	}
}