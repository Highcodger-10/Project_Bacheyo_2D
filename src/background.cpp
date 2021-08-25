#include "background.h"


background::background()
{
	
	this->initVariables();
	this->initPositions();
}
void background::initVariables()
{
	this->BackgroundImage3.loadFromFile("/home/highcodger_10/Desktop/Project_OOP_bachiyo_2D/images/backgrounds/png/game_background_1/game_background_1.png");
	this->BackgroundImage2.loadFromFile("/home/highcodger_10/Desktop/Project_OOP_bachiyo_2D/images/backgrounds/png/game_background_1/game_background_4.png");
	this->BackgroundImage1.loadFromFile("/home/highcodger_10/Desktop/Project_OOP_bachiyo_2D/images/backgrounds/png/game_background_1/game_background_2.png");
	this->Background = new sf::Sprite[50];
	for (int i = 0; i < 50; i++)
	{
		this->Background[i].setTexture(this->BackgroundImage1);
	}
}

void background::initPositions()
{
	for (int i = 0;i < 50;i++)
	{
		this->Background[i].setPosition(i * 1920, -300);
	}
}



void background::switchBackgroundForLevelChange(int level)
{
	if (level == 2)
	{
		for (int i = 0;i < 50; i++)
		{
			this->Background[i].setTexture(this->BackgroundImage2);
		}
	}
	else if (level == 3)
	{
		for (int i = 0; i < 50; i++)
		{
			this->Background[i].setTexture(this->BackgroundImage3);
		}
	}

}


background::~background() {};
