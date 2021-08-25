#include "enemy.h"
#include"Player.h"

void enemy::initVariables()
{
	
	this->EnemyPart = 0;
	this->enemyMoveCount = 10;
	this->DeadOrNot = new int[1000];
	this->DidPlayerCollided = new bool[1000];
	this->CollidedWithEnemy = false;
	this->EnemySprite1 = new sf::Sprite[1000];
	this->EnemySprite2 = new sf::Sprite[1000];
	this->EnemyTexture.loadFromFile("/home/highcodger_10/Desktop/Project_OOP_bachiyo_2D/images/enemies&chains/Enemies.png");

}

void enemy::initPositions(int WorldMap[][1000])
{
	for (int i = 0;i < 10;i++)
	{
		for (int j = 0; j < 1000; j++)
		{
			
			if (WorldMap[i][j] == 7)
			{
					
					this->EnemySprite1[j].setPosition((j+1) * 60, 515 - 50 * (8 - i));
					this->EnemySprite1[j].setTexture(this->EnemyTexture);
					this->EnemySprite1[j].setTextureRect(sf::IntRect(this->EnemyPart, 0, 32, 30));
					this->EnemySprite1[j].setScale((float)1.2, (float)1.2);
				
				
			}

			if (WorldMap[i][j] == 8)
			{
				this->EnemySprite2[j].setPosition((j+1) * 60, 500 - 50 * (8 - i));
				this->EnemySprite2[j].setTexture(this->EnemyTexture);
				this->EnemySprite2[j].setTextureRect(sf::IntRect(this->EnemyPart, 35, 32, 40));
				this->EnemySprite2[j].setScale((float)1.2, (float)1.2);
			}

			
		}
	}
	for (int i = 0;i < 1000;i++)
	{
		this->DeadOrNot[i] = 0;
		this->DidPlayerCollided[i] = false;
	}
}

enemy::enemy(int WorldMap[][1000])
{
	this->initVariables();
	this->initPositions(WorldMap);
}

enemy::~enemy()
{
	
}

void enemy::Enemy_Player(Player& chara,gameover& over, view& scene,music& audio)
{
	for (int i = 0; i < 1000;i++)
	{
	
		
		if ((chara.character.getGlobalBounds().intersects(this->EnemySprite1[i].getGlobalBounds()) && !this->DidPlayerCollided[i] && !this->DeadOrNot[i] ) ||
			(chara.character.getGlobalBounds().intersects(this->EnemySprite2[i].getGlobalBounds())
			 && !this->DidPlayerCollided[i] && !this->DeadOrNot[i])){
			
			over.lifeGone += 1; 
			if (over.lifeGone > 3)
			{
				over.lifeGone = 0;
			}
			this->CollidedWithEnemy = true;
			chara.PlayerRecovered = false;
			chara.character.setPosition(-4000.f, 700.f);
			
		
			
		}
		
	
		if (!chara.PlayerRecovered)
		{
		
			over.isGameOver(chara, scene, i, this->DidPlayerCollided, audio,&this->CollidedWithEnemy);
			
		}
		

		
	}
}

void enemy::EnemyAnimations()
{
	
	
		if (this->EnemyPart >= 32)
		{
			this->EnemyPart = 0;
		}

		else
		{
			this->EnemyPart += 32;
		}

		for (int i = 0;i < 1000;i++)
		{
			if (!this->DeadOrNot[i])
			{
				
				
					this->EnemySprite1[i].setTextureRect(sf::IntRect(this->EnemyPart, 0, 32, 30));
					this->EnemySprite2[i].setTextureRect(sf::IntRect(this->EnemyPart, 35, 32, 40));
				
				



			}

		}

	
	
	

}

	


void enemy::EnemyMove()
{
	
	if (this->enemyMoveCount > 0)
	{
		this->velocityEnemy.x = 8;
		this->enemyMoveCount -= 1;

		for (int i = 0;i < 1000;i++)
		{
			if (!this->DeadOrNot[i])
			{
				this->EnemySprite2[i].setScale(-1.2f, 1.2f);
			}

		}
	}
		
	else 
	{
		for (int i = 0;i < 1000;i++)
		{
			if (!this->DeadOrNot[i])
			{
				this->EnemySprite2[i].setScale(1.2f, 1.2f);
			}

		}
		this->velocityEnemy.x = -8;
		
		if (this->enemyMoveCount == -9)
		{
			this->enemyMoveCount = 10;
		}
		else
		{
			this->enemyMoveCount -= 1;
		}
		
	}
	
	
		
	



	for (int j = 0; j < 1000;j++)
	{
		if (!this->DeadOrNot[j])
		{
			this->EnemySprite1[j].move((int)this->velocityEnemy.x, 0);
			this->EnemySprite2[j].move(this->velocityEnemy.x * 0.5f, 0);

		}
		if (this->DeadOrNot[j])
		{
			this->EnemySprite2[j].setTextureRect(sf::IntRect(64, 35, 32, 40));
			this->EnemySprite1[j].move(0, 25);
			this->EnemySprite2[j].move(0, 25);
		}
	
		
		
	}

}





