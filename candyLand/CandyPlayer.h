#ifndef PLAYER_H
#define PLAYER_H
#include<iostream>
#include<string>
#include<fstream>

using namespace std; 

// player class included from homework 7 

struct Candy
{
    string candyName;
    string description;
    string effect_type; 
    int effect_value;
    string candy_type; 
    double price;
    
};

struct Character
{
    string characterName; 
    int stamina; 
    int gold; 
    int numberofCandies; 
    Candy characterCandies[9];
    // add all items that a character has 
    ////character name|stamina|gold|candies

};



class CandyPlayer
{
    public: 
    CandyPlayer();
    CandyPlayer(string playerName, string characterName, int stamina, double gold, Candy candy_array[], int CANDY_ARR_SIZE);
    string getplayerName();
    void setplayerName(string name);
    string getCharacter();
    void setCharacter(string character);
    void setCharacterParts(Character character, string playerName);
    void setStamina(int stamina);
    int getStamina();
    void setGold(double gold);
    double getGold() const;
    void setTurnSkipAmount(int skipAmount);
    void printInventory();
    Candy findCandy(string candy_name);
    bool addCandy(Candy candy);
    void replaceCandy (string old, Candy newReplacement);
    bool removeCandy(string candy_name);
    void printInformation();
    bool checkTurn();
    bool getRobbersRepel();
    void setRobbersRepel(bool isRobberRepel);
    bool playRockPaperScissors();
    int getplayersCandyAmount(); 
    bool checkInventoryForMagical();
    void inventoryForOutput(ofstream &outputfile);

    

    


    private: 
    const static int _MAX_CANDY_AMOUNT = 9; // max number of candies the player can have in their inventory. -> 9 candies 
    string _playerName; 
    string _characterName; 
    int _stamina; // current energy 
    double _gold; // value of the player's current money 
    int _skipAmount; 
    //string _effect; // name of the current effect 
    Candy _inventory[_MAX_CANDY_AMOUNT]; // array to store player's candy 
    int _candy_amount; // amount of initizilized candy structs in the inventory array 
    bool _isRobber; 


    
};

#endif 