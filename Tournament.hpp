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
#include <vector>
// #include "CharType.hpp" // already included in Creature

class Tournament
{
private:
	Team* team1;
	Team* team2;
	Stack* standings;
	Stack* top3;
	CharType strength;
	std::string creature[6];
	const int killBonus;
	int fighters;
	IntStack* team;
	IntStack* top3team;
	
public:
	Tournament(Team* one = NULL, Team* two = NULL, int fighters = 2);

	~Tournament();
	
	void doTourney();

	void doRound(Creature* opp1, Creature* opp2);

	void moveToStandings(Creature* dead_creature, int team_num);

	int computePoints(CharType attacker_type, CharType defender_type, int damage);

	void printStandings();

	void printWinner();

	void finishStandings(Team* team);
};

#endif