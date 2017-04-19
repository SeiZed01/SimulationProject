#ifndef WOLF_H
#define WOLF_H
#include "Animal.h"
#include <stdlib.h>
using namespace std;

class Wolf : public Animal{ //wolf inherits from Animal
    public:
        Wolf(int k, int i, bool hunger, priority_queue<World*, vector<World*>, compareItem >* q1, Grassland* t): Animal(k, i, hunger, q1, t){}
        void Run(){ //checks hunger
            if(getDay() <= 10000){
                double probability = 0.01;
                double result = rand() / RAND_MAX;
                if(getDay() >= 800 && (result < probability)){ // 1% chance to die after 800 days
                    hold->cell[this->x][this->y].a = NULL;
                    delete this;
                }
                cout << "Day: " << getDay() << ", I am a Wolf at: (" << x << "," << y << ")";
                if(hold->cell[this->x][this->y].a != NULL){
                    setDay(getDay() + 4);
                    q->push(this);
                }
                else
                    cout << " this Wolf has died today.. " << endl;
            }
        } 
        ~Wolf(){}
};
#endif
