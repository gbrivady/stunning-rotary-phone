#include "physic/cinematic.hpp"

Trajectory::Trajectory(std::tuple<float, float> x, std::tuple<float, float> v){
    this->x = x;
    this->v = v;
}

Trajectory::Trajectory(float x, float y, float vx, float vy){
    this->x = std::make_tuple(x, y);
    this->v = std::make_tuple(vx, vy);
}

std::tuple<float, float> Trajectory::getPosition(){
    return this->x;
}

std::tuple<float, float> Trajectory::getSpeed(){
    return this->v;
}

void Trajectory::setPosition(std::tuple<float, float> x){
    this->x = x;
}

void Trajectory::setSpeed(std::tuple<float, float> v){
    this->x = x;
}
