/*********************************************************************
** Author: Collin James
** Date: 11/5/15
** Description: A class for Shadows that inherits from Creature.
**
** Implementation file 
*********************************************************************/
#include "Shadow.hpp"
#include <iostream>	// for status messages
Shadow::Shadow(double att_num, double att_sides, 
			   double def_num, double def_sides, 	
			   double arm, 	double str, 	
			   CharType t
			  // ) : Barbarian(att_num, att_sides, def_num, def_sides, arm, str, t)
			  ) : Creature(att_num, att_sides, def_num, def_sides, arm, str, t)
{
	disappeared = 0;
}

Shadow::~Shadow()
{
	/* Message to help graders. Comment out in actual battle. */
	std::cout << "     Shadow disappeared " << this->disappeared << " times!" << std::endl;
}

/* 	same as Barbarian!! Inherit from Barbarian instead to avoid duplicating 
	Including only for the sake of having all new Creatures inherit from 
	Creature */
double Shadow::attacks(Creature* target)
{
	/* 	doAttack() will pass rollDice() output to target defend function
		which will inflict the damage */
	return doAttack(target, rollDice(attack));
}

/* Overridden defend function to implement special move. */
double Shadow::defend(double attack_val, CharType attacker, bool halve_attack)
{
	double special = (1 + rand() % 2), // random between 1 and 2 (50% chance)
		damage = 0;

	if(special == 1) // disappear!
	{
		damage = 0;
		disappeared++; // keep track of disappearances
		/* uncomment to display status message! */
		// std::cout << "* ** * Shadow disappeared! * ** *" << std::endl;
	}
	else // normal defense
		damage = inflictDamage(attack_val, halve_attack);

	return damage;
}