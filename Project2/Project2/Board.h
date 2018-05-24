#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <Windows.h>
#include <cstdlib>

class Board
{
private:
	unsigned int lines, columns; //number of lines and columns
	std::vector <std::vector <char> > layout; //bigger vector "lines", smaller vectors are columns
	std::vector <char> newEmpty; //needed to fill the vector
	std::map <std::string, std::string> positionWordsPlaced; //to handle add and remove words, check on repeated words and output/input for/from files
	std::map <std::string, std::string> positionWordsPlacedGrid; //handle the cwplayer grid
	
public:
	//constructor
	Board();
	//argument constructor
	Board(unsigned int lines, unsigned int columns);
	//destructor
	~Board();
	//add word in vertical direction
	void addVertical(std::string word, int line, int column);
	//add word in horizontal direction
	void addHorizontal(std::string word, int line, int column);
	//checks for words that are crossed with the ones being removed
	bool crossedWordsVertical(unsigned int column, unsigned int line);
	bool crossedWordsHorizontal(unsigned int column, unsigned int line);

	//print name of dictionary, board and position-word in file
	void printInFile(std::fstream *f, std::string fileName);

	//load the information from the file on the program
	void loadFromFile(std::fstream *f);
	
	//fill the board with points (beginning)
	void pointFill();

	//prints the vector of the board in the console
	void show();

	//converts char ascii code to lines/columns position
	int whichLine(std::string position);
	int whichColumn(std::string position);

	//does primitive job before sending to the right adding
	void addWord(std::string word, std::string position);

	//primitive job before actually removing
	void removeWord(std::string position);

	//sees if there is space for the word
	bool checkSpace4Word(std::string word, std::string position);

	//sees if the word was already used
	bool unusedWord(std::string word);

	//sees if the position is valid
	bool validPosition(std::string position);

	//when helping, searches in the board for letters in the middle
	void getLettersRight(std::string &word, std::string position);

	//final validation
	std::vector<std::string> verifyHorizontal();
	std::vector<std::string> verifyVertical();

	//info extraction
	void extraction(std::string dictFile);
	void reExtraction(std::string dictFile, std::string outputFile);

	//fill the remaining . in the end of the creation of the file
	void hashtagFill();

	//player board
	void grid();

	//player addiction of the words
	void addVerticalGrid(std::string word, int line, int column);
	void addHorizontalGrid(std::string word, int line, int column);
	//1st add of the "words" in the board and normal add
	void addWord1stGrid(std::string word, std::string position);
	void addWordGrid(std::string word, std::string position);

	//load from file to player program
	void loadFromFileGrid(std::fstream *f);

	//used word in the player program
	bool unusedWordGrid(std::string word);

	//checks for space in the player program
	bool checkSpace4WordGrid(std::string word, std::string position);

	//remove word in player grid
	void removeWordGrid(std::string position);
	void removeVerticalGrid(int line, int column);
	void removeHorizontalGrid(int line, int column);

	//verification of finishing game
	bool finishedGrid();

	//returns the map with position and right word
	std::map<std::string, std::string> positionWords();

	//returns the word in the position asked
	std::string wordInPosition(std::string position);

	//reset the board to every position with '.'
	void boardReset();

	//checks if position exists
	bool checkPosition(std::string position);
};