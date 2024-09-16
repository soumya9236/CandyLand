#include<iostream>
#include "CandyPlayer.h"

using namespace std; 

/*struct Candy
{
    string candyName;
    string description;
    string effect_type; 
    int effect_value;
    string candy_type; 
    double price;
    
};*/

CandyPlayer::CandyPlayer()
{
    _playerName = "";
    _characterName = "";
    _stamina = 0; 
    _gold = 0.0; 
    _skipAmount = 0;
    Candy blank = {"Empty","", "", 0, "", 0.0}; 
    for(int i = 0; i < _MAX_CANDY_AMOUNT; i++)
    {
        _inventory[i] = blank;  
    }
    _candy_amount = 0; 
    _isRobber = false;


}
CandyPlayer::CandyPlayer(string playerName, string characterName, int stamina, double gold, Candy candy_array[], int CANDY_ARR_SIZE)
{
    
    _playerName = playerName; 
    _characterName = characterName; 
    _stamina = stamina; 
    _gold = gold; 
    Candy blank = {"Empty","", "", 0, "", 0.0}; 
    if(candy_array[0].candyName == "") 
    {
        for(int i = 0; i < CANDY_ARR_SIZE; i++)
        {
            if(candy_array[i].candyName.length() == 0) 
            {
                _inventory[i] = blank; 
            }
        }
        _candy_amount = 0;
        _skipAmount = 0;
        _isRobber = false;
    } 
    else if (CANDY_ARR_SIZE < 4)
    {
        for(int i = 0; i < CANDY_ARR_SIZE; i++)
        {
            _inventory[i] = candy_array[i];
        }

    }
    _candy_amount = 0;
    _skipAmount = 0;
    _isRobber = false;

    for(int i = 0; i < 4; i++)
    {
        if(_inventory[i].candyName != "" && _inventory[i].candyName != "Empty")
        {
            _candy_amount++;

        }
    }


    

}
string CandyPlayer::getplayerName()
{
    return _playerName; 
}

void CandyPlayer::setplayerName(string name)
{
    _playerName = name; 

}
string CandyPlayer::getCharacter()
{
    return _characterName; 
    //cout << "getCharacter" << _characterName; 

}
void CandyPlayer::setCharacter(string character)
{
    _characterName = character; 


}
void CandyPlayer::setCharacterParts(Character character, string playerName)
{
    _playerName = playerName;
    _characterName = character.characterName;
    _stamina = _stamina + character.stamina;
    _gold = _gold + character.gold;

    for(int i = 0; i < character.numberofCandies; i++)
    {
        // load the candy inventory with that character's candies
        _inventory[i] = character.characterCandies[i];

        _candy_amount++;
    }
    // cout << _playerName << endl;
    // cout << _characterName << endl;
    // cout << _stamina << endl;
    // cout << _gold << endl;

}
void CandyPlayer::setStamina(int stamina)
{
    _stamina = stamina; 
    if(stamina <= 0)
    {
        _stamina = 0; 
    }

}
int CandyPlayer::getStamina()
{
    return _stamina; 

}
void CandyPlayer::setGold(double gold)
{
    _gold = gold; 

}
double CandyPlayer::getGold() const
{
    return _gold; 

}

void CandyPlayer::setTurnSkipAmount(int skipAmount)
{
    _skipAmount = skipAmount; 

}

bool CandyPlayer::getRobbersRepel()
{
    return _isRobber;
}
void CandyPlayer::setRobbersRepel(bool isRobber)
{

    isRobber = false;
    _isRobber = isRobber;
}

int CandyPlayer::getplayersCandyAmount()
{
    return _candy_amount; 

}


void CandyPlayer::printInventory()
{
    for(int i =0; i < _candy_amount; i++)
    {
        cout << " [" << _inventory[i].candyName <<  "]"  << endl ; 
    }


}
Candy CandyPlayer::findCandy(string candy_name)
{
    string candyLower = "";
    for(int i = 0; i < candy_name.length(); i++){
        char lower = tolower(candy_name[i]);
        candyLower = candyLower + lower;
    }
   
    Candy newTemp;
    for(int i = 0; i < _MAX_CANDY_AMOUNT; i++)
    {
        string currentName = _inventory[i].candyName;
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


}

bool CandyPlayer:: checkInventoryForMagical()
{
    for(int i = 0; i < _candy_amount; i++)
    {
        if(_inventory[i].candy_type == "magical") 
        {
            return true; 
        }
        else
        {
            return false; 

        }

    }
    return false;  
}
bool CandyPlayer::addCandy(Candy candy)
{
    if(_candy_amount < _MAX_CANDY_AMOUNT) {
        for(int i= 0; i < _MAX_CANDY_AMOUNT; i++)
        {
            if(_inventory[i].candyName == "")
            {
                _inventory[i] = candy; 
                _candy_amount++; 
                return true;
            }
        } 
    }
   return false; 

}
void CandyPlayer::replaceCandy (string old, Candy newReplacement)
{
    for(int i = 0; i < _candy_amount; i++)
    {
    
        if(_inventory[i].candyName == old)
        {
           
            _inventory[i] = newReplacement;
        }
    }


}
bool CandyPlayer::removeCandy(string candy_name)
{
    string candy_nameLower = "";
    for(int i = 0; i < candy_name.length(); i++)
    {
        char lower = tolower(candy_name[i]);
        candy_nameLower = candy_nameLower + lower;
    }
    int index = -1;
    for(int i = 0; i < _MAX_CANDY_AMOUNT; i++){
        string currentCandy = _inventory[i].candyName;
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
        for (int i = index; i < _MAX_CANDY_AMOUNT - 1; i++) 
        {
            _inventory[i] = _inventory[i + 1];
        }
        _candy_amount --;
        return true;
    }


}
void CandyPlayer::printInformation()
{
    cout << "Player Name: " << getplayerName() << endl;
    cout << " Player character: " << _characterName  << endl;
    cout << " Player Stamina: " << getStamina() << endl;
    cout << " Player Gold: " << getGold() << endl;
    cout << " Player Inventory: "<< endl;
    printInventory();

}
bool CandyPlayer::checkTurn()
{
    //cout << getplayerName() << endl; 
    //cout << getStamina() << endl; 
    //cout << _stamina << endl; 
    bool turn = true;
    if(_skipAmount != 0)
    {
        turn = false;
        _skipAmount--;
    }
    //if the stamina is 0, player must skip 2 turns before they can go again
    else if(getStamina() == 0)
    {
        turn = false;
         _skipAmount = 2;
    }

    return turn;
    

}


bool CandyPlayer::playRockPaperScissors()
{
    bool playAgain = true; 
    bool playerWon = false;
    char playerselect;

    while(playAgain == true)
    {
        cout << "Enter r, p, or s" << endl; 
        cin >> playerselect; 
        while(cin.fail() || (playerselect != 'r' && playerselect != 'p' && playerselect != 's'))
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid selection!" << endl;
            cin >> playerselect;
        }

        char computerSelect[3] = {'r', 'p', 's'};

        int randomNum = (rand() % 3);

        switch (playerselect)
        {
            case 'r':
                if(computerSelect[randomNum] == 'r')
                {
                    // tie 
                    cout << "Tie! Play again" << endl; 
                    playAgain = true; 
                    playerWon = false; 

                }

                if(computerSelect[randomNum] == 'p')
                {
                    // computer wins
                    cout << "The computer has won!" << endl;
                    playAgain = false; 
                    playerWon = false; 
                   

                
                }

                if(computerSelect[randomNum] == 's')
                {
                    //player 1 wins
                    
                    cout << "You won!" << endl; 
                    playAgain = false; 
                    playerWon = true; 
                   
                }

                break;

            case 'p':
                if(computerSelect[randomNum] == 'r')
                {
                    // player 1 wins 
                    cout << "You Won!" << endl; 
                    playAgain = false;
                    playerWon = true; 


                }
                if(computerSelect[randomNum] == 'p')
                {
                    //tie
                    cout << "Tie! Play again" << endl; 
                    playAgain = true; 
                    playerWon = false; 

                }
                if(computerSelect[randomNum] == 's')
                {
                    //computer wins 
                   
                    cout << "The computer has won!" << endl; 
                    playAgain = false; 
                    playerWon = false; 
               
                }
            
                break;

            case 's':
                if(computerSelect[randomNum] == 'r')
                {
                    //computer wins 
                    cout << "The computer has won!" << endl; 
                    playAgain = false; 
                    playerWon = false; 
                 

                }
                if(computerSelect[randomNum] == 'p')
                {
                    // player 1 wins
                    cout << "You have won!" << endl;
                    playAgain = false;  
                    playerWon = true; 
            
                }
                if(computerSelect[randomNum] == 's')
                {
                    // tie
                    cout << "Tie! Play again" << endl;
                    playAgain = true; 
                    playerWon = false; 
                }
                break;
            }    
        } 

        return playerWon;   
   
}

void CandyPlayer::inventoryForOutput(ofstream &finalFile)
{
    for(int i = 0; i < _MAX_CANDY_AMOUNT; i++)
    {
        if(_inventory[i].candyName == "")
        {
            finalFile << "[Empty]";

        }
        else
        {
            finalFile << "[" << _inventory[i].candyName << "]";
        }
    
    }
}

