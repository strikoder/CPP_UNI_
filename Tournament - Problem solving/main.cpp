#include <bits/stdc++.h>
using namespace std;

/*
                         _______                                                _
                        |__   __|                                              | |
                           | | ___  _   _ _ __ _ __   __ _ _ __ ___   ___ _ __ | |_
                           | |/ _ \| | | | '__| '_ \ / _` | '_ ` _ \ / _ \ '_ \| __|
                           | | (_) | |_| | |  | | | | (_| | | | | | |  __/ | | | |_
                           |_|\___/ \__,_|_|  |_| |_|\__,_|_| |_| |_|\___|_| |_|\__|



                                                    1

                                             _______|______
                                            |              |
                                            1              2
                                         ___|___        ___|___
                                        |       |      |       |
                                        1       3      2       4


*/

void tournament(int n)
{
    // X: the number of the players
    // C: is assigned to middle value+1 to initialize the second value of each pair
    int x,c,mid;

    x=pow(2,n);
    c=(x/2)+1;
    mid=x/2;

    int *a=new int[x];

    for(int i=0;i<x;i++)
    {
        // Calculating the second element of each pair of the tournament
        if(i%2!=0)
        {
            a[i]=c;
            c++;
        }
        // Calculating the first element
        else
        {
            // First element
            if(i==0)
            {
                a[i]=1;
            }
            // The middle element
            else if(i==mid)
            {
                a[mid]=2;
            }
            // To use my algorithm, i need to fill out the third element to move next
            else if(i==2)
            {
                a[i]=ceil((mid/2))+1;
            }
            // calculating the elements where the first element is the half of the second element in the same pair
            else if(a[i-3]%2==0&&(a[i-3]/a[i-4])%2==0&&i>5)
            {
                a[i]=a[i-4]+1;
            }
            // Calculating the other elements
            else if((a[i-1]/a[i-2])%2==0&&i+2<x)
            {
                a[i]=a[i-1]+1-(a[i-3]-a[i-4]);
            }
        }
    }

    for(int i=0;i<x;i++)
    {
        cout<<a[i]<<" ";
    }

}

int main()
{
    int n;

    cout<<"Enter the number of the competitions please: "<<endl;

    cin>>n;

    tournament(n);

    return 0;
}
