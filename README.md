# vector
A vector implementation for C.

### Status
Currently in progress.

## How to add?
Currently in progress.

## Usage
```c
vector vector_new (int size)
```
> returns a vector with a guaranteed minimum size of `size`.

```c
int reserve (vector* v, int size)
```
> Reserves `size` amount of size for the vector if the current vector cannot accommodate at least `size` amount of elements. Returns non-zero in case of failure/lack of enough available space.
