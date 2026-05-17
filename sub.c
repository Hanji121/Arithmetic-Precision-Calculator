#include "apc.h"

int compare(node *head1, node *head2)
    {
        int len1 = 0, len2 = 0;
        node *t1 = head1, *t2 = head2;

        while (t1) { len1++; t1 = t1->next; } // Calculate lenght of first list
        while (t2) { len2++; t2 = t2->next; } // Calculate lenght of second list

        if(len1 > len2) return 1; // First number is larger
        if(len1 < len2) return -1; // Second number is larger

        while(head1 && head2) // If lenght equal, compare digit by digit
        {
            if(head1->data > head2->data) return 1; // First is larger
            if(head1->data < head2->data) return -1; // Second is larger

            head1 = head1->next;
            head2 = head2->next;
        }
        return 0; // Both number are equal
    }

void subtraction(node *tail1, node *tail2, node **headR, node **tailR)
{
    int borrow = 0; // Initialize borrow
    int sub = 0; // Store subtraction result

    while(tail1 != NULL) // Traverse from least significant digit
    {
        int val1 = tail1->data; // Dight from first number
        int val2 = 0; // Digit from second number

        if(borrow) // Apply previous borrow
        {
            val1--;
            borrow = 0;
        }

        if(tail2 != NULL) // Get digit from second number if exists
        {
            val2 = tail2->data;
        }

        if(val1 < val2) // Handle borrow condition
        {
            val1 += 10;
            borrow = 1;
        }

        sub = val1 - val2; // Perfrom subtraction

        insert_first(headR, tailR, sub); // Insert result digit

        tail1 = tail1->prev; // Move to next digit 
        if(tail2 != NULL)
        {
            tail2 = tail2->prev;
        }
    }
    
    // Remove leading zeros from result
    while(*headR != NULL && (*headR)->data == 0 && (*headR)->next != NULL)
    {
        node *temp = *headR;

        *headR = (*headR)->next;
        (*headR)->prev = NULL;

        free(temp); //Free removed node
    }
}
