#include "ground.h"
#include<iostream>
#include<cmath>
void Player::initVariables()
{
	this->grounded = true;
	this->positionX = 30;
	this->positionY = 520;
	this->left = false;
	this->right = false;
	this->isJump = false;
	this->jumpCount = 10;
	this->PlayerRecovered = true;
	this->accGravity = 10;
	this->velocity = sf::Vector2f(0, 0);
	this->maxGravity = 40;
	this->dontMovePlayer = false;
	this->AnimatingPart = sf::IntRect(0, 0, 100, 150);
	this->CharacterText.loadFromFile("/home/highcodger_10/Desktop/Project_OOP_bachiyo_2D/images/characters/characters.png");
	this->character.setTexture(this->CharacterText);
	
}

void Player::initPositions()
{
	this->character.setPosition(this->positionX, this->positionY);
	this->character.setScale(0.6f, 0.7f);

}

Player::Player()
{
	this->initVariables();
	this->initPositions();
}

Player::~Player()
{
}

void Player::PlayerUpdates(ground& grd,Player& chara,platform& pl)
{
	this->PlayerMove(grd,chara,pl);
	this->PlayerJump(grd,chara,pl);
	this->Animate();
	this->getState();

}





void Player::PlayerMove(ground& grd,Player& chara, platform& pl)
{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) and !this->dontMovePlayer) //if user presses the key D
	{
		this->right = true;
		this->left = false;
	
		
		this->velocity.x = 15;
		
	
		

	}
	else
	{
		this->velocity.x = 0.f;
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) and !this->dontMovePlayer) //if user presses the key D
	{
		this->right = false;
		this->left = true;
		if (this->character.getPosition().x > 10.f)
		{
			this->velocity.x = -15.f;
		}
		else
		{
			this->velocity.x = 0.f;
		}

	}
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		
		this->velocity.x = 0.f;
		this->right = false;
		this->left = false;
	}

	

	this->character.move(this->velocity.x, 0);
     
	this->collisionHappen(grd,this->velocity.x, 0);
	pl.PlatformCollision(chara,this->velocity.x, 0);

}





void Player::PlayerJump(ground& grd,Player& chara, platform& pl)
{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && this->grounded and !this->dontMovePlayer)
	{
		this->isJump = true;
	}

	if (this->isJump)

		
	{

		this->AnimatingPart.left = 221;
		this->velocity.y = (float)(pow(this->jumpCount, 2) * 0.5 * -1);
		this->jumpCount -= 1;
		if (this->jumpCount < 0)
		{

			this->grounded = false;
			this->jumpCount = 10;
			this->isJump = false;
		}
	}



	if (!this->grounded || this->jumpCount == 10.f)
	{

		this->velocity.y = pow(this->accGravity, 2) * 0.5f;
		this->accGravity += 1;
		if (this->velocity.y > (float)this->maxGravity) { this->velocity.y = (float)this->maxGravity; }

	}
	else
	{
		this->accGravity = 10;
	}
	this->character.move(0, this->velocity.y);
	this->collisionHappen(grd,0, this->velocity.y);
	pl.PlatformCollision(chara, 0, this->velocity.y);

	
}

void Player::ChangePositionForLevel( int* level, bool* changeOrNot,bool* gameEnd)
{

	
	
	
	if (this->character.getPosition().x == 10000.f && *level == 1)
	{
		
		*changeOrNot = true;
		*level += 1;
		this->character.move({ 30,0 });
	
	}

	else if (this->character.getPosition().x >= 20000.f &&
		this->character.getPosition().x < 20010.f
		&& *level == 2)
	{
		*changeOrNot = true;
		*level += 1;
		this->character.move({ 30,0 });
	}

	else if (this->character.getPosition().x >= 29265.f &&
		this->character.getPosition().x < 29280.f &&
		*level == 3
		)
	{
		*changeOrNot = false;
		*gameEnd = true;
	}

	
}




void Player::Animate()
{
	//std::cout << "Player Position: " << this->character.getPosition().x << std::endl;
	if (this->right)
	{
		if (this->AnimatingPart.left >= 720 && !this->isJump)
		{
			this->AnimatingPart.left = 0;
			this->AnimatingPart.top = 0;
		}
		else { this->AnimatingPart.left += 110; }
	}

	if (this->left)
	{
		this->AnimatingPart.top = 150;
		if (this->AnimatingPart.left >= 720 && !this->isJump)
		{
			this->AnimatingPart.left = 0;
			this->AnimatingPart.top = 150;
		}
		else { this->AnimatingPart.left += 107; }

	}

	if (!this->right &&  !this->left)
	{
		this->AnimatingPart.left = 0;
		this->AnimatingPart.top = 0;
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
	{
		this->AnimatingPart.left = 330;
	}
	
	
	this->character.setTextureRect(this->AnimatingPart);
	
}

 void Player::runToEnd(int level)
 {
	
	if (this->character.getPosition().x != 10000.f && level == 1)
	{	
		this->dontMovePlayer = true;
		this->character.move({ 10,0 });
		
	}

	else if (this->character.getPosition().x != 20015.f and level == 2)
	{
		this->dontMovePlayer = true;
		this->character.move({ 10,0 });
	}
	else if (this->character.getPosition().x != 29265.f && level == 3)
	{
		this->dontMovePlayer = true;
		this->character.move({ 10,0 });
	}

	if (this->AnimatingPart.left >= 720)
	{
		this->AnimatingPart.left = 0;
	}
	this->AnimatingPart.left += 110;
	this->character.setTextureRect(this->AnimatingPart);
}

 void Player::characterFallDown(gameover&)
 {
 }



sf::Vector2f Player::getPositioning()
{
	return (this->character.getPosition());

}

int Player::getState()
{
	if (this->right)
	{
		return 0;
	}
	else
		return 1;
}



void Player::collisionHappen(ground& grd, int xvel, int yvel)
{	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0;j < 1000;j++)
		{
			if (this->character.getPosition().x + 20.f < (grd.GroundSprite[i][j].getPosition().x + grd.GroundSprite[i][j].getGlobalBounds().width) &&
				(this->character.getPosition().x + this->character.getGlobalBounds().width - 15.f) > grd.GroundSprite[i][j].getPosition().x &&
				(this->character.getPosition().y) < (grd.GroundSprite[i][j].getPosition().y + grd.GroundSprite[i][j].getGlobalBounds().height) &&
				(this->character.getPosition().y + this->character.getGlobalBounds().height - 30.f) > (grd.GroundSprite[i][j].getPosition().y))
			{
				this->collision = true;

			}
			else
			{
				this->collision = false;
			}
			if (this->collision)
			{
				if (xvel > 0)
				{
					this->character.setPosition(grd.GroundSprite[i][j].getPosition().x - 60.f, this->character.getPosition().y);
					this->velocity.x = 0;


				}

				if (xvel < 0)
				{

					this->character.setPosition(grd.GroundSprite[i][j].getPosition().x + grd.GroundSprite[i][j].getGlobalBounds().width - 15.f, this->character.getPosition().y);
					this->velocity.x = 0;
				}


				if (yvel > 0)
				{
					this->character.setPosition(this->character.getPosition().x, grd.GroundSprite[i][j].getPosition().y - this->character.getGlobalBounds().height + 25.f);
					this->velocity.y = 0;
					this->grounded = true;

				}

				if (yvel < 0) //&& (this->character.getPosition().x + 40.f < (this->GroundSprite[i][j].getPosition().x + this->GroundSprite[i][j].getGlobalBounds().width + 10.f)))
				{
					this->character.setPosition(this->character.getPosition().x, grd.GroundSprite[i][j].getPosition().y + grd.GroundSprite[i][j].getGlobalBounds().height);
					this->velocity.y = 0;
				}

			}

		}
	}

	

	
}
