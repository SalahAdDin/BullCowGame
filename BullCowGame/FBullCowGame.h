#pragma once
#include <string>

using FString = std::string;
using int32 = int;

class FBullCowGame
{
public:

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	bool IsGameWon() const;

	void reset(); // TODO: Make a more rich return value.
	bool CheckGuessValidity(FString); // TODO: Make a more rich return value.
	FString GenerateIsogram();


	FBullCowGame(int32 MaxTries);
	~FBullCowGame();

private:
	int32 MyCurrentTry;
	int32 MyMaxtries;

};
