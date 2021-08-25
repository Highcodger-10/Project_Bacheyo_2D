#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include"gameover.h"
class coins;
class enemy;
class FireBall;
class Player;
class platform;
class music
{


public:
	//main game audio
	sf::Music mainAudio;
	sf::Music gameOverAudio;
	sf::Music khattamAudio;
	sf::Music level2Audio;
	sf::Music level3Audio;
	sf::Music levelCompletedAudio;
	bool playOutMusic;
	bool levelChanged;
	int gameOverPlayed;
	//load the audio files
	sf::SoundBuffer jumpingAudio;
	sf::SoundBuffer coinAudio;
	sf::SoundBuffer fireAudio;
	sf::SoundBuffer killAudio;
	sf::SoundBuffer pausedAudio;
	

	//functions to play the loaded audio files
	sf::Sound coinSound;
	sf::Sound jumpSound;
	sf::Sound fireSound;
	sf::Sound killSound;
	sf::Sound pausedSound;

	void initAudio();

public:
	music();
	~music();
	void ChangeAudioForLevel(int level);
	void PlayEndingAudio( float xPos);
	void playingAudio(Player& chara,FireBall& fire,enemy& enem,coins& coin);
	friend void gameover::isGameOver(Player& chara, view& scene, int i, bool* didCollide, music& audio,bool*);
};

