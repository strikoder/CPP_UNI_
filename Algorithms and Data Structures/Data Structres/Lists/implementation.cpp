#include"header.h"
using namespace std;


// constructor
CircularList::CircularList()
{
    head = NULL;
    tail = NULL;
    nodeNum=0;
    id=0;
}

// This function is adding the Player at the first of the CircularList
void CircularList::addAtFirst(Player p)
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
void CircularList::addAtLast(Player p)
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
void CircularList::addBefore(Player p, Player pos)
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
void CircularList::addAfter(Player p, Player pos)
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

bool CircularList::isEmpty()
{
    return head == NULL;
}

void CircularList::removeNode(Player p)
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
void CircularList::circularDisplay()
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
void CircularList::starDisplay()
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
            cout <<"\nPlayer ID: "<<temp->data.playerID<<endl;
            cout <<"Player name is: " <<temp->data.playerName<<" and his age is: "<<temp->data.playerAge<<endl;
        }
        else
        {
            temp=head;
            for(int i=0; i<nodeNum+1; i++)
            {
                cout <<"\nPlayer ID: "<<temp->data.playerID<<endl;
                cout <<"Player name is: " <<temp->data.playerName<<" and his age is: "<<temp->data.playerAge<<endl;
                temp=temp->next;
                temp=temp->next;
            }
        }
    }


}


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
