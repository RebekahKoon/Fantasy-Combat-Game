/**********************************************************************
** Program name: project3
** Author:       Rebekah Koon
** Date:         7/24/19
** Description:  Header file for the Medusa class, which is derived
**               from the Character class. Uses the default constructor
**               to initialize the number of attack and defense dice
**               and their side numbers as well as the strength points,
**               armor, and name. Also overrides the attack function
**               in the Character class to determine if Medusa uses
**               her glare special ability.
**********************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Character.hpp"

class Medusa: public Character
{
    public:
        Medusa();
        virtual int attack();
        virtual ~Medusa();
};


#endif