#include<bits/stdc++.h>
#include"header.h"
using namespace std;

void Strings::enterString(string value)
{
    vect.push_back(value);

}

void Strings::displayString()
{
    for(int i=0;i<vect.size();i++)
    {
        cout<<vect[i]<<endl;
    }
}

void Strings::deleteString(string del)
{
    std::vector<string>::iterator itr = std::find(vect.begin(), vect.end(), del);
    if (itr != vect.end())
        vect.erase(itr);

}

void Strings::reArrangeString(int firstPara, int secondPara)
{
    string temp="";
    temp = vect[firstPara];
    vect[firstPara]=vect[secondPara];
    vect[secondPara]=temp;
}
// I could have used the find function, but I decided to write the search function by myself
void Strings::searchWordInString(string searched)
{
    int numberOfAlphabets=0,start=0;
    string line;
    for(int i=0;i<vect.size();i++)
    {
        line=vect[i];
        for(int j=0;;j++)
        {
            if(line[j]==searched[start])
            {
                numberOfAlphabets++;
                start++;
            }
            // If the line ended with fullstop, then the line is finished
            if(line[j]=='.')
                break;
        }
        if(numberOfAlphabets==searched.length())
        {
            cout<<"The word has been found at the line number: "<<i+1<<endl;
            return;
        }
        start=0;
        numberOfAlphabets=0;
    }
    cout<<"The word hasn't been found\n";
}

void menu()
{
    cout<<"Please enter 1 for a adding a new line\n";
    cout<<"Please enter 2 for displaying the whole lines\n";
    cout<<"Please enter 3 to remove it from the strings\n";
    cout<<"Please enter 4 to reArrange a string\n";
    cout<<"Please enter 5 to search a specefic word in a string\n";
    cout<<"Please enter 0 to exit the program\n";
}
