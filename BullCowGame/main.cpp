#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

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
	std::cout << "Wellcome to Bulls and Cows, a fun word game.\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of?\n" ;

	// TODO: Verify why the next games all time are win!

	return;
}


void PlayGame() {
	
	int32 MaxTries = BCGame.GetMaxTries();

	// Repeat the guess back to them
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries){
		FText Guess = GetValidGuess(); // TODO: Make a loop checking validy

		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.bulls << std::endl;
		std::cout << "Cows = " << BullCowCount.cows << std::endl;

		std::cout << "Your guess was: " << Guess << std::endl;
	}

	PrintGameSummary();
	
	return;
}


FText GetValidGuess()
{
	int32 CurrenTry = BCGame.GetCurrentTry();

	FText Guess = "";

	std::cout << "\n\n\nTry " << CurrenTry << ". ";
	EGuessStatus Status = EGuessStatus::Invalid;

	do
	{
		std::cout << "Enter your guess: ";
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Not_Isogram:
			std::cout << "Not isogram. \nPlease enter a valid isogram(not repeat letters) word.\n\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Not lowercase. \nPlease enter all lowercase letters word.\n\n";
			break;
		case EGuessStatus::Wrong_Length:
			std::cout << "Wrong length. \nPlease enter a " << BCGame.GetHiddenWordLength() << " letter word.\n\n";
			break;
		default:
			break;
		}

	} while (Status != EGuessStatus::OK);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y / n)";
	FText Response = "";
	std::getline(std::cin, Response);
	std::cout << "\n\n\n\n";

	return (Response[0] == 'y' || Response[0] == 'Y');
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "\nCongratulations! WELLDONE - YOU WIN!!!\n";
		std::cout << "\n	Hidden word: ";
		std::cout << "\n	Number of tries: " << BCGame.GetCurrentTry() << "\n\n";
		// TODO: it is giving to me one try more.
	}
	else
	{
		std::cout << "Sorry! YOU LOSE!!!\n";
		std::cout << "	Better luck for the next time\n\n";
	}
}
