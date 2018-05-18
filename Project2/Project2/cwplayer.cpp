#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <Windows.h>
#include"Dictionary.h"
#include"Board.h"
#include"Player.h"

using namespace std;

void solvePuzzle()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	
	//dictionary creation and extraction
	Dictionary dict;
	Dictionary *dictA = &dict;
	bool errorOpeningFile;
	do
	{
		errorOpeningFile = false;
		cin.clear();
		string errorMessageFileInput = "That input is not valid! Try again\n";
		cout << "Dictionary file name ? ";
		cin >> dict.fileNameInput;
		if (cin.fail())
		{
			cin.ignore(1000000, '\n');
			SetConsoleTextAttribute(hConsole, 244);
			cout << errorMessageFileInput;
			SetConsoleTextAttribute(hConsole, 15);
			continue;
		}
		if (cin.eof())
		{
			cin.ignore(100, '\n');
			SetConsoleTextAttribute(hConsole, 244);
			cout << errorMessageFileInput;
			SetConsoleTextAttribute(hConsole, 15);
			continue;
		}
		if (!dict.loadToProgram()) errorOpeningFile = true;

	} while (cin.fail() || errorOpeningFile);


	fstream f;
	fstream *fA = &f;

	do
	{
		cin.clear();
		errorOpeningFile = false;
		string errorMessageFileInput = "That input is not valid! Try again\n";
		string errorMessageOpeningFile = "It was not possible to open the %s file";
		cout << "File name?\n";
		cin >> inputFile;
		if (cin.fail())
		{
			cin.ignore(1000000, '\n');
			SetConsoleTextAttribute(hConsole, 244);
			cout << errorMessageFileInput;
			SetConsoleTextAttribute(hConsole, 15);
			continue;
		}
		if (cin.eof())
		{
			cin.ignore(100, '\n');
			SetConsoleTextAttribute(hConsole, 244);
			cout << errorMessageFileInput;
			SetConsoleTextAttribute(hConsole, 15);
			continue;
		}
		f.open(inputFile);
		if (!f.is_open())
		{
			SetConsoleTextAttribute(hConsole, 244);
			printf(errorMessageOpeningFile.c_str(), inputFile.c_str());
			SetConsoleTextAttribute(hConsole, 15);
			errorOpeningFile = true;
		}
	} while (cin.fail() || errorOpeningFile);

	Board board;
	Board *boardA = &board;

	board.loadFromFile(fA);
	f.close();


}

int main()
{
	//PROGRAM LAYOUT
	cout << "			CROSSWORDS PLAYER\n";
	cout << "===========================================\n\n";
	cout << "INSTRUCTIONS:\n\n";
	cout << " Try to find out using the synonyms shown below the board,\nwhat are the hidden words in the white cells\n\n";
	while (true)
	{
		cout << "\n-------------------------------------------------------\n\n";
		cout << "OPTIONS:\n";
		cout << " 0 - Exit\n\n";
		cout << " 1 - Resolve crosswords\n";

		//error-proof input
		string chosenOption;
		while (true)
		{
			cout << "Option ? ";
			cin >> chosenOption;
			if (cin.eof())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				continue;
			}
			if ("0" == chosenOption) return 0;
			if ("1" == chosenOption) 
			{
				solvePuzzle();
				break;
			}
		}
	}

	return 0;
}