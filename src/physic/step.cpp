#include "physic/step.hpp"
void phXStep(vector<Entity>* entities, vector<tuple<double, double>> moves, vector<tuple<double, double>> acc, Terrain terrain){
    pfd(entities, moves, acc, terrain);
    checkCollisions(entities, terrain);
}

void pfd(vector<Entity>* entities, vector<tuple<double, double>> moves, vector<tuple<double, double>> acc, Terrain terrain){
    PhysicPar par;
    tuple<double, double> temp;
    tuple<double, double> a;
    tuple<double, double> u;
    //for each entity
    for(int i = 0; i < entities->size(); i++){
        a = make_tuple(0, 0);
        //apply the constrained moves and speed
        u = make_tuple(0, 0);
        get<0>(u) += get<0>(moves[i]);
        get<1>(u) += get<1>(moves[i]);
        get<0>(u) += get<0>((*entities)[i].getSpeed());
        get<1>(u) += get<1>((*entities)[i].getSpeed());
        (*entities)[i].move(u);
        //stack the accellerations
        get<0>(a) += get<0>(acc[i]);
        get<1>(a) += get<1>(acc[i]);
        //calculate each force
        par = (*entities)[0].getPhyX();

        //gravity
        if(par.getMass() > 0 && (*entities)[i].isFalling()){
            temp = gravity(terrain);
            get<0>(a) += get<0>(temp);
            get<1>(a) += get<1>(temp);
        }
        //viscosity
        temp = viscosity((*entities)[i], terrain);
        get<0>(a) += get<0>(temp);
        get<1>(a) += get<1>(temp);
        //update speed
        (*entities)[i].accelerate(a);
    }
}
