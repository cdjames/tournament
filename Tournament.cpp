// Team* team1{}
// 	Team* team2{}
// 	Stack* standings{}
// 	Queue* top3{}
// 	CharType strength{}
#include "Tournament.hpp"
#include <iostream>
	
Tournament::Tournament(Team* one, Team* two) : killBonus(10)
{
	team1 = one;
	team2 = two;
	top3 = new Queue;
	standings = new Stack;
	// creature[1] = { "None", "Goblin", "Barbarian", "Reptile", "Blue Man", "The Shadow" };
	creature[0] = "None";
	creature[1] = "Goblin";
	creature[2] = "Barbarian";
	creature[3] = "Reptile";
	creature[4] = "Blue Man";
	creature[5] = "Shadow";
	rounds = 0;
}

Tournament::~Tournament()
{
	if(team1)
		delete team1;
	if(team2)
		delete team2;
	if(top3)
		delete top3;
	if(standings)
		delete standings;
}

void Tournament::doTourney()
{	
	// std::cout << "team1 active members " << team1->getActiveMembers() << std::endl;
	// std::cout << "team2 active members " << team2->getActiveMembers() << std::endl;
	while(team1->getActiveMembers() && team2->getActiveMembers())
	{
		// std::cout << "hi from doTourney()" << std::endl;
		doRound(team1->getFrontMember(), team2->getFrontMember());
	}
}

void Tournament::doRound(Creature* opp1, Creature* opp2)
{
	int opp1_damage = 0;
	int opp2_damage = 0;
	CharType opp1_type = opp1->getType();
	CharType opp2_type = opp2->getType();
	std::string opp1_name = "Player 1 " + creature[opp1_type];
	std::string opp2_name = "Player 2 " + creature[opp2_type];
	rounds++;
	std::cout << "\nRound " << rounds << ": " << opp1_name << " vs " << opp2_name << std::endl;

	while (!opp1->isDead() && !opp2->isDead())
	{
		if(!opp1->isDead())
		{
			opp2_damage = opp1->attacks(opp2);

			if(opp2_damage >= 0)
			{
				team1->addPoints(computePoints(opp1_type, opp2_type, opp2_damage));
				std::cout << opp1_name << " inflicts " << opp2_damage << " damage on " << opp2_name << "." << std::endl;
				std::cout << opp2_name << " strength: " << opp2->getStrength() << std::endl;
			}
			// else 
				// if(opp2_damage == -2)
				// std::cout << opp2_name << " is knocked out." << std::endl;
		}

		if(!opp2->isDead())
		{
			opp1_damage = opp2->attacks(opp1);

			if(opp1_damage >= 0)
			{
				team2->addPoints(computePoints(opp2_type, opp1_type, opp1_damage));
				std::cout << opp2_name << " inflicts " << opp1_damage << " damage on " << opp1_name << "." << std::endl;
				std::cout << opp1_name << " strength: " << opp1->getStrength() << std::endl;
			}
			// else 
				// if(opp1_damage == -2)
				// std::cout << opp1_name << " is knocked out." << std::endl;
		}
	}
	if(opp2->isDead())
	{
		team1->addPoints(killBonus);
		moveToStandings(opp2);
		std::cout << opp1_name << " has killed " << opp2_name << "." << std::endl;
		std::cout << opp1_name << " strength: " << opp1->getStrength() << std::endl;
		// p1kills++;
	}
	else if(opp1->isDead())
	{
		moveToStandings(opp1);
		team2->addPoints(killBonus);
		std::cout << opp2_name << " has killed " << opp1_name << "." << std::endl;
		std::cout << opp2_name << " strength: " << opp2->getStrength() << std::endl;
		// p2kills++;
	}

	team1->moveFighters();
	team2->moveFighters();
}

void Tournament::moveToStandings(Creature* dead_creature)
{
	standings->add(dead_creature);
}

int Tournament::computePoints(CharType attacker_type, CharType defender_type, int damage)
{
	return damage * (attacker_type / defender_type);
}

void Tournament::printStandings(){}

void Tournament::printWinner(){}