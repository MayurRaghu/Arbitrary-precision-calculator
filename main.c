/**************************************************************************************************************************************************************
 *Title		: main function(Driver function)
 *Description	: This function is used as the driver function for the all the functions
 ***************************************************************************************************************************************************************/
#include "apc.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int main()
{
    /* Declare the pointers */
    Dlist *head1=NULL, *tail1=NULL, *head2 = NULL, *tail2 = NULL, *headR = NULL, *tailR = NULL;
    char option, operator, count1=0, count2=0;
    char str[100] = {'\0'};
    int size, count = 0, i,data;
    do
    {
	printf("Enter expression\n");
	scanf("%[^\n]s",str);
	size = strlen(str);
	size=size-1;
	printf("%d\n",size);
	int op_flag = 0;
	int op_flag2 = 0;
	int op_flag3 = 0;
	char op, op2;
	printf("str[0]: %c\n",str[0]);
	char temp[100] = {'\0'};
	for(i=0;str[i]!= '\0';i++)
	{
	    if(str[size-i] == '+' || str[size-i] == '-' || str[size-i] == '*')
	    {
		op2 = str[size - i -1];
		op = str[size-i];
		break;
	    }
	}
	printf("op: %c\n",op);
	printf("op2: %c\n",op2);
	for(i=0;str[i]!= '\0';i++)
	{
	    if(str[size-i] == '+' || str[size -i] == '-'|| str[size-i] == '*' || str[size-i] == '/')
	    {
		operator = str[size-i];
		op_flag =1;
	    }
	    else if(op_flag == 1)
	    {
		*temp = str[size-i];
		data = atoi(temp);
		insert_first(&head1, &tail1, data);
		count1++;
	    }
	    else if(op_flag == 0)
	    {
		*temp = str[size-i];
		data = atoi(temp);
		insert_first(&head2, &tail2, data);
		count2++;
	    }
	}
	//printf("str: %c\n"str[size - count - 3]);
	if(str[0] == '-' && op == '-' && op2 != '*')
	{
	    printf("negative addition\n");
	    op_flag2 = 1;
	    operator = '+';
	}
	else if(str[0] == '-' && op == '+')
	{
	    printf("subtraction with first index as - and second index as +\n");
	    op_flag2 = 1;
	    operator = '-';
	}
	else if(str[0] == '+' && op == '-')
	{
	    printf("subtraction with first index as + and second index as -\n");
	    op_flag3 = 1;
	    operator = '-';
	}
	else if(str[0] == '-' && op == '*' && op2 != '-')
	{
	    printf("negative multiplication\n");
	    operator = '*';
	    op_flag2 = 1;
	}
	else if(op2 == '*' && op == '-' && str[0] != '-')
	{
	    printf("neg mul\n");
	    operator = '*';
	    op_flag2 = 1;
	}
	else if(str[0] == '-' && op == '-')
	{
	    printf("pos mul\n");
	    operator = '*';
	    op_flag2 = 0;
	}
	printf("operator %c\n", operator);
	print_list(head1);
	print_list(head2);
	/* Code for reading the inputs */
	/* Function for extracting the operator */
	switch (operator)
	{
	    case '+':
		printf("addition\n");
		addition(&head1,&tail1, &head2, &tail2, &headR, &tailR);
		if(op_flag2 == 1)
		    (*headR).data = ((*headR).data*(-1));
		print_list(headR);
		break;
	    case '-':
		printf("Subtraction\n");
		printf("count1 : %d\n",count1);
		printf("count2 : %d\n",count2);
		if(finding_largest(&head1, &head2, &tail1, &tail2, &headR, &tailR, count1, count2) == SUCCESS)
		{
		    printf("swapped\n");
		    subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR, count1, count2);
		    (*headR).data = (*headR).data*(-1);
		}
		else
		{
		    printf("not swapped\n");
		    subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR, count1, count2);
		}
		if(op_flag2 == 1)
		{
		    (*headR).data = (*headR).data*(-1);
		}

		print_list(headR);
		break;
	    case '*':
		printf("multiplication\n");
		multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR);
		if(op_flag2 == 1)
		{
		    (*headR).data = (*headR).data*(-1);
		}
		print_list(headR);
		break;
	    case '/':
		printf("Division\n");
		division(&head1, &tail1, &head2, &tail2, &headR, &tailR, count1 ,count2);
		print_list(headR);
		break;
	    default:
		printf("Invalid Input:-( Try again...\n");
	}
	printf("Want to continue? Press [yY | nN]: ");
	scanf("\n%c", &option);
    }while (option == 'y' || option == 'Y');
    return 0;
}
