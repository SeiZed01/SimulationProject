#ifndef ANIMAL_H
#define ANIMAL_H
#include "World.h"
#include <iostream>
#include <vector>
using namespace std;

class Animal : public World{
    priority_queue<World*, vector<World*>, compareItem >* q;
    bool hunger;
    public:
        Animal(bool k): hunger(k){}
        Animal(int day, priority_queue<Item*, vector<Item*>, compareItem>* q1): World(day), q(q1){}
        void setHunger(bool k){hunger = k;}
        bool getHunger(){return hunger;}
        void Run(); // Implement death and hunger and etc in Run Func.
        virtual void* Eat(); // Find something to eat within certain parameter then delete pointer. 
        virtual void doublePopulation();
        ~Animal();
};

#endif
