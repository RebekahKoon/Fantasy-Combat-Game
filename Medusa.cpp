/***********************************************************************
** Program name: project3
** Author:       Rebekah Koon
** Date:         7/24/19
** Description:  Implementation file for the Medusa class, which is 
**               derived from the Character class. Uses the default
**               constructor to initialize the number of attack and 
**               defense dice and their side numbers as well as the 
**               strength points, armor, and name. Also overrides the
**               attack function in the Character class to determine if
**               Medusa uses her glare special ability.
***********************************************************************/

#include "Medusa.hpp"


/*********************************************************************
** Description: Default constructor for the Medusa class. Inherits
**              from the Character class and initializes variables for
**              the number of attack and defense die, number of 
**              sides for the attack and defense die, armor, strength
**              points, and name.
*********************************************************************/
Medusa::Medusa(): Character()
{
    //Setting dice amount and number of sides for attack die
    numAttackDie = 2;
    attackDieSides = 6;

    //Setting dice amount and number of sides for defense die
    numDefenseDie = 1;
    defenseDieSides = 6;

    armor = 3;
    strengthPoints = 8;

    name = "Medusa";
}


/*********************************************************************
** Description: Member function attack generates two random integers
**              representing the numbers rolled for the attack dice to
**              calculate Medusa's attack power. If total attack is 
**              12, activates glare, which instantly kills an
**              opponent. Returns the total attack power.
*********************************************************************/
int Medusa::attack()
{
    int attackPoints,
        totalAttack = 0;

    //Finding total attack power of Medusa
    for (int i = 0; i < numAttackDie; i++)
    {
        attackPoints = rand() % attackDieSides + 1;
        totalAttack += attackPoints;
    }

    //If Medusa uses glare, instantly kills opponent
    if (totalAttack == 12)
    {
        cout << "The attacking Medusa rolled a " << totalAttack << "." << endl;

        totalAttack = 100;
        cout << "She used glare to turn her opponent to stone!" << endl;
    }

    return totalAttack;
}


/*********************************************************************
** Description: Destructor for the Medusa class.
*********************************************************************/
Medusa::~Medusa()
{
}