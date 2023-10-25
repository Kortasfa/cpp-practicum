#include <SFML/Graphics.hpp>
#include <iostream>

sf::Texture arrowTexture;

void init(sf::Sprite &sprite)
{
    if(!arrowTexture.loadFromFile("cat.png"))
    {
        std::cerr << "Failed to load cat.png" << std::endl;
    }
    sprite.setTexture(arrowTexture);
    sprite.setPosition({400, 300});
}

int main()
{
    constexpr int WINDOW_WIDTH = 800;
    constexpr int WINDOW_HEIGHT = 600;
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Arrow Drawing");

    sf::Sprite arrowSprite;
    init(arrowSprite);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);
        window.draw(arrowSprite);
        window.display();
    }
}
