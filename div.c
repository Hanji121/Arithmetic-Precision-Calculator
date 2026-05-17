#include "apc.h"

void division(node *head1, node *head2, node **headR, node **tailR)
{
    if (head2->data == 0 && head2->next == NULL) // Check division by zero
    {
        printf("Division by zero\n");
        return;
    }

    node *temp_head1 = NULL;
    node *temp_tail1 = NULL;

    copy_list(head1, &temp_head1, &temp_tail1); // Copy dividend

    int count = 0; // Quotient counter 

    while (1)
    {
        int cmp = compare_list(temp_head1, head2); // Compare number

        if (cmp == OPERAND2) // If dividend < divisor
            break;

        if (cmp == SAME) // If equal
        {
            count++;
            break;
        }

        node *res_head = NULL;
        node *res_tail = NULL;

        // GET TAILS (VERY IMPORTANT)
        node *t1 = get_tail(temp_head1);
        node *t2 = get_tail(head2);

        subtraction(t1, t2, &res_head, &res_tail); // Perfrom subraction

        remove_pre_zeros(&res_head); // Remove leading zeros

        temp_head1 = res_head; // Update dividend

        count++; // Increment quotient
    }

    if(count == 0) //If result is zero
    {
        insert_last(headR, tailR, 0);
        return;
    }

    while (count > 0) // Store quotient in result list
    {
        insert_at_begin(headR, tailR, count % 10); // Insert digit
        count /= 10;
    }
}