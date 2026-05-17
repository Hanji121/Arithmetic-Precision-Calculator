/*
Ashish Kumar Singh.
25036A.
03-04-2025.

Discerption : 

The APC(Arbitrary Precision Calculator) project is designed to perform arithmetic operation on very large number using
doubly linked lists. It supports addition, subtraction, multiplication, division, and modulus by processing each digit
individually. The system also ensures correct results through sign handling and removal of leading zeros.

*/
#include "apc.h"

int main(int argc, char *argv[])
{
    int sign1 = 1, sign2 = 1; // Store sign of operands

    node *head1 = NULL, *tail1 = NULL; // First number
    node *head2 = NULL, *tail2 = NULL; // Second number
    node *headR = NULL, *tailR = NULL; // Result list

    if(argc != 4) // Check for valid number of arguments
    {
        printf("Invalid input\n");
		{
			return FAILURE;
		}
    }

    if(argv[1][0] == '-') // Check sign of first operand
    {
        sign1 = -1;
        argv[1]++; // Skip '-' sign
    }

    if(argv[3][0] == '-') // Check sign of second operand 
    {
        sign2 = -1;
        argv[3]++; // Skip '-' sign
    }

    if(cla_validation(argc, argv) == FAILURE) // Validate operands and operator
    {
        printf("Invalid input\n");
		{
			return FAILURE;
		}
    }

    // Create linked lists from input number
    create_list(argv[1], &head1, &tail1);
    create_list(argv[3], &head2, &tail2);

    remove_pre_zeros(&head1); // Remove leading zeros
    remove_pre_zeros(&head2); // Remove leading zeros

    char oper = argv[2][0]; // Get operator

    printf("Result: ");

    switch(oper)
    {
        case '+':
            if(sign1 == sign2) // Same sign -> direct addition
            {
                addition(tail1, tail2, &headR, &tailR);
                if(sign1 == -1) printf("-"); // Print sign
            }
            else
            {
                int cmp = compare_list(head1, head2);

                if(cmp == OPERAND1 || cmp == SAME) // Compare magnitude
                {
                    subtraction(tail1, tail2, &headR, &tailR);
                    if(sign1 == -1) printf("-");
                }
                else
                {
                    subtraction(tail2, tail1, &headR, &tailR);
                    if(sign2 == -1) printf("-");
                }
            }
            break;

        case '-':
            if(sign1 != sign2) // Different signs->addition 
            {
                addition(tail1, tail2, &headR, &tailR);
                if(sign1 == -1) printf("-");
            }
            else
            {
                int cmp = compare_list(head1, head2); // Compare magnitude

                if(cmp == OPERAND1 || cmp == SAME)
                {
                    subtraction(tail1, tail2, &headR, &tailR);
                    if(sign1 == -1) printf("-");
                }
                else
                {
                    subtraction(tail2, tail1, &headR, &tailR);
                    if(sign1 == 1) printf("-");
                }
            }
            break;

        case 'x':
        case 'X':
            multiplication(tail1, tail2, &headR, &tailR); // Multiply
            if(sign1 != sign2) printf("-"); // Sign handling  
            break;

        case '/':
            division(head1, head2, &headR, &tailR); // Division
            if(sign1 != sign2) printf("-"); // Sing handling
            break;
             
		case '%':   
        	modulus(head1, head2, &headR, &tailR); // Modulus
        	if(sign1 != sign2 && !(headR->data == 0 && headR->next == NULL))
            	printf("-"); // Handle negative remainder

        	break;	

        default:
            printf("Invalid operator\n");
			{
				return FAILURE;
			}
    }

    print_list(headR); // Print result
    printf("\n");

    return SUCCESS;
}