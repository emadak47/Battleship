# Emad Akhras (3035662962)
# Nelson Edward (3035603576)

# Game Description:

* Game Objective:
Battleship is a war-themed game for two players in which the opponents try to guess the location of their opponent's warships and sink them. 

* Setting-up Game:
Each player will have an empty grid to track their moves and five ships of varying lengths.

Before the game starts, each player will input the coordinates and orientation(vertical or horizontal) of their own five ships intp an input file. The program will then read input from the input file and generate the grid by laying out the ships and postitioning them onto the grid. Each ship must be placed horizontally or vertically across grid spaces—not diagonally—and the ships can't hang off the grid. Ships can't occupy the same grid space. You cannot change the position of the ships after the game begins. Also, neither player can see his opponent's grid and ship locations.

The game board each player gets has two grids: a 'hidden' and printed grid. The 'hidden grid contains all the locations of his own ships, while the printed grid is used to record the shots fired toward the opponent and to document whether those shots were hits or misses.

* GamePlay:
Players take turns calling out row and column coordinates on the other player's grid in an attempt to identify a square that contains a ship. 

On your turn, call out a colum and row that identifies on the target grid. program then checks that coordinate against the oponent's 'hidden' grid and responds "miss" if there is no ship there, or "hit" if you have correctly guessed a space that is occupied by a ship.

the program then updates the printed grid marking each of your shots or attempts to fire on the enemy  by using 'O' to document your misses and 'X' to register your hits.

When one of the ships has every slot filled with 'X', the program will announce to your opponent "You sunk a battleship!"

The first player to sink all five of their opponent's ships wins the game.


Function descriptions:

CheckValid(): will check if the cooridinate for the hidden ship inputed by user is valid. it will cross check the coordinate with all the other coordinats previously inputed. if there are any overlap, the progeam will ask the user to input a nother coordinate.

Win(): will be called every round to check if any ships are left. if not then the player with ships still unsunken, is declared the winner. each player will their recive an output, detailing the final condition of their hidden grid and also the reslut of the game.

CheckHit_Miss(): will take the user input of coordinate that they target, and check if it hits or misses 

UpdateGrid(): will print the updated grid of each player. the grid shows the results of all the user's past inputs.

CheckSinkship():will check if any of the ships have been fully 'hit' if so will output "You sunk a battleship!".

