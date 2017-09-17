#include "header.hpp"

int main() {
    srand((unsigned)time(0));

    font.loadFromFile("font/arial.ttf");

    scene.index = 0;
    player.audioPlayOff();
    player.isOpen = false;

    while (window.isOpen()){
        deltaTime = currentClock.restart();
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
            if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::Space && scene.index == 0){
                    scene.index = 1;
                    player.start();
                    spawn.start();
                }
                else if (event.key.code == sf::Keyboard::Space && player.isGameOver){
                    scene.index = 0;
                    textPlay.start();

                    player.audioPlayOff();
                    player.isOpen = false;
                }
            }
        }
        window.clear();
        scene.update();
        window.display();
    }
}
