#include <time.h>
#include <SFML/Graphics.hpp>

int main()
{
    srand((unsigned)time(0));
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML tes!");
    sf::RectangleShape player, mobil;

    int spawn;

    player.setSize(sf::Vector2f(50,80));
    player.setPosition(1000, 500);
    player.setFillColor(sf::Color::Red);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        mobil.move(0,0.5f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            player.move(-1, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            player.move(1, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            player.move(0, -1);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            player.move(0, 1);

        if(player.getGlobalBounds().intersects(mobil.getGlobalBounds())){
            window.draw("BOOM!");
        }

        window.draw(player);
        if(mobil.getPosition().y<=1080)
            window.draw(mobil);
        else {
                spawn=rand()%1920;
                mobil.setSize(sf::Vector2f(50,80));
                mobil.setPosition(spawn, 20);
                mobil.setFillColor(sf::Color::Green);
        }
        window.display();
    }

    return 0;
}
