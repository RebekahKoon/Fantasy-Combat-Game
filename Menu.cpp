/***********************************************************************
** Program name: project3
** Author:       Rebekah Koon
** Date:         7/24/19
** Description:  Implementation file for the Menu class, which controls
**               the game. Contains a function asking user if they want
**               to play. Also has a function to select a character for 
**               each fighter, a function that keeps track of each round
**               as well as the winner of the game, and a function to
**               make the two characters fight.
**               Adapted from project 2 menu.
***********************************************************************/

#include "Menu.hpp"


/*********************************************************************
** Description: Function chooseToPlay asks the user if they want to
**              play the game. Returns the user's choice.
*********************************************************************/
int Menu::chooseToPlay()
{
    int choice;
    const int CHOICE_MIN = 1,
              CHOICE_MAX = 2;

    cout << "1. Play the game." << endl;
    cout << "2. Quit." << endl;
    cout << "Please enter your choice (1-2): ";

    //Calling validInput to see if the user entered 1 or 2
    choice = validInput(CHOICE_MIN, CHOICE_MAX);

    return choice;
}


/*********************************************************************
** Description: Void function playGame first asks the user to select
**              their two fighters. Calls characterSelect to allocate
**              memory for the two fighters dynamically. Displays the
**              character's stats after each round. If a character 
**              runs out of strength points, they lose the game. Exits
**              after winner is determined.
*********************************************************************/
void Menu::playGame()
{
    Character *fighter1,
              *fighter2;

    int atkFighter1,
        atkFighter2,
        defFighter1,
        defFighter2,
        strPtsFighter1,
        strPtsFighter2,
        roundNumber = 1;

    string winner;

    //Dynamically allocating memory for the first fighter
    cout << "Who will be the first fighter?" << endl;
    fighter1 = characterSelect();

    cout << fighter1->getName() << " was selected for the first fighter." 
         << endl << endl;

    //Dynaimically allocating memory for the second fighter
    cout << "Who will be the second fighter?" << endl;
    fighter2 = characterSelect();

    cout << fighter2->getName() << " was selected for the second fighter."
         << endl << endl << endl;
    
    //Game continues until one character runs out of strength points
    while (!(fighter1->characterLost()) && !(fighter2->characterLost()))
    {
        //Tracking round number
        cout << endl << "Round " << roundNumber << ": " << endl;

        cout << "First fighter " << fighter1->getName() << " attacks"
             << " second fighter " << fighter2->getName() << "!" << endl;
        
        //Fighter 1 is attacker, fighter 2 is defender; shows their stats
        characterFight(fighter1, fighter2);

        //Stops game if fighter 2 has 0 strength points; fighter 1 wins
        if ((fighter2->getStrengthPoints()) == 0)
        {
            winner = fighter1->getName();
            cout << "First fighter " << winner << " wins!" << endl << endl;
        }

        //Continue game if fighter 2 hasn't lost
        else
        {
            cout << endl << "Second fighter " << fighter2->getName()
                 << " attacks first fighter " << fighter1->getName() 
                 << "!" << endl;

            //Fighter 2 is attacker, fighter 1 is defender; shows their stats
            characterFight(fighter2, fighter1);

            roundNumber++;

            //If fighter 1 loses, game ends; fighter 2 is winner
            if ((fighter1->getStrengthPoints()) == 0)
            {
                winner = fighter2->getName();
                cout << "Second fighter " << winner << " wins!"
                     << endl << endl;
            }
        }
    }

    delete fighter1;
    delete fighter2;
}


/**********************************************************************
** Description: Function characterSelect is used to allow the user to
**              select what character they want. Dynamically allocates
**              memory depending on their choice. Returns a pointer to
**              a Character object for the chosen fighter.
**********************************************************************/
Character * Menu::characterSelect()
{
    Character *fighter;
    int charChoice;
    const int CHOICE_MIN = 1,
              CHOICE_MAX = 5;

    cout << "1. Vampire" << endl;
    cout << "2. Barbarian" << endl;
    cout << "3. Blue Men" << endl;
    cout << "4. Medusa" << endl;
    cout << "5. Harry Potter" << endl << endl;
    cout << "Please enter your choice (1-5): ";

    charChoice = validInput(CHOICE_MIN, CHOICE_MAX);
    
    //Dynamically allocates memory for the chosen fighter
    switch (charChoice)
    {
    case VAMPIRE:
        fighter = new Vampire;
        break;

    case BARBARIAN:
        fighter = new Barbarian;
        break;
    
    case BLUE_MEN:
        fighter = new BlueMen;
        break;

    case MEDUSA:
        fighter = new Medusa;
        break;

    case HARRY_POTTER:
        fighter = new HarryPotter;
        break;
    }

    return fighter;
}


/*********************************************************************
** Description: Void function characterFight takes in two pointers to 
**              Character objects as parameters for the attacker and 
**              defender. Uses the Character class to calculate the 
**              attack points for the attacker and defense points for
**              the defender. Also uses the damageTaken function from
**              the Character class to determine the amount of damage
**              a character takes.
*********************************************************************/
void Menu::characterFight(Character *attacker, Character *defender)
{
    int attackPts,
        defensePts,
        defenderDamage,
        defenderArmor = defender->getArmor();

    string attackerName = attacker->getName(),
           defenderName = defender->getName();

    //Total attack for attacker
    attackPts = attacker->attack();
    cout << "Attacking " << attackerName << " attack points: " 
         << attackPts << endl << endl;

    //Total defense for defender. Prints defense, armor, and strength points
    defensePts = defender->defense();
    
    //Calculating damage by subtracting defense and armor from enemy attack
    defender->damageTaken(defensePts, attackPts);

    //Showing strength points after attack
    cout << "Defending " << defenderName 
         << "'s strength points after the attack: "
         << defender->getStrengthPoints() << endl << endl;
}