/*********************************************************************
** Author: Collin James
** Date: 11/21/15
** Description: A class that holds a Queue of Creatures. Is able to 
** add members, get them, release them, get and set points, sort its
** fighters according to whether they are dead or alive, return the
** number of the team, return number of active members, and reset the
** team to its original status
*********************************************************************/

#ifndef TEAM_HPP
#define TEAM_HPP
#include "Queue.hpp"
#include "Stack.hpp"

class Team
{
private:
	int points,			// stores total team points
		active_members,	// # of active members
		number;			// team # (i.e. team 1)
	Queue* members;		// storage for active members
	Stack* losers;		// storage for dead members
	
public:
	/*********************************************************************
	** Description: 
	** Constructor -- creates empty Queue, Stack, and passes number. Sets
	** points to 0.
	*********************************************************************/
	Team(int num = 1);
	
	/*********************************************************************
	** Description: 
	** Destructor -- deletes Queue and Stack pointers
	*********************************************************************/
	~Team();

	/*********************************************************************
	** Description: 
	** Add a new member and increment active_members
	*********************************************************************/
	void addMember(Creature* creature);

	/*********************************************************************
	** Description: 
	** Return the top member without removing
	*********************************************************************/
	Creature* getFrontMember();

	/*********************************************************************
	** Description: 
	** Return the top member while removing from duty and decrementing
	** active_members
	*********************************************************************/
	Creature* releaseFrontMember();

	/*********************************************************************
	** Description: 
	** Return number of active members
	*********************************************************************/
	int getActiveMembers();

	/*********************************************************************
	** Description: 
	** Moves fighters to appropriate place; if creature is dead, moves to 
	** loser Stack. If still alive, heals and them moves to back of members
	** Queue.
	*********************************************************************/
	void moveFighters();

	/*********************************************************************
	** Description: 
	** Add points to total points; returns current point total
	*********************************************************************/
	int addPoints(int points);

	/*********************************************************************
	** Description: 
	** Returns current point total
	*********************************************************************/
	int getPoints();

	/*********************************************************************
	** Description: 
	** Resets team. Takes any creatures out of losers Stack and puts them
	** back in the members Queue. Then loops through Queue and revives each
	** member. Returns an error if no members in Queue.
	*********************************************************************/
	void resetTeam();

	/*********************************************************************
	** Description: 
	** Return the team's number
	*********************************************************************/
	int getNumber();

};

#endif