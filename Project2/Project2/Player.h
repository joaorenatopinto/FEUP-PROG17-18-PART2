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
public:
	player();
	~player();
	
	void setName(string playerName);
};

