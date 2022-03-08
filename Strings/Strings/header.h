#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include<bits/stdc++.h>
using namespace std;

class Strings
{
private:
    vector <string> vect;

public:
    void enterString(string value);
    void displayString();
    void deleteString(string del);
    void reArrangeString(int firstPara, int seconPara);
    void searchWordInString(string searched);
};

void menu();



#endif // HEADER_H_INCLUDED
