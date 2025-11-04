// Created by harman on 4/11/25.
//learning constructor
#include <iostream>
#include <string>
using namespace std;

class soccor
{
public:
    string name;
    int goals;
    soccor()// default constructor
    {
        cout<<"This is soccor constructor normal one\n";
    }
    soccor(string x,int y)// parameter constructor;
    {
        name = x;
        goals = y;
    }
    soccor(const soccor &son)//copy constructor
    {
        name = son.name;
        goals = son.goals;
    }
};

int main()
{
    soccor son;
    soccor son1("sony",198);
    soccor son2 = son1 ;
    cout<<son1.name<<""<<son1.goals<<endl;
    cout<<son2.name<<""<<son2.goals;

    return 0;
}
