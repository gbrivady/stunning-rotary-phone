#ifndef PHYSIC_HITBOX_HPP
#define PHYSIC_HITBOX_HPP
#include <tuple>
#include <vector>
using namespace std;

class Hitbox
{
private:
    vector<tuple<double, double>> vertices;
public:
    Hitbox() = default;
    Hitbox(vector<tuple<double, double>> vertices);
    vector<tuple<double, double>> getVertices();
};

#endif