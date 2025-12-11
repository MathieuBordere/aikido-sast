#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARR_SIZE 256

static int foo(char* array)
{
	for (int i = 0; i < ARR_SIZE; i++) {
		printf("%c", array[i]);
	}
	return 0;
}

int main(int argc, char* argv[])
{
	char *array = malloc(ARR_SIZE);
	if (array == NULL) {
		return -1;
	}
	memset(array, 'A', ARR_SIZE);
	free(array);
	/* Oops pass freed pointer. */
	int rv = foo(array);
	return rv;
}
