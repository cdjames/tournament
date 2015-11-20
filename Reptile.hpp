/*********************************************************************
** Author: Collin James
** Date: 11/5/15
** Description: A class for Reptiles that inherits from Creature.  
*********************************************************************/
#ifndef REPTILE_HPP
#define REPTILE_HPP
// #include "CharType.hpp" // included in Creature
// #include "Barbarian.hpp"
#include "Creature.hpp"

// class Reptile : public Barbarian
class Reptile : public Creature
{
protected:
	// all inherited from Creature
public:
	/*********************************************************************
	** Description: 
	** Default constructor. Will pass these values to Creature 
	** constructor. Set default attributes here.
	*********************************************************************/
	Reptile(int att_num=3, 	int att_sides=6, 
			int def_num=1,	int def_sides=6, 	
			int arm=7, 		double str=18, 		
			CharType t=REPTILE
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
};

#endif