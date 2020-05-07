#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

void delete_list(Node * head);
void Build_linked_list(Node * &head, Node * &tail, int x, int y);
bool Search_History(Node * head, int x , int y );

#endif