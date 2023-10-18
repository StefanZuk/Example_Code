#include "SDL.h"
#include "oberflaeche.h"
#include "steuerung.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include <string>
#include <sstream>
#include "stdlib.h"



oberflaeche::oberflaeche()
{

}

void oberflaeche::darstellen()
{
	SDL_Flip(ausgabe);
}

void oberflaeche::setAusgabe()
{
	ausgabe = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE);
	SDL_WM_SetCaption("Mike mit dem Bike",NULL);
}

SDL_Surface* oberflaeche::getAusgabe()
{
	return ausgabe;
}


void oberflaeche::setBackground(std::string filename_str)
{
   background=SDL_LoadBMP(filename_str.c_str());

}

SDL_Surface* oberflaeche::getBackground()
{
	return background;
}

SDL_Rect oberflaeche::getPosition()
{
	return position;
}

	void oberflaeche::setBackgroundL(std::string filename_str)
	{
		backgroundL=SDL_LoadBMP(filename_str.c_str());
	}

	SDL_Surface* oberflaeche::getBackgroundL()
	{
		return backgroundL;
	}

	void oberflaeche::setBackgroundW(std::string filename_str)
	{
		backgroundW=SDL_LoadBMP(filename_str.c_str());
	}

	SDL_Surface* oberflaeche::getBackgroundW()
	{
		return backgroundW;
	}

	