#pragma once
#include<SFML/Graphics.hpp>
#include"Player.h"
#include"music.h"
#include"score.h"
class coins
{


private:

	sf::Texture coinImage;
	sf::Sprite* coinSprite;
	int coinXimage;



	void initVariables();
	void initPositions(int WorldMap[][1000]);


public:
	coins(int WorldMap[][1000]);
	~coins();
	void coinAnimation();
	friend void initRender();
	friend void  Updates();
	friend void music::playingAudio(Player& chara, FireBall& fire, enemy& enem, coins& coin);
	friend void score::ScoreHandling(Player&, enemy&, coins&, FireBall&);

};

