#ifndef TEAM_HPP
#define TEAM_HPP
#include "Queue.hpp"
#include "Stack.hpp"

class Team
{
private:
	int points,
		active_members,
		number;
	Queue* members;
	Stack* losers;
	
public:
	Team(int num = 1);
	
	~Team();

	void addMember(Creature* creature);

	Creature* getFrontMember();

	Creature* releaseFrontMember();

	int getActiveMembers();

	void moveFighters();

	int addPoints(int points);

	int getPoints();

	void resetTeam();

	int getNumber();

};

#endif