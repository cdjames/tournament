/*********************************************************************
** Author: Collin James
** Date: 11/5/15
** Description: A class for Goblins that inherits from Creature.  
** Overrides Creature's attacks function to implement special move
*********************************************************************/
#ifndef GOBLIN_HPP
#define GOBLIN_HPP
// #include "CharType.hpp"
// #include "Barbarian.hpp"
#include "Creature.hpp"

// class Goblin : public Barbarian
class Goblin : public Creature
{
protected:
	int halved;
	// all other inherited from Creature
public:
	/*********************************************************************
	** Description: 
	** Default constructor. Will pass these values to Creature 
	** constructor. Set default attributes here.
	*********************************************************************/
	Goblin(int att_num=2, 	int att_sides=6, 
		   int def_num=1,	int def_sides=6, 	
		   int arm=3, 		double str=8, 		
		   CharType t=GOBLIN
		  );

	/*********************************************************************
	** Description: 
	** Deconstructor. Display a message for testing purposes.
	*********************************************************************/
	~Goblin();

	/*********************************************************************
	** Description: 
	** Override attacks function to implement special move. If goblin rolls
	** a 12, halve the opponents attack attribute.
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