#include <bits/stdc++.h>
using namespace std;
bool notfinished =1;

/*
 ____  _   _  ____  ____  ____     __      __    ____
(_  _)( )_( )(_  _)(  _ \(  _ \   (  )    /__\  (  _ \
  )(   ) _ (  _)(_  )   / )(_) )   )(__  /(__)\  ) _ <
 (__) (_) (_)(____)(_)\_)(____/   (____)(__)(__)(____/

*/

class Game
{
private:
    int sizearr,x,y;
    int **arr;
    string way;
public:

    //Constructor with parameter
    Game(int siz)
    {
        sizearr=siz;
        // creating an empty matrix
        arr=new int*[sizearr+2];
        for(int i=0;i<sizearr+2;i++)
        {
            arr[i]=new int[sizearr+2];
        }
        // filling the matrix randomly with 0 & 1
        for(int i=0;i<sizearr+2;i++)
        {
            for(int j=0;j<sizearr+2;j++)
            {
                //I made this step so if the player wanted to exit the matrix, I won't get an error because he went out of the range
                if(i==0||i==sizearr+1||j==0||j==sizearr+1)
                    arr[i][j]=1;
                else
                    arr[i][j]=rand()%2;
            }
        }
        StartPoint();
        Location();

    }

    //A function that is dealing with random values of the starting coordinates
    void StartPoint()
    {
        int r =1+rand()%(sizearr*sizearr);

        cout<<"My random number is: "<<r<<" "<<endl;

        x=(r/sizearr);
        if(r%sizearr!=0)
            x++;

        y=r%sizearr;
        if(y%sizearr==0)
            y+=sizearr;
        //Binary starts from 0 and also there is 2 invisible lines and columns so in my program it starts from 1
        cout<<"So it starts from the line: "<<x<<"\nand from the column: "<<y<<endl;
    }

    //This function is responsible about the logic of the game
    void Logic(char input)
    {
        //in this switch we are checking the input & the direction of the player
        switch(input)
        {
            case'w':case'W':
                if(arr[x-1][y]==0)
                {
                    x-=1;
                    way+="one step forward\n";
                    Location();
                }
                else
                {
                    cout<<"it's a wrong way\n";
                }
                break;

            case'a':case'A':
                if(arr[x][y-1]==0)
                {
                    y-=1;
                    way+="one step to the left\n";
                    Location();
                }
                else
                {
                    cout<<"it's a wrong way\n";
                }
                break;

            case's':case'S':
                if(arr[x+1][y]==0)
                {
                    x+=1;
                    way+="one stop backward\n";
                    Location();
                }
                else
                {
                    cout<<"it's a wrong way\n";
                }
                break;

            case'd':case'D':
                if(arr[x][y+1]==0)
                {
                    y+=1;
                    way+="one step to the right\n";
                    Location();
                }
                else
                {
                    cout<<"it's a wrong way\n";
                }
                break;

            case'e':case'E':case'q':case'Q':
                notfinished=0;
                break;

            // if none of cases above is achieved, then the program will go to the default input
            default:
                cout<<"You have chosen a wrong input\n"<<"Please enter WASD to move or e,q to quit the game\n";

        }


    }

    // This function is printing out the matrix and also is showing my current place
    void Location()
    {
        arr[x][y]=5;
        if(arr[x-1][y]!=0&&arr[x+1][y]!=0&&arr[x][y-1]!=0&&arr[x][y+1]!=0)
            notfinished=0;
        for(int i=0;i<sizearr+2;i++)
        {
            for(int j=0;j<sizearr+2;j++)
            {
                if(i!=0&&i!=sizearr+1&&j!=0&&j!=sizearr+1)
                {
                    cout<<arr[i][j]<<" ";
                }

            }
            cout<<endl;
        }

    }

    //This function is for printing out the results at the end of the game
    void GameOver()
    {
        cout<<endl<<"==========================GameOver==========================\n";
        cout<<"The way that you have taken is:\n"<<way<<endl;
    }

    //Destructor
    ~Game()
    {
        //Here we are deleting the first array
        for(int i=0; i<sizearr; i++)
            delete[] arr[i];
        //over here we have deleted the second array
        delete[] arr;
        //and here we are pointing our main array to NULL
        arr=NULL;
    }

};

int main()
{
    //for generating a new number each time
    unsigned seed = time(0);
    srand(seed);
    //Size of the matrix and the direction of the player
    int s;
    char var;

    cout<<"Enter the size of the array please: \n";
    cin>>s;

    Game g(s);

    while(notfinished)
    {
        cout<<"Please enter a character:"<<endl;
        cin>>var;
        g.Logic(var);
    }

    g.GameOver();

    return 0;
}
