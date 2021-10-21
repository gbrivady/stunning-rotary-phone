#include "physic/forces.hpp"

tuple<double, double> gravity(Terrain terrain){
    return terrain.getG();
}

tuple<double, double> viscosity(Entity entity, Terrain terrain){
    tuple<double, double> temp;
    get<0>(temp) = -terrain.getNu()*get<0>(entity.getSpeed());
    get<1>(temp) = 0;
    return temp;
}