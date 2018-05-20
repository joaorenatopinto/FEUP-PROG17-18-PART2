#include"Dictionary.h"
#include"Board.h"
#include"player.h"


using namespace std;
//
bool allWordsValidity(Board *boardP, Dictionary *dictP)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	vector<string> verticalWords = boardP->verifyVertical();
	vector<string> horizontalWords = boardP->verifyHorizontal();
	string errorMessageHeadline = "\nThe word %s is not a valid word in the dictionary\n";

	for (unsigned int i = 0; i < verticalWords.size(); i++)
	{
		if (!dictP->headlineExists(verticalWords[i]))
		{
			SetConsoleTextAttribute(hConsole, 244);
			printf(errorMessageHeadline.c_str(), verticalWords[i].c_str());
			SetConsoleTextAttribute(hConsole, 15);
			return false;
		}
	}
	for (unsigned int i = 0; i < horizontalWords.size(); i++)
	{
		if (!dictP->headlineExists(horizontalWords[i]))
		{
			SetConsoleTextAttribute(hConsole, 244);
			printf(errorMessageHeadline.c_str(), horizontalWords[i].c_str());
			SetConsoleTextAttribute(hConsole, 15);
			return false;
		}
	}
	return true;
}

bool finishingCreate(Board *boardP, Dictionary *dictP)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	bool finishedBoard, errorInput;

	do
	{
		string errorMessageResume = "\nThat is not a valid answer to this question! Try again\n";
		errorInput = false;
		cout << "Is your board finished (1) or you will continue later(0) ?\n\tAnswer [1 or 0] -> ";
		cin >> finishedBoard;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(10000, '\n');
			SetConsoleTextAttribute(hConsole, 244);
			cout << errorMessageResume;
			SetConsoleTextAttribute(hConsole, 15);
			errorInput = true;
		}

		if (cin.eof())
		{
			cin.clear();
			cin.ignore(10000, '\n');
			errorInput = true;
			SetConsoleTextAttribute(hConsole, 244);
			cout << errorMessageResume;
			SetConsoleTextAttribute(hConsole, 15);
		}
	} while (errorInput);

	if (finishedBoard)
	{
		boardP->hashtagFill();
		bool validity = allWordsValidity(boardP, dictP);
		if (validity)
		{
			boardP->extraction(dictP->fileNameInput);
		}
		else
		{
			bool finishExtraction;
			do
			{
				string errorMessageResume = "\nThat is not a valid answer to this question! Try again\n";
				errorInput = false;

				cout << "Do you want to:\n\t finish with the wrong words (1)\n\t to replace the wrong words (0)\n\t\tAnswer -> ";
				cin >> finishExtraction;

				if (cin.fail())
				{
					cin.clear();
					cin.ignore(10000, '\n');
					SetConsoleTextAttribute(hConsole, 244);
					cout << errorMessageResume;
					SetConsoleTextAttribute(hConsole, 15);
					errorInput = true;
				}

				if (cin.eof())
				{
					cin.clear();
					cin.ignore(10000, '\n');
					errorInput = true;
					SetConsoleTextAttribute(hConsole, 244);
					cout << errorMessageResume;
					SetConsoleTextAttribute(hConsole, 15);
				}
			} while (errorInput);

			if (finishExtraction)
			{
				boardP->extraction(dictP->fileNameInput);
			}
			else return false;
		}

	}
	else
	{
		boardP->extraction(dictP->fileNameInput);
	}
	return true;
}

bool finishingCreate(Board *boardP, Dictionary *dictP, string inputFile)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	bool finishedBoard, errorInput;

	do
	{
		string errorMessageResume = "\nThat is not a valid answer to this question! Try again\n";
		errorInput = false;
		cout << "Is your board finished (1) or you will continue later(0) ?\n\tAnswer [1 or 0] -> ";
		cin >> finishedBoard;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(10000, '\n');
			SetConsoleTextAttribute(hConsole, 244);
			cout << errorMessageResume;
			SetConsoleTextAttribute(hConsole, 15);
			errorInput = true;
		}

		if (cin.eof())
		{
			cin.clear();
			cin.ignore(10000, '\n');
			errorInput = true;
			SetConsoleTextAttribute(hConsole, 244);
			cout << errorMessageResume;
			SetConsoleTextAttribute(hConsole, 15);
		}
	} while (errorInput);

	if (finishedBoard)
	{
		boardP->hashtagFill();
		bool validity = allWordsValidity(boardP, dictP);
		//cout << "\nThe extraction will continue\n";
		boardP->reExtraction(dictP->fileNameInput, inputFile);

	}
	else
	{
		bool finishExtraction;
		do
		{
			string errorMessageResume = "\nThat is not a valid answer to this question! Try again\n";
			errorInput = false;

			cout << "Do you want to:\n\t finish with the wrong words (1)\n\t to replace the wrong words (0)\n\t\tAnswer -> ";
			cin >> finishExtraction;

			if (cin.fail())
			{
				cin.clear();
				cin.ignore(10000, '\n');
				SetConsoleTextAttribute(hConsole, 244);
				cout << errorMessageResume;
				SetConsoleTextAttribute(hConsole, 15);
				errorInput = true;
			}

			if (cin.eof())
			{
				cin.clear();
				cin.ignore(10000, '\n');
				errorInput = true;
				SetConsoleTextAttribute(hConsole, 244);
				cout << errorMessageResume;
				SetConsoleTextAttribute(hConsole, 15);
			}
		} while (errorInput);

		if (finishExtraction)
		{
			boardP->reExtraction(dictP->fileNameInput, inputFile);
		}
		else return false;
	}
	{
		boardP->reExtraction(dictP->fileNameInput, inputFile);
	}
}

void helpInsertWord(string position, Board *boardP, Dictionary *dictP)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	bool repeatNoMatchingWords = true;
	while (repeatNoMatchingWords)
	{
		repeatNoMatchingWords = false;
		string wordToCreate;
		string errorMessageLength = "A word with so many letters don't fit!\n\nIf the help is no longer needed, press CTRL-Z";
		string errorMessageInput = "Only a numerical value is valid in here! Try again";
		string errorMessageBoolInput = "Only a 0 or a 1 is a valid option here! Try again";
		string returnMessage = "You chose to leave the help!";
		string warningMessageNoWords = "I'm sorry but no words were found that match the place you chose...\nDo you want to try again?\n";
		string errorInputWord = "You miswrote the word you chose!\nTry Again: ";
		bool errorInWordSize, errorInput;
		//input number of letters, input error robust (checks for space in the board and the right input in first question) and creates word and checks for space
		do
		{
			//inicialize flags
			errorInWordSize = false;
			errorInput = false;
			SetConsoleTextAttribute(hConsole, 15);
			//size of the word
			cout << "Insert the number of letters you want the word to have (CTRL-Z to leave the help) : ";
			int lettersNumber; cin >> lettersNumber;
			SetConsoleTextAttribute(hConsole, 244);
			if (cin.eof())
			{
				cin.clear();
				cout << returnMessage;
				SetConsoleTextAttribute(hConsole, 15);
				return;
			}
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000000, '\n');
				cout << errorMessageInput;
				SetConsoleTextAttribute(hConsole, 15);
				errorInput = true;
				continue;
			}

			SetConsoleTextAttribute(hConsole, 15);
			//word creation with the asked size
			for (int i = 0; i < lettersNumber; i++)
				wordToCreate += "?";
			//is there any space available?
			if (!boardP->checkSpace4Word(wordToCreate, position)) errorInWordSize = true;
		} while (errorInput || errorInWordSize);

		boardP->getLettersRight(wordToCreate, position);
		vector<string> resultWord = dictP->matchingWords(wordToCreate);

		if (resultWord.size() == 0)
		{
			//waring message
			SetConsoleTextAttribute(hConsole, 244);
			cout << warningMessageNoWords;
			SetConsoleTextAttribute(hConsole, 15);
			//choose what to do
			bool repeat;
			cout << "0 - Finish help\n1 - Try again\n\tAnswer -> ";
			cin >> repeat;
			//input error robustness
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(1000000, '\n');
				SetConsoleTextAttribute(hConsole, 244);
				cout << errorMessageBoolInput;
				SetConsoleTextAttribute(hConsole, 15);
				cout << "\n\tAnswer -> ";
				cin >> repeat;
			}
			//repeat the funciton
			if (repeat)
			{
				repeatNoMatchingWords = true; continue;
			}
			//leave the function
			else if (!repeat)
			{
				cout << returnMessage; return;
			}
		}
		else {
			//show the content of the vector with the resulting words
			cout << endl;
			for (unsigned int i = 0; i < resultWord.size(); i++)
				cout << "\t" << resultWord[i];
			cout << "\n\nChoose one of them to add to the board [CTRL-Z if you want to cancel help]: ";
			bool wordMatchesVector;
			string answer;
			do
			{
				cin.clear();
				wordMatchesVector = false;
				cin >> answer;
				if (cin.eof())
				{
					cin.clear(); cout << returnMessage;  return;
				}
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1000000, '\n');
					SetConsoleTextAttribute(hConsole, 244);
					cout << errorInputWord;
					SetConsoleTextAttribute(hConsole, 15);
					continue;
				}

				transform(answer.begin(), answer.end(), answer.begin(), ::toupper); //upper case
				for (unsigned int i = 0; i < resultWord.size(); i++)
					if (resultWord[i] == answer)
					{	//searches for the word in the vector, because all the checking was done before 
						wordMatchesVector = true;	//and a mistaken word here would break the "security" of the board
						break;
					}

			} while (cin.fail() || !wordMatchesVector);
			boardP->addWord(answer, position);
		}
	}
}
//
bool checkValidity(Dictionary *dictP, Board *boardP, string word, string position)
{
	//check the existance of the word
	if (!dictP->headlineExists(word)) return false;

	if (!boardP->unusedWordGrid(word)) return false;
	if (!boardP->checkSpace4WordGrid(word, position)) return false;
	return true;
}

void positionSynonymsFill(map<string, string> &positionSynonyms, Board* boardP, Dictionary* dictP)
{
	positionSynonyms = boardP->positionWords(); //fill the map with the position and the roght word

	map<string, string>::iterator it = positionSynonyms.begin(); //beginning of the map

	for (it; it != positionSynonyms.end(); it++) //switch every right word by a synonym of itself
	{
		it->second = dictP->synonymsWord(it->second);
	}
}

void synonymsShow(map<string, string> positionSynonyms)
{
	map<string, string>::iterator it;
	it = positionSynonyms.begin();
	cout << "\n\tHORIZONTAL:";
	for (it; it != positionSynonyms.end(); it++)
	{
		if (it->first[2] == 'H' || it->first[2] == 'h')
		{
			cout << "\n " << it->first[0] << it->first[1] << " - " << it->second;
		}
	}

	it = positionSynonyms.begin();
	cout << "\n\n\tVERTICAL:";
	for (it; it != positionSynonyms.end(); it++)
	{
		if (it->first[2] == 'V' || it->first[2] == 'v')
		{
			cout << "\n " << it->first[0] << it->first[1] << " - " << it->second;
		}
	}
	cout << endl << endl;
}

void synonymChange(map<string, string> &positionSynonyms, string position, Board* boardP, Dictionary* dictP)
{
	string word = boardP->wordInPosition(position); //right word to go to dictionary
	string newSynonym; //substitute
	map<string, string>::iterator it = positionSynonyms.find(position);
	string oldSynonym = it->second;
	do
	{
		newSynonym = dictP->synonymsWord(word);
	} while (newSynonym == oldSynonym);

	positionSynonyms[position] = newSynonym;
}

//void clues(Dictionary *dictP, Board *boardP, map <string, string> keySynonym) {
//
//}

void solvePuzzle()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	string inputFile;
	//dictionary creation and extraction
	Dictionary dict;
	Dictionary *dictA = &dict;
	bool errorOpeningFile;
	//vector<string> wordsplaced;
	//map <string, string> keySynonym;
	//map <string, string> WordsPlacedByPlayer;
	map<string, string> positionSynonyms;

	fstream f;
	fstream *fA = &f;

	do
	{
		cin.clear();
		errorOpeningFile = false;
		string errorMessageFileInput = "That input is not valid! Try again\n";
		string errorMessageOpeningFile = "It was not possible to open the %s file";
		cout << "File name? ";
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

	getline(f, dict.fileNameInput);
	dict.loadToProgram();

	board.loadFromFileGrid(fA);
	f.close(); 

	//loop to fill in the board
	string position, word;
	
	//funçao para dar fill do map dos sinonimos
	positionSynonymsFill(positionSynonyms, boardA, dictA);


	player Player;
	player *PlayerA = &Player; 
	string playerName; 
	cout << "Enter your player name: ";
	cin >> playerName; // Get the name of the player
	Player.StartTime(); // Start counting the itme since the player is playing
	Player.setName(playerName); // Setting the name on the player on the classe Player
	Player.StartCountingClues();

	while (!board.finishedGrid())
	{
		board.grid(); //show the board
		synonymsShow(positionSynonyms);			  //the user choose what to do


		cout << "Position ( LCD / CTRL-Z = stop ) ? "; cin >> position; //<======================= tornar mais robusto
		if (cin.eof())
		{
			cin.clear();
			bool finishBoard = finishingCreate(boardA, dictA);
			if (finishBoard) break;
			else continue;
		}

		cout << "Word ( - = remove / ? = help ) . ? "; cin >> word;
		transform(word.begin(), word.end(), word.begin(), ::toupper); //upper case the word

		if (cin.eof()) {
			cin.clear();
			cin.ignore(10000, '\n');
			SetConsoleTextAttribute(hConsole, 244);
			cout << "That is not a valid answer!";
			SetConsoleTextAttribute(hConsole, 15);
			continue;
		}
																	  //check if position input is correct
		if (!board.validPosition(position))
		{
			SetConsoleTextAttribute(hConsole, 244);
			cout << "That position is not valid... Try Again!\n";
			SetConsoleTextAttribute(hConsole, 15);
		}
		//to remove a word
		else if ("-" == word)
		{
			board.removeWordGrid(position);
		}
		//to help the user
		else if ("?" == word)
		{
			synonymChange(positionSynonyms, position, boardA, dictA);
			Player.OneMoreClue();
		}
		//to add the respective word
		else if (checkValidity(dictA, boardA, word, position)) 
		{
			board.addWordGrid(word, position);
		}

	}
	board.grid();
	Player.FinishTime();
	cout << "CONGRATULATIONS! YOU WON!";//<=======================
	Player.SaveInformation(inputFile);
}
//
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
		cout << " 0 - Exit\n";
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