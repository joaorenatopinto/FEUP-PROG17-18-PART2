#include "player.h"



player::player()
{
}

player::~player()
{
}

void player::setName(string playerName)
{
	name= playerName;//set player name
}

void player::setTime(double seconds_since_start) {
	timeSpent = seconds_since_start; // time spent playing
}

void player::StartCountingClues() {
	NumberOfAlternativeClues = 0;//start counting the number of clues asked form 0
}

void player::OneMoreClue() {
	NumberOfAlternativeClues = NumberOfAlternativeClues + 1; // add 1 to NumberOfAlternativeClues
}

void player::SaveInformation(string inputFile) { //saving the information of the player on text file
	string FileNameOutPut;
	FileNameOutPut = inputFile.erase(4, 4);
	FileNameOutPut = FileNameOutPut.append("_p.txt");
	ofstream Output(FileNameOutPut);

	Output << "The player " << name << " spent " << timeSpent << " seconds and asked for " << NumberOfAlternativeClues << " alternative clues.\n";
}