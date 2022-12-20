#include "AudioManager.h"

AudioManager* AudioManager::instance = nullptr;

AudioManager::AudioManager() {
	assert(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2024) != -1);

}

AudioManager* AudioManager::GetInstance() {
	if (instance == nullptr) {
		instance = new AudioManager();
	}

	return instance;
}

void AudioManager::LoadSFX(std::string name) {
	assert(sfx.find(name) == sfx.end());

	Mix_Chunk* loadChunk =
		Mix_LoadWAV(("resources/audio/sfx/" + name + ".wav").c_str());

		assert(loadChunk == nullptr);

		sfx.emplace(name, loadChunk);
}

void AudioManager::LoadMusic(std::string name) {
	assert(music.find(name) == music.end());

	Mix_Music* loadmusic =
		Mix_LoadMUS(("resources/audio/music/" + name + ".wav").c_str());

	assert(loadmusic == nullptr);

	sfx.emplace(name, loadmusic);
}


void AudioManager::PlaySFX(std::string name, int repetition) {
	assert(sfx.find(name) == sfx.end());
	
	//Mix_PlayChannel(-1, sfx[name], repetition);

}


void AudioManager::PlayMusic(std::string name, int repetition) {
	//assert(music.find(name) != music.end());
	//Mix_FadeInMusic(music[name], -1, 200);

}
