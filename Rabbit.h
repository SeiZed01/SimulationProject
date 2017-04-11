#ifndef RABBIT_H
#define RABBIT_H
#include <iostream>
#include <vector>
#include "Animal.h"
using namespace std;

class ActiveRabbit : public Animal{
    priority_queue<World*, vector<World*>, compareItem >* q;
    public:
        ActiveRabbit(int k, bool hunger,  priority_queue<World*, vector<World*>, compareItem >* q1): World(k), Animal(hunger), q(q1){}
        void* Eat(); // Still thinking
        void Run(); //This will do something
        ~ActiveRabbit();
};

class LazyRabbit : public Animal{
    priority_queue<World*, vector<World*>, compareItem >* q;
    public:
        LazyRabbit(int k, bool hunger, priority_queue<World*, vector<World*>, compareItem >* q1): World(k), Animal(hunger), q(q1){}
        void* Eat(); // Still thinking
        void Run(); // This will do something
        ~LazyRabbit();
};

#endif
