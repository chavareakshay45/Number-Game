# Number Shifting Game

This is a number shifting game implemented in C, where players aim to arrange numbers in a 4x4 matrix in ascending order from 1 to 15, with one empty space for movement.

## How to Play

1. **Compile**: Compile the game using `gcc -o game myGame.c -lcurses`.
2. **Run**: Execute the compiled game using `./game`.
3. **Gameplay**: Use arrow keys to shift numbers. Move numbers into the empty space to rearrange them. The game ends when numbers are arranged in order or when maximum moves are exhausted.
4. **Winning**: Arrange numbers in ascending order from 1 to 15 to win the game.
5. **Exiting**: Press 'E' or 'e' to exit the game at any time.

## Features

- Provides interactive gameplay with ASCII art representation.
- Offers instructions and rules for gameplay.
- Tracks remaining moves and announces the winner or loser.

## Additional Features

- **Player Name**: Allows players to enter their name for a personalized gaming experience.
- **Play Again Option**: After winning or losing, players can choose to play again.
- **Game Statistics**: Keeps track of the number of moves made and displays them at the end of each game.
- **Sound Effects**: Provides audible feedback on successful moves or game completion.
