#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARR_SIZE 256

static int foo(char* array)
{
	char* alias = array;
	/* Do some work so code isn't optimized away by the compiler */
	for (int i = 0; i < ARR_SIZE; i++) {
		printf("%c", array[i]);
	}
	free(alias);
	return 0;
}

int main(int argc, char* argv[])
{
	char* array = malloc(ARR_SIZE);
	if (array == NULL) {
		return -1;
	}
	memset(array, 'A', ARR_SIZE);
	int rv = foo(array);
	/* Array has been freed by foo, accessing a freed pointer is a big
	 * security issue. */
	memset(array, 'B', ARR_SIZE);
	return rv;
}
