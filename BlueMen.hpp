/**********************************************************************
** Program name: project3
** Author:       Rebekah Koon
** Date:         7/24/19
** Description:  Header file for the BlueMen class, which is derived
**               from the Character class. Uses the default constructor
**               to initialize the number of attack and defense dice
**               and their side numbers as well as the strength points,
**               armor, and name. Also overrides the damageTaken 
**               function in the Character class to find the amount of
**               dice the Blue Men currently have.
**********************************************************************/

#ifndef BLUE_MEN_HPP
#define BLUE_MEN_HPP

#include "Character.hpp"

class BlueMen: public Character
{
    public:
        BlueMen();
        virtual void damageTaken(int, int);
        virtual ~BlueMen();
};


#endif