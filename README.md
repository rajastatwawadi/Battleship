# Battleship Game
This is a simple text-based implementation of the classic Battleship game in C++. Two players take turns guessing the locations of each other's ships on a 5x5 grid. The player who sinks all of the opponent's ships first wins the game.

## Features
**Two-Player Gameplay**: Supports two players in a turn-based fashion.

**Ships**: Each player places three types of ships on the board:
Cruiser (2 cells)
Destroyer (3 cells)
Battleship (4 cells)

**Board**: A 5x5 grid where players place their ships and make guesses.
**Hit/Miss** Feedback: Players receive immediate feedback on whether their guess was a hit or a miss.
**Score Tracking**: The game keeps track of the number of hits, and the first player to hit all the opponent's ships wins.

## Code Structure

### Classes
ship: Represents a ship with a size (n) and a vector of pairs (v) for storing the ship's coordinates.

player: Represents a player with three types of ships (cruiser, destroyer, battleship) and a 5x5 grid (placedships) to place the ships.

### Methods
player::reset_board: Resets the player's board, filling it with '*'.

player::take_ip: Takes user input to place ships on the board.

player::display: Displays the player's board with ships.

run_game: Manages the turn-based gameplay between two players, updating the board with hits and misses.

**Main Function**

Initializes two players, takes input for ship placement, and starts the game loop.

## Sample Input/Output
The game asks players to enter the starting coordinates and orientation (horizontal/vertical) for their ships.
Players take turns guessing the coordinates of the opponent's ships.
The game outputs the result of each guess and updates the board.
