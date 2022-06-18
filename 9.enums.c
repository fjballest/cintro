#include <stdio.h>

enum {
	Red,
	Blue,
	Green,
};

// make 0 be your initial valid value
enum {
	OpNone,
	OpAdd,
	OpSub,
	NOps,

	OpWeird = 66,
};

// better to use range checks & arrays
static void
printcol(int c)
{
	switch (c) {
	case Red:
		printf("red\n");
		break;
	case Blue:
		printf("blue\n");
		break;
	case Green:
		printf("green\n");
		break;
	default:
		// bad things DO happen
		printf("COLOR<%x>", c);
		break;
	}
}

int
main(int argc, char *argv[])
{
	int i;

	printf("%d\n", OpNone);
	for (i = OpNone; i < NOps; i++) {
		printf("op %d\n", i);
	}

	printcol(Red);
	return 0;
}
