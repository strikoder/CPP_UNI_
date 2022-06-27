#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector <int>& vect)
{
    int mini;
    for(int i=0 ;i<vect.size()-1;i++ )
    {
        mini=i;
        for(int j=i+1;j<vect.size();j++)
            if(vect[j]<vect[mini])
                mini=j;

        if(mini!=i)
            swap(vect[mini],vect[i]);
    }
}

int main()
{
    int value;
    vector <int> vect;

    cout<<"Welcome to our selection sort program, Please enter any value to enter to array or -1 to exit the loop \n";
    cin>>value;
    while(value!=-1)
    {
        vect.push_back(value);
        cout<<"Please enter any number you want to the array, or -1 if you finished filling the array: \n";
        cin>>value;
    }

    cout<<"The unsorted array looks so stupid and it looks like: \n";

    for(vector<int>::iterator itr = vect.begin() ; itr!=vect.end() ; itr++)
    {
        cout<<*itr<<" ";
    }

    selectionSort(vect);

    cout<<"\nThe beautiful and sexy array looks like: \n";

    for(vector<int>::iterator itr = vect.begin() ; itr!=vect.end() ; itr++)
    {
        cout<<*itr<<" ";
    }

    return 0;
}
