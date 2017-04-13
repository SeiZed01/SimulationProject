#ifndef CELLS_H
#define CELLS_H

#include "Animal.h"
#include <iostream>
using namespace std;

class Cells : public World{
public:
    Animal* a;
    int lastEaten; // Use to keep track of the days for grass growth? Maybe set to 10 and when it gets eaten change to 0 then increase 
    // Until 10 again. Only able to eat if lastEaten is 10.
    int x, y;
    Cells(){a = NULL; lastEaten = 10;}
    ~Cell();
};
#endif
