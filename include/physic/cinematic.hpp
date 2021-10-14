#ifndef PHYSIC_CINEMATIC_HPP
#define PHYSIC_CINEMATIC_HPP
#include <tuple>


class Trajectory
{
private:
    std::tuple<float, float> x;
    std::tuple<float, float> v;

public:
    Trajectory() = default;
    Trajectory(std::tuple<float, float> x, std::tuple<float, float> v);
    Trajectory(float x, float y, float vx, float vy);
    std::tuple<float, float> getPosition();
    std::tuple<float, float> getSpeed();
    void setPosition(std::tuple<float, float> x);
    void setSpeed(std::tuple<float, float> v);
};

#endif