#include <bits/stdc++.h>
using namespace std;
/*
      ___           ___                       ___           ___                    ___           ___           ___                                ___           ___
     /\  \         /\__\          ___        /\  \         /\  \                  /\  \         /\__\         /\  \                   ___        /\__\         /\  \
    /::\  \       /:/  /         /\  \      /::\  \        \:\  \                 \:\  \       /:/  /        /::\  \                 /\  \      /::|  |        \:\  \
   /:/\ \  \     /:/__/          \:\  \    /:/\:\  \        \:\  \                 \:\  \     /:/__/        /:/\:\  \                \:\  \    /:|:|  |         \:\  \
  _\:\~\ \  \   /::\  \ ___      /::\__\  /::\~\:\  \       /::\  \                /::\  \   /::\  \ ___   /::\~\:\  \               /::\__\  /:/|:|  |__       /::\  \
 /\ \:\ \ \__\ /:/\:\  /\__\  __/:/\/__/ /:/\:\ \:\__\     /:/\:\__\              /:/\:\__\ /:/\:\  /\__\ /:/\:\ \:\__\           __/:/\/__/ /:/ |:| /\__\     /:/\:\__\
 \:\ \:\ \/__/ \/__\:\/:/  / /\/:/  /    \/__\:\ \/__/    /:/  \/__/             /:/  \/__/ \/__\:\/:/  / \:\~\:\ \/__/          /\/:/  /    \/__|:|/:/  /    /:/  \/__/
  \:\ \:\__\        \::/  /  \::/__/          \:\__\     /:/  /                 /:/  /           \::/  /   \:\ \:\__\            \::/__/         |:/:/  /    /:/  /
   \:\/:/  /        /:/  /    \:\__\           \/__/     \/__/                  \/__/            /:/  /     \:\ \/__/             \:\__\         |::/  /     \/__/
    \::/  /        /:/  /      \/__/                                                            /:/  /       \:\__\                \/__/         /:/  /
     \/__/         \/__/                                                                        \/__/         \/__/                              \/__/
*/

class matrix{
private:
    int n;
    int **arr;

public:

    //constructor
    matrix(int number)
    {

        // Calculating the length of the input
        int num = number;
        if (num > 0)
        {
            for (n=0; num>0; n++)
                num/=10;
        }

        // Moving the input from the int into the matrix
        arr = new int*[n];
        for (int i = n-1; i>=0; i--)
        {
            arr[n-i-1]=new int [n];
            arr[0][i] = number%10;
            number/=10;
        }

        //printing out the input of the first line
        for (int i=0; i<n; i++)
            cout << arr[0][i] << " ";
        cout<<endl;

    }

    //Shifting the number and printing out the rest of the matrix inside this function
    //P.S: we are returning the array as a pointer
    int* Shift(int *ar)
    {
        int temp=ar[0];
        for (int i=0; i<n-1; i++)
            ar[i] = ar[i+1];
        ar[n-1]=temp;
        for (int i = 0; i < n; i++)
            cout<<ar[i]<<" ";
        cout<<endl;
        return ar;
    }


    void create_matrix()
    {
        for (int i=1; i<n; i++)
            arr[i] = Shift(arr[i-1]);
    }

    //Destructor
    ~matrix()
    {
        for(int i=0; i<n; i++)
            delete[] arr[i];
        delete[] arr;
        arr=NULL;
    }
};

int main()
{
    int value;
    cout<<"Enter a value as an int please"<<endl;
    cin >> value;

    matrix test(value);
    test.create_matrix();
    return 0;
}
