#ifndef RPGGAME_H_INCLUDED
#define RPGGAME_H_INCLUDED
#include<bits/stdc++.h>
using namespace std;

//int randNum = rand()%(max-min + 1) + min;

class Initilize
{
private:
    int sizearr;
    int counter=0;
public:

    void setSizeArray();

    void initializeTheGame();

    // Get function to get the size of the array
    int getSizeArray();


    // Destructor
    ~Initilize();

};

class Player:public Initilize
{

private:
    int x1,x2,y1,y2;
    int sizearr;
    int health,endurance;
public:

    //A function that is dealing with random values of the starting coordinates of player and bot
    void playerCoodinates();

    // Get functions to use these values in Game class
    int getDefaultCorrdinatesFirstPlayerX();

    int getDefaultCorrdinatesFirstPlayerY();

    int getDefaultCorrdinatesSecondPlayerX();

    int getDefaultCorrdinatesSecondPlayerY();


};


class Fighter:virtual public Player
{
private:

    double hp,criticalDmg,endurance,dmg;

public:

    void initializeFighter();

    double getFighterHp();

    double getFighterCriticalDmg();

    double getFighterEndurance();

    double getFighterDmg();


};

class Archer:virtual public Player
{
private:
    double hp,criticalDmg,endurance,dmg;
public:
    void initializeArcher();

    double getArcherHp();

    double getArcherCriticalDmg();

    double getArcherEndurance();

    double getArcherDmg();
};

class RPG:public Fighter, public Archer
{
private:
    string character="";
    char way;
    bool characterChoice=0;
    int roundNumber=0,rando=0,rando2=0;
    int sizearr;
    int x1,x2,y1,y2;
    double fighterHP,fighterCriticalDmg,fighterEndurance,fighterDmg,archerHP,archerCriticalDmg,archerEndurance,archerDmg;
    double *fighterRealHP=&fighterHP,*archerRealHP=&archerHP;
public:

    void initializePlayersSpec();

    void setPlayercharacterChoice();

    void logic();

    void drawMap();

    void fighting();

    // I'm launching all the important functions inside this method
    void launchTheGame();

    void gameOver();



};

#endif // RPGGAME_H_INCLUDED
