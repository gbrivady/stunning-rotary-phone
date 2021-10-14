#ifndef PHYSIC_CINEMATIC_HPP
#define PHYSIC_CINEMATIC_HPP
#include <tuple>

class Trajectory
{
private:
    std::tuple<float, float> x;
    std::tuple<float, float> v;

public:
    Trajectory(std::tuple<float, float> x, std::tuple<float, float> v);
    Trajectory(float x, float y, float vx, float vy);
    std::tuple<float, float> GetPosition();
    std::tuple<float, float> GetSpeed();
    std::tuple<float, float> SetPosition();
    std::tuple<float, float> SetSpeed();
};

#endif