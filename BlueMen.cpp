/*********************************************************************
** Program name: project3
** Author:       Rebekah Koon
** Date:         7/24/19
** Description:  Implementation file for the BlueMen class, which is 
**               derived from the Character class. Uses the default 
**               constructor to initialize the number of attack and
**               defense dice and their side numbers as well as the
**               strength points, armor, and name. Also overrides the
**               damageTaken function in the Character class to find
**               the amount of dice the Blue Men currently have.
*********************************************************************/


#include "BlueMen.hpp"


/*********************************************************************
** Description: Default constructor for the BlueMen class. Inherits
**              from the Character class and initializes variables for
**              the number of attack and defense dice, number of 
**              sides for the attack and defense dice, armor, strength
**              points, and name.
*********************************************************************/
BlueMen::BlueMen(): Character()
{
    //Setting dice amount and number of sides for attack die
    numAttackDie = 2;
    attackDieSides = 10;

    //Setting dice amount and number of sides for defense die
    numDefenseDie = 3;
    defenseDieSides = 6;

    armor = 3;
    strengthPoints = 12;

    name = "Blue Men";
}


/*********************************************************************
** Description: Void member function damageTaken takes in the defense
**              points of the Blue Men and the attack points of the
**              enemy as parameters. Determines the amount of damage 
**              taken by the Blue Men when an opponent is attacking.
**              Subtracts damage from strength points. Also determines
**              the amount of dice the Blue Men currently have.
*********************************************************************/
void BlueMen::damageTaken(int defense, int enemyAttack)
{
    int totalDamage;

    //Determining damage taken
    totalDamage = enemyAttack - defense - armor;

    //totalDamage cannot be negative; if negative, sets to 0
    if (totalDamage < 0)
    {
        totalDamage = 0;
    }

    //Calculating remaining strength points
    strengthPoints -= totalDamage;

    //Cannot have negative strength points
    if (strengthPoints < 0)
    {
        strengthPoints = 0;
    }

    cout << "The defending " << name << " took "
         << totalDamage << " damage." << endl;

    //Lose 2 defense dice if have less than/equal to 4 strength points
    if (strengthPoints <= 4 && strengthPoints != 0)
    {
        numDefenseDie = 1;
        cout << "The Blue Men have one defense die." << endl;
    }

    //Lose 1 defense die if have less than/equal to 8 strength points
    else if (strengthPoints <= 8 && strengthPoints != 0)
    {
        numDefenseDie = 2;
        cout << "The Blue Men have two defense dice." << endl;
    }

    //If strength points not less than/equal to 8, still have all three dice
    else if (strengthPoints <= 12 && strengthPoints != 0)
    {
        cout << "The Blue Men still have three defense dice." << endl;
    }
}


/**********************************************************************
** Description: Destructor for the BlueMen class.
**********************************************************************/
BlueMen::~BlueMen()
{
}