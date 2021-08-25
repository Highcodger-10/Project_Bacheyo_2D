#include "score.h"
#include"Player.h"
#include"enemy.h"
#include"gameover.h"
#include"FireBall.h"
#include"coins.h"
void score::initScore()
{
	this->Score = 0;
	this->wasEnemyKilled = false;

}

score::score()
{
	this->initScore();
}

score::~score()
{
}

void score::operator++()
{
	
	
	this->Score += ( 1 * this->ScoreMultiply);
	
	

}



void score::ScoreHandling(Player& chara, enemy& enem, coins& sikka,  FireBall& fire)
{
	for (int i = 0; i < 1000; i++)
	{
		if (chara.character.getGlobalBounds().intersects(sikka.coinSprite[i].getGlobalBounds()))
		{
			this->ScoreMultiply = 1;
			this->Score++;
			
		}

		

		if (fire.fireball.getGlobalBounds().intersects(enem.EnemySprite1[i].getGlobalBounds()) ||
			fire.fireball.getGlobalBounds().intersects(enem.EnemySprite2[i].getGlobalBounds())
			)
		{
			this->ScoreMultiply = 10;
			this->Score++;

		}
		else
		{
			this->wasEnemyKilled = false;
		}
	}


	

}
