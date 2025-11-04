// Created by harman on 4/11/25.
//doing inheritence

#include <iostream>
using namespace std;

class player
{
public:
    string name;
    player()
    {
        cout<<"Enter player Name\n";
    }
};
class club
{
public:
    string clubname;
    club()
    {
        cout<<"Enter your club name\n";
    }
};
class country
{
public:
    string countryname;
    country()
    {
        cout<<"Enter your country\n";
    }
};
class playerdata :public player,public club,public country
{
public:
        playerdata()
        {
            cout<<"---Player DATA---";
        }
};

int main()
{
playerdata son;
    return 0;
}