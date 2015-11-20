/*********************************************************************
** Author: Collin James
** Date: 11/5/15
** Description: A class for Goblins that inherits from Creature.  
** Overrides Creature's attacks function to implement special move
** 
** Implementation file 
*********************************************************************/
#include "Goblin.hpp"
#include <iostream>		// for status messages
Goblin::Goblin(int att_num, 	int att_sides, 
			   int def_num, 	int def_sides, 	
			   int arm, 		double str, 	
			   CharType t
			  // ) : Barbarian(att_num, att_sides, def_num, def_sides, arm, str, t)
			  ) : Creature(att_num, att_sides, def_num, def_sides, arm, str, t)
{
	halved = 0;
}

Goblin::~Goblin()
{
	/* Message to help graders. Comment out in actual battle. */
	std::cout << "     Goblin halved attacks " << this->halved << " times!" << std::endl;

}

/* Overridden attacks function */
double Goblin::attacks(Creature* target)
{
	double attack_val = rollDice(attack),
		damage;

	/* If Goblin rolls 12, and not fighting a Goblin, then do Special Attack!*/
	if(attack_val == 12 && target->getType() != GOBLIN)
	{
		/* uncomment to display status message! */
		// std::cout << "******* Goblin achilles achieved! *******" << std::endl;
		damage = doAttack(target, attack_val, true); // pass true for "halve_attack" boolean
		halved++;
	}
	else
		damage = doAttack(target, attack_val);

	return damage;
}

/* 	same as Barbarian!! Inherit from Barbarian instead to avoid duplicating 
	Including only for the sake of having all new Creatures inherit from 
	Creature */
double Goblin::defend(double attack_val, CharType attacker, bool halve_attack)
{
	/* inflictDamage() will return a double and take care of subtracting from strength */
	return inflictDamage(attack_val, halve_attack);
}