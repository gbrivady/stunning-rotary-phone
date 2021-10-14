#include "entity.hpp"

Entity::Entity(Trajectory traj, Hitbox hitbox, Sprite sprite){
    this->traj = traj;
    this->hitbox = hitbox;
    this->sprite = sprite;
}