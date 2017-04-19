#include "Grassland.h"
#include "Rabbit.h"
#include "Wolf.h"
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;

void Grassland::addWolf(int xWolf){ //adds wolves based on number of argument xWolf
    int x = rand() % 512; //creates x coordinate
    int y = rand() % 512; //creates y coordinate
    for(int i = 0; i < xWolf; i++){
        while(cell[x][y].a != NULL){ //if cell is currently occupied coordinates are rerolled
            x = rand() % 512;
            y = rand() % 512;
        }
        cell[x][y].a = new Wolf(4, 4, 0, q, this); //creates wolf at open coordinates
        wCount += 1;
        q->push(cell[x][y].a);
        //sets cell coordinates and stores them in cell and animal
        cell[x][y].x = x;
        cell[x][y].y = y;
        cell[x][y].a->x = x;
        cell[x][y].a->y = y;
    }
}

void Grassland::addRabbit(int ar, int lr){ //takes in count of lazy and active rabbits
    // Adding Active Rabbits 
    // Might need a counter to keep track so we can double
    int x = rand() % 512; //creates x coordinate
    int y = rand() % 512; //creates y coordinate
    for(int i = 0; i < ar; i++){
        while(cell[x][y].a != NULL){//rerolls coordinates if cell is occupied
            x = rand() % 512;
            y = rand() % 512;
        }
        cell[x][y].a = new ActiveRabbit(2, 2,  0, q, this); //creates active rabbit
        rCount += 1;
        q->push(cell[x][y].a);
        //stores coordinates in cell and animal
        cell[x][y].x = x;
        cell[x][y].y = y;
        cell[x][y].a->x = x;
    }
  //Adding Lazy Rabbits Below
    x = rand() % 512; //creates x coordinate
    y = rand() % 512; //creates y coordinate

    for(int i = 0; i < lr; i++){
        while(cell[x][y].a != NULL){ //rerolls coordinates if cell is occupied
            x = rand() % 512;
            y = rand() % 512;
        }
        cell[x][y].a = new LazyRabbit(1, 1, 0, q, this);//creates lazy rabbit
        rCount += 1;
        q->push(cell[x][y].a);
        //stores coordinates in cell and animal
        cell[x][y].x = x;
        cell[x][y].y = y;
        cell[x][y].a->x = x;
        cell[x][y].a->y = y;

    }
}

void Grassland::addAnimals(int xWolf, int yRabbits){ //creates initial animals
    addWolf(xWolf);
    int ar = yRabbits / 2;
    int lr = yRabbits / 2;
    addRabbit(ar, lr);
}

//Code Below is Roaming for Wolf, Logic should be correct. 
/*void Grassland::roam(int x, int y, Animal* r){
    bool found = false;
    for(int i = max(0, x-16); i <= min(x+16, 511);i++){
        if(found == 1)
            break;
        for(int j = max(0, y-16);j<=min(j+16,511)j++){
            if(cell[i][j].a == NULL){
                found = true;
                cell[i][j].a = r;
                cell[x][y].a = NULL; // after moves, set previous cell to NULL
                break;
            }
        }
    }
}*/

void Grassland::eatGrass(int x, int y, Animal* r){ //function takes in coordinates x,y and rabbit, eats grass at location
    if(r->getID() == 1){ // This is for Lazy Rabbit
        for(int i = max(0, x-5); i <= min(x+5, 511);i++){
            if(r->getHunger() == 0) //if rabbit is not hungry, function ends
                break;
            for(int j = max(0, y-5); j<= min(j+5, 511);j++){
                if(i != x || j != y){ //checks if grass is available to be eaten
                    if(cell[i][j].lastEaten == 10){
                        cell[i][j].a = r;
                        cell[i][j].lastEaten = 0;
                        cell[i][j].a->x = i;
                        cell[i][j].a->y = j;
                         cout << ", Grass eaten at: (" << i << "," << j << ")" << endl;
                        cell[x][y].a = NULL; //removes rabbit from previous cell
                        break;
                        }
                    else
                        r->setHunger(getHunger() + 1);
                }
            }
        }
    }
    if(r->getID() == 2){ // This is For Active Rabbit
        for(int i = max(0, x-10); i<= min(x+10, 511);i++){
            if(r->getHunger() == 0) //if rabbit is not hungry, function ends
                break;
            for(int j = max(0, y-10); j<=min(y+10, 511);j++){
                if(i != x || j != y){ //checks if grass is available to be eaten
                    if(cell[i][j].lastEaten == 10){
                        cell[i][j].a = r;
                        cell[i][j].lastEaten = 0;
                        cell[i][j].a->x = i;
                        cell[i][j].a->y = j;
                        cout << ", Grass eaten at : (" << i << "," << j << ")" << endl;
                        cell[x][y].a = NULL; //removes rabbit from previous cell
                        break;
                    }
                    else
                        r->setHunger(getHunger() + 1);
                }
            }
        }
    }
}

//Below is the Code for eatingRabbits, please check logic.
/*void Grassland::eatRabbit(int x, int y, Animal* r){ // Code to find Rabbit in a 65x65 Neighborhood.
    bool test = false;
    for(int i = max(0, x-32); i <= min(x+32, 511); i++){
            if(test == 1){
                break;
            }
        for(int j = max(0, y-32); j <= min(j+32, 511);j++){
            if(i!= x || j!= y){ // checks boundaries
                if(hold->cell[i][j].a->getID() == 2 || hold->cell[i][j].a->getID() == 1){
                    test = true;
                    cell[i][j].a = r;
                    cell[i][j].a->x = i;
                    cell[i][j].a->y = j;
                    cout << ", Rabbit eaten at: (" << i << "," << j << ")" << endl;
                    cell[x][y].a = NULL;
                    break;
                }
                else
                    r->setHunger(getHunger() + 1);
            }
        }
    }
    if(bool == false){ // If can't find food, roam with function from above.
        roam(x, y, r);
    }
}*/

// Helper function to inrease grass daily
void Grassland::growGrass(){
    for(int i = 0; i < 512; i++){
        for(int j = 0; j < 512; j++){
            if(cell[i][j].lastEaten < 10)
                cell[i][j].lastEaten++;
        }
    }
}
