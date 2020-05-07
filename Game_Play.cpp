#include <iostream>
#include <iomanip>

#include "Game_Play.h"

using namespace std;

int const rows = 10;
int const columns =10;

bool CheckHit_Miss(int x, int y, int grid[][columns+1])
{
  if (grid[x][y] == 1) return true;
  return false;
}

bool CheckValid(int x, int y, int grid[][columns+1])
{
  if (grid[x][y] == 0) return true;
  else return false;
}


bool Possible_Ship_Expand(int grid[][columns+1], int x, int y, char direction, int size)
{
  bool valid = false;

  if (direction == 'U')
  {
    if (x-size >= 0)
    {
      for (int i = 0; i < size ; i++)
        if (grid [x-i][y] == 1) return valid;

      valid = true;  
      return valid;
    }
    else return valid;
  }
  if (direction == 'D')
  {
    if(x+size-1 <= 10)
    {
      for (int i = 0; i < size ; i++)
        if (grid [x+i][y] == 1) return valid;
            
      valid = true;
      return valid;
    }
    else return valid;
  }
  if (direction == 'L')
  {
    if(y-size >= 0)
    {
      for (int i = 0; i < size ; i++)
        if(grid[x][y-i] == 1) return valid;
      
      valid = true;
      return valid;
    }
    else return valid; 
  }
  if (direction == 'R')
  {
    if(y+size-1 <= 10)
    {
      for (int i = 0; i < size ; i++)
        if(grid[x][y+i] == 1) return valid;
      
      valid = true;
      return valid;
    }
    else return valid; 
  }

  return valid;
}

bool Win_Game(int grid[][columns+1])
{
  for (int i = 1; i < rows+1 ; i++)
    for (int j = 1; j < columns+1; j++)
      if (grid[i][j] == 1)
        return false;
  return true;
}

void Print_Attack_Record(char grid[][columns+1])
{
  for (int i = 1; i < rows+1; i++)
  {
    for (int j = 1; j < columns+1 ; j++)
      cout << setw(3) << grid[i][j] ;
    cout << endl; 
  }
}


void Expand_Ship(int grid[][columns+1], int x, int y, char direction, int size)
{
  if (direction == 'U')
    for (int i = 0 ; i < size; i++)
      grid[x-i][y] = 1;
  
  if (direction == 'D')
    for (int i = 0 ; i < size; i++)
      grid[x+i][y] = 1;

  if (direction == 'L')
    for (int i = 0 ; i < size; i++)
      grid[x][y-i] = 1;
  
  if (direction == 'R')
    for (int i = 0 ; i < size; i++)
      grid[x][y+i] = 1;
  
}