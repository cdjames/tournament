/*********************************************************************
** Author: Collin James
** Date: 
** Description: 
*********************************************************************/

#include <iostream>
#include "Creature.hpp"
#include "Barbarian.hpp"
#include "Reptile.hpp"
#include "Bluemen.hpp"
#include "Goblin.hpp"
#include "Shadow.hpp"
#include "Stack.hpp"
#include "Queue.hpp"
#include "Team.hpp"
#include "Tournament.hpp"
#include <stdlib.h>		// for srand()
#include <ctime>		// for time()

void initialTesting();

int main()
{
	srand(std::time(0)); // seed the random number generator used Creature die function

	/* testing Tournament */
	Team* testTeam = new Team(1);
	testTeam->addMember(new Bluemen);
	testTeam->addMember(new Goblin);
	testTeam->addMember(new Shadow);

	Team* testTeam2 = new Team(2);
	testTeam2->addMember(new Goblin);
	testTeam2->addMember(new Goblin);
	testTeam2->addMember(new Reptile);

	Tournament* testTourney = new Tournament(testTeam, testTeam2);
	std::cout << "Starting tournament." << std::endl;
	testTourney->doTourney();
	testTourney->printWinner();
	testTourney->printStandings();

	// don't delete teams as they're deleted by testTourney
	
	if(testTourney)
		delete testTourney;
}

void initialTesting()
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
	// Team* testTeam = new Team;
	// testTeam->addMember(new Barbarian);
	// Creature* testCreature = testTeam->getFrontMember();
	// testCreature->listStats();
	// std::cout << "number of active members is: " << testTeam->getActiveMembers() << std::endl;
	// testTeam->addMember(new Goblin);
	// std::cout << "number of active members is: " << testTeam->getActiveMembers() << std::endl;
	// // testTeam->moveFighters();
	// // testCreature = testTeam->getFrontMember();
	// // testCreature->listStats();
	// // testTeam->moveFighters();
	// testCreature = testTeam->getFrontMember();
	// // testCreature->listStats();
	// testCreature->kill();
	// testTeam->moveFighters();
	// std::cout << "number of active members is: " << testTeam->getActiveMembers() << std::endl;
	// testCreature = testTeam->getFrontMember();
	// testCreature->listStats();
	// // std::cout << "team points is: " << testTeam->getPoints() << std::endl;
	// // testTeam->addPoints(10);
	// // std::cout << "team points is: " << testTeam->getPoints() << std::endl;
	// testTeam->resetTeam();
	// // testCreature = testTeam->getFrontMember();
	// std::cout << "number of active members is: " << testTeam->getActiveMembers() << std::endl;
	// testCreature = testTeam->getFrontMember();
	// testCreature->listStats();
	// testCreature->kill();
	// testTeam->moveFighters();
	// testCreature = testTeam->getFrontMember();
	// testCreature->listStats();
	// testCreature->listStats();

	/* testing Tournament */
	// Team* testTeam = new Team(1);
	// testTeam->addMember(new Bluemen);
	// testTeam->addMember(new Goblin);
	// testTeam->addMember(new Shadow);

	// Team* testTeam2 = new Team(2);
	// testTeam2->addMember(new Goblin);
	// testTeam2->addMember(new Goblin);
	// testTeam2->addMember(new Reptile);

	// Tournament* testTourney = new Tournament(testTeam, testTeam2);
	// std::cout << "Starting tournament." << std::endl;
	// testTourney->doTourney();
	// testTourney->printWinner();
	// testTourney->printStandings();

	// // don't delete teams as they're deleted by testTourney
	
	// if(testTourney)
	// 	delete testTourney;
	// std::cout << "testTeam: " << &testTeam << std::endl;
	// if(testTeam != NULL)
	// 	delete testTeam;
	// testTeam = 0;	
	// if(testTeam2 != NULL)
	// 	delete testTeam2; 
	// delete testCreature;
}
