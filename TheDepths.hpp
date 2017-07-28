#ifndef THEDEPTHS_HPP
#define THEDEPTHS_HPP
//want to create structs  for the adjacent areaNodes and edges.
struct areaNode;
struct areaAdjacencyList
{
    //
    //every room has a pointer to left right up or down
    areaNode *left;
    areaNode *right;
    areaNode *down;
    areaNode *up;
};
struct areaNode
{
    bool isntWall;
    //if monster is in room
    bool isMonster;
    //if player is in room
    bool isPlayer;
    bool isvisited;
    bool weapons;
    bool potions;
    int ID;
    bool haskey;
    bool hasdoor;
    areaAdjacencyList adjlist;
    int row;
    int colm;


};
struct item;
struct player
{
    int health;
    int damage;
    bool isalive;
    bool haskey;
    bool beatenLevel;
    bool leftgame;
    areaNode *currentroom;
    //need location?

};
struct item
{
    bool isKey;
    bool isPotion;
    bool isWeapon;
    bool isEquipped;
    int damage;
    int healingpower;
    std::string name;
    item *next;
    areaNode *itemroom;
};
struct monster
{
    int health;
    int damage;
    std::string message;
    std::string deathmessage;
    areaNode *monsterRoom;

    //need location?
};
class Dungeon
{
    public:
        Dungeon();
        ~Dungeon();
        void buildLevelOne();
        void buildLevelTwo();
        void buildLevelThree();
        void moveUp();
        void moveDown();
        void moveLeft();
        void moveRight();
        void printMap();
        void printInventory();
        void beginDungeon();
        void searchArea();
        void printMenu();
        void printUserAbilities();
        void monsterCreate();
        void changeWeapon();
        areaNode *start;
    private:
        item *head;
        void usePotion();
        void printInventory(int);
        void battle();
        void playersTurn();
        void playerAttack();
        void enemiesTurn();
        void gameEnding();
        void addtoInventory();
        void itemCreate();
        item *weapons;
        item *key;
        item *potion;
        areaNode *l1adjacencyArray;
        areaNode *l2adjacencyArray;
        areaNode *l3adjacencyArray;
        monster *monsters;
        int **l1mapmatrix;
        int **l2mapmatrix;
        int **l3mapmatrix;
        areaNode *wall;
        player* newplayer;
        item *items;
        monster *mon;
        int difficulty;


};
#endif


