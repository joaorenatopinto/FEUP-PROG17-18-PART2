#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <Windows.h> 
#include <ctime>
#include <stdlib.h>


class Dictionary
{
private:
	std::map <std::string, std::vector <std::string> > wordSynonyms; //map with the word and the vector with synonyms
	std::ifstream f; //open the file

public:
	//constructor
	Dictionary();

	//destructor
	~Dictionary();

	//name of input file
	std::string fileNameInput;

	//returns true if the words exists in the dictionary map
	bool isHeadline(std::string line);

	//separates the word from the line of the dictionary
	std::string singleWord(std::string &Line); //retirar a proxima palavra da linha

	//returns true if the line is valid
	bool validLine(std::string Line);

	//returns true if the word and the wildcard mathces
	bool wildcardMatch(const char *str, const char *strWild);

	//load the dictionary from the file to the program
	bool loadToProgram();

	//sees if the word that the user tried to input belongs to the dictionary
	bool headlineExists(std::string word);

	//searches for matching words, and return a 10-elements-maximum-size vector
	std::vector<std::string> matchingWords(std::string wildCard);

	//returns a synonym of the word asked
	std::string synonymsWord(std::string word);
};

