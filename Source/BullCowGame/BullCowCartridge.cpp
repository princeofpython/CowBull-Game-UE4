// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "HiddenWordsList.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    // PrintLine(TEXT("%i"), GetValidWords(Words).Num());
    Isograms = GetValidWords(Words);
    InitGame();
    // PrintLine(TEXT("%i"),FMath::RandRange(1,100)); 
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    if (bGameOver)
    {
        ClearScreen();
        InitGame();
    }
    else
    {
        ProcessGuess(Input);
    }
}

    

void UBullCowCartridge::InitGame()
{
    PrintLine(TEXT("Welcome to BullCows"));

    // TArray<FString> ValidWords = GetValidWords(Words);
    HiddenWord = Isograms[FMath::RandRange(0, Isograms.Num()-1)];
    Lives = 2 * HiddenWord.Len();

    // PrintLine(FString::Printf(TEXT("The Hidden Word is %s"), *HiddenWord));//debug

    PrintLine(TEXT("Guess A %i letter word"), HiddenWord.Len());
    PrintLine(TEXT("You have %i lives"), Lives);
    PrintLine(TEXT("Type your guess\nPress Enter to continue"));

    
    bGameOver = false;
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("The HiddenWord is %s"), *HiddenWord);
    PrintLine(TEXT("Press Enter to play again"));
}

void UBullCowCartridge::ProcessGuess(const FString& Guess)
{
    if (Guess == HiddenWord)
        {
            PrintLine(TEXT("Congrats. You won!!"));
            EndGame();
            return;
        }
    
    if(HiddenWord.Len() != Guess.Len())
    {
        PrintLine(TEXT("HiddenWord is %i letters long."), HiddenWord.Len());
        return;
    }
        
    if(!IsIsogram(Guess))
    {
        PrintLine(TEXT("It shouldn't contain repeating letters"));
        return;
    }
    Lives--;
    if (Lives == 0)
    {
        PrintLine(TEXT("You lost!!"));
        EndGame();
        return;
    }
    int32 Bulls, Cows;
    GetBullCows(Guess, Bulls, Cows);

    PrintLine(TEXT("%i Bull, %i Cow"),Bulls, Cows);
    PrintLine(TEXT("You have %i lives left"), Lives);
    
}

bool UBullCowCartridge::IsIsogram(const FString& Word) const
{
    for(int32 Index = 0; Index < Word.Len(); ++Index)
    {
        for(int32 Comparison = Index + 1; Comparison < Word.Len(); ++Comparison)
        {
            if (Word[Index] == Word[Comparison])
            {
                return false;
            }
        }
    }
    return true;
}

TArray<FString> UBullCowCartridge::GetValidWords(const TArray<FString>& WordList) const
{
    TArray<FString> ValidWords;

    for (FString Word : WordList)
    {
        if (Word.Len() >= 4 && Word.Len() <= 6 && IsIsogram(Word))
            ValidWords.Emplace(Word);
    }
    return ValidWords;
}

void UBullCowCartridge::GetBullCows(const FString& Guess, int32& BullCount, int32& CowCount)const
{
    BullCount = 0;
    CowCount = 0;

    for (int32 GuessIndex = 0; GuessIndex < Guess.Len(); GuessIndex++)
    {
        if (Guess[GuessIndex] == HiddenWord[GuessIndex])
        {
            ++BullCount;
            continue;
        }
        for (int32 ComparisonIndex = 0; ComparisonIndex < HiddenWord.Len(); ++ComparisonIndex )
        {    
            if (Guess[GuessIndex] == HiddenWord[ComparisonIndex])
            {
                ++CowCount;
                break;
            }
        }
    }
}