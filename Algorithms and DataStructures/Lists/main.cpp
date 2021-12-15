#include <bits/stdc++.h>

using namespace std;

//

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

    Node *head;

    Node *tail;

    Node *temp;

    int nodeNum;

    int id;

public:
    // constructor
    CircularList()
    {
        head = NULL;
        tail = NULL;
        nodeNum=0;
        id=0;
    }

    // This function is adding the Player at the first of the CircularList
    void addAtFirst(Player p)
    {

        temp = new Node;

        id++;
        p.playerID=id;
        temp->data = p;

        if (isEmpty())
        {
            tail = temp;
            temp->next=temp;
        }
        else
        {
            temp->next = head;
            tail->next=temp;
        }


        head = temp;
        nodeNum++;


    }
    void addAtLast(Player p)
    {
        temp = new Node;

        id++;
        p.playerID=id;
        temp->data = p;

        if (isEmpty())
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
        temp->next = head;
        nodeNum++;
    }
    // I'm using add before using only 2 pointers instead of 3 :D  "more efficient for memory"
    void addBefore(Player p, Player pos)
    {
        if (isEmpty())
        {
            cout << "Logic error, the CircularList is empty, please add some Nodes before using this function"<<endl;
        }
        // if we have only one node in our list
        else if (nodeNum == 1)
        {
            addAtFirst(p);
        }
        else
        {
            // initializing 2 pointers
            Node *prev;
            Node *after;
            prev = head;
            after = head->next;

            //if we add before first position
            if(prev->data.playerName==pos.playerName)
            {
                addAtFirst(p);
            }

            else
            {
                while (after->next != head && after->data.playerName != pos.playerName)
                {
                    prev = after;
                    after = after->next;
                }

                if (after->data.playerName == pos.playerName)
                {
                    temp = new Node;
                    id++;
                    p.playerID=id;
                    temp->data = p;
                    temp->next = prev->next;
                    prev->next = temp;
                    nodeNum++;
                }

                else
                {
                    cout << "Error, couldn't find the desired position to insert the Player!"<<endl;
                }

            }

        }
    }
    void addAfter(Player p, Player pos)
    {

        if (isEmpty())
        {
            cout << "Logic error, the CircularList is empty, please add some Nodes before using this function";
        }
        // if we have only one node is our list
        else if (nodeNum == 1)
        {
            addAtLast(p);
        }

        else
        {

            Node *after = new Node;
            after = head;

            while (after->next != head && after->data.playerName != pos.playerName)
            {
                after = after->next;
            }

            if (after->data.playerName == pos.playerName)
            {
                temp = new Node;
                id++;
                p.playerID=id;
                temp->data=p;
                temp->next=after->next;
                after->next=temp;
                nodeNum++;

            }
            else
            {
                cout << "Error, couldn't find the desired position to insert the Player!\n";
            }
        }
    }

    bool isEmpty()
    {
        return head == NULL;
    }

    void removeNode(Player p)
    {
        temp = head;
        Node *prev;
        while (temp->next != head && temp->data.playerName != p.playerName)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp->data.playerName == p.playerName)
        {
            if (nodeNum > 1)
            {
                prev->next = temp->next;
                cout<<temp->data.playerName<<" has been deleted successfully "<<endl;
                delete temp;
            }
            else
            {
                cout <<"Error, please add any Node before deleteing";
            }
        }
        else
        {
            cout << "couldn't find the desired Node to delete";
        }
    }

    // This function is for printing the CircularList
    void circularDisplay()
    {

        if (!isEmpty())
        {
            cout << "The Game has: "<< nodeNum <<" Players"<<endl<<endl;
            for (temp = head; temp->next != head; temp = temp->next)
            {
                cout <<"\nPlayer ID: "<<temp->data.playerID<<endl;
                cout <<"Player name is: " <<temp->data.playerName<<" and his age is: "<<temp->data.playerAge<<endl;

            }
            cout <<"\nPlayer ID: "<<temp->data.playerID<<endl;
            cout <<"Player name is: " <<temp->data.playerName<<" and his age is: "<<temp->data.playerAge<<endl;
            cout<<endl;

        }
        else
        {
            cout << "Error, the CircularList is empty, please add some Nodes before using this function\n";
        }
    }
    void starDisplay()
    {
        if(!isEmpty())
        {
            if(nodeNum%2==0)
            {
                for (temp = head; temp->next != head; temp = temp->next)
                    if(temp->data.playerID%2==0)
                    {
                        cout <<"\nPlayer ID: "<<temp->data.playerID<<endl;
                        cout <<"Player name is: " <<temp->data.playerName<<" and his age is: "<<temp->data.playerAge<<endl;
                    }
                for (temp = head; temp->next != head; temp = temp->next)
                    if(temp->data.playerID%2!=0)
                    {
                        cout <<"\nPlayer ID: "<<temp->data.playerID<<endl;
                        cout <<"Player name is: " <<temp->data.playerName<<" and his age is: "<<temp->data.playerAge<<endl;
                    }
            }
            else
            {
                temp=head;
                for(int i=0;i<nodeNum+1;i++)
                {
                    cout <<"\nPlayer ID: "<<temp->data.playerID<<endl;
                    cout <<"Player name is: " <<temp->data.playerName<<" and his age is: "<<temp->data.playerAge<<endl;
                    temp=temp->next;
                    temp=temp->next;
                }
            }
        }


    }
};

void menu()
{
    cout<<"Please enter 1 to add first of the CircularList.\n";
    cout<<"Please enter 2 to add at last of the CircularList.\n";
    cout<<"Please enter 3 to add before of the CircularList.\n";
    cout<<"Please enter 4 to add after of the CircularList.\n";
    cout<<"Please enter 5 to remove.\n";
    cout<<"Please enter 6 to circularDisplay the CircularList.\n";
    cout<<"Please enter 7 to check if the CircularList is empty or not.\n";
    cout<<"Please enter 8 to clear out the screen.\n";
    cout<<"Please enter 9 to use starDisplay.\n";
    cout<<"Please enter 0 to exit the program.\n";
}


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
