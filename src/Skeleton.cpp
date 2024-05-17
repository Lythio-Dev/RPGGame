#include "Skeleton.hpp"
#include <iostream>

void Skeleton::Initialize()
{

}

void Skeleton::Load()
{
    if(texture.loadFromFile("Assets/Skeleton/Textures/spritesheet.png"))
    {
        std::cout << "Skeleton images loaded!" << std::endl;
        sprite.setTexture(texture);
        sprite.setPosition(sf::Vector2f(400, 100));

        int XIndex = 0;
        int YIndex = 2;

        sprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
        sprite.scale(sf::Vector2f(3, 3));
    }

    else
    {
        std::cout << "Skeleton images failed to loaded!" << std::endl;
    }
}

void Skeleton::Update()
{
 
}

void Skeleton::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}