class SceneManagement{
public:
    int index;

    SceneManagement(){
        index = 0;
    };

    void update(){
        openScene();
    };

    void openScene(){
        if(index == 0){
            mainMenu();
        }
        else if(index == 1){
            playGame();
        }
    };

    void mainMenu(){
        textPlay.update();
    };

    void playGame(){
        spawn.update();
        player.update();
    };

};
