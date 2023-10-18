#include "SDL.h"
#include "SDL_ttf.h"
#include "SDL_mixer.h"
#include <string>
#include <sstream>
#include "stdlib.h"

#ifndef steuerung_h
#define steuerung_h 

class steuerung
{
	private:

	SDL_Event event;

	int mode;
	int level;

	int menuVar;

	int screen;

	Uint8 *keystates;

	int gravityValue;

	bool resettimer;

	bool win;

	int speedV;
	int speedH;

	bool sprung;
	bool collision;

	bool higher;

	int highscore;
	int score;

	SDL_Rect positionF;
	SDL_Rect positionO;


	int framesps;

	int frame;

	bool shot;

	int loaded1;
	int loaded2;
	int loaded3;
	int loaded4;

	int coints;

	int fuel;

	bool boost;

	Mix_Music *soundtrack;
	
	void quit();


    public:
	
	steuerung();

	void selectMenu();
	
	//void selectGame();

	int getMode();

	void createLevel();

	int anleitung(SDLKey code , Uint8 druck);
	int credits(SDLKey code, Uint8 druck);

	void setKeyStates();

	Uint8 *getKeyStates();

	void checkCollision();
	void setKanten(SDL_Rect kantenP);
	
	int getHighscore();

	int hitsDodged;

	int handleEventG(SDLKey code, Uint8 druck);
	int handleEventM(SDLKey code, Uint8 druck);


	void setScore(int scoreP);
	int getScore();

	SDL_Rect kantenBerechnenF(SDL_Rect datenF);
	SDL_Rect kantenBerechnenO(SDL_Rect datenO);

	bool checkKollision(SDL_Rect figur, SDL_Rect objekt);

	/*bool checkKollisionR(SDL_Rect figur, SDL_Rect objekt, int typP);
	bool checkKollisionL(SDL_Rect figur, SDL_Rect objekt, int typP);
	bool checkKollisionO(SDL_Rect figur, SDL_Rect objekt, int typP);
	bool checkKollisionU(SDL_Rect figur, SDL_Rect objekt, int typP);*/

	void gravity();

	void eventRocket();

	void eventBoss();

	void reset();

	void init();

	Mix_Music *getSoundtrack();

	void setSoundtrack();
};
#endif