#ifndef _MODEL_H
#define _MODEL_H

#include <string>
#include <vector>

enum State { NEW_GAME, PLAYING };

const int MAX_WRONG = 6;

// The model manages the state of the game
class Model {
public:
    // Constructor (instantiates object)
    Model();
    // Destructor deletes all dynamically allocated stuff
    ~Model();
    // Is the game over?
    bool gameOver();
    // The secret
	std::string theword;
	// What we see
	std::string progress;
	// The letters we've guessed so far
	std::string used;
	std::vector<std::string> words[3];
	char lastGuess;
	
	State state;
	int wrong;
	void makeChoice(int choice);
	bool lost();
	bool matched();
	void makeGuess(char guess);
	bool guessed();
};

#endif
