#include "Sound.h"

int Sound::Start;
int Sound::EnemyJump;
int Sound::Crack;
int Sound::Parachute;

void Sound::LoadSound() 
{
	Start = LoadSoundMem("sounds/SE_Start.wav");
	EnemyJump = LoadSoundMem("sounds/SE_EnemyMove.wav");
	Crack = LoadSoundMem("sounds/SE_crack.wav");
	Parachute = LoadSoundMem("sounds/SE_parachute.wav");
}