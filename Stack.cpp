/*********************************************************************
** Author: Collin James
** Date: 11/3/15
** Description: A class that implements a single-linked stack data
** structure; implementation file
*********************************************************************/

#include <iostream>
#include "Stack.hpp" // see for function descriptions

Stack::Stack()
{
	head = NULL;
}

Stack::~Stack()
{
	Stacknode *tempPtr = head; // point at head
	/* loop until tempPtr is NULL */
	while(tempPtr)
	{
		Stacknode *trash = tempPtr; // point at current tempPtr
		tempPtr = tempPtr->next;	// set to next pointer in stack
		delete trash;				// delete the pointer
	}	
}

void Stack::add(Creature *val)
{
	if(!head) // if head is null
		head = new Stacknode(val); // head will be the first node
	else
	{
		/* create a new node, where head becomes the next node down the list */
		Stacknode *newnode = new Stacknode(val, head);
		
		/* now make head point back to the beginning of the list*/
		head = newnode;
	}
}

Creature* Stack::remove()
{
	if(head) // if it's not null
	{
		Stacknode *tempPtr = head; // point at head
		Creature* temp_val = tempPtr->value;	// save the value
		head = head->next;	// next node is new head
		delete tempPtr;		// get rid if old head
		return temp_val;	
	}
	else	// if head is null
		return NULL;	// return junk number
}

Creature* Stack::get()
{
	// std::cout << "head value is: " << head->value << std::endl;
	return head->value;
}

void Stack::displayStack()
{
	if(head)
	{
		/* loop through stack and print values */
		Stacknode *tempPtr = head;
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
	else	// if head is null, nothing is in stack
		std::cout << "Stack is empty" << std::endl;
}