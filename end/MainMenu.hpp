class MainMenu{
public:
    sf::Text textPlay;
    sf::FloatRect textPlayRect;

    sf::Text textHighScore;
    sf::FloatRect textHighScoreRect;

    float current;
    float duration;
    bool isBlink;
    float maxScale;
    float valueScale;
    bool isScale;
    int temp;

    MainMenu(){
        start();
    };

    start(){
        current = 0;
        duration = 0.5f;
        isBlink = false;

        maxScale = 1.1f;
        valueScale = 1;
    };

    void update(){
        displayScore();
        display("Press SPACE to start the game", 24);
        animate(sf::Color::White, sf::Color(255, 255, 200, 225));
    };

    void displayScore(){
        textHighScore.setFont(font);

        textHighScore.setString(highScore.line);
        textHighScore.setCharacterSize(24);


        textHighScoreRect = textHighScore.getLocalBounds();
        textHighScore.setOrigin(textHighScoreRect.left + textHighScoreRect.width/2.0f, textHighScoreRect.top + textHighScoreRect.height/2.0f);
        textHighScore.setPosition(sf::Vector2f(SCREEN_WIDTH/2.0f,SCREEN_HEIGHT/2.0f + 200));

        window.draw(textHighScore);
    };

    void display(string valueText, unsigned int sizeText){
        textPlay.setFont(font);

        textPlay.setString(valueText);
        textPlay.setCharacterSize(sizeText);


        textPlayRect = textPlay.getLocalBounds();
        textPlay.setOrigin(textPlayRect.left + textPlayRect.width/2.0f, textPlayRect.top + textPlayRect.height/2.0f);
        textPlay.setPosition(sf::Vector2f(SCREEN_WIDTH/2.0f,SCREEN_HEIGHT/2.0f));

        window.draw(textPlay);
    };

    void animate(sf::Color color1, sf::Color color2){
        if(valueScale > maxScale){
            temp = -1;
        }
        else if(valueScale <= 1){
            temp = 1;
        }

        valueScale += deltaTime.asSeconds() * temp * 0.2;
        textPlay.setScale(valueScale, valueScale);

        if(current < duration){
            current += deltaTime.asSeconds();
            if(current >= duration){
                current = 0;
                if(isBlink){
                    textPlay.setFillColor(color1);
                    isBlink = false;
                }
                else{
                    textPlay.setFillColor(color2);
                    isBlink = true;
                }
            }
        }
    };

};
