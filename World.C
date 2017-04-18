// Initialize Functions of World Header
#include<iostream>
#include "World.h"

using namespace std;

World::World(){ //the base class constructor
	grass = true;
	day = 0; //initial day start
}

World::~World(){ //basic destructor
}

void World::setGrasstrue(){ //sets grass boolean to true
	grass = true;
}

void World::eatGrass(){ //sets grass boolean to false to represent it being eaten
	grass = false;
	growth = 9; //represents the length of time needed to regrow
}

void World::grow(){ //regrows grass
	if(grass == false && growth > 0) growth--;
	else if(grass == false && growth <= 0) setGrasstrue();
}
