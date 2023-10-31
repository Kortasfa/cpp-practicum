#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>

constexpr int POINT_COUNT = 200;
constexpr float DEG_TO_RAD = 2 * M_PI / 180;

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode({1600, 1200}), "Polar Rose", sf::Style::Default, settings);

    sf::ConvexShape shape;
    const sf::Vector2f CENTER_POSITION = {800.f, 560.f};
    shape.setFillColor(sf::Color(0xFF, 0x09, 0x80));
    shape.setPointCount(POINT_COUNT);

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

        for (float i = 1; i <= 360; i += 0.2)
        {
            for (int pointNo = 0; pointNo < POINT_COUNT; ++pointNo)
            {
                float angle = (2 * M_PI * pointNo) / float(POINT_COUNT);
                const float ellipseRadius = 200 * std::sin(6 * angle);
                sf::Vector2f point = {
                        ellipseRadius * std::sin(angle),
                        ellipseRadius * std::cos(angle)};
                shape.setPoint(pointNo, point);
            }

            sf::Vector2f position = {
                    300 * std::sin(i * DEG_TO_RAD),
                    300 * std::cos(i * DEG_TO_RAD)};

            shape.setPosition(CENTER_POSITION + position);
            shape.setRotation(3 * i);

            window.clear();
            window.draw(shape);
            window.display();
        }
    }
}