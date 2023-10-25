#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>

struct Eye
{
    sf::CircleShape white;
    sf::CircleShape pupil;
    sf::Vector2f position;

    Eye(float x, float y)
    {
        position = {x, y};

        white.setRadius(50);
        white.setFillColor(sf::Color::White);
        white.setPosition(position);
        white.setOrigin(50, 50);
        white.setScale(1.3f, 2.0f);

        pupil.setRadius(20);
        pupil.setFillColor(sf::Color::Black);
        pupil.setOrigin(20, 20);
        pupil.setScale(1.3f, 2.0f);
    }

    void update(const sf::Vector2f &mousePosition)
    {
        const sf::Vector2f direction = mousePosition - position;
        float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

        const float maxOffset = 30.0f;

        sf::Vector2f offset = direction / distance * maxOffset;
        pupil.setPosition(position + offset);
    }
};

void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
    std::cout << "mouse x=" << event.x << ", y=" << event.y << std::endl;
    mousePosition = {float(event.x), float(event.y)};
}

void pollEvents(sf::RenderWindow &window, sf::Vector2f &mousePosition)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::MouseMoved:
            onMouseMove(event.mouseMove, mousePosition);
            break;
        default:
            break;
        }
    }
}

void redrawFrame(sf::RenderWindow &window, Eye &leftEye, Eye &rightEye)
{
    window.clear(sf::Color::Black);
    window.draw(leftEye.white);
    window.draw(leftEye.pupil);
    window.draw(rightEye.white);
    window.draw(rightEye.pupil);
    window.display();
}

void update(const sf::Vector2f &mousePosition, Eye &leftEye, Eye &rightEye)
{
    leftEye.update(mousePosition);
    rightEye.update(mousePosition);
}

int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
        "Eyes follow mouse", sf::Style::Default, settings);

    Eye leftEye(300, 300);
    Eye rightEye(500, 300);
    sf::Vector2f mousePosition;

    while (window.isOpen())
    {
        pollEvents(window, mousePosition);
        update(mousePosition, leftEye, rightEye);
        redrawFrame(window, leftEye, rightEye);
    }

    return 0;
}
