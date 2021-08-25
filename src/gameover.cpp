#include "gameover.h"
#include"Player.h"
#include"view.h"
#include"music.h"

void gameover::initVariables()
{
	this->gameOver = false;
	this->checkPointsForPlayer = 30.f;
	this->checkPointsForView = 0.f;
	this->lifeSprite = new sf::Sprite[3];
	this->lifeGone = 0;
	this->life.loadFromFile("/home/highcodger_10/Desktop/Project_OOP_bachiyo_2D/images/characters/life.png");
	for (int i = 0; i < 3; i++)
	{
		this->lifeSprite[i].setTexture(this->life);
		this->lifeSprite[i].setScale(0.25f, 0.15f);
	
	}

	
}

gameover::gameover()
{
	this->initVariables();
}

gameover::~gameover()
{
}

void gameover::changingCheckPoints(int level)
{
	if (level == 2)
	{
		this->checkPointsForPlayer = 10030.f;
		this->checkPointsForView = 10000.f;
	}

	else if (level == 3)
	{
		this->checkPointsForPlayer = 20030.f;
		this->checkPointsForView = 20000.f;
	}
}

void gameover::moveLife(view& scene)
{
	for (int i = 0; i < (3 - this->lifeGone); i++)
	{	
		this->lifeSprite[i].setPosition((scene.ReturningCenter()+30.f) - 50 * (i), 0.f);
	}
}

void gameover::isGameOver(Player& chara,view& scene,int i, bool* didCollide,music& audio,bool *Collided)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !this->gameOver)
	{
		audio.gameOverAudio.stop();	
		chara.character.setPosition((float)this->checkPointsForPlayer, (float)chara.positionY);
		scene.view1.reset(sf::FloatRect(this->checkPointsForView, 0.f, 1920.f, 600.f));
		chara.PlayerRecovered = true;
		*Collided = false;
		if (!didCollide[i])
		{
			didCollide[i] = false;
		}
		
		if (this->checkPointsForPlayer == 30.f)
		{
			audio.mainAudio.play();
		}

		else if (this->checkPointsForPlayer == 10030.f)
		{
			audio.level2Audio.play();
		}

		else if (this->checkPointsForPlayer == 20030.f)
		{
			audio.level3Audio.play();
		}
		

	}
	if (this->lifeGone == 1)
	{
		this->lifeSprite[2].setPosition(4000.f, 4000.f);

	}
	else if (this->lifeGone == 2)
	{
		this->lifeSprite[1].setPosition(3000.f, 4000.f);
	}

	else if (this->lifeGone == 3)
	{
		this->lifeSprite[0].setPosition(4000.f, 5000.f);
		this->gameOver = true;
	}

}


