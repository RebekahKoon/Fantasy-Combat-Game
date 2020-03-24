/**********************************************************************
** Program name: project3
** Author:       Rebekah Koon
** Date:         7/24/19
** Description:  Header file for the Vampire class, which is derived
**               from the Character class. Uses the default constructor
**               to initialize the number of attack and defense dice
**               and their side numbers as well as the strength points,
**               armor, and name. Also overrides the defense function
**               in the Character class to account for the vampire's 
**               special ability.
**********************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Character.hpp"

class Vampire: public Character
{
    public:
        Vampire();
        virtual int defense();
        virtual ~Vampire();
};


#endif