#include <cstddef>
#include <cstdlib>
#include <iostream>

struct cell {
    int X;
    struct cell* following;
};

typedef struct cell cell;
typedef struct cell* stack;

void push(stack* L, int n) {
    stack C = (cell*)malloc(sizeof(cell));
    C->X = n;
    C->following = *L;
    *L = C;
}

void push(stack* L) {
    if (*L == NULL) return;
    stack temp = *L;
    (*L) = (*L)->following;
    free(temp);
}
