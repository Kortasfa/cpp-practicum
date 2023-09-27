#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({50, 350}), "traffic lights");
    window.clear();

    sf::CircleShape circle(50);

    circle.setFillColor(sf::Color(0x0, 0xFF, 0x0)); //Green
    circle.setPosition({10, 10});
    window.draw(circle);

    circle.setFillColor(sf::Color(0xFF, 0xFF, 0x0)); //Yellow
    circle.setPosition({10, 120});
    window.draw(circle);

    circle.setFillColor(sf::Color(0xFF, 0x0, 0x0)); //Red
    circle.setPosition({10, 230});
    window.draw(circle);

    window.display();
    sf::sleep(sf::seconds(1));
}