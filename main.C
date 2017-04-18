//Hung Nguyen
//Joseph Frazier
//CSCE 240 Final Project
//Simulation should run fine with Priority Queue.
#include "World.h"
#include "Grassland.h"
#include <queue>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
    if(argc <= 2 || argc >=4)
        cout << "Invalid number of arguments in the terminal! Please enter in two numbers separated by a space. First # is Wolf, Second is Rabbit" << endl;
    else{
        int wolf = atoi(argv[1]);
        int rabbits = atoi(argv[2]);
        priority_queue<World*, vector<World*>, compareItem > pq;
        Grassland* g1 = new Grassland(450, &pq);
        g1->addAnimals(wolf, rabbits);
        pq.push(g1);
        while(!pq.empty()){
            World* i = pq.top();
            pq.pop();
            i->Run();
        }
        delete g1;
    }
}
