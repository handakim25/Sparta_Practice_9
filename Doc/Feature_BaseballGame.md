# Baseball Game

## 구현 목표

사용자 입력으로 숫자 야구 게임을 진행한다.

## 필요한 기능

- 명령어 기능 추가가
  - /로 시작하는 단어는 명령어이다.
  - /Start
  - /abc : 야구 게임 정답 제출
- 게임 시작 기능
  - 입장한 유저를 기준으로 게임 참여 목록 생성
  - 호스트만 생성 가능(현재는 Listen Server의 Host)
- 턴 제어 기능
  - 현재 입장한 유저를 기준으로 턴의 순서를 만들어서 사용
  - 최대 턴수 3턴
  - 턴 유저가 아닌 유저의 입력을 무시
- 입력 확인
  - 입력을 확인 받아서 S, B, O를 전파
  - if 정답일 경우, 게임 결과를 전파
  - 게임 종료

## 게임 흐름 구현

```TEXT
Function Process Player Guess
    - Sender : PlayerController
    - Guess

if game not start
    return

answer from client
    if not turn player return

evaluate answer -> S, B, O
broadcast game result

if is game over(3S)
    broadcast winner
    end game
    return

// update next turn player
increment index
if index is out of range
  reset index
  increment turn number

if turn number >= max turn
    boradcast current turn number
    end game

broadcast current player turn
```

```TEXT
Function Game Start
    - RequestingPlayer : PlayerController

if bIsGamePlaying true
    return

if RequestingPlayer is not Authorized Player
    return

if Game User is not at least 2
    return

Copy ActivePlayers to GamePlayers
Set bIsGamePlaying true
Generate Answer
Set First Turn Player
Set Turn Count 0
Broadcast Game Start
```

```TEXT
Function protected End Game
    - Winner : PlayerController

Set bIsGamePlaying false
if Winner is not null
    Boradcast Winner
else
    Broadcast Draw

Broadcast Answer
```

## 필요 구현 사항

- GameMode에서 플레이어를 맵에서 리스트로 변경
  - 이는 순서를 기록하기 위해서이다. 이 순서를 바탕으로 Turn Player를 결정
  - 방장 기능을 추가(Host Player)
- 시스템 메시지를 추가
  - 게임 진행 결과를 출력하기 위해 공지와 같은 게임 메시지를 추가
- 커맨드 추가
  - Start
  - 숫자 제출

## 작업 목록

- [x] Game Mode Refactoring
  - [x] Player 리스트를 TMap에서 TArray로 변경
  - [x] Host Player 선정 기능을 추가
- [ ] BaseBall Game 로직 추가
  - [x] Start Game
  - [ ] Process Player Guess
  - [ ] End Game

## 추후 구현

- Turn Player 표시
- Strike, Ball이 있을 때 말고 Out만 있을 때 표시 변경