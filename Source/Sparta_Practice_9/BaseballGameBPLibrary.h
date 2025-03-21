// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BaseballGameBPLibrary.generated.h"

/**
 * 
 */
UCLASS()
class SPARTA_PRACTICE_9_API UBaseballGameBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	/** 3자리 입력을 받아서 Strike, Ball을 반환한다. Strike : 숫자와 자리수가 일치할 경우, Ball : 숫자만 일치할 경우 */
	UFUNCTION(BlueprintPure)
	static void EvaluateGuess(const FString& Guess, const FString& Answer, int32& OutStrike, int32& OutBall);

	/** 중복이 없는 3자리 자연수를 생성한다. */
	UFUNCTION(BlueprintPure)
	static int32 GenerateAnswerNumber();

	/** 유효한 정답 형식인지 검증한다. */
	UFUNCTION(BlueprintPure)
	static bool IsValidGuess(const FString& Guess);

	/** ID 형식을 확인한다.
	 * - 영어 대소문자
	 * - 숫자
	 * - 완성된 한글
	 * - '-', '_'의 특수문자만 허용
	 */
	UFUNCTION(BlueprintPure)
	static bool IsValidIDFormat(const FString& ID);
};
