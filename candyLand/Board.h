#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "CandyStore.h"
#include "CandyPlayer.h"


#include <vector>
#define RED "\033[;41m"     /* Red */
#define GREEN "\033[;42m"   /* Green */
#define BLUE "\033[;44m"    /* Blue */
#define MAGENTA "\033[;45m" /* Magenta */
#define CYAN "\033[;46m"    /* Cyan */
#define ORANGE "\033[48;2;230;115;0m"  /* Orange (230,115,0)*/
#define RESET "\033[0m"

using namespace std;

//Name|Description|Effect type|Effect value|Candy type|Price

/*struct Candy
{
    string name;
    string description;
    string effect_type; 
    int effect_value;
    string candy_type; 
    double price;
    
};*/

struct Tile
{
    string color;
    string tile_type;
    bool isCandyStoreTile;
    int candyStoreNumber;  
    bool isHiddenTresureTile; 
    bool hasGummyCandy; 
    int gummyCandyNumber; 


};

struct Riddles
{
    string question; 
    string answer; 
};

struct Card 
{
    string color; 
    bool is_double; 

};


class Board
{
    private:
        const static int _BOARD_SIZE = 83;
        Tile _tiles[_BOARD_SIZE];
        const static int _MAX_CANDY_STORE = 3;
        int _candy_store_position[_MAX_CANDY_STORE];
        int _candy_store_count;
        int _player_position[2]; //2 is the max amount of players
        int _previous_position[2];
        //int _player2_position;
         // vector<CandyStore> _candyStores; 



    public:
        Board();

        void resetBoard(); // complete
        void displayTile(int); // complete
        void displayBoard(); // complete

        bool setPlayerPosition(int, int); // complete
       // bool setPlayer2Position(int); 

        int getBoardSize() const; // complete
        int getCandyStoreCount() const; // complete
        int getPlayerPosition(int) const; // complete
        //tint getPlayer2Position() const; 
        Tile getTilePosition(int playerNumber); // complete // get the tile and all its information using this 
        //Tile getPlayer2PositionTile(int player2Index);

        bool movePlayer(int playerNumber, int tile_to_move_forward, CandyPlayer &playerMoving, CandyPlayer &checking); // complete 
        

        bool drawCard(int playerNumber); // complete
        bool addCandyStore(int, int); // complete
        bool isPositionCandyStore(int);// complete // is this a candy store? call this function 
        int candyStoreBoard(int boardPosition); // complete // this function is used for when the position is a candy store 
        void gummyTile(int tilePosition, int number_of_skipped_tiles); // complete
        int nextTile(int location, string color);  // complete
        void isthishiddenTreasure(int boardPosition); // complete
        vector<CandyPlayer> calamities(CandyPlayer playerMoving, CandyPlayer otherPlayer); //  player position, player2position*/
        void showCandyStores();
        vector<CandyPlayer> specialTiles(CandyPlayer playerOne, CandyPlayer playerTwo, int playerNumber);
        int getPrevPosition(int playerNumber);

    
        /*void tileEffects(int, int); // player position, player2position
        void sametimeconstraints(int, int); //  player position, player2positio
        void calamities(int, int); //  player position, player2position*/

        //vector<CandyStore> addACandyStore(CandyStore); // adds a candy store onto the board 
        //vector<CandyStore> getCandyStore() const; // getter 
        //void setCandyStore(vector<CandyStore>); // setter 
        

       
       
       


    // add functions for tile effects 
    // special tile effects 
    // same time constraints 
    // hidden treasure 
    // calamities 
};

#endif