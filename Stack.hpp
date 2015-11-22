/*********************************************************************
** Author: Collin James
** Date: 11/3/15
** Description: A class that implements a single-linked stack data
** structure
*********************************************************************/

#ifndef STACK_HPP
#define STACK_HPP
#include "Creature.hpp"

class Stack
{
protected:
	/* container structure for nodes */
	struct Stacknode
	{
		Creature *value;
		Stacknode *next; // link to next node
		/* constructor; set a value and before/after nodes */
		Stacknode(Creature *val = NULL, Stacknode *nextnode = NULL)
		{
			value = val;
			next = nextnode;
		}
	};

	Stacknode *head;  // points to item on top

	/*********************************************************************
	** Description: 
	** Loop through stack and print values separated by spaces. If empty
	** print "Stack is empty". FOR TESTING
	*********************************************************************/
	void displayStack();
	
public:
	/*********************************************************************
	** Description: 
	** Constructor; set head to null
	*********************************************************************/
	Stack();
	
	/*********************************************************************
	** Description: 
	** Deconstructor; loop through nodes and delete pointers
	*********************************************************************/
	~Stack();

	/*********************************************************************
	** Description: 
	** Add a value to the stack. Value will be on top of the stack (LIFO)
	*********************************************************************/
	void add(Creature *val);

	/*********************************************************************
	** Description: 
	** Remove a value from the stack. Return the value before removing. 
	** Return NULL if stack is empty.
	*********************************************************************/
	Creature* remove();

	/*********************************************************************
	** Description: 
	** Return the top value without removing
	*********************************************************************/
	Creature* get() const;
};

#endif