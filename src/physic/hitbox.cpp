#include "physic/hitbox.hpp"

Hitbox::Hitbox(vector<tuple<double, double>> vertices){
    this->vertices = vertices;
}

vector<tuple<double, double>> Hitbox::getVertices(){
    return this->vertices;
}