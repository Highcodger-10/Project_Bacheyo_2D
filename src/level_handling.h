#pragma once
#include<SFML/Graphics.hpp>

class Player;
class view;
class music;
class gameover;
class background;
class level_handling
{
private:

	int Level;
	bool ChangeLevel;
	bool levelCompleted;
	void initVariables();

public:
	level_handling();
	~level_handling();
	friend void Updates();
	void ChangingLevel(Player& chara, music& audio, view& scene,background&,gameover&);
};

