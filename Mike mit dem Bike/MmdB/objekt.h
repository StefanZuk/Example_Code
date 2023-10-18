#include "SDL.h"
#include <string>
#include <sstream>
#include "stdlib.h"
#include "SDL_ttf.h"
#ifndef objekt_h
#define objekt_h 

class objekt
{
	private:

	SDL_Rect data;
	int xPosition;
	int yPosition;

	int kanteRechts;
	int kanteLinks;
	int kanteOben;
	int kanteUnten;

	int typ;

	SDL_Surface* bild;
	SDL_Surface* bildI;
	SDL_Surface* optimized;
	SDL_Surface* optimizedI;



    public:

	objekt(int typP, int xPos, int yPos, int w, int h);

	void setBild(std::string filename_str);
	SDL_Surface* getBild();

	void setBildI(std::string filename_str);
	SDL_Surface* getBildI();


	SDL_Rect getData();
	void setData(int posX, int posY, int width, int height);

	int getPositionX();
	int getPositionY();
	int getWidth();
	int getHight();

	int getType();

	void setKanten (SDL_Rect kanten);
	int getKanteR();
	int getKanteL();
	int getKanteO();
	int getKanteU();
	
	

};
#endif