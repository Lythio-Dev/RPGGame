#include "Math.hpp"
#include <math.h>


sf::Vector2f Math::normalizeVector(sf::Vector2f vector)
{
    float m = std::sqrt(vector.x * vector.x + vector.y * vector.y);
 
    sf::Vector2f normalizedVector;
    normalizedVector.x = vector.x / m;
    normalizedVector.y = vector.y / m;

    return normalizedVector;
}

bool Math::didRectCollide(sf::FloatRect rect1, sf::FloatRect rect2)
{
    if(rect1.left + rect1.width > rect2.left && 
        rect2.left + rect2.width > rect1.left &&
        rect2.top + rect2.height > rect1.top &&
        rect1.left + rect1.width > rect2.top)
        return true;
        
    else
        return false;
}