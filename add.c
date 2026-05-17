#include "apc.h"

void addition(node *tail1, node *tail2, node **headR, node **tailR)
{
    if(tail1 == NULL && tail2 == NULL) // Check if both lists are empty
    {
        return;
    }

    node *temp1 = tail1; // Pointer for first number(LSB side)
    node *temp2 = tail2; // Pointer for second number(LSB side)

    int carry = 0, result = 0; // Initialize carry and result

    while(temp1 != NULL || temp2 != NULL || carry)  // Loop until both lists and carry are processed
    {
        result = carry; // Start with carry

        if(temp1 != NULL)
        {
            result += temp1->data; // Add digit from first list
            temp1 = temp1->prev; // Move to previous digit
        }

        if(temp2 != NULL)
        {
            result += temp2->data; // Add digit from second list
            temp2 = temp2->prev; // Move to previous digit
        }

        carry = result / 10; // Calculate carry
        result = result % 10; // Get single digit  

        insert_first(headR, tailR, result); // Insert result at beginning 
    }
}