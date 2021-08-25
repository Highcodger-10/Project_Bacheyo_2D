#pragma once
#include<SFML/Graphics.hpp>
#include"view.h"
class accessories
{

private:
	sf::Texture treeImage;
	sf::Sprite* treeSprite;
	sf::Texture menu;
	sf::Texture riverImage;
	sf::Texture grassImage;

	sf::Sprite* riverSprite;
	sf::Sprite* grassSprite;
	sf::Sprite Menu;

	void initVariables();
	void initPositions(int WorldMap[][1000]);

public:
	accessories(int WorldMap[][1000]);
	~accessories();
	void MenuSetPosition(view&);
	friend void initRender();

	
};

