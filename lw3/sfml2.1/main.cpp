#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include <iostream>

constexpr unsigned WINDOW_WIDTH = 800;
constexpr unsigned WINDOW_HEIGHT = 600;
constexpr float BALL_SIZE = 40;
constexpr float AMPLITUDE_Y = 80.f;
constexpr float PERIOD_Y = 22;

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Wave Moving Ball");
    sf::Clock clock;

    sf::CircleShape ball(BALL_SIZE);
    ball.setPosition(10, 350);
    ball.setFillColor(sf::Color::White);

    float speedX = 100.f;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        const float dt = clock.restart().asSeconds();
        const float startX = ball.getPosition().x + speedX * dt;
        const float startY = 350 + AMPLITUDE_Y * std::sin(startX / PERIOD_Y);

        ball.setPosition(startX, startY);

        if ((startX + 2 * BALL_SIZE >= WINDOW_WIDTH && speedX > 0) || (startX < 0 && speedX < 0))
        {
            speedX = -speedX;
        }

        window.clear();
        window.draw(ball);
        window.display();
    }

    return 0;
}