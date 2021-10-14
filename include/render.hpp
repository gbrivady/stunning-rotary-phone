#ifndef RENDER_HPP
#define RENDER_HPP
#include <SFML/Graphics.hpp>
#include "entity.hpp"

class Scene;

void render_scene(sf::RenderWindow window, Scene scene);

void render_entity(Entity entity);



#endif