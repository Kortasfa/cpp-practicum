#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

void init(sf::ConvexShape &pointer)
{
    pointer.setPointCount(7);
    pointer.setPoint(0, {20, -100});        
    pointer.setPoint(1, {20, -40});         
    pointer.setPoint(2, {50, -40});         
    pointer.setPoint(3, {0, 0});            
    pointer.setPoint(4, {-50, -40});        
    pointer.setPoint(5, {-20, -40});        
    pointer.setPoint(6, {-20, -100});  
    
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

float getAngleDifference(float angle1, float angle2)
{
    float difference = fmod(angle2 - angle1 + 90.0f, 360.0f) - 180.0f;
    if (difference <= -180.0f)
        difference += 360.0f;
    return difference;
}

void update(const sf::Vector2f &mousePosition, sf::ConvexShape &pointer, sf::Clock &clock)
{
    const float elapsedTime = clock.restart().asSeconds();
    
    const sf::Vector2f delta = mousePosition - pointer.getPosition();
    const float distance = sqrt(delta.x * delta.x + delta.y * delta.y);
    const float angleToMouse = toDegrees(atan2(delta.y, delta.x));
    
    const float maxAngleChange = 90.0f * elapsedTime; // 90 degrees per second
    const float angleDifference = getAngleDifference(pointer.getRotation(), angleToMouse);
    const float angleChange = std::clamp(angleDifference, -maxAngleChange, maxAngleChange);
    
    pointer.setRotation(pointer.getRotation() + angleChange);

    if (distance > 1.0f)
    {
        const float maxDistanceChange = 20.0f * elapsedTime; // 20 pixels per second
        const sf::Vector2f direction = delta / distance;
        const sf::Vector2f moveAmount = direction * std::min(distance, maxDistanceChange);
        
        pointer.move(moveAmount);
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