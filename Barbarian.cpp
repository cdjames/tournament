/*********************************************************************
** Author: Collin James
** Date: 11/5/15
** Description: A class for Barbarians that inherits from Creature.
**
** Implementation file 
*********************************************************************/
#include "Barbarian.hpp" // please see for function descriptions
#include <iostream>		// for status messages

/* Note that default values are sent to Creature's constructor */
Barbarian::Barbarian(int att_num, 	int att_sides, 
					 int def_num, 	int def_sides, 	
					 int arm, 		double str, 	
					 CharType t
					) : Creature(att_num, att_sides, def_num, def_sides, arm, str, t)
{}

double Barbarian::attacks(Creature* target)
{
	/* 	doAttack() will pass rollDice() output to target defend function
		which will inflict the damage */
	return doAttack(target, rollDice(attack));
}

double Barbarian::defend(double attack_val, CharType attacker, bool halve_attack)
{
	/* inflictDamage() will return an double and take care of subtracting from strength */
	return inflictDamage(attack_val, halve_attack);
}
