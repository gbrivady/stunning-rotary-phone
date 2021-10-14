#include "main.hpp"
using namespace std;

int main(int argc, char** argv)
{
    
    sf::RenderWindow window(sf::VideoMode(200, 200), "Stunning Rotary Phone");
    //sf::CircleShape shape(100.f);
    // shape.setFillColor(sf::Color::Green);

    //creates an entity
    tuple<float, float> cur_pos;
    Trajectory square_traj(100., 100., 0., 0.);
    tuple<int, int, int> color = make_tuple(255, 0, 0);
    Sprite square_sprite = make_tuple(0, color);
    Entity square_one(square_traj, make_tuple(10., 10.), square_sprite);

    sf::RectangleShape shape(sf::Vector2f(10., 10.));
    shape.setFillColor(sf::Color(150, 100, 0));

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
            //jump
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            cur_pos = square_traj.getPosition();
            get<0>(cur_pos) -= 1;
            square_traj.setPosition(cur_pos);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            cur_pos = square_traj.getPosition();
            get<0>(cur_pos) += 1;
            square_traj.setPosition(cur_pos);
        }

        cur_pos = square_traj.getPosition();
        shape.setPosition(sf::Vector2f(get<0>(cur_pos), get<1>(cur_pos)));
        window.clear();
        window.draw(shape);

        //render everything here:

        //then update the scene
        window.display();
    }

    return 0;
}