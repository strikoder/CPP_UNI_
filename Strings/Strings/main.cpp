#include <bits/stdc++.h>
#include "header.h"
using namespace std;

int main()
{
    Strings str;
    string s;
    int option,a,b;

    do
    {
        menu();
        cin>>option;
        switch(option)
        {

            case 1:
                cout<<"Enter a text and end it with fullstop'.':\n";
                cin.ignore();
                getline(cin, s);
                str.enterString(s);
                break;
            case 2:
                str.displayString();
                break;
            case 3:
                cout<<"Please enter the text that you want to delete:\n";
                cin.ignore();
                getline(cin, s);
                str.deleteString(s);
                //remove
                break;
            case 4:
                cout<<"Please enter the lines numbers that you want to change between:\n";
                cin>>a>>b;
                str.reArrangeString(a-1,b-1);
                //reArrange
                break;
            case 5:
                cout<<"Enter a word to search for and:\n";
                cin.ignore();
                getline(cin, s);
                str.searchWordInString(s);
                //Search a specefic word
                break;
            default:
                continue;
        }

    }while(option !=0);


    return 0;
}
