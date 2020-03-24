/**********************************************************************
** Program name: project3
** Author:       Rebekah Koon
** Date:         7/24/19
** Description:  Header file for the Barbarian class, which is derived
**               from the Character class. Uses the default constructor
**               to initialize the number of attack and defense dice 
**               and their side numbers as well as the strength points,
**               armor amount, and name.
**********************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Character.hpp"

class Barbarian: public Character
{
    public:
        Barbarian();
        virtual ~Barbarian();
};


#endif