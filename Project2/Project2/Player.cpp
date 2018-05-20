#include "player.h"



player::player()
{
}

player::~player()
{
}

void player::setName(string playerName)
{
	name= playerName;
}

void player::StartTime() {
	time_t start = time(0);
}

void player::StartCountingClues() {
	NumberOfAlternativeClues = 0;
}

void player::FinishTime() {
	int seconds_since_start = difftime(time(0), start);
}

void player::OneMoreClue() {
	NumberOfAlternativeClues = NumberOfAlternativeClues + 1;
}

void player::SaveInformation(string inputFile) {//b017.txt
	string FileNameOutPut;
	FileNameOutPut = inputFile.erase(4, 4);
	FileNameOutPut = FileNameOutPut.append("_p.txt");
	ofstream Output(FileNameOutPut);

	Output << "The player " << name << " spent " << seconds_since_start << " seconds and asked for " << NumberOfAlternativeClues << " alternative clues.\n";
}