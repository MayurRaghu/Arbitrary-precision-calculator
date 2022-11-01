#ifndef APC_H
#define APC_H
#define SUCCESS 0
#define FAILURE -1
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
typedef int data_t;
typedef struct node
{
	struct node *prev;
	data_t data;
	struct node *next;
}Dlist;

/* Include the prototypes here */
void print_list(Dlist *head);
int insert_first(Dlist **head, Dlist **taili,int data);
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR, int count1, int count2);
int swap(Dlist **head1, Dlist **head2, Dlist **tail1, Dlist **tail2);
int finding_largest(Dlist **head1, Dlist **head2, Dlist **tail1, Dlist **tail2, Dlist **headR, Dlist **tailR, int count1, int count2);
int sub(Dlist **head1, Dlist **head2, Dlist **tail1, Dlist **tail2, Dlist **headR, Dlist **tailR, int borrow);
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR, int count1, int count2);
#endif

