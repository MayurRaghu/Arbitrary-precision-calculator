#include "apc.h" 
int finding_largest(Dlist **head1, Dlist **head2, Dlist **tail1, Dlist **tail2, Dlist **headR, Dlist **tailR, int count1, int count2)
{
    Dlist *t1 = *head1;
    Dlist *t2 = *head2;
    while(t1->data == t2->data && count1 == count2)
    {
	if(t1->next != NULL)
	{
	    t1 = t1->next;
	    t2 = t2->next;
	}
	else
	    break;

    }
    if(t1->data <= t2->data && count1 <= count2)
    {
	swap(head1, head2, tail1, tail2);
	return SUCCESS;
    }
    else
	return FAILURE;

}
