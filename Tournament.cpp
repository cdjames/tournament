
#include "Tournament.hpp"
#include <iostream>
#include <math.h> // for ceil()
	
Tournament::Tournament(Team* one, Team* two, int fighters) : killBonus(50)
{
	team1 = one;
	team2 = two;
	top3 = new Stack;
	standings = new Stack;
	team = new IntStack;
	top3team = new IntStack;
	creature[0] = "None";
	creature[1] = "Goblin";
	creature[2] = "Barbarian";
	creature[3] = "Shadow";
	creature[4] = "Reptile";
	creature[5] = "Blue Man";
	this->fighters = fighters;
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
	if(team)
		delete team;
	if(top3team)
		delete top3team;
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
	int opp1_damage, opp2_damage, p1kills, p2kills, rounds;
	p1kills = p2kills = opp1_damage = opp2_damage = rounds = 0;
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
			// std::cout << opp1_name << " inflicts " << opp2_damage << " damage on " << opp2_name << "." << std::endl;
			// std::cout << opp2_name << " strength: " << opp2->getStrength() << std::endl;

			if(opp2_damage > 0)
			{
				team1->addPoints(computePoints(opp1_type, opp2_type, opp2_damage));
				// std::cout << "team 1 has " << team1->addPoints(computePoints(opp1_type, opp2_type, opp2_damage)) << " points" << std::endl;
				
			}
			// else 
				// if(opp2_damage == -2)
				// std::cout << opp2_name << " is knocked out." << std::endl;
		}

		if(!opp2->isDead())
		{
			opp1_damage = opp2->attacks(opp1);
			// std::cout << opp2_name << " inflicts " << opp1_damage << " damage on " << opp1_name << "." << std::endl;
			// std::cout << opp1_name << " strength: " << opp1->getStrength() << std::endl;

			if(opp1_damage > 0)
			{
				// std::cout << "team 2 has " << team2->addPoints(computePoints(opp2_type, opp1_type, opp1_damage)) << " points" << std::endl;
				team2->addPoints(computePoints(opp2_type, opp1_type, opp1_damage));
				
			}
			// else 
				// if(opp1_damage == -2)
				// std::cout << opp1_name << " is knocked out." << std::endl;
		}
	}
	if(opp2->isDead())
	{
		team1->addPoints(killBonus);
		// std::cout << "team 1 has " << team1->addPoints(killBonus) << " points" << std::endl;
		moveToStandings(opp2, 2);
		std::cout << "    " << opp1_name << " has killed " << opp2_name << "." << std::endl;
		// std::cout << opp1_name << " strength: " << opp1->getStrength() << std::endl;
		// p1kills++;
	}
	else if(opp1->isDead())
	{
		moveToStandings(opp1, 1);
		team2->addPoints(killBonus);
		// std::cout << "team 2 has " << team2->addPoints(killBonus) << " points" << std::endl;
		std::cout << "    " << opp2_name << " has killed " << opp1_name << "." << std::endl;
		// std::cout << opp2_name << " strength: " << opp2->getStrength() << std::endl;
		// p2kills++;
		// std::cout << 
	}

	team1->moveFighters();
	team2->moveFighters();
}

void Tournament::moveToStandings(Creature* dead_creature, int team_num)
{
	standings->add(dead_creature);
	team->add(team_num);
}

int Tournament::computePoints(CharType attacker_type, CharType defender_type, int damage)
{
	// std::cout << "damage is " << damage << "; defender / attacker = " << static_cast<double>(static_cast<double>(defender_type) / static_cast<double>(attacker_type)) << std::endl;
	// std::cout << "points is " << ceil(damage * static_cast<double>(static_cast<double>(defender_type) / static_cast<double>(attacker_type))) << std::endl;
	// return damage * (defender_type / attacker_type);
	double award_ratio = static_cast<double>(defender_type) / static_cast<double>(attacker_type);
	return ceil(damage * award_ratio);
}

void Tournament::printStandings()
{
	int count = 0,
		team_num = team->remove();
	Creature* tempCr = standings->remove();

	std::cout << "\n" << "Standings:" << std::endl;
	while(tempCr != NULL)
	{
		count++;
		std::cout << creature[tempCr->getType()] << " from team " << team_num << " was " 
				  << count << ((count == 1) ? "st" : ((count == 2) ? "nd" : ((count == 3) ? "rd" : "th"))) 
				  << " place." << std::endl;
		tempCr = standings->remove();
		team_num = team->remove();
	}
}

void Tournament::printWinner()
{
	if(team1->getActiveMembers())
		finishStandings(team1);
	if(team2->getActiveMembers())
		finishStandings(team2);
	Creature* tempCr;
	int team_num;
	int top_num = (fighters < 3) ? fighters : 3;

	std::cout << "\n" << "Top " << top_num << ":" << std::endl;
	for (int i = 1; i < top_num+1; i++)
	{
		tempCr = standings->remove();
		team_num = team->remove();
		std::cout << creature[tempCr->getType()] << " from team " << team_num << " is " 
				<< i << ((i == 1) ? "st" : ((i == 2) ? "nd" : ((i == 3) ? "rd" : "th")))
				<< " place." << std::endl;
		top3->add(tempCr);
		top3team->add(team_num);
	}
	for (int i = 0; i < top_num; i++)
	{
		standings->add(top3->remove());
		team->add(top3team->remove());
	}

	int team1_pts = team1->getPoints(),
	 	team2_pts = team2->getPoints(),
		winner, loser, winner_pts, loser_pts;

	std::cout << "\n" << "Outcome:" << std::endl;
	if(team1_pts > team2_pts)
	{
		winner = team1->getNumber();
		loser = team2->getNumber();
		winner_pts = team1_pts;
		loser_pts = team2_pts;
		std::cout << "The winner was Team " << winner << " with " 
				  << winner_pts << " points."  << std::endl;
		std::cout << "Team " << loser << " had " 
				  << loser_pts << " points."  << std::endl;
	}
	else if(team1_pts < team2_pts)
	{
		winner = team2->getNumber();
		loser = team1->getNumber();
		winner_pts = team2_pts;
		loser_pts = team1_pts;
		std::cout << "The winner was Team " << winner << " with " 
				  << winner_pts << " points."  << std::endl;
		std::cout << "Team " << loser << " had " 
				  << loser_pts << " points."  << std::endl;
	}
	else
		std::cout << "It was a tie. Both teams had " << team1_pts << " points." << std::endl;
}

void Tournament::finishStandings(Team* team)
{
	while(team->getActiveMembers())
	{
		// std::cout << "in finishStandings, active members is "<< team->getActiveMembers() << std::endl;
		moveToStandings(team->releaseFrontMember(), team->getNumber());
	}
}