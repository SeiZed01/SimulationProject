#ifndef WOLF_H
#define WOLF_H
#include "Animal.h"
#include <stdlib.h>
using namespace std;

class Wolf : public Animal{ //wolf inherits from Animal
    public:
        Wolf(int k, int i, int hunger, priority_queue<World*, vector<World*>, compareItem >* q1, Grassland* t): Animal(k, i, hunger, q1, t){}
        void Run(){ //checks hunger
            if(getDay() <= 1000){
                cout << "Day: " << getDay() << ", I am a Wolf at: (" << x << "," << y << ")";

                double probability = 0.01;
                double result = (double)rand() / RAND_MAX;
                if(getDay() >= 800 && (result < probability)){ // 1% chance to die after 800 days
                    hold->wCount -= 1;
                    cout << " this Wolf has died today.. " << endl;
                    hold->cell[this->x][this->y].a = NULL;
                    delete this;
                    return;
                }
                if(getHunger() > 20){ // Death hasnt eaten in 20 days
                    hold->cell[x][y].a = NULL;
                    cout << " this Wolf has died today.. " << endl;
                    hold->wCount -= 1;
                    delete this;
                    return;
                }
                if(hold->cell[x][y].a != NULL){
                    setDay(getDay() + 4);
                   /* if(getHunger() >= 0){ // Commented out line below check logic.
                        Animal* r = hold->eatRabbit(x, y);
                        if(r != NULL){
                            hold->cell[r->x][r->y].a = this;
                            this->x = r->x; this->y= r->y;
                            setHunger(0);
                            &r = NULL;
                     
                        }
                        else{
                            setHunger(getHunger() + 1);
 hold->roam(x, y, this);
                            }
                        q->push(this);
        
                }*/
                   q->push(this);
                }
            }
            cout << endl;
        }
        ~Wolf(){}
};
#endif
