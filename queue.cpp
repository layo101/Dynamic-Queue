#include "queue.h"
#include <iostream>
using namespace std;
Queue::Queue()
{
	//contructor initializes queue to be empty
	front_p = NULL;
	back_p = NULL;
	current_size = 0;
}

Queue::~Queue()
{
	//Destructor: deallocates nodes in the linked list
	node * temp;
	while(front_p != NULL)			// while queue is not yet empty
	{
		temp = front_p;			// save address of front item
		front_p = front_p->next;	// reset pointer to next item
		delete temp;			// delete former front
	}	

}
void Queue::enqueue(int item)
{
	//enters item at the rear of the queue
	if(front_p == NULL)
	{
		front_p = new node(item, NULL);
		back_p = front_p;
	}	
	else
	{
		node * temp = new node(item, NULL);
		back_p -> next = temp;
		back_p = temp;
	}
	current_size += 1;

}
int Queue::dequeue()
{
	//Assumes queue is not empty
	//Results in a removal from the front of the queue
	if(current_size == 0)
	{
		return false;
	}
	else if(current_size == 1)
	{
		int item = front_p -> data;
		delete front_p;
		front_p = NULL;
		current_size -= 1;
		return item;
	}
	else
	{
		int item = front_p -> data;
		node * temp = front_p -> next;
		delete front_p;
		front_p = temp;
		current_size -= 1;
		return item;
	}
}

int Queue::front()
{
	//Assumes: queue is not empty
	//returns: references to item at the front of the queue
	if(front_p == NULL)
	{
		return 1;
	}
	return front_p -> data;
}

bool Queue::empty()
{
	//returns true if queue is empty, otherwise false
	return current_size == 0;	
}

int Queue::size()
{
	// returs the size of the queue
	return current_size;
}

int Queue::makeUnique(int item)
{
	// If <item> occurs in the queue more 
	// than once, remove all occurrences of <item> except the first. 
	// Return the number of elements removed.
	int count = 0;
	node * temp = front_p;
	node * pre = NULL;

	while( temp != NULL)
	{
		if(temp -> data == item)
		{
			count++;

			if(temp == front_p)
			{
				node * second_temp = temp -> next;
				delete front_p;
				front_p = second_temp;
				temp = front_p;
			}
			else
			{
				node * second_temp = temp -> next;
				delete temp;
				pre -> next = second_temp;
				temp = temp -> next;
			}
		}
		else
		{
			pre = temp;
			temp = temp -> next;
		}
	}
	return count;
}
