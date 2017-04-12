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
    Cells(){a = NULL; lastEaten = 0; int x = y = 0;
    ~Cell();
};
#endif
