/*********************************************************************
** Author: Collin James
** Date: 11/3/15
** Description: A class that implements a single-linked IntStack data
** structure
*********************************************************************/

#ifndef INTSTACK_HPP
#define INTSTACK_HPP

class IntStack
{
protected:
	/* container structure for nodes */
	struct Intstacknode
	{
		int value;
		Intstacknode *next; // link to next node
		/* constructor; set a value and before/after nodes */
		Intstacknode(int val, Intstacknode *nextnode = NULL)
		{
			value = val;
			next = nextnode;
		}
	};

	Intstacknode *head;  // points to item on top

	/*********************************************************************
	** Description: 
	** Loop through IntStack and print values separated by spaces. If empty
	** print "IntStack is empty". FOR TESTING
	*********************************************************************/
	void displayIntstack();
public:
	/*********************************************************************
	** Description: 
	** Constructor; set head to null
	*********************************************************************/
	IntStack();
	
	/*********************************************************************
	** Description: 
	** Deconstructor; loop through nodes and delete pointers
	*********************************************************************/
	~IntStack();

	/*********************************************************************
	** Description: 
	** Add a value to the IntStack. Value will be on top of the IntStack (LIFO)
	*********************************************************************/
	void add(int val);

	/*********************************************************************
	** Description: 
	** Remove a value from the IntStack. Return the value before removing. 
	** Return -12345 if IntStack is empty.
	*********************************************************************/
	int remove();
};

#endif