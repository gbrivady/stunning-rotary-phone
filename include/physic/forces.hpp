#ifndef PHYSIC_FORCES_HPP
#define PHYSIC_FORCES_HPP
#include <tuple>
#include "entity.hpp"
#include "terrain.hpp"
using namespace std;

tuple<double, double> gravity(Terrain terrain);
tuple<double, double> viscosity(Entity entity, Terrain terrain);

#endif