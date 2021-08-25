#pragma once
#include<SFML/Graphics.hpp>
#include"platform.h"
#include"music.h"
#include"FireBall.h"
#include"view.h"
#include"enemy.h"
#include"gameover.h"
#include"chains.h"
#include"score.h"
#include"level_handling.h"
class ground;
class Player
{
private:
	//variables for players
	int positionX;
	int positionY;
	bool left, right;
	bool isJump;
	bool grounded;
	int accGravity;
	bool dontMovePlayer;
	int maxGravity;
	int jumpCount;
	bool collision;
	bool scored;
	bool PlayerRecovered;

	//textures and sprites for player
	sf::Texture CharacterText;
	sf::Sprite character;
	sf::IntRect AnimatingPart;


	//initializing functions for positions and variables
	void initVariables();
	void initPositions();


	
	
	

public:
	//public functions and constructors creations

	sf::Vector2f velocity;
	Player();
~Player();
	void PlayerUpdates(ground& grd,Player& chara,platform& pl);
	void PlayerMove(ground& grd,Player& chara, platform& pl);
	void PlayerJump(ground& grd,Player& chara, platform& pl);
	void ChangePositionForLevel(int* level,bool* ChangeOrNot,bool* End);
	void Animate();
	void runToEnd(int level);
	void characterFallDown(gameover&);


	//a friend function to use its private members
	sf::Vector2f getPositioning();
	int getState();
	friend void initRender();
	friend void  Updates();
	friend void platform::PlatformCollision(Player& chara,int xvel, int yvel);
	friend void gameover::moveLife( view&);
	friend void gameover::isGameOver(Player& chara,view& scene,int i,bool* didCollide,music& audio,bool*);
	friend void music::playingAudio(Player& chara,FireBall& fire, enemy& enem, coins& coin);
	friend void view::moveView(Player& chara);
	friend void enemy::Enemy_Player(Player& chara,gameover& over,view& scene,music& audio);
	friend void chains::chainCollide(Player&, gameover&);
	friend void level_handling::ChangingLevel(Player&, music&, view&,background&,gameover&);
	friend void score::ScoreHandling(Player&, enemy&, coins&,FireBall& );
	friend void FireBall::CollisionWithEnemyorSurfaces(ground& grd, enemy& enem);
	//checking for ground and player collisions
	void collisionHappen(ground& grd,int xvel, int yvel);
};




