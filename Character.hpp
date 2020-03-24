/***********************************************************************
** Program name: project3
** Author:       Rebekah Koon
** Date:         7/24/19
** Description:  Header file for the Character class, which has virtual
**               functions to calculate the attack, defense, and damage
**               taken for a character. It also has virtual functions to
**               determine if a character lost and to get the name,
**               armor, or strength points of a character.
***********************************************************************/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

using std::string;
using std::cout;
using std::endl;

class Character
{
    protected:
        int numAttackDie;
        int attackDieSides;

        int numDefenseDie;
        int defenseDieSides;

        int armor;
        int strengthPoints;

        string name;

    public:
        Character();

        virtual int attack();
        virtual int defense();
        virtual void damageTaken(int, int);

        virtual bool characterLost();

        virtual string getName();
        virtual int getArmor();
        virtual int getStrengthPoints();

        virtual ~Character() = 0;
};

#endif