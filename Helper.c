#include "apc.h"

/* existing functions */

node* get_tail(node *head) // Get the last node(tail) of the linked list
{
    while(head && head->next)
        head = head->next; // Traverse to next node
    return head; // Return tail node
}