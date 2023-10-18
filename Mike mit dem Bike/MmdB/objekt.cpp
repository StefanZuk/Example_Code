#include "SDL.h"
#include "objekt.h"
#include <string>
#include <sstream>
#include "stdlib.h"

objekt::objekt(int typP, int xPos, int yPos, int w, int h)
{
	data.x = xPos;
	data.y = yPos;
	data.w = w;
	data.h = h;

	typ=typP;
}

void objekt::setBild(std::string filename_str)
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

SDL_Surface* objekt::getBild()
{
	return optimized;
}

void objekt::setData(int posX, int posY, int width, int height)
{
	data.x=posX;
	data.y=posY;
	data.w=width;
	data.h=height;
}

SDL_Rect objekt::getData()
{
	return data;
}

int objekt::getPositionX()
{
	return data.x;
}

int objekt::getPositionY()
{
	return data.y;
}

int objekt::getWidth()
{
	return data.w;
}

int objekt::getHight()
{
	return data.h;
}

int objekt::getType()
{
	return typ;
}


void objekt::setKanten(SDL_Rect kanten)
{
	kanteRechts = kanten.y;
	kanteLinks = kanten.x;
	kanteOben = kanten.w;
	kanteUnten = kanten.h;
}

int objekt::getKanteR()
{
	return kanteRechts;
}

int objekt::getKanteL()
{
	return kanteLinks;
}

int objekt::getKanteO()
{
	return kanteOben;
}

int objekt::getKanteU()
{
	return kanteUnten;
}


void objekt::setBildI(std::string filename_str)
{
   bildI=SDL_LoadBMP(filename_str.c_str());

   if(bild !=NULL)
   {
      optimizedI = SDL_DisplayFormat(bildI);
	  SDL_FreeSurface (bildI);

	  Uint32 colorkey = SDL_MapRGB( optimizedI->format, 0x4C, 0xFF, 0x00 );
      SDL_SetColorKey( optimizedI, SDL_SRCCOLORKEY, colorkey );
   }
}

SDL_Surface* objekt::getBildI()
{
	return optimizedI;
}
