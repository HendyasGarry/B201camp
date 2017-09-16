#include <iostream>
#include <time.h>
#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
    int spawn, screenWidth, screenHeight;
    screenWidth=400;
    screenHeight=600;
    bool isDisplayed=1;

    srand((unsigned)time(0));
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "SFML tes!");
    sf::RectangleShape player, mobil;
    sf::Text txt;

    player.setSize(sf::Vector2f(50,80));
    player.setPosition(200, 300);
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

        mobil.move(0,0.2f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            player.move(-1, 0);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            player.move(1, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            player.move(0, -1);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            player.move(0, 1);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.close();

        window.draw(player);
        if(mobil.getPosition().y<=screenHeight)
        {
            if(player.getGlobalBounds().intersects(mobil.getGlobalBounds())){
                std::cout<<"BHRUWAK!"<<endl;
                isDisplayed=0;
            }
            else if (isDisplayed)
                window.draw(mobil);
        }
        else {
                spawn=rand()%3+1;
                mobil.setSize(sf::Vector2f(50,80));
                mobil.setPosition(screenWidth/spawn+25, 20);
                mobil.setFillColor(sf::Color::Green);
        }
        window.display();
    }

    return 0;
}
