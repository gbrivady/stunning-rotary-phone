#include "main.hpp"
using namespace std;

int main(int argc, char** argv)
{
    //DEBUG
    tuple<double, double> temp;
    //END DEBUG
    sf::RenderWindow window(sf::VideoMode(600, 600), "Stunning Rotary Phone");
    //sf::CircleShape shape(100.f);
    // shape.setFillColor(sf::Color::Green);
    //creates an entity
    //tuple<double, double> cur_pos;
    Trajectory square_traj(100., 100., 0.05, 1e-10);
    tuple<int, int, int> color = make_tuple(255, 0, 0);
    Sprite square_sprite = make_tuple(0, color);
    vector<tuple<double, double>> sq_vrtx;
    sq_vrtx.push_back(make_tuple(-5., -5.));
    sq_vrtx.push_back(make_tuple(5., -5.));
    sq_vrtx.push_back(make_tuple(5., 5.));
    sq_vrtx.push_back(make_tuple(-5., 5.));
    Hitbox sq_hitbx(sq_vrtx);
    PhysicPar phX(1.);
    Entity square_one(square_traj, sq_hitbx, square_sprite, phX);
    Terrain terrain(make_tuple(0., 1e-3), 0.05);
    sf::RectangleShape shape(sf::Vector2f(10., 10.));
    shape.setFillColor(sf::Color(255, 0, 255));
    vector<Entity> entities;
    entities.push_back(square_one);
    vector<tuple<double, double>> empty_all(1, make_tuple(0,0));
    sf::RectangleShape shape2(sf::Vector2f(600., 100.));
    shape2.setFillColor(sf::Color(255, 255, 255));
    shape2.setPosition(sf::Vector2f(0, 510));
    //shape2.setPosition()
    printf("%d", square_one.isFalling());
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //read inputs

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            entities[0].accelerate(make_tuple(0, -0.1));
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            entities[0].accelerate(make_tuple(-0.1, 0));
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            entities[0].accelerate(make_tuple(0.1, 0));  
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            entities[0].accelerate(make_tuple(0, 0.1));
        }
        // cur_pos = square_traj.getPosition();
        // shape.setPosition(sf::Vector2f(get<0>(cur_pos), get<1>(cur_pos)));
        //if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){   
        phXStep(&entities, empty_all, empty_all, terrain);
        temp = entities[0].getPosition();
        printf("%f, %f, ", get<0>(temp), get<1>(temp));
        temp = entities[0].getSpeed();
        printf("%f, %f \n", get<0>(temp), get<1>(temp));
        shape.setPosition(sf::Vector2f(get<0>(entities[0].getPosition()), get<1>(entities[0].getPosition())));
        //}
        window.clear();
        window.draw(shape);
        window.draw(shape2);

        //render everything here:

        //then update the scene
        window.display();
    }

    return 0;
}