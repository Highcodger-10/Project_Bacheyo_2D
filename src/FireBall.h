#pragma once
#include<SFML/Graphics.hpp>
#include"music.h"
#include"score.h"

class ground;
class platform;			
class Player;
class enemy;
class FireBall
{
private:
	//variables
	int positionX, positionY;
	bool fired;
	bool CollidedAnything;
	int finalX, finalY;
	sf::Vector2f velocityFire;
	sf::IntRect animationPart;
	//textures and sprites

	sf::Texture FireballImage;
	sf::Sprite fireball;

	//privates functions
	void initVariables();
	


public:
	FireBall();
	 ~FireBall();
	void isFired(Player& chara);
	friend void initRender();
	friend void Updates();
	friend void music::playingAudio(Player& chara, FireBall& fire, enemy& enem, coins& coin);
	void FireballUpdates(Player& chara);
	friend void score::ScoreHandling(Player&, enemy&, coins&, FireBall&);
	void animateFireBall();
	void CollisionWithEnemyorSurfaces(ground& grd, enemy& enem);
};

