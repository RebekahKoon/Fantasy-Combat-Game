/***********************************************************************
** Program name: project3
** Author:       Rebekah Koon
** Date:         7/24/19
** Description:  Implementation file for the Character class, which
**               has virtual functions to calculate the attack, defense,
**               and damage taken for a character. It also has virtual
**               functions to determine if a character lost and to get
**               the name, armor, or strength points of a character.
***********************************************************************/

#include "Character.hpp"


/*********************************************************************
** Description: Default constructor for the Character class. Sets
**              number of attack die and sides of an attack die to 0,
**              number of defense die and sides of a defense die to 0,
**              armor to 0, and number of strength points to 0. Also
**              sets the name of a character to an empty string.
*********************************************************************/
Character::Character()
{
    numAttackDie = 0;
    attackDieSides = 0;

    numDefenseDie = 0;
    defenseDieSides = 0;

    armor = 0;
    strengthPoints = 0;

    name = "";
}


/*********************************************************************
** Description: Member function attack randomly generates integers to
**              roll dice in order to determine the attack points of 
**              a character. Returns the total attack.
*********************************************************************/
int Character::attack()
{
    int attackPoints,
        totalAttack = 0;

    //Finding the total attack by rolling number of attack dice for character
    for (int i = 0; i < numAttackDie; i++)
    {
        //Random number generated for side rolled
        attackPoints = rand() % attackDieSides + 1;
        totalAttack += attackPoints;
    }

    return totalAttack;
}


/*********************************************************************
** Description: Member function defense randomly generates integers to
**              roll dice in order to determine the defense points of
**              a character. Returns the total defense.
*********************************************************************/
int Character::defense()
{
    int defensePoints,
        totalDefense = 0;

    //Finding the total defense by rolling number of defense dice for character
    for (int i = 0; i < numDefenseDie; i++)
    {
        //Random number generated for side rolled
        defensePoints = rand() % defenseDieSides + 1;
        totalDefense += defensePoints;
    }

    //Printing defense stats
    cout << "Defending " << name << "'s stats:" << endl;
    cout << getStrengthPoints() << " strength points" << endl;
    cout << totalDefense << " defense points" << endl;
    cout << getArmor() << " armor" << endl << endl;

    return totalDefense;
}


/*********************************************************************
** Description: Void member function damageTaken takes in the defense
**              points of the character and the attack points of the
**              enemy as parameters. Determines the amount of damage 
**              taken by a character when an opponent is attacking.
**              Subtracts damage from strength points.
*********************************************************************/
void Character::damageTaken(int defense, int enemyAttack)
{
    int totalDamage;

    //Determining damage taken
    totalDamage = enemyAttack - defense - armor;

    //totalDamage cannot be negative. If negative, sets to 0
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
}


/***********************************************************************
** Description: Member function characterLost determines if a character
**              is out of strength points. Returns true if out of 
**              strength points and false if not out of strength points.
***********************************************************************/
bool Character::characterLost()
{
    bool lost;

    //Character has not lost
    if (strengthPoints > 0)
    {
        lost = false;
    }

    //Character has lost
    else
    {
        lost = true;
    }
    
    return lost;
}


/*********************************************************************
** Description: Member function getName returns a character's name.
*********************************************************************/
string Character::getName()
{
    return name;
}


/*********************************************************************
** Description: Member function getArmor returns a character's armor.
*********************************************************************/
int Character::getArmor()
{
    return armor;
}


/*********************************************************************
** Description: Member function getStrengthPoints returns the number 
**              of strength points a character has.
*********************************************************************/
int Character::getStrengthPoints()
{
    return strengthPoints;
}


/*********************************************************************
** Description: Destructor for the Character class.
*********************************************************************/
Character::~Character()
{
}