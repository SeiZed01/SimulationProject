#ifndef GRASSLAND_H
#define GRASSLAND_H

#include "World.h"
#include <iostream>
#include <vector>
using namespace std;

class Grassland : public World{
    priority_queue<World*, vector<World*>, compareItem>* q;
    int growth;
    bool grass;
    public:
        void setGrassTrue();
        bool grow(); // Return true if grow
        void eatGrass();
        Grassland(int day, priority_queue<World*, vector<World*>, compareItem>* q1): World(day), q(q1){}
        void Run();
        ~Grassland();
};
#endif
