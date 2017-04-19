#ifndef WOLF_H
#define WOLF_H
#include "Animal.h"
#include <stdlib.h>
using namespace std;

class Wolf : public Animal{ //wolf inherits from Animal
    public:
        Wolf(int k, int i, int hunger, priority_queue<World*, vector<World*>, compareItem >* q1, Grassland* t): Animal(k, i, hunger, q1, t){}
        void Run(){ //checks hunger
            if(getDay() <= 10000){
                cout << "Day: " << getDay() << ", I am a Wolf at: (" << x << "," << y << ")";

                double probability = 0.01;
                double result = (double)rand() / RAND_MAX;
                if(getDay() >= 800 && (result < probability)){ // 1% chance to die after 800 days
                    hold->wCount -= 1;
                    hold->cell[this->x][this->y].a = NULL;
//                    delete this;
                }
                if(hold->cell[this->x][this->y].a != NULL){
                    setDay(getDay() + 4);
                    if(getHunger() >= 0){
                        hold->eatRabbit(x, y, this);
                        hold->setHunger(0);
                        q->push(this);
                    }
                   // q->push(this);
                }
                else{
                    cout << " this Wolf has died today.. " << endl;
                }
            }
            cout << endl;
        }
        ~Wolf(){delete this;}
};
#endif
