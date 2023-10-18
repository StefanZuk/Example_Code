#include "SDL.h"
#include <string>
#include <sstream>
#include "stdlib.h"
#include "SDL_ttf.h"
#pragma once

#ifndef figur_h
#define figur_h 

class figur
{
	private:

	SDL_Rect data;
	int xPosition;
	int yPosition;

	int kanteRechts;
	int kanteLinks;
	int kanteOben;
	int kanteUnten;

	int zustand;

	bool alive;

	SDL_Surface* bild;
	SDL_Surface* bildR;

	SDL_Surface* optimized;
	SDL_Surface* optimizedR;
	SDL_Surface* optimizedJ;
	SDL_Surface* optimizedJR;

    public:

	figur(int xPos, int yPos, int w, int h);

	void setBild(std::string filename_str);
	SDL_Surface* getBild();

	void setBildR(std::string filename_str);
	SDL_Surface* getBildR();

	
void figur::setData(int posX, int posY, int width, int height);


SDL_Rect figur::getData();

int figur::getPositionX();
int figur::getPositionY();
int figur::getWidth();
int figur::getHeight();

void setKanten (SDL_Rect kanten);

int getKanteR();
int getKanteL();
int getKanteO();
int getKanteU();

void setZustand(int zustandP);
int getZustand();

void setAlive(bool aliveP);
bool getAlive();
	
	void setBildJ(std::string filename_str);
	SDL_Surface* getBildJ();

	void setBildJR(std::string filename_str);
	SDL_Surface* getBildJR();


};
#endif