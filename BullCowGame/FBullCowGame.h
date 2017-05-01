#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 bulls = 0;
	int32 cows = 0;
};

class FBullCowGame
{
public:

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void reset(); // TODO: Make a more rich return value.
	bool CheckGuessValidity(FString); // TODO: Make a more rich return value.
	FString GenerateIsogram();

	FBullCowCount SubmitGuess(FString);

	FBullCowGame(int32 MaxTries, FString HiddenWord);
	~FBullCowGame();

private:
	int32 MyCurrentTry;
	int32 MyMaxtries;
	FString MyHiddenWord;
};
