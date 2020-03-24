/*********************************************************************
** Program name: project3
** Author:       Rebekah Koon
** Date:         7/24/19
** Description:  Implementation file for the Barbarian class, which is
**               derived from the Character class. Uses the default 
**               constructor to initialize the number of attack and
**               defense dice and their side numbers as well as the
**               strength points, armor, and name.
*********************************************************************/


#include "Barbarian.hpp"


/*********************************************************************
** Description: Default constructor for the Barbarian class. Inherits
**              from the Character class and initializes variables for
**              the number of attack and defense dice, number of 
**              sides for the attack and defense dice, armor, strength
**              points, and name.
*********************************************************************/
Barbarian::Barbarian(): Character()
{
    //Setting dice amount and number of sides for attack die
    numAttackDie = 2;
    attackDieSides = 6;

    //Setting dice amount and number of sides for defense die
    numDefenseDie = 2;
    defenseDieSides = 6;

    armor = 0;
    strengthPoints = 12;

    name = "Barbarian";
}


/*********************************************************************
** Description: Destructor for the Barbarian class.
*********************************************************************/
Barbarian::~Barbarian()
{
}