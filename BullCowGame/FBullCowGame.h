#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 bulls = 0;
	int32 cows = 0;
};

enum class EGuessStatus
{
	Invalid,
	OK, 
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

class FBullCowGame
{
public:

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;

	void reset(); // TODO: Make a more rich return value.
	EGuessStatus CheckGuessValidity(FString Guess) const; // TODO: Make a more rich return value.
	FString GenerateIsogram();

	FBullCowCount SubmitGuess(FString Guess);

	FBullCowGame(int32 MaxTries, FString HiddenWord);
	~FBullCowGame();

private:
	int32 MyCurrentTry;
	int32 MyMaxtries;
	FString MyHiddenWord;
};
