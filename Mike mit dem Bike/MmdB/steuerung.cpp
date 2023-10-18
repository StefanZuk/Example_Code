#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include <string>
#include <sstream>
#include "stdlib.h"

#include "steuerung.h"
#include "oberflaeche.h"
#include "spieler.h"
#include "figur.h"
#include "timer.h"
#include "objekt.h"

oberflaeche dieOberflaeche;
objekt derCursor(1, 475, 285, 100, 100);
figur derMike(15,320,74,71);
objekt derStachel(2, 200, 409, 64, 33);
objekt derStachelII(2, 400, 409, 64,33);
objekt derStachelIII(2, 466, 409, 64,33);
objekt derBoden(3, 0, 444, 800, 160);
objekt derBlock(5, 450, 300, 70, 30);
objekt derBlockII(5, 450, 700, 70, 30);
objekt derVorsprung(3, 635, 307, 165, 293);
objekt dieAnzeige(7, 1, 1 ,1, 1);
objekt dieRakete(2, 874, 350, 73, 50);

objekt dasProjektilI(2, 490, 300, 30,30);
objekt dasProjektilII(2, 550, 300, 30,30);
objekt dasProjektilIII(2, 610, 300, 30,30);

objekt dieMikeCoinI(3,1,1,1,1);
objekt dieMikeCoinII(3,1,1,1,1);
objekt dieMikeCoinIII(3,1,1,1,1);

objekt dasJetpack(11,1,1,1,1);

objekt benzin(12,1,1,1,1);

objekt derBoss(2, 900,150, 200, 300);

timer dieBestzeit;
timer fps;


steuerung::steuerung()
{
	//appRunning = true;
	mode = 0;
	menuVar = 1;
	level = 1;
	speedH = 4;
	framesps = 80;
	hitsDodged = 0;
	shot = false;
	loaded1 = false;
	loaded2 = false;
	loaded3 = false;
	loaded4 = false;
	coints =0;
	fuel =0;
	screen =1;
	higher = false;
}


void steuerung::selectMenu()
{
	dieOberflaeche.setAusgabe();
	dieOberflaeche.setBackground("Menu.bmp");
	derCursor.setBild("auswahl.bmp");
}


void steuerung::createLevel()
{
	sprung = true;
	derMike.setZustand(1);

	switch (level)
	{
		case 1:

			if (loaded1 == false)
			{
				loaded1  = true;
				dieOberflaeche.setBackground("background.bmp");
			}
			derStachel.setData(200, 409, 64, 33);
			derStachelII.setData(400, 409, 64,33);
			derStachelIII.setData(466, 409, 64,33);

			derBlock.setData(450, 300, 70, 30);
			derBlockII.setData(450, 700, 70, 30);

			derVorsprung.setData(0,0,0,0);

			derBoss.setData(999,1150, 200, 300);

			dasProjektilI.setData(1,800,1,1);
			dasProjektilII.setData(1,800,1,1);
			dasProjektilIII.setData(1,800,1,1);

			dieMikeCoinI.setData(300, 380, 54,54);
			dieMikeCoinII.setData(466, 240, 54,54);
			dieMikeCoinIII.setData(600, 380, 54,54);

			benzin.setData(700,390, 37, 43);

			dasJetpack.setData(900,0,1,1);

			break;

		case 2:

			if(loaded2 == false)
			{
				loaded2 = true;
				dieOberflaeche.setBackground("background2.bmp");
			}
			derStachel.setData(150,409,64,33);
			derStachelII.setData(539,409,64,33);
			derStachelIII.setData(605,409,64,33);

			derBlock.setData(450, 300, 70, 30);
			derBlockII.setData(600, 300, 70, 30);

			derVorsprung.setData(0,0,0,0);

			derBoss.setData(999,1150, 200, 300);

			dasProjektilI.setData(1,800,1,1);
			dasProjektilII.setData(1,800,1,1);
			dasProjektilIII.setData(1,800,1,1);

			dieMikeCoinI.setData(150, 330, 54,54);
			dieMikeCoinII.setData(455, 380, 54,54);
			dieMikeCoinIII.setData(605, 100, 54,54);

			benzin.setData(455,250, 37, 43);

			dasJetpack.setData(900,0,1,1);

			break;

		case 3:
			
			if(loaded3 == false)
			{
				loaded3 = true;
				dieOberflaeche.setBackground("background3.bmp");
			}

			derStachel.setData(120,409,64,33);
			derStachelII.setData(300,409,64,33);
			derStachelIII.setData(500,409,64,33);

			derBlock.setData(120, 300, 70, 30);
			derBlockII.setData(470, 300, 70, 30);

			derVorsprung.setData(635, 307, 165, 293);

			derBoss.setData(999,1150, 200, 300);

			dasProjektilI.setData(1,800,1,1);
			dasProjektilII.setData(1,800,1,1);
			dasProjektilIII.setData(1,800,1,1);

			dieMikeCoinI.setData(200, 380, 54,54);
			dieMikeCoinII.setData(300, 100, 54,54);
			dieMikeCoinIII.setData(380, 380, 54,54);

			dasJetpack.setData(900,0,1,1);

			benzin.setData(645,250, 37, 43);

			break;

		case 4:
			
			if(loaded4 == false)
			{
				loaded4 = true;
				dieOberflaeche.setBackground("backgroundBoss.bmp");
			}
			derStachel.setData(200,409,64,33);
			derStachelII.setData(265,409,64,33);
			derStachelIII.setData(330,409,64,33);

			derBlock.setData(150, 300, 70, 30);
			derBlockII.setData(230, 300, 70, 30);

			derVorsprung.setData(900, 307, 165, 293);

			derBoss.setData(500,0, 200, 441);

			dieRakete.setData(800, 700,1,1);

			dasProjektilI.setData(480,247,30,30);
			dasProjektilII.setData(520,247,30,30);
			dasProjektilIII.setData(560,247,30,30);

			dieMikeCoinI.setData(200, 880, 54,54);
			dieMikeCoinII.setData(300, 800, 54,54);
			dieMikeCoinIII.setData(380, 880, 54,54);

			dasJetpack.setData(230,200,41,65);

			benzin.setData(1000,390, 37, 43);

			break;

		case 5:
			win = true;
			level = 1;
			loaded1 = false;
			loaded2 = false;
			loaded3 = false;
			loaded4 = false;

			dieOberflaeche.setBackgroundL("score.bmp");

			reset();


			break;
	}

	dieBestzeit.start();
	
}

	
int steuerung::getHighscore()
{
	return highscore;	
}

void steuerung::setKeyStates()
{
	keystates = SDL_GetKeyState(NULL);
}

Uint8* steuerung::getKeyStates()
{
	return keystates;
}

int steuerung::getMode()
{
	return mode;
}

int steuerung::handleEventG(SDLKey code, Uint8 druck)
{
	fps.start();

	keystates = SDL_GetKeyState(NULL);

	if (druck == SDL_QUIT)
	{
		mode=3;
	}

	gravity();

	if (druck == SDL_KEYDOWN)
	{
		
		if(keystates[SDLK_ESCAPE])
		{
			mode = 0;
			win = false;
			
			reset();

			loaded1 = false;
			loaded2 = false;
			loaded3 = false;
			loaded4 = false;

			level = 1;

			fuel = 0;
		}

	


		if(keystates[SDLK_RIGHT])
		{
			derMike.setZustand(1);
			for(int i = 0; i <=speedH; i++)
			{
				derMike.setZustand(1);
				derMike.setData(derMike.getPositionX()+1, derMike.getPositionY(), derMike.getWidth(), derMike.getHeight());

				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derStachel.getData())) == true)
				{
					derMike.setAlive(false);
				}
				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derStachelII.getData())) == true)
				{
					derMike.setAlive(false);
				}
				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derStachelIII.getData())) == true)
				{
					derMike.setAlive(false);
				}

				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derBlock.getData())) == true)
				{
					derMike.setData(derMike.getPositionX()-1, derMike.getPositionY(), derMike.getWidth(), derMike.getHeight());
				}
				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derBlockII.getData())) == true)
				{
					derMike.setData(derMike.getPositionX()-1, derMike.getPositionY(), derMike.getWidth(), derMike.getHeight());
				}
				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derVorsprung.getData())) == true)
				{
					derMike.setData(derMike.getPositionX()-1, derMike.getPositionY(), derMike.getWidth(), derMike.getHeight());
				}

				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(dieMikeCoinI.getData())) == true)
				{
					coints++;
					dieMikeCoinI.setData(898,889,1,1);
				}
				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(dieMikeCoinII.getData())) == true)
				{
					coints++;
					dieMikeCoinII.setData(898,889,1,1);
				}
				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(dieMikeCoinIII.getData())) == true)
				{
					coints++;
					dieMikeCoinIII.setData(898,889,1,1);
				}

				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(dasJetpack.getData())) == true)
				{
					if(fuel >= 3)
					{
						boost = true;
					}

					else
					{
						boost = false;
					}

					dasJetpack.setData(898,889,1,1);
				}

				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(benzin.getData())) == true)
				{
					fuel++;
					benzin.setData(898,889,1,1);
				}

				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derBoss.getData())) == true)
				{
					derMike.setAlive(false);
				}

			}
		}

		if(keystates[SDLK_LEFT])
		{
			derMike.setZustand(2);

			for(int j = 0; j<=speedH; j++)
			{
				derMike.setData(derMike.getPositionX()-1, derMike.getPositionY(), derMike.getWidth(), derMike.getHeight());

				if(derMike.getPositionX() <= 1)
				{
					derMike.setData(derMike.getPositionX()+1, derMike.getPositionY(), derMike.getWidth(), derMike.getHeight());
				}

				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derStachel.getData())) == true)
				{
					derMike.setAlive(false);
				}
				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derStachelII.getData())) == true)
				{
					derMike.setAlive(false);
				}
				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derStachelIII.getData())) == true)
				{
					derMike.setAlive(false);
				}

				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derBlock.getData())) == true)
				{
					derMike.setData(derMike.getPositionX()+1, derMike.getPositionY(), derMike.getWidth(), derMike.getHeight());
				}
				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derBlockII.getData())) == true)
				{
					derMike.setData(derMike.getPositionX()+1, derMike.getPositionY(), derMike.getWidth(), derMike.getHeight());
				}
				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derVorsprung.getData())) == true)
				{
					derMike.setData(derMike.getPositionX()+1, derMike.getPositionY(), derMike.getWidth(), derMike.getHeight());
				}

				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(dieMikeCoinI.getData())) == true)
				{
					coints++;
					dieMikeCoinI.setData(898,889,1,1);
				}
				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(dieMikeCoinII.getData())) == true)
				{
					coints++;
					dieMikeCoinII.setData(898,889,1,1);
				}
				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(dieMikeCoinIII.getData())) == true)
				{
					coints++;
					dieMikeCoinIII.setData(898,889,1,1);
				}

				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(dasJetpack.getData())) == true)
				{
					if(fuel >= 3)
					{
						boost = true;
					}

					else
					{
						boost = false;
					}

					dasJetpack.setData(898,889,1,1);
				}

				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(benzin.getData())) == true)
				{
					fuel++;
					benzin.setData(898,889,1,1);
				}

				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derBoss.getData())) == true)
				{
					derMike.setAlive(false);
				}

			}
		}

		if(keystates[SDLK_UP])
		{
			
			if(boost == true)
			{
				for(int y = 0; y <= 12; y++)
				{

					derMike.setData(derMike.getPositionX(), derMike.getPositionY()-1, derMike.getWidth(), derMike.getHeight());

					if(derMike.getPositionY() <= 10)
					{
						derMike.setData(derMike.getPositionX(), derMike.getPositionY()+1, derMike.getWidth(), derMike.getHeight());
					}

					if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derBlock.getData())) == true)
					{
						derMike.setData(derMike.getPositionX(), derMike.getPositionY()+1, derMike.getWidth(), derMike.getHeight());
					}
				}
			}

			else
			{

				if(derMike.getPositionY() <= 70)
				{
					derMike.setData(derMike.getPositionX(), derMike.getPositionY()+1, derMike.getWidth(), derMike.getHeight());
				}

				if (sprung == false)
				{
					derMike.setData(derMike.getPositionX(), derMike.getPositionY(), derMike.getWidth(), derMike.getHeight());						
				}

				else
				{

				
				
					if (derMike.getPositionY()>290 && derMike.getPositionY()<=380 || derMike.getPositionY()>150 && derMike.getPositionY()<=229 && higher == true)
					{
						speedV = 14;
				

						for(int i=0; i<=speedV; i++)
						{				
							derMike.setData(derMike.getPositionX(), derMike.getPositionY() - 1, derMike.getWidth(), derMike.getHeight());
					

							if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derBlock.getData())) == true)
							{
								derMike.setData(derMike.getPositionX(), derMike.getPositionY()+1, derMike.getWidth(), derMike.getHeight());
								sprung = false;
							}
							if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derBlockII.getData())) == true)
							{
								derMike.setData(derMike.getPositionX(), derMike.getPositionY()+1, derMike.getWidth(), derMike.getHeight());
								sprung = false;
							}

							if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(dieMikeCoinI.getData())) == true)
							{
								coints++;
								dieMikeCoinI.setData(898,889,1,1);
							}
							if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(dieMikeCoinII.getData())) == true)
							{
								coints++;
								dieMikeCoinII.setData(898,889,1,1);
							}
							if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(dieMikeCoinIII.getData())) == true)
							{
								coints++;
								dieMikeCoinIII.setData(898,889,1,1);
							}

							if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(dasJetpack.getData())) == true)
							{
								if(fuel >= 3)
								{
									boost = true;
								}

								else
								{
									boost = false;
								}

								dasJetpack.setData(898,889,1,1);
							}

							if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(benzin.getData())) == true)
							{
								fuel++;
								benzin.setData(898,889,1,1);
							}

							if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derBoss.getData())) == true)
							{
								derMike.setAlive(false);
							}
						}
					}

					else
					{
						if (derMike.getPositionY()>250 && derMike.getPositionY()<=290 || derMike.getPositionY()>110 && derMike.getPositionY()<150 && higher == true)
						{
							speedV = 10;
					

							for(int j=0; j<=speedV; j++)
							{
								derMike.setData(derMike.getPositionX(), derMike.getPositionY() - 1, derMike.getWidth(), derMike.getHeight());
								

								if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derBlock.getData())) == true)
								{
									derMike.setData(derMike.getPositionX(), derMike.getPositionY()+1, derMike.getWidth(), derMike.getHeight());
									sprung = false;
								}
								if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derBlockII.getData())) == true)
								{
									derMike.setData(derMike.getPositionX(), derMike.getPositionY()+1, derMike.getWidth(), derMike.getHeight());
									sprung = false;
								}

								if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(dieMikeCoinI.getData())) == true)
								{
									coints++;
									dieMikeCoinI.setData(898,889,1,1);
								}
								if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(dieMikeCoinII.getData())) == true)
								{
									coints++;
									dieMikeCoinII.setData(898,889,1,1);
								}
								if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(dieMikeCoinIII.getData())) == true)
								{
									coints++;
									dieMikeCoinIII.setData(898,889,1,1);
								}

								if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(dasJetpack.getData())) == true)
								{
									if(fuel >= 3)
									{
										boost = true;
									}

									else
									{
										boost = false;
									}
									dasJetpack.setData(898,889,1,1);
								}

								if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(benzin.getData())) == true)
								{
									fuel++;
									benzin.setData(898,889,1,1);
								}

								if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derBoss.getData())) == true)
								{
									derMike.setAlive(false);
								}
							}
						}

						else
						{
							if (derMike.getPositionY()>=200 && derMike.getPositionY()<=250  || derMike.getPositionY()>70 && derMike.getPositionY()<110 && higher == true )
							{
								speedV = 8;
							

								for(int k=0; k<=speedV; k++)
								{
									derMike.setData(derMike.getPositionX(), derMike.getPositionY() - 1, derMike.getWidth(), derMike.getHeight());
						
									
									if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derBlock.getData())) == true)
									{
										derMike.setData(derMike.getPositionX(), derMike.getPositionY()+1, derMike.getWidth(), derMike.getHeight());
										sprung = false;
									}
									if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derBlockII.getData())) == true)
									{
										derMike.setData(derMike.getPositionX(), derMike.getPositionY()+1, derMike.getWidth(), derMike.getHeight());
										sprung = false;
									}

									if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(dieMikeCoinI.getData())) == true)
									{
										coints++;
										dieMikeCoinI.setData(898,889,1,1);
									}
									if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(dieMikeCoinII.getData())) == true)
									{
										coints++;
										dieMikeCoinII.setData(898,889,1,1);
									}
									if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(dieMikeCoinIII.getData())) == true)
									{
										coints++;
										dieMikeCoinII.setData(898,889,1,1);
									}

									if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(dasJetpack.getData())) == true)
									{
										if(fuel >= 3)
										{
											boost = true;
										}

										else
										{
											boost = false;
										}

										dasJetpack.setData(898,889,1,1);
									}

									if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(benzin.getData())) == true)
									{
										fuel++;
										benzin.setData(898,889,1,1);
									}

									if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derBoss.getData())) == true)
									{
										derMike.setAlive(false);
									}
								}
							}

							else
							{
																
								speedV = 0;
								sprung = false;
							}

						}
					}
				}
			}
		}
	}

	if (druck == SDL_KEYUP)
	{
		if(boost == false)
		{
			if(code == SDLK_UP)
			{

				if (collision == true)
				{
					sprung = true;
				}
				else
				{
					sprung= false;
				}
			}

			if(code == SDLK_LEFT)
			{
				if (collision == true)
				{
					sprung = true;
				}
				else
				{
					sprung = false;
				}
			}

			if(code == SDLK_RIGHT)
			{
				if (collision == true)
				{
					sprung = true;
				}
				else
				{
					sprung = false;
				}
			}
		}
	}

	if(level != 4)
	{
		eventRocket();
	}

	if(level == 4)
	{
		eventBoss();			
	}



	SDL_BlitSurface(derStachel.getBild(),NULL,dieOberflaeche.getAusgabe(), &derStachel.getData());
	SDL_BlitSurface(derStachelII.getBild(),NULL,dieOberflaeche.getAusgabe(), &derStachelII.getData());
	SDL_BlitSurface(derStachelIII.getBild(),NULL,dieOberflaeche.getAusgabe(), &derStachelIII.getData());

	SDL_BlitSurface(derBlock.getBild(),NULL,dieOberflaeche.getAusgabe(), &derBlock.getData());
	SDL_BlitSurface(derBlockII.getBild(),NULL,dieOberflaeche.getAusgabe(), &derBlockII.getData());

	SDL_BlitSurface(dieRakete.getBild(),NULL,dieOberflaeche.getAusgabe(), &dieRakete.getData());

	SDL_BlitSurface(dasProjektilI.getBild(),NULL, dieOberflaeche.getAusgabe(), &dasProjektilI.getData());
	SDL_BlitSurface(dasProjektilII.getBild(),NULL, dieOberflaeche.getAusgabe(), &dasProjektilII.getData());
	SDL_BlitSurface(dasProjektilIII.getBild(),NULL, dieOberflaeche.getAusgabe(), &dasProjektilIII.getData());

	SDL_BlitSurface(dieMikeCoinI.getBild(),NULL, dieOberflaeche.getAusgabe(), &dieMikeCoinI.getData());
	SDL_BlitSurface(dieMikeCoinII.getBild(),NULL, dieOberflaeche.getAusgabe(), &dieMikeCoinII.getData());
	SDL_BlitSurface(dieMikeCoinIII.getBild(),NULL, dieOberflaeche.getAusgabe(), &dieMikeCoinIII.getData());

	SDL_BlitSurface(dasJetpack.getBild(), NULL, dieOberflaeche.getAusgabe(), &dasJetpack.getData());

	SDL_BlitSurface(benzin.getBild(), NULL, dieOberflaeche.getAusgabe(), &benzin.getData());

	if(hitsDodged >= 3)
	{
		derBoss.setData(derBoss.getPositionX(), 145, 200,300);
		SDL_BlitSurface(derBoss.getBildI(),NULL, dieOberflaeche.getAusgabe(), &derBoss.getData());

	}

	else
	{
		SDL_BlitSurface(derBoss.getBild(),NULL, dieOberflaeche.getAusgabe(), &derBoss.getData());
	}
	

	if(derMike.getZustand() == 1)
	{
		if(boost == false)
		{
			SDL_BlitSurface(derMike.getBild(),NULL,dieOberflaeche.getAusgabe(), &derMike.getData());
		}

		else
		{
			SDL_BlitSurface(derMike.getBildJ(),NULL,dieOberflaeche.getAusgabe(), &derMike.getData());
		}
	}

	else
	{
		if(boost == false)
		{
			SDL_BlitSurface(derMike.getBildR(),NULL,dieOberflaeche.getAusgabe(), &derMike.getData());
		}

		else
		{
			SDL_BlitSurface(derMike.getBildJR(),NULL,dieOberflaeche.getAusgabe(), &derMike.getData());
		}
	}

	if(derMike.getAlive() == false)
	{
		derMike.setData(-100,0,derMike.getHeight(),derMike.getWidth());
		SDL_BlitSurface(dieOberflaeche.getBackgroundL(), NULL, dieOberflaeche.getAusgabe(),NULL);
		SDL_BlitSurface(derMike.getBildR(),NULL,dieOberflaeche.getAusgabe(), &derMike.getData());

		dieOberflaeche.darstellen();

		SDL_Delay(1500);
		derMike.setAlive(true);

		reset();
	}

	if(derMike.getPositionX() >= 726)
	{
		reset();
		level++;
		if(level >= 5)
		{
			mode = 69;
		}
		createLevel();

		return mode;

	}


	dieOberflaeche.darstellen();
	frame++;

	if(fps.get_ticks() < 1000 / framesps ) 
    {
		SDL_Delay( ( 1000 / framesps ) - fps.get_ticks() );
    }

	return mode;
	
}


int steuerung::handleEventM(SDLKey code , Uint8 druck)
{
	
	if (druck == SDL_QUIT)
	{
		mode=3;
		//appRunning = false;
	}

	if (druck == SDL_KEYDOWN)
	{
		switch( code )
		{
			case SDLK_UP: 
				switch (menuVar)
				{
					case 3:

						derCursor.setData(475,380,100,100);
						menuVar=2;
						break;
				
				
					case 1:					
						derCursor.setData(475,485,100,100);
						menuVar=3;
						break;
				
				
					case 2:
						derCursor.setData(475,285,100,100);
						menuVar=1;
						break;
				}
				break;

			case SDLK_DOWN:
				switch (menuVar)
				{
				case 3:
					derCursor.setData(475,285,100,100);
					menuVar=1;
					break;
				
				case 1:
				
					menuVar=2;
					derCursor.setData(475,380,100,100);
					break;
				
				case 2:
				
					menuVar=3;
					derCursor.setData(475,485,100,100);
					break;
				}
				break;

			case SDLK_ESCAPE:
				mode = 3;
				//appRunning = false;
				break;

			case SDLK_RETURN:
				switch (menuVar)
				{
					case 1:
						mode = 1;
					
						createLevel();
						break;
										
					case 2: 		
						mode = 2;
						init();
					break;

					case 3:
						mode = 3;
					
						break;
				}	
				level =1;

				coints = 0;

				boost = false;

				init();
				break;
		}
		
	}

	SDL_BlitSurface(dieOberflaeche.getBackground(),NULL,dieOberflaeche.getAusgabe(),NULL);
	SDL_BlitSurface(derCursor.getBild(),NULL,dieOberflaeche.getAusgabe(),&derCursor.getData());
	dieOberflaeche.darstellen();
	SDL_Delay (70);

	return mode;
	

	
}

void steuerung::setScore(int scroreP)
{
}

int steuerung::getScore()
{
	return score;
}


SDL_Rect steuerung::kantenBerechnenF(SDL_Rect datenF)
{
	positionF.x = datenF.x;
    positionF.y = datenF.x + datenF.w;
    positionF.w = datenF.y;
    positionF.h = datenF.y + datenF.h;

	return positionF;
}

SDL_Rect steuerung::kantenBerechnenO(SDL_Rect datenO)
{
	positionO.x = datenO.x;
    positionO.y = datenO.x + datenO.w;
    positionO.w = datenO.y;
    positionO.h = datenO.y + datenO.h;

	return positionO;
}



bool steuerung::checkKollision(SDL_Rect figur, SDL_Rect objekt)
{
	if( figur.w == objekt.h && figur.y >= objekt.x && figur.y <= objekt.y || figur.w == objekt.h && figur.x >= objekt.x && figur.x <= objekt.y || figur.w == objekt.h && figur.x <= objekt.x && figur.y >= objekt.y || figur.y == objekt.x && figur.h >= objekt.w && figur.h <= objekt.h || figur.y == objekt.x && figur.w <= objekt.h && figur.w >=objekt.w || figur.y == objekt.x && figur.w < objekt.w && figur.h > objekt.h || figur.x == objekt.y  &&  figur.h >= objekt.w && figur.h <= objekt.h || figur.x == objekt.y && figur.w <= objekt.h && figur.w >=objekt.w || figur.x == objekt.y && figur.w < objekt.w && figur.h > objekt.h || figur.h == objekt.w && figur.y >= objekt.x && figur.y <= objekt.y || figur.h == objekt.w && figur.x >= objekt.x && figur.x <= objekt.y || figur.h == objekt.w && figur.x < objekt.x && figur.y > objekt.y )
	{
		return true;
	}

	else
	{
		return false;
	}
}


void steuerung::gravity()
{

if(boost ==true)
{
	gravityValue =5;

	for(int i=0; i<=gravityValue; i++)
	{
		derMike.setData(derMike.getPositionX(), derMike.getPositionY() +1, derMike.getWidth(), derMike.getHeight());
	
		

		if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derBoden.getData())) == true)
		{
			derMike.setData(derMike.getPositionX(), derMike.getPositionY()-1, derMike.getWidth(), derMike.getHeight());
			sprung = true;
			higher = false;
		}

		if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derStachel.getData())) == true)
		{
			derMike.setAlive(false);
		}
		if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derStachelII.getData())) == true)
		{
			derMike.setAlive(false);
		}
		if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derStachelIII.getData())) == true)
		{
			derMike.setAlive(false);
		}

		if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derBlock.getData())) == true)
		{
			derMike.setData(derMike.getPositionX(), derMike.getPositionY()-1, derMike.getWidth(), derMike.getHeight());
			sprung = true;
			higher = true;
		}
		if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derBlockII.getData())) == true)
		{
			derMike.setData(derMike.getPositionX(), derMike.getPositionY()-1, derMike.getWidth(), derMike.getHeight());
			sprung = true;
			higher = true;
		}
		if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derVorsprung.getData())) == true)
		{
			derMike.setData(derMike.getPositionX(), derMike.getPositionY()-1, derMike.getWidth(), derMike.getHeight());
			sprung = true;
			higher = true;
		}

		if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(dieMikeCoinI.getData())) == true)
		{
			coints++;
			dieMikeCoinI.setData(898,889,1,1);
		}
		if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(dieMikeCoinII.getData())) == true)
		{
			coints++;
			dieMikeCoinII.setData(898,889,1,1);
		}
		if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(dieMikeCoinIII.getData())) == true)
		{
			coints++;
			dieMikeCoinIII.setData(898,889,1,1);
		}

		if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(dasJetpack.getData())) == true)
		{
			if(fuel >= 3)
			{
				boost = true;
			}

			else
			{
				boost = false;
			}
			dasJetpack.setData(898,889,1,1);
		}

		if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(benzin.getData())) == true)
		{
			fuel++;
			benzin.setData(898,889,1,1);
		}

		if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derBoss.getData())) == true)
		{
			derMike.setAlive(false);
		}
	}
}

else
{

	if (derMike.getPositionY() <=  270 && derMike.getPositionY() >= 220 || derMike.getPositionY() <=  110 && derMike.getPositionY() > 30 && higher == true)
	{
		gravityValue =4;

		for(int i=0; i<=gravityValue; i++)
		{
			derMike.setData(derMike.getPositionX(), derMike.getPositionY() +1, derMike.getWidth(), derMike.getHeight());
		
			

			if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derBoden.getData())) == true)
			{
				derMike.setData(derMike.getPositionX(), derMike.getPositionY()-1, derMike.getWidth(), derMike.getHeight());
				sprung = true;
				higher = false;
			}

			if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derStachel.getData())) == true)
			{
				derMike.setAlive(false);
			}
			if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derStachelII.getData())) == true)
			{
				derMike.setAlive(false);
			}
			if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derStachelIII.getData())) == true)
			{
				derMike.setAlive(false);
			}

			if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derBlock.getData())) == true)
			{
				derMike.setData(derMike.getPositionX(), derMike.getPositionY()-1, derMike.getWidth(), derMike.getHeight());
				sprung = true;
				higher = true;
			}
			if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derBlockII.getData())) == true)
			{
				derMike.setData(derMike.getPositionX(), derMike.getPositionY()-1, derMike.getWidth(), derMike.getHeight());
				sprung = true;
				higher = true;
			}
			if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derVorsprung.getData())) == true)
			{
				derMike.setData(derMike.getPositionX(), derMike.getPositionY()-1, derMike.getWidth(), derMike.getHeight());
				sprung = true;
				higher = true;
			}

			if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(dieMikeCoinI.getData())) == true)
			{
				coints++;
				dieMikeCoinI.setData(898,889,1,1);
			}
			if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(dieMikeCoinII.getData())) == true)
			{
				coints++;
				dieMikeCoinII.setData(898,889,1,1);
			}
			if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(dieMikeCoinIII.getData())) == true)
			{
				coints++;
				dieMikeCoinIII.setData(898,889,1,1);
			}

			if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(dasJetpack.getData())) == true)
			{
				if(fuel >= 3)
				{
					boost = true;
				}

				else
				{
					boost = false;
				}
				dasJetpack.setData(898,889,1,1);
			}

			if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(benzin.getData())) == true)
			{
				fuel++;
				benzin.setData(898,889,1,1);
			}

			if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derBoss.getData())) == true)
			{
				derMike.setAlive(false);
			}
		}


	}

	else
	{


		if (derMike.getPositionY() <= 310 && derMike.getPositionY() > 270 || derMike.getPositionY() <= 150 && derMike.getPositionY() > 110 && higher == true)
		{
			gravityValue =5;

			for(int j=0; j<=gravityValue; j++)
			{
				derMike.setData(derMike.getPositionX(), derMike.getPositionY() +1, derMike.getWidth(), derMike.getHeight());

				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derBoden.getData())) == true)
				{
					derMike.setData(derMike.getPositionX(), derMike.getPositionY()-1, derMike.getWidth(), derMike.getHeight());
					sprung = true;
					higher = false;
				}

				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derStachel.getData())) == true)
				{
					derMike.setAlive(false);
				}
				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derStachelII.getData())) == true)
				{
					derMike.setAlive(false);
				}
				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derStachelIII.getData())) == true)
				{
					derMike.setAlive(false);
				}

				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derBlock.getData())) == true)
				{
					derMike.setData(derMike.getPositionX(), derMike.getPositionY()-1, derMike.getWidth(), derMike.getHeight());
					sprung = true;
					higher = true;
				}
				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derBlockII.getData())) == true)
				{
					derMike.setData(derMike.getPositionX(), derMike.getPositionY()-1, derMike.getWidth(), derMike.getHeight());
					sprung = true;
					higher = true;
				}
				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derVorsprung.getData())) == true)
				{
					derMike.setData(derMike.getPositionX(), derMike.getPositionY()-1, derMike.getWidth(), derMike.getHeight());
					sprung = true;
					higher = true;
				}

				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(dieMikeCoinI.getData())) == true)
				{
					coints++;
					dieMikeCoinI.setData(898,889,1,1);
				}
				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(dieMikeCoinII.getData())) == true)
				{
					coints++;
					dieMikeCoinII.setData(898,889,1,1);
				}
				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(dieMikeCoinIII.getData())) == true)
				{
					coints++;
					dieMikeCoinIII.setData(898,889,1,1);
				}

				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(dasJetpack.getData())) == true)
				{
					if(fuel >= 3)
					{
						boost = true;
					}

					else
					{
						boost = false;
					}
					dasJetpack.setData(898,889,1,1);
				}

				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(benzin.getData())) == true)
				{
					fuel++;
					benzin.setData(898,889,1,1);
				}

				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derBoss.getData())) == true)
				{
					derMike.setAlive(false);
				}
			}
		}

		else
		{
			gravityValue = 6;

			for(int j=0; j<=gravityValue; j++)
			{
				derMike.setData(derMike.getPositionX(), derMike.getPositionY() +1, derMike.getWidth(), derMike.getHeight());

				
				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derBoden.getData())) == true)
				{
					derMike.setData(derMike.getPositionX(), derMike.getPositionY()-1, derMike.getWidth(), derMike.getHeight());
					sprung = true;
					higher = false;
				}

				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derStachel.getData())) == true)
				{
					derMike.setAlive(false);
				}
				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derStachelII.getData())) == true)
				{
					derMike.setAlive(false);
				}
				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derStachelIII.getData())) == true)
				{
					derMike.setAlive(false);
				}

				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derBlock.getData())) == true)
				{
					derMike.setData(derMike.getPositionX(), derMike.getPositionY()-1, derMike.getWidth(), derMike.getHeight());
					sprung = true;
					higher = true;
				}
				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derBlockII.getData())) == true)
				{
					derMike.setData(derMike.getPositionX(), derMike.getPositionY()-1, derMike.getWidth(), derMike.getHeight());
					sprung = true;
					higher = true;
				}
				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derVorsprung.getData())) == true)
				{
					derMike.setData(derMike.getPositionX(), derMike.getPositionY()-1, derMike.getWidth(), derMike.getHeight());
					sprung = true;
					higher = true;
				}

				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(dieMikeCoinI.getData())) == true)
				{
					coints++;
					dieMikeCoinI.setData(898,889,1,1);
				}
				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(dieMikeCoinII.getData())) == true)
				{
					coints++;
					dieMikeCoinII.setData(898,889,1,1);
				}
				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(dieMikeCoinIII.getData())) == true)
				{
					coints++;
					dieMikeCoinIII.setData(898,889,1,1);
				}

				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(dasJetpack.getData())) == true)
				{
					if(fuel >= 3)
					{
						boost = true;
					}

					else
					{
						boost = false;
					}
					dasJetpack.setData(898,889,1,1);
				}

				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(benzin.getData())) == true)
				{
					fuel++;
					benzin.setData(898,889,1,1);
				}

				if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(derBoss.getData())) == true)
				{
					derMike.setAlive(false);
				}
			}			
		}	
	}
}
	SDL_BlitSurface(dieOberflaeche.getBackground(), NULL, dieOberflaeche.getAusgabe(),NULL);

}

void steuerung::eventRocket()
{
	for(int i=1;i<=4;i++)
	{
		dieRakete.setData(dieRakete.getPositionX()-1,dieRakete.getPositionY(),dieRakete.getWidth(), dieRakete.getHight());

		if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(dieRakete.getData())) == true)
		{
			derMike.setAlive(false);
		}
	}
}


void steuerung::reset()
{
	derMike.setData(15,340,74,71);

	dieRakete.setData(874, 360, 70, 65);

	derMike.setAlive(true);

	hitsDodged = 0;

	shot = false;

	boost = false;

	if(level == 4)
	{
		dasJetpack.setData(230,200,41,65);
	}



	dasProjektilI.setData(480,dasProjektilI.getPositionY(),dasProjektilI.getWidth(), dasProjektilI.getHight());
	dasProjektilII.setData(520,dasProjektilII.getPositionY(),dasProjektilIII.getWidth(), dasProjektilII.getHight());
	dasProjektilIII.setData(560,dasProjektilIII.getPositionY(),dasProjektilIII.getWidth(), dasProjektilIII.getHight());

	derBoss.setData(derBoss.getPositionX(), 0, derBoss.getWidth(), derBoss.getHight());


}


int steuerung::anleitung(SDLKey code , Uint8 druck)
{
	dieOberflaeche.setBackground("anleitung.bmp");
	
	if (druck == SDL_QUIT)
	{
		mode=3;
		//appRunning = false;
	}

	if (druck == SDL_KEYDOWN)
	{
		if (code == SDLK_ESCAPE)
		{
			mode = 0;
		}
	}

	SDL_BlitSurface(dieOberflaeche.getBackground(),NULL,dieOberflaeche.getAusgabe(),NULL);
	dieOberflaeche.darstellen();
	SDL_FreeSurface(dieOberflaeche.getBackground());
	return mode;
}


void steuerung::eventBoss()
{
	if(derMike.getPositionY() < 300 || shot == true)
	{
		for (int i =0; i<=5; i++)
		{
			dasProjektilI.setData(dasProjektilI.getPositionX()-1,dasProjektilI.getPositionY(),dasProjektilI.getWidth(), dasProjektilI.getHight());
			if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(dasProjektilI.getData())) == true)
			{
				derMike.setAlive(false);
			}
	

			dasProjektilII.setData(dasProjektilII.getPositionX()-1,dasProjektilII.getPositionY(),dasProjektilII.getWidth(), dasProjektilII.getHight());
			if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(dasProjektilII.getData())) == true)
			{
				derMike.setAlive(false);
			}

			dasProjektilIII.setData(dasProjektilIII.getPositionX()-1,dasProjektilIII.getPositionY(),dasProjektilIII.getWidth(), dasProjektilIII.getHight());
			if(checkKollision(kantenBerechnenF(derMike.getData()), kantenBerechnenO(dasProjektilIII.getData())) == true)
			{
				derMike.setAlive(false);
			}
		
			if(dasProjektilI.getPositionX() <= 0)
			{
				dasProjektilI.setData(480,dasProjektilI.getPositionY(), dasProjektilI.getWidth(),dasProjektilI.getHight());
				hitsDodged++;
			}

			if(dasProjektilII.getPositionX() <= 0)
			{
				dasProjektilII.setData(480,dasProjektilI.getPositionY(), dasProjektilI.getWidth(),dasProjektilI.getHight());
			}

			if(dasProjektilIII.getPositionX() <= 0)
			{
				dasProjektilIII.setData(480,dasProjektilI.getPositionY(), dasProjektilI.getWidth(),dasProjektilI.getHight());
			}
		}

		shot = true;
	}
}

void steuerung::init()
{
	derMike.setBild("figur.bmp");
	derMike.setBildR("figurR.bmp");
	derMike.setBildJ("figurJ.bmp");
	derMike.setBildJR("figurJR.bmp");

	dasJetpack.setBild("jetpack.bmp");

	derStachel.setBild("Stacheln.bmp");
	derStachelII.setBild("Stacheln.bmp");
	derStachelIII.setBild("Stacheln.bmp");

	derBlock.setBild("block.bmp");
	derBlockII.setBild("block.bmp");

	dieRakete.setBild("rocket.bmp");

	derBoss.setBild("boss.bmp");
	derBoss.setBildI("bossW.bmp");

	dasProjektilI.setBild("projektil.bmp");
	dasProjektilII.setBild("projektil.bmp");
	dasProjektilIII.setBild("projektil.bmp");

	dieMikeCoinI.setBild("mcoin.bmp");
	dieMikeCoinII.setBild("mcoin.bmp");
	dieMikeCoinIII.setBild("mcoin.bmp");

	benzin.setBild("benzin.bmp");

	dieOberflaeche.setBackgroundL("backgroundD.bmp");
	dieOberflaeche.setBackgroundW("backgroundF.bmp");

	

}

int steuerung::credits(SDLKey code, Uint8 druck)
{
	keystates = SDL_GetKeyState(NULL);
	

	if(screen == 1)
	{
		SDL_BlitSurface(dieOberflaeche.getBackgroundW(),NULL,dieOberflaeche.getAusgabe(), NULL);			
	}



	if (druck == SDL_QUIT)
	{
		//appRunning = false;
		mode=3;
	}

	if (druck == SDL_KEYDOWN)
	{
		
		switch(code)
		{
			case SDLK_ESCAPE:
				mode = 0;
				win = false;
			
				reset();

				loaded1 = false;
				loaded2 = false;
				loaded3 = false;
				loaded4 = false;

				level = 1;

				fuel = 0;
				break;
		
	
			case SDLK_RETURN:
		
				screen++;

				switch (screen)
				{
					

					case 2:
			
						SDL_BlitSurface(dieOberflaeche.getBackgroundL(),NULL,dieOberflaeche.getAusgabe(), NULL);

						break;

					case 3:
						mode = 0;
						screen = 1;
						break;
			
				
				}

				win = false;
			
				reset();

				loaded1 = false;
				loaded2 = false;
				loaded3 = false;
				loaded4 = false;

				level = 1;

				fuel = 0;

			break;
		}
	}


	dieOberflaeche.darstellen();

	SDL_Delay(200);

	return mode;
}


Mix_Music* steuerung::getSoundtrack()
{
	return soundtrack;
}

void steuerung::setSoundtrack()
{
	soundtrack = Mix_LoadMUS( "Guile_Theme_SNES.wav" );
}