#pragma once
#include<SFML/Graphics.hpp>
class background
{
private:
	sf::Texture BackgroundImage1;
	sf::Texture BackgroundImage2;
	sf::Texture BackgroundImage3;
	sf::Sprite* Background;

	void initVariables();
	void initPositions();
	
public:
	background();
	~background();
	
	void switchBackgroundForLevelChange(int);

	//a friend function to use its private members
	friend void initRender();
	
};

