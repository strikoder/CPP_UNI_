#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include<bits/stdc++.h>
using namespace std;
struct Player
{

    string playerName;

    int playerAge;

    int playerID;

};

struct Node
{

    Player data;

    Node *next;

};

class CircularList
{
private:
    Node *head;

    Node *tail;

    Node *temp;

    int nodeNum;

    int id;

public:
    // constructor
    CircularList();

    // This function is adding the Player at the first of the CircularList
    void addAtFirst(Player p);

    void addAtLast(Player p);

    // I'm using add before using only 2 pointers instead of 3 :D  "more efficient for memory"
    void addBefore(Player p, Player pos);

    void addAfter(Player p, Player pos);

    bool isEmpty();

    void removeNode(Player p);

    // This function is for printing the CircularList
    void circularDisplay();

    void starDisplay();
};

void menu();



#endif // HEADER_H_INCLUDED
