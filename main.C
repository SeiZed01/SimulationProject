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

int main(int argc, char* argv[]){ //main function takes in arguments for the number of wolves and rabbits
    if(argc <= 2 || argc >=4) //error check message for improper variables.
        cout << "Invalid number of arguments in the terminal!" << endl;
        cout << "Please enter in two numbers separated by a space. First # is Wolf, Second is Rabbit" << endl;
    else{ //creates wolves based on the input arguments and runs
        int wolf = atoi(argv[1]); 
        int rabbits = atoi(argv[2]);
        priority_queue<World*, vector<World*>, compareItem > pq; //creates priority queue
        Grassland* g1 = new Grassland(450, &pq); //grassland created with constructor that takes queue
        g1->addAnimals(wolf, rabbits); //creates the initial animals
        pq.push(g1); //pushes g1 to the queue
        while(!pq.empty()){ //runs the simulator
            World* i = pq.top();
            pq.pop();
            i->Run(); //runs the world items, either Grassland, Wolf, Active Rabbit, or Lazy rabbit
        }
        delete g1; //clean up
    }
}
