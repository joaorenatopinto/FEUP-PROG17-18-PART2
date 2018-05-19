#include "player.h"



player::player()
{
}

player::~player()
{
}

void player::setName(string playerName)
{
	playerName = name;
}

void player::StartTime() {
	time_t start = time(0);
}

double player::FinishTime() {
	double seconds_since_start = difftime(time(0), start);
	return seconds_since_start;
}

void player::OneMoreClue() {
	NumberOfAlternativeClues += 1;
}

void player::SaveInformation() {

}