#ifndef sort_list
#define sort_list
#include"list.h"

void sort (List*list);
int cmp_int (const void *a ,const void *b);
int cmp_strings(const void *a,const void *b);
int cmp_double (const void *a,const void *b);
void swap(Node*a , Node*b);

#endif