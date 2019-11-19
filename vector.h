#include <stdlib.h>
#include <limits.h>

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

int capacity_bound (int size)
{
	int bound = 1;

	while (bound < size)
		bound <<= 1;

	return bound;
}

int reserve (vector* v, int capacity)
{
	if (capacity > v -> capacity)
	{
		int temp_capacity = capacity_bound (capacity);
		int* temp = (int*) realloc (v -> base_addr, sizeof (int) * temp_capacity);

		if (temp)
		{
			v -> base_addr = temp;
			v -> capacity = temp_capacity;

			return 0;
		}
		else
			return INT_MAX;
	}
	else
		return 0;
}

int resize (vector* v, int size)
{
	if (size == v -> size)
		return 0;
	else if (size < v -> size)
	{
		v -> base_addr = (int*) realloc (v -> base_addr, sizeof (int) * (v -> capacity = capacity_bound (size)));
		v -> size = size;

		return 0;
	}
	else
	{
		if (!reserve (v, size))
		{
			v -> size = size;

			return 0;
		}
		else
			return INT_MAX;
	}
}

vector vector_new (int size)
{
	vector v = {(int*) calloc (1, sizeof (int)), 1, 1};
	resize (&v, size);

	return v;
}

int* access (vector v, int idx)
{
	if (idx < v.size)
		return v.base_addr + idx;
	else
		return NULL;
}
