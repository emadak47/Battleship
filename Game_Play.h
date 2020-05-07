#ifndef GAMEPLAY_H
#define GAMEPLAY_H

bool CheckHit_Miss(int x, int y, int grid[][10+1]);
bool CheckValid(int x, int y, int grid[][10+1]);
bool Possible_Ship_Expand(int grid[][10+1], int x, int y, char direction, int size);
bool Win_Game(int grid[][10+1]);
void Print_Attack_Record(char grid[][10+1]);
void Expand_Ship(int grid[][10+1], int x, int y, char direction, int size);

#endif