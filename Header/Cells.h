#ifndef CELLS_H
#define CELLS_H

#include "Animal.h"
#include <iostream>
using namespace std;
class Cells { //Cell class, counts as a basic tile point
public:
    Animal* a; //points to animal residing in tile
    int lastEaten;
    int x, y;
    Cells(){lastEaten = 10; x = 0; y = 0; a = NULL;} // basic constructor sets initial values
    ~Cells(){delete this;} //basic deconstructor
};
#endif
