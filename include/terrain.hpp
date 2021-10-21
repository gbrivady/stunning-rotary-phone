#ifndef TERRAIN_HPP
#define TERRAIN_HPP
#include <tuple>

using namespace std;

class Terrain{
private:
    tuple<double, double> g; //gravity
    double nu; //viscosity
public:
    Terrain(tuple<double, double> g, double nu);
    tuple<double, tuple<double, double>> hitbox(double x, double y);
    tuple<double, double> getG();
    double getNu();
};

#endif