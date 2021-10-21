#ifndef PHYSIC_COLLISION_HPP
#define PHYSIC_COLLISION_HPP
#include <vector>
#include <tuple>
#include <cmath>
#include <limits>
#include "physic/cinematic.hpp"
#include "physic/hitbox.hpp"
#include "entity.hpp"
#include "terrain.hpp"

using namespace std;

void checkCollisions(vector<Entity>* entities, Terrain terrain);

tuple<double, tuple<double, double>> collideTRRN(Entity entity, Terrain terrain);
tuple<double, tuple<double, double>> collideHTBX(Hitbox hitbox1, tuple<double, double> g1, Hitbox hitbox2, tuple<double, double>);

double isSeparatingAxis(tuple<double, double> n, vector<tuple<double, double>> vertices1, tuple<double, double> g1,
                                                 vector<tuple<double, double>> vertices2, tuple<double, double> g2);

double inner_product(tuple<double, double> t1, tuple<double, double> t2);
double inner_product(tuple<double, double> t1, tuple<double, double> t2, tuple<double, double> g2);

tuple<double, double> normalize(tuple<double, double> t);

tuple<double, double> normalVector(tuple<double, double> t1, tuple<double, double> t2);

#endif