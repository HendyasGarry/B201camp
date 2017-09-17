class PlayerController{
public:
    sf::Texture texture;
    sf::Sprite player;

    sf::Texture textureShield;
    sf::Sprite shield;

    sf::Texture textureExplo;
    sf::Sprite explo;

    sf::Text textEnergy;
    sf::Text textEnergyBar;

    sf::Text textScore;
    sf::Text textScoreBar;

    sf::SoundBuffer energyBuf;
    sf::Sound energySound;

    sf::SoundBuffer exploBuf;
    sf::Sound exploSound;

    float speed;
    float y;
    float energy;
    float energyMax;
    float energyAdd;
    float score;
    bool isOpen;
    bool isAddSpeed;
    bool isGameOver;

    PlayerController(){
        //start();
    };

    start(){
        audioPlay();

        speed = 0.6f;
        y = 500;
        energyMax = 120;
        energy = energyMax;
        energyAdd = 10;
        score = 0;
        isOpen = true;
        isAddSpeed = false;
        isGameOver = false;

        textureExplo.loadFromFile("img/explosion.png");

        texture.loadFromFile("img/car.png");
        player.setTexture(texture);
        player.setScale(0.3f, 0.3f);
        player.setPosition(SCREEN_WIDTH/2, y);

        textureShield.loadFromFile("img/shield.png");
        shield.setTexture(textureShield);
        shield.setScale(0.3f, 0.3f);
        shield.setPosition(-100, 0);

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

        effectAudio();
        exploAudio();
    };

    void update(){
        scoreManage();
        effectShield();
        energyManage();
        display();

        if(isOpen){
            movement();
        }

        if(player.getGlobalBounds().intersects(spawn.item.getGlobalBounds())){
            spawn.item.setPosition(-100, 0);
            if(spawn.indexItem == 0){
                spawn.isShield = true;
                spawn.currentShield = 0;
            }
            else{
                energySound.play();
                spawn.speedScale -= 0.4f;
                if(spawn.speedScale < 1)
                    spawn.speedScale = 1;
            }
        }

        if(player.getGlobalBounds().intersects(spawn.energy.getGlobalBounds())){
            spawn.energy.setPosition(-100, 0);
            energy += energyAdd;
            if(energy > energyMax) energy = energyMax;
            energySound.play();
        }

        if(player.getGlobalBounds().intersects(spawn.enemy.getGlobalBounds())){
            explo.setTexture(textureExplo);
            explo.setScale(0.1f, 0.1f);
            explo.setPosition(spawn.enemy.getPosition().x, spawn.enemy.getPosition().y + 100);
            spawn.enemy.setPosition(-100, 0);
            if(!spawn.isShield && !isGameOver){
                energy -= energyAdd;
            }
            exploSound.play();

        }
        else{
            if(explo.getPosition().y <= 700)
                explo.move(0, 0.5);
        }
    };

    void movement(){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            player.move(-1 * speed, 0);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            player.move(1 * speed, 0);

        if(player.getPosition().x < 120){
            player.setPosition(125, y);
        }
        else if(player.getPosition().x > SCREEN_WIDTH - 210){
            player.setPosition(SCREEN_WIDTH - 215, y);
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
        window.draw(explo);
        window.draw(shield);

        if(!isGameOver){
            energy -= deltaTime.asSeconds();
            score = score + (deltaTime.asSeconds() / 2);
        }
    };

    void energyManage(){
        if((int)energy <= 0){
            isGameOver = true;
            energy = 0;
            spawn.speedScale = 0;
            textPlay.display("\t  GAME OVER\nPress SPACE to back", 24);
            textPlay.animate(sf::Color::White, sf::Color(255, 255, 200, 225));
            window.draw(textPlay.textPlay);
        }
    };

    void scoreManage(){
        bool a = (int)score % 10 == 0;
        if(a && !isAddSpeed && (int)score != 0){
            spawn.speedScale += 0.2f;
            isAddSpeed = true;
            if(spawn.speedScale > 2){
                spawn.speedScale = 2;
            }
        }
        else if (!a && isAddSpeed)isAddSpeed = false;
    };

    void audioPlay(){
        soundBuf.loadFromFile("audio/play.ogg");
        sound.setBuffer(soundBuf);
        sound.setLoop(true);
        sound.play();
    };

    void audioPlayOff(){
        sound.stop();
    };

    void effectAudio(){
        energyBuf.loadFromFile("audio/energy.ogg");
        energySound.setBuffer(energyBuf);
    };
    void exploAudio(){
        exploBuf.loadFromFile("audio/explosion.ogg");
        exploSound.setBuffer(exploBuf);
    };

    void effectShield(){
        if(spawn.isShield){
            shield.setPosition(player.getPosition().x + 15, player.getPosition().y);
            if(spawn.currentShield < spawn.durationShield){
                spawn.currentShield += deltaTime.asSeconds();
                if(spawn.currentShield >= spawn.durationShield){
                    spawn.currentShield = 0;
                    spawn.isShield = false;
                }
            }
        }
        else shield.setPosition(-100, 0);
    };
};
