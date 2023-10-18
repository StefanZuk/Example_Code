#include "SDL.h"
#include "spieler.h"
#include <string>
#include <sstream>
#include "stdlib.h"


spieler::spieler()
{
	score=0;

	zeit=0;
}


void spieler::setName(std::string nameP)
{
	spielerName=nameP;
}

std::string spieler::getName()
{
	return spielerName;
}


void spieler::setScore(int scoreP)
{
	score=scoreP;
}

int spieler::getScore()
{
	return score;
}


void spieler::setZeit(int zeitP)
{
	zeit=zeitP;
}

int spieler::getZeit()
{
	return zeit;
}