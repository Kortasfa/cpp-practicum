#include <SFML/Graphics.hpp>

void init(sf::ConvexShape &pointer)
{
    pointer.setPointCount(7);
    pointer.setPoint(0, {0,0});
    pointer.setPoint(1, {0,60});
    pointer.setPoint(2, {30,60});
    pointer.setPoint(3, {-20,100 });
    pointer.setPoint(4, {-70,60});
    pointer.setPoint(5, {-40, 60});
    pointer.setPoint(6, {-40, 0});

    pointer.setPosition({400, 300});
    pointer.setFillColor(sf::Color::Yellow);
    pointer.setOutlineColor(sf::Color::Black);
    pointer.setOutlineThickness(4);
    pointer.setRotation(190);
}

int main()
{
    constexpr int WINDOW_WIDTH = 800;
    constexpr int WINDOW_HEIGHT = 600;
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Arrow Drawing");
    sf::ConvexShape pointer;
    init(pointer);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        window.draw(pointer);
        window.display();
    }
}
