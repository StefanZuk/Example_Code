#include "SDL.h"
#include <string>
#include <sstream>
#include "stdlib.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"

#ifndef oberflaeche_h
#define oberflaeche_h 

class oberflaeche
{
	private:
	
	SDL_Surface* background;

	SDL_Surface* backgroundL;
	SDL_Surface* backgroundW;

	SDL_Surface* ausgabe;

	SDL_Rect position;



	

    public:

	oberflaeche();

	void setBackground(std::string filename_str);
	SDL_Surface* getBackground();

	void setBackgroundL(std::string filename_str);
	SDL_Surface* getBackgroundL();

	void setBackgroundW(std::string filename_str);
	SDL_Surface* getBackgroundW();

	void setAusgabe();
	SDL_Surface* getAusgabe();

	SDL_Rect getPosition();

	void darstellen();
	

};
#endif