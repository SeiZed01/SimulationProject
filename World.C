// Initialize Functions of World Header
#include<iostream>
#include "World.h"

using namespace std;

World::World(){
	grass = true;
	day = 0;
}

World::~World(){
}

void World::setGrasstrue(){
	grass = true;
}

void World::eatGrass(){
	grass = false;
	growth = 9;
}

void World::grow(){
	if(grass == false && growth > 0) growth--;
	else if(grass == false && growth <= 0) setGrasstrue();
}
