#include <bits/stdc++.h>

using namespace std;

class Stack
{
private:
    int top;
    int *arr;
    int sizearr;
public:
    Stack()
    {
        top =-1;
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
        return (top==-1)?true:false;
    }

    bool isFull()
    {
        return(top==sizearr-1)?true:false;
    }

    void push(int value)
    {
        if(!isFull())
        {
            top++;
            arr[top]=value;

        }
        else
            cout<<"Stack overflow, you can't fill the stack anymore\n";
    }

    void pop()
    {
        if(!isEmpty())
        {
            cout<<"The deleted value is: "<<arr[top]<<endl;
            arr[top]=0;
            top--;
        }
        else
        {
            cout<<"Stack underflow, you can't delete a value from an empty stack\n";
        }
    }

    int length()
    {
        return(top+1);
    }

    int peek(int pos)
    {
        if(!isEmpty())
        {
            return arr[pos-1];
        }
        else
        {
            cout<<"Stack underflow, you can't search for a value in an empty stack\n";
            return 0;
        }
    }

    int changeValue(int pos, int value)
    {
        cout<<"The value of the position["<<pos<<"] has been changed from "<<arr[pos-1];
        arr[pos-1]=value;
        cout<<" to "<<arr[pos-1]<<endl;
    }

    void display()
    {
        cout<<"All the values in the stack are\n";
        for(int i=sizearr-1;i>=0;i--)
        {
            cout<<"====="<<endl;
            cout<<"|"<<arr[i]<<"|"<<endl;
            cout<<"====="<<endl;
        }
    }

    ~Stack()
    {
        delete [] arr;
    }
};


int main()
{
    Stack s;
    int option,position,value;
    system("cls");
    do
    {
        cout<<"Welcome to stack program, please select the option number, or enter 0 to quit the application\n";
        cout<<"1. push()\n";
        cout<<"2. pop()\n";
        cout<<"3. isEmpty()\n";
        cout<<"4. isFull()\n";
        cout<<"5. peek()\n";
        cout<<"6. length()\n";
        cout<<"7. changeValue()\n";
        cout<<"8. display\n";
        cout<<"9. Clear Screen\n";

        cin>>option;
        switch(option)
        {
            case 0:
                break;

            case 1:
                cout<<"Enter a number to push it into the stack\n";
                cin>>value;
                s.push(value);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.isEmpty()==true?cout<<"The stack is empty\n":cout<<"The stack is not empty, get out of my face :D"<<endl;
                break;

            case 4:
                s.isFull()==true?cout<<"The stack is full\n":cout<<"The stack is not full yet, what you're waiting for, go and add some values to it."<<endl;
                break;

            case 5:
                cout<<"Enter the position of the value that your are peeking for\n";
                cin>>position;
                cout<<"The value of the position that you are searching for is: "<<s.peek(position);
                break;

            case 6:
                cout<<"The current stack has: "<<s.length()<<" elements";
                break;

            case 7:
                cout<<"Enter the position of the value that you want to change: ";
                cin>>position;
                cout<<"\nEnter the value: ";
                cin>>value;
                cout<<endl;
                s.changeValue(position,value);
                break;

            case 8:
                s.display();
                break;

            case 9:
                system("cls");
                break;

            default:
                cout<<"Please choice an option or press 0 to exit\n";

        }
    }while(option!=0);
    cout<<"Thank you for using our program";
    return 0;
}
