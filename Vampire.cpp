/*********************************************************************
** Program name: project3
** Author:       Rebekah Koon
** Date:         7/24/19
** Description:  Implementation file for the Vampire class, which is 
**               derived from the Character class. Uses the default 
**               constructor to initialize the number of attack and
**               defense dice and their side numbers as well as the
**               strength points, armor, and name. Also overrides the
**               defense function in the Character class to account
**               for the vampire's charm special ability.
*********************************************************************/


#include "Vampire.hpp"


/*********************************************************************
** Description: Default constructor for the Vampire class. Inherits
**              from the Character class and initializes variables for
**              the number of attack and defense die, number of 
**              sides for the attack and defense die, armor, strength
**              points, and name.
*********************************************************************/
Vampire::Vampire(): Character()
{
    //Setting dice amount and number of sides for attack die
    numAttackDie = 1;
    attackDieSides = 12;

    //Setting dice amount and number of sides for defense die
    numDefenseDie = 1;
    defenseDieSides = 6;

    armor = 1;
    strengthPoints = 18;

    name = "Vampire";
}


/**********************************************************************
** Description: Member function defense generates a random integer
**              representing the defense of the vampire. Also generates
**              a random integer representing the vampire's charm. If 
**              charm is activated, defense increases to 100. Returns
**              the total defense of the vampire.
**********************************************************************/
int Vampire::defense()
{
    int charm,
        totalDefense = 0;

    totalDefense = rand() % defenseDieSides + 1;

    //Printing defense stats
    cout << "Defending " << name << "'s stats:" << endl;
    cout << getStrengthPoints() << " strength points" << endl;
    cout << totalDefense << " defense points" << endl;
    cout << getArmor() << " armor" << endl << endl;

    //Determining if the vampire charmed their opponent
    charm = rand() % 2 + 1;

    //If charm is activated
    if (charm == 1)
    {
        totalDefense = 100;
        cout << "The defending Vampire turned up the charm!" << endl;
        cout << "The opponent was not able to attack!" << endl << endl;
    }

    return totalDefense;
}


/**********************************************************************
** Description: Destructor for the Vampire class.
**********************************************************************/
Vampire::~Vampire()
{
}