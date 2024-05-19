#pragma once
#include <SFML/Graphics.hpp>

class Math
{
public:
    static sf::Vector2f normalizeVector(sf::Vector2f vector);
    static bool didRectCollide(sf::FloatRect rect1, sf::FloatRect rect2);
};