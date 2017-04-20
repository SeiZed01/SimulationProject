#ifndef GRASSLAND_H
#define GRASSLAND_H

#include "World.h"
#include "Cells.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
class Animal;
using namespace std;

class Grassland : public World{ //grassland class inherits from the world class
    priority_queue<World*, vector<World*>, compareItem >* q;
    public:
        int wCount = 0; // Wolf Counter
        int rCount = 0; // Rabbit Counter
        int reproduceDay = rand() % 100 + 400;
    
        //void roam(int x, int y, Animal*); // Wolf roams if cant find food.
        Cells **cell; //pointer to create two dimensional array
        Grassland(int day, priority_queue<World*, vector<World*>, compareItem >* q1): World(day), q(q1){
        cell = new Cells*[512]; //creates the tile area
        for(int i = 0; i < 512; i++)
            cell[i] = new Cells[512];
        }
        void addWolf(int xWolf); // Helper Function to add animals
        void addRabbit(int ar, int lr); // Helper function to add animals
        void addAnimals(int x, int y); //Helper function to add animals
        //void eatRabbit(int x, int y, Animal*);
        void eatGrass(int x, int y, Animal*);
        void growGrass(); // Grow grass each cell daily helper function
        virtual void Run(){
            if(getDay() == reproduceDay){
                cout << "Reproduction day!" << endl;
                reproduceDay = reproduceDay + (rand() % 100 + 400);
                    
            }
            if(getDay() <= 10000){
                
                cout << "In Grassland " << getDay() << endl;
                setDay(getDay() + 450);
                q->push(this);
            }
        }
        ~Grassland(){ // clean up cells
            delete[] cell;
        }
};
#endif
