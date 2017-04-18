#ifndef WOLF_H
#define WOLF_H
#include "Animal.h"
using namespace std;

class Wolf : public Animal{ //wolf inherits from Animal
    public:
        Wolf(int k, int i, bool hunger, priority_queue<World*, vector<World*>, compareItem >* q1, Grassland* t): Animal(k, i, hunger, q1, t){}
        void Run(){ //checks hunger
            if(getDay() <= 1000){
                cout << "Day: " << getDay() << ", I am a Wolf at: (" << x << "," << y << ")" << endl;
                setDay(getDay() + 4);
                q->push(this);
            }
        } // Needs work
        ~Wolf(){}
};
#endif
