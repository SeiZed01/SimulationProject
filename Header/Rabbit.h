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
            if(getDay() <= 100){
                cout << "This is an Active Rabbit: " << getDay() << endl;
                setDay(getDay() + 2);
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
            if(getDay() <= 100){
                cout <<"Day: " << getDay() << ", This is a Lazy Rabbit at : (" << x << "," << y << ")";
                setDay(getDay() + 1);
                setHunger(1);
                if(getHunger() == 1){
                    hold->eatGrass(x, y, this);
                }
                q->push(this);
            }
            //cout << endl;
        }
        // This will do something still have add more functions like requeue and etc
        ~LazyRabbit(){}
};

#endif
