#ifndef RABBIT_H
#define RABBIT_H
#include <iostream>
#include <vector>
#include "Grassland.h"
#include "Animal.h"
using namespace std;
class ActiveRabbit : public Animal{
    public:
        ActiveRabbit(int k,int i, bool hunger,  priority_queue<World*, vector<World*>, compareItem >* q1, Grassland* t): Animal(k, i, hunger, q1, t){}
        //void* Eat(); // Still thinking
        void Run(){
            if(getDay() <= 1000){
                double probability = 0.05; // Probability of DEATH AFTER 750 Days
                double result = rand() / RAND_MAX;
                if(getDay() >= 750 && (result < probability)){
                    hold->cell[this->x][this->y].a = NULL;
                }
                cout << "Day: " << getDay() << ", This is an Active Rabbit at: (" << x << "," << y << ")";
                setDay(getDay() + 2);
                setHunger(1);
                if(getHunger() == 1){
                    hold->eatGrass(x, y, this);
                }
                q->push(this);
            }
        } //This will do something, gutta add more functionaly.. requeue, death etc..
        ~ActiveRabbit(){}
};

class LazyRabbit : public Animal{
    public:
        LazyRabbit(int k,int i, bool hunger, priority_queue<World*, vector<World*>, compareItem >* q1, Grassland* t): Animal(k, i, hunger, q1, t){}
        //void* Eat(); // Still thinking
        void Run(){
            if(getDay() <= 10000){
                if(getDay() == 450){ // death after 450 days
                    hold->cell.a[this->x][this->y] = NULL;
                }
                cout <<"Day: " << getDay() << ", This is a Lazy Rabbit at : (" << x << "," << y << ")";
                setDay(getDay() + 1);
                setHunger(1);
                if(getHunger() == 1){
                    hold->eatGrass(x, y, this);
                }
                q->push(this);
            }
        }
        // This will do something still have add more functions like requeue and etc
        ~LazyRabbit(){}
};

#endif
