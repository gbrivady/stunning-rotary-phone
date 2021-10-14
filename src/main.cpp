#include <SFML/Graphics.hpp>

int main()
{
    
    sf::RenderWindow window(sf::VideoMode(200, 200), "Stunning Rotary Phone");
    // sf::CircleShape shape(100.f);
    // shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        // window.draw(shape);

        //render everything here:

        //then update the scene
        window.display();
    }

    return 0;
}