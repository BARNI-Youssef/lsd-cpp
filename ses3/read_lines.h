#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

struct cell{
    char X;
    struct cell* following;
};

typedef struct cell cell;
typedef struct cell* list;

void add_element(list*, char);         // add a charater at the end of a list.
list next_delim(list);                 // return the adress of the cell that contain the first EOL, return null if there isn't any.
void write_in_list(char*, list*, int); // write the fisrt nth charcaters of a string in a list.
char* read_lines(int);                 // return a full line from a file.
