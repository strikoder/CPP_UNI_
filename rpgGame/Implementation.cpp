#include "RpgGame.h"
using namespace std;
bool notfinished =1;
int **arr;

//I need to check the input, if it was an int instead of string and otherwise

void Initilize::setSizeArray()
{
    cout<<"Welcome to RPG turn-based game: \n\n";
    cout<<"##################################\n";
    cout<<"##################################\n";
    cout<<"##################################\n";
    cout<<"##################################\n";
    cout<<"##################################\n";
    cout<<"##################################\n\n\n";
    cout<<"Enter the size of the map please: \n";
    cin>>sizearr;
}

void Initilize::initializeTheGame()
{
    // creating an empty matrix
    arr=new int*[sizearr+4];
    for(int i=0; i<sizearr+4; i++)
    {
        arr[i]=new int[sizearr+4];
    }
    // filling the matrix randomly with 0 & 1
    for(int i=0; i<sizearr+4; i++)
    {
        for(int j=0; j<sizearr+4; j++)
        {
            // I made this step so if the player wanted to exit the matrix, I won't get out of range exception
            if(i==0||i==1||i==sizearr+3||i==sizearr+2||j==0||j==1||j==sizearr+3||j==sizearr+2)
                arr[i][j]=178;
            // I wrote this condition so I won't get too many barriers in the map
            // taking into account that the size of the REAL ARRAY is bigger with 2 columns and two lines
            // Also I added some conditions so that in the map won't be 2 barriers next to each other "makes no sense"
            else if (counter<(sizearr*sizearr)/4&&arr[i][j-1]!=178&&arr[i-1][j]!=178&&arr[i+1][j]!=178&&arr[i][j+1]!=178&&arr[i+1][j+1]!=178&&arr[i-1][j-1]!=178)
            {
                arr[i][j]=rand()%2 + 177;
                if(arr[i][j]==178)
                    counter++;
            }
            else
                arr[i][j]=177;
        }
    }
}

// Get function to get the size of the array
int Initilize::getSizeArray()
{
    return sizearr;
}

// Destructor
Initilize::~Initilize()
{
    //Here we are deleting the first array
    for(int i=0; i<sizearr; i++)
        delete[] arr[i];
    //over here we have deleted the second array
    delete[] arr;
    //and here we are pointing our main array to NULL
    arr=NULL;
}

//================================================================================================
//A function that is dealing with random values of the starting coordinates of player and bot
void Player::playerCoodinates()
{
    sizearr=getSizeArray();

//int randNum = rand()%(max-min + 1) + min;
    //Generating the coordinates of the players
    x1=rand()%(sizearr);

    y1=rand()%(sizearr);


    x2=rand()%(sizearr);


    y2=rand()%(sizearr);


    // solving the case where both of them are on the same spot
    if(x1==x2&&y1==y2)
    {
        if(arr[x2+1][y2]==177)
            x2++;
        else if(arr[x2][y2+1]==177)
            y2++;
        else if(arr[x2-1][y2]==177)
            x2--;
        else if(arr[x2][y2-1]==177)
            y2--;
    }
    arr[x1+2][y1+2]=206;
    arr[x2+2][y2+2]=126;
    for(int i=2; i<sizearr+2; i++)
    {
        for(int j=2; j<sizearr+2; j++)
        {
            cout<<(char)arr[i][j]<<" ";
        }
        cout<<endl;
    }

}

// Get functions to use these values in Game class
int Player::getDefaultCorrdinatesFirstPlayerX()
{
    return x1+2;
}

int Player::getDefaultCorrdinatesFirstPlayerY()
{
    return y1+2;
}

int Player::getDefaultCorrdinatesSecondPlayerX()
{
    return x2+2;
}

int Player::getDefaultCorrdinatesSecondPlayerY()
{
    return y2+2;
}

//================================================================================================
void Fighter::initializeFighter()
{
    hp=125;
    criticalDmg=2;
    endurance=0.2;
    dmg=10;
}

double Fighter::getFighterHp()
{
    return hp;
}

double Fighter::getFighterCriticalDmg()
{
    return criticalDmg;
}

double Fighter::getFighterEndurance()
{
    return endurance;
}

double Fighter::getFighterDmg()
{
    return dmg;
}

//================================================================================================
void Archer::initializeArcher()
{
    hp=100;
    criticalDmg=4;
    endurance=0.3;
    dmg=8;
}

double Archer::getArcherHp()
{
    return hp;
}

double Archer::getArcherCriticalDmg()
{
    return criticalDmg;
}

double Archer::getArcherEndurance()
{
    return endurance;
}

double Archer::getArcherDmg()
{
    return dmg;
}

//================================================================================================
void RPG::initializePlayersSpec()
{
    fighterHP=getFighterHp();
    fighterCriticalDmg=getFighterCriticalDmg();
    fighterEndurance=getFighterEndurance();
    fighterDmg=getFighterDmg();

    archerHP=getArcherHp();
    archerCriticalDmg=getArcherCriticalDmg();
    archerEndurance=getArcherEndurance();
    archerDmg=getArcherDmg();

    x1=getDefaultCorrdinatesFirstPlayerX();
    y1=getDefaultCorrdinatesFirstPlayerY();
    x2=getDefaultCorrdinatesSecondPlayerX();
    y2=getDefaultCorrdinatesSecondPlayerY();

    sizearr=getSizeArray();
}

void RPG::setPlayercharacterChoice()
{
    cout<<"Please enter (Fighter or Archer) to Choice your character's type."<<endl;
    cin>>character;
    if(character=="Archer"||character=="archer"||character=="a"||character=="A")
    {
        characterChoice=1;
        cout<<"You picked an Archer, try not to waste your arrows and always focus on headshots, it deals a critical damage to enemy!"<<endl;
    }


    // In case he entered a wrong case neither Fighter or Archer
    else if (character=="Fighter"||character=="fighter"||character=="f"||character=="F")
    {
        characterChoice=0;
        cout<<"You picked a barbarian, pickup a shield and go to the battlefield"<<endl;
    }
    else
    {
        cout<<"You didn't choose your character's type, so by default it will be randomly chosen "<<endl;
        characterChoice=rand()%2;
        if(characterChoice==0)
            cout<<"You have chosen a fighter, stay tight comrade."<<endl;
        else
            cout<<"You have chosen an archer, may the odds be ever in your favor."<<endl;
    }

}



void RPG::logic()
{
    while(notfinished)
    {

        rando=rand()%2;
        rando2=rand()%2;

        cout<<"Please enter WASD to move or E/Q to quit the game."<<endl;
        cin>>way;
        cout<<"###### Round: "<<roundNumber<<" Fight! #######\n";
        if (characterChoice==0)
        {
            // Player path finding
            switch(way)
            {
            case'w':case'W':
                if(arr[x1-1][y1]==177)
                {
                    arr[x1-1][y1]=206;
                    arr[x1][y1]=177;
                    x1-=1;
                    roundNumber++;
                }
                else
                {
                    cout<<"it's a wrong direction.\n";
                }
                break;

            case'a':case'A':
                if(arr[x1][y1-1]==177)
                {
                    arr[x1][y1]=177;
                    arr[x1][y1-1]=206;
                    y1-=1;
                    roundNumber++;
                }
                else
                {
                    cout<<"it's a wrong direction.\n";
                }
                break;

            case's':case'S':
                if(arr[x1+1][y1]==177)
                {
                    arr[x1][y1]=177;
                    arr[x1+1][y1]=206;
                    x1+=1;
                    roundNumber++;
                }
                else
                {
                    cout<<"it's a wrong direction.\n";
                }
                break;

            case'd':case'D':
                if(arr[x1][y1+1]==177)
                {
                    arr[x1][y1]=177;
                    arr[x1][y1+1]=206;
                    y1+=1;
                    roundNumber++;
                }
                else
                {
                    cout<<"it's a wrong direction.\n";
                }
                break;

            case'e':case'E':case'q':case'Q':
                gameOver();
                break;

            // if none of cases above is achieved, then the program will go to the default input
            default:
                cout<<"You have chosen a wrong input\n"<<"Please enter WASD to move or e,q to quit the Initialize.\n";

            }

            //bot path finding as an archer

            if(rando==0&&rando2==0&&arr[x2+1][y2]==177&&x2+1<sizearr)
            {
                arr[x2+1][y2]=126;
                arr[x2][y2]=177;
                x2+=1;
            }
            else if(rando==0&&rando2==1&&arr[x2-1][y2]==177&&x2-1>1)
            {
                arr[x2-1][y2]=126;
                arr[x2][y2]=177;
                x2-=1;
            }
            else if(rando==1&&rando2==0&&arr[x2][y2+1]==177&&y2+1<sizearr)
            {
                arr[x2][y2+1]=126;
                arr[x2][y2]=177;
                y2+=1;
            }
            else if (rando==1&&rando2==1&&arr[x2][y2-1]==177&&y2-1>1)
            {
                arr[x2][y2-1]=126;
                arr[x2][y2]=177;
                y2-=1;
            }

            drawMap();

        }
        else
        {
            switch(way)
            {
            case'w':
            case'W':
                if(arr[x2-1][y2]==177)
                {
                    arr[x2][y2]=177;
                    arr[x2-1][y2]=126;
                    x2-=1;
                    roundNumber++;

                }
                else
                {
                    cout<<"it's a wrong direction.\n";
                }
                break;

            case'a':case'A':
                if(arr[x2][y2-1]==177)
                {
                    arr[x2][y2]=177;
                    arr[x2][y2-1]=126;
                    y2-=1;
                    roundNumber++;
                }
                else
                {
                    cout<<"it's a wrong direction.\n";
                }
                break;

            case's':
            case'S':
                if(arr[x2+1][y2]==177)
                {
                    arr[x2][y2]=177;
                    arr[x2+1][y2]=126;
                    x2+=1;
                    roundNumber++;
                }
                else
                {
                    cout<<"it's a wrong direction\n.";
                }
                break;

            case'd':case'D':
                if(arr[x2][y2+1]==177)
                {
                    arr[x2][y2]=177;
                    arr[x2][y2+1]=126;
                    y2+=1;
                    roundNumber++;
                }
                else
                {
                    cout<<"it's a wrong direction.\n";
                }
                break;

            case'e':case'E':case'q':case'Q':
                notfinished=0;
                gameOver();
                break;

            // if none of cases above is achieved, then the program will go to the default input
            default:
                cout<<"You have wasted your turn\n"<<"Please enter WASD to move or e,q to quit the Game.\n";
            }

            //bot path finding as a fighter


            if(rando==0&&rando2==0&&arr[x1+1][y1]==177&&x1+1<sizearr)
            {
                arr[x1+1][y1]=206;
                arr[x1][y1]=177;
                x1+=1;
            }
            else if(rando==0&&rando2==1&&arr[x1-1][y1]==177&&x1-1>1)
            {
                arr[x1-1][y1]=206;
                arr[x1][y1]=177;
                x1-=1;
            }
            else if(rando==1&&rando2==0&&arr[x1][y1+1]==177&&y1+1<sizearr)
            {
                arr[x1][y1+1]=206;
                arr[x1][y1]=177;
                y1+=1;
            }
            else if (rando==1&&rando2==1&&arr[x1][y1-1]==177&&y1-1>1)
            {
                arr[x1][y1-1]=206;
                arr[x1][y1]=177;
                y1-=1;
            }

            drawMap();

        }

        fighting();

        if(fighterHP<=0||archerHP<=0||roundNumber==50)
        {
            gameOver();
        }
    }
}

void RPG::fighting()
{

    //206 figh  126 arch
    for(int i=0;i<=2;i++)
        for(int j=0;j<=2;j++)
        {

            // make a limit so they won't search out the matrix
            // if the player is on the right bottom corner
            if(arr[x1+i][y1+j]==126&&i<2&&j<2)
            {
                // I'm using the random numbers for critical hits so if "rando" is 1 the character will have a critical hit, if 0 it won't have
                *archerRealHP-=(fighterDmg+(fighterCriticalDmg*rando)*archerEndurance);
                if(*archerRealHP>0)
                    cout<<"The Archer got a hit, his HP is: "<<*archerRealHP<<endl;
                else
                    cout<<"The Archer is dead, RIP!"<<endl;
            }
            else if(arr[x1-i][y1-j]==126&&i<2&&j<2)
            {
                *archerRealHP-=(fighterDmg+(fighterCriticalDmg*rando)*archerEndurance);
                if(*archerRealHP>0)
                    cout<<"The Archer got a hit, his HP is: "<<*archerRealHP<<endl;
                else
                    cout<<"The Archer is dead, RIP!"<<endl;
            }
            else if(arr[x1-i][y1+j]==126&&i<2&&j<2)
            {
                *archerRealHP-=((fighterDmg+(fighterCriticalDmg*rando))*archerEndurance);
                if(*archerRealHP>0)
                    cout<<"The Archer got a hit, his HP is: "<<*archerRealHP<<endl;
                else
                    cout<<"The Archer is dead, RIP!"<<endl;
            }
            else if(arr[x1+i][y1-j]==126&&i<2&&j<2)
            {
                *archerRealHP-=(fighterDmg+(fighterCriticalDmg*rando)*archerEndurance);
                if(*archerRealHP>0)
                    cout<<"The Archer got a hit, his HP is: "<<*archerRealHP<<endl;
                else
                    cout<<"The Archer is dead, RIP!"<<endl;;
            }



            if(arr[x2+i][y2+j]==206)
            {
                *fighterRealHP-=((archerDmg+(archerCriticalDmg*rando2))*fighterEndurance);
                if(*fighterRealHP>0)
                    cout<<"The Fighter got shot, and his HP is: "<<*fighterRealHP<<endl;
                else
                    cout<<"The Fighter is dead, press F to pay respect!"<<endl;
            }
            else if(arr[x2-i][y2-j]==206)
            {
                *fighterRealHP-=((archerDmg+(archerCriticalDmg*rando2))*fighterEndurance);
                if(*fighterRealHP>0)
                    cout<<"The Fighter got shot, and his HP is: "<<*fighterRealHP<<endl;
                else
                    cout<<"The Fighter is dead, press F to pay respect!"<<endl;
            }
            else if(arr[x2+i][y2-j]==206)
            {
                *fighterRealHP-=((archerDmg+(archerCriticalDmg*rando2))*fighterEndurance);
                if(*fighterRealHP>0)
                    cout<<"The Fighter got shot, and his HP is: "<<*fighterRealHP<<endl;
                else
                    cout<<"The Fighter is dead, press F to pay respect!"<<endl;
            }
            else if(arr[x2-i][y2+j]==206)
            {
                *fighterRealHP-=((archerDmg+(archerCriticalDmg*rando2))*fighterEndurance);
                if(*fighterRealHP>0)
                    cout<<"The Fighter got shot, and his HP is: "<<*fighterRealHP<<endl;
                else
                    cout<<"The Fighter is dead, press F to pay respect!"<<endl;
            }
        }

}

void RPG::drawMap()
{

    for(int i=2; i<sizearr+2; i++)
    {
        for(int j=2; j<sizearr+2; j++)
        {
            cout<<(char)arr[i][j]<<" ";
        }
        cout<<endl;
    }

}



// I'm launching all the important functions inside this method
void RPG::launchTheGame()
{
    setSizeArray();
    initializeTheGame();
    playerCoodinates();
    initializeFighter();
    initializeArcher();
    setPlayercharacterChoice();
    initializePlayersSpec();
    logic();
}

void RPG::gameOver()
{
    notfinished=0;
    cout<<endl<<endl;
    if(roundNumber>=100)
        cout<<"The game has finished, DRAW.";
    else if(archerHP<=0)
        cout<<"The fighter is the winner, try to shoot better next time :)";
    else
        cout<<"You should've bought a better shield #, good luck next time worrier.";
}




