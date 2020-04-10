# Team Members:
Emad Akhras (3035662962)     Nelson Edward (3035603576)

# Game Description:

* Game Objective:
Battleship is a war-themed game for two players in which the opponents try to guess the location of their opponent's warships and sink them. 

* Setting-up Game:
Each player will be allocated an empty grid (printed), a hidden grid, and five ships of varying lengths.

Before the game starts, each player inputs the coordinates and orientation (vertical or horizontal) of their own five ships into an input file. For each player, the program will read input from the input file and generate the hidden grid by laying out the ships and postitioning them onto the grid. Each ship must be placed horizontally or vertically across grid spaces —not diagonally— and the ships can't hang off the grid. Ships can't occupy the same grid space. You cannot change the position of the ships after the game begins. Also, neither player can see his opponent's grid and ship locations.

The 'printed' grid is used to record the shots fired toward the opponent and to document whether those shots were hits or misses.

* GamePlay:
Players take turns calling out row and column coordinates on the other player's grid in an attempt to identify a square that contains a ship. 

On your turn, call out a colum and row. The program then checks that coordinate against the oponent's 'hidden' grid and responds "miss" if there is no ship there, or "hit" if you have correctly guessed a space that is occupied by a ship. The program then updates the 'printed' grid marking each of your shots by using 'O' to document the misses and 'X' to register the hits. When one of the ships has every slot filled with 'X', the program will announce to your opponent "You sunk a battleship!"

The first player to sink all five of their opponent's ships wins the game.


# Function descriptions:
1- CheckValid(): will check if the inputted cooridinate for the hidden ship is valid. It will cross check the availability of the spaces with all previously inputted coordinates. If there is any overlap, the progeam will ask the user to input new coordinates. 

2- win_game(): will be called every round to check if any ships are left. If not then the player with ships still unsunken is declared the winner. Each player will ultimately recive a report on their own output file, detailing the final condition of their hidden grid and also the reslut of the game.

3- CheckHit_Miss(): will take the user input of coordinate that they target, and check if it hits or misses. 

4- UpdateGrid(): will update and then display the 'printed' grid of each player. The grid keeps record of all the user's past targets.

5- CheckSinkship(): will check if any of the ships have been fully 'hit' if so, the function will output "You sunk a battleship!".



Reference: https://www.thesprucecrafts.com/the-basic-rules-of-battleship-411069 
