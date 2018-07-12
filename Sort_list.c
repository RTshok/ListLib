#include "list.h"
#include "Sort_list.h"
#include <string.h>

int cmp_int (const void *a ,const void *b)
{
int val1 = *(int*)a;
int val2 = *(int*)b;

return(val1-val2);
}
int cmp_strings(const void *a,const void *b)
{
	char *val1 = *(char**)a;
	char *val2 = *(char**)b;
	
	return strcmp(val1,val2);
}
int cmp_double (const void *a,const void *b)
{
	double val1 = *(double*)a;
	double val2 = *(double*)b;

	return(val1-val2);
}
void swap(Node*a , Node*b)
{	
	
	void* temp = a->data;
    a->data = b->data;
    b->data = temp;

}
void sort(List*list)
{
	if(list->SizeOfElements == sizeof(int))
	{
		Node* tmp = list->head;
		Node* lastNode =NULL;
		int swapped;
		if(tmp == NULL)
		return;
	do{
	swapped = 0;
	tmp = list->head;
	while(tmp->next !=lastNode)
	{
		if(cmp_int(tmp->data,tmp->next->data)>0)
		{
			swap(tmp,tmp->next);
			swapped = 1;
		}
		tmp = tmp->next;
	}
	
	lastNode = tmp;
	}while(swapped);
	}

	if(list->SizeOfElements == sizeof(char*))
	{
	Node* tmp = list->head;
		Node* lastNode =NULL;
		int swapped;
		if(tmp == NULL)
		return;
	do{
	swapped = 0;
	tmp = list->head;
	while(tmp->next !=lastNode)
	{
		if(cmp_strings(tmp->data,tmp->next->data)>0)
		{
			swap(tmp,tmp->next);
			swapped = 1;
		}
		tmp = tmp->next;
	}
	
	lastNode = tmp;
	}while(swapped);
	}

	if(list->SizeOfElements == sizeof(double))
	{
	Node* tmp = list->head;
		Node* lastNode =NULL;
		int swapped;
		if(tmp == NULL)
		return;
	do{
	swapped = 0;
	tmp = list->head;
	while(tmp->next !=lastNode)
	{
		if(cmp_double(tmp->data,tmp->next->data)>0)
		{
			swap(tmp,tmp->next);
			swapped = 1;
		}
		tmp = tmp->next;
	}
	
	lastNode = tmp;
	}while(swapped);
	}
	printf("the List has been sorted!\n");
}