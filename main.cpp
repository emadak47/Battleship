#include <iostream>
#include <utility>
#include <string>
#include <fstream>
#include <iomanip>

#include "Game_Play.h"
#include "Game_Setting.h"
#include "Streamin.h"
#include "Streamout.h"
#include "LinkedList.h"
#include "Players.h"
#include "ShipDetails.h"
#include "Node.h"

using namespace std;
 
int main() {
// take and store name of first user
  string name1; 
  cout << "Please enter the name of Player 1: ";
  cin >> name1;
  P1.PlayerName = name1;
	
// take and store second user name
  string name2; 
  cout << "Please enter the name of Player 2: ";
  cin >> name2;
  P2.PlayerName = name2;
//create grid for player 1 and player 2 by calling the initialise_ship_grid function
  Initialise_Ship_Grid(P1.ShipGrid);
  Initialise_Ship_Grid(P2.ShipGrid);


  read_input("inputfile1.txt");
  if (checkvalid == false) return 0;
  read_input("inputfile2.txt");
  if (checkvalid == false) return 0;
  
//create their 'updated grid' to record all their next moves
  Initialise_Record_Grid(P1.RecordGrid);
  Initialise_Record_Grid(P2.RecordGrid);

  //To decide who begins the attack
  int starter = Begin_Attack(P1.PlayerName, P2.PlayerName);

  Node * head1 = NULL, * tail1 = NULL;
  Node * head2 = NULL, * tail2 = NULL;
  int x, y; 
	//ends game when all ships of one player have been sunken.
  while (Win_Game(P1.ShipGrid) == false && Win_Game(P2.ShipGrid) == false)
  {
// determines that it is player 1's turn
    if (starter % 2 == 1)
    {
      Print_Attack_Record(P1.RecordGrid);
      cout << P1.PlayerName << ", Enter coordinates for your next attack: ";
      cin >> x >> y;
//enusres that coordinate inputed is within the grid
      if ( x < 1 || x > 10 || y < 1 || y > 10 ) cout << "Please think inside the box next time :)" << endl;\
//ensures coordinate was not used before and updates the update grid with 'H' if hit and 'X' if miss
      if (Search_History(head1,x,y) == false)
      {
        Build_linked_list(head1, tail1, x, y);
        if (CheckHit_Miss(x, y, P2.ShipGrid))
        {
          P2.ShipGrid[x][y] = 2;
          P1.RecordGrid[x][y] = 'H';
					if(Win_Game(P2.ShipGrid) == false){
          	cout << "Hit! You get to go again " << P1.PlayerName << endl;
					}
          starter += 2;
        }
        else 
        {
          starter++;
          P1.RecordGrid[x][y] = 'X';
        }
      }
      else 
      {
        cout << "Coordinate has been targeted before! Try again ! " << endl;
        starter += 2;
      }
    }

    if (starter % 2 == 0)
    {
      Print_Attack_Record(P2.RecordGrid); 
      cout << P2.PlayerName << ", Enter coordinates for your next attack: ";
      cin >> x >> y;
      if ( x < 1 || x > 10 || y < 1 || y > 10 ) cout << "Please think inside the box next time :)" << endl;
      if (Search_History(head2,x,y) == false)
      {
        Build_linked_list(head2, tail2, x, y);
        if (CheckHit_Miss(x, y, P1.ShipGrid))
        {
          P1.ShipGrid[x][y] = 2;
          P2.RecordGrid[x][y] = 'H';
					if(Win_Game(P1.ShipGrid) == false){
          cout << "Hit! You get to go again " << P2.PlayerName << endl;
					}
          starter += 2;
        }
        else 
        {
          starter++;
          P2.RecordGrid[x][y] = 'X';
        }
      }
      else 
      {
        cout << "Coordinate has been targeted before! Try again ! " << endl;
        starter += 2;
      }
    }
  }

  char choice;
//if player 2 wins declares player 2 as the winner
  if (Win_Game(P2.ShipGrid)) 
  {
    cout << "Game Over " << P2.PlayerName << "!" << endl;
    cout << P1.PlayerName << " wins" << endl;
    cout << P1.PlayerName << ", would like to see a record of all your moves? (Y/N): ";
    cin >> choice;
//optional output file.
    if (choice == 'Y')
    {
      cout << "Please open outputfile1 to see your record." << endl;
      print_output("outpulefile1.txt", head1, P1.RecordGrid);
    }
    else cout << "Bye!" << endl;
  }
//if player 1 wins it declares player 1 as the winner.
  if (Win_Game(P1.ShipGrid)) 
  {
    cout << "Game Over " << P1.PlayerName << " !" << endl;
    cout << P2.PlayerName << " wins" << endl;
    cout << P2.PlayerName << ", would like to see a record of all your moves? (Y/N): ";
    cin >> choice;
    if (choice == 'Y')
    {
      cout << "Please open outputfile2 to see your record." << endl;
      print_output("outpulefile2.txt", head2, P2.RecordGrid);
    }
    else cout << "Bye!" << endl;
  }
  
//delete the linked lists 
  delete_list(head1);
  delete_list(head2);

  return 0;
}
