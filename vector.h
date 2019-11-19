#include <stdio.h>
#include <stdlib.h>

typedef struct _vector
{
	int* base_addr;

	int size;
	int capacity;
}
vector;

vector vector_new (int);
int resize (vector* v, int);
int reserve (vector* v, int);
void shrink_to_fit (vector* v);
int* access (vector, int);
int* insert (vector*, int);
int* erase (vector*, int);
int* push_back (vector* v, int);
int* pop_back (vector* v, int);
