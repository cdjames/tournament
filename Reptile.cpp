/*********************************************************************
** Author: Collin James
** Date: 11/5/15
** Description: A class for Reptiles that inherits from Creature. 
**
** Implementation file 
*********************************************************************/
#include "Reptile.hpp"
#include <iostream>

/* Note that default values are sent to Creature's constructor */
Reptile::Reptile(int att_num, 	int att_sides, 
				 int def_num, 	int def_sides, 	
				 int arm, 		double str, 	
				 CharType t
				// ) : Barbarian(att_num, att_sides, def_num, def_sides, arm, str, t)
				) : Creature(att_num, att_sides, def_num, def_sides, arm, str, t)
{}

/* 	same as Barbarian!! Inherit from Barbarian instead to avoid duplicating 
	Including only for the sake of having all new Creatures inherit from 
	Creature */
double Reptile::attacks(Creature* target)
{
	/* 	doAttack() will pass rollDice() output to target defend function
		which will inflict the damage */
	return doAttack(target, rollDice(attack));
}

/* 	same as Barbarian!! Inherit from Barbarian instead to avoid duplicating 
	Including only for the sake of having all new Creatures inherit from 
	Creature */
double Reptile::defend(double attack_val, CharType attacker, bool halve_attack)
{
	/* inflictDamage() will return an double and take care of subtracting from strength */
	return inflictDamage(attack_val, halve_attack);
}