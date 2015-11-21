/*********************************************************************
** Author: Collin James
** Date: 11/3/15
** Description: A class that implements a single-linked IntStack data
** structure
**
** Implementation file
*********************************************************************/

#include <iostream>
#include "IntStack.hpp" // see for function descriptions

IntStack::IntStack()
{
	head = NULL;
}

IntStack::~IntStack()
{
	Intstacknode *tempPtr = head; // point at head
	/* loop until tempPtr is NULL */
	while(tempPtr)
	{
		Intstacknode *trash = tempPtr; // point at current tempPtr
		tempPtr = tempPtr->next;	// set to next pointer in IntStack
		delete trash;				// delete the pointer
	}	
}

void IntStack::add(int val)
{
	if(!head) // if head is null
		head = new Intstacknode(val); // head will be the first node
	else
	{
		/* create a new node, where head becomes the next node down the list */
		Intstacknode *newnode = new Intstacknode(val, head);
		
		/* now make head point back to the beginning of the list*/
		head = newnode;
	}
}

int IntStack::remove()
{
	if(head) // if it's not null
	{
		Intstacknode *tempPtr = head; // point at head
		int temp_val = tempPtr->value;	// save the value
		head = head->next;	// next node is new head
		delete tempPtr;		// get rid if old head
		return temp_val;	
	}
	else	// if head is null
		return -12345;	// return junk number
}

void IntStack::displayIntstack() // for testing
{
	if(head)
	{
		/* loop through IntStack and print values */
		Intstacknode *tempPtr = head;
		std::cout << "head pointer is: " << head << "   \n";
		while(tempPtr)
		{
			std::cout << tempPtr->value << "   ";
			/* comment out next two lines for no pointer addresses */
			std::cout << "pointer is: " << tempPtr << "   ";
			std::cout << "next pointer is: " << tempPtr->next << "   \n";
			
			tempPtr = tempPtr->next;
		}	
		std::cout << std::endl;
	}
	else	// if head is null, nothing is in IntStack
		std::cout << "IntStack is empty" << std::endl;
}