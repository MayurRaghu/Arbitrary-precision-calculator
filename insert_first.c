
#include"apc.h"

int insert_first(Dlist **head, Dlist **tail, int data)
{
    Dlist *new_node = malloc(sizeof(Dlist));
    new_node->prev = NULL;
    new_node->next = NULL;
    new_node->data = data;
    if(*head == NULL)
    {
	*head = new_node;
	*tail = new_node;
    }
    else
    {
	new_node->next = *head;
	(*head)->prev = new_node;
	(*head) = new_node;
    }
}
