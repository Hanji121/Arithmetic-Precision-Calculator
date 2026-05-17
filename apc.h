#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

#define SAME 0
#define OPERAND1 1
#define OPERAND2 2

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} node;

/* Operations */
void addition(node *, node *, node **, node **);
void subtraction(node *, node *, node **, node **);
void multiplication(node *, node *, node **, node **);
void division(node *, node *, node **, node **);

/* Helpers */
int cla_validation(int argc, char *argv[]);
void create_list(char *, node **, node **);
int insert_first(node **, node **, int);
int insert_last(node **, node **, int);
void insert_at_begin(node **, node **, int);
void print_list(node *);
void remove_pre_zeros(node **);
void copy_list(node *src, node **dest_head, node **dest_tail);
int compare_list(node *, node *);
void modulus(node *head1, node *head2, node **headR, node **tailR);
node* get_tail(node *head);

#endif