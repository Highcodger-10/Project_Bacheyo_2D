#include "text_fonts.h"
#include"view.h"
#include"score.h"

void text_fonts::initVariables()
{
	this->defaultFont.loadFromFile("/home/highcodger_10/Desktop/Project_OOP_bachiyo_2D/fonts/menu_font.ttf");

	this->scores.setFont(this->defaultFont);
	this->over_Score.setFont(this->defaultFont);
	this->resetText.setFont(this->defaultFont);
	
	this->resetText.setString("Press Enter to continue from last check Point");
	this->resetText.setCharacterSize(30);

	this->over_Score.setCharacterSize(30);





}

text_fonts::text_fonts()
{
	this->initVariables();
}


/*
void text_fonts::FileHandle(int* HighScores)
{
	this->file.open("score.dat");

	try
	{
		this->file.read(reinterpret_cast<char*>(HighScores), sizeof(*HighScores));

		if (*HighScores == NULL)
		{
			throw;
		}
		
	}

	catch (...)
	{
		*HighScores = 0;
	}
	

	
	




}
*/
void text_fonts::changingPosition(view& scene, score& marks)
{	
	this->resetText.setPosition(scene.ReturningCenter() - 340.f, 300.f);
	this->over_Score.setPosition(scene.ReturningCenter() - 260.f, 300.f);
	this->scores.setPosition(scene.ReturningCenter() - 960.f, 0);
	this->scores.setString("score " + std::to_string(marks.Score));
	this->over_Score.setString("Game over. Your Score is " + std::to_string(marks.Score));



} 
