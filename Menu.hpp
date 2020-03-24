/***********************************************************************
** Program name: project3
** Author:       Rebekah Koon
** Date:         7/24/19
** Description:  Header file for the Menu class, which controls the 
**               game. Contains a function asking user if they want to
**               play. Also has a function to select a character for 
**               each fighter, a function that keeps track of each round
**               as well as the winner of the game, and a function to
**               make the two characters fight.
**               Adapted from project 2 menu.
***********************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include "validInput.hpp"
#include "Character.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"

#include <iostream>
#include <string>
#include <cstdlib>

using std::cin;
using std::cout;
using std::getline;
using std::atoi;
using std::string;
using std::endl;

//Used in selecting a character to fight with
enum CharacterChoice {VAMPIRE = 1, BARBARIAN, BLUE_MEN, MEDUSA, HARRY_POTTER};

class Menu
{
    public:
        int chooseToPlay();
        Character * characterSelect();
        void playGame();
        void characterFight(Character *, Character *);
};

#endif