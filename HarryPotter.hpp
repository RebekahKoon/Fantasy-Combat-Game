/***********************************************************************
** Program name: project3
** Author:       Rebekah Koon
** Date:         7/24/19
** Description:  Header file for the HarryPotter class, which is derived
**               from the Character class. Uses the default constructor
**               to initialize the number of attack and defense dice
**               and their side numbers as well as the strength points,
**               armor, name, and hogwarts. Overrides the damageTaken
**               function to determine if Harry Potter can be revived
**               using hogwarts after losing all strength points.
***********************************************************************/

#ifndef HARRY_POTTER_HPP
#define HARRY_POTTER_HPP

#include "Character.hpp"

class HarryPotter: public Character
{
    private:
        int hogwarts;
        
    public:
        HarryPotter();
        virtual void damageTaken(int, int);
        virtual ~HarryPotter();
};


#endif