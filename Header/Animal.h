#ifndef ANIMAL_H
#define ANIMAL_H
#include "World.h"
#include <iostream>
#include <vector>
using namespace std;
class Grassland;
class Animal : public World{ //animal class inherits from world
    bool hunger; //boolean for hunger
    int ID; //sets id of the animal, wolf = 4, active rabbit = 2, lazy rabbit = 1
    public:
        int x, y; //coordinates of current location
        Grassland* hold; //pointer towards the world
        priority_queue<World*, vector<World*>, compareItem >* q;
        Animal(int day, int i,  int hunger, priority_queue<World*, vector<World*>, compareItem>* q1, Grassland* t): World(day), hunger(hunger), hold(t), q(q1), ID(i){}
        int getID(){return ID;} //returns ID
        void setHunger(int k){hunger = k;} //takes in boolean, sets hunger boolean
        int getHunger(){return hunger;} //returns hunger boolean
        virtual void Run(){} // Implement death and hunger and etc in Run Func.
        //virtual void* Eat(); // Find something to eat within certain parameter then delete pointer. 
       // virtual void doublePopulation();
        virtual ~Animal(){} //destructor
};

#endif
