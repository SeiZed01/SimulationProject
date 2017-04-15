#ifndef GRASSLAND_H
#define GRASSLAND_H

#include "World.h"
#include "Animal.h"
#include "Wolf.h"
#include "Rabbit.h"
#include "Cells.h"
#include <iostream>
#include <vector>
using namespace std;

class Grassland : public World{
    priority_queue<World*, vector<World*>, compareItem >* q;
    public:
        Cells **cell;
        Grassland(int day, priority_queue<World*, vector<World*>, compareItem >* q1): World(day), q(q1){
        cell = new Cells*[512];
        for(int i = 0; i < 512; i++)
            cell[i] = new Cells[512];
        }
        void addWolf(int xWolf);
        void addRabbit(int ar, int lr);
        void addAnimals(int x, int y);
       //Rabbit* getRabbitClose(int x, int y);
        //void grow(); 
        //void eatGrass(int x, int y, Rabbit*);
        virtual void Run(){cout << "In Grassland " << getDay() << endl;
            setDay(getDay() + 25); /*q->push(this)*/;}
        ~Grassland(){delete cell;}
};
#endif
