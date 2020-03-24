/***********************************************************************
** Program name: project3
** Author:       Rebekah Koon
** Date:         7/24/19
** Description:  Implementation file for the HarryPotter class, which is
**               derived from the Character class. Uses the default
**               constructor to initialize the number of attack and 
**               defense dice and their side numbers as well as the 
**               strength points, armor, name, and hogwarts. Overrides 
**               the damageTaken function to determine if Harry Potter 
**               can be revived using hogwarts after losing all strength 
**               points.
***********************************************************************/


#include "HarryPotter.hpp"


/**********************************************************************
** Description: Default constructor for the HarryPotter class. Inherits
**              from the Character class and initializes variables for
**              the number of attack and defense die, number of 
**              sides for the attack and defense die, armor, strength
**              points, and name. Also initializes hogwarts.
**********************************************************************/
HarryPotter::HarryPotter(): Character()
{
    //Setting die amount and number of sides for attack die
    numAttackDie = 2;
    attackDieSides = 6;

    //Setting die amount and number of sides for defense die
    numDefenseDie = 2;
    defenseDieSides = 6;

    armor = 0;
    strengthPoints = 10;

    name = "Harry Potter";

    //Tracks how many times Harry Potter can be revived
    hogwarts = 1;
}


/*********************************************************************
** Description: Void member function damageTaken takes in the defense
**              points of Harry Potter and the attack points of the
**              enemy as parameters. Determines the amount of damage 
**              taken by Harry Potter when an opponent is attacking.
**              Subtracts damage from strength points. If Harry Potter
**              has not yet used his Hogwarts ability, revives him and
**              increases strength points to 20.
*********************************************************************/
void HarryPotter::damageTaken(int defense, int enemyAttack)
{
    int totalDamage;

    totalDamage = enemyAttack - defense - armor;

    //Determining if totalDamage is negative; if so, sets to 0
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

    cout << "The defending Harry Potter took "
         << totalDamage << " damage." << endl;

    //Determining if Harry Potter can be revived using hogwarts
    if (strengthPoints == 0 && hogwarts > 0)
    {
        cout << "He was mortally wounded but used Hogwarts to revive!" << endl;

        strengthPoints = 20;

        //Harry Potter cannot revive again
        hogwarts--;
    }
}


/*********************************************************************
** Description: Destructor for the HarryPotter class.
*********************************************************************/
HarryPotter::~HarryPotter()
{
}