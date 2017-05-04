#include "FBullCowGame.h"
#include <map>
#define TMap std::map

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
	return bGameIsWon;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess))	return EGuessStatus::Not_Isogram;
	else if (!IsLowerCase(Guess))	return EGuessStatus::Not_Lowercase;
	else if (Guess.length() != GetHiddenWordLength())	return EGuessStatus::Wrong_Length;
	else return EGuessStatus::OK;
}

FString FBullCowGame::GenerateIsogram()
{
	return FString();
}

FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;

	int32 WordLength = MyHiddenWord.length();

	for (int32 i = 0; i < WordLength; i++)
	{
		for (int32 j = 0; j < WordLength; j++)
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
	bGameIsWon = (BullCowCount.bulls == WordLength);

	return BullCowCount;
}


FBullCowGame::FBullCowGame(int32 MaxTries, FString HiddenWord)
{
	MyCurrentTry = 1;
	MyMaxtries = MaxTries;
	MyHiddenWord = HiddenWord;
	bGameIsWon = false;
}


FBullCowGame::~FBullCowGame()
{
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	if (Word.length() <= 1)	return true;

	TMap<char, bool> LetterSeen;

	for (auto Letter : Word)
	{
		Letter = tolower(Letter);

		if (LetterSeen[Letter]) return false;
		else LetterSeen[Letter] = true;
	}

	return true;
}

bool FBullCowGame::IsLowerCase(FString Word) const
{
	for (auto Letter : Word)
	{
		if (!islower(Letter)) return false;
		else return true;
	}
	return true;
}
