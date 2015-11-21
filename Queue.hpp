/*********************************************************************
** Author: Collin James
** Date: 11/17/15
** Description: A class that implements a double-linked circular queue 
** data structure
*********************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP
#include "Creature.hpp"

class Queue
{
protected:
	/* container structure for nodes */
	struct Queuenode
	{
		Creature* value;
		Queuenode *ahead; 	//link to node added before
		Queuenode *behind;	//link to node added after

		/* constructor; set a value and before/after nodes */
		Queuenode(Creature* val = NULL, Queuenode *aheadnode = NULL, Queuenode *behindnode = NULL)
		{
			value = val;

			/* Don't want null pointers, so make ahead/behind point to itself */
			if(!aheadnode)
				ahead = this;
			else
				ahead = aheadnode;

			if(!behindnode)
				behind = this;
			else
				behind = behindnode;
		}
	};

	Queuenode *front; 	// points to front of queue
	Queuenode *back;	// points to back of queue	
	
	// umm, for testing
	/********************************************************************
	** Description: 
	** Loop through queue and print values (and pointer addresses). If 
	** empty print "Queue is empty". Print from front to back.
	********************************************************************/
	void displayQueue();
public:
	/*********************************************************************
	** Description: 
	** Constructor; set front and back to -1 (empty node). Can be created
	** with initial value as well.
	*********************************************************************/
	Queue(Creature* val = NULL);
	
	/*********************************************************************
	** Description: 
	** Deconstructor; loop through nodes and delete pointers
	*********************************************************************/
	~Queue();

	/*********************************************************************
	** Description: 
	** Add a positive value to the queue. Value will be at back of the 
	** queue (FIFO). If empty nodes in queue, uses them before adding new
	** nodes.
	*********************************************************************/
	bool addBack(Creature* val);

	/*********************************************************************
	** Description: 
	** Remove a value from the front of queue. Return the value before 
	** removing. Removing actually just sets to -1. Return -1 if queue is 
	** empty.
	*********************************************************************/
	Creature* removeFront();

	/*********************************************************************
	** Description: 
	** Simply return the value at the front pointer of the queue. Returns
	** -1 if queue is empty. Used in removeFront()
	*********************************************************************/
	Creature* getFront() const;
};

#endif