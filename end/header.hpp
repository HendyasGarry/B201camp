#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>
#include <time.h>
#include <windows.h>
#include <fstream>
#include <sstream>

using namespace std;

const int SCREEN_WIDTH = 590;
const int SCREEN_HEIGHT = 600;

sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "SFML Demo");
sf::Event event;

sf::Font font;
sf::Time deltaTime;
sf::Clock currentClock;

sf::SoundBuffer soundBuf;
sf::Sound sound;

#define SSTR( x ) static_cast< std::ostringstream & >( \
                                                      ( std::ostringstream() << std::dec << x ) ).str()


#include "HighScore.hpp"
HighScore highScore;

#include "MainMenu.hpp"
MainMenu textPlay;

#include "Spawn.hpp"
Spawn spawn;

#include "PlayerController.hpp"
PlayerController player;

#include "SceneManagement.hpp"
SceneManagement scene;
