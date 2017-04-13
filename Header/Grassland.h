#ifndef GRASSLAND_H
#define GRASSLAND_H

#include "World.h"
#include "Cells.h"
#include <iostream>
#include <vector>
using namespace std;

class Grassland : public World{
    Cells** cell;
    priority_queue<World*, vector<World*>, compareItem>* q;
    
    //int growth; Might not need these since theres a lastEaten data in Cell.h.
    //bool grass; 
    
    public:
        Grassland(int day, priority_queue<World*, vector<World*>, compareItem>* q1): World(day), q(q1){}
        Rabbit* getRabbitClose(int x, int y);
        //void grow(); 
        void eatGrass(int x, int y, Rabbit*);
        void Run();
        ~Grassland();
};
#endif
