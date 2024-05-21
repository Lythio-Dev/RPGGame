#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "Player.hpp"
#include "Skeleton.hpp"


int main()
{
    // -------------------------------- INITIALIZE --------------------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "RPG Game", sf::Style::Default, settings);
    window.setFramerateLimit(240);

    sf::Text frameRateText;
    sf::Font font;
    std::string frameRateString;

    Player player;
    Skeleton skeleton;

    player.Initialize(); 
    skeleton.Initialize();

    sf::Time deltaTimeTimer;
    double deltaTime;
    sf::Clock clock;

    // -------------------------------- LOAD --------------------------------

    if(font.loadFromFile("Assets/Fonts/Poppins-Regular.ttf"))
    {
        std::cout << "Font loaded!" << std::endl;
        frameRateText.setFont(font);
    }
    else 
    {
        std::cout << "Font failed to load!" << std::endl;
    }

    player.Load();
    skeleton.Load();
    

    while(window.isOpen())
    {
        deltaTimeTimer = clock.restart();
        deltaTime = deltaTimeTimer.asMilliseconds();

        frameRateString = "FPS : " + std::to_string(1000.0 / deltaTime);

        frameRateText.setString(frameRateString);
        

        // -------------------------------- UPDATE --------------------------------
        sf::Event event;

        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }


        player.Update(skeleton, deltaTime);
        skeleton.Update(deltaTime);

        // -------------------------------- DRAW --------------------------------
        window.clear(sf::Color(119, 181, 254, 255));
        player.Draw(window);
        skeleton.Draw(window);
        window.draw(frameRateText);
        window.display();
    }

    return 0;
}