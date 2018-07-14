#include <stdio.h>
#include "list.h"
#include<stdlib.h>
#include<string.h>
#include "Sort_list.h"
/**
* initList - initiation of the list
* @list - the list which need to be initiated
* @SizeOfElements - size of elements which will be in the list
*
* That function initiate the list. This is the first function you must to use to work with the list.
*
*/
void initList(List*list, int SizeOfElements)
{
	list->head = list->tail = NULL;
	list->SizeOfElements = SizeOfElements;
	list->Length = 0;
}
/**
* addHead - add head to the list.
* @list - the list in what we want to add the head.
* @DATA - information,arrays,numbers.
* 
* This function adds head to the chosen list.
*
*/
void addHead(List*list,void *DATA)
{
	Node*theNewHead = malloc (sizeof(Node));
	theNewHead->data = malloc(list->SizeOfElements);
	memcpy(theNewHead->data, DATA, list->SizeOfElements);
	
	theNewHead->next = list->head;
	list->head = theNewHead;
	
	if(list->Length == 0)
	list->tail = list->head;
	
	list->Length++;
	printf("the Head added!\n");
}

/**
* addTail - add tail to the list.
* @list - the list in what we want to add the tail.
* @DATA - information,arrays,numbers.
* 
* This function adds tail to the chosen list.
*
*/

void addTail(List*list,void*DATA)
{	
	Node*theNewTail = malloc (sizeof(Node));
	theNewTail-> data = malloc(sizeof(list->SizeOfElements));
	theNewTail->next = NULL;

	memcpy(theNewTail->data, DATA, list->SizeOfElements);
	
	if(list->Length == 0){
	list->head = list->tail = theNewTail;
	
	}
	else {
	list->tail->next = theNewTail;
	list->tail = theNewTail;
	
	}
	list->Length++;
	printf("the Tail added!\n");
}
/**
* clearList - deleting all information from the nodes
* @list - the list which need to be freed
*
* This function frees the memory which was allocated and delete the data in the list.
*/

void clearList(List*list)
{
	Node * current = list->head;
	Node* next;
	while(current!=NULL)
	{
	next = current->next;
	free(current->data);
	free(current);
	current = next;
	list->Length--;
	}
list->head = NULL;
printf("the data from the list has been successfully removed !\n");
}
/**
* Insert - inserting the node at exact position.
* @list - the list to insert the node
* @DATA - the data that need to be inserted.
* @position - position in the list to paste the data.
*
* This function has a lot of checking by position. If position 0, call function 'addHead', if position is list->Length +1, call addTail.
* Then if we haven't added the node earlier, traversing the list, and find the position to insert the data.
*
*/
void Insert (List*list,void *DATA,int position)
{	if(position <0 || position >list->Length+1)
	{
	printf("the Position is incorrect! Check it. \n");
	return;
	}
	if(position == 0)
{
	addHead(list,DATA);
	return ;
}
	if(position == list->Length+1)
{
	addTail(list,DATA);
	return ;
}	

	Node*theNewNode = malloc(sizeof(Node));
	theNewNode->data = malloc(sizeof(list->SizeOfElements));
	memcpy(theNewNode->data, DATA, list->SizeOfElements);
	Node*tmp = list->head;
	Node*prev = NULL;
	
	int i = 0;
	while(1)
	{	if(i!=position-1)
		{
		tmp = tmp->next;
		i++;
		}
		if(i==position-1)
		{
		prev = tmp;
		tmp = tmp->next;
		prev->next = theNewNode;
		theNewNode->next = tmp;
		list->Length++;
		printf("the data has been successfully inserted at position :%i \n",position);
		break;
		}
	
	}
	
	
}
/**
* Delete - deleting the node at exact position
* @list - the list to do operation
* @position - at that position we do the deletion
*
* That function frees the memory that used data and the node.
*
*/
void Delete (List*list,int position)
{
	if(position <0 || position >list->Length-1)
	{
	printf("the Position is incorrect! Check it. \n");
	return;	
	}


	Node*theNodetoDel= list->head;
	Node*prev = NULL;
	Node*next = NULL;

	if(position == 0)
	{	
	next = theNodetoDel->next;
	list->head = next;
	free(theNodetoDel->data);
	free(theNodetoDel);
	list->Length --;
	return;
	}

	if(position == list->Length)
	{
	int i = 0;
	while(1)
	{
	if(i==list->Length-1)
	{
	prev = theNodetoDel;
	theNodetoDel = theNodetoDel->next;
	list->tail = prev;
	free(theNodetoDel->data);
	free(theNodetoDel);
	list->Length --;	
	return;
	}
	theNodetoDel=theNodetoDel->next;
	i++;	
	}
	}

	int i = 0;
	while(1)
	{	
	if(i==position-1)
	{
	prev = theNodetoDel;
	theNodetoDel = theNodetoDel->next;
	next = theNodetoDel->next;
	prev->next = next;
	free(theNodetoDel->data);
	free(theNodetoDel);
	list->Length --;
	return;
	}
	theNodetoDel = theNodetoDel->next;
	i++;
	}
}
/**
* reverse - the nodes are pointing to the opposite direction.
* @list - the list to do the operation
*
* That function reversing the pointers and repoint the head and the tail.
* ||->||->||->||->NULL
* NULL<-||<-||<-||<-|| 
*/
void reverse (List*list)
{
	Node* current,*prev,*next,*tmptail;
	current = list->head;
	tmptail = current;
	
	prev = NULL;
	while(current!=NULL)
	{
	next = current->next;
	current->next = prev;
	prev = current;
	current = next;
	}
	list->head = prev;
	list->tail = tmptail;
	list->tail->next = NULL;
}
/**
* print - print all the nodes
* @list - the list to do the operation
*
* That function could print the data of different data types.
*
*/
void print(List*list) {

Node *theNode = list->head ; 

if(list->head==NULL)
		{
	printf("the List is empty!\n");
	return;
		}
if(list->SizeOfElements == sizeof(char*))
		{

	int i = 0;
	while(theNode!=NULL)
	{	
	printf("theNode %i has data :%s\n",i,*(char**)theNode->data);
	theNode = theNode->next;
	i++;
	}
	printf("the Length is : %i \n",list->Length);
	return;
		}

if(list->SizeOfElements == sizeof(int))
		{
	int i = 0;
	while(theNode!=NULL)
	{	
	printf("theNode %i has data :%d\n",i,*(int*)theNode->data);
	theNode = theNode->next;
	i++;
	}
	printf("the Length is : %i \n",list->Length);
	return;
		}

if(list->SizeOfElements == sizeof(double))
		{
	int i = 0;
	
	while(theNode!=NULL)
	{	
	printf("theNode %i has data :%lf\n",i,*(double*)theNode->data);
	theNode = theNode->next;
	i++;
	}
	printf("the Length is : %i \n",list->Length);
	return;
		}
}
void TestIntList (List newList)
{
initList(&newList,sizeof(int));
int i =10;
int k = 15;
int d = 45;
int b = 20;
addHead(&newList,&i);
addHead(&newList,&k);
addHead(&newList,&d);
addTail(&newList,&b);
Insert(&newList,&i,0);
Insert(&newList,&i,6);
Insert(&newList,&i,9);
print(&newList);
Delete(&newList,0);
sort(&newList);
print(&newList);
reverse(&newList);
print(&newList);
clearList(&newList);
}

void TestStringList(List stringList)
{
int numPlanets = 8;
char * planets[] = {"Mercury","Venus","Earth","Mars","Jupiter","Saturn","Uranus","Neptune"};
initList(&stringList,sizeof(char*));
char *planet ;
for(int i = 0; i<numPlanets; i++){
planet = strdup(planets[i]);
Insert(&stringList,&planet,i);

}
print(&stringList);
char *newPlanet = "AlphaCentaura";
Insert(&stringList,&newPlanet,4);

print(&stringList);
Delete(&stringList,0);
print(&stringList);
sort(&stringList);
print(&stringList);
reverse(&stringList);
print(&stringList);
clearList(&stringList);

}

void TestDoubleList(List doubleList)
{
initList(&doubleList,sizeof(double));
double i =10.5;
double k = 15.5;
double d = 45.2;
double b = 20.61;
addHead(&doubleList,&i);
addHead(&doubleList,&k);
addHead(&doubleList,&d);
addTail(&doubleList,&b);
Insert(&doubleList,&i,0);
Insert(&doubleList,&i,6);
Insert(&doubleList,&i,9);
print(&doubleList);
printf("huinya\n");
Delete(&doubleList,0);
sort(&doubleList);
print(&doubleList);
reverse(&doubleList);
print(&doubleList);
clearList(&doubleList);
}
