#pragma once
#include "SDL.h"
#include <string>
class Audio {
public:
	Audio(std::string title);
	void Play();
	void Loop();
	~Audio();
private:
	SDL_AudioSpec spec;
	SDL_AudioDeviceID device;
	Uint8* start;
	Uint32 length;
	int onQueue = 0;
};