#include "level_handling.h"
#include"Player.h"
#include"view.h"
#include"music.h"
#include"background.h"
void level_handling::initVariables()
{
	this->ChangeLevel = false;
	this->Level = 1;
	this->levelCompleted = false;
}

level_handling::level_handling()
{
	this->initVariables();
}

level_handling::~level_handling()
{
}

void level_handling::ChangingLevel(Player& chara, music& audio, view& scene,background& bg,gameover& over)
{
	chara.ChangePositionForLevel(&this->Level, &this->ChangeLevel,&this->levelCompleted);


	scene.DontMoveSetup(chara.character.getPosition().x);

	if (scene.dontMove)
	{
		chara.runToEnd(this->Level);
		audio.PlayEndingAudio(chara.character.getPosition().x);

	}
	
	if (this->ChangeLevel)
	{	
		
		audio.ChangeAudioForLevel(this->Level);
		scene.changeViewForLevel(this->Level);
		bg.switchBackgroundForLevelChange(this->Level);
		over.changingCheckPoints(this->Level);
		this->ChangeLevel = false;
		chara.dontMovePlayer = false;
	}
	
	

}
