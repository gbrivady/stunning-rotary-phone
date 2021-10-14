#ifndef ENTITY_HPP
#define ENTITY_HPP
#include <tuple>
#include "physic/cinematic.hpp"

typedef std::tuple<float, float> Hitbox;
typedef std::tuple<int, std::tuple<int, int, int>> Sprite;

class Entity
{
private:
    Trajectory traj;
    Hitbox hitbox;
    Sprite sprite;
public:
    Entity(Trajectory traj, Hitbox hitbox, Sprite sprite);
};



#endif