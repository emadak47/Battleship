#ifndef SHIPDETAILS_H
#define SHIPDETAILS_H

using namespace std;

typedef pair<int, int> coordinate;

struct ShipDetails 
{
  int ShipSize;
  string ShipName;
  coordinate InitialPos; 
  char direction;
};

#endif
