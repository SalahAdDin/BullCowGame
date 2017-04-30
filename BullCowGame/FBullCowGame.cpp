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


FBullCowGame::FBullCowGame(int32 MaxTries)
{
	MyCurrentTry = 0;
	MyMaxtries = MaxTries;
}


FBullCowGame::~FBullCowGame()
{
}