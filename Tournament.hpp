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
#include "Queue.hpp"
#include <string>
// #include "CharType.hpp" // already included in Creature

class Tournament
{
private:
	Team* team1;
	Team* team2;
	Stack* standings;
	Queue* top3;
	CharType strength;
	std::string creature[6];
	const int killBonus;
	int rounds;
	
public:
	Tournament(Team* one = NULL, Team* two = NULL);

	~Tournament();
	
	void doTourney();

	void doRound(Creature* opp1, Creature* opp2);

	void moveToStandings(Creature* dead_creature);

	int computePoints(CharType attacker_type, CharType defender_type, int damage);

	void printStandings();

	void printWinner();
};

#endif