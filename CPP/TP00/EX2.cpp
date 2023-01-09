#include <cstddef>
#include <iostream>

struct cell {
    int X;
    struct cell* following;
};

typedef struct cell cell;
typedef struct cell*  list;

void push(list* L, int n) {
    list C = (cell*)malloc(sizeof(cell));
    C->X = n;
    C->following = *L;
    *L = C;
}
void show(list L){
    while (L != NULL ) {
        std::cout << L->X << " ";
        L = L->following;
    }
    std::cout << "\n";
}

void reverse(list* L, int k){
    list temp = *L;
    int delim = 0;
    while (temp->following != NULL && delim < k-1) {
        list temp2 = temp->following;
        temp->following = temp2->following;
        temp2->following = *L;
        *L = temp2;
        delim++;
    }
}

int main (int argc, char *argv[]) {
    list L = NULL;
    push(&L, 1);
    push(&L, 2);
    push(&L, 3);
    push(&L, 4);
    push(&L, 5);
    push(&L, 6);
    show(L);
    reverse(&L, 4334);
    show(L);
    return 0;
}
