/*********************************************************************
** Author: Collin James
** Date: 11/5/15
** Description: A class for Bluemen that inherits from Creature via
** Barbarian, with a default constructor. 
** 
** Implementation file 
*********************************************************************/
#include "Bluemen.hpp"
#include <iostream>

/* Note that default values are sent to Creature's constructor via Barbarian */

Bluemen::Bluemen(int att_num, 	int att_sides, 
				 int def_num, 	int def_sides, 	
				 int arm, 		double str, 	
				 CharType t
				// ) : Barbarian(att_num, att_sides, def_num, def_sides, arm, str, t)
				) : Creature(att_num, att_sides, def_num, def_sides, arm, str, t)
{}

/* 	same as Barbarian!! Inherit from Barbarian instead to avoid duplicating 
	Including only for the sake of having all new Creatures inherit from 
	Creature */
double Bluemen::attacks(Creature* target)
{
	/* 	doAttack() will pass rollDice() output to target defend function
		which will inflict the damage */
	return doAttack(target, rollDice(attack));
}

/* 	same as Barbarian!! Inherit from Barbarian instead to avoid duplicating 
	Including only for the sake of having all new Creatures inherit from 
	Creature */
double Bluemen::defend(double attack_val, CharType attacker, bool halve_attack)
{
	/* inflictDamage() will return an double and take care of subtracting from strength */
	return inflictDamage(attack_val, halve_attack);
}

/* 	redefined defend function that actually knocks blue men out.
	comment out to have same defend behavior as Barbarian */

// double Bluemen::defend(double attack_val, CharType attacker, bool halve_attack)
// {
// 	double damage,
// 		defense_val;
// 	if(!is_knocked_out && halve_attack)
// 	{
// 		is_knocked_out = true;
// 		std::cout << "** ** knocked out! ** **" << std::endl;
// 	}

// 	if(is_knocked_out)
// 	{
// 		damage = attack_val - armor;
// 		// is_knocked_out = false; // wake up when hit
// 	}
// 	else
// 	{
// 		defense_val = rollDice(defense);
// 		// std::cout << "defense_val: " << defense_val << std::endl;
// 		damage = (attack_val - defense_val) - armor;
// 	}

// 	if(damage < 0)
// 		damage = 0;

// 	strength -= damage;

// 	if(strength <= 0)
// 	{
// 		damage += strength;
// 		strength = 0;
// 		is_dead = true;
// 		// damage = -1;
// 	}

// 	return damage;
// }