#include <iostream>

#include "Game_Setting.h"

using namespace std;

int const rows = 10;
int const columns = 10;

//To initialise the printed grid (all * at first).
void Initialise_Record_Grid(char grid[][columns+1])
{
  for (int i = 1; i < rows+1 ; i++)
    for (int j = 1; j < columns+1 ; j++)
      grid [i][j] = '*';
}

//To initialise the hidden grid (all zeros at first).
void Initialise_Ship_Grid(int grid[][columns+1])
{
  for (int i = 1; i < rows+1 ; i++)
    for (int j = 1; j < columns+1 ; j++)
      grid [i][j] = 0;
}

//returns which player starts the attack based on a random computer selection.
int Begin_Attack(string player1, string player2)
{
  srand(time(NULL));
  int starter = rand() % 2+1;
  if (starter == 1) cout << player1 << " begins the attack" << endl;
  else cout << player2 << " begins the attack" << endl;

  return starter;
}
