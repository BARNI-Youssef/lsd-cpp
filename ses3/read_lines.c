#include "read_lines.h"

void add_element(list* L, char element){
    cell* C = malloc(sizeof(cell));                             // allocate the memory for the new cell.
    C->following = NULL;                                        // make this cell the end of the list.
    C->X = element;                                             // put the new element in the cell.
    if(*L == NULL) *L = C;                                      // if the list is empty, make the ne cell the first element.
    else{
        list temp = *L;
        while (temp->following != NULL) temp = temp->following; // go to the end of the list.
        temp->following = C;                                    // add the new cell at the end of the list.
    }
}

list next_delim(list L){
    list temp = L;
    while (temp != NULL) {
        if (temp->X == '\n' || temp->X == '\0') return temp;    // if the cell containt a EOL or EOF character, return it.
        temp = temp->following;
    }
    return temp;                                                // return a NULL pointer if there isn't a end character.
}

void write_in_list(char* buffer, list* L, int n){
    for (size_t i = 0; i < n; i++) add_element(L, buffer[i]);   // filling the list with the characters of the string.
}

char* read_lines(int fd){
    static list L = NULL;                                       // static variable to stock all the read characters.
    int size;                                                   // variable to stock the length to the string read at each time.
    char* buf = malloc(BUFFER_SIZE);                            // string to stock the read characters.
    if (!buf) fprintf(stderr, "Memory allocation failed!\n");   // malloc check.
    size = read(fd, buf, BUFFER_SIZE);                          // getting the number of characters written in buf.
    if (size == 0 && L == NULL) return NULL;                    // checking if there's smth left to read, if not, return NULL.
    write_in_list(buf, &L, size);                               // add all the read characters in the list.
    list a = next_delim(L);                                     // check if the list contain a full line.
    while (a == NULL) {                                         // continue reading as long as the list does not have a full line.
        size = read(fd, buf, BUFFER_SIZE);                      // .
        write_in_list(buf, &L, size);                           // .
        a = next_delim(L);                                      // .
    }                                                           // .
    int final_size = 0;                                         // variable to stock the length of the line.
    list temp = L;
    while (temp != a->following) {                              // counting the length of the line.
        temp = temp->following;
        final_size++;
    }
    char *final = malloc(final_size * sizeof(char) + 1);        // allocating the space for the line.
    if (!final) fprintf(stderr, "Memory allocation failed!\n"); // malloc check.
    for (size_t i = 0; i < final_size; i++) {                   // filling the final string.
        final[i] = L->X;
        temp = L;
        L = L->following;
        free(temp);                                             // freeing the used memory.
    }
    final[final_size] = '\0';                                   // puting a EOF character at the end of the string.
    free(buf);                                                  // freeing the buffer used for reading.
    return final;                                               // returning the line read.
}

int main (){
    int fd = open("read_lines.c", O_RDONLY);
    char* buffer = read_lines(fd);
    while (buffer != NULL) {
        printf("%s", buffer);
        free(buffer);
        buffer = read_lines(fd);
    }
    return 0;
}
