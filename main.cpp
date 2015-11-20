/*********************************************************************
** Author: Collin James
** Date: 
** Description: 
*********************************************************************/

#include <iostream>
#include <iomanip>
#include "Creature.hpp"
#include "Barbarian.hpp"
#include "Reptile.hpp"
#include "Bluemen.hpp"
#include "Goblin.hpp"
#include "Shadow.hpp"
#include "Stack.hpp"
#include "Queue.hpp"
#include "Team.hpp"

int main()
{
	/* testing Stack */
	// Stack* testStack = new Stack;
	// testStack->add(new Barbarian);
	// testStack->displayStack();
	// Creature* testCreature = testStack->remove();
	// testCreature->listStats();
	// testStack->displayStack();

	/* testing Queue */
	// Queue* testQueue = new Queue;
	// testQueue->addBack(new Barbarian);
	// testQueue->displayQueue();
	// Creature* testCreature = testQueue->removeFront();
	// testCreature->listStats();
	// testQueue->displayQueue();
	// testQueue->addBack(testCreature);
	// testQueue->displayQueue();
	// delete testQueue;
	// delete testCreature;

	/* testing Team */
	Team* testTeam = new Team;
	testTeam->addMember(new Barbarian);
	Creature* testCreature = testTeam->getFrontMember();
	testCreature->listStats();
	std::cout << "number of active members is: " << testTeam->getActiveMembers() << std::endl;
	testTeam->addMember(new Goblin);
	std::cout << "number of active members is: " << testTeam->getActiveMembers() << std::endl;
	// testTeam->moveFighters();
	// testCreature = testTeam->getFrontMember();
	// testCreature->listStats();
	// testTeam->moveFighters();
	testCreature = testTeam->getFrontMember();
	// testCreature->listStats();
	testCreature->kill();
	testTeam->moveFighters();
	std::cout << "number of active members is: " << testTeam->getActiveMembers() << std::endl;
	testCreature = testTeam->getFrontMember();
	testCreature->listStats();
	// std::cout << "team points is: " << testTeam->getPoints() << std::endl;
	// testTeam->addPoints(10);
	// std::cout << "team points is: " << testTeam->getPoints() << std::endl;
	testTeam->resetTeam();
	// testCreature = testTeam->getFrontMember();
	std::cout << "number of active members is: " << testTeam->getActiveMembers() << std::endl;
	testCreature = testTeam->getFrontMember();
	testCreature->listStats();
	testCreature->kill();
	testTeam->moveFighters();
	testCreature = testTeam->getFrontMember();
	testCreature->listStats();
	// testCreature->listStats();



	delete testTeam;
}
