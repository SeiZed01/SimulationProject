#ifndef GRASSLAND_H
#define GRASSLAND_H

#include "World.h"
#include "Cells.h"
#include <iostream>
#include <vector>
class Animal;
using namespace std;

class Grassland : public World{ //grassland class inherits from the world class
    priority_queue<World*, vector<World*>, compareItem >* q;
    public:
        Cells **cell; //pointer to create two dimensional array
        Grassland(int day, priority_queue<World*, vector<World*>, compareItem >* q1): World(day), q(q1){
        cell = new Cells*[512]; //creates the tile area
        for(int i = 0; i < 512; i++)
            cell[i] = new Cells[512];
        }
//        bool roam(int x, int y); // Checks surround area to see if place is available to eat or just roam around.
        void addWolf(int xWolf); // Helper Function to add animals
        void addRabbit(int ar, int lr); // Helper function to add animals
        void addAnimals(int x, int y); //Helper function to add animals
       //Rabbit* getRabbitClose(int x, int y);
        void eatGrass(int x, int y, Animal*);
        virtual void Run(){ 
            if(getDay() <= 1000){
                cout << "In Grassland " << getDay() << endl;
                setDay(getDay() + 450);
                q->push(this);
            }
        }
        ~Grassland(){delete cell;} //cleans up cells
};
#endif
