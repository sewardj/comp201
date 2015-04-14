// Cassie, Julia, Adam, Oresti
// Hangman Final Project!!

using namespace std;
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <vector>
#include <string>


string theword;
string progress;
string used;
int choice;
int wrong;

char askguess(string usedletters); //tells the compiler of method askguess
bool match(char letter, string word);
bool playagain();


int main()
{

	// level options 

	vector<string> easywords;  // easy word bank
	easywords.push_back("WORK");
	easywords.push_back("PINK");
	easywords.push_back("PEN");
	easywords.push_back("TOE");
	easywords.push_back("SHOE");
	easywords.push_back("CAKE");

	vector<string> medwords;  // medium word bank
	medwords.push_back("IPHONE");
	medwords.push_back("POINT");
	medwords.push_back("APPLE");
	medwords.push_back("MARKER");
	medwords.push_back("CANDLE");
	medwords.push_back("CANADA");

	vector<string> hardwords;  // hard word bank
	hardwords.push_back("VEHICLE");
	hardwords.push_back("PLASTIC");
	hardwords.push_back("PICTURE");
	hardwords.push_back("TELEVISION");
	hardwords.push_back("COMPUTER");
	hardwords.push_back("ORIGINAL");




	cout << "Welcome to our hangman. Have Fun!\n";


	//game starts
	bool done = false;
	do
	{
		const int MAX_WRONG = 6;  // max number of wrong guesses=6
		cout << "Please choose a level." << endl;
		cout << "Choose 1 for Easy, 2 for Medium, or 3 for Hard: ";
		cin >> choice;

		if (choice == 1) {
			random_shuffle(easywords.begin(), easywords.end());
			theword = easywords[0];            // the easy word to guess
		}
		else if (choice == 2) {

			random_shuffle(medwords.begin(), medwords.end());
			theword = medwords[0];            // the medium word to guess
		}
		else if (choice == 3) {

			random_shuffle(hardwords.begin(), hardwords.end());
			theword = hardwords[0];            // the hard word to guess
		}
		else {
			
			cout << "You did not pick a valid choice. ";
			return 0;
		}
		progress = string(theword.size(), '-');          // word guessed so far
		used = "";                            // letters already used
		// loop for current word
		while ((wrong < MAX_WRONG) && (progress != theword))
		{
			cout << "\n\nYou have " << (MAX_WRONG - wrong) << " incorrect guesses left.\n";
			cout << "\nYou've used the following letters:\n" << used << endl;
			cout << "\nSo far, the word is:\n" << progress << endl;
			used += askguess(used);
		}

		if (wrong == MAX_WRONG)
		{
			cout << "\nYou ran out of guesses. You have been hanged!";
		}
		cout << "\nThe word was " << theword << endl;
	} while (playagain());
	return 0;
}
inline bool match(char letter, string word)
{
	return (word.find(letter) != string::npos);
}
char askguess(string usedletters)
{
	char guess;
	cout << "\n\nEnter your guess: ";
	cin >> guess;
	guess = toupper(guess); // all words have to be uppercase

	while (match(guess, used))
	{
		cout << "\nYou've already guessed " << guess << endl;
		cout << "Enter your guess: ";
		cin >> guess;
		guess = toupper(guess);
	}

	if (match(guess, theword))
	{
		cout << "That's right! " << guess << " is in the word.\n";
		// update and add letter to word
		for (int i = 0; i < theword.length(); i++)
			if (theword[i] == guess)
				progress[i] = guess;
	}

	else
	{
		cout << "The letter " << guess << " is not in the word. Sorry!\n";
		++wrong;
	}
	return guess;
}
bool playagain()
{
	char again;
	cout << "\n\nWould you like to play again? Choose y for yes or n for no. ";

	cin >> again;
	cin.clear();
	cin.ignore();
	again = toupper(again);

	return (again == 'Y');
}
