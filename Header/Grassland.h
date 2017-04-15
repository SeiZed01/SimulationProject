#ifndef GRASSLAND_H
#define GRASSLAND_H

#include "World.h"
#include "Cells.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

class Grassland : public World{
    Cells** cell;
    priority_queue<World*, vector<World*>, compareItem>* q;
    
    //int growth; Might not need these since theres a lastEaten data in Cell.h.
    //bool grass; 
    
    public:
        Grassland(priority_queue<World*, vector<World*>, compareItem>* q1): World(day), q(q1){
            *cell = new Cells[512][512];
        };
        Rabbit* getRabbitClose(int x, int y);
        //void grow(); 
        void createRabbit(int noL, int noA){
            for(int i = 0; i < noL; i++){
                //create noL active rabbits
            }
            for(int i = 0; i < noA; i++){
                //create noA Lazy rabbits;
            }
        };
        void createWolf(int no){
            for(int i = 0; i < no; i++){
                //create wolves
            }
        };
        Animal* getAnimal(int x, int y){
            return cell[x][y].a;
        };
        void moveinto(int x, int y, Animal& newA){
            cell[y][z]->a = newA;
        };
        void eatGrass(int x, int y, Rabbit*);
        void Run();
        ~Grassland();
};
#endif
