#include "entity.hpp"

Entity::Entity(Trajectory traj, Hitbox hitbox, Sprite sprite, PhysicPar phxP){
    this->traj = traj;
    this->hitbox = hitbox;
    this->sprite = sprite;
    this->phxP = phxP;
}

tuple<double, double> Entity::getSpeed(){
    return this->traj.getSpeed();
}

tuple<double, double> Entity::getPosition(){
    return this->traj.getPosition();
}

Hitbox Entity::getHitbox(){
    return this->hitbox;
}
Sprite Entity::getSprite(){
    return this->sprite;
}
PhysicPar Entity::getPhyX(){
    return this->phxP;
}

void Entity::setPosition(tuple<double, double> x){
    this->traj.setPosition(x);
}

void Entity::setSpeed(tuple<double, double> v){
    this->traj.setSpeed(v);
}

void Entity::stopFall(){
    this->setSpeed(make_tuple(get<0>(this->getSpeed()), 0));
}
bool Entity::isFalling(){
    return get<1>(this->getSpeed()) != 0;
}

void Entity::move(tuple<double, double> u){
    this->traj.move(u);
}
void Entity::accelerate(tuple<double, double> a){
    this->traj.accelerate(a);
}

void Entity::onCollision(Entity, tuple<double, tuple<double, double>> colVector){

}

void Entity::onCollision(Terrain terrain, tuple<double, tuple<double, double>> colVector){
    //gently moves it back to where it was
    tuple<double, double> gowoBack = make_tuple(get<0>(colVector)*get<0>(get<1>(colVector))+1e-10,
                                                get<0>(colVector)*get<1>(get<1>(colVector))+1e-10);
    this->move(gowoBack);
    this->stopFall();
    // gowoBack = this->getSpeed();
    // this->setSpeed(make_tuple(get<0>(gowoBack), -get<1>(gowoBack)));
}