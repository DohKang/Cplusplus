#pragma once
class SoundManager
{
public:
	SoundManager();
	virtual ~SoundManager();
private:
	sf::SoundBuffer basicMusicBuffer;
	sf::SoundBuffer bossMusicBuffer;
	sf::SoundBuffer bullet1SoundBuffer;
	sf::SoundBuffer bullet2SoundBuffer;
	sf::SoundBuffer laserSoundBuffer;

	sf::Sound basicMusicSound;
	sf::Sound bossMusicSound;
	sf::Sound bullet1Sound;
	sf::Sound bullet2Sound;
	sf::Sound laserSound;

public:
	void _basicMusic();
	void _bossMusic();
	void _bullet1Sound();
	void _bullet2Sound();
	void _laserSound();

};

