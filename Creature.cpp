/*********************************************************************
** Author: Collin James
** Date: 11/5/15
** Description: An abstract base class for different game creatures,
** with a default constructor, various getters, and a function for
** generating dice rolls. Contains pure virtual attack and defend
** functions; these need to be defined in derived classes.
** 
** Implementation file 
*********************************************************************/
#include "Creature.hpp" // please see for function descriptions
#include <iostream> // for testing

Creature::Creature(int att_num, 	int att_sides, 
				   int def_num, 	int def_sides, 	
				   int arm, 		double str, 	
				   CharType t
				  )
{
	/* set default values */
	attack.num = att_num;
	attack.sides = att_sides;
	defense.num = def_num;
	defense.sides = def_sides;
	armor = arm;
	strength = orig_strength = str;
	type = t;
	is_dead = attack_halved = is_knocked_out = false;
}

Creature::~Creature() // empty deconstructor
{
	// std::cout << "A Creature died." << std::endl;
}

int Creature::rollDice(DieVal roll_data) const
{	
	// std::cout << "roll_data.num: " << roll_data.num << "    ";
	// std::cout << "roll_data.sides: " << roll_data.sides << std::endl;

	int roll = 0;
	/* repeat for number of dice */
	for (int i = 0; i < roll_data.num; i++)
	{
		/* add random roll for number of sides to final roll */
		roll += (1 + rand() % roll_data.sides);
		// std::cout << "roll " << i << ": " << roll << std::endl;
	}
	// roll = 12; // testing
	return roll;
}

/* Note: Pure virtual attack and defend functions to be created in derived classes */

// double Creature::inflictDamage(double attack_val, double defense_val)
double Creature::inflictDamage(double attack_val, bool halve_attack)
{
	int defense_val;

	/* 	If attack has not previously been halved and something is trying to halve it,
		then set attribute to true. Note that this won't run in the future because we
		don't want it set back to false, which is the function default */
	if(!attack_halved && halve_attack)
		attack_halved = halve_attack;

	defense_val = rollDice(defense);
	/* subtract the defense value and armor value from attack value */
	double damage = (attack_val - defense_val) - armor;
	/* if the damage is negative, there was no damage done, so set to 0 */
	if(damage <= 0)
		damage = 0;
	else
		damage = computeStrength(damage); // only run if damage is positive double
	
	return damage;
}

double Creature::computeStrength(double damage)
{
	this->strength -= damage; 	// subtract damage

	if(this->strength <= 0) 	// i.e., if dead!
	{
		// std::cout << "damage is " << damage << "    strength is: " << strength << std::endl;
		/* adjust the damage to be no greater than previous strength */
		damage += this->strength;
		// std::cout << "final damage: " << damage << std::endl;
		this->strength = 0; 	// don't allow negative strength values
		this->is_dead = true;	// set flag for isDead()
	}

	return damage; 				
}

double Creature::doAttack(Creature* target, double attack_val, bool halve_attack)
{
	double damage;

	// if(!is_knocked_out) // for knocking out blueman
	// {

	/* If the creature has had its attack halved */
	if(attack_halved)
	{
		attack_val /= 2; 
		/* uncomment to display status message! */
		// std::cout << "* * * attack halved! * * *" << std::endl;
	}
	// std::cout << "attack_val: " << attack_val << std::endl;

	/* Inflict the damage and get the result */
	damage = target->defend(attack_val, this->type, halve_attack);

	return damage;
	// }
	// else
	// 	return -2; // creature is knocked out
}

/* Getters */
bool Creature::isDead() const
{
	return is_dead;
}

bool Creature::isKnockedOut() const
{
	return is_knocked_out;
}

double Creature::getStrength() const
{
	return strength;
}

/* for testing */
int Creature::getRoll(DieVal die) const
{
	return rollDice(die); // pass it an object's DieVal struct
}

CharType Creature::getType() const
{
	return type;
}

/* for testing */
void Creature::listStats() const
{
	std::string creature[6] = { "None", "Goblin", "Barbarian", "Reptile", "Blue Man", "The Shadow" };
	
	std::cout << "\ntype: " << creature[type] << std::endl;
	std::cout << "attack.num: " << attack.num << std::endl;
	std::cout << "attack.sides: " << attack.sides << std::endl;
	std::cout << "defense.num: " << defense.num << std::endl;
	std::cout << "defense.sides: " << defense.sides << std::endl;
	std::cout << "armor: " << armor << std::endl;
	std::cout << "strength: " << strength << std::endl;
	std::cout << "sample attack roll: " << getRoll(this->attack) << std::endl;
	std::cout << "sample defense roll: " << getRoll(this->defense) << std::endl;
	// std::cout << ""is_dead = 
	// std::cout << ""attack_halved = is_knocked_out = false;
}

void Creature::revive()
{
	strength = orig_strength;
	is_dead = attack_halved = is_knocked_out = false;
}

int Creature::heal(int factor)
{
	int heal_amount;
	heal_amount = (orig_strength - strength) / factor; // factor will be 2 by default
	this->strength += heal_amount;
	return this->strength;
}

void Creature::kill()
{
	computeStrength(orig_strength);
}