#ifndef LIST
#define LIST

typedef struct _Node
{
void *data;
struct _Node*next;
}Node;

typedef struct List{
int Length;
int SizeOfElements;
Node*head;
Node*tail;
}List;

void initList(List*list, int SizeOfElements);
void addHead(List*list, void *DATA);
void addTail(List*list,void *DATA);
void Insert(List*list ,void*DATA,int position);
void Delete(List*list,int position);
void clearList(List*list);
void print(List*list);
void reverse(List*list);
void TestIntList();
void TestStringList();
void TestDoubleList();






#endif 