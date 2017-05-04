#pragma once

#include <iostream>
#include <string>
#include "FBullCowGame.h"

// Make syntax Unreal friendly
using FText = std::string;
using int32 = int;
 
void PrintIntro();
int32 ChooseHiddenWordLength();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

const FString HIDDEN_WORD = "plane";



FBullCowGame BCGame = FBullCowGame::FBullCowGame(HIDDEN_WORD);  // Instantiate a new game
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

// TODO: Implements in main game
int32 ChooseHiddenWordLength()
{
	int32 HiddenWordLength = 6;

	std::cout << "Do you want choose the hidden word length? (y / n)";
	FText Response = "";
	std::getline(std::cin, Response);

	if (Response[0] == 'y' || Response[0] == 'Y')
	{
		std::cout << "How many characters do you want for the hidden word?: ";
		std::cin >> HiddenWordLength;
	}

	return HiddenWordLength;
}


void PlayGame() {
	
	int32 MaxTries = BCGame.GetMaxTries();

	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries){
		FText Guess = GetValidGuess();

		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.bulls << "	|	Cows = " << BullCowCount.cows << std::endl;

		std::cout << "Your guess was: " << Guess << std::endl;
	}

	PrintGameSummary();
	
	return;
}


FText GetValidGuess()
{
	int32 CurrenTry = BCGame.GetCurrentTry();

	FText Guess = "";

	std::cout << "\n\n\nTry " << CurrenTry << " of " << BCGame.GetMaxTries() << ". ";
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
		int32 Tries = BCGame.GetCurrentTry();
		std::cout << "\nCongratulations! WELLDONE - YOU WIN!!!\n";
		std::cout << "\n	Hidden word: ";
		std::cout << "\n	Number of tries: " << (--Tries) << "\n\n";
		// TODO: it is giving to me one try more. The game should freeze the current try number if the game is won
	}
	else
	{
		std::cout << "Sorry! YOU LOSE!!!\n";
		std::cout << "	Better luck for the next time\n\n";
	}
}
