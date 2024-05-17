#pragma once 
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Skeleton.hpp"

class Player
{
private:
    sf::Texture texture;
    std::vector<sf::RectangleShape> bullets;
    sf::Vector2f bulletDirection;
    float bulletSpeed = 0.5f;

public:
    sf::Sprite sprite;

public:
    void Initialize();
    void Load();
    void Update(Skeleton& skeleton);
    void Draw(sf::RenderWindow& window);

};