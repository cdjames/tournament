/*********************************************************************
** Author: Collin James
** Date: 11/21/15
** Description: A class that holds a Queue of Creatures. Is able to 
** add members, get them, release them, get and set points, sort its
** fighters according to whether they are dead or alive, return the
** number of the team, return number of active members, and reset the
** team to its original status
** 
** Implementation
*********************************************************************/

#include "Team.hpp"	// please see for function descriptions
#include <iostream>
	
Team::Team(int num)
{
	/* initilize variables and storage */
	this->members = new Queue;
	this->losers = new Stack;
	this->number = num;
	this->points = 0;
}

Team::~Team()
{
	/* delete pointers */
	if(this->members)
		delete this->members;
	if(this->losers)
		delete this->losers;
}

void Team::addMember(Creature* creature)
{
	/* Make sure there is actually a creature and then add it to stack
	 * Increment active_members */
	if(creature != NULL)
	{
		this->members->addBack(creature);
		this->active_members++;
		// std::cout << "member added!" << std::endl;
	}
	return;
}

Creature* Team::getFrontMember()
{
	return this->members->getFront();
}

Creature* Team::releaseFrontMember()
{
	this->active_members--;
	return this->members->removeFront();
}

int Team::getActiveMembers()
{
	return this->active_members;
}

void Team::moveFighters()
{
	/* If there are fighters in the members Queue */
	if(this->active_members > 0)
	{
		Creature* tempCr = this->members->removeFront();
		bool dead = tempCr->isDead();

		/* if the creature on top of Queue is dead, move it to losers */
		if(dead)
		{
			this->losers->add(tempCr);
			this->active_members--;
			// std::cout << "team " << this << " active_members: " << active_members << std::endl;
		}
		/* if alive then heal it and put it at back of the Queue */
		else
		{
			// std::cout << "team " << this << " fighter " 
			// << tempCr->getType() << " healed to " 
			// << tempCr->heal() << " hit points" << std::endl;
			tempCr->heal();
			this->members->addBack(tempCr);
			// std::cout << "team " << this << " active_members: " << active_members << std::endl;
		}
	}
	return;
}

int Team::addPoints(int points)
{
	this->points += points;
	return getPoints();
	// return points; // testing
}

int Team::getPoints()
{
	return this->points;
}

void Team::resetTeam()
{
	int count = 0;
	/* if any dead creatures, put them back in Queue */
	if(this->losers->get())
	{
		Creature* tempCr = losers->remove();
		while(tempCr)
		{
			std::cout << "tempCr: " << tempCr << std::endl;
			addMember(tempCr);
			tempCr = this->losers->remove();
		}
			
	}
	/* Get top creature from Queue, revive it, and add it to a temporary Queue
	 * When all revived, add them back to the members Queue */
	Creature* tempCr = this->members->removeFront();
	Queue *tempQueue = new Queue;
	if(tempCr != NULL)
	{
		while(tempCr != NULL)
		{
			count++;
			// std::cout << "value at node " << count << " is: " << tempCr << std::endl;
			tempCr->revive();
			tempQueue->addBack(tempCr);
			tempCr = this->members->removeFront();
		}
		/* back to members Queue */
		tempCr = tempQueue->removeFront();
		while(tempCr != NULL)
		{
			this->members->addBack(tempCr);
			tempCr = tempQueue->removeFront();
		}
	}
	else
		std::cout << "Error: no members." << std::endl;
	
	// if(tempQueue)
	// 	delete tempQueue;
	
	return;
}

int Team::getNumber()
{
	return this->number;
}