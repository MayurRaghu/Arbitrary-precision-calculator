#include"apc.h"
int swap(Dlist **head1, Dlist **head2, Dlist **tail1, Dlist **tail2)
{
	Dlist *temp;
	Dlist *temp2;
	temp = *head1;
	*head1 = *head2;
	*head2 = temp;

	temp2 = *tail1;
	*tail1 = *tail2;
	*tail2 = temp2;
}

