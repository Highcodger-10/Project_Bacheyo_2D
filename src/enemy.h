#pragma once
#include<SFML/Graphics.hpp>

#include"FireBall.h"
#include"music.h"
#include"gameover.h"
#include"chains.h"
#include"score.h"
class Player;
class ground;
class enemy
{

private:
	sf::Texture EnemyTexture;
	sf::Sprite* EnemySprite1;
	sf::Sprite* EnemySprite2;
	sf::Clock clock;
	int* DeadOrNot;
	bool* DidPlayerCollided;
	sf::Vector2i velocityEnemy;
	sf::Vertex line;
	int enemyMoveCount;
	bool EnemyOnSurface;
	int EnemyPart;
	bool CollidedWithEnemy;
	void initVariables();
	void initPositions(int WorldMap[][1000]);


public:
	enemy(int WorldMap[][1000]);
	~enemy();
	void Enemy_Player(Player& chara, gameover& over,view& scene,music& audio);
	void EnemyAnimations();
	void EnemyMove();
	//void EnemyWithGround(ground& grd, int yvel);
	friend void music::playingAudio(Player& chara, FireBall& fire, enemy& enem,coins& coin);
	friend void FireBall::CollisionWithEnemyorSurfaces(ground& grd, enemy& enem);
	friend void Updates();
	friend void initRender();
	friend void chains::chainCollide(Player&, gameover&);
	friend void score::ScoreHandling(Player&, enemy&, coins&,FireBall&);

};

