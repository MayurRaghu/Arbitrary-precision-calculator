/*******************************************************************************************************************************************************************
 *Title			: Subtraction
 *Description		: This function performs subtraction of two given large numbers and store the result in the resultant list.
 *Prototype		: int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
 *Input Parameters	: head1: Pointer to the first node of the first double linked list.
 : tail1: Pointer to the last node of the first double linked list.
 : head2: Pointer to the first node of the second double linked list.
 : tail2: Pointer to the last node of the second double linked list.
 : headR: Pointer to the first node of the resultant double linked list.
 *Output			: Status (SUCCESS / FAILURE)
 *******************************************************************************************************************************************************************/
#include "apc.h"

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR, int count1, int count2)
{
    int borrow = 0, data, flag=0;

    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;
    Dlist *trav1 = (*head1);
    Dlist *trav2 = (*head2);
    if(count1 == count2 && (*head1)->data == (*head2)->data)
    {
	if(finding_largest(head1, head2,tail1, tail2, headR, tailR, count1, count2)== SUCCESS)
	{
	    printf("john\n");
	    Dlist *temp1 = *tail1;
	    Dlist *temp2 = *tail2;
	    while(temp1!= NULL || temp2 != NULL)
	    {
		data = temp1->data - temp2->data + borrow;
		flag = 1;
		borrow = 0;
		if(data < 0)
		{
		    data = data+10;
		    borrow = -1;
		}
		insert_first(headR, tailR, data);
		if(temp1 != NULL)
		    temp1 = temp1->prev;
		if(temp2 != NULL)
		    temp2 = temp2->prev;
	    }
	}
	else
	{
	    printf("Hey\n");
	    while(temp1!= NULL || temp2 != NULL)
	    {
		data = (temp1->data) - temp2->data + borrow;
		borrow = 0;
		if(data < 0)
		{
		    data = data+10;
		    borrow = -1;
		}
		insert_first(headR, tailR, data);
		if(temp1 != NULL)
		    temp1 = temp1->prev;
		if(temp2 != NULL)
		    temp2 = temp2->prev;
	    }
	}
    }
    else
    {
	Dlist *temp1 = *tail1;
	Dlist *temp2 = *tail2;
	printf("harry\n");
	while(temp1!= NULL || temp2!= NULL)
	{
	    if(temp1 == NULL && temp2 != NULL)
	    {
		data = 0 - temp2->data + borrow;
		flag = 1;
		borrow = 0;
	    }
	    else if(temp1 != NULL && temp2 == NULL)
	    {
		data = temp1->data - 0 + borrow;
		borrow = 0;
	    }
	    else
	    {
		printf("lee\n");
		printf("temp1: %d\n",temp1->data);
		printf("temp2: %d\n",temp1->data);
		data = (temp1->data) - temp2->data + borrow;
		borrow = 0;
		flag = 0;
	    }
	    if(data < 0)
	    {
		data = data+10;
		borrow = -1;
	    }
	    insert_first(headR, tailR, data);
	    if(temp1 != NULL)
		temp1 = temp1->prev;
	    if(temp2 != NULL)
		temp2 = temp2->prev;
	}
    }
    Dlist *tempR = *headR;
    while((*headR)->data == 0 && tempR->next != NULL)
    {
	tempR->next->prev = (*headR);
	tempR = (*headR)->next;
	free(*headR);
	(tempR)->prev = NULL;
	*headR = tempR;
    }
}    
/*int sub(Dlist **head1, Dlist **head2, Dlist **tail1, Dlist **tail2, Dlist **headR, Dlist **tailR, int borrow)
  {
  Dlist *temp1 = *tail1;
  Dlist *temp2 = *tail2;
  int data;
  data = (temp1->data) - temp2->data + borrow;
  borrow = 0;
  if(data < 0)
  {
  data = data+10;
  borrow = -1;
  }
  insert_first(headR, tailR, data);

  }*/
