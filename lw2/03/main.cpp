#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({860, 660}), "Convex Shapes");
    window.clear(sf::Color::White);

    sf::ConvexShape trapeze; //roof
    trapeze.setFillColor(sf::Color::Red);
    trapeze.setPosition(280, 120);
    trapeze.setPointCount(4);
    trapeze.setPoint(0, {-130, 0});
    trapeze.setPoint(1, {+130, 0});
    trapeze.setPoint(2, {+230, 60});
    trapeze.setPoint(3, {-230, 60});
    window.draw(trapeze);

    sf::RectangleShape rectangle; //basement
    rectangle.setSize({380, 200});
    rectangle.setPosition({100, 180});
    rectangle.setFillColor(sf::Color(128, 64, 48, 255));
    window.draw(rectangle);

    rectangle.setSize({60, 120}); //door
    rectangle.setPosition({130, 260});
    rectangle.setFillColor(sf::Color(0, 0, 0, 255));
    window.draw(rectangle);

    sf::CircleShape circle(20); //smoke 1
    circle.setPosition({350, 70});
    circle.setFillColor(sf::Color(192, 192, 192, 255));
    window.draw(circle);

    circle.setPosition({355, 40}); //smoke 2
    circle.setRadius(22);
    window.draw(circle);

    circle.setPosition({370, 20}); //smoke 3
    circle.setRadius(25);
    window.draw(circle);

    circle.setPosition({390, 1}); //smoke 4
    circle.setRadius(28);
    window.draw(circle);

    rectangle.setSize({40, 60}); //pipe 1
    rectangle.setPosition({340, 100});
    rectangle.setFillColor(sf::Color(128, 128, 128, 255));
    window.draw(rectangle);

    rectangle.setSize({60, 20}); //pipe 2
    rectangle.setPosition({330, 100});
    rectangle.setFillColor(sf::Color(128, 128, 128, 255));
    window.draw(rectangle);

    window.display();

    sf::sleep(sf::seconds(1));
}