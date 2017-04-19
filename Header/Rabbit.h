#ifndef RABBIT_H
#define RABBIT_H
#include <iostream>
#include <vector>
#include "Grassland.h"
#include <stdlib.h>
#include "Animal.h"
using namespace std;
class ActiveRabbit : public Animal{ //Active rabbit inherits directly from animal
    public:
        ActiveRabbit(int k,int i, int hunger,  priority_queue<World*, vector<World*>, compareItem >* q1, Grassland* t): Animal(k, i, hunger, q1, t){}
        void Run(){ //checks various conditions, hunger, death, etc
            if(getDay() <= 10000){
                cout <<"Day: " << getDay() << ", This is a Active Rabbit at : (" << x << "," << y << ")";
                double probability = 0.05; // Probability of DEATH AFTER 750 Days
                double result = (double)rand() / RAND_MAX;
                if(getDay() >= 750 && (result <= probability)){ //checks chance of death after day 750
                    hold->rCount -= 1;
                    hold->cell[this->x][this->y].a = NULL;
//                    delete this; // gets rid of the animal
                }
                if(hold->cell[this->x][this->y].a != NULL){
                    setDay(getDay() + 2);
                    if(getHunger() >= 0){
                        hold->eatGrass(x, y, this);
                        setHunger(0);
                    }
                    q->push(this);
                }
                else{
                    cout << " This rabbit has died today.." << endl;
                }
            }
            cout << endl;
        }
        ~ActiveRabbit(){}
};

class LazyRabbit : public Animal{
    public:
        LazyRabbit(int k,int i, int hunger, priority_queue<World*, vector<World*>, compareItem >* q1, Grassland* t): Animal(k, i, hunger, q1, t){}
        void Run(){ //checks various conditions, hunger, death, etc
            cout <<"Day: " << getDay() << ", This is a Lazy Rabbit at : (" << x << "," << y << ")";
            if(getDay() <= 10000){
                hold->growGrass();
                if(getDay() == 450){ // death after 450 days
                    hold->rCount -= 1;
                    hold->cell[this->x][this->y].a = NULL;
                //    delete this;
                }
                if(hold->cell[this->x][this->y].a != NULL){
                    setDay(getDay() + 1);
                    if(getHunger() >= 0){
                        hold->eatGrass(x, y, this);
                        setHunger(0);
                    }
                    q->push(this);
                }
                else{
                    cout << " This rabbit has died today.." << endl;
                }
            }
            cout << endl;
        }

        ~LazyRabbit(){}
};

#endif
