#ifndef ANIMAL_H
#define ANIMAL_H
#include "World.h"
#include <iostream>
#include <vector>
using namespace std;

class Animal : public World{
    bool hunger;
    public:
        priority_queue<World*, vector<World*>, compareItem >* q;
        Animal(int day, bool hunger, priority_queue<World*, vector<World*>, compareItem>* q1): World(day), hunger(hunger), q(q1){}
        void setHunger(bool k){hunger = k;}
        bool getHunger(){return hunger;}
        virtual void Run(){} // Implement death and hunger and etc in Run Func.
        //virtual void* Eat(); // Find something to eat within certain parameter then delete pointer. 
       // virtual void doublePopulation();
        virtual ~Animal(){}
};

#endif
