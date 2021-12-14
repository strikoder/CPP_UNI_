#include <bits/stdc++.h>

using namespace std;

class CircularQueue
{
private:
    int *arr;
    int sizearr,rearQ,frontQ,itemsCount;
public:
    CircularQueue(int sizearr)
    {
        rearQ =-1;
        frontQ=-1;
        itemsCount=0;
        this->sizearr=sizearr;
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
        return ((rearQ+1)%sizearr==frontQ)?true:false;
    }
    void enQueue(int value)
    {
        if(isFull())
            return;
        else if(isEmpty())
        {
            rearQ=frontQ=0;
        }
        else
        {
            rearQ=(rearQ+1)%sizearr;
        }
        arr[rearQ]=value;
        itemsCount++;
    }
    int deQueue()
    {
        int x=0;
        if(isEmpty())
        {
            cout<<"CircularQueue is Empty dude\n";
            return 0;
        }
        else if(frontQ==rearQ)
        {
            x=arr[frontQ];
            arr[frontQ]=0;
            frontQ=rearQ=-1;
        }
        else
        {
            x=arr[frontQ];
            arr[frontQ]=0;
            frontQ=(frontQ+1)%sizearr;
        }
        itemsCount--;
        return x;
    }

    int length()
    {
        return(itemsCount);
    }

    void display()
    {
        cout<<" The values in the CircularQueue are - "<<endl;
        for(int i=0;i<sizearr;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    int option,value,x,sizearr;

    cout<<"Enter the size of the CircularQueue please: ";
    cin>>sizearr;
    CircularQueue q(sizearr);

    cout<<"Welcome to our CircularQueue program.\n"<<"Which operation do you want to use? select option number please, or enter 0 to quit\n";
    do
    {
        cout<<"1. EnQueue()\n";
        cout<<"2. DeQueue()\n";
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
                cout<<"Please enter an integer to enqueue in the CircularQueue \n";
                cin>>value;
                q.enQueue(value);
                break;
            case 2:
                x=q.deQueue();
                x==0?cout<<"Sorry the stack is empty, you can't do anything\n":cout<<"The dequeued value is : "<<x<<endl;
                break;
            case 3:
                q.isEmpty()?cout<<"The CircularQueue is Empty, gl next time\n":cout<<"The CircularQueue is not empty, lel\n";
                break;
            case 4:
                q.isFull()?cout<<"The CircularQueue is Full, sad\n":cout<<"CircularQueue is not full, YET!\n";
                break;
            case 5:
                cout<<"The count of the current items in CircularQueue is :"<<q.length()<<endl;
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
