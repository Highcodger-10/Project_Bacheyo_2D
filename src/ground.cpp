#include "ground.h"
#include<iostream>

ground::ground(int WorldMap[][1000])
{	
	this->initVariables();
	this->initPosition(WorldMap);
}



void ground::initVariables()
{
	this->GroundImage.loadFromFile("/home/highcodger_10/Desktop/Project_OOP_bachiyo_2D/images/ground & platforms/ground.png");
	this->GroundSprite = new sf::Sprite * [10];

	for (int i = 0;i < 10;i++)
	{
		this->GroundSprite[i] = new sf::Sprite[1000];
	}

}

void ground::initPosition(int WorldMap[][1000])
{
	for (int i = 0;i < 10;i++)
	{
		for (int j = 0; j < 1000;j++)
		{
			if (i == 9)
			{
				if (WorldMap[i][j] == 1)
				{
					this->GroundSprite[i][j].setPosition(60 * (j), 550.f);
					this->GroundSprite[i][j].setTexture(this->GroundImage);
					this->GroundSprite[i][j].setTextureRect(sf::IntRect(84, 0, 120, 90));
					this->GroundSprite[i][j].setScale(0.5, 0.6);

				}


				if (WorldMap[i][j] == 3)
				{

					this->GroundSprite[i][j].setPosition(60 * (j), 550);
					this->GroundSprite[i][j].setTexture(this->GroundImage);
					this->GroundSprite[i][j].setTextureRect(sf::IntRect(84, 80, 120, 90));
					this->GroundSprite[i][j].setScale(0.5, 0.6);
				}
			}
			else
			{
				if (WorldMap[i][j] == 1)
				{

					this->GroundSprite[i][j].setPosition(60 * (j), 500 - 50 * (8 - i));
					this->GroundSprite[i][j].setTexture(this->GroundImage);
					this->GroundSprite[i][j].setTextureRect(sf::IntRect(84, 0, 120, 90));
					this->GroundSprite[i][j].setScale(0.5, 0.6);

				}
				if (WorldMap[i][j] == 3)
				{

					this->GroundSprite[i][j].setPosition(60.f * (j), 500 - 50 * (8 - i));
					this->GroundSprite[i][j].setTexture(this->GroundImage);
					this->GroundSprite[i][j].setTextureRect(sf::IntRect(84, 80, 120, 90));
					this->GroundSprite[i][j].setScale(0.5, 0.6);
				}
				if (WorldMap[i][j] == 12)
				{
				
					this->GroundSprite[i][j].setPosition(60.f * (j), 500 - 50 * (8 - i));
					this->GroundSprite[i][j].setScale(0.5, 0.6);
				}
			}
			

		}
	}
}


ground::~ground()
{
}






