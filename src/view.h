#pragma once
#include<SFML/Graphics.hpp>
#include"gameover.h"
#include"text_fonts.h"
#include"level_handling.h"
class Player;
class view
{
private:
	sf::View view1;

	bool dontMove;
	void initView();

public:
	view();
	~view();
	float ReturningCenter();
	void DontMoveSetup(float xPos);
	void moveView(Player& chara);
	void changeViewForLevel(int level);
	friend int main();
	friend void level_handling::ChangingLevel(Player&, music&, view&,background&,gameover&);
	friend void text_fonts::changingPosition(view&,score&);
	friend void gameover::moveLife(view&);
	friend void gameover::isGameOver(Player& chara, view& scene,int i, bool* didCollide,music& audio,bool*);
	friend void Updates();
};

