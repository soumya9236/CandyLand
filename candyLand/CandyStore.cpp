#include <iostream> 
#include "CandyStore.h"
#include "Board.h"
#include "CandyLand.h"
#include "CandyPlayer.h"

using namespace std; 


CandyStore::CandyStore()
{
    _storeName = "";
    //_tileNumber = 0; 
    _storeStock = 0; 

     

    for(int i= 0; i <3; i++)
    {
        Candy storeCandy;
        storeCandy.candyName = "";
        storeCandy.description = "";
        storeCandy.effect_type = "";
        storeCandy.effect_value = 0; 
        storeCandy.candy_type = "";
        storeCandy.price = 0;
        _storeInventory[i] = storeCandy;
    }
   

}

CandyStore::CandyStore(string storeName)
{
   _storeName = storeName;
   _storeStock = 0;
    for(int i= 0; i <3; i++)
    {
        Candy storeCandy;
        storeCandy.candyName = "";
        storeCandy.description = "";
        storeCandy.effect_type = "";
        storeCandy.effect_value = 0; 
        storeCandy.candy_type = "";
        storeCandy.price = 0;
        _storeInventory[i] = storeCandy;
    }

}


CandyStore::CandyStore(string storeName, int tileNumber, int storeStock, Candy storeInventory[])
{
     _storeName = storeName;
    // _tileNumber = tileNumber; 
     _storeStock = storeStock; 
    if(_storeStock < STORE_CANDY_NUM)
    {
        for(int i = 0; i< _storeStock; i++)
        {
            _storeInventory[i] = storeInventory[i];
        }

    }
    else 
    {
        for(int i = 0; i< STORE_CANDY_NUM; i++)
        {   
            _storeInventory[i] = storeInventory[i];
        }

    }
   


} // string store name , int tile number, int storestock, candy array 
/*int CandyStore::getTileNumber() const
{
   return _tileNumber;

}

void CandyStore::setTileNumber(int tileNumber)
{
    _tileNumber = tileNumber; 

}*/

string CandyStore::getStoreName() const
{
    return _storeName;

}
void CandyStore::setStoreName(string storeName)
{
    _storeName = storeName; 


}
int CandyStore::getStoreStock()
{
    return _storeStock; 

}
void CandyStore::setStoreStock(int storeStock)
{
    _storeStock = storeStock; 


}

/*void CandyStore::setStoreInventory(Candy storeInventory[], int storeStock)
{
    if(_storeStock < 3)
    {
        for(int i = 0; i< storeStock; i++)
        {
            _storeInventory[i] = storeInventory[i];
        }

    }
    else 
    {
        for(int i = 0; i< 3; i++)
        {   
            _storeInventory[i] = storeInventory[i];
        }

    }

}*/


/*Candy CandyStore::findCandy(string candy_name)
{
    Candy candyname; 
    // runs through a loop to see if the candy is in the inventory in the store 
    return candyname; 
    

}*/

bool CandyStore::addCandy(Candy storeCandy)
{
    // add the candy to the store using a for loop 
    // check if the store stock is at the max, and if it is say you cannot add more
    // if it is not, then add the candy to the value that the store stock is at 
    if (_storeStock == STORE_CANDY_NUM)
    {
        cout << "Store has maximum candies. Unable to add more!" << endl;
        return false;
    }
    //cout << "HIIII" << storeCandy.candyName << endl;
    _storeInventory[_storeStock] = storeCandy;
    _storeStock++;
    return true;

}
bool CandyStore::removeCandy(string candy_name)
{
    // remove the candy from the store
    // checks if the candy if equal to the candy that the user inputted, and then removes it if it is in the candy inventory 
    // change the value of the store stock and subtract it 
    bool removed = false;
    //cout << " before removal: " << _storeStock << endl;
    for (int i = 0; i < _storeStock; i++)
    {
        if(_storeInventory[i].candyName == candy_name)
        {
            for (int j = i + 1; j < _storeStock; j++)
            {
                //cout << "Copying " << _storeInventory[j].candyName << " into " << _storeInventory[j-1].candyName << endl;
                _storeInventory[j-1] = _storeInventory[j];
            }

            _storeStock--;
            removed = true;
            // For Debug only
            // cout << "Removing " << candy_name << " from index " << h << "New stock " << _candyStock << "Gone " << candyGone << endl;

            break;
        }
    }
    return removed;

}


void CandyStore::printInventory()
{
    // print all the candies in the array using a for loop 
    cout << "The Store Name: " << _storeName << endl;
    cout << "List of candies:" << endl;
    if (_storeStock == 0)
    {
        cout << "There are no candies at this store! " << _storeName << endl;
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        cout << "  Name: " << _storeInventory[i].candyName << endl;
        cout << "  Description: " << _storeInventory[i].description << endl;
        cout << "  Effect: " << _storeInventory[i].effect_type << endl;
        cout << "  Effect Value: " << _storeInventory[i].effect_value << endl;
        cout << "  Candy Type: " << _storeInventory[i].candy_type << endl;
        cout << "  Price: " << _storeInventory[i].price << endl;
    }



}





/*

CandyStore::CandyStore()
{
    _storeName = ""; 
    _storeStock = 0; 

} 

CandyStore:: CandyStore(string storeName, int storeStock)
{
    _storeName = storeName; 
    _storeStock = storeStock; 

}

bool CandyStore:: addCandy(Candy candy)
{
    if (_storeStock == STORE_CANDY_NUM)
    {
        cout << "Store has maximum candies. Unable to add more!" << endl;
        return false;
    }

    _storeInventory[_storeStock] = candy;
    _storeStock++;
    return true;

}
bool CandyStore::removeCandy(string candy_name)
{


    string candy_nameLower = "";
    for(int i = 0; i < candy_name.length(); i++)
    {
        char lower = tolower(candy_name[i]);
        candy_nameLower = candy_nameLower + lower;
    }
    int index = -1;
    for(int i = 0; i < STORE_CANDY_NUM; i++){
        string currentCandy = _storeInventory[i].candyName;
        // Convert the current candy name to lowercase 
        string current_candyLower = "";
        for (int j = 0; j < currentCandy.length(); j++) 
        {
            current_candyLower += tolower(currentCandy[j]);
        }

        if (current_candyLower == candy_nameLower) {
            index = i;
            break;
        }
    }

    if(index == -1)
    {
        return false;
    } 
    else
    {
        for (int i = index; i < STORE_CANDY_NUM - 1; i++) 
        {
            _storeInventory[i] = _storeInventory[i + 1];
        }
        _storeStock --;
        return true;
    }

   

}
void CandyStore::printCandy()
{
    if (_storeStock == 0)
    {
        cout << "No candies are in " << _storeStock << endl;
        return;
    }

    for (int i = 0; i < _storeStock; i++)
    {
        cout << _storeInventory[i].candyName << endl;
    }

}



// find candy 
string candyLower = "";
    for(int i = 0; i < candy_name.length(); i++){
        char lower = tolower(candy_name[i]);
        candyLower = candyLower + lower;
    }
   
    Candy newTemp;
    for(int i = 0; i < _MAX_CANDY_AMOUNT; i++)
    {
        string currentName = _inventory[i].name;
        string currentLower = "";
        for (int j = 0; j < currentName.length(); j++) 
        {
            currentLower += tolower(currentName[j]);
        }
        if (currentLower == candyLower) {
            newTemp = _inventory[i];
            return newTemp;
        }
    }

    return newTemp; 

*/


