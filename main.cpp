/*********************************************************************
** Author: Collin James
** Date: 
** Description: 
*********************************************************************/

#include <iostream>
#include <iomanip>
#include "Creature.hpp"
#include "Barbarian.hpp"
#include "Stack.hpp"
#include "Queue.hpp"

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
	Queue* testQueue = new Queue;
	testQueue->addBack(new Barbarian);
	testQueue->displayQueue();
	Creature* testCreature = testQueue->removeFront();
	testCreature->listStats();
	testQueue->displayQueue();
	testQueue->addBack(testCreature);
	testQueue->displayQueue();
	delete testQueue;
	// delete testCreature;
}
