#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>    
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


char* conct(char* dest, char* src, int n){
	int size_dest;
	int size_src;
	for(size_dest = 0; dest[size_dest] != '\0'; ++size_dest);
	for(size_src = 0; src[size_src] != '\0'; ++size_src);
	if(n > size_src) n = size_src;
	int size = size_dest + n;
	char* final = malloc(size);
	for(int i = 0; i < size_dest; i++) final[i] = dest[i];
	for(int i = size_dest; i < size; i++) final[i] = src[i-size_dest];
	free(dest);
	return final;
}

char* trim(char* buffer, int n){
	int size;
	for(size = 0; buffer[size] != '\0'; ++size);
	char* final = malloc(size - n);
	for(int i = 0; i < size - n; i++){
		final[i] = buffer[n+i];
	}
	free(buffer);
	return final;
}

static char* off_set;
static int count;

char* read_lines(int fd){
	char* nt = malloc(BUFFER_SIZE);
	if(off_set != NULL) for(count = 0; off_set[count] != '\0'; ++count);
	char* final = malloc(1);
	int f = 0;
	int k = read(fd, nt, BUFFER_SIZE);
	if(k + count == 0) return NULL;
	if(count != 0 ) nt = conct(off_set, nt, BUFFER_SIZE);
	while(f != 1){
		if(k + count == 0) return NULL;
		for(int i = 0; i < k + count; i++){
			if(nt[i] == '\n'){
				final = conct(final, nt, i+1);
				if(i < k + count -1){ 
					off_set = malloc(k + count-1-i);
					for(int j = 0; j < k + count -i; j++) off_set[j] = nt[i+j+1];
					count = k+count-i-1;
				}
				else {
					off_set = NULL; 
					count = 0;
				}
				f = 1;
				break;
			}
		}	
		if(f == 0){
			final = conct(final, nt, k + count);
			count = 0;
			off_set = NULL;
			k = read(fd, nt, BUFFER_SIZE);
		}
	}
	free(nt);
	return final;
}

