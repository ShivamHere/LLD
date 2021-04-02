#include<bits/stdc++.h>
using namespace std;

class Player
{
    int id;
    string name;
    int currPosition;
    bool open;
public:
    void setPlayer(int i, string s){
        id = i;
        name = s;
        currPosition = 0;
        open = false;
    };
    int getCurrPosition() const { return currPosition; }
    void setCurrPosition(int value) { currPosition = value; }
    string getName() const { return name; }

    bool getOpen() const { return open; }
    void setOpen(bool value) { open = value; }
};
typedef unordered_map<int, int> SnakesLadders;
class Game
{
    SnakesLadders snakesLadders;
    int currPlayer;
    Player *Winner;
public:
    Game(){
        this->currPlayer = 0;
        this->Winner = nullptr;
    }
    int rollDice() const { return (rand()%6) + 1; }
    void setGame(SnakesLadders value) { snakesLadders = value; };
    int getCurrPlayer() const { return currPlayer; }
    void setCurrPlayer(int value) { currPlayer = value; }
    Player *winner() const { return Winner; }
    void setWinner(Player *value) { Winner = value; }
    SnakesLadders getSnakesLadders() { return snakesLadders; }
};

int main()
{   
    SnakesLadders snakesLadders;
    snakesLadders.insert( {{99,4},{91,49},{86,46},{80,43},{37,19},{13,7},
    {5,27},{9,51},{22,60},{28,54},{44,79},{66,88},{71,92},{85,97}});
    Game game;
    game.setGame(snakesLadders);
    cout<<"Add Number of Players: ";
    int totalPlayers;
    cin>>totalPlayers;
    Player player[totalPlayers];
    int id=0;
    while(id < totalPlayers)    //Take name and set id of players
    {
        string name;
        cout<<"Enter Player "<<id+1<<" Name : ";
        cin>>name;
        player[id].setPlayer(id, name);
        id++;
    }
    srand(time(0));
    do{
        id = game.getCurrPlayer();
        int curr = player[id].getCurrPosition();
        cout<<player[id].getName()<<" is at : "<<curr<<"\t\t\t\t";
        system("PAUSE");
        int diceNum = game.rollDice();
        cout<<player[id].getName()<<" got dice number : "<< diceNum<<"\t\t\t";
        system("PAUSE");
        if(diceNum==6 && player[id].getOpen()==false){
            player[id].setOpen(true);
            continue;
        }
        if(player[id].getOpen()==false){
            game.setCurrPlayer((id+1)%totalPlayers);
            continue;
        }
        int newPos = curr+diceNum>100? curr : curr+diceNum;
        SnakesLadders snakesLadders = game.getSnakesLadders();
        if(snakesLadders.count(newPos)) newPos = snakesLadders[newPos];
        if(newPos==100) game.setWinner(&player[id]);
        else    player[id].setCurrPosition(newPos);
        curr = player[id].getCurrPosition();
        
        cout<<player[id].getName()<<" is now at :"<<curr<<endl;
        game.setCurrPlayer((id+1)%totalPlayers);
    }while(game.winner()==nullptr);
    cout<<endl<<"Winner : "<<game.winner()->getName()<<endl;
    system("PAUSE");
    return 0;
}