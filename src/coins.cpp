#include "coins.h"


void coins::initVariables()
{
	this->coinImage.loadFromFile("/home/highcodger_10/Desktop/Project_OOP_bachiyo_2D/images/ground & platforms/coin.png");
	this->coinSprite = new sf::Sprite[1000];
	this->coinXimage = 0;
}

void coins::initPositions(int WorldMap[][1000])
{
	for (int i = 0;i < 1000;i++)
	{
		this->coinSprite[i].setTexture(this->coinImage);
	}

	for (int i = 0; i < 10;i++)
	{
		for (int j = 0; j < 1000;j++)
		{
			if (WorldMap[i][j] == 6)
			{
			
				
					this->coinSprite[j].setPosition(j * 60, (i) * 63);
				
			}

		}
	}


}

coins::coins(int WorldMap[][1000])
{
	this->initVariables();
	this->initPositions(WorldMap);
}

coins::~coins()
{
}

void coins::coinAnimation()
{

	for (int i = 0;i < 1000;i++)
	{
		this->coinSprite[i].setTextureRect(sf::IntRect(this->coinXimage, 0, 30, 50));
	}
	this->coinXimage += 31;
	if (this->coinXimage >= 70)
	{
		this->coinXimage = 0;
	}
}




