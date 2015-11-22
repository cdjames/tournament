/*********************************************************************
** Author: Collin James
** Date: 11/20/15
** Description: A class to carry out a tournament between two teams of 
** Creatures.
**
** Implementation
*********************************************************************/

#include "Tournament.hpp" // please see for function descriptions
#include <iostream>
#include <math.h> // for ceil()
	
Tournament::Tournament(Team* one, Team* two, int fighters) : killBonus(50) // set bonus points
{
	this->team1 = one;				// team 1
	this->team2 = two;				// team 2
	this->top3 = new Stack;			// make empty stacks
	this->standings = new Stack;
	this->team = new IntStack;
	this->top3team = new IntStack;
	this->creature[0] = "None";		// names for creatures
	this->creature[1] = "Goblin";
	this->creature[2] = "Barbarian";
	this->creature[3] = "Shadow";
	this->creature[4] = "Reptile";
	this->creature[5] = "Blue Man";
	this->fighters = fighters;		// number of fighters
	this->rounds = 0;				// rounds at 0; incremented by doRound()
}

Tournament::~Tournament()
{
	/* delete pointers */
	if(this->team1)
		delete this->team1;
	if(this->team2)
		delete this->team2;
	if(this->top3)
		delete this->top3;
	if(this->standings)
		delete this->standings;
	if(this->team)
		delete this->team;
	if(this->top3team)
		delete this->top3team;
}

void Tournament::doTourney()
{	
	// std::cout << "team1 active members " << team1->getActiveMembers() << std::endl;
	// std::cout << "team2 active members " << team2->getActiveMembers() << std::endl;

	/* loop while both teams still have active members and do another round*/
	while(this->team1->getActiveMembers() && this->team2->getActiveMembers())
		doRound(this->team1->getFrontMember(), this->team2->getFrontMember());
}

void Tournament::doRound(Creature* opp1, Creature* opp2)
{
	int opp1_damage, opp2_damage; 	//, p1kills, p2kills; // kills not currently used
	opp1_damage = opp2_damage = 0;	// set damage at 0
	CharType opp1_type = opp1->getType(),	// creature types
		 	 opp2_type = opp2->getType();
	std::string opp1_name = "Team 1 " + this->creature[opp1_type],	// names of creatures
				opp2_name = "Team 2 " + this->creature[opp2_type];
	/* increment rounds and declare start of rounds*/
	this->rounds++;
	std::cout << "\nRound " << this->rounds << ": " << opp1_name << " vs " << opp2_name << std::endl;
	
	/* carry out attacks while the opponents are still alive */
	while (!opp1->isDead() && !opp2->isDead())
	{
		/* check again for life before attacking; Player 1 attack! */
		if(!opp1->isDead())
		{
			opp2_damage = opp1->attacks(opp2);
			// std::cout << opp1_name << " inflicts " << opp2_damage << " damage on " << opp2_name << "." << std::endl;
			// std::cout << opp2_name << " strength: " << opp2->getStrength() << std::endl;

			/* if the damage is greater than 0, figure out points and add to appropriate team */
			if(opp2_damage > 0)
			{
				this->team1->addPoints(computePoints(opp1_type, opp2_type, opp2_damage));
				// std::cout << "team 1 has " << team1->addPoints(computePoints(opp1_type, opp2_type, opp2_damage)) << " points" << std::endl;
				
			}
		}
		/* check again for life before attacking; Player 1 attack! */
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
		}
	}

	/* fight is over, so add bonus points for kills and move dead creatures to standings */
	if(opp2->isDead())
	{
		this->team1->addPoints(killBonus);
		// std::cout << "team 1 has " << team1->addPoints(killBonus) << " points" << std::endl;
		moveToStandings(opp2, 2);
		std::cout << "    " << opp1_name << " has killed " << opp2_name << "." << std::endl;
		// std::cout << opp1_name << " strength: " << opp1->getStrength() << std::endl;
		// p1kills++;
	}
	else if(opp1->isDead())
	{
		moveToStandings(opp1, 1);
		this->team2->addPoints(killBonus);
		// std::cout << "team 2 has " << team2->addPoints(killBonus) << " points" << std::endl;
		std::cout << "    " << opp2_name << " has killed " << opp1_name << "." << std::endl;
		// std::cout << opp2_name << " strength: " << opp2->getStrength() << std::endl;
		// p2kills++;
	}

	/* Team::moveFighters(); moves them to back of team's Queue if alive, back of Team's loser stack if dead */
	this->team1->moveFighters();
	this->team2->moveFighters();
}

void Tournament::moveToStandings(Creature* dead_creature, int team_num)
{
	/* move dead creatures to standings, their team number to team Stack*/
	this->standings->add(dead_creature);
	this->team->add(team_num);
}

int Tournament::computePoints(CharType attacker_type, CharType defender_type, int damage)
{
	// std::cout << "damage is " << damage << "; defender / attacker = " << static_cast<double>(static_cast<double>(defender_type) / static_cast<double>(attacker_type)) << std::endl;
	// std::cout << "points is " << ceil(damage * static_cast<double>(static_cast<double>(defender_type) / static_cast<double>(attacker_type))) << std::endl;
	
	/* Award ratio is determined by defender type ÷ attacker type • damage 
	 * Thus, if a Goblin attacks a Blue Man and does 2 damage, the final result
	 * would be 2 • 5 ÷ 1, or 10 points. The Blue Man has a higher status than Goblin
	 * and so the Goblin earns more points with a successful attack.
	 * If a Blue Man had done 10 pts of damage against a Goblin, the result would be
	 * 10 • 1 ÷ 5, or 2 points. */
	double award_ratio = static_cast<double>(defender_type) / static_cast<double>(attacker_type);
	return ceil(damage * award_ratio); // gets cast as int upon return
}

void Tournament::printStandings()
{
	int count = 0,									// keep track of place
		team_num = this->team->remove();			// get top creature team number
	Creature* tempCr = this->standings->remove();	// get top creature

	/* Announce and loop until standings Stack is empty*/
	std::cout << "\n" << "Standings:" << std::endl;
	while(tempCr != NULL)
	{
		count++;
		/* Print creature type and team # and place */
		std::cout << this->creature[tempCr->getType()] << " from team " << team_num << " was " 
				  /* if 1 add st, else if 2 add nd, else if 3 add rd, else add th */
				  << count << ((count == 1) ? "st" : ((count == 2) ? "nd" : ((count == 3) ? "rd" : "th"))) 
				  << " place." << std::endl;
		/* get another creatuure and its team (or perhaps NULL if empty) */
		tempCr = this->standings->remove();
		team_num = this->team->remove();
	}
}

void Tournament::printWinner()
{
	/* before doing anything, make sure standings Stack contains all creatures 
	 * Clear out active members with finishStandings() */
	if(team1->getActiveMembers())
		finishStandings(team1);
	if(team2->getActiveMembers())
		finishStandings(team2);
	
	Creature* tempCr;
	int team_num,
		/* make sure that if there are less than 3 fighters, that you don't
		 * print top 3 (will result in seg. fault) */
	 	top_num = (fighters < 3) ? fighters : 3;

	/* announce and print top 3 creatures. Put them in top3 Stack for temporary storage */
	std::cout << "\n" << "Top " << top_num << ":" << std::endl;
	for (int i = 1; i < top_num+1; i++)
	{
		tempCr = this->standings->remove();
		team_num = this->team->remove();
		std::cout << this->creature[tempCr->getType()] << " from team " << team_num << " is " 
				<< i << ((i == 1) ? "st" : ((i == 2) ? "nd" : ((i == 3) ? "rd" : "th")))
				<< " place." << std::endl;
		this->top3->add(tempCr);
		this->top3team->add(team_num);
	}
	/* Put creatures from top3 Stack back into standings stack in case printStandings() is called */
	for (int i = 0; i < top_num; i++)
	{
		this->standings->add(this->top3->remove());
		this->team->add(this->top3team->remove());
	}
	/* Get the final point total from teams */
	int team1_pts = this->team1->getPoints(),
	 	team2_pts = this->team2->getPoints(),
		winner, loser, winner_pts, loser_pts;
	/* If team 1 won, print the outcome. */
	std::cout << "\n" << "Outcome:" << std::endl;
	if(team1_pts == team2_pts)
		std::cout << "It was a tie. Both teams had " << team1_pts << " points." << std::endl;
	else
	{
		/* If team 1 won, set variables accordingly */
		if(team1_pts > team2_pts)
		{
			winner = this->team1->getNumber();
			loser = this->team2->getNumber();
			winner_pts = team1_pts;
			loser_pts = team2_pts;
		}
		/* If team 2 won, set variables accordingly */
		else
		{
			winner = this->team2->getNumber();
			loser = this->team1->getNumber();
			winner_pts = team2_pts;
			loser_pts = team1_pts;
		}
		/* print the outcome */
		std::cout << "The winner was Team " << winner << " with " 
				  << winner_pts << " points."  << std::endl;
		std::cout << "Team " << loser << " had " 
				  << loser_pts << " points."  << std::endl;
	}
}

void Tournament::finishStandings(Team* team)
{
	/* Move players out of team and into standings until there are no active members */
	while(team->getActiveMembers())
	{
		// std::cout << "in finishStandings, active members is "<< team->getActiveMembers() << std::endl;
		moveToStandings(team->releaseFrontMember(), team->getNumber());
	}
}