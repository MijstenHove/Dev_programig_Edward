#pragma once
#include <SDL_mixer.h>

#include <unordered_map>
#include <string>
#include <cassert>

class AudioManager {
private:

	std::unordered_map<std::string , Mix_Chunk>sfx;
	std::unordered_map<std::string , Mix_Music> music;
	
	bool isMuted;

	static AudioManager* instance;
	AudioManager();
	AudioManager(const AudioManager&) = delete;
	AudioManager& operator=(const AudioManager&) = delete;
public:
	static AudioManager* GetInstance();
	void LoadSFX(std::string name);
	void UnLoadSFX(std::string name);

	void LoadMusic(std::string name);
	void UmLoadMusic(std::string name);

	void PlaySFX(std::string name, int repetition);
	void PlayMusic(std::string name, int repetition);
};

