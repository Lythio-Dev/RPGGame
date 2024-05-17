#include "Player.hpp"
#include "Math.hpp"

void Player::Initialize()
{

}

void Player::Load()
{
    if(texture.loadFromFile("Assets/Player/Textures/spritesheet.png"))
    {
        std::cout << "Player images loaded!" << std::endl;
        sprite.setTexture(texture);
        sprite.setPosition(sf::Vector2f(1300, 800));

        int XIndex = 0;
        int YIndex = 0;

        sprite.setTextureRect(sf::IntRect(XIndex * 64, YIndex * 64, 64, 64));
        sprite.scale(sf::Vector2f(3, 3));
    }

    else
    {
        std::cout << "Player images failed to loaded!" << std::endl;
    }
}

void Player::Update(Skeleton& skeleton)
{
    // Moving player       
    sf::Vector2f position = sprite.getPosition();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        sprite.setPosition(position + sf::Vector2f(1, 0));

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        sprite.setPosition(position + sf::Vector2f(-1, 0));

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        sprite.setPosition(position + sf::Vector2f(0, -1));

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        sprite.setPosition(position + sf::Vector2f(0, 1));


    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
    {
        bullets.push_back(sf::RectangleShape(sf::Vector2f(30, 30)));
        bullets[bullets.size() - 1].setFillColor(sf::Color::Black);
        bullets[bullets.size() - 1].setPosition(sprite.getPosition());
    }

    for(size_t i = 0; i < bullets.size(); i++)
    {
        bulletDirection = skeleton.sprite.getPosition() - bullets[i].getPosition();
        bulletDirection = Math::normalizeVector(bulletDirection);
        bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed);
    }
        

        
}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);

    for(size_t i = 0; i < bullets.size(); i++)
        {
            window.draw(bullets[i]);
        }
}