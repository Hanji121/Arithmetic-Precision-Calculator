#include "apc.h"

void modulus(node *head1, node *head2, node **headR, node **tailR)
{
    if(head2->data == 0 && head2->next == NULL) // Check division by zero
    {
        printf("Division by zero\n");
        return;
    }

    node *temp_head1 = NULL;
    node *temp_tail1 = NULL;

    // Copy dividend to temporary list
    copy_list(head1, &temp_head1, &temp_tail1);

    while(1)
    {
        int cmp = compare_list(temp_head1, head2); // Compare dividend and divisor

        // stop when temp < divisor
        if(cmp == OPERAND2)
        {
            break;
        }

        // if equal → remainder is 0
        if(cmp == SAME)
        {
            insert_last(headR, tailR, 0); // Store 0 as result
            return;
        }

        node *res_head = NULL;
        node *res_tail = NULL;

        // get tails for subtraction
        node *t1 = get_tail(temp_head1);
        node *t2 = get_tail(head2);

        subtraction(t1, t2, &res_head, &res_tail); // Perfrom subraction

        remove_pre_zeros(&res_head); // Remove leading zeros

        temp_head1 = res_head; // Update dividend
    }

    // Remaining value is modulus(remainder)
    node *temp = temp_head1;
    while (temp)
    {
        insert_last(headR, tailR, temp->data); // Copy remanider to result
        temp = temp->next;
    }
}