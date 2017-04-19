//Code for world header
//Copied & Modified from Dr. Tang's Item.h
#ifndef WORLD_H_
#define WORLD_H_
#include <functional>
#include <vector>
#include <queue>
using namespace std;
class World{
    int days;
    public:
        World(){}
        World(int day) : days(day){}
        friend class compareItem;
        int getDay(){return days;}
        void setDay(int day){days = day;}
        virtual void Run(){}
        virtual ~World(){}

};

struct compareItem : public binary_function<World*, World*, bool>{
    bool operator()(const World* t1, const World* t2) const {
        return (t1->days > t2->days);
    }
};


#endif




