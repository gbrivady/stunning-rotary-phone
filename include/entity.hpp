#ifndef ENTITY_HPP
#define ENTITY_HPP
#include <tuple>
#include <limits>
#include "terrain.hpp"
#include "physic/cinematic.hpp"
#include "physic/hitbox.hpp"

using namespace std;

typedef std::tuple<int, std::tuple<int, int, int>> Sprite;

class Entity
{
private:
    Trajectory traj;
    Hitbox hitbox;
    Sprite sprite;
    PhysicPar phxP;

public:
    Entity(Trajectory traj, Hitbox hitbox, Sprite sprite, PhysicPar phxP);
    Trajectory getTrajectory();
    tuple<double, double> getSpeed();
    tuple<double, double> getPosition();
    Hitbox getHitbox();
    Sprite getSprite();
    PhysicPar getPhyX();
    void setSpeed(tuple<double, double> v);
    void setPosition(tuple<double, double> x);
    void stopFall();
    bool isFalling();
    void move(tuple<double, double> u);
    void accelerate(tuple<double, double> a);
    void onCollision(Entity entity, tuple<double, tuple<double, double>> colVector);
    void onCollision(Terrain terrain, tuple<double, tuple<double, double>> colVector);
    
};

class PEntity: Entity{

};

class NPEntity: Entity{

};



#endif