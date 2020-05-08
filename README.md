# Team Members:
Emad Akhras (3035662962)     Edward Neslon (3035603576)

# Game Description:

* Game Objective:
Battleship is a war-themed game for two players in which the opponents try to guess the location of their opponent's warships and sink them. 

* Setting-up Game:
Each player will be allocated an empty grid (printed), a hidden grid, and five ships of varying lengths.

Before the game starts, each player inputs the coordinates and direction (U, D, L, R) of their own five ships into an input file. For each player, the program will read input from the input file and generate the hidden grid by laying out the ships and postitioning them onto the grid. Each ship must be placed horizontally or vertically across grid spaces —not diagonally— and the ships can't hang off the grid. Ships can't occupy the same grid space. You cannot change the position of the ships after the game begins. Also, neither player can see his opponent's grid or ship locations.

The 'printed' grid is used to record the shots fired toward the opponent and to document whether those shots were hits (H) or misses (X).

* GamePlay:
Players take turns calling out row and column coordinates in an attempt to identify a square on the other player's grid that contains a ship. 

On your turn, call out a colum and row. The program then checks that coordinate against the oponent's 'hidden' grid and reports "miss" if there is no ship there, or "hit" if you have correctly guessed a space that is occupied by a ship. The program then updates the 'printed' grid marking each of your shots by using 'H' to document the misses and 'X' to register the hits.

The first player to sink all five of their opponent's ships wins the game.


# Function Description:
* Streamin.cpp:
1- read_input(): To read input from the input files for each player. It also stores input in data structure. 

* Game_Setting.cpp:
1- Begin_Attack(): returns which player starts the attack based on a random computer selection. 
2- Initialise_Record_Grid(): To initialise the printed grid (all * at first).
3- Initialise_Ship_Grid(): To initialise the hidden grid (all zeros at first).

* Game_Play.cpp:
1- CheckHit_Miss(): returns true if ship input coordinate at run time hit a ship.
2- CheckValid(): returns true if a square in the hidden grid is not occupied by another ship. 
3- Possible_Shio_Expand(): return true if it is possible for a ship to expand in a specified direction.
4- Win_Game(): return true if all ships have been sunken in the hidden grid.
5- Print_Attack_Record(): To print the record grid for each player before each round.
6- Expand_Ship(): To expand a ship on the hidden grid in a specified direction.

* LinkedList.cpp:
1- delete_list(): To delete linked list and free memory.
2- Build_linked_list(): To build a linked list forward. 
3- Search_History(): To search a linked list for an specific entry. 

* Streamout.cpp:
1- print_output(): To print the linked list of a player (a recrod of all his moves) and to print his recrod grid.
2- print_list(): To print the linked list of a player.

* Files.h:
1- Node.h: Contains information about the data structure Node (used for linked list)
2- ShipDetails.h: Contains information about the ships details (size, name, initial coordinate x & y, direction)
3- Players.h: Contains information about the players (name, hidden grid, record grid, array of the struct ShipDetails)
4- Game_PLay.h: contains all functions used in Game_Play.cpp
5- Game_Setting.h: contains all functions used in Game_Setting.cpp
6- LinkedList.h: contains all functions used in LinkedList.cpp
7- Streamin.h: contains all functions used in Streamin.cpp
8- Streamout.h: contains all functions used in Streamout.cpp

# Code Requirments:
* Generation of random game sets or events: The function "Begin_Attack()"
* Data structure for storing game status: ShipDetails, Players (Nested data structures).
* Dynamic mempry managment: Two Linked Lists to store each players moves.  
* File input/output: 
1- File input for loading each player's input. 
2- File output for printing a player's record of moves and his record grid. 
* Program codes in multiple files: main.cpp, Game_Play.cpp, Game_Setting.cpp, LinkedList.cpp, Streamin.cpp, Streamout.cpp
* Proper indentation and naming styles: Proper names and neat organisation of the code.
* In-code documentation: done on every file.

Reference: https://www.thesprucecrafts.com/the-basic-rules-of-battleship-411069 
