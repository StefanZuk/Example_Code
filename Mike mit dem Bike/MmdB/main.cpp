#include "SDL.h"
#include <string>
#include <sstream>
#include "stdlib.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"

#include "steuerung.h"
#include "spieler.h"
#include "oberflaeche.h"
#include "figur.h"
#include "timer.h"
#include "objekt.h"

SDL_Event event;
steuerung dieSteuerung;
SDL_Surface *ausgabe = NULL;
int main(int argc, char* args[])
{


	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2,4096);

	dieSteuerung.setSoundtrack();

	if(Mix_PlayMusic(dieSteuerung.getSoundtrack(),-1)==-1)
	{
		SDL_Quit();
	}

	while (dieSteuerung.getMode() == 0 || dieSteuerung.getMode() == 1 || dieSteuerung.getMode() == 2 || dieSteuerung.getMode() == 69)
	{

		if (dieSteuerung.getMode() == 0)
		{
				dieSteuerung.selectMenu();
		
				while (dieSteuerung.getMode() == 0)
				{
					SDL_PollEvent(&event);
					dieSteuerung.handleEventM(event.key.keysym.sym, event.type);
				}

		}	

		if(dieSteuerung.getMode() == 2)
		{
			SDL_PollEvent(&event);
			dieSteuerung.anleitung(event.key.keysym.sym, event.type);
		}


		if(dieSteuerung.getMode() == 1)
		{
		//dieSteuerung.createLevel();
			
				while (dieSteuerung.getMode() == 1)
				{
					SDL_PollEvent(&event);
					dieSteuerung.handleEventG(event.key.keysym.sym, event.type);
				}

		}	

		if(dieSteuerung.getMode() == 69)
		{
		//dieSteuerung.createLevel();

				while (dieSteuerung.getMode() == 69)
				{
					SDL_PollEvent(&event);
					dieSteuerung.credits(event.key.keysym.sym, event.type);
				}

		}	

	}


	TTF_Quit();
	SDL_Quit();
	
	
	return 0;
}