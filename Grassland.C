#include "Grassland.h"
#include "Rabbit.h"
#include "Wolf.h"
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;

void Grassland::addWolf(int xWolf){
    int x = rand() % 512;
    int y = rand() % 512;
    for(int i = 0; i < xWolf; i++){
        while(cell[x][y].a != NULL){
            x = rand() % 512;
            y = rand() % 512;
        }
        cell[x][y].a = new Wolf(4, 4, false, q, this);
        q->push(cell[x][y].a);
        cell[x][y].x = x;
        cell[x][y].y = y;
        cell[x][y].a->x = x;
        cell[x][y].a->y = y;
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
        cell[x][y].a = new ActiveRabbit(2, 2,  false, q, this);
        q->push(cell[x][y].a);
        cell[x][y].x = x;
        cell[x][y].y = y;
        cell[x][y].a->x = x;
        cell[x][y].a->y = y;

    }
    //Adding Lazy Rabbits Below
    x = rand() % 512;
    y = rand() % 512;

    for(int i = 0; i < lr; i++){
        while(cell[x][y].a != NULL){
            x = rand() % 512;
            y = rand() % 512;
        }
        cell[x][y].a = new LazyRabbit(1, 1, true, q, this);
        q->push(cell[x][y].a);
        cell[x][y].x = x;
        cell[x][y].y = y;
        cell[x][y].a->x = x;
        cell[x][y].a->y = y;

    }
}

void Grassland::addAnimals(int xWolf, int yRabbits){
    addWolf(xWolf);
    int ar = yRabbits / 2;
    int lr = yRabbits / 2;
    addRabbit(ar, lr);
}

void Grassland::eatGrass(int x, int y, Animal* r){
    if(r->getID() == 1){
        for(int i = max(0, x-5); i <= min(x+5, 511);i++){
            if(r->getHunger() == 0)
                break;
            for(int j = max(0, y-5); j<= min(j+5, 511);j++){
                if(i != x || j != y){
                    if(cell[i][j].lastEaten == 10){
                        cell[i][j].a = r;
                        cell[i][j].lastEaten = 0;
                        r->setHunger(0);
                        cell[i][j].a->x = i;
                        cell[i][j].a->y = j;
                        cout << ", Grass eaten at: (" << i << "," << j << ")" << endl;
                        cell[x][y].a = NULL;
                        break;
                        }
                }
            }
        }
    }
