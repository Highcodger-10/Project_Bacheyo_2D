#pragma once
#include<SFML/Graphics.hpp>
#include"text_fonts.h"
class Player;
class enemy;
class coins;
class gameover;
class FireBall;
class score
{
private:
	int Score;
	bool wasEnemyKilled;
	int ScoreMultiply;
	void initScore();

public:
	score();
	~score();
	void operator ++(); //operator overloading for friend function
	friend void text_fonts::changingPosition(view& , score&);

	void ScoreHandling(Player&, enemy&, coins&,FireBall& );


};

