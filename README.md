# CowBull-Game-UE4
Computerized Cow-Bull Game with Unreal Engine 4.22

## General Game Rules

The game play for letter version of this game is as follows.

- A person (Host) thinks of any isogram word, and gives out the number of letters in the word.
- Other players (Guessers) try to figure that word by guessing isogram words containing the same number of letters.
- Host responds with the number of Cows & Bulls for each guessed word. "Cow" means a letter in the wrong position, while "Bull" means a letter in the right position.

The game may also be played by two teams of players, with the team members discussing their strategy before selecting a move.

For example, if the secret word is HEAT, a guess of COIN would result in "0 Bulls, 0 Cows" (all of the guessed letters are wrong); a guess of EATS would result in "0 Bulls, 3 Cows" (since E, A, T are all present, but not in the guessed positions), and a guess of TEAL would result in "2 Bulls, 1 Cow" (since E and A are in the right positions, while T is in the wrong position). The game would continue until someone scores "4 Bulls" for guessing HEAT exactly.

**In this Version, you will be playing with CPU. You have given number of lives and You will lose if you couldn't guess before the lives run out.**   
**You need Unreal Engine v4 or greater to be able to play.**

## How to play 
- Download the Complete Folder.
- Double Click `BullCowGame.uproject`.
- Click Play on the Top Dock.
- Click on the screen and press `Tab` to access Terminal.
- Follow the Instructions mentioned there. (Rules are shown)

## Source Code
Main source file which controls the game is [here](https://github.com/princeofpython/CowBull-Game-UE4/blob/master/Source/BullCowGame/BullCowCartridge.cpp).
