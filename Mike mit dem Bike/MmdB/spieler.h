#include "SDL.h"
#include <string>
#include <sstream>
#include "stdlib.h"
#include "SDL_ttf.h"


#ifndef spieler_h
#define spieler_h 

class spieler
{
	private:

	int score;
	std::string spielerName;
	int zeit;


    public:
	
	spieler();

	void setName(std::string nameP);
	void setScore(int scoreP);
	void setZeit(int zeitP);

	std::string getName();
	int getScore();
	int getZeit();
	

};
#endif