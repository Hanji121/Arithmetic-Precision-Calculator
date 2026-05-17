#include "apc.h"

// Function definitions

int cla_validation(int argc, char *argv[])
{
    char op = argv[2][0];

    // Check valid operator
    if(op != '+' && op != '-' && op != '*' && op != '/' && op != 'x' && op != 'X' && op != '%')
    {
        return FAILURE;
    }

    for(int i = 0; argv[1][i]; i++) // check second operand is numeric
    {
        if(argv[1][i] < '0' || argv[1][i] > '9')
        {
            return FAILURE;
        }
    }

    for(int i = 0; argv[3][i]; i++) // check second operand is numeric
    {
        if(argv[3][i] < '0' || argv[3][i] > '9')
        {
            return FAILURE;
        }
    }
    return SUCCESS;
}

void create_list(char *opr, node **head, node **tail)
{
    for(int i = 0; opr[i] != '\0'; i++)
    {
        insert_last(head, tail, opr[i] - '0'); // Insert digit 
    }
}

int insert_first(node **head, node **tail, int data)
{
    node *new = malloc(sizeof(node)); // Allocate memory
    if(new == NULL)
    {
        return FAILURE;
    }

    new->data = data;
    new->prev = NULL;
    new->next = NULL;

    if(*head == NULL) // If list is empty
    {
        *head = *tail = new;
    }
    else
    {
        new->next = *head;
        (*head)->prev = new;
        *head = new;
    }
    return SUCCESS;
}

int insert_last(node **head, node **tail, int data)
{
    node *new = malloc(sizeof(node)); // Allocate memory
    if(new == NULL)
    {
        return FAILURE;
    }    

    new->data = data;
    new->next = NULL;
    new->prev = NULL;

    if(*head == NULL)
    {
        *head = *tail = new;
    }
    else
    {
        (*tail)->next = new;
        new->prev = *tail;
        *tail = new;
    }
    return SUCCESS;
}

int delete_list(node **head, node **tail)
{
    if(*head == NULL)
    {
        return FAILURE;  // list already empty
    }

    node *temp = *head;

    while(temp != NULL)
    {
        node *next = temp->next; // Store next node
        free(temp); // Free current node 
        temp = next;
    }

    *head = NULL;
    *tail = NULL;

    return SUCCESS;
}

void print_list(node *head)
{
    if(head == NULL)
    {
        printf("Empty list");
        return;
    }

    while(head)
    {
        printf("%d", head->data); // Print digit
        head = head->next;
    }
}

int compare_list(node *head1, node *head2)
{
    int len1 = 0, len2 = 0;

    node *t1 = head1, *t2 = head2;

    while(t1) { len1++; t1 = t1->next; } // Count length1
    while(t2) { len2++; t2 = t2->next; } // Count length2

    if(len1 > len2) return OPERAND1;
    if(len2 > len1) return OPERAND2;

    while(head1 && head2) // Compare digit by digit
    {
        if(head1->data > head2->data) return OPERAND1; 
        if(head2->data > head1->data) return OPERAND2;

        head1 = head1->next;
        head2 = head2->next;
    }

    return SAME; // Both equal
} 
int list_len(node *head)
{
    int count = 0;
    while(head)
    {
        count++;
        head = head->next;
    }
    return count;
}

void remove_pre_zeros(node **head)
{
    while(*head && (*head)->data == 0 && (*head)->next != NULL)
    {
        node *temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp); // Delete zero node
    }
}

void insert_at_begin(node **head, node **tail, int data)
{
    node *new = malloc(sizeof(node)); // Allocate memory

    if(new == NULL)
    {
        return;
    }

    new->data = data;
    new->prev = NULL;
    new->next = *head;

    if(*head != NULL)
    {
        (*head)->prev = new;
    }
    else
    {
        *tail = new; // First node
    }
    *head = new;
} 
void copy_list(node *head, node **new_head, node **new_tail)
{
    while(head != NULL)
    {
        insert_last(new_head, new_tail, head->data); // Copy data
        head = head->next;
    }
}