/*********************************************************************
** Author: Collin James
** Date: 
** Description: 
*********************************************************************/

#include <iostream>
#include "Creature.hpp"
// #include "CharType.hpp" // already in Creature.hpp
#include "Barbarian.hpp"
#include "Reptile.hpp"
#include "Bluemen.hpp"
#include "Goblin.hpp"
#include "Shadow.hpp"
// #include "Stack.hpp"
// #include "Queue.hpp"
#include "Team.hpp"
#include "Tournament.hpp"
#include <stdlib.h>		// for srand()
#include <ctime>		// for time()

int mainMenu(int player);

void intakeInt(int &num_items, std::string message);

void clearCin();

bool cinFail();

void addCreature(int type, Team* team);

void initialTesting();

int main()
{
	srand(std::time(0)); // seed the random number generator used by Creature die function

	Team* team1 = new Team(1);
	Team* team2 = new Team(2);

	int fighters;
	intakeInt(fighters, "the number of fighters. Max is 20.");

	/* get Player 1 creatures and assemble team */
	for (int i = 0; i < fighters; i++)
	{
		int choice = mainMenu(1);
		addCreature(choice, team1);
	}
	/* get Player 2 creatures and assemble team */
	for (int i = 0; i < fighters; i++)
	{
		int choice = mainMenu(2);
		addCreature(choice, team2);
	}

	/* assemble Tournament */
	Tournament* testTourney = new Tournament(team1, team2, fighters*2);
	/* announce start */
	std::cout << "Starting tournament..." << std::endl;

	testTourney->doTourney();
	testTourney->printWinner();
	testTourney->printStandings();

	// don't delete teams as they're deleted by testTourney
	
	if(testTourney)
		delete testTourney;
}

int mainMenu(int player)
{
	int input = -1;

	std::cout << std::endl;
	std::cout << "Player " << player << ", enter a fighter:" << std::endl;
	std::cout << "   1 - Goblin" << std::endl;
	std::cout << "   2 - Barbarian" << std::endl;
	std::cout << "   3 - Shadow" << std::endl;
	std::cout << "   4 - Reptile" << std::endl;
	std::cout << "   5 - Bluemen" << std::endl;

	std::cin >> input;

	/* test for bad input and loop until good */
	while(input < 1 || input > 5 || cinFail())
	{
		std::cout << "Please enter 1-5." << std::endl;
		clearCin(); // clear cin, otherwise endless loop!
		input = mainMenu(player); // run menu again
	}

	return input;
}

void addCreature(int type, Team* team)
{
	switch(type)
	{
		case GOBLIN: // 1
			team->addMember(new Goblin);
			break;
		case BARB: // 2
			team->addMember(new Barbarian);
			break;
		case SHADOW: // 3
			team->addMember(new Shadow);
			break;
		case REPTILE: // 4
			team->addMember(new Reptile);
			break;
		case BLUEMEN: // 5
			team->addMember(new Bluemen);
			break;
		default:
			break;

	}
}

void intakeInt(int &num_items, std::string message)
{ // not in spec
	// int imax = std::numeric_limits<int>::max(); // upper limit for ints on system
	int imax = 20; // upper limit for ints on system
	std::cout << "Please enter "<< message << std::endl;
	
	do{
		std::cin >> num_items;
		if(cinFail()) // some bad or strange input
			std::cout << "Please enter a correct value." << std::endl;
		else if (num_items <= 0)
			std::cout << "Please enter a positive number." << std::endl;
		else if (num_items > imax)
			std::cout << "Please enter a lower number." << std::endl;

	} while (cinFail() || num_items <= 0 || num_items > imax);

	clearCin();
	return;
}

void clearCin()
{
	std::cin.clear();
	std::cin.ignore(50, '\n');
}

bool cinFail()
{
	bool failed = false;
	if(std::cin.fail()) // check for bad input
	{
		clearCin(); // ignore the bad input
		failed = true;
	}
	return failed;
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
