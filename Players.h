#ifndef PLAYERS_H
#define PLAYERS_H

#include "ShipDetails.h"

struct Player
{
  string PlayerName;
  int ShipGrid[10+1][10+1];
  char RecordGrid[10+1][10+1];
  ShipDetails S[5];
};

extern Player P1, P2;

#endif
