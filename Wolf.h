#ifndef WOLF_H
#define WOLF_H
#include <iostream>
#include <vector>
#include "Animal.h"
using namespace std;

class Wolf : public Animal{
    priority_queue<World*, vector<World*>, compareItem >* q;
    public:
        Wolf(int k, bool hunger, priority_queue<World*, vector<World*>, compareItem >* q1): World(k), Animal(hunger), q(q1){}
        void* Eat(); // Might change Eat to Roam for all
        void Run(); // Needs work
};
#endif
