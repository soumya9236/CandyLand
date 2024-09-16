#include "CandyPlayer.h"
#include "Board.h"
#include "CandyLand.h"
#include <iostream>
#include <fstream>
#include<cstdlib> // has the random function (rand())
#include<ctime>
#include<vector>

using namespace std; 

int main()
{
    //cout << "hi1" << endl; 
    CandyLand candyland;
    Board board; 
    // candyland.setupGame();
    //cout << "hi" << endl; 
    srand(time(0));
    //cout << "hi2" << endl; 
    

    //int numberOfPlayers = 2; 
    CandyPlayer playerOne; 
    CandyPlayer playerTwo; 
    //CandyPlayer players[] = {playerOne, playerTwo}; 
    vector <Character> characters = candyland.loadCharacters ("Characters.txt"); //characters); // read characters from the file  
    Character character;
    vector <Candy> candies = candyland.loadCandies("candies.txt");// candies); // read candies and store them into a vector 
    vector <Riddles> riddles = candyland.loadRiddles("Riddles.txt");// riddles);  // read the riddles and store into vectore 
    candyland.updateInfo(characters, candies); 
    board.resetBoard();
    CandyStore candyStores[3] = {CandyStore("CandyStore1"), CandyStore("CandyStore2"), CandyStore("CandyStore3")};
    //cout << "hi2" << endl; 
    //cout << "1" << endl; 
    /* ALL CANDY STORE RELATED THINGS*/ // -> setting this all up 


  
     //cout << "hi3" << endl; 

    // Add candy stores to board and set their locations 

    // For store in first 27 tiles, get a random number between 0-24
    
    int candyStoreLocation = (rand() % 25);// random storelocationn
    candyStoreLocation = board.nextTile(candyStoreLocation, MAGENTA); // checks for the next tile with magenta to place it 
    board.addCandyStore(candyStoreLocation, 0);  // add the first candy Store 
    
    
    
    // For store in 28-54 tiles, get a random number between 27-51, (25%)
    candyStoreLocation = 27 + (rand() % 25); // random store 
    candyStoreLocation = board.nextTile(candyStoreLocation, GREEN); // get the next green tile 
    board.addCandyStore(candyStoreLocation, 1); // add next candy store 
    

    // For store in 55-82 tiles, get a random number between 54-79, 
    candyStoreLocation = 54 + (rand() % 25);
    candyStoreLocation = board.nextTile(candyStoreLocation, BLUE); // get next blue tile 
    board.addCandyStore(candyStoreLocation, 2); // add the next candy store 
     //cout << "hi3" << endl; 
    

    for (int i = 0; i < 3; i++) // adds three hidden treasures 
    {
        int hiddenTreasureLocationIndex;
        hiddenTreasureLocationIndex = rand() % 83;
        board.isthishiddenTreasure(hiddenTreasureLocationIndex);
        
    }

    // this adds all the candies into each store randomly 

    for(int i = 0; i < 3; i++) // three stores 
    {
        for(int j= 0; j< 3; j++) // three candies in each store 
        {
            
            int randomNumber =(rand() % (candies.size() - 1)); // get random candies from the vector
            candyStores[i].addCandy(candies[randomNumber]); // add candies to the candy stores
            //cout << "HI CANDY NAME" << candies[randomNumber].candyName; 
        
            
        }
        
        //candyStores[i].printInventory();
    }

   
 
    // call the function in candy land 
   

    string player1; 
    string player2;
    
    cout << "Welcome to the game of candyland. Please enter the number of participants(numerical values only): " << endl; 
    int number_of_participants; 
    cin >> number_of_participants;
    if (number_of_participants != 2) 
    {   
        cout << "This game only allows two players. Please re-enter the amount of participants (numerical values only): " << endl;
        cin.clear(); 
        cin.ignore(10000, '\n'); 
        cin >> number_of_participants;
    }
   
    cout << "Enter player 1 name" << endl; 
    cin >> player1; 
    string selectedCharacter1 = candyland.choosePlayer1(player1, characters, playerOne); // this calls the function that chooses the player 
    //Character character1 = candyland.CharacterFromName(selectedCharacter1, characters); // this sets the names 
    //cout << character1.characterName << endl; 
    //playerOne.setCharacterParts(character1, player1); 
    playerOne.printInformation();
    char visitStorePlayer1; 


    
    
    cout << "Do you want to visit the candy store? (enter only y or n)" << endl;
    cin >> visitStorePlayer1;
    if((visitStorePlayer1 != 'y') && (visitStorePlayer1 != 'n')) 
    {   
        cout << "Invalid input" << endl;
        cin.clear(); 
        cin.ignore(10000, '\n'); 
        cin >> visitStorePlayer1;
    }

    if(visitStorePlayer1 == 'y')
    {
        string candyName1, substitutecandyName1;
        //double playerGold1 = playerOne.getGold();

        // prints the candies of that store
        candyStores[0].printInventory();
        cout << "Which candy would you like to buy? ";
        // these help with filtering inputs and ensuring that whitespaces are included as the input is being taken
        cin.ignore(1000, '\n');
        getline(cin, candyName1, '\n');

        // takes the input candy string and assigns it to the name of the candy
        // this also makes it easier to assign the candy attributes later on
        Candy boughtCandy = candyland.CandyFromName(candyName1, candies);

        if(playerOne.getplayersCandyAmount() == 9)
        // check to see if the inventory is fully 
        {
            cout << "You do not have room in your candy inventory, Would you like to substitute your candy with any existing candy?(y/n): ";
            char substituteChoice;
            cin >> substituteChoice;
            if(substituteChoice == 'y')
            {
                cout << "Which candy would you like to substitute?" << endl;
                cin.ignore(10000, '\n');
                getline(cin, substitutecandyName1, '\n');
                cout << "Substitute " << substitutecandyName1 << "With " << candyName1 << endl;
                playerOne.replaceCandy(substitutecandyName1, boughtCandy);
                candyStores[0].removeCandy(candyName1);
            }

        }
    }
    
    cout << "Enter player 2 name" << endl; 
    cin >> player2; 
    string selectedCharacter2 = candyland.choosePlayer2(player2, characters, playerTwo); 
    //Character character2 = candyland.CharacterFromName(selectedCharacter2, characters);
    //cout << character1.characterName << endl; 
    //playerTwo.setCharacterParts(character2, player2); 
    playerTwo.printInformation();

    char visitStorePlayer2; 
    
    cout << "Do you want to visit the candy store? (y/n)" << endl;
    cin >> visitStorePlayer2;
    if((visitStorePlayer2 != 'y') && (visitStorePlayer2 != 'n')) 
    {   
        cout << "Invalid input" << endl;
        cin.clear(); 
        cin.ignore(10000, '\n'); 
        cin >> visitStorePlayer2;
    }

    if(visitStorePlayer2 == 'y')
    {
        string candyName2, substitutecandyName2;
        //double playerGold2 = playerTwo.getGold();

        // prints the candies of that store
        candyStores[0].printInventory();
        cout << "Which candy would you like to buy? ";
        // these help with filtering inputs and ensuring that whitespaces are included as the input is being taken
        cin.ignore(1000, '\n');
        getline(cin, candyName2, '\n');

        // takes the input candy string and assigns it to the name of the candy
        // this also makes it easier to assign the candy attributes later on
        Candy boughtCandy2 = candyland.CandyFromName(candyName2, candies);

        if(playerTwo.getplayersCandyAmount() == 9)
        // check to see if the inventory is fully 
        {
            cout << "You do not have room in your candy inventory, Would you like to substitute your candy with any existing candy?(y/n): ";
            char substituteChoice2;
            cin >> substituteChoice2;
            if(substituteChoice2 == 'y')
            {
                cout << "Which candy would you like to substitute?" << endl;
                cin.ignore(10000, '\n');
                getline(cin, substitutecandyName2, '\n');
                cout << "Substitute " << substitutecandyName2 << "With " << candyName2 << endl;
                playerOne.replaceCandy(substitutecandyName2, boughtCandy2);
                candyStores[0].removeCandy(candyName2);
            }

        }
    }




   


    bool anyWinner = false;
    int winnerIndex = 0;
    //int playerArrayIndex = 0;
    bool playerOneTurn = true; 
   


    do
    {
        bool nextPlayer = false; 
        int playerPositionIndex;
        //int otherPlayerArrayIndex = 1; 
        //int otherPlayerPositionIndex = 0; 
        
    
       
        
        do
        {
            if(board.getPlayerPosition(0)==82)
            {
                winnerIndex = 0;
                anyWinner = true;
                break;
                
            }
            if(board.getPlayerPosition(1)==82)
            {
                winnerIndex = 1;
                anyWinner = true;
                break;
            }
            if(playerOneTurn == true)
            {
                cout << "It's Player 1: " << playerOne.getplayerName() << "'s turn" << endl;
                cout << "Select a menu option below (choose 1, 2 or 3)" << endl;
                cout << "1.  Draw a card" << endl;
                cout << "2.  Use candy" << endl;
                cout << "3.  Show player stats" << endl;



            }
            else 
            {
                 cout << "It's " << playerTwo.getplayerName() << " turn" << endl;
                cout << "Select a menu option below (choose 1, 2 or 3)" << endl;
                cout << "1.  Draw a card" << endl;
                cout << "2.  Use candy" << endl;
                cout << "3.  Show player stats" << endl;
            }
           

            char inputOption;
            cin >> inputOption;
            if((inputOption!= '1') && (inputOption!= '2') && (inputOption != '3')) 
            {   
                cout << "Please enter a valid menu option" << endl;
                cin.clear(); 
                cin.ignore(10000, '\n'); 
                cin >> inputOption;
            }


            switch(inputOption)
            {

                case '1':
                {
                    cout << "To draw a card type the letter D" << endl;
                    cin >> inputOption;

                    if(inputOption == 'D' || inputOption == 'd')
                    {

                        if(playerOneTurn == true)
                        {
                            if(playerOne.checkTurn() == true) // BRUH THIS FUNCTION DOESN"T WORK 
                            {
                                anyWinner = board.drawCard(0); // check to make sure this works 

                                // Display board now
                                board.displayBoard();
                            
                                // Calamaties

                                
                                // for each turn , the player loses one stamina unit
                                int playerStamina = playerOne.getStamina();
                                playerStamina = playerStamina-1;
                                // sets the new stamina value 
                                playerOne.setStamina(playerStamina);

                                //cout << players[playerArrayIndex].getStamina(); 
                                vector<CandyPlayer> bothPlayers = board.calamities(playerOne, playerTwo); // calls the calamities functions for the players  
                                playerOne = bothPlayers.at(0);
                                playerTwo = bothPlayers.at(1);

                             
                                
                                if((rand()%5+1) == 3) // 20% chance that it lands on a special tile and get all the tiles 
                                {
                                    bothPlayers = board.specialTiles(playerOne, playerTwo, 1);
                                    if(bothPlayers.empty())
                                    {
                                        anyWinner = board.drawCard(0);
                                    }
                                    else 
                                    {
                                        playerOne = bothPlayers.at(0);
                                        playerTwo = bothPlayers.at(1);

                                    }
                                    cout << "Here is the updated board" << endl; 
                                    board.displayBoard();

                                }
                                

                               
                                // End Calamaties and special tiles 

                            
                                playerPositionIndex = board.getPlayerPosition(0);
                                bool isCandyStore = board.isPositionCandyStore(playerPositionIndex); // check to see if its a candy store 
                                if(isCandyStore == true)
                                {
                                    cout << "You landed on a tile that has a candy store" << endl;
                                    int candyStoreIndex = rand() % 3; // gets a random candy store 
                  
                                    char visitCandyStore;
                                            
                                    // in case the input for visitCandyStore isn't 'y' or 'n'
                                    cout << "Do you want to visit the candy store? (y/n)" << endl;
                                    cin >> visitCandyStore;
                                    if((visitCandyStore!= 'y') && (visitCandyStore!= 'n')) 
                                    {   
                                        cout << "Invalid input" << endl;
                                        cin.clear(); 
                                        cin.ignore(10000, '\n'); 
                                        cin >> visitCandyStore;
                                    }
                                
                                    if(visitCandyStore == 'n')
                                    {
                                        continue;
                                    }

                                    if(visitCandyStore == 'y')
                                    {
                                        string candyName, substitutecandyName;
                                        double playerGold = playerOne.getGold();

                                        // prints the candies of that store
                                        candyStores[candyStoreIndex].printInventory();
                                        cout << "Which candy would you like to buy? ";
                                        // these help with filtering inputs and ensuring that whitespaces are included as the input is being taken
                                        cin.ignore(1000, '\n');
                                        getline(cin, candyName, '\n');

                                        // takes the input candy string and assigns it to the name of the candy
                                        Candy boughtCandy = candyland.CandyFromName(candyName, candies);

                                        if(playerOne.getplayersCandyAmount() == 9)
                                        // check to see if the inventory is fully 
                                        {
                                            cout << "You do not have room in your candy inventory, Would you like to substitute your candy with any existing candy?(y/n): ";
                                            char substituteChoice;
                                            cin >> substituteChoice;
                                            if(substituteChoice == 'y')
                                            {
                                                cout << "Which candy would you like to substitute?" << endl;
                                                cin.ignore(10000, '\n');
                                                getline(cin, substitutecandyName, '\n');
                                                cout << "Substitute " << substitutecandyName << "With " << candyName << endl;
                                                playerOne.replaceCandy(substitutecandyName, boughtCandy);
                                                candyStores[candyStoreIndex].removeCandy(candyName);
                                            }

                                        }
                                        else if (playerGold >= boughtCandy.price)
                                        {
                                            // adds candy to player inventory
                                            playerOne.addCandy(boughtCandy);
                                            playerGold = playerGold - boughtCandy.price;
                                            playerOne.setGold(playerGold);
                                            candyStores[candyStoreIndex].removeCandy(candyName);
                                            candyStores[candyStoreIndex].printInventory();

                                        }
                                        else
                                        {
                                            cout << "You don't have enough gold to purchase this candy" << endl;
                                        }

                                        cout << "Here is your updated candy inventory" << endl;
                                        playerOne.printInventory();
                                    

                                    }

                                }

                                cout << "Player " << 0 + 1 << " position  is " << playerPositionIndex+1 << endl;
                                Tile playerTile = board.getTilePosition(0);
                                if(playerTile.hasGummyCandy == true)
                                {
                                    cout << "Player " << playerOne.getplayerName() << " on a tile with gummy candy and will skip " << playerTile.gummyCandyNumber << " turns" << endl;
                                    playerOne.setTurnSkipAmount(playerTile.gummyCandyNumber);
                                } /// check this hoe 

                                if(playerTile.isHiddenTresureTile == true)
                                {
                                    srand(time(0));
                                    string playerRiddleAnswer;
                                    int randomRiddleIndex = rand() % riddles.size();
                                    bool keepSolvingRiddle;
                                
                                    do
                                    {
                                        keepSolvingRiddle = false;
                                    
                                        cout << "You landed on a hidden treasure! Solve the ridde to get a prize!" << endl;
                                        cout << riddles[randomRiddleIndex].question << endl;
                                        cin.ignore(1000, '\n'); // this will check for any white spaces 
                                        getline(cin, playerRiddleAnswer, '\n');

                                        if (playerRiddleAnswer == riddles[randomRiddleIndex].answer)
                                        {
                                            cout << "Congratulations! That is the correct answer! Here is your prize!" << endl;

                                            int randomTreasureIndex = rand () % 100;

                                            if (randomTreasureIndex < 10) // Gold Windall
                                            {
                                                int currentGold, newGold;
                                                int randomGold = (rand() % 20) + 20;
                                                cout << "Your prize is the Gold Windfall! Here is " << randomGold << " units of Gold!" << endl;
                                                currentGold = playerOne.getGold();
                                                newGold = currentGold + randomGold;
                                                playerOne.setGold(newGold);
                                            }
                                            else if (randomTreasureIndex > 10 && randomTreasureIndex < 40) // Stamina Refill 
                                            {
                                                int stamina, newStamina;
                                                int randomStamina = (rand() % 20) + 10;
                                                cout << "Your prize is the Stamina Refill! Here is " << randomStamina << " units of Stamina!" << endl;
                                                stamina = playerOne.getStamina();
                                                newStamina = stamina + randomStamina;
                                                playerOne.setStamina(newStamina);
                                                
                                            }
                                            else if (randomTreasureIndex > 40 && randomTreasureIndex < 70) // This is for Robber's Repel
                                            {
                                                playerOne.setRobbersRepel(true);
                                                cout << "Lucky for you, you got the Robber's Repel Shield! This will protect you from robbery!" << endl;
                                            }
                                            else if (randomTreasureIndex > 70 && randomTreasureIndex < 100)
                                            {
                                                int randomCandyAcquisition = rand() % 100;

                                                if (randomCandyAcquisition < 30) // Hunter's Truffle
                                                {
                                                    keepSolvingRiddle = true;
                                                }
                                                else if (randomCandyAcquisition > 30 && randomCandyAcquisition < 100) // Jellybean of Vigor
                                                {
                                                    int stamina, newStamina;
                                                    cout << "Your prize is the Jellybean of Vigor! You get 50 units of Stamina!" << endl;
                                                    stamina = playerOne.getStamina();
                                                        
                                                    // Assumption is that if a player already has a stamina > 100, it shouldn't be capped at 100 because of this
                                                    if(stamina < 100 )
                                                    {
                                                        newStamina = stamina + 50;
                                                        if(newStamina > 100)
                                                        {
                                                            newStamina = 100;
                                                        }
                                                        playerOne.setStamina(newStamina);
                                                    }
                                                }
                                            }
                                        }
                                        else
                                        {
                                            cout << "Sorry pookie that's not the right answer! Better luck next time!" << endl;
                                        }

                                    } while(keepSolvingRiddle == true); 

                                }

                                int otherPlayerPositionIndex = board.getPlayerPosition(1); // this gets the other players position incase they are on the same tile 



                                if(otherPlayerPositionIndex == playerPositionIndex) // same tile constraint
                                {
                                   
                                    //cout << playerArrayIndex+1 << endl;
                                    cout << " Player " << 0 + 1 << " stepped on same tile as previous player" << endl;
                                    if (playerOne.getRobbersRepel() == false)
                                    {
                                        srand(time(NULL));
                                        int stealGold, readGold, newGold;
                                        stealGold = (rand() % 25) + 5; // 5-30 gold coins
                                        readGold = playerOne.getGold();
                                        newGold = readGold - stealGold;
                                        // take gold away from player one 
                                        playerOne.setGold(newGold);

                                        readGold= playerOne.getGold();
                                        // add the steal amount to other plays inventory 
                                        playerTwo.setGold(readGold + stealGold);

                                        cout << "Player " << 2 << " has stolen " << stealGold << " gold coins from you!" << endl;
                                    }
                                    else
                                    {
                                        cout << "Player " << 1  << " has the Robber's Repel Shield to protect them!" << endl;
                                        
                                    }
                                }

                                
                                
                               
                            }

                            else
                            {
                                // if isPlayerEligibleForTurn is false, then do this
                                cout << "Player " << playerOne.getplayerName() << " not eligible for a turn currently" << endl;
                            }


                            if (anyWinner == true)
                            {
                                winnerIndex = 0; // sets the winnerIndex to 0
                            }
                            //board.displayBoard();
                            

                        }

                        else // start of player two things 
                        {
                            if(playerTwo.checkTurn() == true) // BRUH THIS FUNCTION DOESN"T WORK -> jk it does now 
                            {
                                anyWinner = board.drawCard(1); // check to make sure this works 
                                //cout << "hi" << endl; 

                                // Display board now
                                board.displayBoard();

                            
                                // Calamaties

                                
                               // for each turn made, the player loses one stamina unit
                                int playerStamina = playerTwo.getStamina(); 
                                playerStamina = playerStamina-1;
                                // sets the new stamina value for that player 
                                playerTwo.setStamina(playerStamina);
                                

                                //cout << players[playerArrayIndex].getStamina(); 
                                vector<CandyPlayer> bothPlayers = board.calamities(playerTwo, playerOne); 
                                playerTwo = bothPlayers.at(0);
                                playerOne = bothPlayers.at(1);

                                if((rand()%5+1) == 3) // 20% chance of there being a special tile (FIGURE OUT THIS JHIT IS IT DOING THE RIGHT PERCENT )
                                {

                                    bothPlayers = board.specialTiles(playerTwo, playerOne, 2);
                                    if(bothPlayers.empty())
                                    {
                                        anyWinner = board.drawCard(0);
                                    }
                                    else 
                                    {
                                        playerTwo = bothPlayers.at(0);
                                        playerOne = bothPlayers.at(1);

                                    }
                                    cout << "Here is the updated board" << endl; 
                                    board.displayBoard();

                                    

                                }
                                
                              
                              // CHECK TO SEE IF THIS IS WORKING 
                              // doing this at the end 

                             


                        
                                // End Calamaties
                            
                                playerPositionIndex = board.getPlayerPosition(1);
                                //Check if this player position on board is a candy Store
                                bool isCandyStore = board.isPositionCandyStore(playerPositionIndex);
                                if(isCandyStore == true)
                                {
                                    cout << "You landed on a tile that has a candy store" << endl;
                                    // ensures that the player is on a candy store & returns candy store index
                                    int candyStoreIndex = rand() % 3;
                                    
                                    char visitCandyStore;
                                            
                                    // in case the input for visitCandyStore isn't 'y' or 'n'
                                    cout << "Do you want to visit the candy store? (y/n)" << endl;
                                    cin >> visitCandyStore;
                                    while((visitCandyStore!= 'y') && (visitCandyStore!= 'n')) 
                                    {   
                                        cout << "Invalid input" << endl;
                                        cin.clear(); 
                                        cin.ignore(10000, '\n'); 
                                        cin >> visitCandyStore;
                                    }
                                
                                    if(visitCandyStore == 'n')
                                    {
                                        continue;
                                    }

                                    if(visitCandyStore == 'y')
                                    {
                                        string candyName, substitutecandyName;
                                        double playerGold = playerTwo.getGold();

                                        // prints the candies of that store
                                        candyStores[candyStoreIndex].printInventory();
                                        cout << "Which candy would you like to buy? ";
                                        // TBD: Check if candy matches the exact name
                                        // these help with filtering inputs and ensuring that whitespaces are included as the input is being taken
                                        cin.ignore(1000, '\n');
                                        getline(cin, candyName, '\n');

                                        Candy boughtCandy = candyland.CandyFromName(candyName, candies); // assigns the candy by using the name 

                                        if(playerTwo.getplayersCandyAmount() == 9)
                                    
                                        {
                                            cout << "You do not have room in the candy inventory, Would you like to substitute your candy with any existing candy?(y/n): ";
                                            char substituteChoice;
                                            cin >> substituteChoice;
                                            if(substituteChoice == 'y')
                                            {
                                                cout << "Which candy would you like to substitute?" << endl;
                                                cin.ignore(10000, '\n');
                                                getline(cin, substitutecandyName, '\n');
                                                cout << "Substitute " << substitutecandyName << "With " << candyName << endl;
                                                playerTwo.replaceCandy(substitutecandyName, boughtCandy);
                                                candyStores[candyStoreIndex].removeCandy(candyName);
                                            }

                                        }
                                        else if (playerGold >= boughtCandy.price)
                                        {
                                            // adds candy to player inventory
                                            playerTwo.addCandy(boughtCandy);
                                            playerGold = playerGold - boughtCandy.price;
                                            playerTwo.setGold(playerGold);
                                            candyStores[candyStoreIndex].removeCandy(candyName);
                                            candyStores[candyStoreIndex].printInventory();

                                        }
                                        else
                                        {
                                            cout << "Sorry you don't have enough gold to purchase this candy" << endl;
                                        }

                                        cout << "Here is your updated candy inventory" << endl;
                                        playerTwo.printInventory();
                                    

                                    }

                                }

                                cout << "Player " << 2 << " position  is " << playerPositionIndex+1 << endl;
                                Tile playerTile = board.getTilePosition(1);
                                if(playerTile.hasGummyCandy == true)
                                {
                                    cout << "Player " << playerTwo.getplayerName() << " on a tile with gummy candy and will skip " << playerTile.gummyCandyNumber << " turns" << endl;
                                    playerTwo.setTurnSkipAmount(playerTile.gummyCandyNumber);
                                }

                                if(playerTile.isHiddenTresureTile == true)
                                {
                                    srand(time(0));
                                    string playerRiddleAnswer;
                                    int randomRiddleIndex = rand() % riddles.size();
                                    bool keepSolvingRiddle;
                                
                                    do
                                    {
                                        keepSolvingRiddle = false;
                                    
                                        cout << "You landed on a hidden treasure! Solve this riddle to get a prize!" << endl;
                                        cout << riddles[randomRiddleIndex].question << endl;
                                        cin.ignore(10000, '\n');
                                        getline(cin, playerRiddleAnswer, '\n');

                                        if (playerRiddleAnswer == riddles[randomRiddleIndex].answer)
                                        {
                                            cout << "Congratulations! That is the correct answer! Here is your prize!" << endl;

                                            int randomTreasureIndex = rand () % 100;

                                            if (randomTreasureIndex < 10) // Gold Windall
                                            {
                                                int currentGoldAmount, newGoldAmount;
                                                int randomGoldWindfall = (rand() % 20) + 20;
                                                cout << "Your prize is the Gold Windfall! Here is " << randomGoldWindfall << " units of Gold!" << endl;
                                                currentGoldAmount = playerTwo.getGold();
                                                newGoldAmount = currentGoldAmount + randomGoldWindfall;
                                                playerTwo.setGold(newGoldAmount);
                                            }
                                            else if (randomTreasureIndex > 10 && randomTreasureIndex < 40) // Stamina Refill 
                                            {
                                                int staminaAmount, newStaminaAmount;
                                                int randomStaminaRefill = (rand() % 20) + 10;
                                                cout << "Your prize is the Stamina Refill! Here is " << randomStaminaRefill << " units of Stamina!" << endl;
                                                staminaAmount = playerTwo.getStamina();
                                                newStaminaAmount = staminaAmount + randomStaminaRefill;
                                                playerTwo.setStamina(newStaminaAmount);
                                                
                                            }
                                            else if (randomTreasureIndex > 40 && randomTreasureIndex < 70) // This is for Robber's Repel
                                            {
                                                playerTwo.setRobbersRepel(true);
                                                cout << "Lucky for you, you got the Robber's Repel Shield! This will protect you from robbery!" << endl;
                                            }
                                            else if (randomTreasureIndex > 70 && randomTreasureIndex < 100)
                                            {
                                                int randomCandyAcquisition = rand() % 100;

                                                if (randomCandyAcquisition < 30) // Hunter's Truffle
                                                {
                                                    keepSolvingRiddle = true;
                                                }
                                                else if (randomCandyAcquisition > 30 && randomCandyAcquisition < 100) // Jellybean of Vigor
                                                {
                                                    int staminaAmount, newStaminaAmount;
                                                    cout << "Your prize is the Jellybean of Vigor! You get 50 units of Stamina!" << endl;
                                                    staminaAmount = playerTwo.getStamina();
                                                        
                                                    // stamina won't be capped 
                                                    if(staminaAmount < 100 )
                                                    {
                                                        newStaminaAmount = staminaAmount + 50;
                                                        if(newStaminaAmount > 100)
                                                        {
                                                            newStaminaAmount = 100;
                                                        }
                                                        playerTwo.setStamina(newStaminaAmount);
                                                    }
                                                }
                                            }
                                        }
                                        else
                                        {
                                            cout << "Sorry pookie that's not the right answer! Better luck next time!" << endl;
                                        }

                                    } while(keepSolvingRiddle == true); 

                                }

                                int otherPlayerPositionIndex = board.getPlayerPosition(0);



                                if(otherPlayerPositionIndex == playerPositionIndex) // same tile constraint
                                {
                                    // For debug only
                                    //cout << playerArrayIndex+1 << endl;
                                    cout << " Player " << 1 + 1 << " stepped on same tile as previous player" << endl;
                                    if (playerTwo.getRobbersRepel() == false)
                                    {
                                        srand(time(NULL));
                                        int stealGoldAmount, readGoldAmount, newGoldAmount;
                                        stealGoldAmount = (rand() % 25) + 5; // steal range from 5-30 gold coins
                                        readGoldAmount = playerTwo.getGold();
                                        // this subtracts the steal amount from current amount
                                        newGoldAmount = readGoldAmount - stealGoldAmount;
                                        playerTwo.setGold(newGoldAmount);

                                        readGoldAmount = playerTwo.getGold();
                                        // adds that steal amount to previous player's gold amount
                                        playerOne.setGold(readGoldAmount + stealGoldAmount);

                                        cout << "Player " << 1 << " has stolen " << stealGoldAmount << " gold coins from you!" << endl;
                                    }
                                    else
                                    {
                                        cout << "Player " << 2  << " has the Robber's Repel Shield to protect them!" << endl;
                                        
                                    }
                                }
                                
                                
                            }

                            else
                            {
                                // if isPlayerEligibleForTurn is false, then do this
                                cout << "Player " << playerTwo.getplayerName() << " not eligible for a turn currently" << endl;
                            }


                            if (anyWinner == true)
                            {
                                winnerIndex = 1; // sets the winnerIndex to 0
                            }
                            //board.displayBoard();
                            
                        }


                        // Check if player is eligble for a turn here
                       
                    }

                    nextPlayer = true;
                    if(playerOneTurn == true)
                    {
                        playerOneTurn = false;
                    }
                    else
                    {
                        playerOneTurn = true;
                    }
                
                }
                break;

                case '2':
                {
                    string candyNameInput;

                    cout << "Here is your candy inventory:" << endl;

                    if(playerOneTurn == true)
                    {
                        playerOne.printInventory();

                        cout << "Which candy would you like to use? (type in candy name exactly)" << endl;

                        cin.ignore(1000, '\n');
                        getline(cin, candyNameInput, '\n');

                        // takes the input candy string and assigns it to the name of the candy
                        // this also makes it easier to assign the candy attributes later on
                        Candy candyToUse = candyland.CandyFromName(candyNameInput, candies);

        
                        candyland.ApplyCandyToPlayers(board, candyToUse, playerOne, playerTwo); // apply the candy being used to the other player and subtract/add anything necessary 

                        //Remove the candy from Player inventory
                        playerOne.removeCandy(candyNameInput);
                    
                        
                            

                    }
                    else 
                    {
                        playerTwo.printInventory();
                        cout << "Which candy would you like to use (type in candy name exactly)?" << endl;

                       
         
                        cin.ignore(1000, '\n');
                        getline(cin, candyNameInput, '\n');
                        
             
                        Candy candyToUse = candyland.CandyFromName(candyNameInput, candies); // assign w name 

                        candyland.ApplyCandyToPlayers(board, candyToUse, playerTwo, playerOne); // apply it to the players 

  
                        playerTwo.removeCandy(candyNameInput); // then remove the candy 
                        
                        
                        
                        
                    }
                    nextPlayer = true;
                    if(playerOneTurn == true)
                    {
                        playerOneTurn = false;
                    }
                    else
                    {
                        playerOneTurn = true;
                    }
            
                    
                }
                break;

                case '3':
                {

                    if(playerOneTurn == true)
                    {
                        cout << "Here are your stats:" << endl;
                        playerOne.printInformation();
                        // For debug only
                        //candyStore[0].printCandy();
                        //candyStore[1].printCandy();
                        //candyStore[2].printCandy();

                    }
                    else 
                    {
                        cout << "Here are your stats:" << endl;
                        playerTwo.printInformation();
                        // For debug only
                        //candyStore[0].printCandy();
                        //candyStore[1].printCandy();
                        //candyStore[2].printCandy();
                      
                    }
                    
                        
                }

                break;

            }

            


        } while(nextPlayer == false); //while one of the player  is still going
        
        
        // otherPlayerPositionIndex = playerPositionIndex;
        // otherPlayerArrayIndex = playerArrayIndex;
        
        //Update the player 
        // if (playerArrayIndex == 1)
        // {
        //     // sets player 1's turn
        //     playerArrayIndex = 0;
        // }
        // else
        // {
        //     // sets player 2's turn
        //     playerArrayIndex++;
        // }

        

    } while (anyWinner == false);
    

    // TBD: We also need to print these stats in a files called results.txt
    if(anyWinner == true)
    {
        if(winnerIndex == 0)
        {
            cout << "The Winner is " << playerOne.getplayerName() << " !!!" << endl;
            cout << "Check the file to see all player stats." << endl; 
            

            // cout << "Player 1 information" << endl; 
            // playerOne.printInformation();
            // cout << "Player 2 information" << endl; 
            // playerTwo.printInformation(); 


            ofstream finalFile;
            finalFile.open ("finalStats.txt");
            finalFile << "The Winner is " << playerOne.getplayerName(); 
            finalFile << "Winner Stats:" << endl; 
            finalFile << "Player Name: " << playerOne.getplayerName() << endl;
            finalFile << " Player character: " << playerOne.getCharacter()  << endl;
            finalFile << " Player Stamina: " << playerOne.getStamina() << endl;
            finalFile << " Player Gold: " << playerOne.getGold() << endl;
            finalFile << " Player Inventory: " << endl;
            playerOne.inventoryForOutput(finalFile);

            finalFile << "The Other Player is " << playerTwo.getplayerName(); 
            finalFile << "Other Player Stats:" << endl; 
            finalFile << "Player Name: " << playerTwo.getplayerName() << endl;
            finalFile << " Player character: " << playerTwo.getCharacter()  << endl;
            finalFile << " Player Stamina: " << playerTwo.getStamina() << endl;
            finalFile << " Player Gold: " << playerTwo.getGold() << endl;
            finalFile << " Player Inventory: " << endl;
            playerTwo.inventoryForOutput(finalFile);


            
            finalFile.close();
            cout << "Thank you for playing" << endl; 
            return 0;

           
            //// PRINT THESE STATS OUR ONTO ANOTHER NEW FILE 
            

        }
        if(winnerIndex == 1)
        {
            cout << "The Winner is " << playerTwo.getplayerName() << " !!!" << endl;
            cout << "Check the file to see all player stats" << endl; 

            // cout << "Player 1 information" << endl; 
            // playerOne.printInformation();
            // cout << "Player 2 information" << endl; 
            // playerTwo.printInformation(); 

            ofstream finalFile;

            finalFile << "The Winner is " << playerTwo.getplayerName(); 
            finalFile << "Winner Stats:" << endl; 
            finalFile << "Player Name: " << playerTwo.getplayerName() << endl;
            finalFile << " Player character: " << playerTwo.getCharacter()  << endl;
            finalFile << " Player Stamina: " << playerTwo.getStamina() << endl;
            finalFile << " Player Gold: " << playerTwo.getGold() << endl;
            finalFile << " Player Inventory: " << endl;
            playerTwo.inventoryForOutput(finalFile);

            finalFile.open ("finalStats.txt");
            finalFile << "The Other Player is " << playerOne.getplayerName(); 
            finalFile << "Other Player Stats:" << endl; 
            finalFile << "Player Name: " << playerOne.getplayerName() << endl;
            finalFile << " Player character: " << playerOne.getCharacter()  << endl;
            finalFile << " Player Stamina: " << playerOne.getStamina() << endl;
            finalFile << " Player Gold: " << playerOne.getGold() << endl;
            finalFile << " Player Inventory: " << endl;
            playerOne.inventoryForOutput(finalFile);

            finalFile.close();
            cout << "Thank you for playing" << endl; 
            return 0;

            //// PRINT THESE STATS OUR ONTO ANOTHER NEW FILE 
        }
        
    }


}



  
