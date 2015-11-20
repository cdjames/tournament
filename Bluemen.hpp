/*********************************************************************
** Author: Collin James
** Date: 11/5/15
** Description: A class for Bluemen that inherits from Creature. 
*********************************************************************/
#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP
// #include "CharType.hpp"
// #include "Barbarian.hpp"
#include "Creature.hpp"

// class Bluemen : public Barbarian
class Bluemen : public Creature
{
protected:
	// all inherited from Creature
public:
	/*********************************************************************
	** Description: 
	** Default constructor. Will pass these values to Barbarian 
	** constructor, which will in turn pass to Creature. Set default 
	** attributes here.
	*********************************************************************/
	Bluemen(int att_num=2, 	int att_sides=10, 
			int def_num=3,	int def_sides=6, 	
			int arm=3, 		double str=12, 		
			CharType t=BLUEMEN
		   );

	/*********************************************************************
	** Description: 
	** A function for initiating attacks. Rolls dice and calls doAttack().
	**
	** SAME AS BARBARIAN. Inherit from Barbarian instead to avoid duplicating.
	** Including only for the sake of having all new Creatures inherit from 
	** Creature
	*********************************************************************/
	virtual double attacks(Creature* target);

	/*********************************************************************
	** Description: 
	** A function for initiating defense. Returns damage amount via 
	** inflictDamage(); 
	**
	** SAME AS BARBARIAN. Inherit from Barbarian instead to avoid duplicating.
	** Including only for the sake of having all new Creatures inherit from 
	** Creature
	*********************************************************************/
	virtual double defend(double attack_val, CharType attacker, bool halve_attack = false);

	/* Implements knocked out feature; not needed for current assignment */
	// virtual double defend(double attack_val, CharType attacker, bool halve_attack);
};


#endif