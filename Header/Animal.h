#ifndef ANIMAL_H
#define ANIMAL_H
#include "World.h"
#include <iostream>
#include <vector>
using namespace std;
class Grassland;
class Animal : public World{
    bool hunger;
    int ID;
    public:
        int x, y;
        Grassland* hold;
        priority_queue<World*, vector<World*>, compareItem >* q;
        Animal(int day, int i,  bool hunger, priority_queue<World*, vector<World*>, compareItem>* q1, Grassland* t): World(day), hunger(hunger), hold(t), q(q1), ID(i){}
        int getID(){return ID;}
        void setHunger(bool k){hunger = k;}
        bool getHunger(){return hunger;}
        virtual void Run(){} // Implement death and hunger and etc in Run Func.
        //virtual void* Eat(); // Find something to eat within certain parameter then delete pointer. 
       // virtual void doublePopulation();
        virtual ~Animal(){}
};

#endif
