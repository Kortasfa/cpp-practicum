#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

void init(sf::ConvexShape &pointer)
{
    pointer.setPointCount(7);
    pointer.setPoint(0, {60, 0});
    pointer.setPoint(1, {0, -60});
    pointer.setPoint(2, {0, -30});
    pointer.setPoint(3, {-70, -30});
    pointer.setPoint(4, {-70, 30});
    pointer.setPoint(5, {0, 30});
    pointer.setPoint(6, {0, 60});

    pointer.setPosition({400, 300});
    pointer.setFillColor(sf::Color::Yellow);
    pointer.setOutlineColor(sf::Color::Black);
    pointer.setOutlineThickness(4);
}

float toDegrees(float radians)
{
    return float(double(radians) * 180.0 / M_PI);
}

void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
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

void update(const sf::Vector2f &mousePosition, sf::ConvexShape &arrow, sf::Clock &clock)
{

    const float dTime = clock.restart().asSeconds();
    constexpr float maxRotationSpeed = 90.0f;
    constexpr float speed = 20.0f;

    const sf::Vector2f motion = mousePosition - arrow.getPosition();
    const float targetRotation = toDegrees(atan2(motion.y, motion.x));
    float currentRotation = arrow.getRotation();

    float rotationDiff = targetRotation - currentRotation;
    if (rotationDiff > 180.0)
    {
        rotationDiff -= 360.0;
    }
    else if (rotationDiff < -180.0)
    {
        rotationDiff += 360.0;
    }

    float maxRotationDiff = maxRotationSpeed * dTime;
    rotationDiff = std::clamp(rotationDiff, -maxRotationDiff, maxRotationDiff);

    arrow.setRotation(currentRotation + rotationDiff);

    const float offset = speed * dTime;
    const sf::Vector2f direction =
            {
                    (motion.x / std::abs(std::sqrt(motion.x * motion.x + motion.y * motion.y))),
                    (motion.y / std::abs(std::sqrt(motion.x * motion.x + motion.y * motion.y)))};

    sf::Vector2f newPosition = arrow.getPosition() + direction * offset;

    if ((newPosition.x <= mousePosition.x && newPosition.y <= mousePosition.y) ||
        (newPosition.x >= mousePosition.x && newPosition.y <= mousePosition.y) ||
        (newPosition.x <= mousePosition.x && newPosition.y >= mousePosition.y) ||
        (newPosition.x >= mousePosition.x && newPosition.y >= mousePosition.y))
    {
        arrow.setPosition(newPosition);
    }
}

void redrawFrame(sf::RenderWindow &window, sf::ConvexShape &pointer)
{
    window.clear(sf::Color::White);
    window.draw(pointer);
    window.display();
}

int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
            sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
            "Pointer follows mouse", sf::Style::Default, settings);

    sf::ConvexShape pointer;
    sf::Vector2f mousePosition;
    sf::Clock clock;

    init(pointer);
    while (window.isOpen())
    {
        pollEvents(window, mousePosition);
        update(mousePosition, pointer, clock);
        redrawFrame(window, pointer);
    }
}