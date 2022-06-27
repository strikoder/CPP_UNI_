#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector <int> vect;
    int value;

    cout << "Welcome to our insertion sort program, please enter any value to add to the array or -1 to exit\n";
    cin>>value;

    while(value!=-1);
    {
        vect.push_back(value);
        cout<<"please enter any value to add to the array or -1 to exit\n";
        cin>>value;
    }


    return 0;
}
