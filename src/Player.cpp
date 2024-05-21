#include "Player.hpp"
#include "Math.hpp"

void Player::Initialize()
{
    boundingRectangle.setFillColor(sf::Color::Transparent);
    boundingRectangle.setOutlineColor(sf::Color::Red);
    boundingRectangle.setOutlineThickness(3);

    size = sf::Vector2i(64, 64);
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

        sprite.scale(sf::Vector2f(3, 3));
        boundingRectangle.setSize(sf::Vector2f(size.x * sprite.getScale().x, size.y * sprite.getScale().y));

        sprite.setTextureRect(sf::IntRect(XIndex * size.x, YIndex * size.y, size.x, size.y));
    }

    else
    {
        std::cout << "Player images failed to loaded!" << std::endl;
    }
}

void Player::Update(Skeleton& skeleton, float deltaTime)
{
    // Moving player
    sf::Vector2f position = sprite.getPosition();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        sprite.setPosition(position + sf::Vector2f(1, 0) * playerSpeed * deltaTime);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
        sprite.setPosition(position + sf::Vector2f(-1, 0) * playerSpeed * deltaTime);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
        sprite.setPosition(position + sf::Vector2f(0, -1) * playerSpeed * deltaTime);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        sprite.setPosition(position + sf::Vector2f(0, 1) * playerSpeed * deltaTime);


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
        bullets[i].setPosition(bullets[i].getPosition() + bulletDirection * bulletSpeed * deltaTime);
    }

    boundingRectangle.setPosition(sprite.getPosition());

    if(Math::didRectCollide(sprite.getGlobalBounds(), skeleton.sprite.getGlobalBounds()))
    {
        std::cout << "COLLISION" << std::endl;
    }
}

void Player::Draw(sf::RenderWindow& window)
{
    window.draw(sprite);
    window.draw(boundingRectangle);

    for(size_t i = 0; i < bullets.size(); i++)
        {
            window.draw(bullets[i]);
        }
}