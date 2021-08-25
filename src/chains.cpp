#include "chains.h"
#include"Player.h"
#include"gameover.h"
#include"enemy.h"

void chains::initVariables()
{
		this->chainImage.loadFromFile("/home/highcodger_10/Desktop/Project_OOP_bachiyo_2D/images/ground & platforms/chainWheel.png");
	this->rotationUnit = 30;
	this->WheelPart = sf::IntRect(0, 0, 400, 280);
	this->chainCollided = false;
	this->chainSprite = new sf::Sprite[1000];
}

void chains::initPositions(int WorldMap[][1000])
{
	for (int i = 0; i < 10;i++)
	{
		for (int j = 0; j < 1000; j++)
		{
			if (WorldMap[i][j] == 10)
			{
				this->chainSprite[j].setPosition(j * 62, 500 - 50 * (8 - i));
				this->chainSprite[j].setTexture(this->chainImage);
				this->chainSprite[j].setTextureRect(this->WheelPart);
				this->chainSprite[j].setOrigin(115.5, 113);
				this->chainSprite[j].setScale(0.3f, 0.3f);
			}
		}
	}
}

chains::chains(int WorldMap[][1000])
{
	this->initVariables();
	this->initPositions(WorldMap);
}

chains::~chains()
{
}

void chains::rotateChains()
{
	for (int i = 0;i < 1000; i++)
	{
		this->chainSprite[i].rotate(this->rotationUnit);
	}
	
}

void chains::chainCollide(Player& chara,  gameover& over)
{
	for (int i = 0; i < 1000; i++)
	{
		if (chara.character.getGlobalBounds().intersects(this->chainSprite[i].getGlobalBounds()))
		{
			this->chainCollided = true;
			over.lifeGone += 1;
			chara.PlayerRecovered = false;
			chara.character.setPosition(-4000.f, 700.f);
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		{
			this->chainCollided = false;
		}
	}
	
}
