#include <bits/stdc++.h>
using namespace std;

/*
 █████  ██████  ██████  ██ ████████ ██  ██████  ███    ██  █████  ██          ██       █████  ██████
██   ██ ██   ██ ██   ██ ██    ██    ██ ██    ██ ████   ██ ██   ██ ██          ██      ██   ██ ██   ██
███████ ██   ██ ██   ██ ██    ██    ██ ██    ██ ██ ██  ██ ███████ ██          ██      ███████ ██████
██   ██ ██   ██ ██   ██ ██    ██    ██ ██    ██ ██  ██ ██ ██   ██ ██          ██      ██   ██ ██   ██
██   ██ ██████  ██████  ██    ██    ██  ██████  ██   ████ ██   ██ ███████     ███████ ██   ██ ██████
*/

void tournament(int n)
{
    // X: the number of the players
    // mid: the middle
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
            // First one
            if(i==0)
            {
                a[i]=1;
            }
            // Middle of the array
            else if(i==mid)
            {
                a[mid]=2;
            }
            // To use my algorithm, i need to fill out the third element
            else if(i==2)
            {
                a[i]=ceil((mid/2))+1;
            }
            // filling out the position of the elements that the second element of the pair is doubled by 2 from the first element
            else if(a[i-3]%2==0&&(a[i-3]/a[i-4])%2==0&&i>5)
            {
                a[i]=a[i-4]+1;
            }
            // filling out the other elements
            else if((a[i-1]/a[i-2])%2==0&&i+2<x)
            {
                a[i]=a[i-1]+1-(a[i-3]-a[i-4]);
            }
        }
    }

    // Printing output
    for(int i=0;i<x;i++)
    {
        cout<<a[i]<<" ";
    }

}

int main()
{
    int n;

    cout<<"Enter n please: "<<endl;

    cin>>n;

    tournament(n);

    return 0;
}
