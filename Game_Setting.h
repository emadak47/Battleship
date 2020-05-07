#ifndef GAMESETTING_H
#define GAMESETTING_H

#include <string>

using namespace std;

void Initialise_Record_Grid(char grid[][10+1]);
void Initialise_Ship_Grid(int grid[][10+1]);
int Begin_Attack(string player1, string player2);

#endif