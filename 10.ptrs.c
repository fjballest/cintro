#include <stdio.h>

int
main(int argc, char *argv[])
{
	int i;
	int *j;

	i = 3;
	j = NULL;

	printf("i %d at %p\n", i, &i);
	printf("j %p\n", j);

	j = &i;
	printf("j %p\n", j);
	*j = 5;
	printf("i %d at %p\n", i, &i);
	printf("j %p pt to %d\n", j, *j);
	return 0;
}
