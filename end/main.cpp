#include "header.hpp"

int main() {
    srand((unsigned)time(0));

    font.loadFromFile("font/arial.ttf");

    scene.index = 0;

    while (window.isOpen()){
        deltaTime = currentClock.restart();
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
            if (event.type == sf::Event::KeyPressed){
                if (event.key.code == sf::Keyboard::Space){
                    scene.index = 1;
                    player.isOpen = true;
                    player.isAudio = true;
                }
            }
        }
        window.clear();
        scene.update();
        window.display();
    }
}
