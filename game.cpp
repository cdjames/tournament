/*********************************************************************
** Author: Collin James
** Date: 11/5/15
** Description: A testing program for Creature and derived classes.
** Ensure that attributes for each class are different, and that battle
** win and loss statistics for the battle pairings are realistic
** based on attributes.
*********************************************************************/

#include <iostream>
#include "Creature.hpp"
#include "Barbarian.hpp"
#include "Reptile.hpp"
#include "Bluemen.hpp"
#include "Goblin.hpp"
#include "Shadow.hpp"
#include <stdlib.h>		// for srand()
#include <string>
#include <ctime>		// for time()
// #include <unistd.h>

/*********************************************************************
** Description: 
** One on one fight.
*********************************************************************/
void doFight(Creature *opp1, Creature *opp2, std::string creature[], int &p1kills, int &p2kills);

/*********************************************************************
** Description: 
** One creature fights an array of NUMOPPS creatures
*********************************************************************/
void doFight(Creature *opp1, Creature *opp2[], std::string creature[], int NUMOPPS);

/*********************************************************************
** Description: 
** Main function for testing Creature classes. List the attributes for
** each creature. Aggregate 100 fights and record and pring the number of
** wins for each combatant. Ensure that each type of creature battles
** each other type.
*********************************************************************/
int main()
{
	srand(std::time(0)); // seed the random number generator used Creature die function
	const int NUMBLUES = 5;
	std::string creature[6] = { "None", "Goblin", "Barbarian", "Reptile", "Blue Man", "The Shadow" };
	std::string creature2[6] = { "None", "The Shadow", "Blue Man", "Barbarian", "Reptile", "Goblin"  };
	int p1kills = 0,
		p2kills = 0,
		num_battles = 0;

	// Creature *conan = new Barbarian;
	// Creature *highlander = new Barbarian;
	// Creature *snake = new Reptile;
	// Creature *blue = new Bluemen;
	// Creature *blue2 = new Bluemen;
	// Creature *blue3 = new Bluemen;
	// Creature *goblin = new Goblin;
	// Creature *hobgoblin = new Goblin;
	// Creature *shadow = new Shadow;
	// Creature *shadow2 = new Shadow;
	// Creature *bluemen[NUMBLUES] = { new Bluemen, new Bluemen, new Bluemen };
	// Creature *group[NUMBLUES] = { new Goblin, new Barbarian, new Reptile, new Bluemen, new Shadow };
	Creature *group[NUMBLUES] = { new Goblin, new Barbarian, new Reptile, new Bluemen, new Shadow };
	// Creature *group2[NUMBLUES] = { new Shadow, new Bluemen, new Barbarian, new Reptile, new Goblin };
	Creature *group2[NUMBLUES] = { new Shadow, new Bluemen, new Barbarian, new Reptile, new Goblin };

	/* Some initial testing */
	// std::cout << "Creature strength: " << testCreature.getStrength() << std::endl;
	// std::cout << "Conan strength: " << conan->getStrength() << std::endl;
	// std::cout << "Barbarian strength: " << highlander->getStrength() << std::endl;
	// std::cout << "Snake strength: " << snake->getStrength() << std::endl;
	// std::cout << "Barbarian attack roll: " << getRoll() << std::endl;
	
	/* One on one fight! */
	doFight(group[1], group[0], creature, p1kills, p2kills);
	
	/* One on 5 fight! */
	// doFight(shadow, group, creature, NUMBLUES);

	/* Print out each Creature's attribute */
	// for (int i = 0; i < NUMBLUES; i++)
	// {
	// 	group[i]->listStats();
	// }

	// /* Aggregate fights */
	// std::cout << "--------------FIGHT!--------------" << std::endl;
	// for (int x = 0; x < 5; x++)
	// {
	// 	for (int i = 0; i < 5; i++)
	// 	{			
	// 		for (int y = 0; y < 100; y++)
	// 		{
	// 			doFight(group[x], group2[i], creature, p1kills, p2kills);
	// 			group[x]->revive();
	// 			group2[i]->revive();
	// 			num_battles++;
	// 		}
	// 		std::cout << creature[x+1] << "1 won " << p1kills << " times.\n";
	// 		std::cout << creature2[i+1] << "2 won " << p2kills << " times.\n" << std::endl;
	// 		p1kills = p2kills = 0;
	// 	}
	// }

	// delete conan;
	// delete highlander;
	// delete snake;
	// delete blue;
	// delete blue2;
	// delete blue3;
	// delete goblin;
	// delete hobgoblin;
	// delete shadow;
	// delete shadow2;
	// std::cout << "In " << num_battles << " battles, " << NUMBLUES * 100 << " of which each creature fought in," << std::endl;
	for (int i = 0; i < NUMBLUES; i++)
	{
		delete group[i];
		delete group2[i];
	}
}

void doFight(Creature *opp1, Creature *opp2, std::string creature[], int &p1kills, int &p2kills)
{
	int opp1_damage = 0;
	int opp2_damage = 0;
	std::string opp1_name = creature[opp1->getType()];
	std::string opp2_name = creature[opp2->getType()] + "2";
	
	while (!opp1->isDead() && !opp2->isDead())
	{
		if(!opp1->isDead() && !opp1->isKnockedOut())
		{
			opp2_damage = opp1->attacks(opp2);

			if(opp2_damage > 0 && !opp2->isDead())
			{
				opp2->heal();
			}
				std::cout << opp1_name << " inflicts " << opp2_damage << " damage on " << opp2_name << "." << std::endl;
				std::cout << opp2_name << " strength: " << opp2->getStrength() << std::endl;
			// }
			// else 
				// if(opp2_damage == -2)
				// std::cout << opp2_name << " is knocked out." << std::endl;
		}

		if(!opp2->isDead() && !opp2->isKnockedOut())
		{
			opp1_damage = opp2->attacks(opp1);

			// if(opp1_damage >= 0)
			// {
				std::cout << opp2_name << " inflicts " << opp1_damage << " damage on " << opp1_name << "." << std::endl;
				std::cout << opp1_name << " strength: " << opp1->getStrength() << std::endl;
			// }
			// else 
				// if(opp1_damage == -2)
				// std::cout << opp1_name << " is knocked out." << std::endl;
		}
	}
	if(opp2->isDead())
	{
		std::cout << opp1_name << " has killed " << opp2_name << "." << std::endl;
		std::cout << opp1_name << " strength: " << opp1->getStrength() << std::endl;
		p1kills++;
	}
	else if(opp1->isDead())
	{
		std::cout << opp2_name << " has killed " << opp1_name << "." << std::endl;
		std::cout << opp2_name << " strength: " << opp2->getStrength() << std::endl;
		p2kills++;
	}
}

// void doFight(Creature *opp1, Creature *opps[], std::string creature[], int NUMOPPS)
// {
// 	int opp1_damage = 0;
// 	int opp2_damage = 0;
// 	int opp1_kills = 0;
// 	std::string opp1_name = creature[opp1->getType()];
	
// 	bool battle_won = false;
// 	while (!opp1->isDead() && !battle_won)
// 	{
// 		for (int i = 0; i < NUMOPPS && !battle_won; i++)
// 		{
// 			std::string opp2_name = creature[opps[i]->getType()];
// 			if(!opps[i]->isDead())
// 			{
// 				if(!opp1->isDead() && !opp1->isKnockedOut())
// 				{
// 					opp2_damage = opp1->attacks(opps[i]);

// 					// if(opp2_damage >= 0)
// 					// {
// 						std::cout << opp1_name << " inflicts " << opp2_damage << " damage on " << opp2_name << " " << i+1 << "." << std::endl;
// 						std::cout << opp2_name << " " << i+1 << " strength: " << opps[i]->getStrength() << std::endl;
// 					// }
// 					// else 
// 						if(opp2_damage == -2)
// 						std::cout << opp2_name << " " << i+1 << " is knocked out." << std::endl;
// 				}

// 				if(!opps[i]->isDead() && !opps[i]->isKnockedOut())
// 				{
// 					opp1_damage = opps[i]->attacks(opp1);

// 					// if(opp1_damage >= 0)
// 					// {
// 						std::cout << opp2_name << " " << i+1 << " inflicts " << opp1_damage << " damage on " << opp1_name << "." << std::endl;
// 						std::cout << opp1_name << " strength: " << opp1->getStrength() << std::endl;
// 					// }
// 					// else 
// 						if(opp1_damage == -2)
// 						std::cout << opp1_name << " is knocked out." << std::endl;
// 				}
			

// 				if(opps[i]->isDead())
// 				{
// 					std::cout << opp1_name << " has killed " << opp2_name << " " << i+1 << "." << std::endl;
// 					std::cout << opp1_name << " strength: " << opp1->getStrength() << std::endl;
// 					opp1_kills++;
// 					std::cout << "opp1_kills: " << opp1_kills << std::endl;
// 					if(opp1_kills == NUMOPPS)
// 						battle_won = true;
// 				}
// 				if(opp1->isDead())
// 				{
// 					battle_won = true;
// 					std::cout << opp2_name << " " << i+1 << " has killed " << opp1_name << "." << std::endl;
// 					for (int x = 0; x < NUMOPPS; x++)
// 					{
// 						std::cout << creature[opps[x]->getType()] << " " << x+1 << " strength: " << opps[x]->getStrength() << std::endl;
// 					}
// 				}
// 			}
// 		}
// 	}
// }
