#include "Board.h"
#include "CandyLand.h"
#include "CandyPlayer.h"
#include<iostream>

using namespace std; 

Board::Board()
{
    resetBoard();
}

void Board::resetBoard()
{
    const int COLOR_COUNT = 3;
    const string COLORS[COLOR_COUNT] = {MAGENTA, GREEN, BLUE};
    Tile newTile;
    string current_color;
    for (int i = 0; i < _BOARD_SIZE - 1; i++)
    {
        current_color = COLORS[i % COLOR_COUNT];
        newTile.color = current_color;
        newTile.tile_type = "regular tile";
        newTile.isCandyStoreTile = false;
        newTile.candyStoreNumber = 0;
        newTile.isHiddenTresureTile = false;
        newTile.hasGummyCandy = false;
        newTile.gummyCandyNumber = 0;
        _tiles[i] = newTile;
        //_tiles[i] = newTile;
    }
    //newTile = {ORANGE, "regular tile"};
    newTile.color = ORANGE;
    newTile.tile_type = "regular tile";
    newTile.isCandyStoreTile = false;
    newTile.candyStoreNumber = 0;
    newTile.isHiddenTresureTile = false;
    newTile.hasGummyCandy = false;
    newTile.gummyCandyNumber = 0;
    
    _tiles[_BOARD_SIZE - 1] = newTile;

    _candy_store_count = 0;
    for (int i = 0; i < _MAX_CANDY_STORE; i++)
    {
        _candy_store_position[i] = -1;
    }

    for(int i=0; i< 2; i++)
    {
        _player_position[i] = 0;
        _previous_position[i] = 0;
    }

    
}

void Board::displayTile(int position)
{
    if (position < 0 || position >= _BOARD_SIZE)
    {
        return;
    }
    Tile target = _tiles[position];
    cout << target.color << " ";

    for(int i=0; i < 2; i++)
    {
        if (position == _player_position[i])
        {
            cout << i+1;
        }
        else
        {
            cout << " ";
        }
    }
    cout << " " << RESET;
}


void Board::displayBoard()
{
    // First horizontal segment
    for (int i = 0; i <= 23; i++)
    {
        displayTile(i);
    }
    cout << endl;
    // First vertical segment
    for (int i = 24; i <= 28; i++)
    {
        for (int j = 0; j < 23; j++)
        {
            cout << "    ";
        }
        displayTile(i);
        cout << endl;
    }
    // Second horizontal segment
    for (int i = 52; i > 28; i--)
    {
        displayTile(i);
    }
    cout << endl;
    // Second vertical segment
    for (int i = 53; i <= 57; i++)
    {
        displayTile(i);
        for (int j = 0; j < 23; j++)
        {
            cout << "   ";
        }
        cout << endl;
    }
    // Third horizontal segment
    for (int i = 58; i < _BOARD_SIZE; i++)
    {
        displayTile(i);
    }
    cout << ORANGE << "Castle" << RESET << endl;
}

bool Board::setPlayerPosition(int playerNumber, int new_position)
{
    _previous_position[0] = _player_position[0];
    _previous_position[1] = _player_position[0];
    if (new_position >= 0 && new_position < _BOARD_SIZE)
    {
        _player_position[playerNumber] = new_position;
        return true;
    }
    return false;
}





/*bool Board::setPlayer2Position(int new2_position)
{
    if (new2_position >= 0 && new2_position < _BOARD_SIZE)
    {
        _player2_position = new2_position;
        return true;
    }
    return false;
}*/




int Board::getBoardSize() const
{
    return _BOARD_SIZE;
}

int Board::getCandyStoreCount() const
{
    return _candy_store_count;
}

int Board::getPlayerPosition(int playerNumber) const
{
    return  _player_position[playerNumber];
}

Tile Board::getTilePosition(int playerIndex)
{
    return _tiles[_player_position[playerIndex]];
}


/*int Board::getPlayer2Position() const
{
    return _player2_position;
}*/

bool Board::drawCard(int playerNumber)
{
    
   // Tile target;
    int cardColorNum = 1 + (rand() % 100);
    int doubleCardNum = (rand() % 3) + 1;
    string drawnCard;
    string drawnCardName;
    bool doubleColor = false;
    int moveAmount = 0;
    //int doubleCardNumber = 0;
    bool isPlayerWinner = false;
    srand(time(0));

     // Set drawnCard and drawnCardName based on card_color_index
    if (cardColorNum >= 1 && cardColorNum <= 25)
    {
        drawnCard = MAGENTA;
        drawnCardName = "Magenta";
    }

    else if (cardColorNum >= 26 && cardColorNum <= 50)
    {
        drawnCard = GREEN;
        drawnCardName = "Green";
    }

    else if (cardColorNum >= 51 && cardColorNum <= 75)
    {
        drawnCard = BLUE;
        drawnCardName = "Blue";
    }

    else if (cardColorNum >= 76 && cardColorNum <= 100)
    {
        if (doubleCardNum == 1)
        {
            drawnCard = MAGENTA;
            drawnCardName = "Magenta";
            doubleColor = true;
        }

        else if (doubleCardNum == 2)
        {
            drawnCard = GREEN;
            drawnCardName = "Green";
            doubleColor = true;
        }

        else if (doubleCardNum == 3)
        {
            drawnCard = BLUE;
            drawnCardName = "Blue";
            doubleColor = true;
        }
    }


    // Check if doubleColor is true or false
    if (doubleColor == false)
    {
        for (int i = getPlayerPosition(playerNumber) + 1; i < 83; i++)
        {
            if (drawnCard == _tiles[i].color) // if the drawn card color is equal to the upcoming tile
            {
                moveAmount = i;
                isPlayerWinner = false;
                break;
            }
            else
            {
                moveAmount = i;
                isPlayerWinner = true; // since there is no more of that color that was drawn left, that means the player is approaching the catsle and has won
            }
        }

         cout << "You drew a " << drawnCardName << " card. Your gamepiece advances to " << drawnCardName << " tile. Here is the updated trail" << endl;
    }

    else if (doubleColor == true)
    {
        for (int i = getPlayerPosition(playerNumber) + 4; i < 83; i++)
        {
            if (drawnCard == _tiles[i].color && drawnCard != ORANGE)
            {
                moveAmount = i;
                isPlayerWinner = false;
                break;
            }
            else
            {
                moveAmount = i;
                isPlayerWinner = true;
            }
        }

        cout << "You drew a double " << drawnCardName << " card. Your gamepiece will advance two " << drawnCardName << " tile. Here's the updated trail:" << endl;
    }

    //cout << "Card Drawn: ";
    //if (!doubleColor)
    //{
    //    cout << drawnCardName;
    //}
    //else
    //{
    //    cout << "Double " << drawnCardName;
   // }
    //cout << endl;

    // Set player position
    setPlayerPosition(playerNumber, moveAmount);


    return isPlayerWinner;
}

int Board::getPrevPosition(int playerNumber)
{
    return _previous_position[playerNumber - 1];
}


bool Board::addCandyStore(int candyStoreCount, int position) // position candystore board
{
    if (_candy_store_count >= _MAX_CANDY_STORE)
    {
        return false;
    }
    _tiles[position].isCandyStoreTile = true;
    _candy_store_position[_candy_store_count] = position;
    _tiles[position].candyStoreNumber = candyStoreCount;
    _candy_store_count++;
    return true;
}

bool Board::isPositionCandyStore(int board_position)
{
    for (int i = 0; i < _candy_store_count; i++)
    {
        if(_candy_store_position[i] == board_position)
        {
            return true;
        }
    }
    
    return false;
}


int Board::candyStoreBoard(int boardPosition)
{
    if(_tiles[boardPosition].isCandyStoreTile == true)
    {
        return _tiles[boardPosition].candyStoreNumber;
    }
    else
    {
        cout << "no candy store here" << endl;
        return 0;
    }


}

void Board::gummyTile(int position, int number_of_skipped_tiles)
{
    if (position < 0 || position >= _BOARD_SIZE)
    {
        return;
    }
    _tiles[position].hasGummyCandy = true;
    _tiles[position].gummyCandyNumber = number_of_skipped_tiles;
}

bool Board::movePlayer(int playerNumber, int tile_to_move_forward, CandyPlayer &playerMoving, CandyPlayer &checking)
{
    int new_position = tile_to_move_forward + _player_position[playerNumber];
    if(new_position < 0 )
    {
        return false; // returns false when it cannot move anymore 
    }
    if(tile_to_move_forward >= _BOARD_SIZE - 1) // check to see if this works -> this checks if the tile = castle then it will set the position to the castle itself 
    {
        new_position = _BOARD_SIZE - 1; 

    }

    _player_position[playerNumber] = new_position;

    
    return true;
}



int Board::nextTile(int location, string color) // this function checks for the next color position when moving it 
{
    for(int i=location; i < _BOARD_SIZE; i++)
    {
        if(_tiles[i].color == color)
        {
            return i;
        }
    }
    return 0;


}

void Board::isthishiddenTreasure(int boardPosition)
{
    _tiles[boardPosition].isHiddenTresureTile = true;

}

vector<CandyPlayer> Board::calamities(CandyPlayer playerMoving, CandyPlayer otherPlayer)
{

    srand(time(0)); 
    int isCalamity = rand() % 100;

    if (isCalamity < 40)
    {
        int randomCalamity = rand() % 100;

        if (randomCalamity < 30) // Candy Bandits
        {
            int currentGoldAmount, newGoldAmount;
            int randomGoldBandit = (rand() % 9) + 1;
            cout << "Oh my! The Crazy Candy Bandits have swiped your gold coin! So sorry pookie bear!" << endl;
            currentGoldAmount = playerMoving.getGold();
            newGoldAmount = currentGoldAmount - randomGoldBandit;
            playerMoving.setGold(newGoldAmount);
            cout << "your new gold amount: " << newGoldAmount << endl; 

        }
        else if (randomCalamity > 30 && randomCalamity < 65) // Lollipop Labyrinth
        {
            cout << "Oh my pookie, you got lost in the lollypop labyrinth!" << endl;
            cout <<  "You lot a turn trying to escape, but if you play a game of rock paper scissors and win, you might just be able to get your turn back!" << endl;
            bool won = playerMoving.playRockPaperScissors();
            cout << won << endl; 
           
            
            if (won == true)
            {
                cout << "YAY you survived and made it out of the Labyrinth and didn't lose a turn!" << endl;
            }
            else 
            {
                playerMoving.setTurnSkipAmount(1);
                //players[playerArrayIndex].isPlayerEligibleForTurn = false;
                cout << "DANG sorry pookie, you have lost a turn because you couldn't escape!" << endl;
            }

        }
        else if (randomCalamity > 65 && randomCalamity < 80) // Candy Avalanche
        {
            int randomCandyAvalanche = (rand() % 5) + 5;
            cout << "Watch out! A candy avalanche has struck! You have lost " << randomCandyAvalanche << " gold coins! You must lose a turn to recover!" << endl;
            cout << "BUT you can save yourself and recover your turn and your gold by winning a game of Rock Paper Scissors!" << endl;
            if (playerMoving.playRockPaperScissors() == true)
            {
                cout << "PHEW! You sucessfully recovered and didn't lose a turn or gold!" << endl;
            }
            else
            {
                int currentGoldAmount, newGoldAmount;
                currentGoldAmount = playerMoving.getGold();
                newGoldAmount = currentGoldAmount - randomCandyAvalanche;
                playerMoving.setGold(newGoldAmount);
                playerMoving.setTurnSkipAmount(1);
                cout << newGoldAmount << endl; 

            
                cout << "You have lost a turn and " << randomCandyAvalanche << " gold coins!" << endl;
            }
            // if you win, don't lose turn and gold
            // if you lose, increment skip count and lose gold
        }
        else // Sticky Taffy
        {
            cout << "Oh No! You just got stuck in stick taffy so you will miss a turn, if you have a magical candy in your inventory, you can break free!" << endl;
            cout << "Checking your inventory now" << endl; 
            // for debug -> has to be frosty fizz, crimson crystal or mystic marshmallow 
            //playerMoving.printInventory();
            if( playerMoving.checkInventoryForMagical() == true)
            {
                cout << "You got saved! You had a magical candy in your inventory you don't have to miss a turn" << endl;  // if there is a magical candy output this 

            }
            else
            {
                cout << "Sorry! you don't have a candy to save you! Your turn will be skipped" << endl;
                playerMoving.setTurnSkipAmount(1);  
            // if no magical candy in inventory, increment skip count

            }
            
           
        }
    }
    vector<CandyPlayer> bothPlayers = {playerMoving, otherPlayer};
    return bothPlayers;
}

vector<CandyPlayer> Board::specialTiles(CandyPlayer movingPlayer, CandyPlayer otherPlayer,int playerNumber)
{
    // if it returns 1 it draws card again, but if it returns 0 that turn is over 
    int typeOfTile = rand()%4+1;
    if(typeOfTile == 1) // shortcut tile 
    {
        int position = getPlayerPosition(playerNumber -1);
        // Handle shortcut logic
        cout << "You landed on a shortcut tile" <<endl;
        if (position + 4 >= _BOARD_SIZE)
        {
            // If the player is less than 4 tiles from the castle, move to the castle
            setPlayerPosition(playerNumber-1, _BOARD_SIZE - 1);
        }
        else
        {
            setPlayerPosition(playerNumber-1, (position + 4)); // getPlayerPosition(playerNumber-1)
        }
        return {movingPlayer,otherPlayer};
        

    }

    else if(typeOfTile ==2) // gum drop forest 
    {//gumdrop forest
        cout << "You landed in the gumdrop forest" << endl;
         if(getPlayerPosition(playerNumber-1) - 4 <= 0){

                //removeLastPosotion;
                setPlayerPosition(playerNumber-1,0);
                
            } 
            else
            {
                setPlayerPosition(playerNumber-1,getPrevPosition(playerNumber)); // this stores the prev position in an arry ana d then will get that 
                
                setPlayerPosition(playerNumber-1,getPlayerPosition(playerNumber-1));
            }
           
            int randomGold = rand() % 6 + + 5;
           
            if(movingPlayer.getGold() - randomGold <= 0)
            {
                movingPlayer.setGold(0);
            } 
            else
            {
                movingPlayer.setGold(movingPlayer.getGold() - randomGold);
            }
            return {movingPlayer,otherPlayer};
        //change player position to 4 steps back
            //if the player is less than 4 tiles from the start, taken back to start
        //remove a random number between 5 and 10 from their gold
   
    }
    else if(typeOfTile == 3) // icecream tile 
    {//ice cream tile
     
        cout << "You landed on an ice cream stop. You get an extra card draw" << endl;
       return {};

    }
    else if(typeOfTile == 4) // gingerbread tile 
    {//gingerbread
         //take the player back to their previous position and remove an immunit candy from the player's inventory
            cout << "You landed at the Gingerbread House. It transported you back to your last position and took an immunity candy!" << endl;
           setPlayerPosition(playerNumber-1,getPrevPosition(playerNumber)); // set it to the previous position 
           displayBoard();
           // this part of the function will remove one of immunity candie 
            if(movingPlayer.removeCandy("Caramel Comet")==0){
                if(movingPlayer.removeCandy("Sparkling Sapphire")==0)
                {
                    movingPlayer.removeCandy("Bubblegum Blast");
                    
                }
            }
          
           
            return {movingPlayer,otherPlayer};
    } 

    return {movingPlayer,otherPlayer};
     
} 


//void Board::showCandyStores()
//{
//    for (int i=0; i< _MAX_CANDY_STORES; i++)
//    {
//        _candy_stores[i].printCandy();
//    }
//}



/*void Board::tileEffects(int, int) // player position, player2position
{
    // this function will take care of all tile effects 
    

}
void Board::sametimeconstraints(int, int) //  player position, player2position
{
    // this functions will take care of everything that happens when a player lands on a time at the same time 

}
void Board::hiddenTreasure(int boardPosition) //player position, player2position
{

    // this function will take care of all functions that happen when there is a treasure on a certain tile

}
void Board::calamities(int, int) //  player position, player2position
{
    // this function will take care of all tiles with calamitites on them 

}*/

/*vector<CandyStore> Board::addACandyStore(CandyStore)
{
    // code for adding a candy store to the board 
    return _candyStores;


}*/
/*vector<CandyStore> Board::getCandyStore() const
{
    return _candyStores;

}
void Board::setCandyStore(vector<CandyStore> candyStores)
{
    _candyStores = candyStores;

   
}*/
