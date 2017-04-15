#ifndef WOLF_H
#define WOLF_H
#include <iostream>
#include <vector>
#include "Animal.h"
using namespace std;

class Wolf : public Animal{
    public:
        Wolf(int k, bool hunger, priority_queue<World*, vector<World*>, compareItem >* q1): Animal(k, hunger, q1){}
        //void doublePopulation();
       // void* Eat(); // Might change Eat to Roam for all
        void Run(){
            if(getDay() <= 1000){
                cout << "I am a Wolf : " << getDay() << endl;
                setDay(getDay() + 4);
                q->push(this);
            }
        } // Needs work
        ~Wolf(){}
};
#endif
