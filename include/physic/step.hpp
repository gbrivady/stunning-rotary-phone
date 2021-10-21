#ifndef PHYSIC_STEP_HPP
#define PHYSIC_STEP_HPP
#include <vector>
#include <tuple>
#include "terrain.hpp"
#include "physic/forces.hpp"
#include "physic/cinematic.hpp"
#include "physic/collision.hpp"
#include "entity.hpp"
using namespace std;

void phXStep(vector<Entity>* entities, vector<tuple<double, double>> moves, vector<tuple<double, double>> acc, Terrain terrain);
void pfd(vector<Entity>* entities, vector<tuple<double, double>> moves, vector<tuple<double, double>> acc, Terrain terrain);

#endif