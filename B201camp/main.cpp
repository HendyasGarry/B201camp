#include <iostream>
#include <time.h>
#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
    int spawn, screenWidth, screenHeight;
    float currDuration, duration;
    bool isDisplayed=1;
    screenWidth=400;
    screenHeight=600;

    srand((unsigned)time(0));
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "SFML tes!");
    sf::RectangleShape player, truck;
    sf::Text txt;
    sf::Clock clk;
    sf::Time deltaTime;

    duration=5;
    player.setSize(sf::Vector2f(50,80));
    player.setPosition(200, 500);
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

        deltaTime=clk.restart();

        if(currDuration<duration)
            currDuration +=deltaTime.asSeconds();
        else {
                isDisplayed=1;
                spawn=rand()%3+1;
                truck.setSize(sf::Vector2f(100,140));
                powerUp.setPosition(screenWidth*spawn/3-118,0);
                powerUp.setFillColor(sf::Color::Green);
                currDuration=0;
        }
        powerUp.move(0,0.1f);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            player.move(-0.2f, 0);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            player.move(0.2f, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.close();

        if(isDisplayed==1){
            if(player.getGlobalBounds().intersects(powerUp.getGlobalBounds())){
                std::cout<<"POWER UP"<<endl;
                isDisplayed=0;
            }
        }
        if (powerUp.getPosition().y>screenHeight)
            isDisplayed=0;
        else if(powerUp.getPosition().y<=screenHeight)
        {
            if (isDisplayed)
                window.draw(powerUp);
        }

        window.draw(player);
        window.display();
    }

    return 0;
}
