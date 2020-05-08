#include <iostream>

#include "LinkedList.h"

//To delete linked list and free memory.
void delete_list(Node * head)
{
  while (head != NULL)
  {
    Node * p = head;
    head = head->next;
    delete p;
  } 
}

//To build a linked list forward.
void Build_linked_list(Node * &head, Node * &tail, int x, int y)
{
  Node * p = new Node;
	p->x = x;
	p->y = y;
	p->next = NULL;

	if (head == NULL) 
  {
		head = p;
		tail = p;
	}

	else 
  {
		tail->next = p;
		tail = p;
	}	
}

//To search a linked list for an specific entry, and returns true if found.
bool Search_History( Node * head, int x , int y )
{
	Node * current = head;

	while (current != NULL) {
		if (current->x == x && current->y == y)
			return true;
		else
			current = current->next;
	}
	return false;
}
