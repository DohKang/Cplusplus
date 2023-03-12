#include "stdafx.h"
#include "SoundManager.h"

SoundManager::SoundManager()
{
	if (!this->basicMusicBuffer.loadFromFile("Music/basicMusic.wav"))
	{
		std::cout << "ERROR::TEXT::CAND NOT LOAD BASIC MUSIC" << "\n";
	}
	else 
	{
		this->basicMusicSound.setBuffer(this->basicMusicBuffer);
	}
	if (!this->bossMusicBuffer.loadFromFile("Music/bossMusic.wav"))
	{
		std::cout << "ERROR::TEXT::CAND NOT LOAD BOSS MUSIC" << "\n";
	}
	else
	{
		this->bossMusicSound.setBuffer(this->bossMusicBuffer);
	}
	if (!this->bullet1SoundBuffer.loadFromFile("Music/bullet1Sound.ogg"))
	{
		std::cout << "ERROR::TEXT::CAND NOT LOAD BULLET1 SOUND" << "\n";
	}
	else
	{
		this->bullet1Sound.setBuffer(this->bullet1SoundBuffer);
	}
	if (!this->bullet2SoundBuffer.loadFromFile("Music/bullet2Sound.wav"))
	{
		std::cout << "ERROR::TEXT::CAND NOT LOAD BULLET2 SOUND" << "\n";
	}
	else
	{
		this->bullet2Sound.setBuffer(this->bullet2SoundBuffer);
	}
	if (!this->laserSoundBuffer.loadFromFile("Music/laserSound.wav"))
	{
		std::cout << "ERROR::TEXT::CAND NOT LOAD LASER SOUND" << "\n";
	}
	else
	{
		this->laserSound.setBuffer(this->laserSoundBuffer);
	}
}

SoundManager::~SoundManager()
{

}

void SoundManager::_basicMusic()
{
	this->basicMusicSound.play();
	
}

void SoundManager::_bossMusic()
{
	this->bossMusicSound.play();
	
}

void SoundManager::_bullet1Sound()
{
	this->bullet1Sound.play();
	
}

void SoundManager::_bullet2Sound()
{
	this->bullet2Sound.play();
}

void SoundManager::_laserSound()
{
	this->laserSound.play();
}
