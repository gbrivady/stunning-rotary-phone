#ifndef RENDER_HPP
#define RENDER_HPP
#include <SFML/Graphics.hpp>
#include "entity.hpp"
#include "scene.hpp"

void render_scene(sf::RenderWindow window, scene scene);

void render_entity(entity entity);



#endif