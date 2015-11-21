/*********************************************************************
** Author: Collin James
** Date: 11/20/15
** Description: A class to carry out a tournament between two teams of 
** Creatures.
*********************************************************************/

#ifndef TOURNAMENT_HPP
#define TOURNAMENT_HPP
#include "Team.hpp"
#include "Creature.hpp"
#include "Stack.hpp"
#include "IntStack.hpp"
#include "Queue.hpp"
#include <string>
// #include "CharType.hpp" // already included in Creature

class Tournament
{
private:
	Team* team1;			// holds fighters for team 1
	Team* team2;			// holds fighters for team 2
	Stack* standings;		// holds dead fighters
	Stack* top3;			// temporary Stack for top 3 fighters
	// CharType strength;	// not used 
	std::string creature[6];// holds names of creatures
	const int killBonus;	// holds the bonus points for kill
	int fighters, rounds;	// number of fighters, number of rounds
	IntStack* team;			// holds team of dead fighters; companion to standings
	IntStack* top3team;		// temporary Stack for top 3 fighters' teams
	
public:
	/*********************************************************************
	** Description: (Constructor)
	** Take two team pointers and a number of fighters; set up variables
	*********************************************************************/
	Tournament(Team* one = NULL, Team* two = NULL, int fighters = 2);

	/*********************************************************************
	** Description: (Destructor)
	** Delete pointers!
	*********************************************************************/
	~Tournament();
	
	/*********************************************************************
	** Description: 
	** Loop through teams while active members exist and call doRound()
	** with front member of each team
	*********************************************************************/
	void doTourney();

	/*********************************************************************
	** Description: 
	** Pass in two creatures and watch them fight to the death. Also prints
	** helpful messages about round # and player teams/type.
	*********************************************************************/
	void doRound(Creature* opp1, Creature* opp2);

	/*********************************************************************
	** Description: 
	** Moves dead creatures to standings and the creatures' teams to 
	** team Stack
	*********************************************************************/
	void moveToStandings(Creature* dead_creature, int team_num);

	/*********************************************************************
	** Description: 
	** Award ration is determined by defender type ÷ attacker type • damage 
	** Thus, if a Goblin attacked a Blue Man and did 2 damage, the final result
	** would be 2 • 5 ÷ 1, or 10 points. The Blue Man has a higher status than Goblin,
	** so the Goblin earns more points with a successful attack.
	** If a Blue Man did 10 pts of damage against a Goblin, the result would be
	** 10 • 1 ÷ 5, or 2 points.
	*********************************************************************/
	int computePoints(CharType attacker_type, CharType defender_type, int damage);

	/*********************************************************************
	** Description: 
	** Prints top 3 and the winning team. First calls finishStandings() on
	** both teams to ensure that all creatures are in the standings Stack. 
	** Then gets first 3 creatures from standings Stack and prints them,
	** adding them to the top3 Stack. Loops through top3 Stack and adds 
	** creatures back to standings Stack after printing. Finally prints
	** winning team and point info.
	*********************************************************************/
	void printWinner();

	/*********************************************************************
	** Description: 
	** Print all the names from the standings Stack, with their team numbers
	** from the team Stack. Does not assume that finishStandings() has been called
	*********************************************************************/
	void printStandings();

	/*********************************************************************
	** Description: 
	** Loops over team while members are still active and moves members to
	** the standings Stack. Calls Team::releaseFrontMember() to remove them
	** from active duty!
	*********************************************************************/
	void finishStandings(Team* team);
};

#endif