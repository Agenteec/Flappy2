#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
class TesterFeatures
{
    struct PairRect
    {
        sf::RectangleShape r1;
        sf::RectangleShape r2;
        sf::Sprite r1s;
        sf::Sprite r2s;
    };
public:
	TesterFeatures() {
        sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Motion Blur");

        sf::CircleShape ball(30);
        ball.setFillColor(sf::Color::Red);

        sf::Vector2f currentPosition(400, 300);
        sf::Vector2f previousPosition(400, 300);

        sf::Clock clock;
        sf::Time deltaTime;

        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            deltaTime = clock.restart();

            sf::Vector2f movement(0.0f, 0.0f);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                movement.y -= 300.0f;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                movement.y += 300.0f;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                movement.x -= 300.0f;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                movement.x += 300.0f;

            previousPosition = currentPosition;
            currentPosition += movement * deltaTime.asSeconds();

            float interpolationFactor = 1.00f; // ‘актор интерпол€ции (от 0.0 до 1.0)
            sf::Vector2f interpolatedPosition = previousPosition + (currentPosition - previousPosition) * interpolationFactor;

            ball.setPosition(interpolatedPosition);

            window.clear();
            window.draw(ball);
            window.display();
        }
        


	}

};

