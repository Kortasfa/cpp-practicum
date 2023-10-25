#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

sf::Texture arrowTexture;
sf::Texture laserTexture;

void init(sf::Sprite &sprite, sf::Sprite &laser)
{
    if(!arrowTexture.loadFromFile("cat.png"))
    {
        std::cerr << "Failed to load cat.png" << std::endl;
    }
    if(!laserTexture.loadFromFile("red_pointer.png"))
    {
        std::cerr << "Failed to load lazer.png" << std::endl;
    }
    laser.setTexture(laserTexture);
    sprite.setTexture(arrowTexture);
    sprite.setPosition({400, 300});
    laser.setPosition({600, 600});
}

float toDegrees(float radians)
{
    return float(double(radians) * 180.0 / M_PI);
}

void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
    mousePosition = {float(event.x), float(event.y)};
}

void pollEvents(sf::RenderWindow &window, sf::Vector2f &mousePosition, sf::Sprite &laser)
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
            case sf::Event::MouseButtonPressed:
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                laser.setPosition({float(event.mouseButton.x), float(event.mouseButton.y)});
            }
            break;
        default:
            break;
        }
    }
}

sf::Vector2f getSpriteCenter(const sf::Sprite& sprite)
{
    sf::FloatRect bounds = sprite.getGlobalBounds();
    return sf::Vector2f(bounds.left + bounds.width / 2, bounds.top + bounds.height / 2);
}

float getAngleDifference(float angle1, float angle2)
{
    float difference = fmod(angle2 - angle1 + 90.0f, 360.0f) - 180.0f;
    if (difference <= -180.0f)
        difference += 360.0f;
    return difference;
}

void update(const sf::Sprite &laser, sf::Sprite &cat, sf::Clock &clock)
{
    const float elapsedTime = clock.restart().asSeconds();
    const sf::Vector2f laserPosition = getSpriteCenter(laser);
    const sf::Vector2f delta = laserPosition - getSpriteCenter(cat);
    const float distance = sqrt(delta.x * delta.x + delta.y * delta.y);
    
    if (laserPosition.x < getSpriteCenter(cat).x) 
    {
        cat.setScale(-1,1);
    }
    else
    {
        cat.setScale(1,1);
    }

    if (distance > 1.0f)
    {
        const float maxDistanceChange = 50.0f * elapsedTime; // 50 pixels per second (исправил комментарий)
        const sf::Vector2f direction = delta / distance;
        const sf::Vector2f moveAmount = direction * std::min(distance, maxDistanceChange);

        cat.move(moveAmount);
    }
}


void redrawFrame(sf::RenderWindow &window, sf::Sprite &cat, sf::Sprite &laser)
{
    window.clear(sf::Color::White);
    window.draw(cat);
    window.draw(laser);
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

    sf::Vector2f mousePosition;
        sf::Clock clock;

    sf::Sprite cat, laser;
    init(cat, laser);
    while (window.isOpen())
    {
        pollEvents(window, mousePosition, laser);
        update(laser, cat, clock);
        redrawFrame(window, cat, laser);
    }
}
