# Blueprint Library

## 구현 목적

블루프린트에서 접근할 수 없거나 작성하기 번거로운 기능을 구현하기 위해 블루프린트 라이브러리를 작성한다.

## 필요한 기능

- GenerateTargetNumber
  - 각 자리수 중복이 없는 세자리 자연수를 생성
  - blueprint pure
- EvaluateGuess
  - Target Number, Guess Number를 받아서 Strike, Ball, Out을 판정
    - Strike : 자리수와 값이 동일
    - Ball : 자리수가 같지는 않지만 값이 동일
    - Out은 Strike, Ball이 없을 경우
  - 출력 : Strike 개수, Out 개수
  - Blueprint Pure
- IsValidGuess
  - 숫자가 중복 없는 세자리 자연수인지를 확인
  - Bluepirnt Pure
- IsValidIDFormat
  - String을 입력받아 적합한 알파벳, 영어, 특수문자(-,_)로 이루어져 있는지 확인
  - Blueprint Pure

## 작업 목록

- [x] Blueprint Library 생성
- [x] GenerateTargetNumber
- [x] EvaluateGuess
- [x] IsValidGuess
- [x] IsValidIDFormat

## 정리 목록

### 정해진 리스트 중에서 랜덤하게 선택

```C++
    TArray<int> Numbers;
    for (int i = 1; i <= 9; i++)
    {
        Numbers.Add(i);
    }
    Algo::RandomShuffle(Numbers);
```

### 숫자 확인

- FChar::IsDigit
