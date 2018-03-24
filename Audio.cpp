#include "Audio.h"
#include <iostream>
Audio::Audio(std::string title)
{
	if (SDL_LoadWAV(title.c_str(), &spec, &start, &length) == NULL)
		std::cout << "Failed to load audio file: " << SDL_GetError() << std::endl;
	device = SDL_OpenAudioDevice(NULL, 0, &spec, NULL, 0);

}

void Audio::Play()
{
	SDL_QueueAudio(device, start, length);
	SDL_PauseAudioDevice(device, 0);
}

//Not a real sound loop,needs to be called on a loop (preferably game loop).
//Also a bit wasteful since it queues the audio file twice. Meant for background
//music which has a length longer than sound effects.
void Audio::Loop() {
	if (SDL_GetQueuedAudioSize(device) < length) {
		SDL_QueueAudio(device, start, length);
		SDL_PauseAudioDevice(device, 0);
	}
}

Audio::~Audio()
{
	SDL_FreeWAV(start);
	SDL_CloseAudioDevice(device);
}
