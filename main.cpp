/*********************************************************************
** Program name: project3
** Author:       Rebekah Koon
** Date:         7/24/19
** Description:  This program plays a game in which the user selects
**               two fighters to battle. The attacker's total attack
**               is based on dice rolls, while the defender's defense
**               is based on dice rolls and their amount of armor. 
**               With each round, each character attacks the other as
**               well as defends an attack, and some characters have
**               special attacks to use. The character that runs out
**               of strength points first loses. Game can be played 
**               again if the user chooses to do so.
*********************************************************************/

#include "Menu.hpp"
#include "validInput.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;

int main()
{
    //Used to generate random numbers
    unsigned seed;
    seed = time(0);
    srand(seed);

    int choice;

    Menu gameMenu;

    cout << "In this game, you will pick two characteres to fight." << endl;
    cout << "A character loses if they run out of strength points." 
         << endl << endl;
    cout << "Would you like to play?" << endl;

    //Determining if game will be played
    choice = gameMenu.chooseToPlay();

    //Playing the game
    while (choice == 1)
    {
        cout << endl;
        gameMenu.playGame();

        //Game starts over if user wants to play again
        cout << "Would you like to play again?" << endl;
        choice = gameMenu.chooseToPlay();
    }

    cout << "Goodbye!" << endl;

    return 0;
}