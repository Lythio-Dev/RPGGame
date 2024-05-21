#pragma once 
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Skeleton.hpp"

class Player
{
private:
    sf::Texture texture;
    std::vector<sf::RectangleShape> bullets;
    sf::Vector2f bulletDirection;
    float bulletSpeed = 0.5f;
    float playerSpeed = 2.0f;
    
    sf::RectangleShape boundingRectangle;
    sf::Vector2i size;

public:
    sf::Sprite sprite;

public:
    void Initialize();
    void Load();
    void Update(Skeleton& skeleton, float deltaTime);
    void Draw(sf::RenderWindow& window);

};