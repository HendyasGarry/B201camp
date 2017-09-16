class PlayerController{
public:
    sf::Texture texture;
    sf::Sprite player;

    sf::Text textEnergy;
    sf::Text textEnergyBar;

    sf::Text textScore;
    sf::Text textScoreBar;

    float speed;
    float y;
    float energy;
    float energyMax;
    float energyAdd;
    float score;
    bool isOpen;
    bool isAudio;

    PlayerController(){
        speed = 0.2f;
        y = 400;
        energyMax = 60;
        energy = energyMax;
        energyAdd = 15;
        score = 0;
        isOpen = false;
        isAudio = false;

        texture.loadFromFile("img/player.png");
        player.setTexture(texture);
        player.setScale(0.2f, 0.2f);
        player.setPosition(SCREEN_WIDTH/2, y);

        textEnergy.setFont(font);
        textEnergy.setString("ENERGY");
        textEnergy.setCharacterSize(16);
        textEnergy.setPosition(sf::Vector2f(10, SCREEN_HEIGHT - 550));

        textEnergyBar.setFont(font);
        textEnergyBar.setCharacterSize(24);
        textEnergyBar.setPosition(sf::Vector2f(25, SCREEN_HEIGHT - 590));

        textScore.setFont(font);
        textScore.setString("SCORE");
        textScore.setCharacterSize(16);
        textScore.setPosition(sf::Vector2f(SCREEN_WIDTH - 70, SCREEN_HEIGHT - 550));

        textScoreBar.setFont(font);
        textScoreBar.setCharacterSize(24);
        textScoreBar.setPosition(sf::Vector2f(SCREEN_WIDTH - 45, SCREEN_HEIGHT - 590));
    };

    void update(){
        display();
        if(isOpen){
            movement();
        }
        if(isAudio){
            audioPlay();
        }

        if(player.getGlobalBounds().intersects(spawn.energy.getGlobalBounds())){
            spawn.energy.setPosition(-100, 0);
            energy += energyAdd;
            if(energy > energyMax) energy = energyMax;
        }
    };

    void movement(){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            player.move(-1 * speed, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            player.move(1 * speed, 0);

        if(player.getPosition().x < 30){
            player.setPosition(40, y);
        }
        else if(player.getPosition().x > SCREEN_WIDTH - 90){
            player.setPosition(SCREEN_WIDTH - 100, y);
        }
    };

    void display(){
        textEnergyBar.setString(SSTR((int)((energy/energyMax) * 100)<<"%"));
        textScoreBar.setString(SSTR((int)score));

        window.draw(player);
        window.draw(textEnergy);
        window.draw(textEnergyBar);
        window.draw(textScore);
        window.draw(textScoreBar);

        energy -= deltaTime.asSeconds();
        score = score + (deltaTime.asSeconds() / 2);
    };

    void audioPlay(){
        isAudio = false;
        soundBuf.loadFromFile("audio/play.ogg");
        sound.setBuffer(soundBuf);
        sound.setLoop(true);
        sound.play();
    };
};
