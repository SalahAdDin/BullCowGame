#include "FBullCowGame.h"

void FBullCowGame::reset()
{
}

int32 FBullCowGame::GetMaxTries() const
{
	return MyMaxtries;
}

int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}

FString FBullCowGame::GenerateIsogram()
{
	return FString();
}

FBullCowCount FBullCowGame::SubmitGuess(FString)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;

	for (int32 i = 0; i < MyHiddenWord.length(); i++)
	{
		for (int32 j = 0; j < MyHiddenWord.length(); j++)
		{
			if (MyHiddenWord[i])
			{

			}
		}
	}

	return BullCowCount;
}


FBullCowGame::FBullCowGame(int32 MaxTries, FString HiddenWord)
{
	MyCurrentTry = 1;
	MyMaxtries = MaxTries;
	MyHiddenWord = HiddenWord;
}


FBullCowGame::~FBullCowGame()
{
}