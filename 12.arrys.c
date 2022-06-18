#include <string.h>
#include <stdio.h>

enum {N = 10};

#define NELEM(x)	((int)((sizeof(x))/sizeof((x)[0])))

static int arry[N];	// always 0, static

static void
parry(int n, int arry[])
{
	int i;

	for (i = 0; i < n; i++) {
		printf("arry[%d] at %p = %d\n", i, &arry[i], arry[i]);
	}
	printf("nelems? %d\n", NELEM(arry));
	printf("sz is %d\n", (int)sizeof arry);
}

int
main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < N; i++) {
		printf("arry[%d] at %p = %d\n", i, &arry[i], arry[i]);
	}
	printf("nelems? %d\n", NELEM(arry));

	parry(N, arry);
	return 0;
}
