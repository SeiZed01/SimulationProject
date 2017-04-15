#ifndef CELLS_H
#define CELLS_H

#include "Animal.h"
#include <iostream>
using namespace std;

class Cells : public World{
public:
    Animal* a; // Pointing to nothing, just make it point to animal when animal is put within cell.
    int lastEaten; // Use to keep track of the days for grass growth? Maybe set to 10 and when it gets eaten change to 0 then increase 
    // Until 10 again. Only able to eat if lastEaten is 10.
    int x, y;
    Cells(): World(400), lastEaten(10){} // probably rand 400-450 so change that later
    ~Cell();
};
#endif
