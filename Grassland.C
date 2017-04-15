#include "Grassland.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

void Grassland::addWolf(int xWolf){
    int x = rand() % 512;
    int y = rand() % 512;
    for(int i = 0; i < xWolf; i++){
        while(cell[x][y].a != NULL){
            x = rand() % 512;
            y = rand() % 512;
        }
        cell[x][y].a = new Wolf(4, false, q);
        q->push(cell[x][y].a);
        cell[x][y].x = x;
        cell[x][y].y = y;
    }
}

void Grassland::addRabbit(int ar, int lr){
    // Adding Active Rabbits 
    // Might need a counter to keep track so we can double
    int x = rand() % 512;
    int y = rand() % 512;
    for(int i = 0; i < ar; i++){
        while(cell[x][y].a != NULL){
            x = rand() % 512;
            y = rand() % 512;
        }
        cell[x][y].a = new ActiveRabbit(2, false, q);
        q->push(cell[x][y].a);
        cell[x][y].x = x;
        cell[x][y].y = y;
    }
    //Adding Lazy Rabbits Below
    x = rand() % 512;
    y = rand() % 512;

    for(int i = 0; i < lr; i++){
        while(cell[x][y].a != NULL){
            x = rand() % 512;
            y = rand() % 512;
        }
        cell[x][y].a = new LazyRabbit(1, false, q);
        q->push(cell[x][y].a);
        cell[x][y].x = x;
        cell[x][y].y = y;
    }
}

void Grassland::addAnimals(int xWolf, int yRabbits){
    addWolf(xWolf);
    int ar = yRabbits / 2;
    int lr = yRabbits / 2;
    addRabbit(ar, lr);
}
