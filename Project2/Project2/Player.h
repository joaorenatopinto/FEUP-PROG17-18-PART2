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
	time_t start;
	double seconds_since_start;
	int NumberOfAlternativeClues;

public:
	player();
	~player();
	
	void setName(string playerName);

	void StartTime();

	double FinishTime();

	void OneMoreClue();

	void SaveInformation();
};