#include <string.h>
#include <stdio.h>

enum {N = 10};

#define NELEM(x)	((sizeof(x))/sizeof((x)[0]))

static void
zeroarry(int n, int arry[])
{
	int i;

	for (i = 0; i < n; i++) {
		arry[i] = 0;
	}
}

static void
parry(int n, int arry[])
{
	int i;

	for (i = 0; i < n; i++) {
		printf("arry[%d] = %d\n", i, arry[i]);
	}
}

int
main(int argc, char *argv[])
{
	int arry[N];
	int other[] = {3, 5};

	zeroarry(N, arry);
	parry(N, arry);
	parry(2, other);

	memset(other, 0, sizeof other);
	parry(NELEM(other), other);

	return 0;
}
