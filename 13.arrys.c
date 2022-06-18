#include <string.h>
#include <stdio.h>

enum {N = 10};

#define NELEM(x)	((int)((sizeof(x))/sizeof((x)[0])))

static int arry[N];	// always 0, static

static void
parry(int *a0, int *an)
{
	int *a;
	int nels;

	nels = an - a0;
	printf("%d elems\n", nels);
	for (a = a0; a < an; a++) {
		printf("arry[] at %p = %d\n", a, *a);
	}
}

int
main(int argc, char *argv[])
{

	parry(arry, arry+N);
	return 0;
}
