#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

#include "Streamout.h"

using namespace std;

int const rows = 10;
int const columns = 10;

void print_output(string outputfile, Node * head, char grid[][columns+1])
{
  Node * current = head;
  ofstream fout;
  fout.open(outputfile.c_str());

  if (fout.fail())
  {
    cout << "Error in file opening!" << endl;
    exit(1);
  }

  while(current != NULL)
    {
      fout << current->x << setw(3) << current->y << endl;
      current = current->next;
    }

  fout << "___________________________________" << endl;
  
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < columns; j++)
      fout << grid[i][j] << setw(3);
    fout << endl;
  }
  fout.close();
}

void print_list(Node *head)
{
  Node * current = head;
  while(current != NULL)
  {
    cout << current->x << setw(3) << current->y << endl;
    current = current->next;
  }
}

