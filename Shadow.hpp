/*********************************************************************
** Author: Collin James
** Date: 11/5/15
** Description: A class for Shadows that inherits from Creature.
** Overrides Creature's defend function to implement special move.
*********************************************************************/
#ifndef SHADOW_HPP
#define SHADOW_HPP
// #include "CharType.hpp"
// #include "Barbarian.hpp"
#include "Creature.hpp"

// class Shadow : public Barbarian
class Shadow : public Creature
{
protected:
	int disappeared;
	// all inherited from Creature
public:
	/*********************************************************************
	** Description: 
	** Default constructor. Will pass these values to Creature 
	** constructor. Set default attributes here.
	*********************************************************************/
	Shadow(double att_num=2, 	double att_sides=10, 
		   double def_num=1,	double def_sides=6, 	
		   double arm=0, 		double str=12, 		
		   CharType t=SHADOW
		  );

	/*********************************************************************
	** Description: 
	** Deconstructor. Display a message for testing purposes.
	*********************************************************************/
	~Shadow();

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
	** Override defend function to implement special move. 50% chance that
	** shadow will disappear on any given attack
	*********************************************************************/
	virtual double defend(double attack_val, CharType attacker, bool halve_attack = false);
};

#endif