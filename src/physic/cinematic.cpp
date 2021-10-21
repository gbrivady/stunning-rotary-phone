#include "physic/cinematic.hpp"

PhysicPar::PhysicPar(double mass){
    this->mass = mass;
}

double PhysicPar::getMass(){
    return this->mass;
}
Trajectory::Trajectory(std::tuple<double, double> x, std::tuple<double, double> v){
    this->x = x;
    this->v = v;
}

Trajectory::Trajectory(double x, double y, double vx, double vy){
    this->x = std::make_tuple(x, y);
    this->v = std::make_tuple(vx, vy);
}

std::tuple<double, double> Trajectory::getPosition(){
    return this->x;
}

std::tuple<double, double> Trajectory::getSpeed(){
    return this->v;
}

void Trajectory::setPosition(std::tuple<double, double> x){
    this->x = x;
}

void Trajectory::setSpeed(std::tuple<double, double> v){
    this->v = v;
}

void Trajectory::move(tuple<double, double> u){
    tuple<double, double> temp = this->x;
    get<0>(temp) += get<0>(u);
    get<1>(temp) += get<1>(u);
    this->setPosition(temp);
}

void Trajectory::accelerate(tuple<double, double> a){
    tuple<double, double> temp = this->v;
    get<0>(temp) += get<0>(a);
    get<1>(temp) += get<1>(a);
    this->setSpeed(temp);
}