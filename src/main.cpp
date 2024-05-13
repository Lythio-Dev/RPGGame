#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>
#include "Player.hpp"

// Vector normalizing function
sf::Vector2f normalizeVector(sf::Vector2f vector)
{
    float m = std::sqrt(vector.x * vector.x + vector.y * vector.y);

    sf::Vector2f normalizedVector;
    normalizedVector.x = vector.x / m;
    normalizedVector.y = vector.y / m;

    return normalizedVector;
}

// Main function
int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "RPG Game", sf::Style::Default, settings);

    // Bullets
    std::vector<sf::RectangleShape> bullets;
    sf::Vector2f bulletDirection;
    float bulletSpeed = 0.5f;

    // Skeleton
    sf::Texture skeletonTexture;
    sf::Sprite skeletonSprite;

    if(skeletonTexture.loadFromFile("Assets/Skeleton/Textures/spritesheet.png"))
    {
        std::cout << "Skeleton images loaded!" << std::endl;
        skeletonSprite.setTexture(skeletonTexture);
        skeletonSprite.setPosition(sf::Vector2f(400, 100));

        int XIndex = 0;
        int YIndex = 2;

        skeletonSprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
        skeletonSprite.scale(sf::Vector2f(3, 3));
    }

    else
    {
        std::cout << "Skeleton images failed to loaded!" << std::endl;
    }
    
    // Player
    sf::Texture playerTexture;
    sf::Sprite playerSprite;

    if(playerTexture.loadFromFile("Assets/Player/Textures/spritesheet.png"))
    {
        std::cout << "Player images loaded!" << std::endl;
        playerSprite.setTexture(playerTexture);
        playerSprite.setPosition(sf::Vector2f(1300, 800));

        int XIndex = 0;
        int YIndex = 0;

        playerSprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
        playerSprite.scale(sf::Vector2f(3, 3));
    }

    else
    {
        std::cout << "Player images failed to loaded!" << std::endl;
    }

    // While loop
    while(window.isOpen())
    {
        // Checking for events
        sf::Event event;

        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // Moving player       
        sf::Vector2f position = playerSprite.getPosition();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            playerSprite.setPosition(position + sf::Vector2f(1, 0));

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            playerSprite.setPosition(position + sf::Vector2f(-1, 0));

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
            playerSprite.setPosition(position + sf::Vector2f(0, -1));

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            playerSprite.setPosition(position + sf::Vector2f(0, 1));
        
        // Shooting bullets
        if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            bullets.push_back(sf::RectangleShape(sf::Vector2f(30, 30)));
            bullets[bullets.size() - 1].setFillColor(sf::Color::Black);
            bullets[bullets.size() - 1].setPosition(playerSprite.getPosition());
        }

        for(size_t i = 0; i < bullets.size(); i++)
        {
            bulletDirection = skeletonSprite.getPosition() - bullets[i].getPosition();
            bulletDirection = normalizeVector(bulletDirection);
            bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
        }

        // Drawing on the screen
        window.clear(sf::Color(119, 181, 254, 255));
        window.draw(playerSprite);
        window.draw(skeletonSprite);

        for(size_t i = 0; i < bullets.size(); i++)
        {
            window.draw(bullets[i]);
        }
        window.display();
    }

    return 0;
}