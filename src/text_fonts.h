#pragma once
#include<SFML/Graphics.hpp>
#include<fstream>
#include<iostream>
#include<iomanip>
#include<cstring>

class score;
class view;
class text_fonts
{
private:
	sf::Text resetText;
	sf::Text PressToEnter;
	sf::Text scores;
	sf::Text HighScore;
	sf::Text over_Score;
	sf::Font defaultFont;
	bool reset;
	bool pressToEnter;


	std::fstream file;




	void initVariables();


public:
	text_fonts();
	//~text_fonts();
	//void FileHandle(int* HighScore);
	void changingPosition(view&,score&);
	friend void initRender();
	friend void Updates();
	
};

