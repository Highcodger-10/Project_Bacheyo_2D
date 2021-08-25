#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
#include"chains.h"
#include"score.h"
class music;
class Player;
class view;
class gameover
{
public:
	bool gameOver;
	int lifeGone;
	float checkPointsForPlayer;
	float checkPointsForView;
	sf::Texture life;
	sf::Sprite* lifeSprite;


	void initVariables();


public:
	gameover();
	~gameover();
	friend void Updates();
	friend void initRender();
	void changingCheckPoints(int level);
	void moveLife(view&);
	void isGameOver(Player& chara,view& scene,int i, bool* didCollide,music& audio,bool* );

	friend void chains::chainCollide(Player&, gameover&);
	friend void score::ScoreHandling(Player&, enemy&, coins&,FireBall&);
};

