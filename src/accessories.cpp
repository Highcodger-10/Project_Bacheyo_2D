#include "accessories.h"

void accessories::initVariables()
{
	this->riverImage.loadFromFile("/home/highcodger_10/Desktop/Project_OOP_bachiyo_2D/images/ground & platforms/river.png");
	this->treeImage.loadFromFile("/home/highcodger_10/Desktop/Project_OOP_bachiyo_2D/images/ground & platforms/trees.png");
	this->grassImage.loadFromFile("/home/highcodger_10/Desktop/Project_OOP_bachiyo_2D/images/ground & platforms/grass.png");
	this->menu.loadFromFile("/home/highcodger_10/Desktop/Project_OOP_bachiyo_2D/images/backgrounds/png/game_background_1/image0.jpg");
	this->treeSprite = new sf::Sprite[1000];
	this->grassSprite = new sf::Sprite[1000];
	this->riverSprite = new sf::Sprite[1000];
	this->Menu.setTexture(this->menu);
	this->Menu.setScale(1.3f, 0.8f);
}

void accessories::initPositions(int WorldMap[][1000])
{
	for (int i = 0;i < 10;i++)
	{
		for (int j = 0; j < 1000;j++)
		{
			if (WorldMap[i][j] == 5)
			{

				this->treeSprite[j].setPosition((float)(60 * (j)), (float)(500 - 100 * (8 - i)));
				this->treeSprite[j].setTexture(this->treeImage);
				this->treeSprite[j].setTextureRect(sf::IntRect(0, 0, 500, 230));
				this->treeSprite[j].setScale(0.7f, 0.8f);
			}
			if (WorldMap[i][j] == 9)
			{
				this->grassSprite[j].setPosition((float)j * 60,(float)( 520 - 50 * (8 - i)));
				this->grassSprite[j].setTexture(this->grassImage);

			}

			if (WorldMap[i][j] == 4)
			{
				this->riverSprite[j].setPosition((float)j * 60.f, (570.f));
				this->riverSprite[j].setTexture(this->riverImage);
				this->riverSprite[j].setScale(0.65f, 0.6f);
			}
		}
	}
}

accessories::accessories(int WorldMap[][1000])
{
	this->initVariables();
	this->initPositions(WorldMap);
}

accessories::~accessories()
{
}

void accessories::MenuSetPosition(view& scene)
{
	this->Menu.setPosition(scene.ReturningCenter() - 550.f, 70.f);

}
