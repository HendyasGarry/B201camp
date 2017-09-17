class HighScore{
public :
    int myHighScore;
    int playerScore;
    string line;

    HighScore(){
        ReadScore();
    };

    void ReadScore(){
        ifstream myFile ("score.txt");
        if(myFile.is_open()){
            while (getline(myFile,line)){
                myHighScore = atoi(line.c_str());
            }
        }
        else cout<<"score.txt not found"<<endl;
    }

    void SaveScore(){
        if(playerScore > myHighScore){
            myHighScore = playerScore;

            ofstream myFile ("score.txt");
            if(myFile.is_open()){
                myFile << myHighScore;
                myFile.close();
            }
            else cout<<"score.txt not found"<<endl;
        }
    };

};
