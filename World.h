//Code for world header
#ifndef WORLD_H_
#define WORLD_H_

class World{
    int days;
    public:
        World();
        World(int day) : days(day){}
        friend class compareItem;
        int getDay(){return days;}
        void setDay(int day){day = day;}
        virtual void Run();
        virtual ~World(){}

};

struct compareItem : binary_function<World*, World*, bool>{
    bool operator(){const World* t1, const World* t2) const {
        return (t1->day > t2->day);
    }
};


#endif