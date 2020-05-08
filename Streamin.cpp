#include <iostream>
#include <string>
#include <utility>
#include <fstream>

#include "Streamin.h"
#include "Game_Play.h"
#include "Players.h"
#include "ShipDetails.h"

using namespace std;

Player P1, P2;

int const rows = 10;
int const columns = 10;

bool checkvalid = true;

// To read input from the input files for each player. It also stores input in data structure.
void read_input(string inputfile)
{
  //opens file
  ifstream fin;
  fin.open(inputfile.c_str());
  if(fin.fail())
  {
    cout << "Error in file opening!" << endl;
    exit(1);
  }

  string word;
  //opens player 1's inputfile
  if (inputfile == "inputfile1.txt")
  {
    int DataType = 0, Ship = 0;
    //extracts each word, each word is seperated by spaces
    while (fin >> word)
    {
      //appends each data type with the data from the user's input
      if (DataType % 5 == 0)
        P1.S[Ship].ShipSize = stoi(word);
      if (DataType % 5 == 1)
        P1.S[Ship].ShipName = word;
      if (DataType % 5 == 2)
        P1.S[Ship].InitialPos.first = stoi(word);
      if (DataType % 5 == 3)
        P1.S[Ship].InitialPos.second = stoi(word);
      if (DataType % 5 == 4)
      {
        P1.S[Ship].direction = word[0];
        //checks if the ship size is valid.
        if (P1.S[Ship].ShipSize < 1 || P1.S[Ship].ShipSize > 5)
        {
          cout << "The size of " << P1.PlayerName << "'s " << P1.S[Ship].ShipName << " is not consistent with the game directory." << endl;
          cout << "Please go back to the inputfile1 and change it." << endl;
          checkvalid = false;
          break;
        }
        //checks if the coordinate input by user is within the grid.
        if ( P1.S[Ship].InitialPos.first < 1 || P1.S[Ship].InitialPos.first > 10 ) 
        {
          cout << "X coordinate of " << P1.PlayerName << "'s " << P1.S[Ship].ShipName << " is out of range" << endl;
          cout << "Please go back to the inputfile1 and change it." << endl;
          checkvalid = false;
          break;
        }
        if ( P1.S[Ship].InitialPos.second < 1 || P1.S[Ship].InitialPos.second > 10 ) 
        {
          cout << "Y coordinate of " << P1.PlayerName << "'s " << P1.S[Ship].ShipName << " is out of range" << endl;
          cout << "Please go back to the inputfile1 and change it." << endl;
          checkvalid = false;
          break;
        }
        //checks if the initial positions of the ships overlap
        if (CheckValid(P1.S[Ship].InitialPos.first, P1.S[Ship].InitialPos.second, P1.ShipGrid) == false)
        {
        cout << "The initial coordinate for " << P1.S[Ship].ShipName << " is occupied." << endl;
        cout << "Please go back to inputfile1 and change it." << endl;
        checkvalid = false;
        break;
        }
        //checks if a ship can expand without overlap.
        if (Possible_Ship_Expand(P1.ShipGrid, P1.S[Ship].InitialPos.first, P1.S[Ship].InitialPos.second, P1.S[Ship].direction, P1.S[Ship].ShipSize) == false)
        {
          cout << P1.S[Ship].ShipName << " cannot expand in the " << P1.S[Ship].direction << " direction." << endl;
          cout << "Please go back to inputfile1 and change its direction." << endl;
          checkvalid = false;
          break;
        }
        else 
        {
          Expand_Ship(P1.ShipGrid, P1.S[Ship].InitialPos.first, P1.S[Ship].InitialPos.second, P1.S[Ship].direction, P1.S[Ship].ShipSize);
          Ship++;
        }
      }
      DataType ++;
    }
  }
  //takes input from second user
  if (inputfile == "inputfile2.txt")
  {
    int DataType = 0, Ship = 0;
    while (fin >> word)
    {
      if (DataType % 5 == 0)
        P2.S[Ship].ShipSize = stoi(word);
      if (DataType % 5 == 1)
        P2.S[Ship].ShipName = word;
      if (DataType % 5 == 2)
        P2.S[Ship].InitialPos.first = stoi(word);
      if (DataType % 5 == 3)
        P2.S[Ship].InitialPos.second = stoi(word);
      if (DataType % 5 == 4)
      {
        P2.S[Ship].direction = word[0];
        if (P2.S[Ship].ShipSize < 1 || P2.S[Ship].ShipSize > 5)
        {
          cout << "The size of " << P2.PlayerName << "'s " << P2.S[Ship].ShipName << " is not consistent with the game directory." << endl;
          cout << "Please go back to the inputfile2 and change it." << endl;
          checkvalid = false;
          break;
        }
        if ( P2.S[Ship].InitialPos.first < 1 || P2.S[Ship].InitialPos.first > 10 ) 
        {
          cout << "X coordinate of " << P2.PlayerName << "'s "<< P2.S[Ship].ShipName << " is out of range" << endl;
          cout << "Please go back to the inputfile2 and change it." << endl;
          checkvalid = false;
          break;
        }
        if ( P2.S[Ship].InitialPos.second < 1 || P2.S[Ship].InitialPos.second > 10 ) 
        {
          cout << "Y coordinate of " << P2.PlayerName << "'s "<< P2.S[Ship].ShipName << " is out of range" << endl;
          cout << "Please go back to the inputfile2 and change it." << endl;
          checkvalid = false;
          break;
        }
        if (CheckValid(P2.S[Ship].InitialPos.first, P2.S[Ship].InitialPos.second, P2.ShipGrid) == false)
        {
          cout << "The initial coordinate for " << P2.S[Ship].ShipName << " is occupied." << endl;
          cout << "Please go back to the inputfile2 and change it." << endl;
          checkvalid = false;
          break;
        }
        if (Possible_Ship_Expand(P2.ShipGrid, P2.S[Ship].InitialPos.first, P2.S[Ship].InitialPos.second, P2.S[Ship].direction, P2.S[Ship].ShipSize) == false)
        {
          cout << P2.S[Ship].ShipName << " cannot expand in the " << P2.S[Ship].direction << " direction." << endl;
          cout << "Please go back to inputfile2 and change its direction." << endl;
          checkvalid = false;
          break;
        }
        else 
        {
          Expand_Ship(P2.ShipGrid, P2.S[Ship].InitialPos.first, P2.S[Ship].InitialPos.second, P2.S[Ship].direction, P2.S[Ship].ShipSize);
          Ship++;
        }
      }
      DataType ++;
    }
  }
  fin.close();
}

