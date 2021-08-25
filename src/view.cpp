#include "view.h"
#include"Player.h"

void view::initView()
{
	this->dontMove = false;
	this->view1 = sf::View(sf::FloatRect(0.f, 0.f, 1920.f, 600.f));
}

view::view()
{
	this->initView();
}

view::~view()
{
}

float view::ReturningCenter()
{
	return this->view1.getCenter().x;
}

void view::DontMoveSetup(float xPos)
{
	if (xPos >= 9050.f && xPos <= 9100.f)
	{
		this->dontMove = true;
	}

	if (xPos >= 19050.f && xPos <= 20000.f)
	{
		this->dontMove = true;
	}

	if (xPos >= 29260.f && xPos < 29280.f)
	{
		this->dontMove = true;
	}

	
}

void view::moveView(Player& chara)
{
	
	if (chara.character.getPosition().x >( this->view1.getCenter().x)  and sf::Keyboard::isKeyPressed(sf::Keyboard::D) and !this->dontMove)
	{
		
		this->view1.move(15.f, 0.f);
		
	}
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
	{
		this->view1.reset(sf::FloatRect(0.f, 0.f, 1920.f, 600.f));
	}
	
}void view::changeViewForLevel(int level)
{

	this->view1.reset(sf::FloatRect(10000.f * ((float)level - 1.f), 0.f, 1920.f, 600.f));
	this->dontMove = false;
}
