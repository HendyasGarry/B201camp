class Spawn{
public:
    sf::Texture textureEnergy;
    sf::Sprite energy;
    sf::Texture textureRoad;
    sf::Sprite road;
    sf::Texture textureEnemy;
    sf::Sprite enemy;
    sf::Texture textureTree;
    sf::Sprite tree;
    sf::Texture textureChick;
    sf::Sprite chick;
    sf::Texture textureItem[2];
    sf::Sprite item;

    float speedScale;

    float speedEnergyGroup[5] = {0.1f, 0.2f, 0.5f, 0.6f, 0.8f};
    float speedEnergy;

    float current;
    float duration;
    int medScreen = SCREEN_WIDTH / 2;
    int randEnergy[5] = {medScreen - 15, medScreen - 70, medScreen + 55, medScreen + 150, medScreen - 135};

    float speedEnemyGroup[3] = {0.5f, 0.3f, 0.7f};
    float speedEnemy;

    float currentEnemy;
    float durationEnemy;
    int randEnemy[5] = {medScreen - 50, medScreen -120, medScreen + 50, medScreen - 180, medScreen + 100};

    float currentChick;
    float durationChick;

    float currentItem;
    float durationItem;
    int indexItem;

    float currentShield;
    float durationShield;
    bool isShield;

    Spawn(){
        //start();
    };

    start(){
        indexItem = 0;
        current = 0;
        duration = 10;

        speedEnemy = 0.5f;
        currentEnemy = 0;
        durationEnemy = 3;
        speedScale = 1;

        currentChick = 0;
        durationChick = 5;

        currentItem = 0;
        durationItem = 15;

        currentShield = 0;
        durationShield = 5;
        isShield = false;

        textureItem[0].loadFromFile("img/shield.png");
        textureItem[1].loadFromFile("img/slow.png");

        speedEnergy = 0.1f;
        textureEnergy.loadFromFile("img/energy.png");
        energy.setTexture(textureEnergy);
        energy.setScale(0.2f, 0.2f);
        energy.setPosition(randEnergy[0], -10);

        speedEnergy = 0.1f;
        textureEnemy.loadFromFile("img/car.png");
        enemy.setTexture(textureEnemy);
        enemy.setScale(0.3f, 0.3f);
        enemy.setPosition(-1000, -100);
        enemy.setColor(sf::Color::Red);

        textureRoad.loadFromFile("img/road.jpg");
        road.setTexture(textureRoad);
        road.setScale(3.7f, 10);
        road.setPosition(0, -2000);

        textureTree.loadFromFile("img/tree.png");
        tree.setTexture(textureTree);
        tree.setScale(0.03f, 0.03f);
        tree.setPosition(0, 0);

        textureChick.loadFromFile("img/chick.png");
        chick.setTexture(textureChick);
        chick.setScale(1, 1);
        chick.setPosition(0, 1000);
    };

    void update(){
        roadMove();
        spawnChick();
        spawnEnemy();
        spawnEnergy();
        spawnItem();
        window.draw(tree);

        if(chick.getGlobalBounds().intersects(enemy.getGlobalBounds())){
            //chick.setPosition(0, -1000);
        }
    };

    void spawnItem(){
        if(currentItem < durationItem){
            currentItem += deltaTime.asSeconds();
            if(currentItem >= durationItem){
                currentItem = 0;
                indexItem = rand() % 2;
                if(speedScale < 1.5 && indexItem == 1){
                    indexItem = 0;
                }
                item.setTexture(textureItem[indexItem]);
                int x = rand() % 5;
                item.setScale(0.3f, 0.3f);
                item.setPosition(randEnemy[x], -200);
            }
        }
        item.move(0, 1 * speedScale);
        window.draw(item);
    };

    void spawnChick(){
        if(currentChick < durationChick){
            currentChick += deltaTime.asSeconds();
            if(currentChick >= durationChick){
                currentChick = 0;
                chick.setPosition(rand() % SCREEN_WIDTH / 2, -50);
            }
        }
        chick.move(0.2f, speedEnemy * speedScale);
        window.draw(chick);
    };

    void spawnEnemy(){
        if(currentEnemy < durationEnemy){
            currentEnemy += deltaTime.asSeconds();
            if(currentEnemy >= durationEnemy){
                currentEnemy = 0;
                speedEnemy = speedEnemyGroup[(rand() % 3)];
                int x = rand() % 5;
                enemy.setPosition(randEnemy[x], -200);
            }
        }
        enemy.move(0, speedEnemy * speedScale);
        window.draw(enemy);
    };

    void roadMove(){
        road.move(0, 1 * speedScale);
        if(road.getPosition().y >= 0){
            road.setPosition(0, -2000);
        }
        window.draw(road);
    };

    void spawnEnergy(){
        if(current < duration){
            current += deltaTime.asSeconds();
            if(current >= duration){
                current = 0;
                speedEnergy = speedEnergyGroup[(rand() % 5)];
                int x = rand() % 5;
                energy.setPosition(randEnergy[x], -50);

            }
        }
        energy.move(0, speedEnergy * speedScale);
        window.draw(energy);
    };

};
