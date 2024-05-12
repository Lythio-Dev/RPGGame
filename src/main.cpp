#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "RPG Game", sf::Style::Default, settings);

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
        sf::Event event; 

        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        
        sf::Vector2f position = playerSprite.getPosition();

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            playerSprite.setPosition(position + sf::Vector2f(1, 0));

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
            playerSprite.setPosition(position + sf::Vector2f(-1, 0));

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
            playerSprite.setPosition(position + sf::Vector2f(0, -1));

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            playerSprite.setPosition(position + sf::Vector2f(0, 1));

        window.clear(sf::Color(119, 181, 254, 255));
        window.draw(playerSprite);
        window.draw(skeletonSprite);
        window.display();
    }

    return 0;
}