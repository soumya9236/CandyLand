#include <iostream>
#include<fstream> 
#include<sstream> 
#include "Board.h"
#include "CandyStore.h"
#include "CandyPlayer.h"
#include "CandyLand.h"

using namespace std; 

CandyLand::CandyLand()
{
    _number_of_players = 0; 
    _startGame = false; 

}

string CandyLand::choosePlayer1(string player1,vector<Character>& characters, CandyPlayer& playerOne)
{
     
    string selectedCharacter1;
    //string selectedCharacter2;
   
    
    
    cout << "Awesome! Here is a list of characters a player can select from: " << endl; 

    //characters = loadCharacters("Characters.txt", characters);

    for (int i = 0; i < characters.size(); i++)
    {
       cout << "--------------------------------------------------------------------------------------------------" << endl;
       cout << "Name: " << characters[i].characterName << endl << "Stamina: " << characters[i].stamina << endl << "Gold: " << characters[i].gold << endl << "Candies: " << endl; 
       // print 3 candies and then on the next line print the next three then on the next line print the last three candies 
       for (int j = 0; j < 3; j++)
       {
          cout << "[" << characters[i].characterCandies[j].candyName << "]";
       }
       cout << endl;
       for (int j = 3; j < 6; j++)
       {
          cout << "[" << characters[i].characterCandies[j].candyName << "]";
       }
       cout << endl;
       for (int j = 6; j < 9; j++)
       {
          cout << "[" << characters[i].characterCandies[j].candyName << "]";
       }
       cout << endl;

    }
    cout << "Select a character (please type name exactly as shown on menu and only characters that are in the menu)" << endl; 
    cin >> selectedCharacter1;
    if (selectedCharacter1 != "Toffee_Todd" && selectedCharacter1 != "JellyBean_Jane" && selectedCharacter1 != "Gummy_Gilly" && selectedCharacter1 != "Lollypop_Lilly") 
    {   
        cout << "Invalid input, please retype in the character name exactly" << endl;
        cin.clear(); 
        cin.ignore(10000, '\n'); 
        cin >> selectedCharacter1;
    }


        
    Character character1 = CharacterFromName(selectedCharacter1, characters);
    playerOne.setCharacterParts(character1, player1);
        //cout << "selected character: " << playerOne.getCharacter() << endl; 


    vector<Character> newCharacters; 
    for(int i = 0; i < characters.size(); i++)
    {
      if(characters.at(i).characterName != selectedCharacter1)
      {
         newCharacters.push_back(characters.at(i)); 

      }
    
    }

    characters = newCharacters; 


   return selectedCharacter1; 
}

string CandyLand::choosePlayer2(string player2, vector<Character>& characters, CandyPlayer& playerTwo)
{
    string selectedCharacter2; 
    //CandyPlayer number2player; 
    for (int i = 0; i < characters.size(); i++)
    {
       cout << "--------------------------------------------------------------------------------------------------" << endl;
       cout << "Name: " << characters[i].characterName << endl << "Stamina: " << characters[i].stamina << endl << "Gold: " << characters[i].gold << endl << "Candies: " << endl; 
       // print 3 candies and then on the next line print the next three then on the next line print the last three candies 
       for (int j = 0; j < 3; j++)
       {
          cout << "[" << characters[i].characterCandies[j].candyName << "]";
       }
       cout << endl;
       for (int j = 3; j < 6; j++)
       {
          cout << "[" << characters[i].characterCandies[j].candyName << "]";
       }
       cout << endl;
       for (int j = 6; j < 9; j++)
       {
          cout << "[" << characters[i].characterCandies[j].candyName << "]";
       }
       cout << endl;

    }
    cout << "Select a character (please type name exactly as shown on menu, and only characters that are in the menu)" << endl; 
    cin >> selectedCharacter2;
    // THIS IS NOT WORKING BRUH 
    if (selectedCharacter2 != "Toffee_Todd" && selectedCharacter2 != "JellyBean_Jane" && selectedCharacter2 != "Gummy_Gilly" && selectedCharacter2 != "Lollypop_Lilly") 
    {   
        cout << "Invalid input. Please type in the character name properly" << endl;
        cin.clear(); 
        cin.ignore(10000, '\n'); 
        cin >> selectedCharacter2;
    }

    Character character2 = CharacterFromName(selectedCharacter2, characters);
    playerTwo.setCharacterParts(character2, player2);
    // playerTwo.getplayerName();
    // playerTwo.getGold();


    vector<Character> newCharacters2; 
    for(int i = 0; i < characters.size(); i++)
    {
        if(characters.at(i).characterName != selectedCharacter2)
        {
            newCharacters2.push_back(characters.at(i)); 

        }
    
    }

    characters = newCharacters2; 
    return selectedCharacter2; 
    // add visit candy store here 
    
}


vector<Candy> CandyLand::getLoadedCandies()
{
    return _loadedCandies;

}
void CandyLand::setLoadedCandies(vector<Candy> loadedCandies)
{
    _loadedCandies = loadedCandies; 


}
vector<Character> CandyLand::getLoadedCharacters()
{
    return _loadedCharacters; 
}
void CandyLand::setLoadedCharacters(vector<Character> loadedCharacters)
{
    _loadedCharacters = loadedCharacters;
    
}
vector<Riddles> CandyLand::getLoadedRiddles()
{
    return _loadedRiddles;

}
void CandyLand::setLoadedRiddles(vector<Riddles> loadedRiddles)
{
    _loadedRiddles = loadedRiddles; 
    
}

int CandyLand::getNumberOfPlayers()
{
    return _number_of_players;


}
void CandyLand::setNumberOfPlayers(int numberOfPlayers)
{
    _number_of_players = numberOfPlayers;

} 


/*void CandyLand::setCards(string cards[12])
{
    for (int i = 0; i < 12; i++)
    {
        _cards[i] = cards[i]; 
    }
     
} 

string CandyLand::getCard()
{
    return _card; 
} 

void CandyLand::setCard(string card)
{
    _card = card; 

} */


vector<Candy> CandyLand::loadCandies(string fileName)
{
    // load all of the candies from candy.txt 
    // Name|Description|Effect type|Effect value|Candy type|Price
    ifstream file_candies;
    file_candies.open(fileName);
    Candy candy;
    string effect_value; // int
    string price; // double
    string line; 
    getline(file_candies,line); // skips the first line 
    while(getline(file_candies,line))
    {
        stringstream ss(line); 
        getline(ss, candy.candyName, '|');
        getline(ss, candy.description, '|'); 
        getline(ss, candy.effect_type, '|');
        getline(ss, effect_value, '|'); 
        candy.effect_value = stoi(effect_value); 
        getline(ss, candy.candy_type, '|'); 
        getline(ss, price, '|');
        candy.price = stod(price); 

        _loadedCandies.push_back(candy); 



    }
    return _loadedCandies; 

}
vector<Character> CandyLand::loadCharacters(string fileName)//vector<Character> loadedCharacters)
{
    // load all of the characters from characters.txt 
    //character name|stamina|gold|candies

    ifstream file_characters;
    file_characters.open(fileName);
    Character character;
    string stamina;
    string gold;
    //int numberOfCandies; 
    string line;
    while (getline(file_characters, line))
    {
        stringstream ss(line);
        getline(ss, character.characterName, '|');
        if (character.characterName == "") // if the character name is blank then jsut continue
        {
            continue;
        }

        getline(ss, stamina, '|');
        character.stamina = stoi(stamina);
        
        
        getline(ss, gold, '|');
        character.gold = stoi(gold);

        character.numberofCandies = 0;
        while(ss.good()) // this is good function will continue 
        {
            string candies;
            getline(ss, candies, ',');
            character.characterCandies[character.numberofCandies].candyName = candies;
            character.numberofCandies++;
        }

        _loadedCharacters.push_back(character);

    }

    return _loadedCharacters;

}
vector<Riddles> CandyLand::loadRiddles(string fileName)// vector<Riddles> loadedRiddles)
{
    ifstream file_riddles;
    file_riddles.open(fileName);
    Riddles riddles;
    string line;
    while(getline(file_riddles, line))
    {
        stringstream ss(line); 
        getline(ss, riddles.question, '|');
        getline(ss, riddles.answer, '|');
        _loadedRiddles.push_back(riddles); 
    }
    return _loadedRiddles;

}

void CandyLand::updateInfo(vector <Character>& loadedCharacters, vector <Candy>& loadedCandies)
{

  for(int i = 0; i < loadedCharacters.size(); i++)
  {
    for(int j = 0; j < loadedCharacters[i].numberofCandies; j++)
    {
       for(int k = 0; k < loadedCandies.size(); k++)
       {
         if(loadedCandies[k].candyName == loadedCharacters[i].characterCandies[j].candyName)
         {
            // taking candy dectails and setting it equal to the characters 
            loadedCharacters[i].characterCandies[j].description = loadedCandies[k].description; 
            loadedCharacters[i].characterCandies[j].effect_type = loadedCandies[k].effect_type;
            loadedCharacters[i].characterCandies[j].effect_value= loadedCandies[k].effect_value;
            loadedCharacters[i].characterCandies[j].candy_type = loadedCandies[k].candy_type;
            loadedCharacters[i].characterCandies[j].price = loadedCandies[k].price;
           
         }

       }
    }
  }


}
void CandyLand::printCharacters(vector <Character> loadedCharacters)
{
    int length = loadedCharacters.size();
  
    for (int i = 0; i < length; i++)
    {
        cout << "--------------------------------------------------------------------------------------------------" << endl;
        cout << "Name: " << loadedCharacters[i].characterName << endl << " Stamina: " << loadedCharacters[i].stamina << endl << " Gold: " << loadedCharacters[i].gold << endl << " Candies: " << endl;
            
        for (int j = 0; j < loadedCharacters[i].numberofCandies; j++)
        {
            cout << "[" << loadedCharacters[i].characterCandies[j].candyName << "]" << endl;
        }
    }
        

}


void CandyLand::printCharactersDetails(vector <Character> loadedCharacters)
{
    int length = loadedCharacters.size();
  
    for (int i = 0; i < length; i++)
    {
        cout << "--------------------------------------------------------------------------------------------------" << endl;
        cout << "Name: " << loadedCharacters[i].characterName << endl << " Stamina: " << loadedCharacters[i].stamina << endl << " Gold: " << loadedCharacters[i].gold << endl << " Candies: " << endl;
            
        for (int j = 0; j < loadedCharacters[i].numberofCandies; j++)
        {
            cout << "[" << loadedCharacters[i].characterCandies[j].candyName << "," << loadedCharacters[i].characterCandies[j].description << "," << loadedCharacters[i].characterCandies[j].effect_type << "]" << endl;
        }
    }    


}
Character CandyLand::CharacterFromName(string characterName, vector<Character>& characters)
{
    Character newCharacter;
    int size = characters.size();
    for (int i =0; i < size; i++)
    {
       // makes sure that it is the same candy as the one in the vector 
       if(characters[i].characterName == characterName)
       {
          newCharacter = characters[i]; // sets the newCharacter = to the character from the file 
         //break;
       }
       
    }
    //cout << newCharacter.characterName << endl; 
    return newCharacter;
 
}
Candy CandyLand::CandyFromName(string candyName, vector <Candy> candies)
{
    Candy newCandy;
    int size = candies.size();

    for (int i = 0; i < size; i++)
    {
        // ensures the input candyName string is the same as the one in the candies vector
       if(candies[i].candyName == candyName)
       {
         newCandy = candies[i];
         break;
       }
       
    }
    
    return newCandy;

}
void CandyLand::printThreeRandomCandies(vector <Candy> loadedCandies)
{
    int size = loadedCandies.size();

    srand(time(0));

    for (int u = 0; u < 3; u++)
    {
        int randomValue = (rand() % size); // randomly picks 3 candies to display at the store
        //cout << "Random Index " << random_index;
        cout << "--------------------------------------------------------------------------------------------------" << endl;
        cout << "Name: " << loadedCandies[randomValue].candyName << endl << " Description: " << loadedCandies[randomValue].description << endl << " Effect: " << loadedCandies[randomValue].effect_type << endl << " Effect value: " << loadedCandies[randomValue].effect_value << endl;
        cout << "Candy type: " << loadedCandies[randomValue].candy_type << endl << "Price: " << loadedCandies[randomValue].price << endl;
    }

}


void CandyLand::ApplyCandyToPlayers(Board& board, Candy candy, CandyPlayer &movingPlayer, CandyPlayer &otherPlayer)
{
    string candy_type = candy.candy_type;

    if (candy_type == "gummy")
    {
        
        cout << "Which tile do you want to place  " << candy.candyName << "  - gummy candy (hint put it behind your own position)?" << endl; // place the candy 
        string tilePositionstring;
        // This helps with filtering inputs and ensuring that whitespaces are included as the input is being taken
        getline(cin, tilePositionstring, '\n');
        int tilePosition = stoi(tilePositionstring);
        int skipValue = abs(candy.effect_value);
        board.gummyTile(tilePosition - 1, skipValue);
        cout << "You placed gummy candy on tile " << tilePosition << ". When a player lands on a gummy tile, a player will cannot move past the tile for " << skipValue << " move(s)." << endl;


    }
    else if(candy_type == "poison")
    {
        char poisCandychoice;
      
        cout << "Do you want to use " << candy.candyName << " against your opponent (y/n)" << endl;
        cin >> poisCandychoice;
        if ((poisCandychoice != 'y') && (poisCandychoice != 'n')) 
        {   
            cout << "Invalid input" << endl;
            cin.clear(); 
            cin.ignore(10000, '\n'); 
            cin >> poisCandychoice;
        }

        //} while ((poisCandychoice != 'y') && (poisCandychoice != 'n'));

        if(poisCandychoice == 'y')
        {
            // First check if opponent has an immunity candy
            Candy foundCandy;
            // Bubblegum Blast will only protect against Lucky Licorice.
            // Sparkling Sapphire will only protect against Lucky Licorice and Venomous Vortex.
            // Caramel Comet will protect against all the poison candies: Lucky Licorice, Venomous Vortex, and Toxic Taffy.
            bool hasCaramelComet = false;
            bool hasBubbleGumBlast = false;
            bool hasSparklingSapphire = false;
            bool otherPlayerLoseStamina = true;

            foundCandy = otherPlayer.findCandy("Bubblegum Blast");
            if(foundCandy.candyName == "Bubblegum Blast")
            {
                hasBubbleGumBlast = true;
            }

            foundCandy = otherPlayer.findCandy("Sparkling Sapphire");
            if(foundCandy.candyName == "Sparkling Sapphire")
            {
                hasSparklingSapphire = true;
            }

            foundCandy = otherPlayer.findCandy("Caramel Comet");
            if(foundCandy.candyName == "Caramel Comet")
            {
                hasCaramelComet = true;
            }
            // use candy to make sure that we don't overuse the immunity 

    
            if(candy.candyName == "Toxic Taffy")
            {
                // Need Caramet Comet
                if(hasCaramelComet)
                {
                    // remove this immunity candy from prevPlayer and no change to stamina
                    otherPlayer.removeCandy("Caramel Comet");
                    otherPlayerLoseStamina = false;
                    cout << "You have used " << candy.candyName << " candy but your opponent has Caramel Comet candy to protect against your poison candy." << endl;
                }
            }
            else if(candy.candyName == "Venomous Vortex")
            {
                if(hasSparklingSapphire)
                {
                    // remove this immunity candy from prevPlayer and no change to stamina
                    otherPlayer.removeCandy("Sparkling Sapphire");
                    otherPlayerLoseStamina = false;
                    cout << "You have used " << candy.candyName << " candy but your opponent has Sparkling Sapphire candy to protect against your poison candy." << endl;
                }
                else if(hasCaramelComet)
                {
                    // remove this immunity candy from prevPlayer and no change to stamina
                    otherPlayer.removeCandy("Caramel Comet");
                    otherPlayerLoseStamina = false;
                    cout << "You have used " << candy.candyName << " candy but your opponent has Caramel Comet candy to protect against your poison candy." << endl;
                }

            }
            else if(candy.candyName == "Lucky Licorice")
            {
                if(hasBubbleGumBlast)
                {
                    // remove this immunity candy from prevPlayer and no change to stamina
                    otherPlayer.removeCandy("Bubblegum Blast");
                    otherPlayerLoseStamina = false;
                    cout << "You have used " << candy.candyName << " candy but your opponent has Bubblegum Blast candy to protect against your poison candy." << endl;
                }
                else if(hasSparklingSapphire)
                {
                    // remove this immunity candy from prevPlayer and no change to stamina
                    otherPlayer.removeCandy("Sparkling Sapphire");
                    otherPlayerLoseStamina = false;
                    cout << "You have used " << candy.candyName << " candy but your opponent has Sparkling Sapphire candy to protect against your poison candy." << endl;
                }
                else if(hasCaramelComet)
                {
                    // remove this immunity candy from other Player and no change to stamina
                   otherPlayer.removeCandy("Caramel Comet");
                    otherPlayerLoseStamina = false;
                    cout << "You have used " << candy.candyName << " candy but your opponent has Caramel Comet candy to protect against your poison candy." << endl;
                }

            }

            // Only decrease stamina from other player if they don't have any immunity candy
            if(otherPlayerLoseStamina == true)
            {
                int otherPlayerStamina = otherPlayer.getStamina();
                int candyStamina = candy.effect_value;
                // decrease other player stamina. this candy stamina is in negative
                int updatedStamina = otherPlayerStamina + candyStamina;
                if(updatedStamina < 0)
                {
                    updatedStamina = 0;
                }
               otherPlayer.setStamina(updatedStamina);

            }
        }

    }
    else if(candy_type == "magical")
    {
        int playersStamina = movingPlayer.getStamina();
        int candyStamina = candy.effect_value;

        // sets the new stamina value for that player
        movingPlayer.setStamina(playersStamina+candyStamina);

        cout << "You used " << candy.candyName << " candy. This increased stamina by " << candy.effect_value << endl;

    }
    
    else if(candy_type=="immunity")
    {
        cout<<"You cannot use this type of candy yet!"<<endl;
    }

    else
    {
        cout << "Unknown candy type. You missed your turn, type carefully next time!" << endl;
    }

}







/*void CandyLand::calamities(int playerArrayIndex, CandyPlayer players[])
{
    int randomCalamity = rand() % 100;

    if (randomCalamity < 30) // Candy Bandits
    {
        int currentGoldAmount, newGoldAmount;
        int randomGoldBandit = (rand() % 9) + 1;
        cout << "Oh no! Candy Bandits have swiped your gold coins!" << endl;
        currentGoldAmount = players[playerArrayIndex].getGold();
        newGoldAmount = currentGoldAmount - randomGoldBandit;
        players[playerArrayIndex].setGold(newGoldAmount);

    }
    else if (randomCalamity > 30 && randomCalamity < 65) // Lollipop Labyrinth
    {
        cout << "Oh dear! You got lost in the lollipop labyrinth! You have lost a turn trying to escape!" << endl;
        cout << "BUT you can save yourself and recover your turn by winning a game of Rock Paper Scissors!" << endl;
        
        if (players[playerArrayIndex].playRockPaperScissors() == true)
        {
            cout << "PHEW! You made it out of the Labyrinth and didn't lose a turn!" << endl;
        }
        else
        {
            players[playerArrayIndex].SetTurnSkipCount(1);
            //players[playerArrayIndex].isPlayerEligibleForTurn = false;
            cout << "You have lost a turn because you couldn't escape!" << endl;
        }

    }
    else if (randomCalamity > 65 && randomCalamity < 80) // Candy Avalanche
    {
        int randomCandyAvalanche = (rand() % 5) + 5;
        cout << "Watch out! A candy avalanche has struck! You have lost " << randomCandyAvalanche << " gold coins! You must lose a turn to recover!" << endl;
        cout << "BUT you can save yourself and recover your turn and your gold by winning a game of Rock Paper Scissors!" << endl;
        if (players[playerArrayIndex].playRockPaperScissors() == true)
        {
            cout << "PHEW! You sucessfully recovered and didn't lose a turn or gold!" << endl;
        }
        else
        {
            int currentGoldAmount, newGoldAmount;
            currentGoldAmount = players[playerArrayIndex].getGold();
            newGoldAmount = currentGoldAmount - randomCandyAvalanche;
            players[playerArrayIndex].setGold(newGoldAmount);
            players[playerArrayIndex].SetTurnSkipCount(1);
        
            cout << "You have lost a turn and " << randomCandyAvalanche << " gold coins!" << endl;
        }
        // if you win, don't lose turn and gold
        // if you lose, increment skip count and lose gold
    }
    else // Sticky Taffy
    {
        cout << "Oops! You are stuck in a sticky taffy trap! You are stuck for a turn!" << endl;
        cout << "BUT if you have a magical candy in your inventory, you can use it to break free!" << endl;
        // TBD: if magical candy, you can get out of trap
        // if no magical candy in inventory, increment skip count
    }
    

}*/







