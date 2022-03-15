#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int binarySearch(const vector <int>& vect, int value)
{
    // Enhanced algorithm of binary search
    int pointer=(vect.size()/2)+vect.size()%2;
    while(pointer>=0&&pointer<=vect.size())
    {

        if(vect[pointer-1]==value)
            return pointer-1;
        else if(vect[pointer-1]<value)
        {
            pointer+=pointer/2;
        }
        else
        {
            pointer-=pointer/2;
        }
    }
    return -1;

    // Normal algorithm of binary search
    /*
    while(left<=right)
    {
        mid=left+(right-left)/2;
        if(vect[mid]==value)
            return mid;
        else if(vect[mid]<value)
            left=mid+1;
        else
            right=mid-1;
    }
    return -1;
    */

}

int main()
{
    vector <int> vect;
    int value,index;

    cout<<"Welcome to our binary search program, Please enter any value to enter to array or -1 to exit the loop \n";
    cin>>value;

    while(value!=-1)
    {
        vect.push_back(value);
        cout<<"Please enter any number you want to the array, or -1 if you finished filling the array: \n";
        cin>>value;
    }

    sort(vect.begin(),vect.end());

    cout<<"Your lovely matrix is look like this:\n";

    for(vector<int>::iterator itr = vect.begin() ; itr!=vect.end() ; itr++)
    {
        cout<<*itr<<" ";
    }

    cout<<"\nPlease enter the number that you are searching for.\n";
    cin>>value;

    index=binarySearch(vect,value);

    index==-1?cout<<"No match found\n":cout<<"The value is at the "<<index+1<<" Place";

    return 0;
}
