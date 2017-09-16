class Spawn{
public:
    sf::Texture textureEnergy;
    sf::Sprite energy;
    sf::Texture textureRoad;
    sf::Sprite road;

    float speedEnergyGroup[5] = {0.1f, 0.2f, 0.5f, 0.6f, 0.8f};
    float speedEnergy;

    float current;
    float duration;
    int i;

    Spawn(){
        current = 0;
        duration = 10;
        i = 0;

        speedEnergy = 0.1f;
        textureEnergy.loadFromFile("img/energy.png");
        energy.setTexture(textureEnergy);
        energy.setScale(0.2f, 0.2f);

        textureRoad.loadFromFile("img/road.jpg");
        road.setTexture(textureRoad);
        road.setScale(3.7f, 10);
        road.setPosition(-100, -2000);
    };

    void update(){
        spawnEnergy();
        roadMove();
    };

    void roadMove(){
        road.move(0, 1);
        if(road.getPosition().y >= 0){
            road.setPosition(-100, -2000);
        }
    };

    void spawnEnergy(){
        if(current < duration){
            current += deltaTime.asSeconds();
            if(current >= duration){
                current = 0;
                i++;
                speedEnergy = speedEnergyGroup[(rand() % 5)];
                int x = rand() % (SCREEN_WIDTH - 100);
                energy.setPosition(x, -10);

            }
        }

        energy.move(0, speedEnergy);
        window.draw(road);
        window.draw(energy);
    };

};
