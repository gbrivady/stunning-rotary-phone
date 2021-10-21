#ifndef PHYSIC_CINEMATIC_HPP
#define PHYSIC_CINEMATIC_HPP
#include <tuple>
#include <vector>

using namespace std;

class PhysicPar
{
private:
    double mass;
public:
    PhysicPar() = default;
    PhysicPar(double mass);
    double getMass();
};


class Trajectory
{
private:
    std::tuple<double, double> x;
    std::tuple<double, double> v;

public:
    Trajectory() = default;
    Trajectory(std::tuple<double, double> x, std::tuple<double, double> v);
    Trajectory(double x, double y, double vx, double vy);
    std::tuple<double, double> getPosition();
    std::tuple<double, double> getSpeed();
    void setPosition(std::tuple<double, double> x);
    void move(std::tuple<double, double> u);
    void setSpeed(std::tuple<double, double> v);
    void accelerate(tuple<double, double> a);
};


#endif