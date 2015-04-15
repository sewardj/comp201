#include "model.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

// Constructor initializes the object
Model::Model() {
	// level options 
	words[0].push_back("WORK");
	words[0].push_back("PINK");
	words[0].push_back("PEN");
	words[0].push_back("TOE");
	words[0].push_back("SHOE");
	words[0].push_back("CAKE");
	words[1].push_back("IPHONE");
	words[1].push_back("POINT");
	words[1].push_back("APPLE");
	words[1].push_back("MARKER");
	words[1].push_back("CANDLE");
	words[1].push_back("CANADA");
	words[2].push_back("VEHICLE");
	words[2].push_back("PLASTIC");
	words[2].push_back("PICTURE");
	words[2].push_back("TELEVISION");
	words[2].push_back("COMPUTER");
	words[2].push_back("ORIGINAL");
	makeChoice(0);
	state = NEW_GAME;
}

// Destructor deletes dynamically allocated memory
Model::~Model() {
}

// Start a new game
void Model::makeChoice(int choice) {
	vector<string> wordList = words[choice];
	random_shuffle(wordList.begin(), wordList.end());
	theword = wordList[0];
	
	progress = string(theword.size(), '-');          // word guessed so far
	used = "";                            // letters already used
	wrong = 0;
	state = PLAYING;
	lastGuess = '\0';
}

bool Model::guessed() {
	return lastGuess != '\0';
}

// Did the last guess match the word?
bool Model::matched()
{
	return (theword.find(lastGuess) != string::npos);
}

// Make a guess and update progress
void Model::makeGuess(char letter) {
	lastGuess = letter;
	if (matched()) {
		for (int i = 0; i < theword.length(); i++) {
			if (theword[i] == lastGuess) {
				progress[i] = lastGuess;
			}
		}
	} else {
		if (used.find(lastGuess) == string::npos) {
			used = used + lastGuess;
			++wrong;
		}
	}
}

bool Model::lost() {
	return wrong == MAX_WRONG;
}

bool Model::gameOver() {
    return !((wrong < MAX_WRONG) && (progress != theword));
}

