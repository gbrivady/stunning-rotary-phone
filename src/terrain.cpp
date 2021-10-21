#include "terrain.hpp"

Terrain::Terrain(tuple<double, double> g, double nu){
    this->g = g;
    this->nu = nu;
}

tuple<double, tuple<double, double>> Terrain::hitbox(double x, double y){
    return make_tuple(y-500, make_tuple(0,-1));
}

tuple<double, double> Terrain::getG(){
    return this->g;
}

double Terrain::getNu(){
    return this->nu;
}
