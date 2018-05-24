#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <Windows.h>
#include <time.h>


class player
{
private:

	std::string name;
	double timeSpent;
	int NumberOfAlternativeClues;

public:
	player();
	~player();
	
	void setName(std::string playerName);

	void OneMoreClue();

	void StartCountingClues();

	void SaveInformation(std::string inputFile);

	void setTime(double seconds_since_start);
};