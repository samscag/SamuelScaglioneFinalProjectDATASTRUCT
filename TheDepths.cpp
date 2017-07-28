#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include "TheDepths.hpp"
using namespace std;

Dungeon::Dungeon()
{
    difficulty = 0;
    l1adjacencyArray = new areaNode[19];
    l2adjacencyArray = new areaNode[41];
    l3adjacencyArray = new areaNode[41];
    l1mapmatrix = new int*[5];
    for(int i = 0; i<5; i++)
    {
        l1mapmatrix[i] = new int[8];
    }
    l2mapmatrix = new int*[7];
    for(int i = 0; i<7; i++)
    {
        l2mapmatrix[i] = new int[13];
    }
    l3mapmatrix = new int*[9];
    for(int i = 0; i<9 ;i++)
    {
        l3mapmatrix[i] = new int[15];
    }
    monsters = new monster[10];
    weapons = new item[6];
    key = new item[3];
    potion = new item[10];
    start = nullptr;
    head = nullptr;
    newplayer = new player;
    items = new item;
    mon = new monster;


}
Dungeon::~Dungeon()
{

}
void Dungeon::buildLevelOne()
{
    ifstream file;
    int numrooms = 18;
    string roomdata;
    file.open("l1.txt");
    if(file.good())
    {
        int i = 0;
        while(getline(file, roomdata))
        {
           // cout<<roomdata<<endl;
            stringstream ss(roomdata);
            ss>>l1adjacencyArray[i].isntWall;
            ss>>l1adjacencyArray[i].isMonster;
            ss>>l1adjacencyArray[i].isPlayer;
            ss>>l1adjacencyArray[i].isvisited;
            ss>>l1adjacencyArray[i].weapons;
            ss>>l1adjacencyArray[i].potions;
            ss>>l1adjacencyArray[i].ID;
            ss>>l1adjacencyArray[i].haskey;
            ss>>l1adjacencyArray[i].hasdoor;
            ss>>l1adjacencyArray[i].row;
            ss>>l1adjacencyArray[i].colm;
            //cout<<l1adjacencyArray[i].ID<<endl;
            i++;
        }
    }
    ifstream file2;
    string roomadj;
    file2.open("l1adj.txt");
    if(file2.good())
    {
        int i = 0;
        int room = 0;
        while(file2>>roomadj)
        {
            //cout<<roomadj<<endl;
            string u = "U";
            string d = "D";
            string l = "L";
            string r = "R";
            string one = "1";
            if(roomadj == u)
            {
                l1adjacencyArray[i].adjlist.up = &l1adjacencyArray[room];
               // cout<<"UP "<<l1adjacencyArray[i].ID<<" "<<l1adjacencyArray[i].adjlist.up->ID<<endl;

            }
            if(roomadj == d)
            {
                l1adjacencyArray[i].adjlist.down = &l1adjacencyArray[room];
                //cout<<"DOWN "<<l1adjacencyArray[i].ID<<" "<<l1adjacencyArray[i].adjlist.down->ID<<endl;
            }
            if(roomadj == l)
            {
                l1adjacencyArray[i].adjlist.left = &l1adjacencyArray[room];
             //   cout<<"LEFT "<<l1adjacencyArray[i].ID<<" "<<l1adjacencyArray[i].adjlist.left->ID<<endl;
            }
            if(roomadj == r)
            {
                l1adjacencyArray[i].adjlist.right = &l1adjacencyArray[room];
             //   cout<<"RIGHT "<<l1adjacencyArray[i].ID<<" "<<l1adjacencyArray[i].adjlist.right->ID<<endl;
            }
            room++;
            if(roomadj == one)
            {
                room = 0;
                i++;
            }
        }
    }
    /*
           [6][7][8]
   [K12][4][5]    [9] [10]end
[15]    [3]   [16][11]
[14][13][2][17][18]
        [1]
        start
        */
    difficulty = 1;
}
void Dungeon::buildLevelTwo()
{
    ifstream file;
    int numrooms = 41;
    string roomdata;
    file.open("l2.txt");
    if(file.good())
    {
        int i = 0;
        while(getline(file, roomdata))
        {
            cout<<roomdata<<endl;
            stringstream ss(roomdata);
            ss>>l2adjacencyArray[i].isntWall;
            ss>>l2adjacencyArray[i].isMonster;
            ss>>l2adjacencyArray[i].isPlayer;
            ss>>l2adjacencyArray[i].isvisited;
            ss>>l2adjacencyArray[i].weapons;
            ss>>l2adjacencyArray[i].potions;
            ss>>l2adjacencyArray[i].ID;
            ss>>l2adjacencyArray[i].haskey;
            ss>>l2adjacencyArray[i].hasdoor;
            ss>>l2adjacencyArray[i].row;
            ss>>l2adjacencyArray[i].colm;
            //cout<<l1adjacencyArray[i].ID<<endl;
            i++;
        }
    }

    ifstream file2;
    string roomadj;
    file2.open("l2adj.txt");
    if(file2.good())
    {
        int i = 0;
        int room = 0;
        while(file2>>roomadj)
        {
            //cout<<roomadj<<endl;
            string u = "U";
            string d = "D";
            string l = "L";
            string r = "R";
            string one = "1";
            if(roomadj == u)
            {
                l2adjacencyArray[i].adjlist.up = &l2adjacencyArray[room];
                cout<<"UP "<<l2adjacencyArray[i].ID<<" "<<l2adjacencyArray[i].adjlist.up->ID<<endl;

            }
            if(roomadj == d)
            {
                l2adjacencyArray[i].adjlist.down = &l2adjacencyArray[room];
                cout<<"DOWN "<<l2adjacencyArray[i].ID<<" "<<l2adjacencyArray[i].adjlist.down->ID<<endl;
            }
            if(roomadj == l)
            {
                l2adjacencyArray[i].adjlist.left = &l2adjacencyArray[room];
                cout<<"LEFT "<<l2adjacencyArray[i].ID<<" "<<l2adjacencyArray[i].adjlist.left->ID<<endl;
            }
            if(roomadj == r)
            {
                l2adjacencyArray[i].adjlist.right = &l2adjacencyArray[room];
                cout<<"RIGHT "<<l2adjacencyArray[i].ID<<" "<<l2adjacencyArray[i].adjlist.right->ID<<endl;
            }
            room++;
            if(roomadj == one)
            {
                room = 0;
                i++;
            }
        }
    }
/*
       end  [41][40][39][38][37][36][35]
                    [34]    [33]    [32][31][30]
                [29][28][27][26][25]        [24][23][22]key
            [21]    [20]    [19]    [18]
        [16][15][14][10][9-][8-][7-][6-][5-][4-][3-]
        [17]    [11]        [2 ]
                [13][12]    [1 ]
                          start
                          */
    difficulty = 2;

}
void Dungeon::buildLevelThree()
{
    ifstream file;
    int numrooms = 41;
    string roomdata;
    file.open("l3.txt");
    if(file.good())
    {
        int i = 0;
        while(getline(file, roomdata))
        {
            cout<<roomdata<<endl;
            stringstream ss(roomdata);
            ss>>l3adjacencyArray[i].isntWall;
            ss>>l3adjacencyArray[i].isMonster;
            ss>>l3adjacencyArray[i].isPlayer;
            ss>>l3adjacencyArray[i].isvisited;
            ss>>l3adjacencyArray[i].weapons;
            ss>>l3adjacencyArray[i].potions;
            ss>>l3adjacencyArray[i].ID;
            ss>>l3adjacencyArray[i].haskey;
            ss>>l3adjacencyArray[i].hasdoor;
            ss>>l3adjacencyArray[i].row;
            ss>>l3adjacencyArray[i].colm;
            //cout<<l1adjacencyArray[i].ID<<endl;
            i++;
        }
    }

    ifstream file2;
    string roomadj;
    file2.open("l3adj.txt");
    if(file2.good())
    {
        int i = 0;
        int room = 0;
        while(file2>>roomadj)
        {
            //cout<<roomadj<<endl;
            string u = "U";
            string d = "D";
            string l = "L";
            string r = "R";
            string one = "1";
            if(roomadj == u)
            {
                l3adjacencyArray[i].adjlist.up = &l3adjacencyArray[room];
                cout<<"UP "<<l3adjacencyArray[i].ID<<" "<<l3adjacencyArray[i].adjlist.up->ID<<endl;

            }
            if(roomadj == d)
            {
                l3adjacencyArray[i].adjlist.down = &l3adjacencyArray[room];
                cout<<"DOWN "<<l3adjacencyArray[i].ID<<" "<<l3adjacencyArray[i].adjlist.down->ID<<endl;
            }
            if(roomadj == l)
            {
                l3adjacencyArray[i].adjlist.left = &l3adjacencyArray[room];
                cout<<"LEFT "<<l3adjacencyArray[i].ID<<" "<<l3adjacencyArray[i].adjlist.left->ID<<endl;
            }
            if(roomadj == r)
            {
                l3adjacencyArray[i].adjlist.right = &l3adjacencyArray[room];
                cout<<"RIGHT "<<l3adjacencyArray[i].ID<<" "<<l3adjacencyArray[i].adjlist.right->ID<<endl;
            }
            room++;
            if(roomadj == one)
            {
                room = 0;
                i++;
            }
        }
    }
            /*                         [28]
                                       [27][26]
        end[41][40][36]        [39]        [25]
                   [34][33][32][31][30][29][24][21][22][23]key
                   [35]        [37]            [20]
          start[18][17][19]    [38][9 ][8 ][6 ][7 ]
                   [16]            [4 ]    [5 ]
   [15][14][13][12][11][10]        [3 ]
                                   [2 ][1 ]
                */
    difficulty = 3;
}
void Dungeon::printMap()
{
    //an x will occur where player is
    if(difficulty == 1)
    {
        cout<<"       CAVE MAP      "<<endl;
        cout<<"^^^^^^^^^^^^^^^^^^^^^"<<endl;
        for(int i = 0; i<5; i++)
        {
            for(int j = 0; j<8; j++)
            {
                if(l1mapmatrix[i][j] == 1)
                {
                    cout<<"[ ]";
                }
                else if(l1mapmatrix[i][j] == 2)
                {
                    cout<<"[X]";
                }
                else if(l1mapmatrix[i][j] == 3)
                {
                    cout<<endl;
                }
                else
                {
                    cout<<"   ";
                }
            }
        }
        cout<<"^^^^^^^^^^^^^^^^^^^^^"<<endl;
        /*
           [ ][ ][ ]
     [K][ ][ ]   [ ][ ]end
  [ ]   [ ]   [ ][ ]
  [ ][ ][ ][ ][ ]
        [ ]
        start
        */


    }
    else if(difficulty == 2)
    {
        cout<<"              CAVE MAP             "<<endl;
        cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
        for(int i = 0; i<7; i++)
        {
            for(int j = 0; j<13; j++)
            {
                if(l2mapmatrix[i][j] == 1)
                {
                    cout<<"[ ]";
                }
                else if(l2mapmatrix[i][j] == 2)
                {
                    cout<<"[X]";
                }
                else if(l2mapmatrix[i][j] == 3)
                {
                    cout<<endl;
                }
                else
                {
                    cout<<"   ";
                }
            }
        }
        cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
      /* end[41][40][39][38][37][36][35]
                    [34]    [33]    [32][31][30]
                [29][28][27][26][25]        [24][23][22]key
            [21]    [20]    [19]    [18]
        [16][15][14][10][9-][8-][7-][6-][5-][4-][3-]
        [17]    [11]        [2 ]
                [13][12]    [1 ]
                          start
                          */
    }
    else if(difficulty == 3)
    {
        cout<<"                  CAVE MAP               "<<endl;
        cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
        for(int i = 0; i<9; i++)
        {
            for(int j = 0; j<15; j++)
            {
                if(l3mapmatrix[i][j] == 1)
                {
                    cout<<"[ ]";
                }
                else if(l3mapmatrix[i][j] == 2)
                {
                    cout<<"[X]";
                }
                else if(l3mapmatrix[i][j] == 3)
                {
                    cout<<endl;
                }
                else
                {
                    cout<<"   ";
                }
            }
        }
        cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
        /*                      [ ]
                             [ ][ ]
  end[ ][ ][ ]      [ ]      [ ]
           [ ][ ][ ][ ][ ][ ][ ][ ][ ][K]key
           [ ]      [ ]            [ ]
   start[ ][ ][ ]   [ ][ ][ ][ ][ ]
           [ ]         [ ]   [ ]
  [ ][ ][ ][ ][ ][ ]   [ ]
                       [ ]
        */
    }

}
void Dungeon::moveUp()
{
        if(difficulty == 1)
            {if(newplayer->currentroom->adjlist.up != nullptr)
            {
                l1mapmatrix[newplayer->currentroom->row - 1][newplayer->currentroom->colm - 1] = 1;
                newplayer->currentroom->isPlayer = false;
                newplayer->currentroom = newplayer->currentroom->adjlist.up;
                if(newplayer->currentroom->isMonster == true)
                {
                    battle();
                }
                newplayer->currentroom->isvisited = true;
                newplayer->currentroom->isPlayer = true;
                l1mapmatrix[newplayer->currentroom->row - 1][newplayer->currentroom->colm - 1] = 2;
                //cout<<newplayer->currentroom->ID<<endl;
            }
            else
            {
                cout<<"You have run into a wall."<<endl;
            }
        }
        else if(difficulty == 2)
        {
            if(newplayer->currentroom->adjlist.up != nullptr)
            {
                l2mapmatrix[newplayer->currentroom->row - 1][newplayer->currentroom->colm - 1] = 1;
                newplayer->currentroom->isPlayer = false;
                newplayer->currentroom = newplayer->currentroom->adjlist.up;
                if(newplayer->currentroom->isMonster == true)
                {
                    battle();
                }
                newplayer->currentroom->isvisited = true;
                newplayer->currentroom->isPlayer = true;
                l2mapmatrix[newplayer->currentroom->row - 1][newplayer->currentroom->colm - 1] = 2;
                //cout<<newplayer->currentroom->ID<<endl;
            }
            else
            {
                cout<<"You have run into a wall."<<endl;
            }
        }
        else if(difficulty == 3)
        {
            if(newplayer->currentroom->adjlist.up != nullptr)
            {
                l3mapmatrix[newplayer->currentroom->row - 1][newplayer->currentroom->colm - 1] = 1;
                newplayer->currentroom->isPlayer = false;
                newplayer->currentroom = newplayer->currentroom->adjlist.up;
                if(newplayer->currentroom->isMonster == true)
                {
                    battle();
                }
                newplayer->currentroom->isvisited = true;
                newplayer->currentroom->isPlayer = true;
                l3mapmatrix[newplayer->currentroom->row - 1][newplayer->currentroom->colm - 1] = 2;
                //cout<<newplayer->currentroom->ID<<endl;
            }
            else
            {
                cout<<"You have run into a wall."<<endl;
            }
        }
}
void Dungeon::moveDown()
{   if(difficulty == 1)
    {
        if(newplayer->currentroom->adjlist.down != nullptr)
        {
            l1mapmatrix[newplayer->currentroom->row - 1][newplayer->currentroom->colm - 1] = 1;
            newplayer->currentroom->isPlayer = false;
            newplayer->currentroom = newplayer->currentroom->adjlist.down;
             if(newplayer->currentroom->isMonster == true)
            {
                battle();
            }
            newplayer->currentroom->isvisited = true;
            newplayer->currentroom->isPlayer = true;
            l1mapmatrix[newplayer->currentroom->row - 1][newplayer->currentroom->colm - 1] = 2;

            //cout<<newplayer->currentroom->ID<<endl;
        }
        else
        {
            cout<<"You have run into a wall."<<endl;
        }
    }
    else if(difficulty == 2)
        {
            if(newplayer->currentroom->adjlist.down != nullptr)
            {
                l2mapmatrix[newplayer->currentroom->row - 1][newplayer->currentroom->colm - 1] = 1;
                newplayer->currentroom->isPlayer = false;
                newplayer->currentroom = newplayer->currentroom->adjlist.down;
                if(newplayer->currentroom->isMonster == true)
                {
                    battle();
                }
                newplayer->currentroom->isvisited = true;
                newplayer->currentroom->isPlayer = true;
                l2mapmatrix[newplayer->currentroom->row - 1][newplayer->currentroom->colm - 1] = 2;
                //cout<<newplayer->currentroom->ID<<endl;
            }
            else
            {
                cout<<"You have run into a wall."<<endl;
            }
        }
        else if(difficulty == 3)
        {
            if(newplayer->currentroom->adjlist.down != nullptr)
            {
                l3mapmatrix[newplayer->currentroom->row - 1][newplayer->currentroom->colm - 1] = 1;
                newplayer->currentroom->isPlayer = false;
                newplayer->currentroom = newplayer->currentroom->adjlist.down;
                if(newplayer->currentroom->isMonster == true)
                {
                    battle();
                }
                newplayer->currentroom->isvisited = true;
                newplayer->currentroom->isPlayer = true;
                l3mapmatrix[newplayer->currentroom->row - 1][newplayer->currentroom->colm - 1] = 2;
                //cout<<newplayer->currentroom->ID<<endl;
            }
            else
            {
                cout<<"You have run into a wall."<<endl;
            }
        }
    //if monster in room
}
void Dungeon::moveLeft()
{
    if(difficulty == 1)
    {
        if(newplayer->currentroom->adjlist.left != nullptr)
        {
            l1mapmatrix[newplayer->currentroom->row - 1][newplayer->currentroom->colm - 1] = 1;
            newplayer->currentroom->isPlayer = false;
            newplayer->currentroom = newplayer->currentroom->adjlist.left;
            if(newplayer->currentroom->isMonster == true)
            {
                battle();
            }
            newplayer->currentroom->isvisited = true;
            newplayer->currentroom->isPlayer = true;
            l1mapmatrix[newplayer->currentroom->row - 1][newplayer->currentroom->colm - 1] = 2;
           // cout<<newplayer->currentroom->ID<<endl;
        }
        else
        {
            cout<<"You have run into a wall."<<endl;
        }
    }
    else if(difficulty == 2)
        {
            if(newplayer->currentroom->adjlist.left != nullptr)
            {
                l2mapmatrix[newplayer->currentroom->row - 1][newplayer->currentroom->colm - 1] = 1;
                newplayer->currentroom->isPlayer = false;
                newplayer->currentroom = newplayer->currentroom->adjlist.left;
                if(newplayer->currentroom->isMonster == true)
                {
                    battle();
                }
                newplayer->currentroom->isvisited = true;
                newplayer->currentroom->isPlayer = true;
                l2mapmatrix[newplayer->currentroom->row - 1][newplayer->currentroom->colm - 1] = 2;
                //cout<<newplayer->currentroom->ID<<endl;
            }
            else
            {
                cout<<"You have run into a wall."<<endl;
            }
        }
        else if(difficulty == 3)
        {
            if(newplayer->currentroom->adjlist.left != nullptr)
            {
                l3mapmatrix[newplayer->currentroom->row - 1][newplayer->currentroom->colm - 1] = 1;
                newplayer->currentroom->isPlayer = false;
                newplayer->currentroom = newplayer->currentroom->adjlist.left;
                if(newplayer->currentroom->isMonster == true)
                {
                    battle();
                }
                newplayer->currentroom->isvisited = true;
                newplayer->currentroom->isPlayer = true;
                l3mapmatrix[newplayer->currentroom->row - 1][newplayer->currentroom->colm - 1] = 2;
                //cout<<newplayer->currentroom->ID<<endl;
            }
            else
            {
                cout<<"You have run into a wall."<<endl;
            }
        }
    //if monster in room
}
void Dungeon::moveRight()
{
    if(difficulty == 1){
        if(newplayer->currentroom->adjlist.right != nullptr)
        {

            l1mapmatrix[newplayer->currentroom->row - 1][newplayer->currentroom->colm - 1] = 1;
            newplayer->currentroom->isPlayer = false;
            newplayer->currentroom = newplayer->currentroom->adjlist.right;
            if(newplayer->currentroom->isMonster == true)
            {
                battle();
            }
            newplayer->currentroom->isvisited = true;
            newplayer->currentroom->isPlayer = true;
            l1mapmatrix[newplayer->currentroom->row - 1][newplayer->currentroom->colm - 1] = 2;
            //cout<<newplayer->currentroom->ID<<endl;
        }
        else
        {
            cout<<"You have run into a wall."<<endl;
        }
    }
    else if(difficulty == 2)
        {
            if(newplayer->currentroom->adjlist.right != nullptr)
            {
                l2mapmatrix[newplayer->currentroom->row - 1][newplayer->currentroom->colm - 1] = 1;
                newplayer->currentroom->isPlayer = false;
                newplayer->currentroom = newplayer->currentroom->adjlist.right;
                if(newplayer->currentroom->isMonster == true)
                {
                    battle();
                }
                newplayer->currentroom->isvisited = true;
                newplayer->currentroom->isPlayer = true;
                l2mapmatrix[newplayer->currentroom->row - 1][newplayer->currentroom->colm - 1] = 2;
                //cout<<newplayer->currentroom->ID<<endl;
            }
            else
            {
                cout<<"You have run into a wall."<<endl;
            }
        }
        else if(difficulty == 3)
        {
            if(newplayer->currentroom->adjlist.right != nullptr)
            {
                l3mapmatrix[newplayer->currentroom->row - 1][newplayer->currentroom->colm - 1] = 1;
                newplayer->currentroom->isPlayer = false;
                newplayer->currentroom = newplayer->currentroom->adjlist.right;
                if(newplayer->currentroom->isMonster == true)
                {
                    battle();
                }
                newplayer->currentroom->isvisited = true;
                newplayer->currentroom->isPlayer = true;
                l3mapmatrix[newplayer->currentroom->row - 1][newplayer->currentroom->colm - 1] = 2;
                //cout<<newplayer->currentroom->ID<<endl;
            }
            else
            {
                cout<<"You have run into a wall."<<endl;
            }
        }
}
void Dungeon::printInventory()
{
    cout<<"Health: "<<newplayer->health<<endl;
    cout<<"Damage: "<<newplayer->damage<<endl;
    cout<<"^^^^^^^^^^"<<endl;
    if(head == nullptr)
    {
        cout<<"Inventory is empty"<<endl;
    }
    else
    {
        item *temp = head;
        while(temp != nullptr)
        {
            if(temp->isWeapon == true)
            {
                cout<<"Weapon: "<<temp->name<<" Damage: "<<temp->damage<<endl;
                if(temp->isEquipped == true)
                {
                    cout<<"Equipped"<<endl;
                }
            }
            if(temp->isPotion == true)
            {
                cout<<temp->name<<" Healing Power: "<<temp->healingpower<<endl;
                if(temp->next == nullptr)
                {
                    break;
                }
            }
            if(temp->isKey)
            {
                cout<<temp->name<<endl;
                if(temp->next == nullptr)
                {
                    break;
                }
            }
            temp = temp->next;
        }
        string input;
        cout<<"Use Potion (h)"<<endl;
        cout<<"Change Weapon (n)"<<endl;
        cout<<"Exit screen(e)"<<endl;
        cin.ignore();
        cin>>input;
        if(input == "h")
        {
            usePotion();
        }
        else if(input == "n")
        {
            for(int i = 0; i<5; i++)
            {
                if(weapons[i].isEquipped == true)
                {
                    weapons[i].isEquipped = false;
                }
            }
            changeWeapon();
        }
        else if(input == "e")
        {
            printUserAbilities();
        }
        else
        {
            cout<<"incorrect input"<<endl;
            printInventory();
        }
    }
}
void Dungeon::usePotion()
{
    if(head == nullptr)
    {
        cout<<"No potions available"<<endl;
    }
    else
    {
        bool potionfound = false;
        if(head->isPotion == true)
        {
            cout<<"Potion heals you "<<head->healingpower<<" Health Points"<<endl;
            newplayer->health = newplayer->health + head->healingpower;
            potionfound = true;
            head = head->next;
        }
        else{
            item *temp = head;
            while(temp->next != nullptr)
            {
                if(temp->next->isPotion == true)
                {
                    cout<<"Potion heals you "<<temp->next->healingpower<<" Health points"<<endl;
                    newplayer->health = newplayer->health + temp->next->healingpower;
                    potionfound = true;
                    temp->next = temp->next->next;
                    break;
                }
                temp = temp->next;
            }
            if(temp->next == nullptr && temp->isPotion != true)
            {
                potionfound = false;
            }
        }
        if(potionfound == false)
        {
            cout<<"No potions in inventory"<<endl;
        }
    }
}
void Dungeon::beginDungeon()
{
    if(difficulty == 1)
    {
        cout<<"You wake up beside a burning torch"<<endl;
        cout<<"Your whole body is in pain and you don't remember anything"<<endl;
        cout<<"The low ceiling above you is made of stone"<<endl;
        cout<<"you are in a cave"<<endl;
        cout<<"you have absolutely no possessions"<<endl;
        cout<<"You pick up the torch and see that there is only one way to move"<<endl;
        cout<<"Darkness is all you can see of this next passage"<<endl;
        cout<<"On the ground you see drag marks leading to where you awoke"<<endl;
        cout<<"You hear the sound of chains being dragged in the distance"<<endl;
        cout<<"What will you do to escape the depths?"<<endl;
        start = &l1adjacencyArray[0];
        for(int i = 0; i<5;i++)
        {
            l1mapmatrix[i][7] = 3;
        }
        l1mapmatrix[4][2] = 2;
    }
    else if(difficulty == 2)
    {
        cout<<"You wake up with scratches all over your body."<<endl;
        cout<<"You cannot remember a single thing"<<endl;
        cout<<"You do not know how long you have been here, you only know you are in a cave"<<endl;
        cout<<"You have no idea how deep it is or how to surface"<<endl;
        cout<<"You pick up the torch and see there is only one way to move"<<endl;
        cout<<"You only see one passage up ahead but darkness envelopes the entrance"<<endl;
        cout<<"As you steady walk closer to get a closer look, you hear a snarl"<<endl;
        cout<<"What will you do to escape the depths?"<<endl;
        start = &l2adjacencyArray[0];
        for(int i = 0; i<7; i++)
        {
            l2mapmatrix[i][12] = 3;
        }
        l2mapmatrix[6][5] = 2;
    }
    else
    {
        cout<<"You wake up with scratches all over your body."<<endl;
        cout<<"You cannot remember a single thing"<<endl;
        cout<<"You do not know how long you have been here, you only know you are in a cave"<<endl;
        cout<<"You have no idea how deep it is or how to surface"<<endl;
        cout<<"You pick up the torch and see there is only one way to move"<<endl;
        cout<<"You only see one passage up ahead but darkness envelopes the entrance"<<endl;
        cout<<"As you steady walk closer to get a closer look, you hear a snarl"<<endl;
        cout<<"What will you do to escape the depths?"<<endl;
        start = &l3adjacencyArray[17];
        for(int i = 0; i<9; i++)
        {
            l3mapmatrix[i][14] = 3;
        }
        l3mapmatrix[5][3] = 2;
    }
    monsterCreate();
    itemCreate();
    newplayer->isalive = true;
    newplayer->currentroom = start;
    newplayer->health = 50;
    newplayer->damage = 5;
    newplayer->beatenLevel == false;
    newplayer->haskey = false;
    newplayer->currentroom->isPlayer = true;
    newplayer->currentroom->isvisited = true;
    printMap();
}
void Dungeon::searchArea()
{    if(newplayer->currentroom->hasdoor != true && newplayer->currentroom->haskey != true && newplayer->currentroom->weapons != true && newplayer->currentroom->potions != true)
     {
        if(newplayer->currentroom->adjlist.up == nullptr)
        {
            cout<<"there is no passage up ahead"<<endl;
        }
        else{
            cout<<"through the shadows you see there is a path up"<<endl;
        }
        if(newplayer->currentroom->adjlist.left == nullptr)
        {
            cout<<"the passage to the left has been blocked off by large rocks"<<endl;
        }
        else{
            cout<<"there is a shadowy passage to the left."<<endl;
        }
        if(newplayer->currentroom->adjlist.right == nullptr)
        {
            cout<<"The passage to the right is blocked off by wooden boards"<<endl;
        }
        else{
            cout<<"There is a dimly lit passage to the right"<<endl;
        }
        if(newplayer->currentroom->adjlist.down == nullptr)
        {
            cout<<"There is a rock solid wall blocking your way down the cave"<<endl;
        }
        else{
            cout<<"There is an open passage downward."<<endl;
        }
    }
    if(newplayer->currentroom->potions == true)
    {
        for(int i = 0; i<9; i++){
            if(potion[i].itemroom == newplayer->currentroom)
                {
                    cout<<"You have found a "<<potion[i].name<<endl;
                    addtoInventory();
                    newplayer->currentroom->potions = false;
                }
        }
    }
    else if(newplayer->currentroom->weapons == true)
    {
        for(int i = 0; i<5; i++)
        {
            //cout<<weapons[i].name<<endl;
            if(weapons[i].itemroom == newplayer->currentroom)
            {
                cout<<"You have found a "<<weapons[i].name<<endl;
                addtoInventory();
                newplayer->currentroom->weapons = false;
            }
        }
    }
    else if(newplayer->currentroom->haskey == true)
    {
        for(int i = 0; i<2; i++)
        {
            if(key[i].itemroom == newplayer->currentroom)
            {
                newplayer->haskey = true;
                cout<<"In the room you find a "<<key[i].name<<endl;
                addtoInventory();
                newplayer->currentroom->haskey = false;
            }
        }
    }
    if(newplayer->currentroom->hasdoor == true)
    {
        if(newplayer->haskey == true)
        {
            cout<<"You see a large door that has a key hole just the size of your key"<<endl;
            cout<<"After much effort the large key slides into the lock and turns."<<endl;
            newplayer->beatenLevel = true;
            printUserAbilities();
        }
        else
        {
            cout<<"You cannot open this door"<<endl;
        }
    }
}
void Dungeon::printUserAbilities()
{
    //go up left right and down will only appear if there are according adjacent rooms.
    if(newplayer->beatenLevel == false && newplayer->isalive == true && newplayer->leftgame == false)
    {   if(newplayer->currentroom->adjlist.up != nullptr)
        {
            cout<<"Go Up (w)"<<endl;
        }
        if(newplayer->currentroom->adjlist.left != nullptr)
        {
            cout<<"Go Left (a)"<<endl;
        }
        if(newplayer->currentroom->adjlist.down != nullptr)
        {
            cout<<"Go Down (s)"<<endl;
        }
        if(newplayer->currentroom->adjlist.right != nullptr)
        {
            cout<<"Go Right (d)"<<endl;
        }
        cout<<"View Inventory (i)"<<endl;
        cout<<"Search Area/Interact (q)"<<endl;
        cout<<"Quit (y)"<<endl;
    }
    else if(newplayer->isalive == false && newplayer->leftgame == false)
    {
        newplayer->leftgame = true;
        newplayer->isalive = true;
        cout<<"Enter y to quit"<<endl;
    }
    else if(newplayer->isalive == true && newplayer->beatenLevel == true && newplayer->leftgame == false)
    {
        if(difficulty == 1 && newplayer->leftgame == false)
        {
            string input;
            cout<<"You have beaten the game on easy difficulty!"<<endl;
            cout<<"Enter y to quit"<<endl;
        }
        if(difficulty == 2 && newplayer->leftgame == false)
        {
            string input;
            cout<<"You have beaten the game on medium difficulty!"<<endl;
            cout<<"Enter y to quit"<<endl;
        }
        if(difficulty == 3 && newplayer->leftgame == false)
        {
            string input;
            cout<<"You have beaten the game on the hardest difficulty!"<<endl;
            cout<<"You are finally free from the cave"<<endl;
            cout<<"Enter y to quit"<<endl;
        }
        newplayer->leftgame = true;
        newplayer->beatenLevel = true;
    }

}
void Dungeon::battle()
{
    //occurs when user enters a room with a monster in it
    //while monster health >  0 and player health > 0
        for(int i = 0; i<9; i++)
        {
            if(newplayer->currentroom == monsters[i].monsterRoom)
            {

                if(newplayer->currentroom->isvisited == false)
                {
                    cout<<"You are faced by a "<<monsters[i].message<<endl;
                }
                while(newplayer->health > 0 && monsters[i].health > 0)
                {
                    playersTurn();
                    if(monsters[i].health > 0)
                    {
                        enemiesTurn();
                    }
                }
                if(monsters[i].health <= 0)
                {
                    cout<<monsters[i].deathmessage<<endl;
                }
                else
                {
                    cout<<"You've Died"<<endl;
                    newplayer->isalive = false;
                    printUserAbilities();
                }
            }
        }


}
void Dungeon::playersTurn()
{
    string input;
    cout<<"Your Health: "<<newplayer->health<<endl;
    for(int i = 0; i<9; i++){
        if(newplayer->currentroom == monsters[i].monsterRoom)
        {
            cout<<"Monster's Health: "<<monsters[i].health<<endl;
        }
    }
    cout<<"Attack (v)"<<endl;
    cout<<"Drink Potion (h)"<<endl;
    cout<<"Change Weapon (l)"<<endl;
    cin>>input;
    if(input == "v")
    {
        playerAttack();
    }
    else if(input == "h")
    {
        usePotion();
        playersTurn();
    }
    else if(input == "l")
    {
        for(int i = 0; i<5; i++)
        {
            if(weapons[i].isEquipped == true)
            {
                weapons[i].isEquipped = false;
            }
        }
        changeWeapon();
        playersTurn();
    }
    else
    {
        cout<<"not an option"<<endl;
        playersTurn();
    }

}
void Dungeon::monsterCreate()
{
    int damage = 5;
    int health = 10;
    for(int i = 0; i<9; i++)
    {
        monsters[i].health = health;
        monsters[i].damage = damage;
        health = health +3;
        damage = damage+2;
    }
    //monsters[0].monsterRoom = &l1adjacencyArray[2];
    monsters[0].message = "small cave dweller. It looks skinny and weak, though human-like";
    monsters[0].deathmessage = "the small cave dweller has been killed. You discover it doesn't have eyes but otherwise distinctly human features.";
    monsters[1].message = "medium sized cave dweller. It appears to be injured, though it snarls and attacks you immediately.";
    monsters[1].deathmessage = "the small cave dweller has been killed. You discover it doesn't have eyes but otherwise distinctly human features.";
    monsters[2].message = "small cave dweller welding a wooden plank with nails through it. It's ready to attack";
    monsters[2].deathmessage = "You have killed the small cave dweller";
    monsters[3].message = "fairly large cave dweller. It appears to be injured, but has a powerful strike";
    monsters[3].deathmessage = "The large cave dweller lies in a pool of blood. you have killed it.";
    monsters[4].message = "flying cave monster. It is small in size but has a big bite";
    monsters[4].deathmessage = "The winged monster lies in a pool of blood";
    monsters[5].message = "strong cave monster with a long sharp thorn acting as an arm";
    monsters[5].deathmessage = "The thorned monster lies died";
    monsters[6].message = "large cave monster. With large arms and a club it appears to be ready to attack you.";
    monsters[6].deathmessage = "The large monster lies dead.";
    monsters[7].message = "extremely strong cave monster. It has horns and is ready to attack with its sword";
    monsters[7].deathmessage = "The large monster lays dead. It's nearly twice your size";
    monsters[8].message = "winged cave monster. It has a powerful shout and a club the size of a tree";
    monsters[8].deathmessage = "You have conquered the king of the cave.";

    if(difficulty == 1)
    {
        monsters[0].monsterRoom = &l1adjacencyArray[2];
        monsters[6].monsterRoom = &l1adjacencyArray[9];
        monsters[1].monsterRoom = &l1adjacencyArray[15];
    }
    else if(difficulty == 2)
    {
       //4 8 13 14 22 26 38 41
       monsters[0].monsterRoom = &l2adjacencyArray[4];
       monsters[1].monsterRoom = &l2adjacencyArray[7];
       monsters[2].monsterRoom = &l2adjacencyArray[12];
       monsters[3].monsterRoom = &l2adjacencyArray[13];
       monsters[4].monsterRoom = &l2adjacencyArray[21];
       monsters[5].monsterRoom = &l2adjacencyArray[25];
       monsters[6].monsterRoom = &l2adjacencyArray[37];
       monsters[7].monsterRoom = &l2adjacencyArray[40];
    }
    else if(difficulty == 3)
    {
        //4 8 12 21 25 29 34 37 41
       monsters[0].monsterRoom = &l3adjacencyArray[11];
       monsters[1].monsterRoom = &l3adjacencyArray[33];
       monsters[2].monsterRoom = &l3adjacencyArray[36];
       monsters[3].monsterRoom = &l3adjacencyArray[28];
       monsters[4].monsterRoom = &l3adjacencyArray[24];
       monsters[5].monsterRoom = &l3adjacencyArray[3];
       monsters[6].monsterRoom = &l3adjacencyArray[7];
       monsters[7].monsterRoom = &l3adjacencyArray[20];
       monsters[8].monsterRoom = &l3adjacencyArray[40];
    }
}
void Dungeon::enemiesTurn()
{
        for(int i = 0; i<9; i++){
            if(newplayer->currentroom == monsters[i].monsterRoom)
            {
                int damage = rand() % monsters[i].damage;
                cout<<"the monster hits you for "<<damage<<" damage"<<endl;
                newplayer->health = newplayer->health - damage;
            }
        }
}
void Dungeon::playerAttack()
{
        for(int i = 0; i<9; i++){
            if(newplayer->currentroom == monsters[i].monsterRoom)
            {
                int damage = rand() % newplayer->damage;
                cout<<"You hit the monster with "<<damage<<" damage"<<endl;
                monsters[i].health = monsters[i].health - damage;
            }
        }
}
void Dungeon::changeWeapon()
{
    if(head == nullptr)
    {
        cout<<"You only have your bare fists"<<endl;
    }
    else
    {
        int i = 0;
        item *temp = head;
        while(temp != nullptr)
        {
            if(temp->isWeapon == true)
            {
                i++;
                cout<<"Weapon: "<<temp->name<<" Damage: "<<temp->damage<<endl;
                if(temp->isEquipped == true){
                    cout<<"Equipped"<<endl;
                }

            }
            temp = temp->next;
        }
        if(i == 0)
        {
            cout<<"You only have your bare fists Damage: 5"<<endl;
        }
        else{
        cout<<"Enter name of weapon to switch to"<<endl;
        string input;
        bool weaponfound = false;
        cin.ignore();
        getline(cin, input);
        for(int i = 0; i<5; i++)
        {
            if(input == weapons[i].name)
            {
                cout<<"Switched weapon to "<<weapons[i].name<<endl;
                newplayer->damage = weapons[i].damage;
                weapons[i].isEquipped = true;
                weaponfound = true;
            }
        }
        if(weaponfound == false)
        {
            cout<<"weapon not found"<<endl;
        }

    }
    }

}
void Dungeon::itemCreate()
{
    for(int i =0 ; i<5; i++)
    {
        weapons[i].isEquipped = false;
        weapons[i].isWeapon = true;
    }
    int damage = 10;
    for(int i = 0; i<5; i++)
    {
        weapons[i].damage = damage;
        damage = damage +4;
    }
    weapons[0].name = "Broken Glass Bottle";
    weapons[1].name = "Rusty Iron Dagger";
    weapons[2].name = "Nail Spiked club";
    weapons[3].name = "Iron Longsword";
    weapons[4].name = "Large Greatsword";
    for(int i = 0; i<3; i++)
    {
        potion[i].name = "Small Potion";
        potion[i].isPotion = true;
        potion[i].healingpower = 5;
    }
    for(int i = 3; i<6 ; i++)
    {
        potion[i].name = "Medium Potion";
        potion[i].isPotion = true;
        potion[i].healingpower = 10;
    }
    for(int i = 6; i<9 ; i++)
    {
        potion[i].name = "Large Potion";
        potion[i].isPotion = true;
        potion[i].healingpower = 20;
    }
    for(int i = 0; i<2; i++)
    {
        key[i].isKey = true;
    }
    key[0].name = "Old Rusty Key";
    key[1].name = "Solid Iron Key";
    if(difficulty == 1)
    {
        potion[4].itemroom = &l1adjacencyArray[13];
        potion[8].itemroom = &l1adjacencyArray[6];
        potion[1].itemroom = &l1adjacencyArray[1];
        weapons[0].itemroom = &l1adjacencyArray[0];
        weapons[1].itemroom = &l1adjacencyArray[8];
        weapons[3].itemroom = &l1adjacencyArray[14];
        key[0].itemroom = &l1adjacencyArray[11];
    }
    else if(difficulty == 2)
    {
        // 3 7 10 16 17 27 29 36
        potion[0].itemroom = &l2adjacencyArray[2];
        potion[1].itemroom = &l2adjacencyArray[9];
        potion[2].itemroom = &l2adjacencyArray[16];
        potion[3].itemroom = &l2adjacencyArray[6];
        potion[4].itemroom = &l2adjacencyArray[26];
        potion[5].itemroom = &l2adjacencyArray[35];
        potion[6].itemroom = &l2adjacencyArray[28];
        potion[7].itemroom = &l2adjacencyArray[15];
        //1 12 18 25
        weapons[0].itemroom = &l2adjacencyArray[0];
        weapons[1].itemroom = &l2adjacencyArray[17];
        weapons[3].itemroom = &l2adjacencyArray[11];
        weapons[4].itemroom = &l2adjacencyArray[24];
        key[0].itemroom = &l2adjacencyArray[21];
    }
    else if(difficulty == 3)
    {
        //1 3 10 16 19 26 32 35 39
        potion[0].itemroom = &l3adjacencyArray[2];
        potion[1].itemroom = &l3adjacencyArray[15];
        potion[2].itemroom = &l3adjacencyArray[34];
        potion[3].itemroom = &l3adjacencyArray[9];
        potion[4].itemroom = &l3adjacencyArray[25];
        potion[5].itemroom = &l3adjacencyArray[38];
        potion[6].itemroom = &l3adjacencyArray[18];
        potion[7].itemroom = &l3adjacencyArray[0];
        potion[8].itemroom = &l3adjacencyArray[31];
      //2 5 15 18 28
        weapons[0].itemroom = &l3adjacencyArray[17];
        weapons[1].itemroom = &l3adjacencyArray[4];
        weapons[2].itemroom = &l3adjacencyArray[1];
        weapons[3].itemroom = &l3adjacencyArray[14];
        weapons[4].itemroom = &l3adjacencyArray[27];
        key[1].itemroom = &l3adjacencyArray[22];
    }

}
void Dungeon::addtoInventory()
{
    if(newplayer->currentroom->haskey == true)
    {
        if(head == nullptr)
        {
            for(int i = 0; i<2; i++)
            {
                if(newplayer->currentroom == key[i].itemroom)
                {
                    head = &key[i];
                }
            }
        }
        else
        {
            item* temp = head;
            while(temp->next != nullptr)
            {
                temp = temp->next;
            }
            for(int i = 0; i<2; i++)
            {
                if(newplayer->currentroom == key[i].itemroom)
                {
                    temp->next = &key[i];
                }
            }
        }
    }
    else if(newplayer->currentroom->weapons == true)
    {
        if(head == nullptr)
        {
            for(int i = 0; i<5; i++)
            {
                if(newplayer->currentroom == weapons[i].itemroom)
                {
                    head = &weapons[i];
                }
            }
        }
        else if(head->next == nullptr)
            {
                for(int i = 0; i<5; i++)
                {
                    if(newplayer->currentroom == weapons[i].itemroom)
                    {
                        head->next = &weapons[i];
                    }
                }
            }
        else
        {
            item *temp = head;
            while(temp->next != nullptr)
            {
                temp = temp->next;
            }
            for(int i = 0; i<5; i++)
            {
                if(newplayer->currentroom == weapons[i].itemroom)
                {
                    temp->next = &weapons[i];
                }
            }
        }
    }
    else if(newplayer->currentroom->potions == true)
    {
        if(head == nullptr)
        {
            for(int i = 0; i<9; i++)
            {
                if(newplayer->currentroom == potion[i].itemroom)
                {
                    head = &potion[i];
                }
            }
        }
        else if(head->next == nullptr)
            {
                for(int i = 0; i<9; i++)
                {
                    if(newplayer->currentroom == potion[i].itemroom)
                    {
                        head->next = &potion[i];
                    }

                }
            }
        else
        {
            item *temp = head;
            while(temp->next != nullptr)
            {
                temp = temp->next;
            }
            for(int i = 0; i<9; i++)
            {
                if(newplayer->currentroom == potion[i].itemroom)
                {
                    temp->next = &potion[i];

                }
            }
        }
    }
}
