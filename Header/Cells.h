#ifndef CELLS_H
#define CELLS_H

#include "Animal.h"
#include <iostream>
using namespace std;
class Cells {
public:
    Animal* a;
    int lastEaten;
    int x, y;
    Cells(){lastEaten = 10; x = 0; y = 0; a = NULL;}
    ~Cells(){}
};
#endif
