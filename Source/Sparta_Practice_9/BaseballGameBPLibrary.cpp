// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseballGameBPLibrary.h"

#include "Algo/RandomShuffle.h"

void UBaseballGameBPLibrary::EvaluateGuess(const FString& Guess, const FString& Answer, int32& OutStrike,
                                           int32& OutBall)
{
	OutStrike = 0;
	OutBall = 0;
	if (Guess.Len() != 3 || Answer.Len() != 3)
	{
		return;
	}
	
	for (int32 i = 0; i < 3; i++)
	{
		if (Guess[i] == Answer[i])
		{
			OutStrike++;
		}
		else if (Answer.Contains(FString::Chr(Guess[i])))
		{
			OutBall++;
		}
	}
}

int32 UBaseballGameBPLibrary::GenerateAnswerNumber()
{
	TArray<int> Numbers;
	for (int i = 1; i <= 9; i++)
	{
		Numbers.Add(i);
	}
	Algo::RandomShuffle(Numbers);

	int Answer = 0;
	for (int i = 0; i < 3; i++)
	{
		Answer += Numbers[i] * FMath::Pow(10.0, 2 - i);
	}

	return Answer;
}

bool UBaseballGameBPLibrary::IsValidGuess(const FString& Guess)
{
	if (Guess.Len() != 3)
	{
		return false;
	}

	// 중복이 있는지 확인
	for (int i = 0; i < 3; i++)
	{
		for (int j = i + 1; j < 3; j++)
		{
			if (Guess[i] == Guess[j])
			{
				return false;
			}
		}
	}

	// 숫자인지 확인
	for (int i = 0; i < 3; i++)
	{
		if (!FChar::IsDigit(Guess[i]))
		{
			return false;
		}
	}

	return true;
}

bool UBaseballGameBPLibrary::IsValidIDFormat(const FString& ID)
{
	const FRegexPattern Pattern(TEXT("^[A-Za-z0-9가-힣-_]+$"));
	FRegexMatcher Matcher(Pattern, ID);
	return Matcher.FindNext();
}
