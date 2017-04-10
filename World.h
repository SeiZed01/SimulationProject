//Code for world header
#ifndef WORLD_H_
#define WORLD_H_

class World{
public:
	bool grass;
	int day;
	int growth = 0;
	void setGrasstrue();
	void grow();
	void eatGrass();
	World();
	~World();
};

#endif
