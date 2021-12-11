#include <bits/stdc++.h>

using namespace std;

class Queue()
{
private:
    int arr[4];
    int *arr;
    int sizearr,rearQ,frontQ;
public:
    Queue()
    {
        rearQ =-1;
        frontQ=-1;
        cout<<"Enter the size of the stack please: ";
        cin>>sizearr;
        arr=new int[sizearr];
        for(int i=0;i<sizearr;i++)
        {
            arr[i]=0;
        }
    }
    bool isEmpty()
    {
        (frontQ==-1&&rearQ==-1)?true:false;
    }
    bool isFull()
    {
        (rear==sizearr-1)?true:false;
    }
    void enqueue(int value)
    {
        if(isFull())
            return;
        else if(isEmpty())
        {
            rearQ=frontQ=0;
        }
        else
        {
            rearQ++;
        }
        arr[rearQ]=value;
    }
    int dequeue()
    {
        int x=0;
        if(isEmpty())
        {
            cout<<"Queue is Empty dude\n";
            return 0;
        }
        else if(frontQ==rearQ)
        {
            x=arr[frontQ];
            arr[frontQ]=0;
            frontQ=rearQ=-1;
            return x;
        }
        else
        {
            x=arr[frontQ];
            arr[frontQ]=0;
            frontQ++;
            return x;
        }
    }
};

int main()
{
    int option;
    Queue q
    do
    {
        cout<<"Welcome to our Queue program.\n"<<"Which operation do you want to use? select option number please, or enter 0 to quit\n";
        cout<<"1. Enqueue()\n";
        cout<<"2. Dequeue()\n";
        cout<<"3. isEmpty()\n";
        cout<<"4. isFull()\n";
        cout<<"5. count()\n";
        cout<<"6. display()\n";
        cout<<"7. Clear Screen()\n";

        cin>>option;

        switch(option)
        {
            case 0:
                break;
            case 1;
                break;
            case 2:
                break;
            case 3;
                break;
            case 4:
                break;
            case 5;
                break;
            case 6:
                break;
            case 7:
                break;
            default:
        }

    }while(option!=0)

    return 0;
}
