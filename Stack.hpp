/*********************************************************************
** Author: Collin James
** Date: 11/3/15
** Description: A class that implements a single-linked stack data
** structure
*********************************************************************/

#ifndef STACK_HPP
#define STACK_HPP

class Stack
{
protected:
	/* container structure for nodes */
	struct Stacknode
	{
		int value;
		Stacknode *next; // link to next node
		/* constructor; set a value and before/after nodes */
		Stacknode(int val, Stacknode *nextnode = NULL)
		{
			value = val;
			next = nextnode;
		}
	};

	Stacknode *head;  // points to item on top
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
	void add(int val);

	/*********************************************************************
	** Description: 
	** Remove a value from the stack. Return the value before removing. 
	** Return -12345 if stack is empty.
	*********************************************************************/
	int remove();

	/*********************************************************************
	** Description: 
	** Loop through stack and print values separated by spaces. If empty
	** print "Stack is empty"
	*********************************************************************/
	void displayStack();
};

#endif