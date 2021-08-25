#include "FireBall.h"
#include"ground.h"
#include"platform.h"
#include"Player.h"
#include"enemy.h"

void FireBall::initVariables()
{
	this->FireballImage.loadFromFile("/home/highcodger_10/Desktop/Project_OOP_bachiyo_2D/images/ground & platforms/Mario.png");
	this->fireball.setTexture(this->FireballImage);
	this->animationPart = sf::IntRect(0, 0, 16, 33);
	this->fired = false;
	this->fireball.setTextureRect(this->animationPart);
	
}



FireBall::FireBall()
{
	this->initVariables();
	
}

FireBall::~FireBall()
{


}


void FireBall::isFired(Player& chara)
{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
	{
		this->fired = true;
		this->fireball.setPosition(chara.getPositioning().x + 30, chara.getPositioning().y + 40);
		
		
	}
	
	
	if(this->fired)
	{
			
			this->fireball.move({45,0 });
			this->animateFireBall();
	}
	else
	{
		this->fireball.setPosition(3000,3000);
	}

}


void FireBall::FireballUpdates(Player& chara)
{

	this->isFired(chara);

}

void FireBall::animateFireBall()
{
	
	if (this->animationPart.left > 16) this->animationPart.left = 0;
	this->fireball.setTextureRect(this->animationPart);
	this->animationPart.left += 16;
}


void FireBall::CollisionWithEnemyorSurfaces(ground& grd, enemy& enem)
{
	//collision with the anything 
	
	for (int i = 0;i < 1000;i++)
	{
		if (this->fireball.getGlobalBounds().intersects(enem.EnemySprite1[i].getGlobalBounds()) and this->fired)
		{
			enem.EnemySprite1[i].setScale(1.2f, -1.2f);
			enem.DeadOrNot[i] = 1;
			this->fired = false;
		}
		if (this->fireball.getGlobalBounds().intersects(enem.EnemySprite2[i].getGlobalBounds()) and this->fired)
		{
			enem.EnemySprite2[i].setScale(1.2f, -1.2f);
			enem.DeadOrNot[i] = 1;
			this->fired = false;
		}


	}
	for (int i = 0;i < 10; i++)
	{
		for (int j = 0; j < 1000; j++)
		{
			
			if (this->fireball.getGlobalBounds().intersects(grd.GroundSprite[i][j].getGlobalBounds()))
			{
				this->fireball.setTextureRect(sf::IntRect(66, 0, 16, 33));
				this->fired = false;
			}


		}
	}
	

}
