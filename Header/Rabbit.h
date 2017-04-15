#ifndef RABBIT_H
#define RABBIT_H
#include <iostream>
#include <vector>
#include "Animal.h"
using namespace std;

class ActiveRabbit : public Animal{
    public:
        ActiveRabbit(int k, bool hunger,  priority_queue<World*, vector<World*>, compareItem >* q1): Animal(k, hunger, q1){}
        //void* Eat(); // Still thinking
        void Run(){
            if(getDay() <= 10000){
                cout << "This is an Active Rabbit: " << getDay() << endl;
                setDay(getDay() + 2);
                q->push(this);
            }
        } //This will do something, gutta add more functionaly.. requeue, death etc..
        ~ActiveRabbit(){}
};

class LazyRabbit : public Animal{
    public:
        LazyRabbit(int k, bool hunger, priority_queue<World*, vector<World*>, compareItem >* q1): Animal(k, hunger, q1){}
        //void* Eat(); // Still thinking
        void Run(){
            if(getDay() <= 10000){
                cout << "This is a Lazy Rabbit: " << getDay() << endl;
                setDay(getDay() + 1);
                q->push(this);
            }
        }
        // This will do something still have add more functions like requeue and etc
        ~LazyRabbit(){}
};

#endif
