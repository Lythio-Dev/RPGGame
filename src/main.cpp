#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.hpp"
#include "Skeleton.hpp"


int main()
{
    // -------------------------------- INITIALIZE --------------------------------
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "RPG Game", sf::Style::Default, settings);

    Player player;
    Skeleton skeleton;

    player.Initialize();
    skeleton.Initialize();

    // -------------------------------- LOAD --------------------------------

    player.Load();
    skeleton.Load();

    while(window.isOpen())
    {
        // -------------------------------- UPDATE --------------------------------
        sf::Event event;

        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        player.Update(skeleton);
        skeleton.Update();

        // -------------------------------- DRAW --------------------------------
        window.clear(sf::Color(119, 181, 254, 255));
        player.Draw(window);
        skeleton.Draw(window);
        window.display();
    }

    return 0;
}