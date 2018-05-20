#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <Windows.h>
#include <time.h>

using namespace std; 

class player
{
private:

	string name;
	double timeSpent;
	int NumberOfAlternativeClues;

public:
	player();
	~player();
	
	void setName(string playerName);

	//void StartTime();

	//void FinishTime();

	void OneMoreClue();

	void StartCountingClues();

	void SaveInformation(string inputFile);

	void setTime(double seconds_since_start);
};