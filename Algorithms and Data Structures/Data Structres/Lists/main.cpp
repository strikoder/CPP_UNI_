#include <bits/stdc++.h>
#include "header.h"
using namespace std;


int main()
{
    CircularList l;
    Player player1,player2;
    int option;
    cout<<"Welcome to our CircularList program.\n";
    do
    {
        menu();
        cin>>option;
        switch(option)
        {
            case 1:
                cout<<"Enter the name of the player please: \n";
                cin>>player1.playerName;
                cout<<"Enter the age of the player please: \n";
                cin>>player1.playerAge;
                l.addAtFirst(player1);
                break;

            case 2:
                cout<<"Enter the Name of the player please: \n";
                cin>>player1.playerName;
                cout<<"Enter the age of the player please: \n";
                cin>>player1.playerAge;
                l.addAtLast(player1);
                break;

            case 3:
                cout<<"Enter the the name of the player please: \n";
                cin>>player1.playerName;
                cout<<"Enter the age of the player please: \n";
                cin>>player1.playerAge;
                cout<<"Please enter the name of the player that you want to add this player before \n";
                cin>>player2.playerName;
                l.addBefore(player1,player2);
                break;

            case 4:
                cout<<"Enter the name of the player please: \n";
                cin>>player1.playerName;
                cout<<"Enter the age of the player please: \n";
                cin>>player1.playerAge;
                cout<<"Please enter the name of the player that you want to add this player after \n";
                cin>>player2.playerName;
                l.addAfter(player1,player2);
                break;

            case 5:
                cout<<"Enter the name of the player that you want to remove please: \n";
                cin>>player2.playerName;
                l.removeNode(player2);
                break;

            case 6:
                l.circularDisplay();
                break;

            case 7:
                l.isEmpty();
                break;

            case 8:
                system("cls");
                break;
            case 9:
                l.starDisplay();
                break;
            default:
                cout<<"You didn't choose a proper output, please try again\n";

        }
    }
    while(option!=0);

    return 0;
}
