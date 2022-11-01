/*******************************************************************************************************************************************************************
 *Title			: Multiplication
 *Description		: This function performs multiplication of two given large numbers and store the result in the resultant list.
 *Prototype		: int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
 *Input Parameters	: head1: Pointer to the first node of the first double linked list.
 : tail1: Pointer to the last node of the first double linked list.
 : head2: Pointer to the first node of the second double linked list.
 : tail2: Pointer to the last node of the second double linked list.
 : headR: Pointer to the first node of the resultant double linked list.
 *Output			: Status (SUCCESS / FAILURE)
 *******************************************************************************************************************************************************************/
#include "apc.h"

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    int data, carry=0, i=0,mul=0;
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;
    Dlist *h1 = NULL;
    Dlist *t1 = NULL;

    Dlist *h2 = NULL;
    Dlist *t2 = NULL;
    while(temp2 != NULL)
    {
	h1 = NULL;
	t1 = NULL;
	*headR = NULL;
	*tailR = NULL;
	for(i=0;i<mul;i++)
	{
	    insert_first(&h1, &t1, 0);
	}
	mul++;
	while(temp1!= NULL)
	{
	    data = (temp1->data * temp2->data) + carry;
	    if(data > 9)
		carry = data/10;
	    else
		carry = 0;
	    data = data % 10;
	    insert_first(&h1, &t1, data);

	    temp1=temp1->prev;
	}
	temp1 = *tail1;
	if(carry != 0)
	{	
	    insert_first(&h1, &t1, carry);
	    carry = 0;
	}
	if(temp2->prev == NULL && temp2->next == NULL)
	{
	    *headR = h1;
	    *tailR = t1;
	}
	else if(h2 == NULL)
	{
	    h2 = h1;
	    t2 = t1;
	}
	else if(temp2->prev != NULL)
	{
	    addition(&h1, &t1, &h2, &t2, headR, tailR);
	    h2 = (*headR);
	    t2 = (*tailR);
	}
	else
	{
	    addition(&h1, &t1, &h2, &t2, headR, tailR);
	}
	temp2 = temp2->prev;
    }
}
