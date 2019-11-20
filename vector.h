#include <stdlib.h>
#include <limits.h>

int capacity_bound (int size)
{
	int bound = 1;

	while (bound < size)
		bound <<= 1;

	return bound;
}

typedef struct _vector
{
	int* base;

	int size;
	int capacity;
}
vector;

vector vector_new (int);
int resize (vector* v, int);
int reserve (vector* v, int);
void shrink_to_fit (vector* v);

int* insert (vector*, int*, int);
int* erase (vector*, int*);
int* push_back (vector* v, int);
int* pop_back (vector* v, int);

int* at (vector, int);
int front (vector);
int back (vector);
int* begin (vector);
int* end (vector);
int size (vector);
int capacity (vector);

int reserve (vector* v, int capacity)
{
	if (capacity > v -> capacity)
	{
		int temp_capacity = capacity_bound (capacity);
		int* temp = (int*) realloc (v -> base, sizeof (int) * temp_capacity);

		if (temp)
		{
			v -> base = temp;
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
		v -> base = (int*) realloc (v -> base, sizeof (int) * (v -> capacity = capacity_bound (size)));
		v -> size = size;

		return 0;
	}
	else if (v -> size <= size && size <= v -> capacity)
		v -> size = size;
	else if (!reserve (v, size))
	{
		v -> size = size;

		return 0;
	}
	else
		return INT_MAX;
}

vector vector_new (int size)
{
	vector v = {NULL, 0, 0};
	resize (&v, size);

	return v;
}

int* insert (vector* v, int* p, int x)
{
	if (begin (*v) <= p && p <= end (*v))
	{
		int idx = p - begin (*v);

		if (v -> size == v -> capacity)
			reserve (v, v -> capacity + 1);
		
		p = begin (*v) + idx;

		for (int* i = end (*v); i > p; --i)
			*i = *(i - 1);
		*p = x;
		++(v -> size);

		return p;
	}
	else
		return NULL;
}

int* push_back (vector* v, int x)
{
	return insert (v, end (*v), x);
}

int* at (vector v, int idx)
{
	if (0 <= idx && idx < v.size)
		return v.base + idx;
	else
		return NULL;
}

int front (vector v)
{
	return *at (v, 0);
}

int back (vector v)
{
	return *(end (v) - 1);
}

int* begin (vector v)
{
	return v.base;
}

int* end (vector v)
{
	return v.base + v.size;
}

int size (vector v)
{
	return v.size;
}

int capacity (vector v)
{
	return v.capacity;
}
