/*********************************************************************
** Author: Collin James
** Date: 
** Description: 
*********************************************************************/
#include "Team.hpp"
#include <iostream>
// int points,
// 		active_members;
// 	Queue* members;
// 	Stack* losers;
	
Team::Team()
{
	members = new Queue;
	losers = new Stack;
}

Team::~Team()
{
	// std::cout << "team " << this << " out." << std::endl;
	if(members)
		delete members;
	if(losers)
		delete losers;
}

void Team::addMember(Creature* creature)
{
	if(creature != NULL)
	{
		members->addBack(creature);
		active_members++;
		// std::cout << "member added!" << std::endl;
	}
	return;
}

Creature* Team::getFrontMember()
{
	return members->getFront();
}

int Team::getActiveMembers()
{
	return active_members;
}

void Team::moveFighters()
{
	if(active_members > 0)
	{
		Creature* tempCr = members->removeFront();
		bool dead = tempCr->isDead();

		if(dead)
		{
			losers->add(tempCr);
			active_members--;
		}
		else
		{
			members->addBack(tempCr);
		}
	}
	return;
}

int Team::addPoints(int points)
{
	this->points += points;
	return getPoints();
}

int Team::getPoints()
{
	return this->points;
}

void Team::resetTeam()
{
	int count = 0;

	if(losers->get())
	{
		Creature* tempCr = losers->remove();
		while(tempCr)
		{
			std::cout << "tempCr: " << tempCr << std::endl;
			addMember(tempCr);
			tempCr = losers->remove();
		}
			
	}
	
	Creature* tempCr = members->removeFront();
	Queue *tempQueue = new Queue;
	if(tempCr != NULL)
	{
		while(tempCr != NULL)
		{
			count++;
			std::cout << "value at node " << count << " is: " << tempCr << std::endl;
			tempCr->revive();
			tempQueue->addBack(tempCr);
			tempCr = members->removeFront();
		}

		tempCr = tempQueue->removeFront();
		while(tempCr != NULL)
		{
			members->addBack(tempCr);
			tempCr = tempQueue->removeFront();
		}
	}
	else
		std::cout << "Queue is empty." << std::endl;

	return;
}