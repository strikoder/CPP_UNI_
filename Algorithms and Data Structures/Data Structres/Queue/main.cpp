#include <bits/stdc++.h>

using namespace std;

class Queue
{
private:
    int *arr;
    int sizearr,rearQ,frontQ;
public:
    Queue()
    {
        rearQ =-1;
        frontQ=-1;
        cout<<"Enter the size of the Queue please: ";
        cin>>sizearr;
        arr=new int[sizearr];
        for(int i=0;i<sizearr;i++)
        {
            arr[i]=0;
        }
    }
    bool isEmpty()
    {
        return (frontQ==-1&&rearQ==-1)?true:false;
    }
    bool isFull()
    {
        return (rearQ==sizearr-1)?true:false;
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
            x=arr[rearQ];
            arr[rearQ]=0;
            rearQ--;
            return x;
        }
    }

    int length()
    {
        return(rearQ-frontQ+1);
    }

    void display()
    {
        cout<<" The values in the Queue are - "<<endl;
        for(int i=0;i<sizearr;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    int option,value,x;
    Queue q;
    cout<<"Welcome to our Queue program.\n"<<"Which operation do you want to use? select option number please, or enter 0 to quit\n";
    do
    {
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
            case 1:
                cout<<"Please enter an integer to enqueue in the Queue \n";
                cin>>value;
                q.enqueue(value);
                break;
            case 2:
                x=q.dequeue();
                x==0?cout<<"Sorry the stack is empty, you can't do anything\n":cout<<"The dequeued value is : "<<x<<endl;
                break;
            case 3:
                q.isEmpty()?cout<<"The Queue is Empty, gl next time\n":cout<<"The Queue is not empty, lel\n";
                break;
            case 4:
                q.isFull()?cout<<"The Queue is Full, sad\n":cout<<"Queue is not full, YET!\n";
                break;
            case 5:
                cout<<"The count of the current items in Queue is :"<<q.length()<<endl;
                break;
            case 6:
                q.display();
                break;
            case 7:
                system("cls");
                break;
            default:

                cout<<"Please choose a choice from above";
                break;

        }

    }while(option!=0);

    return 0;
}
