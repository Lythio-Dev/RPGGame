#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(800, 600), "RPG Game", sf::Style::Default, settings);

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

        window.clear(sf::Color::Black);
        window.draw(playerSprite);
        window.display();
    }

    return 0;
}