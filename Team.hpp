#ifndef TEAM_HPP
#define TEAM_HPP
#include "Queue.hpp"
#include "Stack.hpp"

class Team
{
private:
	int points,
		active_members;
	Queue* members;
	Stack* losers;
	
public:
	Team();
	
	~Team();

	void addMember(Creature* creature);

	Creature* getFrontMember();

	int getActiveMembers();

	void moveFighters();

	int addPoints(int points);

	int getPoints();

	void resetTeam();

};

#endif