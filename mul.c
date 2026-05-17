#include "apc.h"

void multiplication(node *tail1, node *tail2, node **headR, node **tailR)
{
    node *t2 = tail2; // Pointer for second number (LSB side)
    node *temp_head = NULL, *temp_tail = NULL; // Temporay product list
    node *result_head = NULL, *result_tail = NULL; // Final result list

    int carry, mul, count = 0; // Carry , multiplication result , shift counter

    while(t2 != NULL) // Loop through second number digits
    {
        node *t1 = tail1; // Reset first number pointer
        carry = 0;

        temp_head = temp_tail = NULL; // Reset temporary list
        
        // Add zeros based on position(like shifting)
        for(int i = 0; i < count; i++) 
        {
            insert_first(&temp_head, &temp_tail, 0);
        }

        // Multiply each digit of first number with current digit of second
        while(t1 != NULL)
        {
            mul = (t1->data * t2->data) + carry; // Multiply + carry
            carry = mul / 10; // Update carry 

            insert_first(&temp_head, &temp_tail, mul % 10); // Store digit

            t1 = t1->prev; // Move to next digit
        }

        // If carry remains, insert it
        if(carry > 0)
        {
            insert_first(&temp_head, &temp_tail, carry);
        }

        // If first iteration, directly assign result
        if(result_head == NULL)
        {
            result_head = temp_head;
            result_tail = temp_tail;
        }
        else
        {
            node *new_head = NULL, *new_tail = NULL;
            // Add temporary result to final result
            addition(result_tail, temp_tail, &new_head, &new_tail);

            result_head = new_head;
            result_tail = new_tail;
        }

        count++; // Increase shift (place value)
        t2 = t2->prev; // Move to next digit of second number
    }

    *headR = result_head; // Assign final result head
    *tailR = result_tail; // Assign final result tail
}