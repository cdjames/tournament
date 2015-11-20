/*********************************************************************
** Author: Collin James
** Date: 11/5/15
** Description: A class for Barbarians that inherits from Creature.
*********************************************************************/
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP
// #include "CharType.hpp" // included in Creature.hpp
#include "Creature.hpp"

class Barbarian : public Creature
{
protected:
	// all inherited from Creature
public:
	/*********************************************************************
	** Description: 
	** Default constructor. Will pass these values to Creature constructor.
	** Set default attributes here.
	*********************************************************************/
	Barbarian(int att_num=2, 	int att_sides=6, 
			  int def_num=2,	int def_sides=6, 	
			  int arm=0, 		double str=12, 		
			  CharType t=BARB
			 );

	/*********************************************************************
	** Description: 
	** A function for initiating attacks. Rolls dice and calls doAttack().
	**
	** SAME IN REPTILE, BLUEMEN, SHADOW! Have them inherit from Barbarian
	** to avoid duplicating
	*********************************************************************/
	virtual double attacks(Creature* target);

	/*********************************************************************
	** Description: 
	** A function for initiating defense. Returns damage amount via 
	** inflictDamage();
	**
	** SAME IN REPTILE, BLUEMEN, GOBLIN! Have them inherit from Barbarian
	** to avoid duplicating
	*********************************************************************/
	virtual double defend(double attack_val, CharType attacker, bool halve_attack = false);
};

#endif