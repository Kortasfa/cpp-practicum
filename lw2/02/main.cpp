#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Initials");
    window.clear();
    sf::RectangleShape rectangle;

    rectangle.setFillColor(sf::Color(0x0, 0xFF, 0x0)); //T - color

    rectangle.setSize({70, 20}); //T
    rectangle.setPosition({10, 10});
    window.draw(rectangle);

    rectangle.setSize({20, 60}); //T
    rectangle.setPosition({35, 30});
    window.draw(rectangle);

    rectangle.setFillColor(sf::Color(0xFF, 0x0, 0x0)); //З - color

    rectangle.setSize({20, 80}); //З
    rectangle.setPosition({150, 10});
    window.draw(rectangle);

    rectangle.setSize({60, 10}); //З
    rectangle.setPosition({110, 10});
    window.draw(rectangle);

    rectangle.setPosition({110, 45}); //З
    window.draw(rectangle);

    rectangle.setPosition({110, 80}); //З
    window.draw(rectangle);

    rectangle.setFillColor(sf::Color(0xFF, 0xFF, 0x0)); //Г - color

    rectangle.setSize({60, 10}); //Г
    rectangle.setPosition({200, 10});
    window.draw(rectangle);

    rectangle.setSize({20, 80}); //Г
    rectangle.setPosition({200, 10});
    window.draw(rectangle);

    window.display();
    sf::sleep(sf::seconds(1));
}