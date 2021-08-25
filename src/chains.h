#pragma once
#include<SFML/Graphics.hpp>

class Player;
class enemy;
class gameover;
class chains
{

	sf::Texture chainImage;
	sf::Texture hangImage;
	sf::Sprite* hangSprite;
	sf::Sprite* chainSprite;

	int rotationUnit;
	sf::IntRect WheelPart;
	bool chainCollided;
	void initVariables();
	void initPositions(int WorldMap[][1000]);


public:
	
	chains(int WorldMap [][1000]);
	~chains();

	void rotateChains();
	void chainCollide(Player&,  gameover&);
	friend void initRender();
	friend void Updates();
};

