/*******************************************************************************************************************************************************************
*Title			: Addition
*Description		: This function performs addition of two given large numbers and store the result in the resultant list.
*Prototype		: int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    int carry = 0,data;
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;
    while(temp1 != NULL || temp2!= NULL)
    {
	if(temp1 != NULL && temp2 == NULL) 
	    data = temp1->data + carry;
	else if(temp2 != NULL && temp1 == NULL)
	    data = temp2->data + carry;
	else
	{
	    data = temp1->data + temp2->data + carry;
	}
	if(data > 9)
	{
	    carry = 1;
	    data = data-10;
	    insert_first(headR, tailR, data);
	}
	else
	{
	    insert_first(headR, tailR, data);
	    carry = 0;
	}
	if(temp1 != NULL)
	{
	    temp1 = temp1->prev;
	}
	if(temp2 != NULL)
	{
	    temp2 = temp2->prev;
	}
    }
    if(carry == 1)
	insert_first(headR, tailR, carry);
    return SUCCESS;
}
