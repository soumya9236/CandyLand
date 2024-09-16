// this class will be used to set up the game and load characters, candies, ask for the number of players, and let the users choose the players they want 
#ifndef CANDYLAND_H
#define CANDYLAND_H

#include <iostream>
#include <vector> 
#include "Board.h"
#include "CandyStore.h"
#include "CandyPlayer.h"


using namespace std; 

/*struct Tile
{
    string color;
    string tile_type;
};*/




/*struct Candy
{
    string candyName;
    string description;
    string effect_type; 
    int effect_value;
    string candy_type; 
    double price;
        
};*/




/*struct Riddles
{
    string question; 
    string answer; 
};*/


class CandyLand
{
    public: 

        //loadCharacters();
        CandyLand(); 
        // void setupGame(); // set up board and tiles 
        //void setupBoard(Board board); 
        void addCandyStores(); 
        string choosePlayer1(string, vector<Character>& characters, CandyPlayer& playerOne); 
        string choosePlayer2(string, vector<Character>& characters, CandyPlayer& playerTwo); 
        vector<Candy> getLoadedCandies();
        void setLoadedCandies(vector<Candy>); 
        vector<Character> getLoadedCharacters(); 
        void setLoadedCharacters(vector<Character>); 
        vector<Riddles> getLoadedRiddles();
        void setLoadedRiddles(vector<Riddles>); 
        int getNumberOfPlayers(); 
        void setNumberOfPlayers(int); 
        //void setCards(string arr[]); 
        //string getCard(); 
        //void setCard(string); 
        string characterChoice(); 
        vector<Candy> loadCandies(string);// vector<Candy>); 
        vector<Character> loadCharacters(string);// vector<Character>); 
        vector<Riddles> loadRiddles(string);// vector<Riddles>); 
        void updateInfo(vector <Character>& characters, vector <Candy>& candies);
        void printCharacters(vector <Character> characters); 
        void printCharactersDetails(vector <Character> characters);
        Character CharacterFromName(string characterName, vector<Character>& characters); 
        Candy CandyFromName(string candyName, vector <Candy> candies); 
        void printThreeRandomCandies(vector <Candy> candies); 
        void ApplyCandyToPlayers(Board& board, Candy candyToUse, CandyPlayer& currentPlayer, CandyPlayer& prevPlayer);
        void calamities(int, CandyPlayer players[]); 
       


        // bool drawCards(); -> do this in board instead so that you can easily connect to the tiles





    private: 
        vector<Candy> _loadedCandies;
        vector<Character> _loadedCharacters; 
        vector<Riddles> _loadedRiddles; 
        int _number_of_players; 
        bool _startGame; 
        //int const MAX_NUM_CANDY = 9;


};

#endif



// min -> 1 and max -> 3 
// if you get 1 -> pink, 2 -> green 3-> blue 

// generate a number till it falls in between 1 and 27 or candy store 1 


//getColorTile() -> function in board 

// players start at - 1 and then move forward 

// 1 -> 27: pink 
// 28 -> 53: blue
// 54 -> 82 : green 

// player has a position, candies, stamina, .... attributes in the class! 
/**
 * 
 * struct -> candy, card 
 * class -> player, board, CandyLand 
 * Events, rilles, candy store 
 * set up the game
 *      set up the board -> 83 
 *      place candy stores 
 *      place special tiles 
 *      ... 
 * 
 * load candy from file -> function -> candyland, candystore 
 * visit candystore -> board, candyland 
 *      
 * Load characters from file 
 * choose a character 
 * choose number of players 
 * 
 * visit candystore 
*/