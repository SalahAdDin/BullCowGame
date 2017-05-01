#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

constexpr int32 MAX_TRIES = 8;
const FString HIDDEN_WORD = "planet";



FBullCowGame BCGame = FBullCowGame::FBullCowGame(MAX_TRIES, HIDDEN_WORD);  // Instantiate a new game
// Why have to use a double function calling? 


int main()
{	
	do
	{
		PrintIntro();
		PlayGame();
	} while (AskToPlayAgain());

	std::cout << std::endl;
	return 0;
}


void PrintIntro() {
	// Introduce the game
	constexpr int WORD_LENGHT = 5;
	std::cout << "Wellcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGHT << " letter isogram I'm thinking of?\n" << std::endl;

	return;
}


void PlayGame() {
	
	int32 MaxTries = BCGame.GetMaxTries();

	// Repeat the guess back to them
	for (int i = 0; i < MaxTries; i++){
		FText Guess = GetGuess(); // TODO: Make a loop checking validy
		std::cout << "Your guess was: " << Guess << std::endl;
	}
}


FText GetGuess()
{
	int32 CurrenTry = BCGame.GetCurrentTry();
	// Get a guess from the player
	std::cout << "Try " << CurrenTry << " ";
	FText Guess = "";
	std::cout << "Enter your guess: ";
	std::getline(std::cin, Guess);

	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y / n)";
	FText Response = "";
	std::getline(std::cin, Response);

	return (Response[0] == 'y' || Response[0] == 'Y');
}
