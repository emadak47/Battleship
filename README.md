# Emad Akhras (3035662962)
# Nelson Edward (3035603576)

# Game Description:

* Game Objective:
Battleship is a war-themed game for two players in which the opponents try to guess the location of their opponent's warships and sink them. 

* Setting-up Game:
Each player receives a game board and five ships of varying lengths.

Before the game starts, each opponent secretly writes down their own five ships positions in terms of coordinates on an input file. The program the ocean grid (lower part of the board) by laying out their ships and anchoring them into the holes on the grid. Each ship must be placed horizontally or vertically across grid spaces—not diagonally—and the ships can't hang off the grid. Ships can touch each other, but they can't occupy the same grid space. You cannot change the position of the ships after the game begins

Neither player can see his opponent's grid and ship locations.

* GamePlay:
The gameplay is straightforward. Each player hides ships on a plastic grid containing vertical and horizontal space coordinates. Players take turns calling out row and column coordinates on the other player's grid in an attempt to identify a square that contains a ship. 

The game board each player gets has two grids: an upper and lower grid. The lower grid is used by the player to "hide" the location of his own ships, while the upper grid is used to record the shots fired toward the opponent and to document whether those shots were hits or misses.

Players take turns firing shots (by calling out a grid coordinate) to attempt to hit the opponent's enemy ships.

On your turn, call out a letter and a number that identifies a row and column on your target grid. Your opponent checks that coordinate on their ocean grid and verbally responds "miss" if there is no ship there, or "hit" if you have correctly guessed a space that is occupied by a ship.

Mark each of your shots or attempts to fire on the enemy using your target grid (upper part of the board) by using white pegs to document your misses and red pegs to register your hits. As the game proceeds, the red pegs will gradually identify the size and location of your opponent's ships.

When it is your opponent's turn to fire shots at you, each time one of your ships receives a hit, put a red peg into the hole on the ship corresponding to the grid space. When one of your ships has every slot filled with red pegs, you must announce to your opponent when your ship is sunk. In classic play, the phrase is "You sunk my battleship!"

The first player to sink all five of their opponent's ships wins the game.


Function descriptions:

Function 1: will check if the cooridinate for the hidden ship inputed by user is valid. it will cross check the coordinate with all the other coordinats previously inputed. if there are any overlap, the progeam will ask the user to input a nother coordinate.

Function 2: will be called every round to check if any ships are left. if not then the player with ships still unsunken, is declared the winner.

Functionn 3: will take the user input of coordinate that they target, and check if it hits or misses 

Function 4: will print the updated grid of each player. the grid shows the results of all the user's past inputs.

