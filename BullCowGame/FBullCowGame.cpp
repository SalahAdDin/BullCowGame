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

int32 FBullCowGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (false)
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false)
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength())
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}
}

FString FBullCowGame::GenerateIsogram()
{
	return FString();
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;

	for (int32 i = 0; i < MyHiddenWord.length(); i++)
	{
		for (int32 j = 0; j < MyHiddenWord.length(); j++)
		{
			if (Guess[j] == MyHiddenWord[i])
			{
				if (i == j)
				{
					BullCowCount.bulls++;
				}
				else
				{
					BullCowCount.cows++;
				}
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