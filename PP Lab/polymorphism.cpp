// Created by harman on 4/11/25.
//polymorphism

#include <iostream>
using namespace std;

class soccor
{
public:
    void player(string name)
    {
        cout<<"This is the name of the player"<<endl;
    }
    void player(int goals)
    {
        cout<<"This is the number of goals of the player"<<endl;
    }
    void player(double h)
    {
        cout<<"This might be the height of the player"<<endl;
    }
};

int main()
{
    soccor son;
    son.player("huingminson");
    son.player(198);
    son.player(7.5);
}
