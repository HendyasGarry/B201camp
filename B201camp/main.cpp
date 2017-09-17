#include <iostream>
#include <time.h>
#include <SFML/Graphics.hpp>

using namespace std;

int main()
{
    int spawn, screenWidth=400, screenHeight=600;
    float currDuration, duration;
    bool isDisplayed=1, gameOver=0;

    srand((unsigned)time(0));
    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "SFML tes!");
    sf::RectangleShape player, truck;
    sf::Font font;
    font.loadFromFile("font/arial.ttf");
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
                truck.setPosition(screenWidth*spawn/3-118,0);
                truck.setFillColor(sf::Color::Green);
                currDuration=0;
        }
        truck.move(0,0.1f);

        if(!gameOver){
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                player.move(-0.2f, 0);
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                player.move(0.2f, 0);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.close();

        if(isDisplayed==1){
            if(player.getGlobalBounds().intersects(truck.getGlobalBounds())){
                std::cout<<"GAME OVER!"<<endl;
                isDisplayed=0;
                player.setPosition(screenWidth,screenHeight);
                gameOver=1;
            }
        }
        if (truck.getPosition().y>screenHeight)
            isDisplayed=0;
        else if(truck.getPosition().y<=screenHeight)
        {
            if (isDisplayed)
                window.draw(truck);
        }

        if(!gameOver)
            window.draw(player);
        else {
            txt.setFont(font);
            txt.setString("\tGAME OVER!\npress SPACE to retry\n\tor ESC to exit");
            txt.setCharacterSize(30);
            txt.setColor(sf::Color::White);
            txt.Bold;
            txt.setPosition(screenWidth/2.0f-140, screenHeight/2.0f);
            window.draw(txt);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                gameOver=0;
                player.setPosition(200, 500);
            }
        }
        window.display();
    }

    return 0;
}
