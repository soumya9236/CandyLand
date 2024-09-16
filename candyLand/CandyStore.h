#ifndef CANDYSTORE_H
#define CANDYSTORE_H

#include <iostream>
#include "CandyPlayer.h"
#include <vector>
using namespace std; 

// what candy store is doing: displaying the available candies at each store 
// private: array of available candies, 
// accept all available candies in the parameterized constructor 
// make an array of all the available candies -> read from the file 



/*struct Store
{
    string name; 
    int location; 

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

/*struct Store
{
    string name; 
    int location; 

};*/

class CandyStore
{
    public: 
        CandyStore(); 
        CandyStore(string storeName);
        CandyStore(string, int, int, Candy candy[]); // string store name , int tile number, int storestock, candy array 
        //int getTileNumber() const; 
        //void setTileNumber(int); 
        string getStoreName() const; 
        void setStoreName(string); 
        int getStoreStock();
        void setStoreStock(int);
        //void setStoreInventory(Candy candy[], int);// pass in array and store stock 
        // Candy findCandy(string );// string candy name 
        bool addCandy(Candy); // candy storeCandy
        bool removeCandy(string); // candy name
        void printInventory();
        

    private:
        //int _tileNumber; 
        string _storeName; 
        int _storeStock; 
        const static int STORE_CANDY_NUM = 3; // max amount of candies in a store 
        Candy _storeInventory[STORE_CANDY_NUM];    

};

#endif