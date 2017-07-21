#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include "TheDepths.hpp"
using namespace std;
void printStart()
{
    cout<<"   THE DEPTHS   "<<endl;
    cout<<"^^^^^^^^^^^^^^^^"<<endl;
}
void printDifficulty()
{
    cout<<"Enter Difficulty"<<endl;
    cout<<"1. EASY"<<endl;
    cout<<"2. MEDIUM"<<endl;
    cout<<"3. HARD"<<endl;
}
int main()
{
    Dungeon td;
    int input = 0;
    printStart();
    printDifficulty();
    cin>>input;
    while(input != 0)
    {
        if(input == 1)
        {
            td.buildLevelOne();
            break;
        }
        else if(input == 2)
        {
            td.buildLevelTwo();
            break;
        }
        else if(input == 3)
        {
            td.buildLevelThree();
            break;
        }
        else
        {
            cout<<"Try Again"<<endl;
            printDifficulty();
            cin>>input;
        }
    }
    td.beginDungeon();
    td.printUserAbilities();
    string action = "b";
    string y = "y";
    string a = "a";
    string w = "w";
    string s = "s";
    string d = "d";
    string i = "i";
    string q = "q";
    while(action != "y")
    {
        cin>>action;
        if(action == w)
        {
            td.moveUp();
        }
        else if(action == a)
        {
            td.moveLeft();
        }
        else if(action == s)
        {
            td.moveDown();
        }
        else if(action == d)
        {
            td.moveRight();
        }
        else if(action == i)
        {
            td.printInventory();
        }
        else if(action == q)
        {
            td.searchArea();
        }
        else if(action == y)
        {
            cout<<"Exiting"<<endl;
            break;
        }
        else
        {
            cout<<"Incorrect input"<<endl;

        }
        td.printMap();
        td.printUserAbilities();
    }

}
