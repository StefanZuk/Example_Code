#include "SDL.h"
#include "figur.h"
#include <string>
#include <sstream>
#include "stdlib.h"

figur::figur(int xPos, int yPos, int w, int h)
{
	data.x=xPos;
	data.y=yPos;
	data.w=w;
	data.h=h;

	alive = true;
}


void figur::setBild(std::string filename_str)
{
	bild=SDL_LoadBMP(filename_str.c_str());

   if(bild !=NULL)
   {
      optimized = SDL_DisplayFormat(bild);
	  SDL_FreeSurface (bild);

	  Uint32 colorkey = SDL_MapRGB( optimized->format, 0x4C, 0xFF, 0x00 );
      SDL_SetColorKey( optimized, SDL_SRCCOLORKEY, colorkey );
   }
}

SDL_Surface* figur::getBild()
{
	return optimized;
}


void figur::setBildR(std::string filename_str)
{
	bildR=SDL_LoadBMP(filename_str.c_str());

   if(bildR !=NULL)
   {
      optimizedR = SDL_DisplayFormat(bildR);
	  SDL_FreeSurface (bildR);

	  Uint32 colorkey = SDL_MapRGB( optimizedR->format, 0x4C, 0xFF, 0x00 );
      SDL_SetColorKey( optimizedR, SDL_SRCCOLORKEY, colorkey );
   }
}

SDL_Surface* figur::getBildR()
{
	return optimizedR;
}


void figur::setData(int posX, int posY, int width, int height)
{
	data.x=posX;
	data.y=posY;
	data.w=width;
	data.h=height;
}

SDL_Rect figur::getData()
{
	return data;
}

int figur::getPositionX()
{
	return data.x;
}

int figur::getPositionY()
{
	return data.y;
}

int figur::getWidth()
{
	return data.w;
}

int figur::getHeight()
{
	return data.h;
}


void figur::setKanten(SDL_Rect kanten)
{
	kanteRechts = kanten.y;
	kanteLinks = kanten.x;
	kanteOben = kanten.w;
	kanteUnten = kanten.h;
}

int figur::getKanteR()
{
	return kanteRechts;
}

int figur::getKanteL()
{
	return kanteLinks;
}

int figur::getKanteO()
{
	return kanteOben;
}

int figur::getKanteU()
{
	return kanteUnten;
}

void figur::setZustand(int zustandP)
{
	zustand = zustandP;
}

int figur::getZustand()
{
	return zustand;
}

void figur::setAlive(bool aliveP)
{
	alive = aliveP;
}

bool figur::getAlive()
{
	return alive;
}

void figur::setBildJ(std::string filename_str)
{
	bild=SDL_LoadBMP(filename_str.c_str());

   if(bild !=NULL)
   {
      optimizedJ = SDL_DisplayFormat(bild);
	  SDL_FreeSurface (bild);

	  Uint32 colorkey = SDL_MapRGB( optimizedJ->format, 0x4C, 0xFF, 0x00 );
      SDL_SetColorKey( optimizedJ, SDL_SRCCOLORKEY, colorkey );
   }
}

SDL_Surface* figur::getBildJ()
{
	return optimizedJ;
}

void figur::setBildJR(std::string filename_str)
{
	bild=SDL_LoadBMP(filename_str.c_str());

   if(bild !=NULL)
   {
      optimizedJR = SDL_DisplayFormat(bild);
	  SDL_FreeSurface (bild);

	  Uint32 colorkey = SDL_MapRGB( optimizedJR->format, 0x4C, 0xFF, 0x00 );
      SDL_SetColorKey( optimizedJR, SDL_SRCCOLORKEY, colorkey );
   }
}

SDL_Surface* figur::getBildJR()
{
	return optimizedJR;
}