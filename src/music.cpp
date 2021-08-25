#include "music.h"
#include"Player.h"
#include"FireBall.h"
#include"enemy.h"
#include"coins.h"
#include"platform.h"
void music::initAudio()
{
	this->playOutMusic = false;
	this->levelChanged = false;
	this->gameOverPlayed = 10;
	this->levelCompletedAudio.openFromFile("/home/highcodger_10/Desktop/Project_OOP_bachiyo_2D/audios/stage_clear.wav");
	this->level3Audio.openFromFile("/home/highcodger_10/Desktop/Project_OOP_bachiyo_2D/audios/underwater.ogg");
	this->level2Audio.openFromFile("/home/highcodger_10/Desktop/Project_OOP_bachiyo_2D/audios/underworld.ogg");
	this->khattamAudio.openFromFile("/home/highcodger_10/Desktop/Project_OOP_bachiyo_2D/audios/game_over.wav");
	this->pausedAudio.loadFromFile("/home/highcodger_10/Desktop/Project_OOP_bachiyo_2D/audios/pause.wav");
	this->killAudio.loadFromFile("/home/highcodger_10/Desktop/Project_OOP_bachiyo_2D/audios/kick.wav");
	this->fireAudio.loadFromFile("/home/highcodger_10/Desktop/Project_OOP_bachiyo_2D/audios/fireball.wav");
	this->mainAudio.openFromFile("/home/highcodger_10/Desktop/Project_OOP_bachiyo_2D/audios/overworld.ogg");
	this->gameOverAudio.openFromFile("/home/highcodger_10/Desktop/Project_OOP_bachiyo_2D/audios/mario_die.wav");
	if (!this->jumpingAudio.loadFromFile("/home/highcodger_10/Desktop/Project_OOP_bachiyo_2D/audios/jump_super.wav"))

	{
		std::cout << "failed to load audio";
	}
	
	if (!this->coinAudio.loadFromFile("/home/highcodger_10/Desktop/Project_OOP_bachiyo_2D/audios/coin.wav"))
	{
		std::cout << "failed to load audio";
	}
	this->coinSound.setBuffer(this->coinAudio);
	this->jumpSound.setBuffer(this->jumpingAudio);
	this->fireSound.setBuffer(this->fireAudio);
	this->killSound.setBuffer(this->killAudio);
	this->pausedSound.setBuffer(this->pausedAudio);

	this->mainAudio.play();
	
}

music::music()
{
	this->initAudio();
}

music::~music()
{
}

void music::ChangeAudioForLevel(int level)
{
	
	
	this->levelCompletedAudio.stop();
		if (level == 2)
		{
			this->mainAudio.stop();
			this->level2Audio.play();
		}
		else if (level == 3)
		{
			this->level2Audio.stop();
			this->level3Audio.play();
		}

	

}

void music::PlayEndingAudio(float xPos)
{
	if ((xPos >= 9050.f && xPos < 9090.f) || (xPos >= 19050.f && xPos < 19090.f)) 
	{
		this->mainAudio.stop();
		this->level2Audio.stop();
		this->level3Audio.stop();
		this->levelCompletedAudio.play();
	}

	
	
	
}

void music::playingAudio(Player& chara,FireBall& fire,enemy& enem,coins& coin)
{
	
	if (chara.isJump == true && chara.jumpCount == 9)
	{
		this->jumpSound.play();
	}
	
	
	
	
	if (chara.character.getPosition().y > 800.f )
	{
		this->mainAudio.stop();
		this->level2Audio.stop();
		this->level3Audio.stop();
		this->gameOverAudio.play();
		chara.character.setPosition(-4000, -5000);
	}
	
	if ((fire.fireball.getPosition().x - 75) ==  chara.character.getPosition().x and fire.fired)
	{
		this->fireSound.play();
	}
	for (int i = 0;i < 1000;i++)
	{
		if (fire.fireball.getGlobalBounds().intersects(enem.EnemySprite1[i].getGlobalBounds()) ||

			(fire.fireball.getGlobalBounds().intersects(enem.EnemySprite2[i].getGlobalBounds()) && fire.fired))
		{
			this->killSound.play();
		}

		if (chara.character.getGlobalBounds().intersects(coin.coinSprite[i].getGlobalBounds()))
		{
			this->coinSound.play();
			coin.coinSprite[i].setPosition(0,5000);
		}
	}

	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
	{
		this->pausedSound.play();
	}
	
}